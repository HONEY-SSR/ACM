//
//  bytedance-004. 机器人跳跃问题.c
//  字节跳动
//
//  Created by SSR on 2022/3/19.
//

#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, i;
    scanf("%d", &n);
    int *h = (int *)malloc(sizeof(int) * n);
    for (i = 0; i < n; i++) {
        scanf("%d", h + i);
    }
    int energy = 0;
    for (i = n - 1; i >= 0; i--) {
        energy = (h[i] + energy + 1) / 2;
    }
    printf("%d\n", energy);
    free(h);
    return 0;
}
