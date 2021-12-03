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
 *  (1) 设计一个算法，采用分治法求一个整数序列中的最大和最小元素。
 */

void findMaxMinInArray(vector<int> &nums, int left, int right, int &MAX, int &MIN)
{
  // 当二分到只有一个元素时，这个元素就是最大/最小值
  if (left == right)
  {
    MAX = nums[left];
    MIN = nums[left];
    return;
  }
  else if (left + 1 == right)
  {
    MAX = max(nums[left], nums[right]);
    MIN = min(nums[left], nums[right]);
    return;
  }

  int lmax, lmin, rmax, rmin;
  // mid = left + (right - left) / 2 可避免大数溢出
  int mid = left + (right - left) / 2;
  findMaxMinInArray(nums, left, mid, lmax, lmin);
  findMaxMinInArray(nums, mid + 1, right, rmax, rmin);
  MAX = max(lmax, rmax);
  MIN = min(lmin, rmin);
}

int main()
{
  vector<int> nums = {5, 2, 9, 8, 3, 7, 14, 6, 1, 0, 10};
  int MAX = INT_MIN;
  int MIN = INT_MAX;
  findMaxMinInArray(nums, 0, nums.size() - 1, MAX, MIN);
  cout << "Array: [ ";
  for (auto num : nums)
  {
    cout << num << " ";
  }
  cout << "]" << endl;
  cout << "min number is: " << MIN << endl;
  cout << "max number is: " << MAX << endl;
  return 0;
}