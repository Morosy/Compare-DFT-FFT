#include "header/header.h"
#include "header/fileio.h"
#include "header/mathlib.h"
#include "header/fft.h"

#include <time.h>
#include <math.h>

COMPLEX *FFT_Running(COMPLEX *, int);


int main(int argc, char *argv[])
{
    int N = read_file_row(argv[1]);
    double *data = read_file_double(argv[1]);
    // printf("read file done (N = %d)\n", N);

    COMPLEX *fft = double_To_COMPLEX(data, N);
    clock_t begin_FFT, end_FFT;
    begin_FFT = clock();
    fft = FFT_Running(fft, N);
    end_FFT = clock();
    // printf("FFT done\n");

    // output_complex_noLabel(fft, N, "output/FFT.csv");
    // printf("output FFT done\n");

    // printf("FFT execution time: %f\n", (double)(end_FFT - begin_FFT) / CLOCKS_PER_SEC);

    FILE *fp = fopen("output/FFT_time.csv", "a");
    fprintf(fp, "%.0f, %f\n", log2((double)N), (double)(end_FFT - begin_FFT) / CLOCKS_PER_SEC);
    fclose(fp);

    printf("%s done\n", argv[1]);
    return 0;
}

COMPLEX *FFT_Running(COMPLEX *data, int N)
{
    FFT(data, N);
    return data;
}
