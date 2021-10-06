#include <stdio.h>

#define BACKSLASH '\\'

int main(){
	int c;
	while((c = getchar()) != EOF){
		switch(c)
		{
			case '\b':
				putchar(BACKSLASH);
				putchar('b');
			break;
			case '\t':
				putchar(BACKSLASH);
				putchar('t');
			break;
			case BACKSLASH:
				putchar(BACKSLASH);
				putchar(BACKSLASH);
			break;
			default: 
				putchar(c);
		}
	};
	return 0;
}
