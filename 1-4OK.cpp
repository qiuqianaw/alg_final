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
 *  (4) 请模仿二分查找过程设计一个三分查找算法。
 */

int findTarget(vector<int> &nums, int target)
{
  int left = 0, right = nums.size() - 1;
  while (left <= right)
  {
    int mid = left + (right - left) / 2;
    if (nums[mid] == target)
    {
      return mid;
    }
    else if (nums[mid] < target)
    {
      left = mid + 1;
    }
    else
    {
      right = mid - 1;
    }
  }
  return -1;
}

int ternaryFind(vector<int> &nums, int target)
{
  int left = 0;
  int right = nums.size() - 1;
  while (left <= right)
  {
    int midl = left + (right - left) / 3;
    int midr = right - (right - left) / 3;

    if (nums[midl] == target)
    {
      return midl;
    }
    else if (nums[midr] == target)
    {
      return midr;
    }

    if (nums[midr] < target)
    {
      left = midr + 1;
    }
    else
    {
      left = midl + 1;
      right = midr - 1;
    }
  }
  return -1;
}
int main()
{
  vector<int> nums = {0, 3, 5, 6, 7, 9, 10, 17, 29};
  int target = 9;
  cout << findTarget(nums, target) << endl;
  cout << ternaryFind(nums, target) << endl;
  return 0;
}