#include "include.hpp"
using namespace std;
/*
试题 08.11. 硬币
硬币。给定数量不限的硬币，币值为25分、10分、5分和1分，编写代码计算n分有几种表示法。(结果可能会很大，你需要将结果模上1000000007)

示例1:

 输入: n = 5
 输出：2
 解释: 有两种方式可以凑成总金额:
5=5
5=1+1+1+1+1
示例2:

 输入: n = 10
 输出：4
 解释: 有四种方式可以凑成总金额:
10=10
10=5+5
10=5+1+1+1+1+1
10=1+1+1+1+1+1+1+1+1+1
说明：

注意:

你可以假设：

0 <= n (总金额) <= 1000000
*/

class Solution {
public:
    int waysToChange(int n) {
        int vals[4] = {1,5,10,25};
        vector<vector<int>> dp(0,vector<int>(n));
        for(int j = 0;j < 4; j++)
        {
            dp[j][0] = 1;
            for(int i = 1;i < n; i++)
            {
                if(j == 0)
                {
                    if(i % vals[0] == 0)
                        dp[j][i] = 1;
                }
                else
                {
                    if(i - vals[j] > 0)
                        dp[j][i] = dp[j-1][i-vals[j]] + dp[j][i-vals[j]];
                }
                
            }
        }
        return dp[3][n];
    }
};

int main()
{
    Solution s;
    system("pause");
};