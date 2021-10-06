#include <stdio.h>

#define FIRST_PRINTABLE_CHAR 33
#define LAST_PRINTABLE_CHAR 127

void put_shebang_line_for_each_char(int c)
{
    putchar(' ');
    for (int i = 0; i < c; ++i) {
        putchar('#');
    }
    putchar('\n');
}

int main()
{
    int c;
    int ch[128];

    for (int i = 0; i < 128; ++i) {
        ch[i] = 0;
    }

    while ((c = getchar()) != EOF) {
        if (c > 0 && c < 128) {
            ++ch[c];
        }
    }

    for (int i = FIRST_PRINTABLE_CHAR; i < LAST_PRINTABLE_CHAR; ++i) {
        putchar(i);
        put_shebang_line_for_each_char(ch[i]);
    }
    return 0;
}
