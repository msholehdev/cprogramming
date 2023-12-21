#include <stdio.h>
#include <stdbool.h>

bool is_even(const int x){
    return (x%2==0)?true:false;
}
float celtofah(const int c){
    return ((9*c)/5)+32;
}
int main() {
  int x = 5;
  if(is_even(x)){
    printf("The number is Even. \n");
  }else{
    printf("The number is Odd. \n");
  }

  printf("Fahrenheit dari 36 adalah %f",celtofah(36));
  
  return 0;
}
