#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 100

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordFreq;

int findWord(WordFreq wordFreqs[], int size, const char *word) {
    for (int i = 0; i < size; i++) {
        if (strcmp(wordFreqs[i].word, word) == 0) {
            return i;
        }
    }
    return -1;
}

int main() {
    char paragraph[10000];
    WordFreq wordFreqs[MAX_WORDS];
    int wordCount = 0;

    printf("Enter a paragraph: ");
    fgets(paragraph, sizeof(paragraph), stdin);

    char *token = strtok(paragraph, " \t\n");
    while (token != NULL) {
        char word[MAX_WORD_LENGTH];
        int i = 0;

        while (token[i]) {
            word[i] = tolower(token[i]);
            i++;
        }
        word[i] = '\0';

        int index = findWord(wordFreqs, wordCount, word);
        if (index == -1) {
            strcpy(wordFreqs[wordCount].word, word);
            wordFreqs[wordCount].count = 1;
            wordCount++;
        } else {
            wordFreqs[index].count++;
        }

        token = strtok(NULL, " \t\n");
    }

    for (int i = 0; i < wordCount; i++) {
        printf("%s: %d\n", wordFreqs[i].word, wordFreqs[i].count);
    }

    return 0;
}
