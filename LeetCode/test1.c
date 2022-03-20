//
//  test1.c
//  LeetCode
//
//  Created by SSR on 2022/3/16.
//

#include <stdio.h>
#include <stdlib.h>

struct NODE {
    int val;
    struct NODE *next;
};

struct NODE *createNode(void);
struct NODE *sortNodeWithAscending(struct NODE *head);
struct NODE* mergeTwoLists(struct NODE* list1, struct NODE* list2);
void logNode(struct NODE *node);

int main() {
    struct NODE *first = NULL, *secend = NULL;
    
    first = createNode();
    secend = createNode();
    
    sortNodeWithAscending(first);
    sortNodeWithAscending(secend);
    printf("first NODE :\n");
    logNode(first);
    printf("secend NODE :\n");
    logNode(secend);
    
    struct NODE *newNode = mergeTwoLists(first, secend);
    printf("merge NODE :\n");
    logNode(newNode);
    
    return 0;
}

struct NODE *createNode() {
    struct NODE *currentNode = NULL, *nextNode = NULL, *head = NULL;
    int t;
    scanf("%d", &t);
    while (t > 0) {
        if (head == NULL) {
            head = (struct NODE *)malloc(sizeof(struct NODE));
            head->val = t;
            head->next = NULL;
            currentNode = head;
        }else {
            nextNode = (struct NODE *)malloc(sizeof(struct NODE));
            nextNode->val = t;
            nextNode->next = NULL;
            currentNode->next = nextNode;
            currentNode = currentNode->next;
        }
        scanf("%d", &t);
    }
    return head;//将链表的首地址传回。
}

struct NODE *sortNodeWithAscending(struct NODE *head) {
    struct NODE *p1, *p2;
    
    for (p1 = head; p1; p1 = p1->next) {
        for (p2 = head; p2->next ; p2 = p2->next) {
            if (p2->val > p2->next->val) {
                int t = p2->val;
                p2->val = p2->next->val;
                p2->next->val = t;
            }
        }
    }
    return head;
}

struct NODE* mergeTwoLists(struct NODE* list1, struct NODE* list2){
    struct NODE head;
    head.next = list1;
    struct NODE* cur = &head;
    while (list1 != NULL && list2 != NULL) {
        if (list1->val > list2->val) {
            cur->next = list2;
            list2 = list2->next;
        } else {
            cur->next = list1;
            list1 = list1->next;
        }
        cur = cur->next;
    }
    cur->next = list1 == NULL ? list2 : list1;
    return head.next;
}

void logNode(struct NODE *node) {
    while (node) {
        printf("%d\n", node->val);
        node = node->next;
    }
}
