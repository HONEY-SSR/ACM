//
//  2. 两数相加.c
//  字节跳动
//
//  Created by SSR on 2022/3/29.
//

#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode *createNodeWithNums(int *nums, int numSize);
struct ListNode *addTwoNumbers(struct ListNode *l1, struct ListNode *l2);
void logListNode(struct ListNode *list);

int main() {
    int a[] = {2,4,9};
    int b[] = {4,5,6};
    struct ListNode *node1 = createNodeWithNums(a, sizeof(a) / sizeof(int));
    struct ListNode *node2 = createNodeWithNums(b, sizeof(b) / sizeof(int));
    
    struct ListNode *sumNode = addTwoNumbers(node1, node2);
    logListNode(sumNode);
    return 0;
}

struct ListNode *createNodeWithNums(int *nums, int numSize) {
    if (numSize <= 0) {
        return NULL;
    }
    int i;
    struct ListNode *head = NULL, *tail = NULL, *pre = head;
    for (i = 0; i < numSize; i++) {
        if (head == NULL) {
            head = (struct ListNode *)malloc(sizeof(struct ListNode));
            head->val = nums[i];
            pre = head;
        } else {
            tail = (struct ListNode *)malloc(sizeof(struct ListNode));
            tail->val = nums[i];
            tail->next = NULL;
            pre->next = tail;
            pre = pre->next;
        }
    }
    return head;
}

struct ListNode *addTwoNumbers(struct ListNode *l1, struct ListNode *l2) {
    struct ListNode *head = NULL, *tail = NULL;
    int carry = 0;
    while (l1 || l2) {
        int n1 = l1 ? l1->val : 0;
        int n2 = l2 ? l2->val : 0;
        int sum = n1 + n2 + carry;
        if (!head) {
            head = tail = malloc(sizeof(struct ListNode));
            tail->val = sum % 10;
            tail->next = NULL;
        } else {
            tail->next = malloc(sizeof(struct ListNode));
            tail->next->val = sum % 10;
            tail = tail->next;
            tail->next = NULL;
        }
        carry = sum / 10;
        if (l1) {
            l1 = l1->next;
        }
        if (l2) {
            l2 = l2->next;
        }
    }
    if (carry > 0) {
        tail->next = malloc(sizeof(struct ListNode));
        tail->next->val = carry;
        tail->next->next = NULL;
    }
    return head;
}

void logListNode(struct ListNode *list) {
    while (list) {
        printf("%d", list->val);
        list = list->next;
    }
    printf("\n");
}
