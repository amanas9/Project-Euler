#include"bits/stdc++.h"
using namespace std;
#define ll long long

ll power(int x, int n)
{
  if(n==0)
    return 1;
  else if(n%2==1)
  return  x*power(x,n-1);
  else
  return power(x*x, n/2);

}
void solve()
{
   int n;
   cin>>n;
   if(n==2)
   {
     cout<<2;
     return;
   }
   int arr[n+1];
   for(int i=1;i<=n;i++) arr[i] = power(2,i);
  ll sum1 = arr[n], sum2 = 0;
  for(int i=1;i<n;i++)
  {
    if(i<=n/2-1)
    sum1+= arr[i];
    else
    sum2+= arr[i];
  }
cout<<abs(sum1-sum2);

}
int main()
{
     int t = 1;
     cin>>t;
     while(t--)
     {
        solve();
        cout<<endl;
     }





}
