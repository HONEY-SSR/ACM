//
//  bytedance-016. 16. 最短移动距离.cpp
//  字节跳动
//
//  Created by SSR on 2022/3/10.
//

#include<iostream>
//#include<bits/stdc++.h>

#define ll long long

using namespace std;
/**暴力100000空间，包括暴力最大数*/
const int N = 100000, info = 0x3f3f3f3f;
/**n和m用于可以跨函数直接递减
 * f用于输入，r则将松鼠转数组问题
 * hFloor用于半树，松鼠也是同样的道理
 */
int n, m, f[N], r[N], hFloor[N << 1], hRoom[N << 1];
/**flow用于将输入转树，step则是步数*/
int flow[N], step;
/**check最小步，直接更改原值*/
void check(int &a, int &b, int x, int y){
    if(x < a) {
        a = x;
        b = y;
    }
}
/**更新树当前节点，先左后右，然后check一下*/
void update(int x){
    hFloor[x] = info;
    if(r[x]) {
        hFloor[x] = 0;
        hRoom[x] = x;
    }
    
    check(hFloor[x], hRoom[x],
          hFloor[x << 1] + (flow[x << 1] < 0 ? -1 : 1), hRoom[x << 1]);
    
    check(hFloor[x], hRoom[x],
          hFloor[x << 1 | 1] + (flow[x << 1 | 1] < 0 ? -1 : 1), hRoom[x << 1 | 1]);
}

int main(){
    scanf("%d%d",&n,&m);
    for(int i = 1; i <= n; i++) {
        scanf("%d", &r[i]);
    }
    for(int i = 1; i <= m; i++) {
        scanf("%d", &f[i]);
    }
    memset(hFloor, 0x3f, sizeof hFloor);
    /**从后往前走，就是树最后一层往前层走*/
    for(int i = n; i; i--) {
        update(i);
    }
    
    for(int i = 1; i <= m; i++) {
        int x = info, y = 0, u = f[i], t = 0, v = 0;
        while(u){
            if(x > hFloor[u] + t) {
                x = hFloor[u]+t;
                y = hRoom[u];
                v = u;
            }
            t += (flow[u] > 0 ? -1 : 1);
            u >>= 1;
        }
        u = f[i];
        step += x;
        while(u != v) {
            flow[u]--;
            update(u >> 1);
            u >>= 1;
        }
        r[y]--;
        update(y);
        while(y != v){
            flow[y]++;
            update(y >> 1);
            y >>= 1;
        }
        while(v) {
            update(v);
            v >>= 1;
        }
    }
    printf("%d\n", step);
    return 0;
}
