#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
char romanNumbersArray[10];

//Create a function that returns the number of digits
//create a fuction that applies the formation rule of decimal numbers

/**
 * @brief This initial description will walk through step by step to get this solution 
 * 
 */


/**
 * @brief 
 * 
 * @param num 
 * @return int 
 */
int numberOfDigits(int num){
    int numDigits = 0;
    while(num > 0){
        num = num/10;
        numDigits++;
    }
    return numDigits;
}
int* formationRuleDecimalNumbers(int number, int numDigits){
    int power = 0, index = numDigits - 1, digit = 0;
    int* numberArray = malloc(numDigits * sizeof(int));
    for(int i = 0; i < numDigits; i++){
        digit = (number % 10) * pow(10, power);
        numberArray[index--] = digit;
        power++;
        number /= 10;
    }
    return numberArray;    
}
char* convertIntToRoman(int* decimalDigitsArray, int numDigts){
    for(int i = 0, j = 0; i < numDigts; i++){
        if(decimalDigitsArray[i]>= 1 && decimalDigitsArray[i] < 5){
            if(decimalDigitsArray[i] == 4){
                romanNumbersArray[j] = 'I';
                romanNumbersArray[j + 1] = 'V';
                romanNumbersArray[j + 2] = '\0';
                j = j + 2;
            }else{
                for(int k = 0; k < decimalDigitsArray[i]; k++, j++){
                   romanNumbersArray[j] = 'I';
                }
                romanNumbersArray[j] = '\0';
            }
        }else if(decimalDigitsArray[i]>= 5 && decimalDigitsArray[i] < 10){
            if(decimalDigitsArray[i] == 9){
                romanNumbersArray[j] = 'I';
                romanNumbersArray[j + 1] = 'X';
                romanNumbersArray[j + 2] = '\0';
                j = j + 2;
            }else{
                for(int k = 5; k <= decimalDigitsArray[i]; k++, j++){
                    if(k == 5){
                        romanNumbersArray[j] = 'V';
                    }else{
                        romanNumbersArray[j] = 'I';
                    }
                }
                romanNumbersArray[j] = '\0';
            }
        }else if(decimalDigitsArray[i]>= 10 && decimalDigitsArray[i] < 50){
            if(decimalDigitsArray[i] == 40){
                romanNumbersArray[j] = 'X';
                romanNumbersArray[j + 1] = 'L';
                romanNumbersArray[j + 2] = '\0';
                j = j + 2;
            }else{
                for(int k = 10; k <= decimalDigitsArray[i]; k+=10, j++){
                    romanNumbersArray[j] = 'X';
                }
                romanNumbersArray[j] = '\0';
            }
        }else if(decimalDigitsArray[i]>= 50 && decimalDigitsArray[i] < 100){
            if(decimalDigitsArray[i] == 90){
                romanNumbersArray[j] = 'X';
                romanNumbersArray[j + 1] = 'C';
                romanNumbersArray[j + 2] = '\0';
                j = j + 2;
            }else{
                for(int k = 50; k <= decimalDigitsArray[i]; k+=10, j++){
                    if(k == 50)
                        romanNumbersArray[j] = 'L';
                    else
                       romanNumbersArray[j] = 'X';
                }
                romanNumbersArray[j] = '\0';
            }
        }else if(decimalDigitsArray[i]>= 100 && decimalDigitsArray[i] < 500){
            if(decimalDigitsArray[i] == 400){
                romanNumbersArray[j] = 'C';
                romanNumbersArray[j + 1] = 'D';
                romanNumbersArray[j + 2] = '\0';
                j = j + 2;
            }else{
                for(int k = 100; k <= decimalDigitsArray[i]; k+=100, j++){
                    romanNumbersArray[j] = 'C';
                }
                romanNumbersArray[j] = '\0';
            }
        }else if(decimalDigitsArray[i]>= 500 && decimalDigitsArray[i] < 1000){
            if(decimalDigitsArray[i] == 900){
                romanNumbersArray[j] = 'C';
                romanNumbersArray[j + 1] = 'M';
                romanNumbersArray[j + 2] = '\0';
                j = j + 2;
            }else{
                for(int k = 500; k <= decimalDigitsArray[i]; k+=100, j++){
                    if(k == 500)    
                        romanNumbersArray[j] = 'D';
                    else
                        romanNumbersArray[j] = 'C';
                }
                romanNumbersArray[j] = '\0';
            }
        }else if(decimalDigitsArray[i]>= 1000 && decimalDigitsArray[i] < 4000){
                for(int k = 1000; k <= decimalDigitsArray[i]; k+=1000, j++){
                    romanNumbersArray[j] = 'M';
                }
                romanNumbersArray[j] = '\0';
        }
    }

    return romanNumbersArray;
}
char* intToRoman(int number){
    if(number >= 1 && number <= 3999){
        int numDigits = 0;
        numDigits = numberOfDigits(number);
        int* decimalDigitsArray = formationRuleDecimalNumbers(number, numDigits);
        char* romanNumber = convertIntToRoman(decimalDigitsArray, numDigits);
        return romanNumber;
    }else{
        return NULL;    
    }
}
int main(){
    char* result = NULL; 
    for(int i = 1; i <= 1000; i++){
        result = intToRoman(i);
        printf("Output: %s\n", result);
    }
    return 0;
    /*
    if(result == NULL){
        printf("Out of Scope!");
    }else{
        printf("output: %s\n", result);
    }
    return 0;*/
}