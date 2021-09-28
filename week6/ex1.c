#include <stdio.h>
#include <stdlib.h>

void minimum(int *first_element, int size, int time, int *minimum, int *minimum_index)
{
    for (int i = 0; i < size; i++)
    {
        if (first_element[i] > time) continue;
        else if (first_element[i] == -1) continue;
        else if (first_element[i] < minimum)
        {
            *minimum = first_element[i];
            *minimum_index = i;
        }
    }
}

int main()
{
    int size;
    scanf("%d", &size);

    int *tmp = (int *)malloc(sizeof(int) * size);
    int *tmp_s = (int *)malloc(sizeof(int) * size);

    for (int i = 0; i < size; ++i) scanf("%d %d", tmp + i, tmp_s + i);

    int timeAverage = 0;
    int waitingAverage = 0;
    int result = 0;
    int sumTime = 0;

    while (result != size)
    {
        int minimum_element = 99999999;
        int minimum_index = -1;

        minimum(tmp, size, sumTime, &minimum_element, &minimum_index);

        if (minimum_index == -1)
        {
            sumTime++;
            continue;
        }

        int waiting_time = sumTime - tmp[minimum_index];

        sumTime += tmp_s[minimum_index];
        tmp_s[minimum_index] = tmp[minimum_index] = -1;
        result++;

        int around = sumTime - tmp[minimum_index];
        printf("Turn around time (TAT): %d", around);
        printf("Waiting time (WT): %d", waiting_time);
        timeAverage += around;
        waitingAverage += waiting_time;
    }

    printf("Completion time: %d\n", sumTime);
    printf("Average Turnaround time: %f\n", timeAverage / size);
    printf("Average waiting time: %f\n", waitingAverage / size);
    return 0;
}