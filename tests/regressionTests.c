#include "unity.h"
#include "regression.h"
#include <stdlib.h>
#include "dataReader.h"

void setUp(void) {

}

void tearDown(void) {

}

void testInitialisationOfDataPoints(void) {
  struct DataPoints dataPoints;
  
  initialiseDataPoints(&dataPoints);
  
  TEST_ASSERT_EQUAL_UINT64(2, dataPoints.capacity);
  TEST_ASSERT_EQUAL_UINT64(0, dataPoints.size);
  
  free(dataPoints.datas);
}

void testExpansionOfDatas(void) {
  struct DataPoints dataPoints;
  initialiseDataPoints(&dataPoints);
  
  struct DataPoint pointOne;
  struct DataPoint pointTwo;
  struct DataPoint pointThree;

  addDataPoint(&dataPoints, pointOne);
  addDataPoint(&dataPoints, pointTwo);
  addDataPoint(&dataPoints, pointThree);
  
  TEST_ASSERT_EQUAL_UINT64(3, dataPoints.size);
  TEST_ASSERT_EQUAL_UINT64(4, dataPoints.capacity);
  
  free(dataPoints.datas);
}

void testAdditionOfDataPoint(void) {
  struct DataPoints dataPoints;
  initialiseDataPoints(&dataPoints);
  
  struct DataPoint pointOne;
  pointOne.x = 5.0;
  pointOne.y = 7.0;

  addDataPoint(&dataPoints, pointOne);
  
  TEST_ASSERT_EQUAL_DOUBLE(5.0, dataPoints.datas[0].x);
  TEST_ASSERT_EQUAL_DOUBLE(7.0, dataPoints.datas[0].y);
  
  free(dataPoints.datas);
}

void testSumX(void) {
  struct DataPoints dataPoints;
  initialiseDataPoints(&dataPoints);

  struct DataPoint pointOne;
  pointOne.x = 1;
  struct DataPoint pointTwo;
  pointTwo.x = 2;
  struct DataPoint pointThree;
  pointThree.x = 3;

  addDataPoint(&dataPoints, pointOne);
  addDataPoint(&dataPoints, pointTwo);
  addDataPoint(&dataPoints, pointThree);

  TEST_ASSERT_EQUAL_DOUBLE(6, sumX(dataPoints));
  
  free(dataPoints.datas);
}

void testSumY(void) {
  struct DataPoints dataPoints;
  initialiseDataPoints(&dataPoints);

  struct DataPoint pointOne;
  pointOne.y = 1;
  struct DataPoint pointTwo;
  pointTwo.y = 2;
  struct DataPoint pointThree;
  pointThree.y = 3;

  addDataPoint(&dataPoints, pointOne);
  addDataPoint(&dataPoints, pointTwo);
  addDataPoint(&dataPoints, pointThree);

  TEST_ASSERT_EQUAL_DOUBLE(6, sumY(dataPoints));
  
  free(dataPoints.datas);
}

void testSumProductXY(void) {
  struct DataPoints dataPoints;
  initialiseDataPoints(&dataPoints);

  struct DataPoint pointOne;
  pointOne.y = 1;
  pointOne.x = 1;
  struct DataPoint pointTwo;
  pointTwo.y = 2;
  pointTwo.x = 2;
  struct DataPoint pointThree;
  pointThree.y = 3;
  pointThree.x = 3;

  addDataPoint(&dataPoints, pointOne);
  addDataPoint(&dataPoints, pointTwo);
  addDataPoint(&dataPoints, pointThree);

  TEST_ASSERT_EQUAL_DOUBLE(14, sumProductXY(dataPoints));
  
  free(dataPoints.datas);
}

void testSumSquaredX(void) {
  struct DataPoints dataPoints;
  initialiseDataPoints(&dataPoints);

  struct DataPoint pointOne;
  pointOne.x = 1;
  struct DataPoint pointTwo;
  pointTwo.x = 2;
  struct DataPoint pointThree;
  pointThree.x = 3;

  addDataPoint(&dataPoints, pointOne);
  addDataPoint(&dataPoints, pointTwo);
  addDataPoint(&dataPoints, pointThree);

  TEST_ASSERT_EQUAL_DOUBLE(14, sumSquaredX(dataPoints));
  
  free(dataPoints.datas);
}

void testLinearRegression(void) {
  struct DataPoints dataPoints;
  initialiseDataPoints(&dataPoints);
  
  readData(&dataPoints, "data/sampleData.csv");
  
  struct LinearRegression linearRegression;
  linearRegression = analyticalMethod(dataPoints);
  
  TEST_ASSERT_EQUAL_DOUBLE(2, linearRegression.gradient);
  TEST_ASSERT_EQUAL_DOUBLE(1, linearRegression.intercept);

}

int main(void) {
  UNITY_BEGIN();

  RUN_TEST(testInitialisationOfDataPoints);
  RUN_TEST(testExpansionOfDatas);
  RUN_TEST(testAdditionOfDataPoint);
  RUN_TEST(testSumX);
  RUN_TEST(testSumY);
  RUN_TEST(testSumProductXY);
  RUN_TEST(testSumSquaredX);
  RUN_TEST(testLinearRegression);

  return UNITY_END();
}
