#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

//count represents the the number of present sheeps
/*
size_t count_sheep(const bool *sheep, size_t count){
    int countPresentSheeps = 0; 
    for(size_t i = 0; i < count;){
      if(sheep[i] == true){
        countPresentSheeps++;
        i++;
      }else{
        i++;
      }
    }
    return countPresentSheeps;
}*/

size_t count_sheep(const bool *sheep, size_t count){
    int sum = 0;
    for(int i=0; i < count; i++) 
      sum += sheep[i];
    return sum;
}

int main(){
  //printf("insert a value for the number of sheeps: ");
  size_t sheepsNumber = 24;
  //size_t *sheeps_array = malloc(sizeof(size_t) * sheepsNumber);
  const bool sheeps_array[24] = {true,  true,  true,  false,
  true,  true,  true,  true,
  true,  false, true,  false,
  true,  false, false, true,
  true,  true,  true,  true,
  false, false, true,  true}; 
  size_t tam = count_sheep(sheeps_array, sheepsNumber);
  printf("the number of present sheeps is: %llu", tam);
  return 0;
}