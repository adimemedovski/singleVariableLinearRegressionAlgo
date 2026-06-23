#ifndef REGRESSION_H
#define REGRESSION_H

#include <stdint.h>
#include <inttypes.h>
#include <stdbool.h>

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
  struct DataPoint* datas;
  uint64_t capacity;
  uint64_t size;
};

/*
 * Initialises the DataPoints structs, by allocating memory 
 * to the dataPoints array, and by setting default values of 
 * 0 to size and 2 to capacity.
 */
void initialiseDataPoints(struct DataPoints* dataPoints);

/*
 * Allocates double the capacity of memory for the datas array.
 */
bool expandDatas(struct DataPoints* dataPoints);

/*
 * Adds a data point to the array datas inside of data points.
 */
void addDataPoint(struct DataPoints* dataPoints, struct DataPoint dataPoint);

/*
 * Takes the summand of the x-values in datas.
 */
double sumX(struct DataPoints dataPoints);

/*
 * Takes the summand of the y-values in datas.
 */
double sumY(struct DataPoints dataPoints);

/*
 * Takes the summand of the product x and y values in datas.
 */
double sumProductXY(struct DataPoints dataPoints);

/*
 * Takes the summand of the squared x value in datas.
 */
double sumSquaredX(struct DataPoints dataPoints);

/*
 * Computes the optimised gradient and intercept values using the 
 * analytical approach for linear regression. This is most efficient 
 * for simple linear regression and when datasets are small.
 */
struct LinearRegression analyticalMethod(struct DataPoints dataPoints);

#endif



