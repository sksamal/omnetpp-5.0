//==========================================================================
//   COSGCANVAS.H  -  header for
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

#ifndef __OMNETPP_COSGCANVAS_H
#define __OMNETPP_COSGCANVAS_H

#include "cownedobject.h"
#include "ccanvas.h"

#ifdef WITH_OSG

// don't include OSG headers yet
namespace osg { class Node; class Group; class Vec3d; }
namespace osgEarth { class Viewpoint; }

namespace omnetpp {

/**
 * @brief Wraps an OpenSceneGraph scene, allowing 3D visualization in graphical
 * user interfaces that support it (currently Qtenv).
 *
 * This class only wraps an OSG scene (as an osg::Node* pointer) and some
 * visualization hints, other tasks like setting up a 3D viewer window are
 * taken care of by the OMNeT++ user interface code (Qtenv). The scene graph
 * can be assembled using the OSG API, e.g. using osgDB::readNodeFile() or
 * creating and adding nodes directly.
 *
 * Since OpenSceneGraph is not a mandatory part of OMNeT++, it is recommended
 * that you surround your OSG code with \#ifdef WITH_OSG.
 *
 * @ingroup OSG
 */
class SIM_API cOsgCanvas : public cOwnedObject
{
    public:
        /**
         * @brief Viewer styles.
         * @ingroup OSG
         */
        enum ViewerStyle {
            STYLE_GENERIC, ///< For generic (non-osgEarth) OSG models
            STYLE_EARTH    ///< For osgEarth models
        };

        typedef cFigure::Color Color;

        /**
         * @brief Camera manupulator types.
         * @ingroup OSG
         */
        enum CameraManipulatorType {
            CAM_AUTO,      ///< Choose the camera manipulator automatically
            CAM_TERRAIN,   ///< Suitable for flying above an object or terrain
            CAM_OVERVIEW,  ///< Similar to TERRAIN, but only allows seeing the object from above
            CAM_TRACKBALL, ///< Allows unrestricted movement centered around an object
            CAM_EARTH      ///< Useful when viewing osgEarth scenes
        };

        // this is only needed to simplify the Viewpoint hint
        struct Vec3d {
            double x, y, z;
            Vec3d() : x(0), y(0), z(0) {}
            Vec3d(double x, double y, double z): x(x), y(y), z(z) {}
            operator osg::Vec3d() const;
        };

        /**
         * @brief Defines a viewpoint in the 3D space.
         *
         * The Viewpoint is defined by the position of the eye, the point
         * to look at, and the "up" direction. See OpenGL gluLookAt() for
         * details.
         *
         * @ingroup OSG
         */
        struct Viewpoint {
            /** @name Data members. */
            //@{
            Vec3d eye;    ///< Specifies the position of the eye point.
            Vec3d center; ///< Specifies the position of the reference point.
            Vec3d up;     ///< Specifies the direction of the up vector.
            bool valid;
            //@}
            /** @name Methods. */
            //@{
            Viewpoint() : valid(false) {}
            Viewpoint(const Vec3d& eye, const Vec3d& center, const Vec3d& up): eye(eye), center(center), up(up), valid(true) {}
            //@}
        };

    protected:
        osg::Node *scene;  // reference counted

        ViewerStyle viewerStyle;

        // OSG viewer hints
        Color clearColor;
        CameraManipulatorType cameraManipulatorType;
        double fieldOfViewAngle;  // a.k.a. fovy, see OpenGL gluPerspective
        double zNear; // see OpenGL gluPerspective
        double zFar;  // see OpenGL gluPerspective

        Viewpoint *genericViewpoint; // never nullptr

        // osgEarth-specific viewer hints
        osgEarth::Viewpoint *earthViewpoint; // never nullptr

    private:
        void copy(const cOsgCanvas& other);

    public:
        /** @name Constructors, destructor, assignment */
        //@{
        cOsgCanvas(const char *name=nullptr, ViewerStyle viewerStyle=STYLE_GENERIC, osg::Node *scene=nullptr);
        cOsgCanvas(const cOsgCanvas& other) : cOwnedObject(other) {copy(other);}
        virtual ~cOsgCanvas();
        cOsgCanvas& operator=(const cOsgCanvas& other);
        //@}

        /** @name Redefined cObject member functions. */
        //@{
        virtual cOsgCanvas *dup() const override {return new cOsgCanvas(*this);}
        virtual std::string info() const override;
        //@}

        /** @name OSG scene. */
        //@{
        /**
         * Set the 3D scene to be displayed. Note that osg::Node implements
         * reference counting, and setScene() increments the reference count.
         */
        virtual void setScene(osg::Node *scene);

