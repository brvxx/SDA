#include <stdlib.h>
#include <stdio.h>

typedef struct {
    int profit;
    int duration;
    int deadline;
}job;

extern int ScheduleJobs(const job* jobs, size_t j_size);

int main(void) {

    job arr[] = {
        {.profit = 50, .duration = 2, .deadline = 4},
        {.profit = 130, .duration = 4, .deadline = 25},
        {.profit = 35, .duration = 1, .deadline = 3},
        {.profit = 50, .duration = 8, .deadline = 30},
        {.profit = 300, .duration = 4, .deadline = 7},
        {.profit = 145, .duration = 20, .deadline = 30},
    };
    size_t size = sizeof(arr) / sizeof(arr[0]);
   
    int res  = ScheduleJobs(arr, size); 
    printf("\nprofitto totale %d", res); 

    return 0; 
}