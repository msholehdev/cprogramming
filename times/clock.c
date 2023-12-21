#include <stdio.h>
#include <time.h>
#include <unistd.h>

int main(void){

    //Processor Ticks
    clock_t start_ticks = clock();
    clock_t end_ticks = clock();  
    printf("start_ticks = %li\nend_ticks   = %li\n", start_ticks, end_ticks);
    

    //Time
    time_t end_time;
    time_t start_time = time(NULL);
    sleep(1);
    time(&end_time);
    printf("start_time  = %lis\nend_time    = %lis\n", start_time, end_time);

    //Difference
    double interval = difftime(end_time, start_time);
    printf("difference  = %fs\n", interval);    
    
    clock_t start, end;
    double cpu_time_used;

    // Memulai pengukuran waktu
    start = clock();

    // Contoh operasi yang memakan waktu
    for (int i = 0; i < 1000000; i++) {
        // Lakukan sesuatu yang memerlukan waktu (misalnya, operasi matematika)
        double result = i * i;
        for (int j = 0; j < 1000; j++) {
            // Lakukan sesuatu yang memerlukan waktu (misalnya, operasi matematika)
            double result = j * j;
        }
    }

    // Mengakhiri pengukuran waktu
    end = clock();

    // Menghitung waktu yang dihabiskan dalam detik
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;

    printf("Waktu CPU yang dihabiskan: %f detik\n", cpu_time_used);


}

/*
Baik fungsi clock() maupun time() adalah bagian dari library standar C <time.h>, namun keduanya memiliki tujuan dan fungsi yang berbeda. Mari kita jelaskan perbedaan antara keduanya:

time():

Tujuan: Fungsi time() digunakan untuk mendapatkan waktu saat ini dalam detik sejak "epoch". "Epoch" adalah titik waktu yang didefinisikan sebagai pukul 00:00:00 UTC pada 1 Januari 1970 (dalam sistem Unix-like).
Format Keluaran: Hasil yang dikembalikan oleh time() adalah nilai bertipe time_t, yang biasanya merupakan detik sejak "epoch".
Penggunaan Umum: time() sering digunakan untuk mengetahui waktu saat ini atau sebagai referensi untuk mengukur durasi atau selisih waktu.
clock():

Tujuan: Fungsi clock() digunakan untuk mengukur waktu CPU yang telah dihabiskan oleh program dari saat dimulainya eksekusi program tersebut. Ini adalah cara untuk mendapatkan estimasi waktu proses (bukan waktu nyata seperti yang diberikan oleh time()).
Format Keluaran: Hasil yang dikembalikan oleh clock() biasanya dalam unit "tick" atau "cycle" CPU. Namun, unit ini bervariasi tergantung implementasi dan platform.
Penggunaan Umum: clock() sering digunakan untuk mengukur performa dan efisiensi dari suatu kode atau algoritma, karena bisa memberikan indikasi berapa banyak waktu CPU yang dihabiskan oleh kode tersebut.
Ringkasan:

time(): Memberikan waktu nyata dalam detik sejak "epoch". Digunakan untuk tujuan terkait kalender dan waktu.
clock(): Memberikan estimasi waktu CPU yang telah dihabiskan oleh program. Digunakan untuk tujuan pengukuran performa dan analisis waktu eksekusi kode.
Meskipun keduanya berhubungan dengan konsep waktu, fungsi time() dan clock() memiliki kegunaan dan aplikasi yang berbeda di dalam pemrograman.
*/