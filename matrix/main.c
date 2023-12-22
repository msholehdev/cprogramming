#include <stdio.h>

// Fungsi untuk menampilkan matriks
void displayMatrix(int matrix[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}
// Fungsi untuk menampilkan matriks menggunakan pointer
void displayMatrix2(int *matrix) {
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            printf("%d ", *(matrix + i * 2 + j));
        }
        printf("\n");
    }
}
// Fungsi untuk menampilkan matriks menggunakan pointer
void displayMatrix_p(int *matrix) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%d ", *(matrix + i * 3 + j));
        }
        printf("\n");
    }
}
void displayMatrix_d(double *matrix) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%.2f ", *(matrix + i * 3 + j));
        }
        printf("\n");
    }
}

// Fungsi untuk menjumlahkan dua matriks
void addMatrix(int matrixA[3][3], int matrixB[3][3], int result[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            result[i][j] = matrixA[i][j] + matrixB[i][j];
        }
    }
}
// Fungsi untuk menjumlahkan dua matriks menggunakan pointer
void addMatrix_p(int *matrixA, int *matrixB, int *result) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            *(result + i * 3 + j) = *(matrixA + i * 3 + j) + *(matrixB + i * 3 + j);
        }
    }
}

// Ukuran matriks 3D
#define SIZE 3
// Fungsi untuk menampilkan matriks
void displayMatrix_multy(int *matrix) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            for (int k = 0; k < SIZE; k++) {
                printf("%d ", *(matrix + i * SIZE * SIZE + j * SIZE + k));
            }
            printf("\n");
        }
        printf("\n");
    }
}
// Fungsi untuk menjumlahkan dua matriks
void addMatrix_multy(int *matrixA, int *matrixB, int *result) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            for (int k = 0; k < SIZE; k++) {
                *(result + i * SIZE * SIZE + j * SIZE + k) = 
                    *(matrixA + i * SIZE * SIZE + j * SIZE + k) + 
                    *(matrixB + i * SIZE * SIZE + j * SIZE + k);
            }
        }
    }
}
// Fungsi untuk mengurangkan dua matriks
void subtractMatrix_multy(int *matrixA, int *matrixB, int *result) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            for (int k = 0; k < SIZE; k++) {
                *(result + i * SIZE * SIZE + j * SIZE + k) = 
                    *(matrixA + i * SIZE * SIZE + j * SIZE + k) - 
                    *(matrixB + i * SIZE * SIZE + j * SIZE + k);
            }
        }
    }
}
// Fungsi untuk mengalikan dua matriks
void multiplyMatrix_multy(int *matrixA, int *matrixB, int *result) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            for (int k = 0; k < SIZE; k++) {
                *(result + i * SIZE * SIZE + j * SIZE + k) = 0;
                for (int l = 0; l < SIZE; l++) {
                    *(result + i * SIZE * SIZE + j * SIZE + k) += 
                        *(matrixA + i * SIZE * SIZE + l * SIZE + k) * 
                        *(matrixB + l * SIZE * SIZE + j * SIZE + k);
                }
            }
        }
    }
}
// Transposisi Matriks: Membalik baris dan kolom matriks.
void transposeMatrix(int *matrix, int *result) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            *(result + j * SIZE + i) = *(matrix + i * SIZE + j);
        }
    }
}
//Determinan Matriks (hanya untuk matriks 2x2 dan 3x3 untuk sederhana):
/*
    Determinan matriks merupakan selisih antara perkalian elemen-elemen pada diagonal utama dengan perkalian elemen-elemen pada diagonal

    det A=  | a  b | = ad - bc
            | c  d |

            | a  b  c |
    det A=  | d  e  f | = (a.e.i + b.f.g + c.d.h) - (c.e.g + q.f.h +b.d.i)
            | g  h  i |

    atau bisa dengan det(A)=a(ei−fh)−b(di−fg)+c(dh−eg)
*/
int determinant2x2(int *matrix) {
    return *(matrix) * *(matrix + 3) - *(matrix + 1) * *(matrix + 2);
}
// Fungsi untuk menghitung determinan matriks 2x2
int determinant2x2_satuan(int a, int b, int c, int d) {
    return a * d - b * c;
}

