//
//  34. 在排序数组中查找元素的第一个和最后一个位置.c
//  LeetCode
//
//  Created by SSR on 2022/2/15.
//

// https://leetcode-cn.com/problems/find-first-and-last-position-of-element-in-sorted-array/

#include <stdio.h>
#include <stdlib.h>

int* searchRange(int* nums, int numsSize, int target, int* returnSize);

int main() {
    int a[] = {8,2};
    int r;
    int *t = searchRange(a, sizeof(a) / sizeof(int), 8, &r);
    printf("%d - %d\n", t[0], t[1]);
    return 0;
}

int* searchRange(int* nums, int numsSize, int target, int* returnSize){
    int *begin = nums, *end = nums + numsSize - 1;
    *returnSize = 2;
    
    int *in = (int *)malloc(sizeof(int) * 2);
    in[0] = in[1] = -1;
    
    /**找不到则会不满足begin <= end，找到则会不满足(in[0] == -1 || in[1] == -1)*/
    while (begin <= end && (in[0] == -1 || in[1] == -1)) {
        printf("b=%d e=%d, 1=%d 2=%d\n", *begin, *end, in[0], in[1]);
        
        /**左边还没有找到*/
        if (in[0] == -1) {
            /**当前的数是找的，赋值*/
            if (*begin == target)
                in[0] = (int) (begin - nums);
            else/**不是则往后找*/
                begin++;
        }
        /**右边还没有找到*/
        if (in[1] == -1) {
            /**当前的数是找的，赋值*/
            if (*end == target)
                in[1] = (int) (end - nums);
            else/**不是则往前找*/
                end--;
        }
    }
    return in;
}
