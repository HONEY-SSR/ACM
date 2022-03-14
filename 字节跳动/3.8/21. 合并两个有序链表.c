//
//  main.c
//  字节跳动
//
//  Created by SSR on 2022/3/8.
//

#include <stdio.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

int main(int argc, const char * argv[]) {
    
    return 0;
}

struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2){
    // 保存链表的头
    struct ListNode head;
    head.next = list1;
    // 为了处理第一次
    struct ListNode* cur = &head;
    // 必须处理完其中一个链表
    while (list1 != NULL && list2 != NULL) {
        // 小的合并
        if (list1->val > list2->val) {
            cur->next = list2;
            list2 = list2->next;
        } else {
            cur->next = list1;
            list1 = list1->next;
        }
        cur = cur->next;
    }
    // 处理剩下的
    cur->next = list1 == NULL ? list2 : list1;
    // 返回链表头
    return head.next;
}
