//
//  200. 岛屿数量.c
//  字节跳动
//
//  Created by SSR on 2022/3/15.
//

#include <stdio.h>

void dfs(char** grid, int x, int y, int m , int n);
int numIslands(char** grid, int gridSize, int* gridColSize);

int main() {
    char a[][2] = {
        {"1","1","1","1","0"},
        {"1","1","0","1","0"},
        {"1","1","0","0","0"},
        {"0","0","0","0","0"}
    };
    int s;
    int sum = numIslands(a, sizeof(a)/sizeof(a[0]), &s);
    printf("%d\n", sum);
}

void dfs(char** grid, int x, int y, int m , int n) {
    grid[x][y] = '0';
    if (x + 1 < m && grid[x + 1][y] == '1') {
        dfs(grid, x + 1, y, m, n);
    }
    if (y + 1 < n && grid[x][y + 1] == '1') {
        dfs(grid, x, y + 1, m, n);
    }
    if (x - 1 >= 0 && grid[x - 1][y] == '1') {
        dfs(grid, x - 1, y, m, n);
    }
    if (y - 1 >= 0 && grid[x][y - 1] == '1') {
        dfs(grid, x, y - 1, m, n);
    }
}

int numIslands(char** grid, int gridSize, int* gridColSize) {
    int m = gridSize;
    int n = gridColSize[0];
    int islandNum = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[i][j] == '1') {
                islandNum++;
                dfs(grid, i, j, m, n);
            }
        }
    }
    return islandNum;
}
