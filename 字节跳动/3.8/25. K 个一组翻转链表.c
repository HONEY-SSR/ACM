//
//  25. K 个一组翻转链表.c
//  字节跳动
//
//  Created by SSR on 2022/3/8.
//

#include <stdio.h>


int main() {
    
}

struct ListNode {
    int val;
    struct ListNode *next;
};

/**逆序，不管p指向什么，最后head就会指向那个*/
void reverse(struct ListNode *head, struct ListNode *p)
{
    // 保存最后一个的指向
    struct ListNode *p1 = head->next;
    struct ListNode *j = NULL;
    head->next = NULL;
    while(p1 != p)
    {
        j = p1->next;
        p1->next = head;
        head = p1;
        p1 = j;
    }
}

/**重组数据*/
struct ListNode* reverseKGroup(struct ListNode* head, int k){
    if(k == 1) return head;
    struct ListNode *p = head;
    struct ListNode *pre = head;
    int i=0;
    while(i < k)
    {
        if(!p) return head;
        pre=p;
        p=p->next;
        i++;
    }
    reverse(head,p);
    head->next = reverseKGroup(p,k);
    return pre;
}
