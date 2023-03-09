#include <stdio.h>
/*
* 
一个长度为N的整形数组A[1...N]，给定整数X，请设计一个时间复杂度不超过O(nlog2n)的算法，查找出这个数组中所有的两两之和等于X的整数对。（每个元素只能输出一次）
*/

/*
* 可以利用双指针的思想来解决这个问题，具体的算法步骤如下：

1.将数组 A 从小到大排序，可以使用快速排序或归并排序等算法，时间复杂度为 O(nlog2n)。

2.定义两个指针 i 和 j，分别指向数组 A 的头部和尾部。

3.当 i < j 时，循环执行以下操作：

    a. 计算 A[i] + A[j] 的值，若等于 X，则将 A[i] 和 A[j] 输出，并将 i 和 j 分别往后和往前移动一位。

    b. 若 A[i] + A[j] 的值小于 X，则将 i 向后移动一位。

    c. 若 A[i] + A[j] 的值大于 X，则将 j 向前移动一位。

4.当 i >= j 时，循环结束，输出所有的符合条件的整数对。
*/
void merge(int A[], int temp[], int left, int mid, int right) {
    int i = left, j = mid + 1, k = left;
    while (i <= mid && j <= right) {
        if (A[i] < A[j]) {
            temp[k++] = A[i++];
        }
        else {
            temp[k++] = A[j++];
        }
    }
    while (i <= mid) {
        temp[k++] = A[i++];
    }
    while (j <= right) {
        temp[k++] = A[j++];
    }
    for (i = left; i <= right; i++) {
        A[i] = temp[i];
    }
}

void mergeSort(int A[], int temp[], int left, int right) {
    if (left < right) {
        int mid = (left + right) / 2;
        mergeSort(A, temp, left, mid);
        mergeSort(A, temp, mid + 1, right);
        merge(A, temp, left, mid, right);
    }
}

void findPairs(int A[], int n, int x) {
    int i = 0, j = n - 1;
    while (i < j) {
        int sum = A[i] + A[j];
        if (sum == x) {
            printf("(%d, %d) ", A[i], A[j]);
            i++;
            j--;
        }
        else if (sum < x) {
            i++;
        }
        else {
            j--;
        }
    }
}

int main() {
    int A[] = { 5, 2, 8, 9, 1, 7, 3, 6, 4 };
    int n = sizeof(A) / sizeof(A[0]);
    int temp[n];
    mergeSort(A, temp, 0, n - 1);
    findPairs(A, n, 10);
    return 0;
}
