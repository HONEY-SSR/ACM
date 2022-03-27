//
//  232. 用栈实现队列.c
//  字节跳动
//
//  Created by SSR on 2022/3/22.
//

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

//栈
typedef struct {
    int* stk;//维护一个数组
    int stkSize;//有数的长度
    int stkCapacity;//整体长度
} Stack;

//根据长度创建栈
Stack* stackCreate(int cpacity) {
    Stack* ret = malloc(sizeof(Stack));
    ret->stk = malloc(sizeof(int) * cpacity);
    ret->stkSize = 0;
    ret->stkCapacity = cpacity;
    return ret;
}

//向栈加入数
void stackPush(Stack* obj, int x) {
    obj->stk[obj->stkSize++] = x;
}

//推出栈
void stackPop(Stack* obj) {
    obj->stkSize--;
}

//输出栈顶数
int stackTop(Stack* obj) {
    return obj->stk[obj->stkSize - 1];
}

//栈是否为空
bool stackEmpty(Stack* obj) {
    return obj->stkSize == 0;
}

//释放栈
void stackFree(Stack* obj) {
    free(obj->stk);
}

//队列
typedef struct {
    Stack* inStack;
    Stack* outStack;
} MyQueue;

//队列创建
MyQueue* myQueueCreate() {
    MyQueue* ret = malloc(sizeof(MyQueue));
    ret->inStack = stackCreate(100);
    ret->outStack = stackCreate(100);
    return ret;
}

//将in栈到out栈
void in2out(MyQueue* obj) {
    while (!stackEmpty(obj->inStack)) {
        stackPush(obj->outStack, stackTop(obj->inStack));
        stackPop(obj->inStack);
    }
}

//向栈加数
void myQueuePush(MyQueue* obj, int x) {
    stackPush(obj->inStack, x);
}

//退出栈
int myQueuePop(MyQueue* obj) {
    if (stackEmpty(obj->outStack)) {
        in2out(obj);
    }
    int x = stackTop(obj->outStack);
    stackPop(obj->outStack);
    return x;
}

//检查栈
int myQueuePeek(MyQueue* obj) {
    if (stackEmpty(obj->outStack)) {
        in2out(obj);
    }
    return stackTop(obj->outStack);
}

//栈是否为空
bool myQueueEmpty(MyQueue* obj) {
    return stackEmpty(obj->inStack) && stackEmpty(obj->outStack);
}

//释放栈
void myQueueFree(MyQueue* obj) {
    stackFree(obj->inStack);
    stackFree(obj->outStack);
}

int main() {
    MyQueue *queue = myQueueCreate();
    myQueuePush(queue, 1);
    return 0;
}
