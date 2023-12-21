#include <stdio.h>
#include <time.h>

int main() {
    // Deklarasi variabel
    struct tm current_time;
    time_t current_seconds, one_hour_ago_seconds;

    // Mengambil waktu saat ini
    time(&current_seconds);
    localtime_r(&current_seconds, &current_time);

    // Mengurangi satu jam dari waktu saat ini
    current_time.tm_hour -= 1;  //1jam
    current_time.tm_min -=20;   //20menit

    // Mengkonversi kembali ke dalam format time_t
    one_hour_ago_seconds = mktime(&current_time);

    // Menampilkan waktu satu jam yang lalu
    printf("Waktu satu jam yang lalu: %s", asctime(&current_time));

    return 0;
}
