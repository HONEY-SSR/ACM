//
//  135. 分发糖果.c
//  字节跳动
//
//  Created by SSR on 2022/3/21.
//

#include <stdio.h>

int candy(int* ratings, int ratingsSize);

int main() {
    int a[] = {2,3,2,4,5,3,1,7};
    int sum = candy(a, sizeof(a) / sizeof(int));
    printf("%d\n ", sum);
    return 0;
}

int candy(int* ratings, int ratingsSize) {
    int sum = 1, inc = 1, dec = 0, current = 1;
    for (int i = 1; i < ratingsSize; i++) {
        if (ratings[i] >= ratings[i - 1]) {
            dec = 0;
            current = ratings[i] == ratings[i - 1] ? 1 : current + 1;
            sum += current;
            inc = current;
        } else {
            dec++;
            if (dec == inc) {
                dec++;
            }
            sum += dec;
            current = 1;
        }
    }
    return sum;
}
