//
//  14. 最长公共前缀.c
//  字节跳动
//
//  Created by SSR on 2022/3/9.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char * longestCommonPrefix(char ** strs, int strsSize);

int main () {
    char *strs[7] = {"flower","flow","flight"};
    char *s = longestCommonPrefix(strs, 3);
    puts(s);
    return 0;
}

char * longestCommonPrefix(char ** strs, int strsSize) {
    if(strsSize == 0)
        return "";
    for (int i = 0; strs[0][i] != '\0'; i++) {
        for (int j = 1; j < strsSize; j++) {
            if (strs[j][i] != strs[0][i]) {
                strs[0][i] = '\0';
                return strs[0];
            }
        }
    }
    return strs[0];
    
//
//
//    for(int i = 0; i < strlen(strs[0]); i++)
//        for(int j = 0; j < strsSize; j++)
//            if(strs[j][i] != strs[0][i]) {
//                strs[0][i] = '\0';
//                break;
//            }
//    return strs[0];
}
