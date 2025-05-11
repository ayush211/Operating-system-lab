#include <stdio.h>

struct Process {
    int pid;
    int bt;
    int priority;
};

void swap(struct Process *a, struct Process *b) {
    struct Process temp = *a;
    *a = *b;
    *b = temp;
}

int main() {
    int n;
    printf("Enter number of processes: ");
    scanf("%d", &n);

    struct Process p[n];
    for (int i = 0; i < n; i++) {
        p[i].pid = i + 1;
        printf("Enter burst time and priority for process %d: ", i + 1);
        scanf("%d %d", &p[i].bt, &p[i].priority);
    }

    for (int i = 0; i < n-1; i++)
        for (int j = 0; j < n-i-1; j++)
            if (p[j].priority > p[j+1].priority)
                swap(&p[j], &p[j+1]);

    int wt[n], tat[n];
    wt[0] = 0;
    for (int i = 1; i < n; i++)
        wt[i] = wt[i-1] + p[i-1].bt;

    printf("\nPID\tBT\tPR\tWT\tTAT\n");
    for (int i = 0; i < n; i++) {
        tat[i] = wt[i] + p[i].bt;
        printf("%d\t%d\t%d\t%d\t%d\n", p[i].pid, p[i].bt, p[i].priority, wt[i], tat[i]);
    }

    return 0;
}
