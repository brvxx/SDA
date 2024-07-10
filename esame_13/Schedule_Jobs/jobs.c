#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

typedef struct {
    int profit;
    int duration;
    int deadline;
}job;

int ScheduleJobs(const job* jobs, size_t j_size) {
    double* greedy = calloc(j_size, sizeof(double)); 
    bool* presi = calloc(j_size, sizeof(bool));

    // popolo il vettore appetibilità 
    for (size_t i = 0; i < j_size; ++i) {
        greedy[i] = jobs[i].profit / jobs[i].duration;
    }

    int time = 0; 
    int profit_tot = 0; 

    int cnt = 0; 

    while (cnt < (int)j_size) {
        int idx = 0; 
        int b_duration = 0; 
        double b_app = 0; 
        for (size_t i = 0; i < j_size; ++i) {
            if (!presi[i]) {
                if (greedy[i] > b_app || (greedy[i] == b_app && jobs[i].duration < b_duration)) {
                    if (time + jobs[i].duration > jobs[i].deadline) {
                        presi[i] = true; 
                        ++cnt; 
                    }
                    else {
                        idx = (int)i; 
                        b_duration = jobs[i].duration; 
                        b_app = greedy[i]; 
                    }
                }
            }
        }
        if (cnt == (int)j_size) {
            break;
        }
        printf("%d ", idx); 
        ++cnt;
        presi[idx] = true; 
        time += jobs[idx].duration; 
        profit_tot += jobs[idx].profit;
    }

    free(presi);
    free(greedy); 

    return profit_tot; 
}