#include <stdio.h>

void get_combinations(int score) {
    int num_TD, num_TD_FG, num_TD_TD, num_TD_three, safety;

    for (num_TD = 0; score >= (8 * num_TD); num_TD++) {
        for (num_TD_FG = 0; score >= (8 * num_TD + 7 * num_TD_FG); num_TD_FG++) {
            for (num_TD_TD = 0; score >= (8 * num_TD + 7 * num_TD_FG + 6 * num_TD_TD); num_TD_TD++) {
                for (num_TD_three = 0; score >= (8 * num_TD + 7 * num_TD_FG + 6 * num_TD_TD + 3 * num_TD_three); num_TD_three++) {
                    for (safety = 0; score >= (8 * num_TD + 7 * num_TD_FG + 6 * num_TD_TD + 3 * num_TD_three + 2 * safety); safety++) {
                        if (score == (8 * num_TD + 7 * num_TD_FG + 6 * num_TD_TD + 3 * num_TD_three + 2 * safety)) {
                            printf("%d TD + 2pt, %d TD + FG, %d TD + %d 3pt FG, %d Safety\n", num_TD, num_TD_FG, num_TD_TD, num_TD_three, safety);
                        }
                    }
                }
            }
        }
    }
}

int main() {
    int score;

    while (1) {
        printf("Enter 0 or 1 to STOP\n");
        printf("Enter the NFL score: ");
        scanf("%d", &score);

        if (score == 0 || score == 1) {
            printf("Program ended. Goodbye.\n");
            break;
        } else if (score < 0) {
            printf("Invalid input. Please enter a non-negative score.\n");
        } else {
            printf("Possible combinations of scoring plays:\n");
            get_combinations(score);
        }
    }

    return 0;
}
