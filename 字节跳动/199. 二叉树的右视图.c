//
//  199. 二叉树的右视图.c
//  字节跳动
//
//  Created by SSR on 2022/3/10.
//

#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

void depthFind(struct TreeNode *current, int depth, int *nums, int *nowDepth);

int main() {
    
}

int* rightSideView(struct TreeNode* root, int* returnSize)
{
    *returnSize = 0;//无数据
    /**为空时直接返回，不做malloc*/
    if (!root) {
        return NULL;
    }
    /**暴力100内存*/
    int *nums = (int *)malloc(sizeof(int) * 100);
    /**自顶向下，所以是0*/
    depthFind(root, 0, nums, returnSize);
    /**个数就是传入的深度*/
    return nums;
}

/**传入当前的根节，和所在的深度，还有整体数组，和数组所记录的深度（保证数组必须够用）*/
void depthFind(struct TreeNode *current, int depth, int *nums, int *nowDepth) {
    /**无了，可以返回了*/
    if (current == NULL) {
        return;
    }
    /**当前节点无数，第一次看到这个数，那么就加入到nums*/
    if (depth == *nowDepth) {
        nums[(*nowDepth)++] = current->val;
    }
    /**此深度+1*/
    depth++;
    /**遍历右再遍历左*/
    depthFind(current->right, depth, nums, nowDepth);
    depthFind(current->left, depth, nums, nowDepth);
}
