#include<stdio.h>
#include<string.h>

#define q 101
#define d 256

void rabinkarp(char* text , char* pattern){
    int textLength = strlen(text);
    int patternLength = strlen(pattern);
    int i,j;
    int h = 1;
    int p = 0;
    int t0 = 0;

    //calculating d^m-1 mod q
    for(i=0;i<patternLength-1;i++){
        h = (h*d)%q;
    }

    //calculating hash value
    for (i = 0; i<patternLength;i++){
        p = (p*d + pattern[i])%q;
        t0 = (t0*d + text[i])%q;
    }

    for(i=0;i<=textLength-patternLength;i++){
        if(p == t0){
            for(j=0;j<patternLength;j++){
                if(text[i+j]!=pattern[j]){
                    break;
                }
            }
            if(j == patternLength){
                printf("match found at %d\n",i);
            }
        }
        if(i<textLength-patternLength){
            t0 = (d*(t0 - text[i]*h)+text[i+patternLength])%q;
            
        }
        if(t0<0){
            t0 = t0+q;
        }
    }

}

int main() {
    char text[] = "AABAACAADAABAAABAA";
    char pattern[] = "CAAD";

    printf("Text: %s\n", text);
    printf("Pattern: %s\n", pattern);

    rabinkarp(text, pattern);

    return 0;
}
