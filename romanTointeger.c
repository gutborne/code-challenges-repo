#include <stdio.h>
#include <string.h>

int romanToInt();
int main(){
    int sum = 0;
    char *s = "MMMCMXCIX";
    sum = romanToInt(s);
    printf("%d", sum);
    return 0;
}

int romanToInt(char * s){
    int sum = 0;
    char *symbols = "IVXLCDM";
    int values[7] = {1, 5, 10, 50, 100, 500, 1000};
    for(int i = 0; s[i] != '\0'; i++){
        for(int j = 0; symbols[j] != '\0'; j++){
            if(s[i] == symbols[j]){
                if(s[i] == 'I'){
                   if(s[i+1] == 'V'){
                        sum += (values[j+1] - values[j]);
                        i++;  
                   }else if(s[i+1] == 'X'){
                        sum += (values[j+2] - values[j]);
                        i++;                
                   }else{
                        sum += values[j];
                    }
                }else if(s[i] == 'X'){
                   if(s[i+1] == 'L'){
                        sum += (values[j+1] - values[j]);
                        i++;
                   }else if(s[i+1] == 'C'){
                        sum += (values[j+2] - values[j]);
                        i++;
                   }else{
                        sum += values[j];
                    }
                 }else if(s[i] == 'C'){
                   if(s[i+1] == 'D'){
                        sum += (values[j+1] - values[j]);
                        i++;
                   }else if(s[i+1] == 'M'){
                        sum += (values[j+2] - values[j]);
                        i++;
                   }else{
                        sum += values[j];
                    }
                }else if(s[i] != 'I' && s[i] != 'C' && s[i] != 'X'){
                        sum += values[j];
                }
                break;
            }   
        }
    }
    return sum;         
}    
               