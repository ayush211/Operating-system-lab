#include <stdio.h>

int main() {
    int n, pages[100], frameSize;
    printf("Enter number of pages: ");
    scanf("%d", &n);
    printf("Enter the pages: ");
    for (int i = 0; i < n; i++)
        scanf("%d", &pages[i]);

    printf("Enter frame size: ");
    scanf("%d", &frameSize);

    int frames[frameSize], front = 0, count = 0, faults = 0;
    for (int i = 0; i < frameSize; i++) frames[i] = -1;

    for (int i = 0; i < n; i++) {
        int found = 0;
        for (int j = 0; j < frameSize; j++)
            if (frames[j] == pages[i]) found = 1;

        if (!found) {
            frames[front] = pages[i];
            front = (front + 1) % frameSize;
            faults++;
        }
    }

    printf("Total Page Faults: %d\n", faults);
    return 0;
}
