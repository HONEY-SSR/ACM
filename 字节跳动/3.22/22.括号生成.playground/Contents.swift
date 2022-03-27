//
//  22. 括号生成.swift
//  字节跳动
//
//  Created by SSR on 2022/3/22.
//

import Foundation
class Solution {
    var result = [String]()
    func generateParenthesis(_ n: Int) -> [String] {
      _generate(0, 0, n, "")
      return result
    }
    func _generate(_ left: Int, _ right: Int, _ n: Int, _ s: String) {
      if left == n && right == n {
        result.append(s)
      }
      //! 递归过程中，进行合法操作
      if left < n {
        _generate(left + 1, right, n, s + "(")
      }
      if left > right {
        _generate(left, right + 1, n, s + ")")
      }
    }
}

let a = Solution()
let s = a.generateParenthesis(3)
print(s);
