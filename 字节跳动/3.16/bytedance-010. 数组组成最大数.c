//
//  bytedance-010. 数组组成最大数.c
//  字节跳动
//
//  Created by SSR on 2022/3/16.
//

#include <stdio.h>
#include <stdlib.h>

typedef long long ll;

typedef struct NumInfo {
    int beginNum;
    int size;
}NumInfo;

void maxNumIn(int *nums, int size);
void setInfoWithNum(NumInfo *info, int num);
void sortNumsWithInfo(int *nums, NumInfo *infos, int size);
void switchNumsAndInfo(int *num1, int *num2, NumInfo *info1, NumInfo *info2);
int num1CompareMoreMax(int num1, NumInfo *info1, int num2, NumInfo *info2);
void newNumWithInfo(int *num, NumInfo *info);

int main() {
    //输入？？？
    
    //处理及输出
    
    
    return 0;
}

void maxNumIn(int *nums, int size) {
    NumInfo *info = (NumInfo *)malloc(sizeof(NumInfo) * size);
    int i;
    for (i = 0; i < size; i++) {
        setInfoWithNum(info + i, nums[i]);
    }
    sortNumsWithInfo(nums, info, size);
    free(info);
    
    for (i = 0; i < size; i++) {
        printf("%d", nums[i]);
    }
}

void setInfoWithNum(NumInfo *info, int num) {
    int s = 1;
    while (num / 10) {
        s++;
        num /= 10;
    }
    info->beginNum = num;
    info->size = s;
}

void sortNumsWithInfo(int *nums, NumInfo *infos, int size) {
    int i, j;
    for (i = 0; i < size; i++) {
        for (j = 0; j < size - i - 1; j++) {
            // 头数应该从大到小排序
            if (infos[j].beginNum < infos[j + 1].beginNum) {
                switchNumsAndInfo(nums + j, nums + j + 1, infos + j, infos + j + 1);
            }
            // 相等时，根据size写算法
            else if (infos[j].beginNum == infos[j + 1].beginNum) {
                if (num1CompareMoreMax(nums[j], infos + j, nums[j + 1], infos + j + 1)) {
                    switchNumsAndInfo(nums + j, nums + j + 1, infos + j, infos + j + 1);
                }
            }
        }
    }
}

void switchNumsAndInfo(int *num1, int *num2, NumInfo *info1, NumInfo *info2) {
    int t = *num1;
    *num1 = *num2;
    *num2 = t;
    
    NumInfo s = *info1;
    *info1 = *info2;
    *info2 = s;
}

int num1CompareMoreMax(int num1, NumInfo *info1, int num2, NumInfo *info2) {
    if (info1->size == 0 || info2->size == 0) {
        return info1->size == 0;
    }
    if (info1->beginNum > info2->beginNum) {
        return 1;
    }
    newNumWithInfo(&num1, info1);
    newNumWithInfo(&num2, info2);
    return num1CompareMoreMax(num1, info1, num2, info2);
}

void newNumWithInfo(int *num, NumInfo *info) {
    int s = 1;
    int i = 1;
    for (; i < info->size; i++) {
        s *= 10;
    }
    *num -= s * info->beginNum;
    info->size--;
    info->beginNum = *num / (s / 10);
}
