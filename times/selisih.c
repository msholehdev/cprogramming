#include <stdio.h>
#include <time.h>
 
void ConvertSectoDay(int n) 
{ 
    int day = n / (24 * 3600); 
  
    n = n % (24 * 3600); 
    int hour = n / 3600; 
  
    n %= 3600; 
    int minutes = n / 60 ; 
  
    n %= 60; 
    int seconds = n; 
      
    printf("days %d hours %d minutes %d second %d\n",day,hour,minutes, seconds); 
} 
int main(void)
{
    time_t now = time(0);
 
    struct tm beg = *localtime(&now);
 
    // set beg to the beginning of the month
    beg.tm_hour = 1,
    beg.tm_min = 0,
    beg.tm_sec = 0,
    beg.tm_mday = 0;
 
    double seconds = difftime(now, mktime(&beg));
 
    printf("%.f seconds have passed since the beginning of the month.\n", seconds);

    ConvertSectoDay(seconds);
 
    return 0;
}