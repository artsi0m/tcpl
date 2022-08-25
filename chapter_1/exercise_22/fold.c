/*% cc -g -Wall -Wextra % getchararr.c -o #
 *
 */
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#include "fns.h"
#define MAXLINE 1000
#define FOLDLINE 20

void	fold(char *, size_t, size_t);
size_t newlinelen(const char *, size_t);

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


/* return length of the string till the newline */
size_t
newlinelen(const char *str, size_t maxlen)
{
    const char *cp;
    for(cp = str; maxlen != 0 && *cp != '\n'; cp++, maxlen--)
    	;

    return (size_t)(cp - str);
}

/* Fold line i.e. insert newlines into returned line  */
void
fold(char s[], size_t maxlen, size_t fold_lim)
{
    	size_t len_till_term = strnlen(s, maxlen);
	size_t len_till_newline = newlinelen(s, maxlen);

	if ((len_till_newline = newlinelen(s, maxlen)) > fold_lim){
    		while(s+len_till_newline < s+len_till_term){
        		s++;
        		if (*s == ' ' || *s == '\t')
         			*s = '\n';
        		else if (*s == '\n'){
            			s = s + len_till_newline;
        			break;
        		}
    		}
	}


}
