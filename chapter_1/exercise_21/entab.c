#include <stdio.h>
#define TABSTOP 8

int
main(void)
{
	int c;
	int spaces = 0;
	int tabs = 0;
	while ((c = getchar()) != EOF) {
		if (c == ' ') {
			spaces++;
		} else {
			tabs = spaces / TABSTOP;
			spaces = spaces % TABSTOP;

			for (; tabs > 0; tabs--)
				putchar('\t');
			for (; spaces > 0; spaces--)
				putchar(' ');

			tabs = 0;
			spaces = 0;
			putchar(c);
		}
	}
}
