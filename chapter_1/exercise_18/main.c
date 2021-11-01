#include <stdio.h>
#include <string.h>
#define MAXLINE 1000 /* maximum input line size */

int getchararr(char line[], int maxline);

int
main(void)
{
	int len;            /* current line length */
	int max;            /* maximum length seen so far */
	char line[MAXLINE]; /* current input line */

	max = 0;
	while ((len = getchararr(line, MAXLINE)) > 0) {
		if (len > 1) {
			puts(line);
		}
	}
	return 0;
}

/* getchararr: read a line into s, return length */
int
getchararr(char s[], int lim)
{
	int c, i, j;
	i = j = 0;

	while ((c = getchar()) != EOF && c != '\n') {
		if (j < lim) {
			s[j++] = c;
		}
		if (c != ' ' && c != '\t') {
			i = j;
		}
	}

	if (c == 'n' && i++ < lim)
		s[i - 1] = '\n';
	s[(i < lim) ? i : lim - 1] = '\0';
	return i;
}