int determinant3x3(int *matrix) {
    int det = (*(matrix) * (*(matrix + 4) * *(matrix + 8) - *(matrix + 5) * *(matrix + 7)))
              - (*(matrix + 1) * (*(matrix + 3) * *(matrix + 8) - *(matrix + 5) * *(matrix + 6)))
              + (*(matrix + 2) * (*(matrix + 3) * *(matrix + 7) - *(matrix + 4) * *(matrix + 6)));
    return det;
}

/* lebih mudah dipahami
int determinant3x3(int *matrix) {
    int a = *(matrix);
    int b = *(matrix + 1);
    int c = *(matrix + 2);
    int d = *(matrix + 3);
    int e = *(matrix + 4);
    int f = *(matrix + 5);
    int g = *(matrix + 6);
    int h = *(matrix + 7);
    int i = *(matrix + 8);
    
    int det = a * (e * i - f * h) - b * (d * i - f * g) + c * (d * h - e * g);
    return det;
}*/

//Invers Matriks: Menghitung matriks invers (khusus untuk matriks persegi).
void inverse2x2(int *matrix, int *result) {
    int det = determinant2x2(matrix);
    *(result) = *(matrix + 3) / det;
    *(result + 1) = -*(matrix + 1) / det;
    *(result + 2) = -*(matrix + 2) / det;
    *(result + 3) = *(matrix) / det;
}
void inverse3x3(int *matrix, double *result) {
    int det = determinant3x3(matrix);
    
    if (det == 0) {
        printf("Matriks tidak memiliki invers karena determinannya 0.\n");
        return;
    }

    *(result) = (double)(*(matrix + 4) * *(matrix + 8) - *(matrix + 5) * *(matrix + 7)) / det;
    *(result + 1) = (double)(*(matrix + 2) * *(matrix + 7) - *(matrix + 1) * *(matrix + 8)) / det;
    *(result + 2) = (double)(*(matrix + 1) * *(matrix + 5) - *(matrix) * *(matrix + 4)) / det;

    *(result + 3) = (double)(*(matrix + 5) * *(matrix + 6) - *(matrix + 3) * *(matrix + 8)) / det;
    *(result + 4) = (double)(*(matrix) * *(matrix + 8) - *(matrix + 2) * *(matrix + 6)) / det;
    *(result + 5) = (double)(*(matrix + 2) * *(matrix + 3) - *(matrix) * *(matrix + 5)) / det;

    *(result + 6) = (double)(*(matrix + 3) * *(matrix + 7) - *(matrix + 4) * *(matrix + 6)) / det;
    *(result + 7) = (double)(*(matrix + 1) * *(matrix + 6) - *(matrix) * *(matrix + 7)) / det;
    *(result + 8) = (double)(*(matrix) * *(matrix + 4) - *(matrix + 1) * *(matrix + 3)) / det;
}

void identityMatrix(int size, double *result) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (i == j) {
                *(result + i * size + j) = 1.0;
            } else {
                *(result + i * size + j) = 0.0;
            }
        }
    }
}
void adjugateMatrix(int *matrix, double *result) {
    // Karena implementasi ini adalah untuk matriks 3x3, kita hanya akan mengeksplisitkan kode untuk ukuran tersebut.
    // Anda bisa menggeneralisasi kode untuk ukuran matriks lainnya.
    
    *(result) = (double)(*(matrix + 4) * *(matrix + 8) - *(matrix + 5) * *(matrix + 7));
    *(result + 1) = - (double)(*(matrix + 3) * *(matrix + 8) - *(matrix + 5) * *(matrix + 6));
    *(result + 2) = (double)(*(matrix + 3) * *(matrix + 7) - *(matrix + 4) * *(matrix + 6));

    *(result + 3) = - (double)(*(matrix + 1) * *(matrix + 8) - *(matrix) * *(matrix + 7));
    *(result + 4) = (double)(*(matrix) * *(matrix + 8) - *(matrix + 2) * *(matrix + 6));
    *(result + 5) = - (double)(*(matrix) * *(matrix + 7) - *(matrix + 1) * *(matrix + 6));

    *(result + 6) = (double)(*(matrix + 1) * *(matrix + 5) - *(matrix) * *(matrix + 4));
    *(result + 7) = - (double)(*(matrix) * *(matrix + 5) - *(matrix + 2) * *(matrix + 3));
    *(result + 8) = (double)(*(matrix) * *(matrix + 4) - *(matrix + 1) * *(matrix + 3));
}

