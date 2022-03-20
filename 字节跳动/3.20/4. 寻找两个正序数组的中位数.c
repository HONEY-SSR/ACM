//
//  4. 寻找两个正序数组的中位数.c
//  字节跳动
//
//  Created by SSR on 2022/3/20.
//

#include <stdio.h>

double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size);

int main() {
    int a[] = {1,3,5,7,11};
    int b[] = {3,6,7,9,10};
    double c = findMedianSortedArrays(a, sizeof(a) / sizeof(int), b, sizeof(b) / sizeof(int));
    printf("%lf\n", c);
    return 0;
}

double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    int length = nums1Size + nums2Size;
    int a = 0, b = 0, mid = -1, next = -1;
    for (int i = 0; i <= length / 2; i++){
        mid = next;
        if(a < nums1Size && (b >= nums2Size || nums1[a] < nums2[b])){
            next = nums1[a];
            a++;
        }
        else{
            next = nums2[b];
            b++;
        }
    }
    if (length % 2 == 0)
        return (mid + next) / 2.0;
    return next;
}
