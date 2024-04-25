#include<stdio.h>
#include<string.h>

void lpsgenerate(char pattern[],int m,int lps[]){
    int len = 0;
    lps[0] = 0;
    int i =1;
    while(i<m){
        if(pattern[i] == pattern[len]){
            len++;
            lps[i] = len;
            i++;
        }else{
            if(len!=0){
                len = lps[len - 1];
            }else{
                lps[i] = 0;
                i++;
            }
        }
    }
}

void kpmsearch(char text[],char pattern[]){
    int n = strlen(text);
    int m = strlen(pattern);
    int lps[m];

    lpsgenerate(pattern,m,lps);

    int i = 0;
    int j = 0;

    while(i<n){
        if(pattern[j]==text[i]){
            i++;
            j++;
        }
        if(j == m){
            printf("match found at %d\n",i-j);
            j = lps[j-1];
        }
        else if(i<n && pattern[j] != text[i]){
            if(j!=0){
                j = lps[j-1];
            }else{
                i++;
            }
        }
    }
}

int main() {
    char text[] = "bacbabababacaca";
    char pattern[] = "ababaca";

    printf("Text: %s\n", text);
    printf("Pattern: %s\n", pattern);

    kpmsearch(text, pattern);

    return 0;
}
