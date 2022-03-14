//
//  54. 螺旋矩阵.c
//  字节跳动
//
//  Created by SSR on 2022/3/13.
//

#include <stdio.h>
#include <stdlib.h>

int* spiralOrder(int** matrix, int matrixSize, int* matrixColSize, int* returnSize);

int main() {
    int a[3][3] = {{1,2,3},{4,5,6},{7,8,9}};
    int e = 0;
    int r = 0;
    int *t = spiralOrder(a, 3, &e, &r);
    for (int i = 0; i < r; i++) {
        printf("%d\n", t[i]);
    }
    free(t);
    return 0;
}

int* spiralOrder(int** matrix, int matrixSize, int* matrixColSize, int* returnSize) {
    // 无数据传入时处理
    if (matrixSize == 0 || matrixColSize[0] == 0) {
        *returnSize = 0;
        return NULL;
    }
    // 初始化数据
    int *newNums = (int *)malloc(sizeof(int) * matrixSize * matrixColSize[0]);
    *returnSize = 0;
    // 上下左右
    int left = 0, right = matrixColSize[0] - 1;
    int top = 0, bottom = matrixSize - 1;
    // 用while使它在可靠范围一直循环
    while (left <= right && top <= bottom) {
        // 每一个for都是一条边，4条边对应一个圈
        // 从左到右
        for (int column = left; column <= right; column++) {
            newNums[(*returnSize)++] = matrix[top][column];
        }
        // 从上到下
        for (int row = top + 1; row <= bottom; row++) {
            newNums[(*returnSize)++] = matrix[row][right];
        }
        // 反过来的情况
        if (left < right && top < bottom) {
            // 从右到左
            for (int column = right - 1; column > left; column--) {
                newNums[(*returnSize)++] = matrix[bottom][column];
            }
            // 从下到上
            for (int row = bottom; row > top; row--) {
                newNums[(*returnSize)++] = matrix[row][left];
            }
        }
        // 对于一个圈结束，应该执行的操作
        left++;
        right--;
        top++;
        bottom--;
    }
    return newNums;
}
