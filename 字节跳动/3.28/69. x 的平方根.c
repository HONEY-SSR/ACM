//
//  69. x 的平方根.c
//  字节跳动
//
//  Created by SSR on 2022/3/28.
//

#include <stdio.h>

int mySqrt(int x);

int main() {
    int s = 277;
    int sqrtS = mySqrt(s);
    printf("%d\n", sqrtS);
    return 0;
}

int mySqrt(int x){
    int l = 0, r = x, ans = -1;
    while (l <= r) {
        int mid = l + (r - l) / 2;
        if ((long long)mid * mid <= x) {
            ans = mid;
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    return ans;
}
