#include <stdio.h>
#include <time.h>

int main() {
    // Deklarasi variabel
    time_t now;
    struct tm future_time;
    char buffer[80];

    // Mendapatkan waktu saat ini
    time(&now);

    // Menghitung waktu 10 hari ke depan
    now += 10 * 24 * 60 * 60;  // 10 hari * 24 jam/hari * 60 menit/jam * 60 detik/menit

    // Mengisi future_time dengan waktu yang telah dihitung
    localtime_r(&now, &future_time);

    // Format dan menampilkan tanggal 10 hari ke depan
    strftime(buffer, sizeof(buffer), "%Y-%m-%d", &future_time);
    printf("10 hari ke depan dari hari ini adalah: %s\n", buffer);

    return 0;
}
