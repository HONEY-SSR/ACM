//
//  887. 鸡蛋掉落.c
//  字节跳动
//
//  Created by SSR on 2022/3/28.
//

#include <stdio.h>

int main() {
    
    return 0;
}

int fun(int k, int t) {
    if (t == 1 || k == 1)
        return t + 1;
    return fun(k - 1, t - 1) + fun(k, t - 1);
}

int superEggDrop(int k, int n) {
    int t = 1;
    while (fun(k, t) < (n + 1))
        t++;
    return t;
}
