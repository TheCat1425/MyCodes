#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CARS 100

typedef struct {
    char make[50];
    char model[50];
    int year;
    float price;
} Car;

void print_car(Car c) {
    printf("%s %s %d $%.2f\n", c.make, c.model, c.year, c.price);
}

void print_cars(Car cars[], int n) {
    for (int i = 0; i < n; i++) {
        print_car(cars[i]);
    }
}

void swap_cars(Car *a, Car *b) {
    Car tmp = *a;
    *a = *b;
    *b = tmp;
}

void sort_cars_by_year(Car cars[], int n) {
    for (int i = 0; i < n-1; i++) {
        for (int j = i+1; j < n; j++) {
            if (cars[j].year < cars[i].year) {
                swap_cars(&cars[i], &cars[j]);
            }
        }
    }
}

void sort_cars_by_price(Car cars[], int n) {
    for (int i = 0; i < n-1; i++) {
        for (int j = i+1; j < n; j++) {
            if (cars[j].price < cars[i].price) {
                swap_cars(&cars[i], &cars[j]);
            }
        }
    }
}

int main() {
    char filename[50], make[50], model[50];
    int option, year;
    float price;
    Car cars[MAX_CARS];
    int num_cars = 0;

    printf("Enter filename: ");
    scanf("%s", filename);

    FILE *fp = fopen(filename, "w");
    if (fp == NULL) {
        printf("Error: cannot open file %s\n", filename);
        exit(1);
    }

    while (fscanf(fp, "%s %s %d %f", cars[num_cars].make, cars[num_cars].model,
            &cars[num_cars].year, &cars[num_cars].price) == 4) {
        num_cars++;
        if (num_cars >= MAX_CARS) {
            break;
        }
    }

    fclose(fp);

    printf("Loaded %d cars from file.\n", num_cars);

    do {
        printf("\nMenu:\n");
        printf("1. List all cars\n");
        printf("2. Search cars by make\n");
        printf("3. Search cars by model\n");
        printf("4. Sort cars by year\n");
        printf("5. Sort cars by price\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &option);

      switch (option) {
        case 1:
            printf("\nAll cars:\n");
            print_cars(cars, num_cars);
            break;

        case 2:
            printf("\nEnter make to search: ");
            scanf("%s", make);
            int found = 0;
            for (int i = 0; i < num_cars; i++) {
                if (strcmp(cars[i].make, make) == 0) {
                    print_car(cars[i]);
                    found = 1;
                }
            }
            if (!found) {
                printf("No cars found.\n");
            }
            break;

        case 3:
            printf("\nEnter model to search: ");
            scanf("%s", model);
            found = 0;
            for (int i = 0; i < num_cars; i++) {
                if (strcmp(cars[i].model, model) == 0) {
                    print_car(cars[i]);
                    found = 1;
                }
            }
            if (!found) {
                printf("No cars found.\n");
            }
            break;

        case 4:
            printf("\nSorting cars by year...\n");
            sort_cars_by_year(cars, num_cars);
            printf("Cars sorted.\n");
            break;

        case 5:
            printf("\nSorting cars by price...\n");
            sort_cars_by_price(cars, num_cars);
            printf("Cars sorted.\n");
            break;

        case 6:
            printf("\nGoodbye!\n");
            break;

        default:
            printf("\nInvalid option. Please try again.\n");
            break;
    }
} while (option != 6);

return 0;
}
