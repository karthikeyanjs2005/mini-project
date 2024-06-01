#include <stdio.h>

void displayScore(int runs, int wickets, int overs, int balls) {
    printf("\nCurrent Score: %d/%d\n", runs, wickets);
    printf("Overs: %d.%d\n", overs, balls);
}

int main() {
    int runs = 0, wickets = 0, overs = 0, balls = 0;
    int max_overs, runs_scored;
    char event;

    // Get the maximum number of overs
    printf("Enter the maximum number of overs: ");
    scanf("%d", &max_overs);

    while (overs < max_overs && wickets < 10) {
        printf("\nEnter the event (r for runs, w for wicket, e for end): ");
        scanf(" %c", &event); // Space before %c to consume any newline character

        switch (event) {
            case 'r':
                printf("Enter runs scored: ");
                scanf("%d", &runs_scored);
                runs += runs_scored;
                balls++;
                if (balls == 6) {
                    balls = 0;
                    overs++;
                }
                break;

            case 'w':
                wickets++;
                balls++;
                if (balls == 6) {
                    balls = 0;
                    overs++;
                }
                break;

            case 'e':
                overs = max_overs;
                break;

            default:
                printf("Invalid event. Please enter 'r', 'w', or 'e'.\n");
                break;
        }

        displayScore(runs, wickets, overs, balls);
    }

    printf("\nFinal Score: %d/%d in %d.%d overs\n", runs, wickets, overs, balls);
    return 0;
}
