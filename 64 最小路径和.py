"""
给定一个包含非负整数的 m x n 网格，请找出一条从左上角到右下角的路径，使得路径上的数字总和为最小。

说明：每次只能向下或者向右移动一步。

示例:

输入:
[
  [1,3,1],
  [1,5,1],
  [4,2,1]
]
输出: 7
解释: 因为路径 1→3→1→1→1 的总和最小。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/minimum-path-sum
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
"""
import numpy as np
#同上题 动规求解

class Solution:
    def minPathSum(self, grid):
        grid = [[1000]*(len(grid[0])+1)] + [[1000] + grid[i] for i in range(len(grid))]
        #print(np.array(grid))
        grid[0][1] = 0
        for y in range(1,len(grid)):
            for x in range(1,len(grid[0])):
                grid[y][x] += min(grid[y-1][x],grid[y][x-1])
                print(np.array(grid))
        return grid[-1][-1]

s = Solution()
s.minPathSum(
    [
        [1,3,1],
        [1,5,1],
        [4,2,1]
    ]
)

s.minPathSum(
    [
        [1,2,5],
        [3,2,1]
    ]
)