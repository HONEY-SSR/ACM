//
//  141. 环形链表.c
//  字节跳动
//
//  Created by SSR on 2022/3/24.
//

#include <stdio.h>
#include <stdbool.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

bool hasCycle(struct ListNode* head);

int main() {
    
    return 0;
}

bool hasCycle(struct ListNode* head) {
    if (head == NULL || head->next == NULL) {
        return false;
    }
    struct ListNode *first = head->next;
    struct ListNode *second = head;
    while (second != first) {
        if (first == NULL || first->next == NULL) {
            return false;
        }
        second = second->next;
        first = first->next->next;
    }
    return true;
}
