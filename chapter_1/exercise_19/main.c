#include <stdio.h>
#define MAXLINE 1000

int getchararr(char line[], int maxline);
void reverse(char s[]);

/* Reverse input a line at a time */
int
main(void)
{
	int len;		/* current line length */
	char line[MAXLINE];	/* current input line */

	while ((len = getchararr(line, MAXLINE)) > 0) {
	    if (len > 1)
	        reverse(line);
	    fputs(line, stdout);
	}
	return 0;
}

/* getchararr: read a line into s, return length */
int
getchararr(char s[], int lim)
{
	int c, i;

	for (i=0; i<lim-1 && (c = getchar()) != EOF && c != '\n'; ++i)
		s[i] = c;
	if (c == '\n') {
	    s[i] = c;
	    ++i;
	}
	s[i] = '\0';
	return i;
}

void
reverse(char *s)
{
	int i, j, k;
	i = 0;


	do { ++i; } while (s[i] != '\n');

	if (s[i] == '\n')
	    i--;

	for(j = 0; j < i; j++, i--){
	    k = s[i];
	    s[i] = s[j];
	    s[j] = k;
	}
}
