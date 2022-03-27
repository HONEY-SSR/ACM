//
//  bytedance-003. 古生物血缘远近判定.cpp
//  字节跳动
//
//  Created by SSR on 2022/3/25.
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;

int EditDistance(string word1,string word2) {
    int len1 = (int)word1.size();
    int len2 = (int)word2.size();
    int i, j;
    if(len1 * len2 == 0){
        return len1 == 0 ? len2 : len1;
    }
    vector<vector<int>> dp(len1 + 1, vector<int> (len2 + 1));
    for(i = 0; i < len1 + 1; i++){
        dp[i][0] = i;
    }
    for(i = 0; i < len2 + 1; i++){
        dp[0][i] = i;
    }
    for(i = 1; i < len1 + 1; i++){
        for(j = 1; j < len2 + 1; j++){
            dp[i][j] = min(min(dp[i][j - 1] + 1, dp[i - 1][j] + 1),
                           dp[i - 1][j - 1] +
                           (word1[i - 1] == word2[j - 1] ? 0 : 1));
        }
    }
    return dp[len1][len2];
}

int main() {
    string s;
    cin >> s;
    string s1;
    string s2;
    int i=0;
    while(s[i]!=','){
        s1.push_back(s[i]);
        ++i;
    }
    ++i;
    while(s[i]){
        s2.push_back(s[i]);
        ++i;
    }
    cout << EditDistance(s1, s2);
}
