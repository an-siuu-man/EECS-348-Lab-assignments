#include <stdio.h>
#include <string.h>

#define MONTHS 12

void swap(float *a, float *b, char str_a[], char str_b[]) {
    float tempf = *a;
    *a = *b;
    *b = tempf;

    char temps[10];
    strcpy(temps, str_a);
    strcpy(str_a, str_b);
    strcpy(str_b, temps);
}

void bubble_sort(float values[], char months[][10], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - 1 - i; j++) {
            if (values[j] < values[j + 1]) {
                swap(&values[j], &values[j + 1], months[j], months[j + 1]);
            }
        }
    }
}

void print_sales_report(float values[], char months[][10], int n) {
    printf("Sales Report (Highest to Lowest)\n\n");
    printf("%-12s%s\n", "Month", "Sales");

    for (int i = 0; i < n; i++) {
        printf("%-12s$%.2f\n", months[i], values[i]);
    }
}

void print_summary(float yearly_sales[], char months[][10]) {
    float highest = yearly_sales[0];
    float lowest = yearly_sales[0];
    int highest_month_index = 0;
    int lowest_month_index = 0;
    float sum = 0;

    for (int i = 0; i < MONTHS; i++) {
        if (yearly_sales[i] > highest) {
            highest = yearly_sales[i];
            highest_month_index = i;
        }
        if (yearly_sales[i] < lowest) {
            lowest = yearly_sales[i];
            lowest_month_index = i;
        }
        sum += yearly_sales[i];
    }

    float average = sum / MONTHS;

    printf("\nMaximum Sales: %s - $%.2f\n", months[highest_month_index], highest);
    printf("Minimum Sales: %s - $%.2f\n", months[lowest_month_index], lowest);
    printf("Average Sales: $%.2f\n", average);
}

void print_all(char months[][10], float yearly_sales[]) {
    for (int i = 0; i < MONTHS; i++) {
        printf("%-12s$%.2f\n", months[i], yearly_sales[i]);
    }
}

void six_month_report(char months[][10], float yearly_sales[], int n) {
    printf("Six-Month Moving Average Report:\n\n");

    for (int i = 0; i < n - 5; i++) {
        float sum = 0;

        for (int j = i; j < i + 6; j++) {
            sum += yearly_sales[j];
        }

        float avg = sum / 6;

        printf("%s - %s $%.2f\n", months[i], months[i + 5], avg);
    }
}

int main() {
    FILE *file;
    float yearly_sales[MONTHS];
    char months[MONTHS][10] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};

    file = fopen("numbers.txt", "r");

    if (file == NULL) {
        perror("Error opening file");
        return 1;
    }

    for (int i = 0; i < MONTHS; i++) {
        fscanf(file, "%f", &yearly_sales[i]);
    }

    fclose(file);

    printf("Original Yearly Sales Data:\n");
    print_all(months, yearly_sales);
    printf("\n");

    bubble_sort(yearly_sales, months, MONTHS);

    printf("Sorted Yearly Sales Data:\n");
    print_all(months, yearly_sales);
    printf("\n");

    six_month_report(months, yearly_sales, MONTHS);

    printf("\n");

    print_sales_report(yearly_sales, months, MONTHS);

    print_summary(yearly_sales, months);
    printf("\n");

    return 0;
}
