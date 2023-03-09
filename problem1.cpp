#include <stdio.h>
/*
* 
һ������ΪN����������A[1...N]����������X�������һ��ʱ�临�ӶȲ�����O(nlog2n)���㷨�����ҳ�������������е�����֮�͵���X�������ԡ���ÿ��Ԫ��ֻ�����һ�Σ�
*/

/*
* ��������˫ָ���˼�������������⣬������㷨�������£�

1.������ A ��С�������򣬿���ʹ�ÿ��������鲢������㷨��ʱ�临�Ӷ�Ϊ O(nlog2n)��

2.��������ָ�� i �� j���ֱ�ָ������ A ��ͷ����β����

3.�� i < j ʱ��ѭ��ִ�����²�����

    a. ���� A[i] + A[j] ��ֵ�������� X���� A[i] �� A[j] ��������� i �� j �ֱ��������ǰ�ƶ�һλ��

    b. �� A[i] + A[j] ��ֵС�� X���� i ����ƶ�һλ��

    c. �� A[i] + A[j] ��ֵ���� X���� j ��ǰ�ƶ�һλ��

4.�� i >= j ʱ��ѭ��������������еķ��������������ԡ�
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
