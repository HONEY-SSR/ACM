//
//  206. 反转链表.c
//  字节跳动
//
//  Created by SSR on 2022/3/10.
//

#include <stdio.h>

int main() {
    
}


struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* reverseList(struct ListNode* head) {
    /**上一个，也是返回的头*/
    struct ListNode* end = NULL;
    /**当前*/
    struct ListNode* cur = head;
    while (cur) {
        /**保存下一个*/
        struct ListNode* next = cur->next;
        /**交换*/
        cur->next = end;
        end = cur;
        cur = next;
    }
    return end;
}
