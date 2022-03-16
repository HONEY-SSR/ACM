//
//  main.c
//  LeetCode
//
//  Created by SSR on 2022/2/7.
//

// https://leetcode-cn.com/problems/valid-parentheses/

#include <stdio.h>
#include <stdbool.h>

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

bool isValid(char *s) {
    char c[10001] = "\0", *t = c;
    int i;
    for (i = 0; *s && i < 10001; s++, i++) {
        switch (*s) {
            case '[':
            case '{':
            case '(':
                *t = *s;
                t++;
                break;
            case ']':
                if (t == c || *(t - 1) != '[') {
                    return false;
                }
                t--;
                break;
            case '}':
                if (t == c || *(t - 1) != '{') {
                    return false;
                }
                t--;
                break;
            case')':
                if (t == c || *(t - 1) != '(') {
                    return false;
                }
                t--;
                break;
        }
    }
    return t == c;
}
