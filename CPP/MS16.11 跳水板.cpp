#include "include.hpp"
using namespace std;
/*
面试题 16.11. 跳水板
你正在使用一堆木板建造跳水板。有两种类型的木板，其中长度较短的木板长度为shorter，长度较长的木板长度为longer。你必须正好使用k块木板。编写一个方法，生成跳水板所有可能的长度。

返回的长度需要从小到大排列。

示例：

输入：
shorter = 1
longer = 2
k = 3
输出： {3,4,5,6}
提示：

0 < shorter <= longer
0 <= k <= 100000
通过次数11,827提交次数26,939
在真实的面试中遇到过这道题？
*/

class Solution {
public:
    vector<int> divingBoard(int shorter, int longer, int k) {
        vector<int> res;
        if(k == 0) return res;
        for(int i = 0;i <= k;i++)
        {
            res.push_back(longer*i+(k-i)*shorter);
        }
        return res;
    }
};

int main()
{
    Solution s;
    system("pause");
};