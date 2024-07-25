#ifndef FFT_H
#define FFT_H

#include "header.h"
#include "complex.h"
#include "mathlib.h"


/*
    @brief FFT
    @param 関数の値
    @param 関数の要素数
*/
void FFT(COMPLEX *, int );
// COMPLEX *FFT(double* input, int N);

/*
    @brief 逆FFT
    @param COMPLEX型の関数
    @param 関数の要素数
*/
// void iFFT(COMPLEX *data, int N);

/*
    @brief 逆FFT
    @param COMPLEX型の関数
    @param 関数の要素数
*/
void iFFT(COMPLEX *, int );

void swap(COMPLEX *, COMPLEX *);
void bitReverse(COMPLEX *, int);

/*
    @brief 逆FFTの実行結果をソート
    @param 関数
    @param 関数の要素数
    @return ソートの結果
*/
double *sort_iFFT(double *, int);




void swap(COMPLEX *a, COMPLEX *b){
    COMPLEX temp = *a;
    *a = *b;
    *b = temp;
}



void bitReverse(COMPLEX *data, int N) {
    int i, j, k;
    for (i = 1, j = 0; i < N; i++) {
        for (k = N >> 1; k > (j ^= k); k >>= 1);
        if (i < j) {
            COMPLEX temp = data[i];
            data[i] = data[j];
            data[j] = temp;
        }
    }
}

void FFT(COMPLEX *data, int N){
    if (N <= 1) return;

    COMPLEX *data_even = (COMPLEX *)malloc(sizeof(COMPLEX) * (N / 2));
    COMPLEX *data_odd = (COMPLEX *)malloc(sizeof(COMPLEX) * (N / 2));

    for (int i = 0; i < N / 2; i++) {
        data_even[i] = data[2 * i];
        data_odd[i] = data[2 * i + 1];
    }

    FFT(data_even, N / 2);
    FFT(data_odd, N / 2);

    for (int k = 0; k < N / 2; k++) {
        double theta = -2 * M_PI * k / N;
        COMPLEX t = {data_odd[k].real * cos(theta) - data_odd[k].imaginary * sin(theta),
                      data_odd[k].real * sin(theta) + data_odd[k].imaginary * cos(theta)};
        data[k].real = data_even[k].real + t.real;
        data[k].imaginary = data_even[k].imaginary + t.imaginary;
        data[k + N / 2].real = data_even[k].real - t.real;
        data[k + N / 2].imaginary = data_even[k].imaginary - t.imaginary;
    }

    free(data_even);
    free(data_odd);
}



void iFFT(COMPLEX *data, int N) {
    bitReverse(data, N);
    double pi = acos(-1);
    for(int s = 1; (1 << s) <= N; s++) {
        int m = 1 << s;
        int m2 = m >> 1;
        COMPLEX w, wm;
        wm.real = cos(pi / m2);
        wm.imaginary = -sin(pi / m2);
        for(int k = 0; k < N; k += m) {
            COMPLEX e = {1, 0};
            for(int j = 0; j < m2; j++) {
                COMPLEX t, u;
                t.real = e.real * data[k + j + m2].real - e.imaginary * data[k + j + m2].imaginary;
                t.imaginary = e.real * data[k + j + m2].imaginary + e.imaginary * data[k + j + m2].real;
                u.real = data[k + j].real - t.real;
                u.imaginary = data[k + j].imaginary - t.imaginary;
                data[k + j].real = data[k + j].real + t.real;
                data[k + j].imaginary = data[k + j].imaginary + t.imaginary;
                data[k + j + m2] = u;
                COMPLEX next;
                next.real = e.real * wm.real - e.imaginary * wm.imaginary;
                next.imaginary = e.real * wm.imaginary + e.imaginary * wm.real;
                e = next;
            }
        }
    }
    for(int i = 0; i < N; i++){
        data[i].real /= N;
        data[i].imaginary /= N;
    }
}


// void ifft(const COMPLEX* coeffs, int coeffs_size, double* output)
// {
//     int N = coeffs_size;
//     double omega_conj = 2 * M_PI / N;
//     double vector;

//     for(int n = 0; n < N; n++) {
//         output[n] = 0;
//         for(int k = 0; k < N; k++) {
//             vector = (double)n * (double)k * omega_conj;
//             COMPLEX multi;
//             multi.real = cos(vector);
//             multi.imaginary = sin(vector);
//             COMPLEX term = MUL(coeffs[k], multi);
//             output[n] += term.real;
//         }
//         output[n] /= N;
//     }
// }




double *sort_iFFT(double *data, int N)
{
    double *output = (double *)malloc(sizeof(double) * N);
    output[0] = data[0];
    for(int i = 1; i < N; i++){
        output[i] = data[N - i];
    }
    return output;
}



#endif
