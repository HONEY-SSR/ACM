//
//  102. 二叉树的层序遍历.c
//  字节跳动
//
//  Created by SSR on 2022/3/17.
//

#include <stdio.h>
#include <stdlib.h>

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

#define MaxSize 2000

int** levelOrder(struct TreeNode* root,int* returnSize,int** returnColumnSizes) {
    *returnSize = 0;
    if(root == NULL)
        return NULL;
    int **res = (int **)malloc(sizeof(int *) * MaxSize);
    *returnColumnSizes = (int *)malloc(sizeof(int) * MaxSize);
    struct TreeNode* queue[MaxSize];
    int front = 0,rear = 0;
    struct TreeNode *cur;

    queue[rear++] = root;
    while(front != rear) {
        int colSize = 0,last = rear;
        res[*returnSize] = (int *)malloc(sizeof(int) * (last - front));
        while(front < last) {
            cur = queue[front++];
            res[*returnSize][colSize++] = cur ->val;
            if(cur -> left != NULL)
                queue[rear++] = cur -> left;
            if(cur -> right != NULL)
                queue[rear++] = cur -> right;
        }
        (*returnColumnSizes)[*returnSize] = colSize;
        (*returnSize)++;
    }
    return res;
}
