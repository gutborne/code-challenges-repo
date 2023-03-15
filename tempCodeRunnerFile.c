#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

//count represents the the number of present sheeps
size_t count_sheep(const bool *sheep, size_t count){
    for(int i = 0; i < sizeof(sheep)/sizeof(sheep[0]);){
      if(sheep[i] == true){
        count++;
        i++;
      }else{
        i++; 
      }
    }
    printf("%llu", count);
}

int main(){
  printf("insert a value for the number of sheeps: ");
  size_t sheepsNumber = 0;
  //size_t *sheeps_array = malloc(sizeof(size_t) * sheepsNumber);
  const bool sheeps_array = {true,  true,  true,  false,
  true,  true,  true,  true,
  true,  false, true,  false,
  true,  false, false, true,
  true,  true,  true,  true,
  false, false, true,  true}; 
  count_sheep(sheeps_array, sheepsNumber);
  return 0;
}