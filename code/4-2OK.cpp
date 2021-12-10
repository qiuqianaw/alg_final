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
 *  (2) 设计求解有重复元素的排列问题的算法。
 *      设有 n 个元素, a[ ]={a0,a1,...,an-1}，其中可能含有重复的元素，求这些元素的所有排列。
 *      例如 a[ ]={1,1,2}，输出结果是(1,1,2)、(1,2,1)、(2,1,1)。
 */

//19001020502邱谦
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

// 19001020502邱谦
// 按照回溯框架
vector<vector<int>> result;
vector<int> path;

void backtrack(vector<int> nums, vector<bool> used)
{
  for (int i = 0; i < nums.size(); i++)
  {
    if (path.size() == nums.size())
    {
      result.push_back(path);
      return;
    }
    if (i > 0 && used[i - 1] == false && nums[i] == nums[i - 1])
    {
      continue;
    }
    if (used[i] == false)
    {
      used[i] = true;
      path.push_back(nums[i]);
      backtrack(nums, used);
      path.pop_back();
      used[i] = false;
    }
  }
}

vector<vector<int>> permuteUnique(vector<int> &nums)
{
  vector<bool> used(nums.size() + 1, false);
  // sort(nums.begin(), nums.end());
  nums = sortArray(nums);
  backtrack(nums, used);
  return result;
}

int main()
{
  vector<int> nums = {1, 1, 2};
  vector<vector<int>> result = permuteUnique(nums);
  for (auto res : result)
  {
    for (auto r : res)
    {
      cout << r << " ";
    }
    cout << endl;
  }
  return 0;
}
