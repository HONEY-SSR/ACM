//
//  682. 棒球比赛.c
//  LeetCode
//
//  Created by SSR on 2022/2/8.
//

// https://leetcode-cn.com/problems/baseball-game/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int calPoints(char ** ops, int opsSize);
int main() {
//    int t = calPoints(a, 8);
//    printf("%d",t);
    return 0;
}
//int calPoints(char ** ops, int opsSize){
//    int number[1000], *n = number;
//    int i;
//    for (i = 0; i < opsSize; i++) {
//        char *c = *(ops + i);
//        int t = 1, s = 0;
//        /**判断*/
//        switch (*c) {
//            case 'C':
//                n--;
//                break;
//            case 'D':
//                *n = *(n - 1) * 2;
//                n++;
//                break;
//            case '+':
//                *n = *(n - 2) + *(n - 1);
//                break;
//            case '-':
//                t = -1;
//                c++;
//            default:
//                for (; *c; c++) {
//                    s = s * 10 + *c - '0';
//                }
//                *n = t * s;
//                break;
//        }
//    }
//    int s = 0;
//    for (i = 0; number + i < n ;i++) {
//        s += number[i];
//    }
//    return s;
//}
int calPoints(char ** ops, int opsSize){
    if(opsSize <= 0)
        return 0;
    int num[1000];
    int top = 0;
    int sum = 0;
    for(int i = 0; i < opsSize; i++) {
        switch(*ops[i]) {
            case '+' :
                num[top] = num[top - 2] + num[top - 1];
                sum += num[top];
                top ++;
            break;
            case 'D' :
                num[top] = num[top - 1] * 2;
                sum += num[top];
                top ++;
            break;
            case 'C' :
                sum -= num[top - 1];
                top--;
            break;
            default :
                num[top] = atoi(ops[i]);
                sum += num[top];
                top ++;
        }
    }
    return sum;
}
