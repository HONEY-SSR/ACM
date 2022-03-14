//
//  41. 缺失的第一个正数.c
//  字节跳动
//
//  Created by SSR on 2022/3/14.
//

#include <stdio.h>

int main() {
    
}

// tips: 正整数从1开始，初步换序后，a[0]应为1，a[1]应为2
int firstMissingPositive(int* nums, int numsSize){
  // 换序的过程即将数换到正确位置的过程，最多换n个，故复杂度为O(n)
  for (int i = 0; i < numsSize; i++) {
    // 该数字不属于当前位置 交换a[i] 和a[i]-1位置上的数字
    while ((nums[i] >= 1 && nums[i] <= numsSize) && (nums[i] != nums[nums[i]-1])) {
      int tmp = nums[i];
      nums[i] = nums[tmp-1];
      nums[tmp-1] = tmp;
    }
  }
  // 默认缺少的是正整数是 数组长度+1
  int is = numsSize + 1;
  // 如果中间有缺少的，直接替换is
  for (int i = 0; i < numsSize; i++) {
    if (nums[i] != (i + 1)) {
      is = i + 1;
      break;
    }
  }
  return is;
}
