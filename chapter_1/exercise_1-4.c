#include <stdio.h>

#define LOWER -20
#define UPPER 20
#define STEP 1

int 
main(){
	int celsius;
	printf("CELSIUS \t FAHR \n");
	for (celsius = LOWER; celsius <= UPPER; celsius += STEP){
		printf("%3d \t %3f \n", celsius, (celsius / 5.0 * 9.0) + 32);
	}
}
