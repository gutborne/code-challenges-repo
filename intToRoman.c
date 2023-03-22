#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

//Create a function that returns the number of digits
//create a fuction that applies the formation rule of decimal numbers
int numberOfDigits(int num){
    int numDigits = 0;
    while(num > 0){
        num = num/10;
        numDigits++;
        numberOfDigits(num);
    }
    return numDigits;
}
int* formationRuleDecimalNumbers(int number, int numDigits){
    int power = 0, index = numDigits - 1, digit = 0, powerResult = 0;
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
    char* romanNumbersArray = malloc(10*sizeof(char));
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
        printf("value: %d\n", numDigits);
        int* decimalDigitsArray = formationRuleDecimalNumbers(number, numDigits);
        for(int i = 0; i < numDigits; i++){
            printf("%d ", decimalDigitsArray[i]);
        }
        char* romanNumber = convertIntToRoman(decimalDigitsArray, numDigits);
        return romanNumber;
    }else{
        return NULL;    
    }
}
int main(){
    int number = 288;
    char* result = NULL; 
    result = intToRoman(number);
    if(result == NULL){
        printf("Out of Scope!");
    }else{
        printf("\n%s", result);
    }
    return 0;
}