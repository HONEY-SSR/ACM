//
//  16test.cpp
//  字节跳动
//
//  Created by SSR on 2022/3/10.
//

#include <iostream>
//#include <bits/stdc++.h>
using namespace std;

void fast_read() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

int n, m;

int main() {
    fast_read();
    cin >> n >> m;
    vector<int> a(n + 1);
    int totalHome = 0;
    int res = 0;

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        totalHome += a[i];
    }

    for (int i = 0; i < m; i++) {
        int index;
        cin >> index;
        a[index]--;
    }

    int leftHome = totalHome - m;

    for (int i = n; i > 1; i--) {
        if (a[i] != 0) {
            if (leftHome > 0 && a[i] > 0) {
                if (leftHome > a[i]) {
                    leftHome -= a[i];
                }
                else {
                    a[i / 2] += (a[i] - leftHome);
                    res += (a[i] - leftHome);
                    a[i] = 0;
                }
                continue;
            }
            a[i / 2] += a[i];
            res += abs(a[i]);
            a[i] = 0;
        }
    }
    cout << res << endl;
}
