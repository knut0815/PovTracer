#ifndef __CAMERA_H__
#define __CAMERA_H__
#include <Eigen/Dense>
#include "Precision.hpp"
#include "base/Ray.hpp"
/**
 * A camera creates a 
 * virtual point and a view screen
 */
class Camera
{
public:
   Camera();
   /**
    * Get a ray from the camera in a direction
    * @param  u The u-value, from -0.5 to 0.5
    * @param  v the v-value, from -0.5 to 0.5   
    * @return   A ray
    */
   Ray getRay(Amount u, Amount v) const;

   /**
    * Setters
    */
   void setLocation(const Vector3 & location);
   void setLookAt(const Vector3 & look_at);
   void setSky(const Vector3 & sky);
   void setUp(const Vector3 & up);
   void setRight(const Vector3 right);
   void setDirection(const Vector3 & direction);
   void setAngle(const double angle);
   /**
    * Getters
    */
   const Vector3 & getLocation() const;
   const Vector3 & getDirection() const;
   const Vector3 & getRight() const;
   const Vector3 & getUp() const;
   

   /**
    * Initialize any other values.
    */
   void init();
private:
   Vector3 location;
   //Vector from location to view screen
   Vector3 direction;

   bool initLookAt;
   Vector3 look_at;
   Vector3 sky;
   //Relative height and width of the viewScreen
   Vector3 upVec;
   Vector3 rightVec;

};
#endif