#include <stdio.h>
#include <sys/time.h>

int main() {
    struct timeval current_time;
    double microseconds;

    // Mendapatkan waktu saat ini dengan presisi mikrodetik
    gettimeofday(&current_time, NULL);

    // Menghitung waktu dalam format detik + mikrodetik
    microseconds = (double) current_time.tv_sec + (double) current_time.tv_usec / 1000000.0;

    printf("Waktu saat ini dengan presisi mikrodetik: %lf detik\n", microseconds);

    return 0;
}
