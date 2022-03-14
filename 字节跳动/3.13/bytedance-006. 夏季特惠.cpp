//
//  bytedance-006. 夏季特惠.cpp
//  字节跳动
//
//  Created by SSR on 2022/3/13.
//

#include <iostream>

using namespace std;

long long m,n,len,f[1000005],ans;
struct node{
    long long y;
    long long z;
}a[505];

int main() {
    scanf("%lld %lld",&n,&m);
    for(long long i = 1, ai, bi, ci; i <= n; i++) {
        scanf("%lld %lld %lld", &ai, &bi, &ci);
        long long vi = bi * 2 - ai;
        if(vi <= 0) {
            m -= vi;
            ans += ci;
        }
        else {
            a[++len].y = vi;
            a[len].z = ci;
        }
    }
    for(long long i = 1; i <= len; i++) {
        for(long long j = m;j >= a[i].y; j--) {
            if(f[j - a[i].y] + a[i].z > f[j])
                f[j] = f[j - a[i].y] + a[i].z;
        }
    }
    printf("%lld", f[m] + ans);
    return 0;
}
