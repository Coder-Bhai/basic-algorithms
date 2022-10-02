#include <bits/stdc++.h>
using namespace std;
int max(int a, int b){
    return (a>b)?a:b;
}
int knapSack(int w, int wt[], int val[], int n)
{
  vector<vector<int>> k(n+1, vector<int>(w+1));
  for (int i = 0; i <= n; i++)
  {
    for (int j = 0; j <= w; j++)
    {
      if(i==0 || j==0)
      {
        k[i][j]=0;
      }
      else if(wt[i-1]<=j)
      {
        k[i][j] = max(val[i-1]+k[i-1][j-wt[i-1]], k[i-1][j]);
      } else{
        k[i][j] = k[i-1][j];
      }
    }
  }
  return k[n][w];
}
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int val[] = { 60, 100, 120 };
    int wt[] = { 10, 20, 30 };
    int W = 50;
    int n = sizeof(val) / sizeof(val[0]);
     
    cout << knapSack(W, wt, val, n);
  

  return 0;
}