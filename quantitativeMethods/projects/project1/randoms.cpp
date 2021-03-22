#include <stdio.h>
#include <math.h>
#include <string>
using namespace std;

void print_usage(char *file_name) {
    fprintf (
        stderr,
        "usage: %s <input file> -l <n of numbers|100> -o <output file>",
        file_name
    );
}

int main(int argc, char *argv[]) {
    int size = 100;
    FILE *INPUT_FILE;
    FILE *OUTPUT_FILE;

    if((INPUT_FILE = fopen(argv[1], "r")) == NULL)
        fprintf(stderr, "Could not open file %s", argv[2]);

    if((OUTPUT_FILE = fopen(argv[2], "w")) == NULL)
        fprintf(stderr, "Could not open file %s", argv[2]);

    float randoms[size], *ptr = randoms;
    bool signs[size-1], *sign_ptr = signs;

    fprintf(stdout, "Fetching numbers from input file...\n");
    while(fscanf(INPUT_FILE, "%f", ptr) > 0) {
        if(*(ptr-1)) {
            (*ptr >= *(ptr-1))? *sign_ptr=false: *sign_ptr=true;
            (*sign_ptr)? printf("+"): printf("-");
            sign_ptr++;
        }
        ptr++;
    }

    fprintf(stdout, "\nAnalysing classes...\n");
    int c = 10;
    float w = 0.10;
    int classes[c] = {0};

    for(auto ptr:randoms) {
        classes[int(floor(ptr/w))]++;
    }

    int ei = size/c;
    float chi = 0.0;

    fprintf(stdout, "ei: %i; %i classes: ", ei, c);
    for(int i = 0; i < c; i++) {
        chi += pow(classes[i]-ei,2)/ei;
        fprintf(stdout, "%i,", classes[i]);
    }
    fprintf(stdout, "; chi: %f\n", chi);

    int runs = 0;
    for(int i=1; i<size;i++) {
        if(signs[i-1] != signs[i])
            runs++;
    }

    float miuR = (2*size-1)/3;
    float omega = (16*size-29)/90;
    float omegaSq = sqrtf(omega);
    float zr = abs((runs-miuR)/omegaSq);

    fprintf (
        OUTPUT_FILE,
        "Chi: %f\nMiuR: %f\nRuns: %i\nStandard Dev: %f\nZR: %f\n",
        chi, miuR, runs, omegaSq, zr
    );

    // CHI
    (chi < 16.9190)?
    fprintf (
        OUTPUT_FILE,
        "Ho: Considering we use alpha as 0.5 and our degrees of freedom are 9 = 16.9190\n Ho is not rejected because chi %f is less than 16.9190.\n", chi
    ):
    fprintf (
        OUTPUT_FILE,
        "Ho: Considering we use alpha as 0.5 and our degrees of freedom are 3 = 16.9190\n Ho is rejected because chi %f is more than 16.9190.\n", chi
    );

    (chi < 16.9190)?
    fprintf (
        stdout,
        "Ho: Considering we use alpha as 0.5 and our degrees of freedom are 9 = 16.9190\n Ho is not rejected because chi %f is less than 16.9190.\n", chi
    ):
    fprintf (
        stdout,
        "Ho: Considering we use alpha as 0.5 and our degrees of freedom are 3 = 16.9190\n Ho is rejected because chi %f is more than 16.9190.\n", chi
    );

    // Z
    (zr > -1.96 && zr < 1.96)?
    fprintf (
        OUTPUT_FILE,
        "Ho: Considering we use alpha as 0.5 so z = -1.96/1.96\n Ho is not rejected because ourzr %f is between -1.96, 1.96.\n", zr
    ):
    fprintf (
        OUTPUT_FILE,
        "Ho: Considering we use alpha as 0.5 so z = -1.96/1.96\n Ho is rejected because our zr %f is between -1.96, 1.96.\n", zr
    );

    (zr > -1.96 && zr < 1.96)?
    fprintf (
        stdout,
        "Ho: Considering we use alpha as 0.5 so z = -1.96/1.96\n Ho is not rejected because ourzr %f is between -1.96, 1.96.\n", zr
    ):
    fprintf (
        stdout,
        "Ho: Considering we use alpha as 0.5 so z = -1.96/1.96\n Ho is rejected because our zr %f is between -1.96, 1.96.\n", zr
    );


    for(auto sign_ptr: signs)
        (sign_ptr)? fprintf(OUTPUT_FILE, "+"): fprintf(OUTPUT_FILE, "-");

    fprintf(OUTPUT_FILE, "\n");

    fclose(INPUT_FILE);
    fclose(OUTPUT_FILE);

    return 0;
}
