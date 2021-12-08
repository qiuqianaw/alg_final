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
 *  (4) 采用优先队列式分支限界法求解最优装载问题。
 *      给出以下装载问题 的求解过程和结果:n=5，集装箱重量为 w=(5,2,6,4,3)，限重为 W=10。
 *      在装载重量相同时最优装载方案是集装箱个数最少的方案。
 */

#define MAXN 21 //最多的集装箱数

//问题表示
int n = 5;
int W = 10;
int w[] = {0, 5, 2, 6, 4, 3}; //集装箱重量,不计下标0的元素

//求解结果表示
int bestw = 0;           //存放最大重量,全局变量
vector<int> bestx(MAXN); //存放最优解,全局变量
int Count = 1;           //搜索空间中结点数累计,全局变量

struct NodeType
{
  int no;      //结点编号
  int i;       //当前结点在解空间中的层次
  int w;       //当前结点的总重量
  int x[MAXN]; //当前结点包含的解向量
  int ub;      //上界
  bool operator<(const NodeType &t) const
  {
    return (this->ub < t.ub) || (this->ub == t.ub && this->x[0] > t.x[0]); //ub越大越优先,当ub相同时x[0]越小越优先
  }
};

void bound(NodeType &e) //计算分枝结点e的上界
{
  int i = e.i + 1;
  int r = 0; //r为剩余集装箱的重量
  while (i <= n)
  {
    r += w[i];
    i++;
  }
  e.ub = e.w + r;
}

void bfs() //求装载问题的最优解
{
  NodeType e, e1, e2;          //定义3个结点
  priority_queue<NodeType> qu; //定义一个优先队列qu
  e.no = Count++;              //设置结点编号
  e.i = 0;                     //根结点置初值,其层次计为0
  e.w = 0;
  //初始化根结点的解向量
  for (int j = 0; j <= n; j++)
  {
    e.x[j] = 0;
  }
  bound(e);           //求根结点的上界
  qu.push(e);         //根结点进队
  while (!qu.empty()) //队不空循环
  {
    e = qu.top();
    qu.pop();     //出队结点e作为当前结点
    if (e.i == n) //e是一个叶子结点
    {
      if ((e.w > bestw) || (e.w == bestw && e.x[0] < bestx[0])) //比较找最优解
      {
        bestw = e.w; //更新bestw
        for (int j = 0; j <= e.i; j++)
        {
          bestx[j] = e.x[j]; //复制解向量e.x->bestx
        }
      }
    }
    else //e不是叶子结点
    {
      if (e.w + w[e.i + 1] <= W) //检查左孩子结点
      {
        e1.no = Count++; //设置结点编号
        e1.i = e.i + 1;  //建立左孩子结点
        e1.w = e.w + w[e1.i];
        for (int j = 0; j <= e.i; j++)
        {
          e1.x[j] = e.x[j]; //复制解向量e.x->e1.x
        }
        e1.x[e1.i] = 1; //选择集装箱i
        e1.x[0]++;      //装入集装箱数增1
        bound(e1);      //求左孩子结点的上界
        qu.push(e1);    //左孩子结点进队
      }
      e2.no = Count++; //设置结点编号
      e2.i = e.i + 1;  //建立右孩子结点
      e2.w = e.w;
      //复制解向量e.x->e2.x
      for (int j = 0; j <= e.i; j++)
      {
        e2.x[j] = e.x[j];
      }
      e2.x[e2.i] = 0; //不选择集装箱i
      bound(e2);      //求右孩子结点的上界
      //若右孩子结点可行,则进队,否则被剪枝
      if (e2.ub > bestw)
      {
        qu.push(e2);
      }
    }
  }
}

int main()
{
  bfs();
  cout << "解向量：";
  for (int i = 1; i <= n; i++)
  {
    cout << bestx[i] << " ";
  }
  cout << endl;
  cout << "总价值：";
  cout << bestw << endl;
}