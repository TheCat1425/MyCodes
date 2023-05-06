#include <stdio.h>

int sum_of_digits(int n) {
    int sum = 0;
    while (n > 0) {
        sum += n % 10;
        n /= 10;
    }
    return sum;
}

int main() {
    int numbers[] = {123, 456, 789, 555, 444, 123};
    int num_numbers = sizeof(numbers) / sizeof(numbers[0]);
    int total_sum_digits = 0;
    int total_sum_numbers = 0;
    int distinct_numbers[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    int num_distinct_numbers = 0;

    // Compute sum of digits for each number
    for (int i = 0; i < num_numbers; i++) {
        int sum_digits = sum_of_digits(numbers[i]);
        total_sum_digits += sum_digits;
        total_sum_numbers += numbers[i];

        // Check if number is distinct
        int distinct = 1;
        for (int j = 0; j < num_distinct_numbers; j++) {
            if (numbers[i] == distinct_numbers[j]) {
                distinct = 0;
                break;
            }
        }
        if (distinct) {
            distinct_numbers[num_distinct_numbers] = numbers[i];
            num_distinct_numbers++;
        }

        // Print sum of digits for this number
        printf("Sum of digits for number %d: %d\n", numbers[i], sum_digits);
    }

    // Print total sum of digits and total sum of numbers
    printf("Total sum of digits: %d\n", total_sum_digits);
    printf("Total sum of numbers: %d\n", total_sum_numbers);

    // Compute sum of distinct numbers
    int sum_distinct_numbers = 0;
    for (int i = 0; i < num_distinct_numbers; i++) {
        sum_distinct_numbers += distinct_numbers[i];
    }

    // Compare total sum of digits and total sum of numbers
    if (total_sum_digits > total_sum_numbers) {
        printf("Sum of digits is greater than sum of numbers.\n");
    } else if (total_sum_digits < total_sum_numbers) {
        printf("Sum of numbers is greater than sum of digits.\n");
    } else {
        printf("Sum of digits is equal to sum of numbers.\n");
    }

    // Print sum of distinct numbers
    printf("Sum of distinct numbers: %d\n", sum_distinct_numbers);

    return 0;
}
