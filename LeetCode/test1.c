//
//  test1.c
//  LeetCode
//
//  Created by SSR on 2022/3/16.
//

#include <stdio.h>
#include <stdlib.h>
/*链表结点结构体*/
struct NODE {
    int val;        //可根据需求修改数据域。
    struct NODE *next;
};
 /*函数声明*/
struct NODE *createNode(void);
struct NODE *sortNodeWithAscending(struct NODE *head);
void logNode(struct NODE *node);

int main() {
    struct NODE *head;//head 用来接收链表首地址。
    head = createNode();//建立链表，并接收链表首地址
    sortNodeWithAscending(head);//将首地址传递给链表输出函数，输出链表
    logNode(head);
    return 0;
}
 
 /*creat函数  建立链表*/
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

/*output函数  输出链表*/
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

void logNode(struct NODE *node) {
    while (node) {
        printf("%d\n", node->val);
        node = node->next;
    }
}
