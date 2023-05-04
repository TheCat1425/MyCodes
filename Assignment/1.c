#include <stdio.h>
#include <string.h>
#include<ctype.h>

#define MAX_WORDS 100
#define MAX_LENGTH 50

int is_vowel(char c) {
    char vowels[] = "aeiouAEIOU";
    for (int i = 0; i < strlen(vowels); i++) {
        if (c == vowels[i]) {
            return 1;
        }
    }
    return 0;
}

int is_consonant(char c) {
    return isalpha(c) && !is_vowel(c);
}

int count_vowels(char* word) {
    int count = 0;
    for (int i = 0; i < strlen(word); i++) {
        if (is_vowel(word[i])) {
            count++;
        }
    }
    return count;
}

int count_consonants(char* word) {
    int count = 0;
    for (int i = 0; i < strlen(word); i++) {
        if (is_consonant(word[i])) {
            count++;
        }
    }
    return count;
}

int main() {
       char words[MAX_WORDS][MAX_LENGTH];
    int num_words = 0;

    // read input
    printf("Enter words (press Ctrl+D or Ctrl+Z (+[Enter] if you're using VSCODE)  to end):\n");
    while (scanf("%s", words[num_words]) == 1) {
        num_words++;
        if (num_words >= MAX_WORDS) {
            break;
        }
    }
    int max_length = 0;
    char longest_word[MAX_LENGTH] = "";
    for (int i = 0; i < num_words; i++) {
        int num_vowels = count_vowels(words[i]);
        int num_consonants = count_consonants(words[i]);
        if (num_vowels >= 3 && num_consonants >= 3 && strlen(words[i]) > max_length) {
            max_length = strlen(words[i]);
            strcpy(longest_word, words[i]);
        }
    }
    if (strlen(longest_word) > 0) {
        printf("The longest word with at least 3 vowels and 3 consonants is: %s\n", longest_word);
    } else {
        printf("No word with at least 3 vowels and 3 consonants was found.\n");
    }
    return 0;
}
