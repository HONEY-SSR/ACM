//
//  394. 字符串解码.c
//  字节跳动
//
//  Created by SSR on 2022/3/17.
//

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

char *decodeString(char *s);

int main() {
    char *a = "3[a]2[bc]";
    char *t = decodeString(a);
    puts(t);
    free(t);
    return 0;
}

char *decodeString(char *s) {
    if (s == NULL) {
        return NULL;
    }
    while (true) {
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
