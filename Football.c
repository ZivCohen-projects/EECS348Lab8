#include <stdio.h>

int main() {
    int score;

    while (1) {
        printf("Enter the NFL score (Enter 1 to stop): ");
        scanf("%d", &score);
        if (score == 1) break;

        printf("Possible combinations of scoring plays if a team's score is %d:\n", score);

        for (int td2 = 0; td2 * 8 <= score; td2++) {
            for (int td1 = 0; td1 * 7 <= score - td2 * 8; td1++) {
                for (int td = 0; td * 6 <= score - td2 * 8 - td1 * 7; td++) {
                    for (int fg = 0; fg * 3 <= score - td2 * 8 - td1 * 7 - td * 6; fg++) {
                        int remaining = score - (td2 * 8 + td1 * 7 + td * 6 + fg * 3);
                        if (remaining % 2 == 0) {
                            int safety = remaining / 2;
                            printf("%d TD + 2pt, %d TD + FG, %d TD, %d 3pt FG, %d Safety\n",
                                   td2, td1, td, fg, safety);
                        }
                    }
                }
            }
        }
    }

    return 0;
}
