//
//  队列学习.c
//  LeetCode
//
//  Created by SSR on 2022/2/9.
//

#include <stdio.h>
#include <stdlib.h>

/**用于定义数组长度*/
#define MaxSize 5

#pragma mark - 队列结构体定义

typedef struct SSRQueue {
    /**数组头*/
    int *num;
    /**队列头*/
    int front;
    /**队列尾*/
    int rear;
    /**数组长*/
    int size;
}SSRQueue;

#pragma mark - 队列的操作

/**创建队列*/
SSRQueue *createWithNums(int *begin, int size);
/**为队列新增一个数*/
void SSRQueueAddNum(SSRQueue *queue, int num);
/**删除队列的一个数，并可以取得此数*/
int SSRQueueDeleteNum(SSRQueue *queue);
/**从队列头输出到队列尾*/
void SSRQueueShow(SSRQueue *queue);
/**长度*/
int SSRQueueLenth(SSRQueue *queue);

#pragma mark - main()

int main() {
    int num[MaxSize] = {0};
    SSRQueue *queue = createWithNums(num, sizeof(num) / sizeof(int));
    
    SSRQueueAddNum(queue, 12);
    SSRQueueAddNum(queue, 23);
    SSRQueueAddNum(queue, 34);
    SSRQueueAddNum(queue, 45);
    
    printf("queue - test1:\n");
    SSRQueueShow(queue);
    
    SSRQueueDeleteNum(queue);
    SSRQueueDeleteNum(queue);
    
    printf("queue - test2:\n");
    SSRQueueShow(queue);
    return 0;
}

#pragma mark - 队列操作

SSRQueue *createWithNums(int *begin, int size) {
    SSRQueue *queue = (SSRQueue *)malloc(sizeof(SSRQueue));
    queue->num = begin;
    queue->front = queue->rear = 0;
    queue->size = size;
    return queue;
}

void SSRQueueAddNum(SSRQueue *queue, int num) {
    if ((queue->rear + 1) % queue->size == queue->front)  {
        printf("Add Error: Queue is Full! (num: %d)\n", num);
        return;
    }
    *(queue->num + queue->rear) = num;
    queue->rear = (queue->rear + 1) % queue->size;
}

int SSRQueueDeleteNum(SSRQueue *queue) {
    if (queue->rear == queue->front) {
        printf("Delete Error: Queue is Empty!\n");
        return 0;
    }
    int num = *(queue->num + queue->front);
    queue->front = (queue->front + 1) % queue->size;
    return num;
}

void SSRQueueShow(SSRQueue *queue) {
    int i = queue->front;
    while (i != queue->rear) {
        printf("%d\n", *(queue->num + i));
        i = (i + 1) % queue->size;
    }
    return;
}

int SSRQueueLenth(SSRQueue *queue) {
    return (queue->rear - queue->front + queue->size) % queue->size;
}
