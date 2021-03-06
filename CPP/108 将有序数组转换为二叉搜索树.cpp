#include "include.hpp"
using namespace std;
/*
题目描述
108. 将有序数组转换为二叉搜索树
将一个按照升序排列的有序数组，转换为一棵高度平衡二叉搜索树。

本题中，一个高度平衡二叉树是指一个二叉树每个节点 的左右两个子树的高度差的绝对值不超过 1。

示例:

给定有序数组: [-10,-3,0,5,9],

一个可能的答案是：[0,-3,9,-10,null,5]，它可以表示下面这个高度平衡二叉搜索树：

      0
     / \
   -3   9
   /   /
 -10  5
*/
/*
分治 思想
*/
class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return sortedArrayToBSTPart(nums,0,nums.size()-1);
    }

    TreeNode* sortedArrayToBSTPart(vector<int>& nums,int left, int right)
    {
        if (left == right)
            return new TreeNode(nums[left]);
        int mid =left + (right - left)/2;
        TreeNode * root = new TreeNode(nums[mid]);
        root->left = sortedArrayToBSTPart(nums,left,mid-1);
        root->right = sortedArrayToBSTPart(nums,mid+1,right);
        return root;
    }
};

int main()
{
    Solution s;
    system("pause");
};