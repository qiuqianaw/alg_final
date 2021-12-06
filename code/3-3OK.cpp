/*
 * @Descripttion: algFinal
 * @version: 1.0
 * @Author: qiuqian 19001020502邱谦
 * @LastEditors: qiquian
 */
#include <bits/stdc++.h>
using namespace std;
/**
 * 3. 贪心法题目
 *  (3) 求解会议安排问题。有一组会议 A 和一组会议室 B，A[i]表示第 i 个会议的参加人数，B[j]表示第 j 个会议室最多可以容纳的人数。
 *      当且仅 当 A[i]≤B[j]时，第 j 个会议室可以用于举办第 i 个会议。
 *      给定数组 A 和数 组 B，最多可以同时举办多少个会议。
 *      例如，A[ ]={1,2,3}，B[ ]={3,2,4}， 结果为 3;
 *      若 A[ ]={3,4,3,1}，B[ ]={1,2,2,6}，结果为 2。
 */

int arrange(vector<int> A, vector<int> B)
{
  sort(A.begin(), A.end());
  sort(B.begin(), B.end());
  int sum = 0;
  int j = B.size() - 1;

  // 双指针技巧
  for (int i = A.size() - 1; i >= 0; i--)
  {
    if (A[i] <= B[j] && j >= 0)
    {
      sum++;
      j--;
    }
  }
  return sum;
}

int main()
{
  vector<int> A = {1, 2, 3};
  vector<int> B = {3, 2, 4};
  cout << arrange(A, B) << endl;
  return 0;
}