#include "unity.h"
#include "regression.h"

void setUp(void) {

}

void tearDown(void) {

}

void testInitialisationOfDataPoints(void) {
  struct DataPoints dataPoints;
  
  
  initialiseDataPoints(&dataPoints);
  
  TEST_ASSERT_EQUAL_UINT64(2, dataPoints.capacity);
  TEST_ASSERT_EQUAL_UINT64(0, dataPoints.size);
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

  return UNITY_END();
}
