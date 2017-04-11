//==========================================================================
//  TEXTVIEWERWIDGET.H - part of
//
//                     OMNeT++/OMNEST
//            Discrete System Simulation in C++
//
//==========================================================================

/*--------------------------------------------------------------*
  Copyright (C) 1992-2015 Andras Varga
  Copyright (C) 2006-2015 OpenSim Ltd.

  This file is distributed WITHOUT ANY WARRANTY. See the file
  `license' for details on this and other legal matters.
*--------------------------------------------------------------*/

#ifndef __OMNETPP_QTENV_TEXTVIEWERWIDGET_H
#define __OMNETPP_QTENV_TEXTVIEWERWIDGET_H

#include <QAbstractScrollArea>
#include <QElapsedTimer>
#include <QFrame>
#include <QHeaderView>
#include <QPaintEvent>
#include <QScrollBar>
#include <QStandardItemModel>
#include <QTimer>
#include <QToolBar>

namespace omnetpp {
namespace qtenv {

class TextViewerContentProvider;

/**
 * Primarily for TextViewer
 * @author Andras
 */
class Pos {
public:
    int line;
    int column;

    Pos(int line, int column);

    bool operator < (const Pos &other);
    bool operator == (const Pos &other);
    bool operator != (const Pos &other);
};


class TextViewerWidget : public QAbstractScrollArea
{
    Q_OBJECT

public:

    enum FindOption {
        FIND_REGULAR_EXPRESSION = 1<<0,
        FIND_CASE_SENSITIVE     = 1<<1,
        FIND_WHOLE_WORDS        = 1<<2,
        FIND_BACKWARDS          = 1<<3
    };

    Q_DECLARE_FLAGS(FindOptions, FindOption)

    struct TabStop {
        int atCharacter;
        QColor color;
        TabStop(int at, const QColor &col);
    };

protected:
    enum ScrollDirection {
        SCROLL_NONE,
        SCROLL_UP,
        SCROLL_DOWN,
        SCROLL_LEFT,
        SCROLL_RIGHT
    };

    // these 4 are all owned
    TextViewerContentProvider *content = nullptr;
    QToolBar *toolBar;
    QStandardItemModel *headerModel;
    QHeaderView *header;

    QFont font;
    QColor backgroundColor;
    QColor foregroundColor;
    QColor selectionBackgroundColor;
    QColor selectionForegroundColor;
    int toolbarSpacing = 4;
    int leftMargin = 5;
    int lineHeight, averageCharWidth; // measured from font
    bool isMonospaceFont;
    int topLineIndex = 0;
    int topLineY = 0; // Y coordinate of where top edge of line topLineIndex gets painted (range: -(lineHeight-1)..0)
    int horizontalScrollOffset = 0; // in pixels
    int caretLineIndex = 0, caretColumn = 0;  // caretColumn may be greater than line length! ()
    int selectionAnchorLineIndex = 0, selectionAnchorColumn = 0; // selection is between anchor and caret
    //Map<Integer,Integer> keyActionMap = new HashMap<Integer, Integer>(); // key: keycode, value: ST.xxx constants

    int clickCount = 0;
    //ISelectionProvider selectionProvider = new SelectionProvider();
    QTimer caretBlinkTimer;
    bool caretShown = true; // during blinking
    QTimer autoScrollTimer;
    ScrollDirection autoScrollDirection = SCROLL_NONE;
    int autoScrollDistance = 0; // currently unused

    static const int MAX_CLIPBOARD_SIZE = 100*1024*1024; // 100 MiB
    static const int CARET_BLINK_DELAY = 500;
    static const int V_SCROLL_RATE = 50;
    static const int H_SCROLL_RATE = 10;
    // if a single click happens less than this many milliseconds after
    // a double click, it is treated as a triple click
    static const int TRIPLE_CLICK_THRESHOLD_MS = 500;


    void doLineUp(bool select);
    void doLineDown(bool select);
    void doCursorPrevious(bool select);
    void doCursorNext(bool select);
    void doPageUp(bool select);
    void doPageDown(bool select);
    void doLineStart(bool select);
    void doLineEnd(bool select);
    void doWordPrevious(bool select);
    void doWordNext(bool select);
    void doPageStart(bool select);
    void doPageEnd(bool select);
    void doContentStart(bool select);
    void doContentEnd(bool select);

