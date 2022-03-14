//
//  124. 二叉树中的最大路径和.c
//  字节跳动
//
//  Created by SSR on 2022/3/9.
//

#include <stdio.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

int main() {
    
}

/** 递归函数，返回值表示包含节点本身在内的左分支最大值、右分支最大值这两者的较大值。 */
int updateMaxWithNode(struct TreeNode *root, int *result) {
    /** 单个节点的处理 */
    if(*result < root->val) {
        *result = root->val;
    }

    /** 子节点。负数则不参与计算，正数返回上级处理。 */
    if(NULL == root->left && NULL == root->right) {
        if(root->val < 0) {
            return 0;
        }
        return root->val;
    }

    /** 先左再右，递归整个此节点 */
    int left = 0, right = 0, val = root->val;

    if(root->left != NULL) {
        left = updateMaxWithNode(root->left, result);
    }

    if(root->right != NULL) {
        right = updateMaxWithNode(root->right, result);
    }

    /** 左+自己+右，和结果最大值比较，看是否更新结果。 */
    if(*result < val + left + right) {
        *result = val + left + right;
    }

    /** 左、右分支路径至少有一个是正值，则选择其中一个较大值返回给上层。
    不能一起返回，是因为一起返回的话，再上一级的路径就出现分叉了。 */
    if(left > 0 || right > 0) {
        val += ((left > right) ? left : right);
    }

    /** 这里再比较一次，是因为left、right可能有负值，上面那一个比较还不够充分。
    即，val单独加上left、right的较大值，可能比加上left、right两者一起要更大。 */
    if(*result < val) {
        *result = val;
    }

    return val;
}

/** 主函数。 */
int maxPathSum(struct TreeNode *root) {
    /** 初始化为根节点的值。 */
    int result = root->val;

    updateMaxWithNode(root, &result);

    return result;
}
