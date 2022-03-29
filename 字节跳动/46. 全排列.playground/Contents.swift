import Cocoa

class Solution {
    var res = [[Int]]()
    func permute(_ nums: [Int]) -> [[Int]] {
        var visited = Array(repeating: false, count: nums.count)
        helper(nums, [], &visited)
        return res
    }
    func helper(_ nums: [Int], _ path: [Int], _ visited: inout [Bool]) {
        if path.count == nums.count {
            res.append(path)
            return
        }
        for i in 0 ..< nums.count {
            if visited[i] {
                continue
            }
            visited[i] = true
            helper(nums, [nums[i]] + path, &visited)
            visited[i] = false
        }
    }
}

let a = Solution()
let t = a.permute([1,2,3,4,5])
print(t)
