#include <stdio.h>

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
        ++ch[c];
    }

    for (int i = 0; i < 128; ++i) {
        if (i == '\n') {
            putchar('\\');
            putchar('n');
            put_shebang_line_for_each_char(ch[i]);
        } else if (i == '\t') {
            putchar('\\');
            putchar('t');
            put_shebang_line_for_each_char(ch[i]);
        } else if (i == '\b') {
            putchar('\\');
            putchar('b');
            put_shebang_line_for_each_char(ch[i]);
        } else {
            putchar(i);
            put_shebang_line_for_each_char(ch[i]);
        }
    }
    return 0;
}
