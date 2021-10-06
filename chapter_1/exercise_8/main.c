#include <stdio.h>


int main(){
	int c;
	unsigned spaces = 0;
	unsigned tabs = 0;
	unsigned lines = 0;
	while((c = getchar()) != EOF){
		switch(c)
		{
			case ' ':
				++spaces;
			break;
			case '\t':
				++tabs;
			break;
			case '\n':
				++lines;
			break;
		}
	};
	printf("Spaces: %d , tabs: %d, lines %d \n", spaces, tabs, lines); 
	return 0;
}
