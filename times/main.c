#define __STDC_WANT_LIB_EXT1__ 1
#define _XOPEN_SOURCE // for putenv
#include <time.h>
#include <stdio.h>
#include <stdlib.h>   // for putenv
 
int main(void)
{
    // waktu saat ini
    time_t t = time(NULL);
    printf("UTC:       %s", asctime(gmtime(&t)));
    printf("local:     %s", asctime(localtime(&t)));
    
    // waktu local
    // POSIX-specific
    putenv("TZ=Asia/Jakarta");
    printf("Jakarta: %s", asctime(localtime(&t)));

    //parsing format
    struct tm tm = *localtime(&(time_t){time(NULL)});
    printf("Jam: %.2d\n", tm.tm_hour);
    printf("Tahun: %4\n", tm.tm_year+1900);
    
    //parsing format
    char buffer[26];
    struct tm* tm_info;

    tm_info=localtime(&t);

    strftime(buffer, 26, "%Y-%m-%d %H:%M:%S", tm_info);
    puts(buffer);
    


#ifdef __STDC_LIB_EXT1__
    struct tm buf;
    char str[26];
    asctime_s(str,sizeof str,gmtime_s(&t, &buf));
    printf("UTC:       %s", str);
    asctime_s(str,sizeof str,localtime_s(&t, &buf));
    printf("local:     %s", str);
#endif
}


/*
Table C-1 Format Strings for Date and Time

Attribute	Allowed Values
%a
Abbreviated day of the week (3 chars)

%d
Day of month as a decimal number (01-31)

%S
Second as a decimal number (00-59)

%M
Minute as a decimal number (00-59)

%H
Hour in 24-hour format (00-23)

%Y
Year with century, as a decimal number, up to 2099

%b
Abbreviated month name (3 chars)

%h
Abbreviated month name (3 chars)

%T
Time in HH:MM:SS format

%X
Time in HH:MM:SS format

%A
Day of the week, full name

%B
Month, full name

%C
"%a %b %e %H:%M:%S %Y"

%c
Date and time in "%m/%d/%y %H:%M:%S" format

%D
Date in "%m/%d/%y" format

%e
Day of month as decimal number (1-31) without leading zeros

%I
Hour in 12-hour format (01-12)

%j
Day of year as a decimal number (001-366)

%k
Hour in 24-hour format (0-23) without leading zeros

%l
Hour in 12-hour format (1-12) without leading zeros

%m
Month as a decimal number (01-12)

%n
Line feed

%p
a.m./p.m. indicator for 12-hour clock

%R
Time in "%H:%M" format

%r
Time in "%I:%M:%S %p" format

%t
Tab

%U
Week of year as a decimal number, with Sunday as first day of week (00-51)

%w
Weekday as a decimal number (0-6; Sunday is 0).

%W
Week of year as decimal number, with Monday as first day of week (00-51)

%x
Date in "%m/%d/%y" format

%y
Year without century, as decimal number (00-99)

%%
Percent sign
*/