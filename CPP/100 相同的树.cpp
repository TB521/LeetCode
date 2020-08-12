#include "include.hpp"
using namespace std;
/*
100. 相同的树
给定两个二叉树，编写一个函数来检验它们是否相同。

如果两个树在结构上相同，并且节点具有相同的值，则认为它们是相同的。

示例 1:

输入:       1         1
          / \       / \
         2   3     2   3

        [1,2,3],   [1,2,3]

输出: true
示例 2:

输入:      1          1
          /           \
         2             2

        [1,2],     [1,null,2]

输出: false
示例 3:

输入:       1         1
          / \       / \
         2   1     1   2

        [1,2,1],   [1,1,2]

输出: false
通过次数122,270提交次数205,199
*/

class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p == NULL && q == NULL) 
            return true;
        else if(p == NULL && q != NULL) 
            return false;
        else if(p != NULL && q == NULL) 
            return false;
        else
            return isSameTree(p->right, q->right)
            && isSameTree(p->left ,q->left)
            && (p->val == q->val);
    }
};

int main()
{
    Solution s;
    system("pause");
};