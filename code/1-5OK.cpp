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
 *  (5) 循环赛日程安排。
 *      问题描述:假设有 n=2^k 个选手参加循环赛， 请设计满足以下要求的比赛日程表:
 *      每个选手都必须与其他 n-1 个选手 比赛一次;每个选手一天只能参赛一次。
 */

/**
 * 按分治策略，我们可以将所有的选手分为两半，则n个选手的比赛日程表可以通过n/2个选手的比赛日程表来决定。
 * 递归地用这种一分为二的策略对选手进行划分，直到只剩下两个选手时，比赛日程表的制定就变得很简单。
 * 这时只要让这两个选手进行比赛就可以了。
 * 如上图，所列出的正方形表是8个选手的比赛日程表。
 * 其中左上角与左下角的两小块分别为选手1至选手4和选手5至选手8前3天的比赛日程。
 * 据此，将左上角小块中的所有数字按其相对位置抄到右下角，
 * 又将左下角小块中的所有数字按其相对位置抄到右上角，
 * 这样我们就分别安排好了选手1至选手4和选手5至选手8在后4天的比赛日程。
 * 依此思想容易将这个比赛日程表推广到具有任意多个选手的情形。
 */

int a[100][100];
int n; //选手的个数

/*
tox:目标数组的行号 
toy:目标数组的列号 
fromx:源数组的行号 
fromy:源数组的列号 
r:数组的大小为 r*r 
*/

void Copy(int tox, int toy, int fromx, int fromy, int r)
{
  for (int i = 0; i < r; i++)
  {
    for (int j = 0; j < r; j++)
    {
      a[tox + i][toy + j] = a[fromx + i][fromy + j];
    }
  }
}

void Table(int k)
{
  n = 1 << k;
  //构造正方形表格的第一行数据
  for (int i = 0; i < n; i++)
    a[0][i] = i + 1;
  //采用分治算法，构造整个循环赛日程表
  for (int r = 1; r < n; r <<= 1)
  {
    for (int i = 0; i < n; i += 2 * r)
    {
      Copy(r, r + i, 0, i, r); //左上角复制到右下角
      Copy(r, i, 0, r + i, r); //右上角复制到左下角
    }
  }
}

int main()
{
  int k = 3;
  Table(k);
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      cout << a[i][j] << " ";
    }
    cout << endl;
  }
  return 0;
}