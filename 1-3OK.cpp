/*
 * @Descripttion: algFinal
 * @version: 1.0
 * @Author: qiuqian 19001020502邱谦
 * @LastEditors: qiquian
 */
#include <bits/stdc++.h>
using namespace std;
const int NODE_NUMBER = 2;
int result = 0;

/**
 * 1. 分治法题目
 *  (3) 假设二叉树采用二叉链存储结构进行存储，设计一个算法采用分治 法求一棵二叉树中度为 2 的结点个数。
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

/**
 * @brief Get the Chidren object
 * 使用先序遍历
 * @param root 
 */
int getChidren(TreeNode *root)
{
  int count = 0;

  if (root == NULL)
  {
    return -1;
  }
  if (root->left != NULL)
  {
    count++;
  }
  if (root->right != NULL)
  {
    count++;
  }

  cout << root->val << "结点的度为：" << count << endl;
  if (count == 2)
  {
    result += 1;
  }

  if (root->left != NULL)
  {
    getChidren(root->left);
  }
  if (root->right != NULL)
  {
    getChidren(root->right);
  }

  return result;
}

int main()
{
  vector<int> nums = {3, 9, 20, -1, -1, 15, 7};
  TreeNode *root = createTree(nums, 0);
  cout << getChidren(root) << endl;

  return 0;
}