//
//  143. 重排链表.c
//  字节跳动
//
//  Created by SSR on 2022/3/26.
//

#include <stdio.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

void reorderList(struct ListNode* head);

int main() {
    
    return 0;
}

void reorderList(struct ListNode* head) {
    if (head == NULL) {
        return;
    }
    struct ListNode *vec[40001];
    struct ListNode *node = head;
    int n = 0;
    while (node != NULL) {
        vec[n++] = node;
        node = node->next;
    }
    int i = 0, j = n - 1;
    while (i < j) {
        vec[i]->next = vec[j];
        i++;
        if (i == j) {
            break;
        }
        vec[j]->next = vec[i];
        j--;
    }
    vec[i]->next = NULL;
}
