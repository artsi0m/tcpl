#include <stdio.h>

#define MAXLEN 26
#define IN 1
#define OUT 0

int
main(){
    int c;
    
    unsigned state = OUT;
    unsigned wlen = 0;
    unsigned wbuf[MAXLEN];
    int x = 0;
    int y = 0;
    
    for(unsigned i = 0; i < MAXLEN; ++i){
        wbuf[i] = 0;
    }
    
    while((c = getchar()) != EOF){
        if (c != '\t' && c != ' ' && c != '\n'){
            state = IN;
            ++wlen;
        } else if( wlen > 0 && wlen < MAXLEN){
            ++wbuf[wlen];
            state = OUT;
            wlen = 0;
        }
    }
    

}
