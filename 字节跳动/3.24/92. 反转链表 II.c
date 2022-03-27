//
//  92. 反转链表 II.c
//  字节跳动
//
//  Created by SSR on 2022/3/24.
//

#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* reverseBetween(struct ListNode* head, int left, int right);

int main() {
    
    return 0;
}

struct ListNode *reverseBetween(struct ListNode *head, int left, int right) {
    
    struct ListNode *newNode = malloc(sizeof(struct ListNode));
    newNode->val = -1;
    newNode->next = head;

    struct ListNode *pre = newNode;
    for (int i = 0; i < left - 1; i++) {
        pre = pre->next;
    }
    struct ListNode *cur = pre->next;
    struct ListNode *next;
    for (int i = 0; i < right - left; i++) {
        next = cur->next;
        cur->next = next->next;
        next->next = pre->next;
        pre->next = next;
    }
    return newNode->next;
}
