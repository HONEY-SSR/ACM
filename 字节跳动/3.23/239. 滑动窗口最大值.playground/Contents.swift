import Cocoa

class Solution {
    func maxSlidingWindow(_ nums: [Int], _ k: Int) -> [Int] {
        if nums.count * k == 0 {
            return [0]
        } else if k == 1 {
            return nums
        }

        var dpLeft = [Int](repeating: 0, count: nums.count)
        dpLeft[0] = nums[0]

        var dpRight = [Int](repeating: 0, count: nums.count)
        dpRight[nums.count - 1] = nums[nums.count - 1]


        for i in 1 ..< nums.count {
            //! 1
            if i % k == 0 {
                dpLeft[i] = nums[i]
            } else {
                dpLeft[i] = max(dpLeft[i - 1], nums[i])
            }
            //! 2
            let j = nums.count - i - 1
            if (j+1) % k == 0 {
                dpRight[j] = nums[j]
            } else {
                dpRight[j] = max(dpRight[j + 1], nums[j])
            }
        }

        var output = [Int](repeating: 0, count: nums.count-k+1)
        for i in 0 ..< nums.count - k + 1 {
            output[i] = max(dpLeft[i + k - 1], dpRight[i])
        }

        return output
    }
}
