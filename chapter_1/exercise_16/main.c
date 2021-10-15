#include <stdio.h>
#include <string.h>
#define MAXLINE 1000 /* maximum input line size */

int getchararr(char line[], int maxline);
void copy(char to[], char from[]);

int
main(void)
{
	int len;		/* current line length */
	int max;		/* maximum length seen so far */
	char line[MAXLINE];	/* current input line */
	char longest[MAXLINE];

	max = 0;
	while ((len = getchararr(line, MAXLINE)) > 0){
	    if (len > max) {
		max = len;
		copy(longest, line);
	    }
	}

	if (max > 0){ /* there was a line */
	    if (longest[max-1] == '\n'){
		max = max - 1;
		}
	    printf("%d: %s", max , longest);
	}
	
	return 0;
}

/* getchararr: read a line into s, return length */
int
getchararr(char s[], int lim)
{
	int c, i;

	for (i=0; i<lim-1 && (c=getchar()) != EOF && c != '\n'; ++i)
	    s[i] = c;
	if (c == '\n') {
		s[i] = c;
		++i;
	}
	s[i] = '\0';
	return i;
}

/* copy: copy 'from' into 'to'; assume to is big enough */
void
copy(char to[], char from[])
{
	int i;

	i = 0;
	while ((to[i] = from[i]) != '\0')
		++i;
}
