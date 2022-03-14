//
//  42. 接雨水.c
//  字节跳动
//
//  Created by SSR on 2022/3/11.
//

#include <stdio.h>

int trap(int* height, int heightSize);

int main() {
    
    return 0;
}

int trap(int* height, int heightSize) {
    int ans = 0;
    int left = 0, right = heightSize - 1;
    int leftMax = 0, rightMax = 0;
    while (left < right) {
        leftMax = (leftMax > height[left] ? leftMax : height[left]);
        rightMax = (rightMax > height[right] ? rightMax : height[right]);
        if (height[left] < height[right]) {
            ans += leftMax - height[left];
            ++left;
        } else {
            ans += rightMax - height[right];
            --right;
        }
    }
    return ans;
}
