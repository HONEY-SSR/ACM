//
//  209. 长度最小的子数组.c
//  LeetCode
//
//  Created by SSR on 2022/2/23.
//

// https://leetcode-cn.com/problems/minimum-size-subarray-sum/

#include <stdio.h>

int minSubArrayLen(int target, int* nums, int numsSize);

int main() {
    int a[] = {1,2,3,4,5};
    int s = minSubArrayLen(11, a, sizeof(a) / sizeof(int));
    printf("%d\n", s);
    return 0;
}

int minSubArrayLen(int target, int *nums, int numsSize) {
    if (numsSize == 0) {
        return 0;
    }
    int size = numsSize + 1;
    int start = 0, end = 0;
    int sum = 0;
    for (start = end = 0; end < numsSize; end++) {
        sum += nums[end];
        while (sum >= target) {
            size = (size < end - start + 1 ? size : end - start + 1);
            sum -= nums[start];
            start ++;
        }
    }
    return size == numsSize + 1 ? 0 :size;
}
