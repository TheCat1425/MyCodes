#include <stdio.h>
#include <string.h>

void check_palindrome(char str[], int start, int end, int *flag) {
    if (start >= end) { // base case
        *flag = 1;
        return;
    }
    if (str[start] == str[end]) {
        check_palindrome(str, start+1, end-1, flag);
    }
    else {
        *flag = 0;
        return;
    }
}

void insert_dollar(char str[], int i, int len) {
    if (i >= len) { // base case
        printf("$");
        return;
    }
    printf("%c", str[i]);
    if (i < len-1) {
        printf("$$$");
    }
    insert_dollar(str, i+1, len);
}

int main() {
    char str[100];
    int flag = 0;
    printf("Enter a string: ");
    scanf("%s", str);
    int len = strlen(str);
    check_palindrome(str, 0, len-1, &flag);
    if (flag == 1) {
        printf("The string is a palindrome.\nAfter inserting $: ");
        printf("$");
        insert_dollar(str, 0, len);
        printf("$\n");
    }
    else {
        printf("The string is not a palindrome.\n");
    }
    return 0;
}