void cofactorMatrix(int *matrix, double *result) {
    int sign = 1;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            // Hitung determinan matriks minor
            int minor[4];
            int k = 0;
            for (int row = 0; row < 3; row++) {
                for (int col = 0; col < 3; col++) {
                    if (row != i && col != j) {
                        minor[k++] = *(matrix + row * 3 + col);
                    }
                }
            }
            int minorDet = determinant2x2_satuan(minor[0], minor[1], minor[2], minor[3]);
            
            *(result + i * 3 + j) = (double)(sign * minorDet);
            sign = -sign; // Ganti tanda untuk faktor kofaktor berikutnya
        }
        sign = -sign; // Ganti tanda untuk baris berikutnya
    }
}

int main() {
    int matrixA[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    int matrixB[3][3] = {
        {9, 8, 7},
        {6, 5, 4},
        {3, 2, 1}
    };

    int result[3][3];

    // Menampilkan matriks A dan B
    printf("Matrix A:\n");
    displayMatrix(matrixA);
    displayMatrix_p((int *)matrixA);

    printf("\nMatrix B:\n");
    displayMatrix(matrixB);
    displayMatrix_p((int *)matrixB);

    // Menjumlahkan matriks A dan B
    addMatrix(matrixA, matrixB, result);
    // Menampilkan hasil penjumlahan
    printf("\nHasil penjumlahan:\n");
    displayMatrix(result);

    addMatrix_p((int *)matrixA, (int *)matrixB, (int *)result);
    displayMatrix_p((int *)result);

    int matrixA3[3][3][3] = {
        {
            {1, 2, 3},
            {4, 5, 6},
            {7, 8, 9}
        },
        {
            {1, 2, 3},
            {4, 5, 6},
            {7, 8, 9}
        },
        {
            {1, 2, 3},
            {4, 5, 6},
            {7, 8, 9}
        }
    };

    int matrixB3[3][3][3] = {
        {
            {9, 8, 7},
            {6, 5, 4},
            {3, 2, 1}
        },
        {
            {9, 8, 7},
            {6, 5, 4},
            {3, 2, 1}
        },
        {
            {9, 8, 7},
            {6, 5, 4},
            {3, 2, 1}
        }
    };
    int result3[3][3][3];
    printf("\nHasil penjumlahan 3:\n");
    //multiplyMatrix_multy((int *)matrixA3, (int *)matrixB3, (int *)result3);
    //displayMatrix_multy((int *)result3);

    transposeMatrix((int *)matrixA, (int *)result);
    displayMatrix_p((int *)result);
    int A[2][2]={{2,5},{4,3}};
    
    int det2=determinant2x2((int *)A);
    printf("\ndeterminan 2:%d\n",det2);
    
    int matrix[3][3][3] = {
        {{1, 2, 3}, {2, 1, 4}, {3, 1, 2}}
    };

    int results = determinant3x3((int *)matrix);
    printf("Determinan dari matriks tersebut adalah: %d\n", results);

    printf("\nInvers:\n");
    int inv[2][2]={{4,1},{7,2}};
    int hasil[2][2];
    inverse2x2((int*)inv,(int *)hasil);
    displayMatrix2((int *)hasil);

    printf("\nInvers 3:\n");
    int inv3[3][3] = {
        {1, 2, 3}, {2, 8, 7}, {1, 5, 6}
    };
    double hasil3[3][3];
    inverse3x3((int*)inv3,(double *)hasil3);
    displayMatrix_d((double *)hasil3);

    int matrixid[3][3] = {
        {1, 2, 3},
        {2, 1, 4},
        {3, 1, 2}
    };

    double resultid[3][3];

    printf("Matriks yang diberikan:\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%d ", matrixid[i][j]);
        }
        printf("\n");
    }

    inverse3x3((int *)matrixid, (double *)resultid);
    printf("\nMatriks Invers:\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%.2f ", resultid[i][j]);
        }
        printf("\n");
    }

    printf("\nMatriks Identitas:\n");
    identityMatrix(3, (double *)resultid);
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%.2f ", resultid[i][j]);
        }
        printf("\n");
    }

    printf("\nMatriks Adjoin (Adjugate):\n");
    adjugateMatrix((int *)matrixid, (double *)resultid);
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%.2f ", resultid[i][j]);
        }
        printf("\n");
    }

    printf("\nMatriks Kofaktor:\n");
    cofactorMatrix((int *)matrixid, (double *)result);
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%.2f ", result[i][j]);
        }
        printf("\n");
    }
    return 0;
}

