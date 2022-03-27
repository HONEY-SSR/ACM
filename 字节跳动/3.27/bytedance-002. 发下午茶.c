//
//  bytedance-002. 发下午茶.c
//  字节跳动
//
//  Created by SSR on 2022/3/27.
//

#include <stdio.h>
#include <stdlib.h>

int checkOfficeWithTime(int *office, int time);

int n, m;

int main() {
    scanf("%d%d", &n, &m);
    int i, j = m;
    int *a = (int *)malloc(sizeof(int) * (m + 1));
    for (i = 1; i <= m; i++) {
        scanf("%d", a + i);
        j += a[i];
    }
    i = 0;
    while (i < j) {
        int middle = (i + j) >> 1;
        if (checkOfficeWithTime(a, middle)) {
            j = middle;
        } else {
            i = middle + 1;
        }
    }
    printf("%d\n", i);
    free(a);
    return 0;
}

int checkOfficeWithTime(int *office, int time) {
    int b[m + 1], i;
    for (i = 0; i < (m + 1); i++) {
        b[i] = office[i];
    }
    int j = m;
    while (b[j] == 0) {
        j--;
    }
    for (i = 0; i < n; i++) {
        int t;
        for (t = time - j; t > 0 && j > 0; j--) {
            if (b[j] > t) {
                b[j] -= t;
                t = 0;
                j++;
            } else {
                t -= b[j];
                b[j] = 0;
            }
        }
        if (j == 0) {
            return 1;
        }
    }
    return 0;
}
