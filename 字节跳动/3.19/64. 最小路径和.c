//
//  64. 最小路径和.c
//  字节跳动
//
//  Created by SSR on 2022/3/19.
//

#include <stdio.h>

int minPathSum(int** grid, int gridSize, int* gridColSize);
int minNum(int num1, int num2);

int main() {
    int a[3][3] = {{1,3,1},{1,5,1},{4,2,1}};
    int s[3] = {3,3,3};
    int t = minPathSum(a, 3, s);
    printf("%d", t);
    return 0;
}

int minPathSum(int** grid, int gridSize, int* gridColSize) {
    int section = gridSize, row = gridColSize[0];
    if (section == 0 || row == 0) {
        return 0;
    }
    int dp[section][row];
    dp[0][0] = grid[0][0];
    for (int i = 1; i < section; i++) {
        dp[i][0] = dp[i - 1][0] + grid[i][0];
    }
    for (int j = 1; j < row; j++) {
        dp[0][j] = dp[0][j - 1] + grid[0][j];
    }
    for (int i = 1; i < section; i++) {
        for (int j = 1; j < row; j++) {
            dp[i][j] = minNum(dp[i - 1][j], dp[i][j - 1]) + grid[i][j];
        }
    }
    return dp[section - 1][row - 1];
}

int minNum(int num1, int num2) {
    return num1 < num2 ? num1 : num2;
}
