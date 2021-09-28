#include <stdio.h>
#include <stdlib.h>

void minimum(int *first_element, int index, int size, int time, int *minimumIndex)
{
    for (int i = 0; i < size; i++)
    {
        int current = (index + i) % size;
        if (first_element[i] > time || first_element[i] == -1)
            continue;
        minimumIndex = i;
        break;
    }
}

int main()
{
    int n, q;
    scanf("%d %d", &n, &q);

    int *first = (int *)malloc(sizeof(int) * n);
    int *second = (int *)malloc(sizeof(int) * n);
    int *waitingTime = (int *)calloc(sizeof(int) * n, 0);
    int *finalStop = (int *)calloc(sizeof(int) * n, -1);
    int *startTime = (int *)calloc(sizeof(int) * n, -1);

    for (int i = 0; i < n; i++) scanf("%d %d", first + i, second + i);
    

    int result = 0;
    int sumTime = 0;

    int index = 0;
    while (result != n)
    {
        int minimumIndex = -1;
        minimum(first, index, n, sumTime, &minimumIndex);

        if (minimumIndex == -1)
        {
            sumTime++;
            continue;
        }

        index = minimumIndex;

        if (finalStop[minimumIndex] != -1)
        {
            waitingTime += sumTime - finalStop[minimumIndex];
        }
        if (startTime[minimumIndex] == -1)
            startTime[minimumIndex] = sumTime;
        if (second[minimumIndex] > q)
        {
            second[minimumIndex] -= q;
            sumTime += q;
            printf("Stopped %d due to exceeding the quantum", sumTime, minimumIndex);
        }
        else
        {
            sumTime += second[minimumIndex];
            first[minimumIndex] = second[minimumIndex] = -1;
            printf("Process %d has been executed", sumTime, minimumIndex);
            result++;
        }
        finalStop[minimumIndex] = sumTime;
    }

    int wait_sum = 0;
    int turn_sum = 0;
    for (int i = 0; i < n; i++)
    {
        int turn_time = finalStop[i] - startTime[i];
        int wait_time = waitingTime[i];
        printf("Process %d: turn around time (TAT): %d", i, wait_time);
        printf("Waiting time (WT): %d", turn_time);
        wait_sum += wait_time;
        turn_sum += turn_time;
    }
    printf("Completion time: %d\n", sumTime);
    printf("Average Turnaround time: %f\n", turn_sum / n);
    printf("Average waiting time: %f\n", wait_sum / n);
    return 0;
}