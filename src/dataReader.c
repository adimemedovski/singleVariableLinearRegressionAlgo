#include "regression.h"
#include "dataReader.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define MAX_BUFFER_SIZE 100 

void readData(struct DataPoints* dataPoints, char* fileName) {
  char* buffer = (char*) malloc(sizeof(char) * MAX_BUFFER_SIZE);
  
  if (buffer == NULL) {
    printf("Error: Failed to allocate memory to buffer.\n");
    return; 
  }
  char* endPointer; 
  FILE* fptr;  
  
  fptr = fopen(fileName, "r");
  
  if (fptr == NULL) {
    free(buffer); 
    printf("Error: Failed to open file.\n"); 
    return; 
  }
  
  /*
   * Skips the first line in the data csv file.
   */
  fgets(buffer, MAX_BUFFER_SIZE, fptr); 
  
  while (fgets(buffer, MAX_BUFFER_SIZE, fptr) != NULL) {
    struct DataPoint dataPoint;
    
    dataPoint.x = strtod(strtok(buffer, ","), &endPointer);
    dataPoint.y = strtod(strtok(NULL, ","), &endPointer); 
    
    addDataPoint(dataPoints, dataPoint);
  }

  free(buffer);
  fclose(fptr);
}
