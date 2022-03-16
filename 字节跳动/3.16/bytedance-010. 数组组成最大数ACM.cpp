//
//  bytedance-010. 数组组成最大数ACM.cpp
//  字节跳动
//
//  Created by SSR on 2022/3/16.
//

#include <iostream>
#include <string>
#include <map>
//#include <bits/stdc++.h>
using namespace std;

void fast_read()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}

int main()
{
    fast_read();

    // 读入整个数组为一个字符串
    string array;
    cin >> array;
    // 将整个字符串拆分成各个数
    vector<string> nums;
    for (int i = 1, j = 1; j < array.size(); j++) {
        if (array[j] == ',' || array[j] == ']') {
            string num = array.substr(i, j - i);
            nums.push_back(num);
            i = j + 1;
        }
    }
    // 按自定义规则排序
    sort(nums.begin(), nums.end(), [&](const string& a, const string& b){
        return a + b > b + a;
    });
    // 打印结果
    string res = "";
    for (auto& num : nums) res += num;
    cout << res << endl;
    return 0;
}
