//
//  27. 移除元素.c
//  LeetCode
//
//  Created by SSR on 2022/2/18.
//

#include <stdio.h>

int removeElement(int* nums, int numsSize, int val);

int main() {
    int a[] = {1, 2, 3, 3, 5, 3, 2}, i;
    int nums = removeElement(a, sizeof(a) / sizeof(int), 2);
    for (i = 0; i < nums; i++) {
        printf("%d\n", a[i]);
    }
}

int removeElement(int* nums, int numsSize, int val) {
    if (numsSize == 0) {
        return 0;
    }
    int j = 0, i;
    for (i = 0; i < numsSize; i++) {
        if (nums[i] == val) {
            continue;
        }
        nums[j++] = nums[i];
    }
    return j;
}
