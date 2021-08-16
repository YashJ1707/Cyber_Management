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
    int time;
    printf("Choose a plan\n");
    printf("Some plan\n");
    scanf("%d", &time);
    return time;
}
int main()
{
    int time = time_remainging();
    do
    {
        printf("\033[A%d minutes remainging\n", time);
        setTimeout(60000);
        time--;
    } while (time >= 0);
}
