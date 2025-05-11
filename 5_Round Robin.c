#include <stdio.h>

int main() {
    int n, tq;
    printf("Enter number of processes: ");
    scanf("%d", &n);
    printf("Enter time quantum: ");
    scanf("%d", &tq);

    int bt[n], rt[n], wt[n], tat[n];
    	for (int i = 0; i < n; i++) {
        	printf("Enter burst time for process %d: ", i + 1);
        	scanf("%d", &bt[i]);
        	rt[i] = bt[i];
        	wt[i] = 0;
    }

    int time = 0, done;
    do {
        done = 1;
        for (int i = 0; i < n; i++) {
            if (rt[i] > 0) {
                done = 0;
                if (rt[i] > tq) {
                    time += tq;
                    rt[i] -= tq;
                } else {
                    time += rt[i];
                    wt[i] = time - bt[i];
                    rt[i] = 0;
                }
            }
        }
    } while (!done);

    printf("\nPID\tBT\tWT\tTAT\n");
    for (int i = 0; i < n; i++) {
        tat[i] = wt[i] + bt[i];
        printf("%d\t%d\t%d\t%d\n", i + 1, bt[i], wt[i], tat[i]);
    }

    return 0;
}
