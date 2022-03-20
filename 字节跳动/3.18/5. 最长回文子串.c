//
//  5. 最长回文子串.c
//  字节跳动
//
//  Created by SSR on 2022/3/18.
//

#include <stdio.h>

char *longestPalindrome(char * s);

int main() {
    char *a = "babad";
    char *c = longestPalindrome(a);
    puts(c);
    return 0;
}

char *longestPalindrome(char * s) {
    ///  默认最大回文串是第一个字符组成的长度为1的回文串
    ///  长度不超过1k，所以用16位储存即可。
    int16_t maxStart = 0, maxSize = 1;
    int16_t s_len;
    int16_t start = 0, left, right;

    for(s_len = 0; s[s_len]; s_len++); ///< 计算长度
    if(s_len == 1)
        return s; ///< 长度为1则直接返回原字符串

    ///  start作为最长回文字符的中心，显然如果当前记录的最长回文为
    ///  maxSize位，那么第(s_len - (maxSize+1)/2 - 1)后的所有位都不可能
    ///  存在更长的回文.
    for(;start < (s_len - (maxSize + 1) / 2);start++) {
        ///  只检测比记录中更长的回文。
        ///  最简单的，尝试以start为中心，判断比记录长度多1或者2的回文需
        ///  要满足条件。
        ///  多2的条件下，左右指针的设置
        left = start - (maxSize + 1) / 2;
        right = start + maxSize / 2 + 1;
        if(left >= 0 && s[right] == s[left]) {
            ///  如果满足，检查内部是否满足条件
            for(left++, right--; s[right] == s[left] && left < right; left++, right--);
            ///  如果内部满足要求，检查外部是否支持更长的回文
            if(left >= right) {
                maxStart = start - (maxSize + 1) / 2;
                maxSize += 2;
                left = maxStart - 1;
                right = maxStart + maxSize;
                while(left >= 0 && right < s_len && s[right] == s[left]) {
                    maxSize += 2;
                    maxStart--;
                    left--;
                    right++;
                }
            }
        }
        ///  多1的条件下，左右指针的设置。
        left = start - maxSize/2;
        right = start + (maxSize + 1) / 2;
        if(left >= 0 && s[right] == s[left]) {
            ///  如果满足，检查内部是否满足条件
            for(left++, right--; s[right] == s[left] && left < right; left++, right--);
            ///  如果内部满足要求，检查外部是否支持更长的回文
            if(left >= right) {
                maxStart = start - maxSize / 2;
                maxSize += 1;
                left = maxStart - 1;
                right = maxStart + maxSize;
                while(left >= 0 && right < s_len && s[right] == s[left]) {
                    maxSize += 2;
                    maxStart--;
                    left--;
                    right++;
                }
            }
        }
    }
    s[maxStart + maxSize] = 0;
    return &s[maxStart];
}
