#include <stdio.h>

int findLRU(int time[], int n) {
    int min = time[0], pos = 0;
    for (int i = 1; i < n; i++) {
        if (time[i] < min) {
            min = time[i];
            pos = i;
        }
    }
    return pos;
}

int main() {
    int n, pages[100], frameSize;
    printf("Enter number of pages: ");
    scanf("%d", &n);
    printf("Enter the pages: ");
    for (int i = 0; i < n; i++)
        scanf("%d", &pages[i]);

    printf("Enter frame size: ");
    scanf("%d", &frameSize);

    int frames[frameSize], time[frameSize], count = 0, faults = 0;
    for (int i = 0; i < frameSize; i++) frames[i] = -1;

    for (int i = 0; i < n; i++) {
        int flag = 0;
        for (int j = 0; j < frameSize; j++) {
            if (frames[j] == pages[i]) {
                count++;
                time[j] = count;
                flag = 1;
                break;
            }
        }

        if (!flag) {
            int pos = -1;
            for (int j = 0; j < frameSize; j++) {
                if (frames[j] == -1) {
                    pos = j;
                    break;
                }
            }

            if (pos == -1)
                pos = findLRU(time, frameSize);

            frames[pos] = pages[i];
            count++;
            time[pos] = count;
            faults++;
        }
    }

    printf("Total Page Faults: %d\n", faults);
    return 0;
}
