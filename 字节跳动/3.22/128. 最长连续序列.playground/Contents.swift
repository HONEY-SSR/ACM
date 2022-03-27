import Cocoa

class Solution {
    func longestConsecutive(_ nums: [Int]) -> Int {
        if nums.count <= 1 {
            return nums.count
        }
        var maxLength = 0
        var dict = [Int : Int]()//用字典伪造Set
        for num in nums {
            //取值，无值则加入字典
            if dict[num] == nil {
                let left = dict[num - 1] ?? 0
                let right = dict[num + 1] ?? 0
                let curLength = left + right + 1
                if curLength > maxLength {
                    maxLength = curLength
                }
                dict[num] = curLength
                //更新左邻居端点
                dict[num - left] = curLength
                //更新右邻居端点
                dict[num + right] = curLength
            }
        }
        return maxLength
    }
}

let a = Solution()
var num = a.longestConsecutive([100,4,200,1,3,2])
print(num)
