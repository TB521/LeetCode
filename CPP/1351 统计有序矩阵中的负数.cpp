#include "include.hpp"
using namespace std;
/*
1351. 统计有序矩阵中的负数
给你一个 m * n 的矩阵 grid，矩阵中的元素无论是按行还是按列，都以非递增顺序排列。 

请你统计并返回 grid 中 负数 的数目。

 

示例 1：

输入：grid = [[4,3,2,-1],[3,2,1,-1],[1,1,-1,-2],[-1,-1,-2,-3]]
输出：8
解释：矩阵中共有 8 个负数。
示例 2：

输入：grid = [[3,2],[1,0]]
输出：0
示例 3：

输入：grid = [[1,-1],[-1,-1]]
输出：3
示例 4：

输入：grid = [[-1]]
输出：1
 

提示：

m == grid.length
n == grid[i].length
1 <= m, n <= 100
-100 <= grid[i][j] <= 100
通过次数13,709提交次数17,933
在真实的面试中遇到过这道题？
*/

class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int m = grid.size(),n = grid[0].size();
        int res = 0;
        int d = 0;
        for(int i = m - 1;i >= 0; i--)
        {
            for(int j = d; j < n; j++)
            {
                if(grid[i][j] < 0)
                {
                    res += (n - j);
                    d = j;
                    break;
                }
            }
        }
        return res;
    }
};
int main()
{
    Solution s;
    system("pause");
};