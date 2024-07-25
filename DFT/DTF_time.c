#include "../header/header.h"
#include "../header/fileio.h"
#include "../header/mathlib.h"
#include "../header/dft.h"
#include "../header/complex.h"


COMPLEX *DFT_Running(double *, int);


int main(int argc, char *argv[])
{
    int N = read_file_row(argv[1]);
    double *data = read_file_double(argv[1]);
    // printf("read file done (N = %d)\n", N);

    clock_t begin_DFT, end_DFT;
    begin_DFT = clock();
    COMPLEX *dft = DFT_Running(data, N);
    end_DFT = clock();
    // printf("DFT done\n");

    // output_complex_noLabel(dft, N, "output/DFT.csv");
    // printf("output DFT done\n");

    // printf("DFT execution time: %f\n", (double)(end_DFT - begin_DFT) / CLOCKS_PER_SEC);

    FILE *fp = fopen("output/DFT_time.csv", "a");
    fprintf(fp, "%.0f, %f\n", log2((double)N), (double)(end_DFT - begin_DFT) / CLOCKS_PER_SEC);
    fclose(fp);

    printf("%s done\n", argv[1]);

    return 0;
}




COMPLEX *DFT_Running(double *data, int N)
{
    COMPLEX *dft = DFT(data, N);
    return dft;
}
