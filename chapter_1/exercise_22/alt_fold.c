/*% cc -g -Wall -Wextra % getchararr.c -o #
 *
 */
#include <stdio.h>

#include "fns.h"
#define MAXLINE 1000
#define FOLDLINE 20

void	fold(char *, size_t, int);

int
main(void)
{
	int len;		/* current line length */
	char line[MAXLINE];

	while ((len = getchararr(line, MAXLINE)) > 0) {
		if (len > FOLDLINE) {
			fold(line, MAXLINE, FOLDLINE);
			fputs(line, stdout);
		} else {
			fputs(line, stdout);
		}
	}
}


void
fold(char s[], size_t len, int fold_lim)
{
	char *string_start = s;
	char *string_end = s+len;
	
	while ((s+= fold_lim) < string_end){
		while(s > string_start && *s != ' ' && *s != '\t') s--;
		if (s != string_start) {
			*s = '\n';
			string_start = (++s);
		}
 	}
}
