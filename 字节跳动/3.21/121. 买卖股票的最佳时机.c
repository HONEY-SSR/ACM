//
//  121. 买卖股票的最佳时机.c
//  字节跳动
//
//  Created by SSR on 2022/3/21.
//

#include <stdio.h>

int maxProfit(int* prices, int pricesSize);

int main() {
    int a[] = {7,1,5,3,6,4};
    int profit = maxProfit(a, sizeof(a) / sizeof(int));
    printf("%d\n", profit);
    return 0;
}

int maxProfit(int* prices, int pricesSize) {
    int profit = 0;
    int minPrice = prices[0];
    int i;
    for(i = 0; i < pricesSize; i++) {
        if(minPrice > prices[i])
            minPrice = prices[i];
        if(prices[i] - minPrice > profit)
            profit = prices[i] - minPrice;
    }
    return profit;
}
