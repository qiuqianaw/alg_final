/*
 * @Descripttion: algFinal
 * @version: 1.0
 * @Author: qiuqian 19001020502邱谦
 * @LastEditors: qiquian
 */
#include <bits/stdc++.h>
using namespace std;
/**
 * 4. 回溯法和分支限界题目
 *  (1) 设计一个算法求解简单装载问题。
 *      设有一批集装箱要装上一艘载重量为 W 的轮船，其中编号为 i(0≤i≤n-1)的集装箱的重量为 wi。
 *      现要 从 n 个集装箱中选出若干个装上轮船，使它们的重量之和正好为 W。
 *      如果找到任一种解，返回 true，否则返回 false。
 */

vector<int> sortArray(vector<int> &nums);
int partation(vector<int> &arr, int left, int right);
void quickSort(vector<int> &arr, int left, int right);

/**
 * @brief 
 * 快速排序：数组中随机选择基准点，遍历剩余数组，将所有比基准点小的元素放在其左边，所有比基准点大的元素放在其右边。
 * 一次遍历后，该基准点就位于已经排序完成时它应该处于的位置。
 * 循环这个操作，直到所有元素排序完成。
 * @param nums 
 * @return vector<int> 
 */
vector<int> sortArray(vector<int> &nums)
{
  quickSort(nums, 0, nums.size() - 1);
  return nums;
}
int partation(vector<int> &arr, int left, int right)
{
  int random = left + rand() % (right - left + 1);
  swap(arr[random], arr[left]);
  int pivot = arr[left];
  while (left < right)
  {
    while (left < right && arr[right] >= pivot)
    {
      right--;
    }
    arr[left] = arr[right];
    while (left < right && arr[left] <= pivot)
    {
      left++;
    }
    arr[right] = arr[left];
  }
  arr[left] = pivot;
  return left;
}
void quickSort(vector<int> &arr, int left, int right)
{
  if (arr.size() < 2 || left >= right)
    return;
  // 主要增加的细节处理在下面这部分的函数中
  int p = partation(arr, left, right);
  quickSort(arr, left, p - 1);
  quickSort(arr, p + 1, right);
}

vector<vector<int>> result;
vector<int> path;
int getSum(vector<int> nums)
{
  int sum = 0;
  for (int i = 0; i < nums.size(); i++)
  {
    sum += nums[i];
  }
  return sum;
}

void backtrack(vector<int> &w, int W, int start, vector<bool> &isUsed)
{
  if (getSum(path) == W)
  {
    result.push_back(path);
    return;
  }

  for (int i = start; i < w.size(); i++)
  {
    if (i > 0 && isUsed[i - 1] == false && w[i] == w[i - 1])
    {
      continue;
    }
    path.push_back(w[i]);
    isUsed[i] = true;
    backtrack(w, W, i + 1, isUsed);
    isUsed[i] = false;
    path.pop_back();
  }
}

void print()
{
  for (auto a : result)
  {
    for (auto c : a)
    {
      cout << c << " ";
    }
    cout << endl;
  }
  if (result.size() < 1)
  {
    cout << "false" << endl;
  }
  else
  {
    cout << "true" << endl;
  }
}

int main()
{
  vector<int> w = {15, 5, 20, 10, 35, 25, 40};
  vector<bool> isUsed(w.size() + 1, false);
  // sort(w.begin(), w.end());
  w = sortArray(w);
  int W = 45;
  backtrack(w, W, 0, isUsed);
  print();
  return 0;
}