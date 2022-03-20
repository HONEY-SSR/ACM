//
//  300. 最长递增子序列.c
//  字节跳动
//
//  Created by SSR on 2022/3/19.
//

#include <stdio.h>

int lengthOfLIS(int* nums, int numsSize);

int main() {
    int a[] = {0,1,0,3,2,3};
    int len = lengthOfLIS(a, sizeof(a) / sizeof(int));
    printf("%d\n", len);
    return 0;
}

int lengthOfLIS(int* nums, int numsSize) {
    const int len = numsSize;
    int dp[len];
    dp[0] = 1;
    for(int i = 1; i < len; i++) {
        int ans = 0;
        for(int j = 0; j < i; j++) {
            if(nums[j] < nums[i] && dp[j] > ans) {
                ans = dp[j];
            }
        }
        dp[i] = (1 > ans + 1 ? 1 : ans + 1);
    }
    int returnSize = 1;
    for(int i = 0; i < len; i++) {
        if(returnSize < dp[i])
            returnSize = dp[i];
    }
    return returnSize;
}