    void selectAll();
    void clearSelection();


    static int clip(int lower, int upper, int x);
    static bool isWordChar(QChar ch);


    void resizeEvent(QResizeEvent *event) override;
    void paintEvent(QPaintEvent *event) override;
    void keyPressEvent(QKeyEvent *) override;

    // Qt doesn't support triple clicks.
    // the events we receive on triple click are: single, double, single
    // so on every single click we measure the time since the last double click
    // and if it is short enough, we act as if it was a triple click event
    QElapsedTimer timeSinceLastDoubleClick;
    void mousePressEvent(QMouseEvent *event) override;
    void mouseDoubleClickEvent(QMouseEvent *event) override;

    void mouseMoveEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;

    void drawLine(QPainter &painter, int lineIndex, int x, int y);
    void drawLinePart(QPainter &painter, const QFontMetrics &metrics, const QString &line, const QList<TabStop> &tabStops, int lineIndex, int partIndex, int y);


    /**
     * A mouse move event has occurred.  See if we should start autoscrolling.  If
     * the move position is outside of the client area, initiate autoscrolling.
     * Otherwise, we've moved back into the widget so end autoscrolling.
     */
    void doAutoScroll(QMouseEvent *event);
    void startOrRefineAutoScroll(ScrollDirection direction, int distance);
    void stopAutoScroll();

    // If the parameter is true, the vertical scrollbar will
    // stay at its maximum if it has already been there,
    // to follow a growing text.
    void updateScrollbars(bool allowStickingToBottom = true);

    // This does the actual handling of the change, when really needed (before painting).
    void handleContentChange();
    bool contentChangedFlag = true; // initially we should update

    /**
     * Scroll the caret into view
     */
    void revealCaret();

    void alignTopLine();
    void alignBottomLine();

protected slots:

    void onAutoScrollTimer();
    void onCaretBlinkTimer();
    void onHeaderSectionResized(int logicalIndex, int oldSize, int newSize);
    void copySelection();

public slots:
    // This is the signal handler, but only sets a flag for
    // performance reasons, see handleContentChange().
    void onContentChanged();
    void onLinesDiscarded(int numLinesDiscarded);

    void scrolledHorizontally(int value);
    void scrolledVertically(int value);

signals:
    void caretMoved(int lineIndex, int column);
    void rightClicked(QPoint globalPos, int lineIndex, int column);

public:
    explicit TextViewerWidget(QWidget *parent = 0);
    ~TextViewerWidget();

    void setContentProvider(TextViewerContentProvider *newContent);
    TextViewerContentProvider *getContentProvider();

    QList<QVariant> getColumnWidths();
    void setColumnWidths(const QList<QVariant> &widths);

    static QFont getMonospaceFont();
    void setFont(QFont font);

    void setToolBar(QToolBar *toolBar);

    /**
     * This is the efficient way to set the caret position.
     */
    void setCaretPosition(int lineIndex, int column);

    /**
     * Returns the caret position.
     */
    Pos getCaretPosition();

    void setSelection(int startLineIndex, int startColumn, int endLineIndex, int endColumn);

    Pos getSelectionAnchor();
    void setSelectionAnchor(int lineIndex, int column);

    Pos getSelectionStart();
    Pos getSelectionEnd();

    void find(QString text, FindOptions options);

    int getLineHeight();

    int getMaxVisibleLineWidth();
    int getNumVisibleLines();
    int getNumVisibleColumns();

    // measured from the left edge of the viewport (includes margin, scrolling, etc...)
    int getLinePartOffset(const QFontMetrics &metrics, const QString &line, const QList<TabStop> &tabStops, int partIndex);
    // the x coordinate of a column in a given line
    int getLineColumnOffset(const QFontMetrics &metrics, const QString &line, const QList<TabStop> &tabStops, int columnIndex);
    Pos getLineColumnAt(int x, int y);
};


Q_DECLARE_OPERATORS_FOR_FLAGS(TextViewerWidget::FindOptions)

} // namespace qtenv
} // namespace omnetpp

#endif // __OMNETPP_QTENV_TEXTVIEWERWIDGET_H
