#include <stdio.h>

int
main(){
	int c;
	printf("%d \n", ((c = getchar()) != EOF)); 
	return 0;
}

/* Any character - 1
 * EOF (Ctrl-D)  - 0 
 */
