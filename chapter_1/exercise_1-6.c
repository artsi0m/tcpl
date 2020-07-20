#include <stdio.h>

int
main(){
	int c;
	printf("%d \n", ((c = getchar()) != EOF)); 
}

/* Any character - 1
 * EOF (Ctrl-D)  - 0 
 */
