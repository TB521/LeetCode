"""

5424. 数组中两元素的最大乘积 显示英文描述 
通过的用户数236
尝试过的用户数259
用户总通过次数248
用户总提交次数277
题目难度Easy
给你一个整数数组 nums，请你选择数组的两个不同下标 i 和 j，使 (nums[i]-1)*(nums[j]-1) 取得最大值。

请你计算并返回该式的最大值。

示例 1：

输入：nums = [3,4,5,2]
输出：12 
解释：如果选择下标 i=1 和 j=2（下标从 0 开始），则可以获得最大值，(nums[1]-1)*(nums[2]-1) = (4-1)*(5-1) = 3*4 = 12 。 
示例 2：

输入：nums = [1,5,4,5]
输出：16
解释：选择下标 i=1 和 j=3（下标从 0 开始），则可以获得最大值 (5-1)*(5-1) = 16 。
示例 3：

输入：nums = [3,7]
输出：12
 

提示：

2 <= nums.length <= 500
1 <= nums[i] <= 10^3
"""
class Solution:
    def maxProduct(self, nums):
        for i in range(len(nums)):
            nums[i] -= 1
        res = 0
        for i in range(len(nums)):
            for j in range(i+1,len(nums)):
                res = max(res,nums[i]*nums[j])
        return res