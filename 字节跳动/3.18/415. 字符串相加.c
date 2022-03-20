//
//  415. 字符串相加.c
//  字节跳动
//
//  Created by SSR on 2022/3/18.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char * addStrings(char * num1, char * num2);

int main() {
    char *a = "123456";
    char *b = "2345";
    char *c = addStrings(a, b);
    puts(c);
    return 0;
}

char* addStrings(char* num1, char* num2) {
    int i = (int)strlen(num1) - 1, j = (int)strlen(num2) - 1, add = 0;
    char *ans = (char *)malloc(sizeof(char) * ((i > j ? i : j) + 3));
    int len = 0;
    while (i >= 0 || j >= 0 || add != 0) {
        int x = i >= 0 ? num1[i] - '0' : 0;
        int y = j >= 0 ? num2[j] - '0' : 0;
        int result = x + y + add;
        ans[len++] = '0' + result % 10;
        add = result / 10;
        i--;
        j--;
    }
    // 计算完以后的答案需要翻转过来
    for (int i = 0; 2 * i < len; i++) {
        int t = ans[i];
        ans[i] = ans[len - i - 1];
        ans[len - i - 1] = t;
    }
    ans[len++] = 0;
    return ans;
}
