//
//  142. 环形链表 II.c
//  字节跳动
//
//  Created by SSR on 2022/3/26.
//

#include <stdio.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode *detectCycle(struct ListNode *head);

int main() {
    
    return 0;
}

struct ListNode* detectCycle(struct ListNode* head) {
    struct ListNode *seconde = head, *first = head;
    while (first != NULL) {
        seconde = seconde->next;
        if (first->next == NULL) {
            return NULL;
        }
        first = first->next->next;
        if (first == seconde) {
            struct ListNode *ptr = head;
            while (ptr != seconde) {
                ptr = ptr->next;
                seconde = seconde->next;
            }
            return ptr;
        }
    }
    return NULL;
}
