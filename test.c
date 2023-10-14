//2330,2320


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct WordFrequency {
    char word[100];
    int frequency;
};

void merge(struct WordFrequency arr[], int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;

    // Create temporary arrays
    struct WordFrequency L[n1], R[n2];

    // Copy data to temporary arrays L[] and R[]
    for (int i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    // Merge the temporary arrays back into arr[l..r]
    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2) {
        if (L[i].frequency > R[j].frequency) {
            arr[k++] = L[i++];
        } else {
            arr[k++] = R[j++];
        }
    }

    // Copy the remaining elements of L[], if there are any
    while (i < n1) {
        arr[k++] = L[i++];
    }

    // Copy the remaining elements of R[], if there are any
    while (j < n2) {
        arr[k++] = R[j++];
    }
}

// Merge sort function
void mergeSort(struct WordFrequency arr[], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;

        // Sort first and second halves
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);

        // Merge the sorted halves
        merge(arr, l, m, r);
    }
}
int file_sort()
{  
    FILE *inputFile, *outputFile;
    char word[100];
    struct WordFrequency words[1000];
    int wordCount = 0;

    inputFile = fopen("input.txt", "r");
    if (inputFile == NULL) {
        printf("File not found 1.\n");
        return 1;
    }

    while (fscanf(inputFile, "%s", word) != EOF) {
        int found = 0;
        for (int i = 0; i < wordCount; i++) {
            if (strcmp(words[i].word, word) == 0) {
                words[i].frequency++;
                found = 1;
                break;
            }
        }
        if (!found) {
            strcpy(words[wordCount].word, word);
            words[wordCount].frequency = 1;
            wordCount++;
        }
    }

    fclose(inputFile);

    mergeSort(words, 0, wordCount - 1);

    outputFile = fopen("output.txt", "w");
    if (outputFile == NULL) {
        printf("Error opening output file.\n");
        return 1;
    }

    for (int i = wordCount - 1; i >= 0; i--) {
        fprintf(outputFile, "%s %d\n", words[i].word, words[i].frequency);
    }

    fclose(outputFile);

    printf("Sorted output written to 'output.txt'.\n");
    return 0; //if successful returns 0
}
int main() {
    
  
    file_sort();
    return 0;
}
