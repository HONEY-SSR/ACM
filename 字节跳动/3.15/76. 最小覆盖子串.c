//
//  76. 最小覆盖子串.c
//  字节跳动
//
//  Created by SSR on 2022/3/15.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *minWindow(char *s, char *t);

int main() {
    char *s = "ADOBECODEBANC";
    char *t = "ABC";
    char *resault = minWindow(s, t);
    puts(resault);
    return 0;
}

#define CHARACTER_NUM 128

char *minWindow(char *s, char *t) {
    if (s == NULL || t == NULL) {
        return "";
    }

    int len_s = (int)strlen(s);
    int len_t = (int)strlen(t);
    if (len_s < len_t) {    // 如果s能覆盖t，则s的长度最起码不小于t的长度
        return "";
    }

    int need[CHARACTER_NUM] = {0};        // need用于记录t中各个字符出现的次数，用于匹配判断s中是否已经找到一个覆盖t的子串
    int window[CHARACTER_NUM] = {0};      // 当前窗口内各个字符出现的次数
    int i;
    for (i = 0; i < len_t; i++) {
        need[t[i]]++;
    }

    int needNum = 0;  // 记录字符串t中不同字符的个数
    for (i = 0; i < CHARACTER_NUM; i++) {
        if (need[i] > 0) {
            needNum++;
        }
    }

    int matchSize = 0;            // 当前窗口内已经次数匹配成功的字符个数
    int left = 0;                 // 当前窗口左指针
    int right = 0;                // 当前窗口右指针
    int start = 0;                // 可以覆盖t的子串的起始位置索引
    int windowSize = len_s + 1;     // 可以覆盖t的子串的长度
    while (right < len_s) {
        char cur = s[right];
        right++;
        if (need[cur] > 0) {      // 如果该字符在t中，即需要匹配，则进行判断
            window[cur]++;
            if (window[cur] == need[cur]) {    // 如果当前窗口内该字符次数与t中次数一样，说明完成一个字符的匹配，计数加1
                matchSize++;
            }
        }

        while (matchSize == needNum) {          // 如果当前窗口内已经完全匹配，则移动左指针压缩窗口
            if ((right - left) < windowSize) {  // 如果当前匹配成功的窗口大小与上一次匹配成功的窗口更小，则更新为当前窗口
                start = left;                   // 更新覆盖子串的起始位置
                windowSize = right - left;      // 更新覆盖子串的大小
            }

            char c = s[left];
            left++;
            if (need[c] > 0) {                  // 移动左指针，相关计数减1
                if (window[c] == need[c]) {
                    matchSize--;
                }
                window[c]--;
            }
        }
    }

    if (windowSize == len_s + 1) {    // 如果遍历之后没有找到覆盖子串，则返回空串
        return "";
    }

    char *ret = (char *)malloc(sizeof(char) * (windowSize + 1));
    if (ret == NULL) {
        return NULL;
    }
    memset(ret, 0, sizeof(char) * (windowSize + 1));

    for (i = 0; i < windowSize; i++) {    // 否则返回最新覆盖子串
        ret[i] = s[start + i];
    }

    return ret;
}
