#include <stdio.h>

int main(){
	int c;
	unsigned spaces = 0;
	while((c = getchar()) != EOF){
		switch(c)
		{
			case ' ':
				++spaces;
				if (spaces == 1){
					putchar(' ');
				}
			break;
			default: 
				spaces = 0;
				putchar(c);
		}
	};
}
