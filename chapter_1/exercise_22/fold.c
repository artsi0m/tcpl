/*% cc -g -Wall -Wextra % getchararr.c -o #
 *
 */
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#include "fns.h"
#define MAXLINE 1000
#define FOLDLINE 60

void	fold(char *, size_t, size_t);
size_t newlinelen(const char *, size_t);
void 	insertnewline(char *, size_t, size_t);

int
main(void)
{
	int len;		/* current line length */
	char line[MAXLINE];

	while ((len = getchararr(line, MAXLINE)) > 0) {
		if (len > FOLDLINE) {
    			fold(line, FOLDLINE, MAXLINE);
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

void
insertnewline(char *str, size_t pos, size_t maxlen)
{
	memmove(str + pos + 1, str + pos, strnlen(str + pos, maxlen));
	str[pos] = '\n';
}

/* Fold line i.e. insert newlines into returned line  */
void
fold(char s[], size_t fold_lim, size_t maxlen)
{
    	size_t len_till_term;
	size_t len_till_newline;

	char *sa = s;
	char *sb = s;

	for (len_till_term = strnlen(sa,maxlen); 
		len_till_term > fold_lim; sa++){
			if(*sa == ' ' || *sa == '\t'){
				*sa = '\n';
				len_till_term = strnlen(sa, maxlen);
 			}
	}

	for (len_till_newline = newlinelen(sb, maxlen);
		*sb != '\0' ; sb++){
		if(*sb == '\n'){
			sb = sb + len_till_newline;
			len_till_newline = newlinelen(sb, maxlen);
		}

		if(len_till_newline > fold_lim){
			insertnewline(sb, fold_lim, maxlen);
			sb = sb + len_till_newline;
			len_till_newline = newlinelen(sb, maxlen);
			
		}
	}

}
