#include"bits/stdc++.h"
using namespace std;
#define ll long long


void solve()
{
   int n,k;
   cin>>n>>k;
   int arr[n];
   unordered_set<int> st;
   for(int i=0;i<n;i++)
    {
      cin>>arr[i];
      st.insert(arr[i]);
    }
    if(st.size()<k)
    {
      cout<<-1;
      return;
    }
  int i =1;
  while(st.size()<k)
  {
    st.insert(i);
    i++;
  }
  cout<<n*k;
  for(int i=1;i<=n;i++)
  {
    for(auto it = st.begin();it!=st.end();it++) cout<<*it<<" ";
  }





}
int main()
{
     int t;
     cin>>t;
     while(t--)
     {
        solve();
        cout<<endl;
     }





}
