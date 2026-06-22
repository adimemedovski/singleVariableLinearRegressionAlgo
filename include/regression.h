#ifndef REGRESSION_H
#define REGRESSION_H

#include <stdint.h>
#include <inttypes.h>

struct LinearRegression {
  double gradient;
  double intercept;
};

/*
 * A data point, which consists of an independent variable, x,
 * and a dependent variable y.
 */
struct DataPoint {
  double x;
  double y;
};

/*
 * This is the struct which stores the collection of data points 
 * in a given dataset.
 */
struct DataPoints {
  struct DataPoint* dataPoints;
  uint64_t capacity;
  uint64_t size;
};

/*
 * Initialises the DataPoints structs, by allocating memory 
 * to the dataPoints array, and by setting default values of 
 * 0 to size and 2 to capacity.
 */
void initialiseDataPoints(struct DataPoints* dataPoints);

#endif

