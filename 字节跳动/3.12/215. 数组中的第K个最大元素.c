//
//  215. 数组中的第K个最大元素.c
//  字节跳动
//
//  Created by SSR on 2022/3/12.
//

#include <stdio.h>

int findKthLargest(int* nums, int numsSize, int k);

int main() {
    int a[] = {3,2,1,5,6,4};
    int size = sizeof(a) / sizeof(int);
    int num = findKthLargest(a, size, 2);
    for (int i = 0; i < size; i++) {
        printf("%d ", a[i]);
    }
    printf("\n%d\n", num);
}

int findKthLargest(int* nums, int numsSize, int k) {
    int i, j;
    for (i = 0; i < numsSize - 1; i++) {
        for (j = 0; j < numsSize - i - 1; j++) {
            if (nums[j] > nums[j + 1]) {
                    int t = nums[j];
                    nums[j] = nums[j + 1];
                    nums[j + 1] = t;
            }
        }
    }
    return nums[numsSize - k];
}
