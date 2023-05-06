#include <stdio.h>
#include <string.h>

#define MAX_PHONE_LENGTH 20
#define MAX_COMPANIES 4

struct PhoneNumber {
    char number[MAX_PHONE_LENGTH];
    char company_code[4];
};

struct Company {
    char code[4];
    char name[15];
    int count;
};

int main() {
    char filename[] = "phone_numbers.txt";
    FILE *file = fopen(filename, "r");

    if (file == NULL) {
        printf("Error: unable to open file.\n");
        return 1;
    }

    struct Company companies[] = {
        {"019", "Banglalink", 0},
        {"016", "Airtel", 0},
        {"017", "Grameenphone", 0},
        {"018", "Robi", 0}
    };
    int num_companies = sizeof(companies) / sizeof(companies[0]);

    char phone[MAX_PHONE_LENGTH];
    int num_incorrect_formats = 0;

    while (fgets(phone, MAX_PHONE_LENGTH, file)) {
        // Remove newline character from phone number string
        int len = strlen(phone);
        if (len > 0 && phone[len-1] == '\n') {
            phone[len-1] = '\0';
        }

        // Check if phone number has correct format
        int has_correct_format = 0;
        for (int i = 0; i < num_companies; i++) {
            if (strncmp(phone, companies[i].code, 3) == 0) {
                has_correct_format = 1;
                strcpy(companies[i].code, companies[i].code);
                companies[i].count++;
                break;
            }
        }
        if (!has_correct_format) {
            printf("Incorrect phone number format: %s\n", phone);
            num_incorrect_formats++;
        }
    }

    fclose(file);

    // Find the company with the most incorrect formats
    int max_incorrect_formats = 0;
    char max_company[15];
    for (int i = 0; i < num_companies; i++) {
        if (companies[i].count > max_incorrect_formats) {
            max_incorrect_formats = companies[i].count;
            strcpy(max_company, companies[i].name);
        }
    }

    printf("\nNumber of incorrect formats: %d\n", num_incorrect_formats);
    printf("Company with the most incorrect formats: %s\n", max_company);

    return 0;
}
