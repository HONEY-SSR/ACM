//
//  912. 排序数组.c
//  字节跳动
//
//  Created by SSR on 2022/3/28.
//

#include <stdio.h>
#include <stdlib.h>

int* sortArray(int* nums, int numsSize, int* returnSize);

int main() {
    
    return 0;
}

int *sortArray(int* nums, int numsSize, int* returnSize){
    int d, i, j, temp;
    *returnSize = numsSize;
    for(d = numsSize / 2; d >= 1; d = d/2){
        for(i = d; i < numsSize; i++){
            if(nums[i] < nums[i - d]){
                temp = nums[i];
                for(j = i - d; j >= 0 && temp < nums[j]; j -= d)
                    nums[j + d] = nums[j];
                nums[j + d] = temp;
            }
        }
    }
    return nums;
}
