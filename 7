#include <stdio.h>

#define MAX_FRAMES 10
#define MAX_PAGES 50

void fifoPageReplacement(int pages[], int n, int frames) {
    int frame[MAX_FRAMES], pageFaults = 0, frameIndex = 0;
    int i, j, k;

    // Initialize all frames as empty (-1)
    for (i = 0; i < frames; i++) {
        frame[i] = -1;
    }

    printf("Page Reference String: ");
    for (i = 0; i < n; i++) {
        printf("%d ", pages[i]);
    }
    printf("\n\n");

    // Process each page in the reference string
    for (i = 0; i < n; i++) {
        int page = pages[i], found = 0;

        // Check if the page is already in a frame
        for (j = 0; j < frames; j++) {
            if (frame[j] == page) {
                found = 1;
                break;
            }
        }

        // If page is not found, a page fault occurs
        if (!found) {
            frame[frameIndex] = page; // Replace the oldest page
            frameIndex = (frameIndex + 1) % frames; // Move to the next frame (circular)
            pageFaults++;

            // Display the current state of frames
            printf("Page %d -> Frames: ", page);
            for (k = 0; k < frames; k++) {
                if (frame[k] == -1) printf(" - ");
                else printf("%d ", frame[k]);
            }
            printf("\n");
        }
    }

    printf("\nTotal Page Faults: %d\n", pageFaults);
}

int main() {
    int pages[MAX_PAGES], n, frames;

    // Input the number of pages
    printf("Enter the number of pages: ");
    scanf("%d", &n);

    // Input the page reference string
    printf("Enter the page reference string: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &pages[i]);
    }

    // Input the number of frames
    printf("Enter the number of frames: ");
    scanf("%d", &frames);

    // Call the FIFO page replacement function
    fifoPageReplacement(pages, n, frames);

    return 0;
}
