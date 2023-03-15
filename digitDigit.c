#include <stdio.h>
#include <stdlib.h>
#include <math.h>
//1. divide the number by 10 repeatedly till its divivendo<divisor
//2. transform each number in a sum of powers of 10

unsigned long long square_digits(unsigned n);//prevents implicit declaration error

int main(){
    unsigned long long number = 10001, finalNumber = 0;
    finalNumber = square_digits(number);
    printf("the final number: %zu", finalNumber);
    return 0;
}
unsigned long long findTheNumberOfDigits(unsigned n){
    unsigned long long count = 0;
    while(n>0){
        n = n/10;
        count++;
        findTheNumberOfDigits(n);
    }
    return count;
}
unsigned long long summationFunction(unsigned long long aux, unsigned long long* powerPointer){
    unsigned long long summation = 0, powerExpression = 0, lastDigit = 0;
    for(int i = 0; aux > 0; i++){
        lastDigit = aux%10;
        powerExpression = pow(10, (double)*powerPointer);
        summation = summation + lastDigit * powerExpression;
        aux = aux/10;
        (*powerPointer)++;//https://stackoverflow.com/questions/11754419/incrementing-pointers
    }
    return summation;
}

unsigned long long square_digits(unsigned n){
    unsigned long long aux = 0, summation = 0, numberDigits = 0, finalNumber = 0, power = 0;
    numberDigits = findTheNumberOfDigits(n);
    printf("number digits: %zu\n", numberDigits);
    printf("n comeca em: %u\n", n);
    unsigned long long* powerPointer = &power;
    for(int i = 0; n > 0; i++){
        aux = n%10;
        aux *= aux;//9119 -> 9 -> 9² = 81 -> 1 * 10^0 + 8 * 10^1 + ...
        summation = summation + summationFunction(aux, &power);
        if(aux == 0){
            power++;
        }
        printf("summation: %zu\n", summation);
        n = n/10;
        printf("Agora o n sera: %u\n", n);     
    }
    return summation;
}