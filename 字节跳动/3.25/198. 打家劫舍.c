//
//  198. 打家劫舍.c
//  字节跳动
//
//  Created by SSR on 2022/3/25.
//

#include <stdio.h>

int rob(int* nums, int numsSize);

int main() {
    int a[] = {2,7,9,3,1};
    int sum = rob(a, sizeof(a) / sizeof(int));
    printf("%d\n", sum);
}

int rob(int* nums, int numsSize){
    if (numsSize == 1) {
        return *nums;
    }
    nums[1] = nums[0] > nums[1] ? nums[0] :nums[1];
    for (int i = 2; i < numsSize; i++) {
        int a = nums[i - 2] + nums[i];
        nums[i] = a > nums[i - 1] ? a :nums[i - 1];
    }
    return nums[numsSize - 1] > nums[numsSize - 2]
        ? nums[numsSize - 1] : nums[numsSize - 2];
}
