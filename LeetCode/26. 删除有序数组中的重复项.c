//
//  26. 删除有序数组中的重复项.c
//  LeetCode
//
//  Created by SSR on 2022/2/19.
//

// https://leetcode-cn.com/problems/remove-duplicates-from-sorted-array/

#include <stdio.h>

int removeDuplicates(int* nums, int numsSize);

int main() {
    int a[] = {1}, i;
    int num = removeDuplicates(a, sizeof(a) / sizeof(int));
    for (i = 0; i < num; i++) {
        printf("%d\n", a[i]);
    }
    return 0;
}

int removeDuplicates(int* nums, int numsSize) {
    if (nums == NULL) {
        return 0;
    }
    int i, j, before = nums[0];
    for (i = j = 1; i < numsSize; i++) {
        if (nums[i] != before) {
            nums[j++] = nums[i];
            before = nums[i];
        }
    }
    return j;
}
