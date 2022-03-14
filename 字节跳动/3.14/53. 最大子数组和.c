//
//  53. 最大子数组和.c
//  字节跳动
//
//  Created by SSR on 2022/3/14.
//

#include <stdio.h>

int maxSubArray(int* nums, int numsSize);

int main() {
    int nums[] = {-2,1,-3,4,-1,2,1,-5,4};
    int max = maxSubArray(nums, sizeof(nums) / sizeof(int));
    printf("%d\n", max);
}

int maxSubArray(int* nums, int numsSize) {
    int sum = 0, maxNum = nums[0];
    for (int i = 0; i < numsSize; i++) {
        sum = (sum + nums[i] > nums[i] ? sum + nums[i] : nums[i]);
        maxNum = (maxNum > sum ? maxNum : sum);
    }
    return maxNum;
}
