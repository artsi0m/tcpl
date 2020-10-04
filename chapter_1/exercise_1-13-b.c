#include <stdio.h>
#include <stdlib.h>

/* values of state variable */
#define WORD 0
#define FIRST_WHITESPACE 1

int main(){
    int c;
    int *nc;
    int **matrix;

    size_t max_number_of_words = 100;
    int nw = 0;
    int state = FIRST_WHITESPACE;

    nc = calloc(max_number_of_words, sizeof(int));
    matrix = calloc(max_number_of_words, sizeof(int *));
    for (int i = 0; i < (int) max_number_of_words; ++i) {
        matrix[i] = calloc(max_number_of_words, sizeof(int));
    }

    while ((c = getchar()) != EOF) {
        if (c != ' ' && c != '\t' && c != '\n') {
            state = WORD;
            ++nc[nw];
        } else {
            ++state;
            if (state == FIRST_WHITESPACE) {
                ++nw;
            }
        }
        if (nw == (int) max_number_of_words) {
            fputs("This program can work only with 1000 words", stderr);
            break;
        }
    }

    /* Filling matrix */
    for (int a = 0; a < (int) max_number_of_words; ++a) {
        for (int b = 0; b < nc[a]; ++b) {
            matrix[b][a] = '#';
        }
        for (int b = nc[a]; b < (int) max_number_of_words - 1; ++b) {
            matrix[b][a] = ' ';
        }
        matrix[(int) max_number_of_words][a] = '\n';
    }
    /* Printing matrix */
    for (int a = 0; a < (int) max_number_of_words; ++a) {
        for (int b = 0; b < (int) max_number_of_words; ++b) {
            putchar(matrix[a][b]);
        }
    }

    free(nc);
    for (int i = 0; i < (int) max_number_of_words; ++i) {
        free(*matrix);
    }
    free(matrix);
    return 0;
}
