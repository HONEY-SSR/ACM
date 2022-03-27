//
//  bytedance-007. 化学公式解析.c
//  字节跳动
//
//  Created by SSR on 2022/3/23.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct List {
    char *name;
    int lenth;
    struct List *next;
}List;



int main() {
    char ch[100000];
    gets(ch);
    int *en[24] = {0};
    
    
}

char *decodeString(char *s) {
    if (s == NULL) {
        return NULL;
    }
    while (1) {
        int len = (int)strlen(s);
        int left = 0, right = len;
        int i = len - 1, num = 0, w = 1;
        for (; i >= 0; i--) {
            if (s[i] == ']') {
                right = i;
            } else if(s[i] == '[') {
                left = i;
            } else if (s[i] >= '0' && s[i] <= '9') {
                do { // 组合数字
                    num += w * (s[i] - '0');
                    w *= 10;
                    i--;
                } while (i >= 0 && (s[i] >= '0' && s[i] <= '9'));
                break;
            }
        }
        if (num == 0) { //没有[]了
            return s;
        } else {
            int slen = (right - left - 1);
            int count = (i + 1) + (len - right - 1) + num * slen + 1;
            char *t = (char *)calloc(count, sizeof(char));
            if (i + 1 > 0) { // 左
                memcpy(t, s, i + 1);
            }
            for (int k = 0; k < num; k++) { // 中
                memcpy(t + (i + 1) + k * slen, s + left + 1, slen);
            }
            if (len - right - 1 > 0) {
                memcpy(t + (i + 1) + num * slen, s + right + 1, len - right - 1);
            }
            s = t;
        }
    }
}
