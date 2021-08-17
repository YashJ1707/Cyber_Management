#include <stdio.h>
#include <time.h>

void setTimeout(int milliseconds)
{
    // If milliseconds is less or equal to 0
    // will be simple return from function without throw error
    if (milliseconds <= 0)
    {
        fprintf(stderr, "Count milliseconds for timeout is less or equal to 0\n");
        return;
    }

    // a current time of milliseconds
    int milliseconds_since = clock() * 1000 / CLOCKS_PER_SEC;

    // needed count milliseconds of return from this timeout
    int end = milliseconds_since + milliseconds;

    // wait while until needed time comes
    do
    {
        milliseconds_since = clock() * 1000 / CLOCKS_PER_SEC;
    } while (milliseconds_since <= end);
}
int time_remainging()
{
    int time, flag, cost;
recharge:
    printf("Choose a plan from the following\n");
    printf("Cost for one hour is Rs.10\n");
    printf("Enter the number of hours you want to top-up\n");
    scanf("%d", &time);
    printf("Do you want to use internet facility? (Rs.5/hour)\n1.Yes\t0.No\n");
    scanf("%d", &flag);
    if (flag == 1)
    {
        cost = time * flag + time * 10;
    }
    printf("Your total bill amount is %d\nDo you want to continue\n1.Yes\t0.Go back\n", time);
    scanf("%d", &flag);
    if (flag == 0)
        goto recharge;
    return time;
}
int main()
{
    int time = time_remainging();
    // printf("You are logged in\n");
    do
    {
        printf("\033[A%d minutes remainging\n", time);
        setTimeout(60000);
        time--;
    } while (time >= 0);
}
