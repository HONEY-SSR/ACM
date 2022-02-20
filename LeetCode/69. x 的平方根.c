//
//  69. x 的平方根.c
//  LeetCode
//
//  Created by SSR on 2022/2/16.
//

// https://leetcode-cn.com/problems/sqrtx/

#include <stdio.h>

int mySqrt(int x);

int main() {
    
    printf("%d\n", mySqrt(2147395599));
    return 0;
}

int mySqrt(int x) {
    int left = 0, right = x / 2 + 1;
    while (left <= right) {
        double middle = (left + right) / 2;
        if (middle * middle == x) {
            return middle;
        }
        else if (middle * middle < x) {
            left = middle + 1;
        }
        else {
            right = middle - 1;
        }
    }
    return right;
}
