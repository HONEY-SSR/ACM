//
//  152. 乘积最大子数组.c
//  字节跳动
//
//  Created by SSR on 2022/3/14.
//

#include <stdio.h>

int maxProduct(int* nums, int numsSize);

int main() {
    int a[] = {-2,1,-3,4,-1,2,1,-5,4};
    int sum = maxProduct(a, sizeof(a) / sizeof(int));
    printf("%d\n", sum);
    return 0;
}

int maxProduct(int* nums, int numsSize) {
    if (numsSize == 1) {
        return nums[0];
    }
    int maxRes = nums[0], curMax = nums[0], curMin = nums[0];
    for (int i = 1; i < numsSize; i++) {
        if (nums[i] < 0) {
            int t = curMax;
            curMax = curMin;
            curMin = t;
        }
        curMax = (curMax * nums[i] > nums[i] ? curMax * nums[i] : nums[i]);
        curMin = (curMin * nums[i] < nums[i] ? curMin * nums[i] : nums[i]);
        maxRes = (maxRes > curMax ? maxRes : curMax);
    }
    return maxRes;
}
