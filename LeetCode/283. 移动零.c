//
//  283. 移动零.c
//  LeetCode
//
//  Created by SSR on 2022/2/21.
//

// https://leetcode-cn.com/problems/move-zeroes/

#include <stdio.h>

void moveZeroes(int* nums, int numsSize);

int main() {
    int a[] = {0,1,0,3,12}, i;
    int nums = sizeof(a) / sizeof(int);
    moveZeroes(a, nums);
    for (i = 0; i < nums; i++) {
        printf("%d\n", a[i]);
    }
    return 0;
}

void moveZeroes(int* nums, int numsSize) {
    int i, j = 0;
    for (i = 0; i < numsSize; i++)
        if (nums[i] != 0)
            nums[j++] = nums[i];
    for (; j < numsSize; j++)
        nums[j] = 0;
    return;
}
