#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void prefix_table(char pattern[], int prefix[], int n){
    prefix[0] = 0;
    int len = 0;
    int i = 1;      //從 1 開始判斷
    while(i < n){
        if(pattern[i] == pattern[len]){
            len += 1;
            prefix[i] = len;
            i += 1;
        }else{
            if(len > 0){
                len = prefix[len - 1];
            }else{
                prefix[i] = len;    //len = 0;
                ++i;
            }
        }
    }
}

void move_prefix_table(int prefix[], int n){
    for(int i = n-1; i > 0; --i){
        prefix[i] = prefix[i-1];
    }
    prefix[0] = -1;
}

void kmp_search(char text[], char pattern[]){
    int n = strlen(pattern);
    int *prefix = malloc(sizeof(int) * n);
    prefix_table(pattern, prefix, n);
    move_prefix_table(prefix, n);

    // text[i]   ,   len(text) = m
    // pattern[j],   len(pattern) = n
    int i = 0; 
    int j = 0;
    int m = strlen(text);
    while(i < m){
        if(j == n-1 && text[i] == pattern[j]){
            printf("Found pattern at %d\n", i - j);
            j = prefix[j];
            if(j == -1){
                i++; j++;
            }
        }
        if(text[i] == pattern[j]){
            i++; j++;
        }else{
            j = prefix[j];
            if(j == -1){
                i++; j++;
            }
        }
    }
}
int main(){
    char pattern[] = "A";
    char text[] =    "ABCABCABDC";
    kmp_search(text, pattern);
/*
    int prefix[6];
    int n = 6;

    prefix_table(pattern, prefix, n);
    move_prefix_table(prefix, 6);

    for(int i = 0; i < 9; ++i){
        printf("%d\n", prefix[i]);
    }
*/
    return 0;
}
