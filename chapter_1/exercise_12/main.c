#include <stdio.h>

int main(){
	int c;
	unsigned whitespace = 0;
	while((c = getchar()) != EOF){
			if(c == ' ' || c == '\t'){
				++whitespace;
				if (whitespace == 1){
					putchar('\n');
				}
			} else {
				whitespace = 0;
				putchar(c);
			}
	};
	return 0;
}

