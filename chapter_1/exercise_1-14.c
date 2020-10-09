#include <stdio.h>

int main()
{
    int c;
    int ch[128];
    for (int i = 0; i < 128; ++i) {
        ch[i] = 0;
    }
    while ((c = getchar()) != EOF) {
        ++ch[c];
    }
    for (int i = 0; i < 128; ++i) {
        if (i == '\n') {
            printf("\\n %d \n", ch[i]);
        } else if (i == '\t') {
            printf("\\t %d \n", ch[i]);
        } else if (i == '\b') {
            printf("\\b %d \n", ch[i]);
        } else {
            printf("%c %d \n", i, ch[i]);
        }
    }
    return 0;
}
