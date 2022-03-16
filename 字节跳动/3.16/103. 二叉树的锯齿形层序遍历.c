//
//  103. 二叉树的锯齿形层序遍历.c
//  字节跳动
//
//  Created by SSR on 2022/3/16.
//

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
#define N 2000

int** zigzagLevelOrder(struct TreeNode* root, int* returnSize, int** returnColumnSizes) {
    *returnSize = 0;
    if (root == NULL) {
        return NULL;
    }
    int **ans = (int **)malloc(sizeof(int*) * N);
    *returnColumnSizes = malloc(sizeof(int) * N);
    struct TreeNode *nodeQueue[N];
    int left = 0, right = 0;
    nodeQueue[right++] = root;
    bool isOrderLeft = true;

    while (left < right) {
        int levelList[N * 2];
        int front = N, rear = N;
        int size = right - left;
        for (int i = 0; i < size; i++) {
            struct TreeNode* node = nodeQueue[left++];
            if (isOrderLeft) {
                levelList[rear++] = node->val;
            } else {
                levelList[--front] = node->val;
            }
            if (node->left) {
                nodeQueue[right++] = node->left;
            }
            if (node->right) {
                nodeQueue[right++] = node->right;
            }
        }
        int *tmp = (int *)malloc(sizeof(int) * (rear - front));
        for (int i = 0; i < rear - front; i++) {
            tmp[i] = levelList[i + front];
        }
        ans[*returnSize] = tmp;
        (*returnColumnSizes)[*returnSize] = rear - front;
        (*returnSize)++;
        isOrderLeft = !isOrderLeft;
    }
    return ans;
}

