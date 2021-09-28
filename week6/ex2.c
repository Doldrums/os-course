#include <stdio.h>
#include <stdlib.h>

void minimum(int *first_element, int *second_element, int size, int sumTime, int *minimumTime, int *minimumIndes)
{
    for (int i = 0; i < size; ++i)
    {
        if (first_element[i] > sumTime) continue;
        else if (second_element[i] < minimumTime)
        {
            minimumTime = second_element[i];
            minimumIndes = i;
        }
    }
}

int main()
{
    int size;
    scanf("%d", &size);

    int *tmp = (int *)malloc(sizeof(int) * size);
    int *tmp_s = (int *)malloc(sizeof(int) * size);

    for (int i = 0; i < size; i++)
    {
        scanf("%d %d", tmp + i, tmp_s + i);
    }

    int result = 0;
    int sumTime = 0;

    int averageTime = 0;
    int averageWaiting = 0;
    while (result != size)
    {
        int minimumTime = 99999999;
        int minimumIndex = -1;

        minimum(tmp, tmp_s, size, sumTime, &minimumTime, &minimumIndex);

        if (minimumIndex == -1)
        {
            sumTime++;
            continue;
        }

        int waiting_time = sumTime - tmp[minimumIndex];

        sumTime += tmp_s[minimumIndex];
        tmp_s[minimumIndex] = tmp[minimumIndex] = -1;
        result++;

        int around = sumTime - tmp[minimumIndex];
        printf("Process %d: turn around time (TAT): %d", minimumIndex, around);
        printf("Waiting time (WT): %d", waiting_time);
        averageTime += around;
        averageWaiting += waiting_time;
    }

    printf("Completion time: %d\n", sumTime);
    printf("Average Turnaround time: %f\n", averageTime / size);
    printf("Average waiting time: %f\n", averageWaiting / size);
    return 0;
}