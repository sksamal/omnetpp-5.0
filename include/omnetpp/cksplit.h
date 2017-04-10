//==========================================================================
//  CKSPLIT.H - part of
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

//  Author: Babak Fakhamzadeh, TU Delft, Mar-Jun 1996;
//  Rewritten by Andras Varga

#ifndef __OMNETPP_CKSPLIT_H
#define __OMNETPP_CKSPLIT_H

#include "cdensityestbase.h"

namespace omnetpp {


/**
 * @brief Implements k-split, an adaptive histogram-like density estimation
 * algorithm.
 *
 * @ingroup Statistics
 * @see Iterator Grid
 */
class SIM_API cKSplit : public cDensityEstBase
{
  public:
    // K is the grid size of the algorithm. It must be 2, or a >=3 odd number.
    enum { K = 2 };

    /**
     * @brief Supporting struct for cKSplit. Represents one grid in the k-split
     * data structure.
     */
    struct Grid
    {
      int parent;      ///< index of parent grid
      int reldepth;    ///< depth = (reldepth - rootgrid's reldepth)
      long total;      ///< sum of cells & all subgrids (also includes 'mother')
      int mother;      ///< observations 'inherited' from mother cell
      int cells[K];    ///< cell values
    };

    /**
     * Prototype for cell split criterion functions used by cKSplit objects.
     * @ingroup Statistics
     */
    typedef int (*CritFunc)(const cKSplit&, cKSplit::Grid&, int, double *);

    /**
     * Prototype for cell division criterion functions used by cKSplit objects.
     * @ingroup Statistics
     */
    typedef double (*DivFunc)(const cKSplit&, cKSplit::Grid&, double, double *);

    /**
     * @brief Walks along cells of the distribution stored in a cKSplit object.
     */
    class Iterator
    {
      private:
        cKSplit *ks;             // host object
        int cellnum;             // global index of current cell
        int grid, cell;          // root index in gridv[], cell index in grid.cell[]
        double gridmin;          // left edge of current grid
        double cellsize;         // cell width on current grid

        // internal
        void dive(int where);

      public:
        /**
         * Constructor.
         */
        Iterator(const cKSplit& ksplit, bool atbeginning=true);

        /**
         * Reinitializes the iterator.
         */
        void init(const cKSplit& ksplit, bool atbeginning=true);

        /**
         * Moves the iterator to the next cell.
         */
        void operator++(int);

        /**
         * Moves the iterator to the previous cell.
         */
        void operator--(int);

        /**
         * Returns true if the iterator has reached either end of the cell sequence.
         */
        bool end() const  {return grid==0;}

        /**
         * Returns the index of the current cell.
         */
        int getCellNumber() const  {return cellnum;}

        /**
         * Returns the upper lower of the current cell.
         */
        double getCellMin() const  {return gridmin+cell*cellsize;}

        /**
         * Returns the upper bound of the current cell.
         */
        double getCellMax() const  {return gridmin+(cell+1)*cellsize;}

        /**
         * Returns the size of the current cell.
         */
        double getCellSize() const  {return cellsize;}

        /**
         * Returns the actual amount of observations in current cell.
         * This is not necessarily an integer value because of previous cell splits.
         */
        double getCellValue() const;
    };

    friend class Iterator;

  protected:
    int numCells;             // number of cells

    Grid *gridv;              // grid vector
    int gridvSize;            // size of gridv[]+1
    int rootGridIndex, lastGridIndex;   // indices into gridv[]
    bool rangeExtEnabled;     // enable/disable range extension

    CritFunc critFunc;        // function that determines when to split a cell
    double *critData;         // data array to pass to crit. function

    DivFunc divFunc;          // function to calc. lambda for cell division
    double *divData;          // data array to pass to div. function

    mutable Iterator *iter;   // iterator used by getBasepoint(), getCellValue() etc.
    mutable long iterNumValues; // numValues when iterator was created

  private:
    void copy(const cKSplit& other);

  protected:
    // internal:
    void resetGrids(int grid);

    // internal:
    void createRootGrid();

    // internal:
    void newRootGrids(double x);

    // internal:
    void insertIntoGrids(double x, int enable_splits);

    // internal:
    void splitCell(int grid, int cell);

    // internal:
    void distributeMotherObservations(int grid);

    // internal:
    void expandGridVector();

    // internal: helper for getBasepoint(), getCellValue()
    void iteratorToCell(int cell_nr) const;

    // abstract method in cDensityEstBase
    virtual void doMergeCellValues(const cDensityEstBase *other) override;

  public:
    /** @name Constructors, destructor, assignment. */
    //@{

