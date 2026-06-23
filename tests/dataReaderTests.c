#include "regression.h"
#include "dataReader.h"
#include "unity.h"
#include <stdint.h>
#include <inttypes.h>
#include <stdlib.h>

void setUp(void) {

}

void tearDown(void) {

}

void testDataReader(void) {
  struct DataPoints dataPoints;
  initialiseDataPoints(&dataPoints);

  readData(&dataPoints, "data/sampleData.csv");
  
  double yStart = 3.0;
  double xStart = 1.0;

  for (uint64_t i = 0; i < dataPoints.size; i++) {
    TEST_ASSERT_EQUAL_DOUBLE(xStart, dataPoints.datas[i].x); 
    TEST_ASSERT_EQUAL_DOUBLE(yStart, dataPoints.datas[i].y); 

    xStart += 1.0; 
    yStart += 2.0;
  }

  free(dataPoints.datas);
}

int main(void) {
  UNITY_BEGIN();
  
  RUN_TEST(testDataReader);
  
  return UNITY_END();
}
