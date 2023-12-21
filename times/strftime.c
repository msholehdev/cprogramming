#include <stdio.h>
#include <time.h>

int main(void){  

    size_t maxsize = 80;
    char dest[maxsize];

    struct tm * time_struct;
    time_t now;
    
    time(&now);
    time_struct = localtime(&now);

    strftime(dest, maxsize, "%D", time_struct);
    printf("Today's date: %s\n", dest);
}