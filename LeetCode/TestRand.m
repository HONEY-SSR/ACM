//
//  TestRand.m
//  LeetCode
//
//  Created by SSR on 2022/3/10.
//

#import <Foundation/Foundation.h>
void test(int maxRand, int count, BOOL rabit);

int main() {
    int room = arc4random() % 100000;
    int rabit = arc4random() % room;
    printf("%d %d \n", room, rabit);
    test(rabit + 1, room, NO);
    test(room, rabit, YES);
}

void test(int maxRand, int count, BOOL rabit) {
    for (int i = 1; i <= count; i++) {
        int rand = arc4random() % maxRand % 5;
        printf("%d ", rand + (rabit ? 1 : 0));
        if (!rabit) {
            maxRand -= rand;
        }
    }
    printf("\n");
}
