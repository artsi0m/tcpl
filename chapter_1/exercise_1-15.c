#include <stdio.h>

#define LOWER 0
#define UPPER 300
#define STEP 20

float celsius_from_fahr(int f)
{
    return (5.0 / 9.0) * (f - 32);
}
int 
main(){
	int fahr;
	printf("FAHR \t CELSIUS\n");
	for (fahr = UPPER; fahr >= LOWER; fahr -= STEP){
        printf("%3d \t %6.1f \n", fahr, celsius_from_fahr(fahr));
    }
	return 0;
}
