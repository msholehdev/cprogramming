#include <stdio.h>
#include <time.h>

int main() {
    // Deklarasi variabel
    struct tm current_time;
    time_t current_seconds, three_days_ago_seconds;

    // Mengambil waktu saat ini
    time(&current_seconds);
    localtime_r(&current_seconds, &current_time);

    // Mengurangi tiga hari dari tanggal saat ini
    current_time.tm_mday -= 3;

    // Mengkonversi kembali ke dalam format time_t
    three_days_ago_seconds = mktime(&current_time);

    // Menampilkan waktu tiga hari yang lalu
    printf("Waktu tiga hari yang lalu: %s", asctime(&current_time));

    return 0;
}
