//
//  160. 相交链表.c
//  字节跳动
//
//  Created by SSR on 2022/3/26.
//

#include <stdio.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB);

int main() {
    
    
    return 0;
}

struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
    if (headA == NULL || headB == NULL) {
        return NULL;
    }
    struct ListNode *pA = headA, *pB = headB;
    while (pA != pB) {
        pA = (pA == NULL ? headB : pA->next);
        pB = (pB == NULL ? headA : pB->next);
    }
    return pA;
}
