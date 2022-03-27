//
//  322. 零钱兑换.c
//  字节跳动
//
//  Created by SSR on 2022/3/25.
//

#include <stdio.h>

int min_fun(int a, int b);
int coinChange(int* coins, int coinsSize, int amount);

int main() {
    
}

#define MAX 2147483645

int min_fun(int a, int b) {
    return a < b ? a : b;
}
int coinChange(int* coins, int coinsSize, int amount){
    int f[amount+1], i, j;
    f[0] = 0;
    for(i = 1; i <= amount; i++) {
        f[i] = MAX;
        for(j = 0; j < coinsSize; j++) {
            if(i>=coins[j] && f[i-coins[j]]!=-1) {
                f[i] = min_fun(f[i], f[i - coins[j]] + 1);
            }
        }
    }
    if(f[amount] == MAX)
        f[amount] = -1;
    return f[amount];
}
