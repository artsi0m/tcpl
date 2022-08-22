/*% cc -g -Wall -Wextra % getchararr.c -o #
 *
 */
#include <stdio.h>

#include "fns.h"
#define MAXLINE 1000
#define FOLDLINE 20

void	fold(char *, char *, int);

int
main(void)
{
	int len;		/* current line length */
	char line[MAXLINE];
	char folded_line[MAXLINE];

	while ((len = getchararr(line, MAXLINE)) > 0) {
		if (len > FOLDLINE) {
			fold(folded_line, line, FOLDLINE);
			fputs(folded_line, stdout);
		} else {
			fputs(line, stdout);
		}
	}
}

/* Fold line i.e. insert newlines into returned line  */
void
fold(char ret[], char s[], int fold_lim)
{
	/*
	 * i -- counter for position in s[]
	 * j -- counter for unfolded part of ret[]
	 * k -- counter for position in s[] in second pass
	 * l -- number of folds in ret[] in a second pass
	 */
	int i, j, k, l;
	int space_position = 0;

	for (i = 0, j = 0; i < MAXLINE - 1; ++i, ++j) {
		ret[i] = s[i];

		if ((s[i] == ' ' || s[i] == '\t') && j < fold_lim)
			space_position = i;

		if (j > fold_lim && space_position != 0) {
			ret[space_position] = '\n';
			j = 0;
		}
	}

	if (j > fold_lim) {
		for (i = 0, k = 0; i < MAXLINE - 1; ++i, ++k) {
			ret[i] = s[k];

			if (i % fold_lim == 0) {
				l = i / fold_lim;
				ret[fold_lim * l] = '\n';
				k--;
			}
		}
	}
}
