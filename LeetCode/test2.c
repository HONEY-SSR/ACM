//
//  test2.c
//  LeetCode
//
//  Created by SSR on 2022/3/18.
//

#include <stdio.h>

int isPrimeNum(int num) {
    if(num <= 1)
        return 0;
    int i;
    for(i = 2;i * i <= num; i++){
        if(num % i == 0){
            return 0;
        }
    }
    return 1;
}
int isPalindromeNum(int num) {
    if (num < 0) {
        return 0;
    }
    int s = 0, old = num;
    while (num) {
        s = s * 10 + num % 10;
        num /= 10;
    }
    return old == num;
}

int main() {
    int max = 10000000, i;
    for (i = 1; i < max; i += 2) {
        if (isPrimeNum(i) && isPalindromeNum(i)) {
            printf("%d\n", i);
        }
    }
    return 0;
}
