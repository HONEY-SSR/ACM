//
//  56. 合并区间.cpp
//  字节跳动
//
//  Created by SSR on 2022/3/21.
//

#include <iostream>
#include <vector>

using namespace::std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if (intervals.size() == 0) {
            return {};
        }
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> merged;
        for (int i = 0; i < intervals.size(); ++i) {
            int L = intervals[i][0], R = intervals[i][1];
            if (!merged.size() || merged.back()[1] < L) {
                merged.push_back({L, R});
            }
            else {
                merged.back()[1] = max(merged.back()[1], R);
            }
        }
        return merged;
    }
};

int main() {
    vector<vector<int>> merge = {{1,3},{2,6},{8,10},{15,18}};
    Solution *a = new Solution();
    vector<vector<int>> resualt = a->merge(merge);
    int count = (int)resualt.size();
    for (int i = 0; i < count; i++) {
        cout << resualt[i][0] << " - " <<  resualt[i][1] << endl;
    }
    return 0;
}
