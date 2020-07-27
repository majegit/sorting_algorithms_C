#include <stdio.h>

void mergeSort(int A[], int l, int r);
void merge(int A[], int l, int m, int r);

/* l is left, r is right.
 * This function recursively splits up the array into smaller and smaller sub-
 * arrays, until they can be merged. Finally it recursirvely merges the sub arrays,
 * until the point where there is only one sorted array.
*/
void mergeSort(int A[], int l, int r) {
    if (l < r) {
        int m = (l+r)/2;
        mergeSort(A, l, m);
        mergeSort(A, m+1, r);
        merge(A, l, m, r);
    }
}

//This function merges the left and right numbers in the array A.
void merge(int A[], int l, int m, int r) {
    int k, i, j;
    int n1 = m - l + 1;
    int n2 = r - m;

    //These arrays are gonna hold the left and right numbers in the array A.
    int L[n1], R[n2];

    //Put the left and right numbers into the arrays.
    for (i = 0; i < n1; i++)
        L[i] = A[l + i];
    for (j = 0; j < n2; j++)
        R[j] = A[m + 1 + j];

    //Now we can merge the arrays L and R together in an ascending order
    i = 0; //Pointer into subarray L.
    j = 0; //Pointer into subarray R.
    k = l; //Pointer into A.
    while (i < n1 && j < n2) { //Keeps going until one of the sub arrays are empty.
        if (L[i] <= R[j]) {
            A[k] = L[i];
            i++;
        }
        else {
            A[k] = R[j];
            j++;
        }
        k++; //Move pointer forward
    }

    //Finally, if there are elements left in L, make sure they get merged
    while (i < n1) {
        A[k] = L[i];
        i++;
        k++;
    }
    //If there are elements left in R, make sure they get merged
    while (j < n2) {
        A[k] = R[j];
        j++;
        k++;
    }
}

int main() {
    int numbers[3] = {1,7,3};
    mergeSort(numbers, 0, 3-1);
    for(int i=0; i < 3; i++)
        printf("Here is numbers[%d]: %d\n",i,numbers[i]);
    return 0;
}