        /**
         * Return the 3D scene to be displayed.
         */
        virtual osg::Node *getScene() const {return scene;}
        //@}

        /** @name Hints for the OSG viewer. */
        //@{
        /**
         * Sets the viewer style. This hint affects the defaults for several other hints,
         * for example the camera maniplator hint. Currently there are two styles,
         * STYLE_GENERIC for generic OSG (non-osgEarth), and STYLE_EARTH for osgEarth
         * models.
         */
        void setViewerStyle(ViewerStyle viewerStyle) {this->viewerStyle = viewerStyle;}

        /**
         * Return the viewer style hint.
         */
        ViewerStyle getViewerStyle() const {return viewerStyle;}

        /**
         * Set the color hint for the background behind the scene. Note that
         * this hint will be ignored by osgEarth models, because osgEarth uses
         * sky models for the same purpose.
         */
        void setClearColor(Color clearColor) {this->clearColor = clearColor;}

        /**
         * Return the color hint for background behind the scene.
         */
        const Color& getClearColor() const {return clearColor;}

        /**
         * Set the camera manipulator type hint. The camera manipulator
         * determines how the camera reacts to mouse/keyboard actions.
         * CAM_TERRAIN, CAM_OVERVIEW, and CAM_TRACKBALL are useful when
         * viewing generic OSG scenes, and CAM_EARTH is useful for osgEarth
         * scenes.
         */
        void setCameraManipulatorType(CameraManipulatorType manipulator) {this->cameraManipulatorType = manipulator;}

        /**
         * Return the camera manipulator type hint.
         */
        CameraManipulatorType getCameraManipulatorType() const {return cameraManipulatorType;}

        /**
         * Set the field of view angle hint, in degrees, in the y direction.
         */
        void setFieldOfViewAngle(double fieldOfViewAngle) {this->fieldOfViewAngle = fieldOfViewAngle;}

        /**
         * Return the field of view angle hint, in degrees, in the y direction.
         */
        double getFieldOfViewAngle() const {return fieldOfViewAngle;}

        /**
         * Set the distance hint from the viewer to the near clipping plane
         * (always positive).
         *
         * @see setZLimits()
         */
        void setZNear(double zNear) {this->zNear = zNear;}

        /**
         * Set the distance hint from the viewer to the far clipping plane
         * (always positive).
         *
         * @see setZLimits()
         */
        void setZFar(double zFar) {this->zFar = zFar;}

        /**
         * Set the distance from the viewer to the near and far clipping planes
         * (always positive) as viewer hint. When not set, the corresponding
         * limits are computed automatically by the viewer.
         *
         * @see clearZLimits()
         */
        void setZLimits(double zNear, double zFar) {this->zNear = zNear; this->zFar = zFar;}

        /**
         * Unset the zNear/zFar values set via setZLimits().
         */
        void clearZLimits();

        /**
         * Returns true if the zNear/zFar values are set manually.
         * @see setZLimits(), clearZLimits()
         */
        bool hasZLimits() const;

        /**
         * Return the distance hint from the viewer to the near clipping plane.
         * Returns NaN when not set (e.g. after clearZLimits()).
         */
        double getZNear() const {return zNear;}

        /**
         * Return the distance from the viewer to the far clipping plane.
         * Returns NaN when not set (e.g. after clearZLimits()).
         */
        double getZFar() const {return zFar;}
        //@}

        /** @name Viewer hints for the generic style. */
        //@{
        /**
         * Sets the initial genericViewpoint hint.
         */
        void setGenericViewpoint(const Viewpoint& viewpoint);

        /**
         * Returns the initial genericViewpoint hint.
         */
        const Viewpoint& getGenericViewpoint() const {return *genericViewpoint;}
        //@}

        /** @name osgEarth-related viewer hints. */
        //@{
        /**
         * Sets the initial earthViewpoint hint.
         */
        void setEarthViewpoint(const osgEarth::Viewpoint& earthViewpoint);

        /**
         * Returns the initial earthViewpoint hint.
         */
        const osgEarth::Viewpoint& getEarthViewpoint() const {return *earthViewpoint;}
        //@}
};

} // namespace omnetpp

#else // not WITH_OSG

// Dummy cOsgCanvas class in case OpenSceneGraph is not available
namespace omnetpp {

  class SIM_API cOsgCanvas : public cOwnedObject
  {
      public:
          cOsgCanvas();
  };

}

#endif // WITH_OSG

#endif
