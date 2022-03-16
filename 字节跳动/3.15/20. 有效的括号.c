//
//  20. 有效的括号.c
//  字节跳动
//
//  Created by SSR on 2022/3/15.
//

#include <stdio.h>
#include <stdbool.h>
#include <string.h>

bool isValid(char *s);

int main() {
    char s[10000];
    gets(s);
    if (isValid(s)) {
        printf("ture");
    }
    else {
        printf("false");
    }
    
    return 0;
}

char pairs(char a) {
    if (a == '}') return '{';
    if (a == ']') return '[';
    if (a == ')') return '(';
    return 0;
}

bool isValid(char* s) {
    int n = (int)strlen(s);
    if (n % 2 == 1) {
        return false;
    }
    int stk[n + 1], top = 0;
    for (int i = 0; i < n; i++) {
        char ch = pairs(s[i]);
        if (ch) {
            if (top == 0 || stk[top - 1] != ch) {
                return false;
            }
            top--;
        } else {
            stk[top++] = s[i];
        }
    }
    return top == 0;
}
