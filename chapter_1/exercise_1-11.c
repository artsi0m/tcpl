#include <assert.h>
#include <stdio.h>

int
main(){
	FILE *f;
	unsigned long i;
	unsinged long up_lim = 66000ul;

	/* input file with zero words */
	f = fopen("test0", "w");
	assert(f != NULL);
	fclose(f);

	/* input file with one enourmous word */
	f = fopen("test1", "w");
	assert(f != NULL);
	for (i = 0; i < up_lim; ++i){
		fputc('A', f);
	}
	fclose(f);

	/* input file with one enourmous word in unicode */
	f = fopen("test1-b", "w");
	assert(f != NULL);
	for (i = 0; i < up_lim; ++i){
		fputc('á', f);
	}
	fclose(f);

	/* input file with all whitespace */
	f = fopen("test", "w");
	assert(f != NULL);
	for (i = 0; i < up_lim; ++i){
		fputc('\t', f);	
	}
	fclose(f);

	/* input file with 66000 newlines */
	f = fopen("test", "w");
	assert(f != NULL);
	for (i = 0; i < up_lim; ++i){
		fputc('\n', f);
	}
	fclose(f);
	
	/* word , whitespaces and word */
	f = fopen("test", "w");
	assert(f != NULL);
	fprintf(f, "long");
	for (i = 0; i < (up_lim / 3); ++i){
		fputc(' ', f);
	}
	for (i = 0; i < (up_lim / 3); ++i){
		fputc('\t', f);
	}
	for (i = 0; i < (up_lim / 3); ++i){
		fputc(' ', f)
	}
	fprintf(f, "word");
	fclose(f);

	/* 66000 single letter words, 66 to line */
	f = fopen("test", "w");
	assert(f != NULL);
	for (i = 0; i < (up_lim / 22); ++i){
		fputs("A A A A A A A A A A A A A A A A A A A A A A ");
	}
	fclose(f);

	/* 66000 words without newlines */
	f = fopen("test", "w");
	assert(f != NULL);
	for (i = 0; i < up_lim; ++i){
		fprintf(f, "long_word");
	}
	fclose(f);
}
