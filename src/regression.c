#include "regression.h"
#include <stdint.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <math.h>

#define DATAS_INITIAL_CAPACITY 2

void initialiseDataPoints(struct DataPoints* dataPoints) {
  dataPoints -> datas = malloc(sizeof(struct DataPoint) * DATAS_INITIAL_CAPACITY);
  
  if (dataPoints -> datas == NULL) {
    printf("Error: Failed to initialise Data Points.\n");
  }
  
  dataPoints -> size = 0; 
  dataPoints -> capacity = DATAS_INITIAL_CAPACITY;
}

bool expandDatas(struct DataPoints* dataPoints) {
  struct DataPoint* tempDatas = realloc(dataPoints -> datas, sizeof(struct DataPoint) * (dataPoints -> capacity * 2));
  
  if (tempDatas == NULL) {
    printf("Error: Failed to expand datas.\n"); 
    return false; 
  }

  dataPoints -> datas = tempDatas;
  dataPoints -> capacity = dataPoints -> capacity * 2;
  return true;
}

void addDataPoint(struct DataPoints* dataPoints, struct DataPoint dataPoint) {
  if (dataPoints -> size == dataPoints -> capacity) {
    if (expandDatas(dataPoints)) {
      dataPoints -> datas[dataPoints -> size] = dataPoint;
      dataPoints -> size += 1;
      return;
    }
    else {
      printf("Error: Failed to add data point to datas.\n");
      return; 
    }
  } 

  dataPoints -> datas[dataPoints -> size] = dataPoint;
  dataPoints -> size += 1;
}

double sumX(struct DataPoints dataPoints) {
  double sum = 0;
  
  for (uint64_t i = 0; i < dataPoints.size; i++) {
    sum += dataPoints.datas[i].x;
  }

  return sum;
}

double sumY(struct DataPoints dataPoints) {
  double sum = 0;

  for (uint16_t i = 0; i < dataPoints.size; i++) {
    sum += dataPoints.datas[i].y;
  }

  return sum;
}

double sumProductXY(struct DataPoints dataPoints) {
  double sum = 0;

  for (uint16_t i = 0; i < dataPoints.size; i++) {
    sum += dataPoints.datas[i].x * dataPoints.datas[i].y;
  }

  return sum;
}

double sumSquaredX(struct DataPoints dataPoints) {
  double sum = 0;
  
  for (uint16_t i = 0; i < dataPoints.size; i++) {
    sum += pow(dataPoints.datas[i].x, 2);
  }

  return sum;
}


