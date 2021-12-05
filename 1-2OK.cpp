/*
 * @Descripttion: algFinal
 * @version: 1.0
 * @Author: qiuqian 19001020502邱谦
 * @LastEditors: qiquian
 */
#include <bits/stdc++.h>
using namespace std;

/**
 * 1. 分治法题目
 *  (2) 假设二叉树采用二叉链存储结构进行存储，设计一个算法采用分治 法求一棵二叉树的高度。
 */

struct TreeNode
{
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

int maxDepth(TreeNode *root)
{
  if (root == NULL)
  {
    return 0;
  }

  int left = maxDepth(root->left);
  int right = maxDepth(root->right);

  return max(left, right) + 1;
}

// void preOrder(TreeNode *root)
// {
//   if (root == NULL)
//   {
//     return;
//   }
//   cout << root->val << " ";
//   preOrder(root->left);
//   preOrder(root->right);
// }

TreeNode *createTree(vector<int> nums, int i)
{
  if (i >= nums.size() || nums[i] == -1)
  {
    return NULL;
  }
  TreeNode *root = new TreeNode(nums[i]);
  root->left = createTree(nums, 2 * i + 1);
  root->right = createTree(nums, 2 * i + 2);
  return root;
}

int main()
{
  vector<int> nums = {3, 9, 20, -1, -1, 15, 7};
  TreeNode *root = createTree(nums, 0);
  // preOrder(root);
  cout << maxDepth(root) << endl;
  return 0;
}