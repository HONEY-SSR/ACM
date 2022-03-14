//
//  7. 整数反转.c
//  字节跳动
//
//  Created by SSR on 2022/3/12.
//

#include <stdio.h>
#include <stdlib.h>

int reverse(int x);

int main() {
    printf("%d\n", reverse(1534236469));
    return 0;
}

int reverse(int x) {
    int s = 0;
    while (x != 0) {
        if (s < INT_MIN / 10 || s > INT_MAX / 10) {
            return 0;
        }
        s = s * 10 + x % 10;
        x /= 10;
    }
    return s;
}
