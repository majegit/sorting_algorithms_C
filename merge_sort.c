#include <stdio.h>

void merge(int numbers[], int l, int m, int r) {
    int left[m-l];
    int right[r-m];
    for(int i=0; i <= m-l; i++) {
        left[i] = numbers[l+i];
        printf("%d\n",left[i]);
    }
    for()


}

void sort() {

}

int main() {
    printf("Hej med dig!\n");
    int numbers[4] = {3,1,0,2};
    merge(numbers, 0, 1, 3);
    return 0;
}
