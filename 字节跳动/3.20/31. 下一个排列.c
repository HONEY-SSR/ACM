//
//  31. 下一个排列.c
//  字节跳动
//
//  Created by SSR on 2022/3/20.
//

#include <stdio.h>

void swap(int *a, int *b);
void nextPermutation(int* nums, int numsSize);

int main() {
    int a[] = {3,2,1};
    int size = sizeof(a) / sizeof(int);
    nextPermutation(a, size);
    int i;
    for (i = 0; i < size; i++) {
        printf("%d\n", a[i]);
    }
    return 0;
}

void swap(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

void nextPermutation(int* nums, int numsSize) {
    if(numsSize == 0)
        return;
    int i = 0, j = 0;
    /*从后往前找第一个后面比前面大的数*/
    for(i = numsSize - 2; i >= 0 && nums[i+1] <= nums[i]; i--);
    if(i >= 0){
        /*从后往前找第一个比nums[i]大的数*/
        for(j = numsSize - 1; j >= 0 && nums[j] <= nums[i]; j--);
        /*交换*/
        swap(&nums[i], &nums[j]);
    }
    /*翻转nums[i]以后的部分,即[i+1, numsSize-1]*/
    for(j = 0; j <= (numsSize - 2 - i) / 2; j++){
        swap(&nums[i + 1 + j], &nums[numsSize - 1 - j]);
    }
}
