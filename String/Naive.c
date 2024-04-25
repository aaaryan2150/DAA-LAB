#include<stdio.h>
#include<string.h>

void StringMatch(char* Pattern, char* Text){
    int TextLength = strlen(Text);
    int PatternLength = strlen(Pattern);
    int i,j;

    for(i=0;i<=TextLength-PatternLength;i++){
        for(j=0;j<PatternLength;j++){
            if(Text[i+j]!=Pattern[j]){
                break;
            }
        }
        if(j==PatternLength){
            printf("Match found at %d\n",i);
        }
    }
}

int main(){
    char text[] = "AABAACAADAABAAABAA";
    char pattern[] = "AABA";

    printf("Text %s\n",text);
    printf("Pattern %s\n",pattern);

    StringMatch(pattern,text);

    return 0;


}