#include <stdio.h>
#include <string.h>
#include <iostream>

void computeNext(char pattern[], int next[]) {
    int len = strlen(pattern);
    int i = 0, j = -1;
    next[0] = -1;

    while (i < len) {
        while (j >= 0 && pattern[i] != pattern[j]) {
            j = next[j];
        }
        i++;
        j++;
        next[i] = j;
    }
}

int kmpSearch(char text[], char pattern[], int next[], int* comparisons) {
    int textLen = strlen(text);
    int patternLen = strlen(pattern);
    int i = 0, j = 0;
    *comparisons = 0;

    while (i < textLen) {
        int f=0;
        while (j >= 0 && text[i] != pattern[j]) {
            j = next[j];
            f=1;
            (*comparisons)++;
        }
        if(f==0)(*comparisons)++;
        i++;
        j++;
        if (j == patternLen) {
            return i - j;  // Pattern found starting at index i-j
        }
    }

    return -1;  // Pattern not found
}

int main() {
    char text[] = "aaabbaabaaababb";
    char pattern[] = "aaabab";

    int patternLen = strlen(pattern);
    int* next = (int*)malloc((patternLen + 1) * sizeof(int));

    computeNext(pattern, next);

    printf("Next数组： ");
    for (int i = 0; i < patternLen ; i++) {
        printf("%d ", next[i]);
    }
    printf("\n");

    int comparisons;
    int position = kmpSearch(text, pattern, next, &comparisons);

    if (position != -1) {
        printf("模式在文本中的起始位置: %d\n", position);
        printf("比较次数: %d\n", comparisons);
    } else {
        printf("模式未在文本中找到\n");
        printf("比较次数: %d\n", comparisons);
    }
    free(next);
    
    return 0;
}
