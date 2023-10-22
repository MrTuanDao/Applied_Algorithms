'''
Bài toán tìm dãy con có tổng lớn nhất
-2,1,-3,4,-1,2,1,-5,4
Có tổng lớn nhất là 6 vì 4,-1,2,1

Gợi ý: Sliding Windows
'''

class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        curSum = 0
        maxSub = nums[0]
        for num in nums:
            if curSum < 0: # loại bỏ những số đứng trước num nếu tổng nó nhỏ hơn 0
                curSum = 0
            curSum += num
            maxSub = max(maxSub, curSum)

        return maxSub
