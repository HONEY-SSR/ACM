//
//  88. 合并两个有序数组.c
//  字节跳动
//
//  Created by SSR on 2022/3/20.
//

#include <stdio.h>

void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n);

int main() {
    int nums1[9] = {1,2,3,0,0,0};
    int nums2[] = {2,5,6};
    merge(nums1, 6, 3, nums2, 3, 3);
    for (int i = 0; i < 9; i++) {
        printf("%d\n", nums1[i]);
    }
    return 0;
}

void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n) {
    int p1 = m - 1, p2 = n - 1;
    int tail = m + n - 1;
    int cur;
    while (p1 >= 0 || p2 >= 0) {
        if (p1 == -1) {
            cur = nums2[p2--];
        } else if (p2 == -1) {
            cur = nums1[p1--];
        } else if (nums1[p1] > nums2[p2]) {
            cur = nums1[p1--];
        } else {
            cur = nums2[p2--];
        }
        nums1[tail--] = cur;
    }
}
