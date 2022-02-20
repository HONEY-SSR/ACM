//
//  225. 用队列实现栈.c
//  LeetCode
//
//  Created by SSR on 2022/2/11.
//

// https://leetcode-cn.com/problems/implement-stack-using-queues/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main() {
    
}

#pragma mark - 单队列

//typedef struct tagListNode {
//    struct tagListNode* next;
//    int val;
//} ListNode;
//
//typedef struct {
//    ListNode* top;
//} MyStack;
//
//MyStack* myStackCreate() {
//    MyStack* stk = calloc(1, sizeof(MyStack));
//    return stk;
//}
//
//void myStackPush(MyStack* obj, int x) {
//    ListNode* node = malloc(sizeof(ListNode));
//    node->val = x;
//    node->next = obj->top;
//    obj->top = node;
//}
//
//int myStackPop(MyStack* obj) {
//    ListNode* node = obj->top;
//    int val = node->val;
//    obj->top = node->next;
//    free(node);
//
//    return val;
//}
//
//int myStackTop(MyStack* obj) {
//    return obj->top->val;
//}
//
//bool myStackEmpty(MyStack* obj) {
//    return (obj->top == NULL);
//}
//
//void myStackFree(MyStack* obj) {
//    while (obj->top != NULL) {
//        ListNode* node = obj->top;
//        obj->top = obj->top->next;
//        free(node);
//    }
//    free(obj);
//}

#pragma mark - 双队列

/**数组长度*/
#define LEN 50

#pragma mark  队列

///**队列*/
//typedef struct queue {
//    /**队列数组*/
//    int *data;
//    /**队列头*/
//    int head;
//    /**队列尾*/
//    int rear;
//    /**队列大小*/
//    int size;
//} Queue;
//
///**创建队列*/
//Queue *initQueue(int count) {
//    /**加载内存*/
//    Queue *obj = (Queue *)malloc(sizeof(Queue));
//    obj->data = (int *)malloc(count * sizeof(int));
//    /**初始化*/
//    obj->head = 0;
//    obj->rear = 0;
//    obj->size = count;
//    return obj;
//}
//
///**队尾加入数*/
//void enQueue(Queue *obj, int num) {
//    /**如果循环的下一个是头，直接返回*/
//    if ((obj->rear + 1) % obj->size == obj->head) {
//        return;
//    }
//    /**队尾赋值*/
//    obj->data[obj->rear] = num;
//    /**队尾+1*/
//    obj->rear = (obj->rear + 1) % obj->size;
//}
//
///**删除队头*/
//int deQueue(Queue *obj) {
//    /**如果空队列，则直接返回*/
//    if (obj->head == obj->rear) {
//        obj->head = obj->rear = 0;
//        return 0;
//    }
//    /**取出队头*/
//    int num = obj->data[obj->head];
//    /**对头+1*/
//    obj->head = (obj->head + 1) % obj->size;
//    return num;
//}
//
///**队为空*/
//int isEmpty(Queue *obj) {
//    return obj->head == obj->rear;
//}

#pragma mark - 测试

typedef struct queue {
    /**队列数组*/
    int *data;
    /**队列头*/
    int head;
    /**队列尾*/
    int rear;
    /**队列大小*/
    int size;
} Queue;

Queue *initQueue(int k) {
    Queue *obj = (Queue *)malloc(sizeof(Queue));
    obj->data = (int *)malloc(k * sizeof(int));
    obj->head = -1;
    obj->rear = -1;
    obj->size = k;
    return obj;
}

void enQueue(Queue *obj, int e) {
    if (obj->head == -1) {
        obj->head = 0;
    }
    obj->rear = (obj->rear + 1) % obj->size;
    obj->data[obj->rear] = e;
}

int deQueue(Queue *obj) {
    int a = obj->data[obj->head];
    if (obj->head == obj->rear) {
        obj->rear = -1;
        obj->head = -1;
        return a;
    }
    obj->head = (obj->head + 1) % obj->size;
    return a;
}

int isEmpty(Queue *obj) {
    return obj->head == -1;
}


#pragma mark 栈

/**栈*/
typedef struct {
    /**主队列*/
    Queue *queue1;
    /**临时队列*/
    Queue *queue2;
} MyStack;

/**创建栈*/
MyStack *myStackCreate() {
    /**申请空间*/
    MyStack *obj = (MyStack *)malloc(sizeof(MyStack));
    obj->queue1 = initQueue(LEN);
    obj->queue2 = initQueue(LEN);
    return obj;
}

/**向栈增一个数*/
void myStackPush(MyStack *obj, int x) {
    /**如果主队列为空，则向临时队列新增*/
    if (isEmpty(obj->queue1)) {
        enQueue(obj->queue2, x);
    }
    /**不为空，则向主队列新增*/
    else {
        enQueue(obj->queue1, x);
    }
    return;
}

/**栈删除*/
int myStackPop(MyStack *obj) {
    /**如果主队列为空*/
    if (isEmpty(obj->queue1)) {
        /**将临时队列往主队列抛，删除临时队列*/
        while (obj->queue2->head != obj->queue2->rear) {
            /**从临时队列向一队列加载*/
            enQueue(obj->queue1, deQueue(obj->queue2));
        }
        /**返回临时队列最后一个数，即最后加载的数*/
        return deQueue(obj->queue2);
    }
    /**主队列不为空，则是向临时队列抛*/
    while (obj->queue1->head != obj->queue1->rear) {
        enQueue(obj->queue2, deQueue(obj->queue1));
    }
    /**这样主队列的最后加载的就被返回了*/
    return deQueue(obj->queue1);
}

/**寻找最栈顶，也就是最后一个加载的*/
int myStackTop(MyStack *obj) {
    /**分两个情况，要么从是主队列*/
    if (isEmpty(obj->queue1)) {
        return obj->queue2->data[obj->queue2->rear];
    }
    /**要么是从临时队列*/
    return obj->queue1->data[obj->queue1->rear];
}

/**判断是否为空栈*/
bool myStackEmpty(MyStack *obj) {
    /**也分两个情况，如果指向都是不存在的，就为空*/
    if (obj->queue1->head == -1 && obj->queue2->head == -1) {
        return true;
    }
    return false;
}

/**释放内存*/
void myStackFree(MyStack *obj) {
    free(obj->queue1->data);
    obj->queue1->data = NULL;
    
    free(obj->queue1);
    obj->queue1 = NULL;
    
    free(obj->queue2->data);
    obj->queue2->data = NULL;
    
    free(obj->queue2);
    obj->queue2 = NULL;
    
    free(obj);
    obj = NULL;
}

