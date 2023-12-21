#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main() {
    // Deklarasi variabel
    char date_str[20];  // Misalnya, format "yyyy-mm-dd"
    //char date_str[20] = "2023-12-23";
    struct tm date = {0};  // Inisialisasi dengan nol untuk menghindari sampah memori
    
    time_t timestamp;

    // Meminta pengguna untuk memasukkan tanggal dalam format string
    printf("Masukkan tanggal (format yyyy-mm-dd): ");
    scanf("%s", date_str);
    

    //jika ada strptime gunakan ini
    /*// Mengonversi string tanggal ke dalam struktur tm
    if (strptime(date_str, "%Y-%m-%d", &date) == NULL) {
        printf("Format tanggal salah!\n");
        return 1;
    }*/
    //jika tidak ada strptime
    // Mengisi komponen tanggal dari string
    sscanf(date_str, "%d-%d-%d", &date.tm_year, &date.tm_mon, &date.tm_mday);
    
    // Koreksi untuk format tm yang dimulai dari tahun 1900
    date.tm_year -= 1900;
    date.tm_mon -= 1;



    // Mengonversi struktur tm ke time_t
    timestamp = mktime(&date);

    // Menampilkan hasil
    printf("Tanggal dalam format time_t: %ld\n", (long)timestamp);

    //mengembalikan ke format date

    struct tm *tanggal;
    char tanggal_str[20];

    // Mengonversi timestamp ke dalam struktur tm dengan localtime
    tanggal = localtime((time_t *)&timestamp);

    // Mengkonversi struktur tm ke dalam format string
    //strftime(tanggal_str, sizeof(tanggal_str), "%Y-%m-%d", tanggal);
    sprintf(tanggal_str, "%04d-%02d-%02d", tanggal->tm_year + 1900, tanggal->tm_mon + 1, tanggal->tm_mday);


    // Menampilkan hasil
    printf("Tanggal dalam format yyyy-mm-dd: %s\n", tanggal_str);

    return 0;
}
