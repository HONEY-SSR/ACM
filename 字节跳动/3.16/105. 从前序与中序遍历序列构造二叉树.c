//
//  105. 从前序与中序遍历序列构造二叉树.c
//  字节跳动
//
//  Created by SSR on 2022/3/16.
//

#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

int main() {
    
    return 0;
}

struct TreeNode* buildTree(int* preorder, int preorderSize, int* inorder, int inorderSize){
    if(preorderSize == 0 || inorderSize == 0) {
        return NULL;
    }
    struct TreeNode* root = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    int index;
    root -> val = preorder[0];
    for(index = 0; index < inorderSize; index++) {
        if(inorder[index] == preorder[0])
            break;
    }
    root->left = buildTree(preorder + 1,index, inorder,index);
    root->right = buildTree(preorder + index + 1, preorderSize - index - 1, inorder + index + 1, preorderSize - index - 1);
    return root;
}
