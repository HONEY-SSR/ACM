import Cocoa

public class TreeNode {
    public var val: Int
    public var left: TreeNode?
    public var right: TreeNode?
    public init() {
        self.val = 0
        self.left = nil
        self.right = nil
    }
    public init(_ val: Int) {
        self.val = val
        self.left = nil
        self.right = nil
    }
    public init(_ val: Int, _ left: TreeNode?, _ right: TreeNode?) {
        self.val = val
        self.left = left
        self.right = right
    }
}

class Solution {
    func sumNumbers(_ root: TreeNode?) -> Int {
        return dfs(root, 0)
    }
    func dfs(_ node: TreeNode?, _ parentSum: Int) -> Int {
        guard let node = node else { return 0 }
        let sum = parentSum * 10 + node.val

        if node.left == nil && node.right == nil {
            return sum
        } else {
            return dfs(node.left, sum) + dfs(node.right, sum)
        }
    }
}

let tree = TreeNode(2,
        TreeNode(5, nil, nil), TreeNode(7, nil, nil))

let a = Solution()
let t = a.sumNumbers(tree)
print(t)
