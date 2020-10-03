#include <stdio.h>
#include <stdlib.h>

/* values of state variable */
#define WORD 0
#define FIRST_WHITESPACE 1

int main(){
    int c;
    int *nc;

    size_t max_number_of_words = 1000;
    int nw = 0;
    int state = FIRST_WHITESPACE;

    nc = calloc(max_number_of_words, sizeof(int));

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
        if (nw == max_number_of_words) {
            fputs("This program can work only with 1000 words", stderr);
            break;
        }
    }
    for (int a = 0; a < nw; ++a) {
        for (int b = 0; b < nc[a]; ++b) {
            putchar('#');
        }
        putchar('\n');
    }
    return 0;
}
