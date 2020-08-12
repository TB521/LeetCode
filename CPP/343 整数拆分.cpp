#include "include.hpp"
using namespace std;
/*
343. 整数拆分
给定一个正整数 n，将其拆分为至少两个正整数的和，并使这些整数的乘积最大化。 返回你可以获得的最大乘积。

示例 1:

输入: 2
输出: 1
解释: 2 = 1 + 1, 1 × 1 = 1。
示例 2:

输入: 10
输出: 36
解释: 10 = 3 + 3 + 4, 3 × 3 × 4 = 36。
说明: 你可以假设 n 不小于 2 且不大于 58。
*/

/*动态规划*/
class Solution {
private:
    vector<int> dp;
public:
    int integerBreak(int n) {
        dp = vector<int>(n+1,0);
        if(n <= 2) return 1;
        if(n == 3) return 2;
        return _integerBreak(n);
    }
    int _integerBreak(int n) {
        if(n <= 3) return n;
        if (dp[n])
            return dp[n];
        int res = 0;
        for(int i = 1;i <= (n + 1)/2;i++)
        {
            res = max(res , _integerBreak(i) * _integerBreak(n-i));
        }
        dp[n] = res;
        return res;
    }
};

/*优化动规*/
class Solution {
public:
    int integerBreak(int n) {
        if (n < 4) {
            return n - 1;
        }
        vector <int> dp(n + 1);
        dp[2] = 1;
        for (int i = 3; i <= n; i++) {
            dp[i] = max(max(2 * (i - 2), 2 * dp[i - 2]), max(3 * (i - 3), 3 * dp[i - 3]));
        }
        return dp[n];
    }
};

int main()
{
    Solution s;
    system("pause");
};