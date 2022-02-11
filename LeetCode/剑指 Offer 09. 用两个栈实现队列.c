//
//  剑指 Offer 09. 用两个栈实现队列.c
//  LeetCode
//
//  Created by SSR on 2022/2/10.
//

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int num[10000];
    int begin;
    int end;
} CQueue;

int main() {
    return 0;
}

CQueue* cQueueCreate() {
    CQueue *queue = (CQueue *)malloc(sizeof(CQueue));
    queue->begin = queue->end = 0;
    return queue;
}

void cQueueAppendTail(CQueue* obj, int value) {
    *(obj->num + obj->end) = value;
    obj->end += 1;
}

int cQueueDeleteHead(CQueue* obj) {
    if (obj->end == obj->begin) {
        return -1;
    }
    int num = *(obj->num + obj->begin);
    obj->begin += 1;
    return num;
}

void cQueueFree(CQueue* obj) {
    free(obj);
}

/**
 * Your CQueue struct will be instantiated and called as such:
 * CQueue* obj = cQueueCreate();
 * cQueueAppendTail(obj, value);
 
 * int param_2 = cQueueDeleteHead(obj);
 
 * cQueueFree(obj);
*/
