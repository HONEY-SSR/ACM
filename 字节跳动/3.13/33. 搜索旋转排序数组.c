//
//  33. 搜索旋转排序数组.c
//  字节跳动
//
//  Created by SSR on 2022/3/13.
//

#include <stdio.h>

int search(int* nums, int numsSize, int target);

int main() {
    int a[]  = {4,5,6,7,0,1,2};
    int num = search(a, sizeof(a) / sizeof(int), 3);
    printf("%d\n", num);
    return 0;
}

int search(int* nums, int numsSize, int target) {
    int i;
    for (i = 0; i < numsSize; i++) {
        if (nums[i] == target) {
            return i;
        }
    }
    return -1;
}
