#include <stdio.h>
#include <stdlib.h>

/* Values of state variable */
#define WORD 0
#define FIRST_WHITESPACE 1
#define MAX_ELEMENTS 25

int main()
{
    int c;
    int *nc;

    int state = FIRST_WHITESPACE;
    int nw = 0;
    size_t max_number_of_words = MAX_ELEMENTS;
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
        if (nw == (int) max_number_of_words) {
            fputs("This program can work only with 1000 words", stderr);
            break;
        }
    }

    for (int i = MAX_ELEMENTS; i > 0; --i) {
        for (int j = 0; j < MAX_ELEMENTS; ++j) {
            if (i <= nc[j]) {
                putchar('#');
            } else {
                putchar(' ');
            }
        }
        putchar('\n');
    }
    free(nc);
}
