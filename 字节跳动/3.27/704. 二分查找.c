//
//  704. 二分查找.c
//  字节跳动
//
//  Created by SSR on 2022/3/27.
//

#include <stdio.h>

int search(int* nums, int numsSize, int target);

int main() {
    int a[] = {-1,0,3,5,9,12};
    int t = search(a, sizeof(a) / sizeof(int), 9);
    printf("%d\n", t);
    return 0;
}

int search(int* nums, int numsSize, int target) {
    int left = 0, right = numsSize - 1;
    while (left <= right) {
        int middle = (right - left) / 2 + left;
        if (nums[middle] == target) {
            return middle;
        } else if (nums[middle] > target) {
            right = middle - 1;
        } else {
            left = middle + 1;
        }
    }
    return -1;
}
