#include"huffman.h"

int Compare_File() {
    FILE* inputfile = fopen("test.txt", "r");
    FILE* outputfile = fopen("OutputText.txt", "r");

    if (inputfile == NULL || outputfile == NULL) {
        printf("Error opening files. Please check if the files exist and try again.\n");
        exit(1);
    }

    char ch1;
    char ch2;

    while ((ch1 = fgetc(inputfile)) != EOF && (ch2 = fgetc(outputfile)) != EOF) {
        if (ch1 != ch2) {
            fclose(inputfile);
            fclose(outputfile);
            return 0;
        }
    }

    fclose(inputfile);
    fclose(outputfile);
    return 1;
}
