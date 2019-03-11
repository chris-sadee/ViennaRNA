/*
 *      RNApuzzler options
 *
 *      c  Daniel Wiegreffe, Daniel Alexander, Dirk Zeckzer
 *      ViennaRNA package
 */

#include "ViennaRNA/plotting/RNApuzzler/definitions.h"
#include "ViennaRNA/plotting/RNApuzzler/vector_math.h"

#include "ViennaRNA/utils.h"

#include <stdlib.h>
#include <math.h>


PRIVATE void
bubblesort(const int            numValues,
           const double *const  valuesLevel1,
           const double *const  valuesLevel2,
           int *const           indices)
{
  for (int i = 0; i < numValues; i++)
    indices[i] = i;

  double  thisValue = 0.0;
  double  nextValue = 0.0;
  short   swap      = 0;
  for (int i = 0; i < numValues - 1; i++) {
    for (int j = 0; j < numValues - i - 1; j++) {
      thisValue = valuesLevel1[indices[j + 0]];
      nextValue = valuesLevel1[indices[j + 1]];
      swap      = 0;
      if (nextValue - thisValue > EPSILON_7) {
        swap = 1;
      } else if (fabs(nextValue - thisValue) < EPSILON_7) {
        thisValue = valuesLevel2[indices[j + 0]];
        nextValue = valuesLevel2[indices[j + 1]];
        if (nextValue - thisValue > EPSILON_7)
          swap = 1;
      }

      if (swap) {
        int tmp = indices[j + 0];
        indices[j + 0]  = indices[j + 1];
        indices[j + 1]  = tmp;
      }
    }
  }
}


/**
 * @brief
 *      Given a circle's radius and a distance between two points on the circle
 *      this function calculates the angle between those points.
 *      Note that the resulting angle will always be smaller than or equal to 180°.
 *      If knowing the wanted angle being greater than 180° just subtract the result from 360°.
 * @param radius the circle's radius
 * @param distance the distance between two points on the circle
 * @return angle in degree
 */
PRIVATE double
distanceToAngle(const double  radius,
                const double  distance)
{
  return 2.0 * asin(distance / (2.0 * radius));
}


PRIVATE double
angleToDistance(const double  radius,
                const double  angle)
{
  return 2.0 * radius * sin(angle / 2.0);
}
