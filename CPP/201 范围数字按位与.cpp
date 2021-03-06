#include "include.hpp"
using namespace std;
/*
201. 数字范围按位与
给定范围 [m, n]，其中 0 <= m <= n <= 2147483647，返回此范围内所有数字的按位与（包含 m, n 两端点）。

示例 1: 

输入: [5,7]
输出: 4
示例 2:

输入: [0,1]
输出: 0
通过次数13,210提交次数28,869
*/

class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        int shiftTime = 0;
        while(m<n)
        {
            m = m >>1;
            n = n >>1;
            ++shiftTime;
        }
        return n<<shiftTime;
    }
};
int main()
{
    Solution s;
    system("pause");
};