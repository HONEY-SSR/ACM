//
//  23. 合并K个升序链表.c
//  字节跳动
//
//  Created by SSR on 2022/3/12.
//

#include <stdio.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

int main() {
    
}

struct ListNode* mergeTwoLists(struct ListNode *first, struct ListNode *secend) {
    struct ListNode head;
    struct ListNode* tail = &head;
    head.next = NULL;
    while(first && secend){
        if (first->val <= secend->val){
            tail->next = first;
            first = first->next;
        }
        else{
            tail->next = secend;
            secend = secend->next;
        }
        tail = tail->next;
    }
    tail->next = first ? first : secend;
    return head.next;
}

struct ListNode* TwoLists(struct ListNode** lists, int l, int size) {
    if(l == size)
        return lists[l];
    if(l > size)
        return NULL;
    int mid = l + (size - l)/2;
    struct ListNode *listFirst = TwoLists(lists, l, mid);
    struct ListNode *listSecond = TwoLists(lists, mid+1, size);
    return mergeTwoLists(listFirst, listSecond);
}

struct ListNode* mergeKLists(struct ListNode** lists, int listsSize){
    if(!listsSize)
        return NULL;
    return TwoLists(lists, 0, listsSize-1);
}
