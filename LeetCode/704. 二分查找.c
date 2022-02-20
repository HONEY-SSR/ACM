//
//  704. 二分查找.c
//  LeetCode
//
//  Created by SSR on 2022/2/12.
//

// https://leetcode-cn.com/problems/binary-search/

#include <stdio.h>

int search(int* nums, int numsSize, int target);

int main() {
    int a[] = {-1, 0, 3, 5, 9, 12};
    printf("%d\n", search(a, sizeof(a) / sizeof(int), 13));
}

int search(int* nums, int numsSize, int target) {
    numsSize--;
    int left = 0, middle = (left + numsSize) / 2;
    while (left <= numsSize) {
        if (target == nums[middle]) {
            return middle;
        }
        else if (target < nums[middle]) {
            numsSize = middle - 1;
        }
        else {
            left = middle + 1;
        }
        middle = (left + numsSize) / 2;
    }
    return -1;
}