    /**
     * Copy constructor.
     */
    cKSplit(const cKSplit& r);

    /**
     * Constructor.
     */
    explicit cKSplit(const char *name=nullptr);

    /**
     * Destructor.
     */
    virtual ~cKSplit();

    /**
     * Assignment operator. The name member is not copied; see cNamedObject's operator=() for more details.
     */
    cKSplit& operator=(const cKSplit& res);
    //@}

    /** @name Redefined cObject member functions. */
    //@{

    /**
     * Creates and returns an exact copy of this object.
     * See cObject for more details.
     */
    virtual cKSplit *dup() const override  {return new cKSplit (*this);}

    /**
     * Produces a multi-line description of the object's contents.
     * See cObject for more details.
     */
    virtual std::string detailedInfo() const override;

    /**
     * Serializes the object into an MPI send buffer.
     * Used by the simulation kernel for parallel execution.
     * See cObject for more details.
     */
    virtual void parsimPack(cCommBuffer *buffer) const override;

    /**
     * Deserializes the object from an MPI receive buffer.
     * Used by the simulation kernel for parallel execution.
     * See cObject for more details.
     */
    virtual void parsimUnpack(cCommBuffer *buffer) override;
    //@}

  protected:
    /**
     * Called internally by collect(), this method updates the k-split
     * data structure with the new value.
     */
    virtual void collectTransformed(double val) override;

  public:
    /** @name Redefined member functions from cStatistic and its subclasses. */
    //@{

    /**
     * Transforms the table of pre-collected values into the k-split data structure.
     */
    virtual void transform() override;

    /**
     * Returns the number of histogram cells used.
     */
    virtual int getNumCells() const override;

    /**
     * Returns the kth cell boundary.
     */
    virtual double getBasepoint(int k) const override;

    /**
     * Returns the number of observations that fell into the kth histogram cell.
     */
    virtual double getCellValue(int k) const override;

    /**
     * Returns the value of the Probability Density Function at a given x.
     */
    virtual double getPDF(double x) const override;

    /**
     * Returns the value of the Cumulated Density Function at a given x.
     */
    virtual double getCDF(double x) const override;

    /**
     * Merging is not supported by this class. This method throws an error.
     */
    virtual void merge(const cStatistic *other) override;

    /**
     * Generates a random number based on the collected data.
     */
    virtual double draw() const override;

    /**
     * Writes the contents of the object into a text file.
     */
    virtual void saveToFile(FILE *) const override;

    /**
     * Reads the object data from a file, in the format written out by saveToFile().
     */
    virtual void loadFromFile(FILE *) override;
    //@}

    /** @name Configuring the k-split algorithm. */
    //@{

    /**
     * Configures the k-split algorithm by supplying a custom split
     * criterion function.
     */
    void setCritFunc(CritFunc _critfunc, double *_critdata);

    /**
     * Configures the k-split algorithm by supplying a custom cell division
     * function.
     */
    void setDivFunc(DivFunc _divfunc, double *_divdata);

    /**
     * Enables/disables range extension. If range extension is enabled,
     * a new observation that falls outside the k-split range (i.e. outside
     * the root grid) will cause the range to be expanded (i.e. new
     * root getGrid(s) to be placed above the current root grid).
     * If range extension is disabled, such observations will simply be
     * counted as underflows or overflows.
     */
    void setRangeExtension(bool enabled);
    //@}

    /** @name Querying the k-split data structure. */
    //@{

    /**
     * Returns the depth of the k-split tree.
     */
    int getTreeDepth() const;

    /**
     * Returns the depth of the k-split tree measured from the specified grid.
     */
    int getTreeDepth(Grid& grid) const;

    /**
     * Returns the actual amount of observations in cell 'cell' of 'grid'.
     * This is not necessarily an integer value because of previous cell splits.
     */
    double getRealCellValue(Grid& grid, int cell) const;

    /**
     * Dumps the contents of the k-split data structure to EV.
     */
    void printGrids() const;

    /**
     * Returns the kth grid in the k-split data structure.
     */
    Grid& getGrid(int k) const {return gridv[k];}

    /**
     * Returns the root grid of the k-split data structure.
     */
    Grid& getRootGrid() const {return gridv[rootGridIndex];}
    //@}
};


// cell split criteria
int critfunc_const(const cKSplit&, cKSplit::Grid&, int, double *);
int critfunc_depth(const cKSplit&, cKSplit::Grid&, int, double *);

// cell division criteria
double divfunc_const(const cKSplit&, cKSplit::Grid&, double, double *);
double divfunc_babak(const cKSplit&, cKSplit::Grid&, double, double *);


}  // namespace omnetpp


#endif

