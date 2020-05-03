#include "bits/stdc++.h"
#include "Euler_project_util.h"
using namespace std;
#define ll long long

//vector<bool> prime;

/*bool ispal(int n)
{
  if(n%10==0)
   return false;
  int rev = 0;
  while(n>rev)
  {
    int l = n%10;
    n = n/10;
    rev = rev*10 + l;
  }
  return n==rev||rev/10==n;
}

bool isprime(int n)
{
  int count = 0;
  for(int i=1;i*i<=n;i++)
  {
    if(n%i==0)
    {
      if(i*i==n)
       count++;
       else
       count+= 2;
    }
  }
  return count==2;
}

int hcf(int a, int b)
{
  if(b==0)
    return a;
  return hcf(b, a%b);
}

vector<bool> sieve(int n)
{
  vector<bool>arr(n+1, true);
  arr[0] = arr[1] = false;
  for(int i=2;i*i<=n;i++)
  {
    if(arr[i])
    {
      for(int j=i*i;j<=n;j+=i)
         arr[j] = false;
    }
  }
  return arr;
}

ll chain(ll n)
{
  if(n<1)
    return INT_MIN;
  else if(n==1)
    return 1;
  else if(n%2==0)
    return 1+chain(n/2);
  else
    return 1+chain(3*n+1);
}

ll no_of_ways(int n)
{
  ll dp[n][n];
  for(int i=0;i<n;i++)
    {
      for(int j=0;j<n;j++)
      {
        if(i==0||j==0)
          dp[i][j] = 1;
        else
          dp[i][j] = dp[i-1][j] + dp[i][j-1];
      }
    }
return dp[n-1][n-1];

}

vector<int> mul_by_2(int n)
{
  vector<int>ans(1,1);
  for(int i=0;i<n;i++)
  {
    int carry = 0;
    for(int j=0;j<ans.size();j++)
    {
      int a = (ans[j]*2);
      ans[j] = a%10+carry;
       carry = a/10;
    }
    if(carry)
      ans.push_back(carry);
  }
  return ans;
}

bool isleap(int year)
{
  if(year%100==0)
    {
      if(year%400==0)
        return true;
      else
      return false;
    }
  else if(year%4==0)
   return true;
  return false;
}

void multiply(vector<int> &v, int x)
{
   int carry = 0;
   for(int i=0;i<v.size();i++)
  {
    int prod = v[i]*x + carry;
    v[i] = prod%10;
    carry = prod/10;
  }
  while(carry)
  {
    v.push_back(carry%10);
    carry = carry/10;
  }
}

vector<int> large_factorial(int n)
{
  vector<int> v(1,1);
  for(int i=2;i<=n;i++)
     multiply(v,i);
  return v;
}

ll power(int x, int n)
{
  if(n==0)
    return 1;
  else if(n%2==1)
  return  x*power(x,n-1);
  else
  return power(x*x, n/2);

}

ll cal_d_util(int n)
{
  int self = n;
  unordered_map<int,int> umap;
  for(int i=2;i*i<=n;i++)
  {
    while(n%i==0)
     {
       umap[i]++;
       n = n/i;
     }
  }
  if(n!=1)
    umap[n]++;
  ll sum = 1;
  for(auto it = umap.begin();it!=umap.end();it++)
  {
     int a = it->first;
     int b = it->second;
    int n = power(a,b+1)-1;
    sum*= n/(a-1);
    //cout<<a<<" "<<b<<" "<<n;
  }
  return sum-self;
}

void cal_d(ll am[],int n)
{
    for(int i=1;i<n;i++)
      {
        am[i] = cal_d_util(i);
      }
}

void next_permuation(int arr[], int n)
{
  int i = n-2, j;
  while(i>=0 && arr[i]>=arr[i+1])
  {
    i--;
  }
  if(i<0)
  return;
  j = n-1;
  while(j>=0 && arr[i]>=arr[j]) j--;
  swap(arr[i], arr[j]);
  reverse(arr+i+1, arr+n);


}

string add_two_string(string a , string b)
{
  int n = a.length(), m = b.length();
  string temp;

  int carry = 0;
  while(n>0 || m>0 || carry>0)
  {
    int p = 0 ,q = 0;
    if(n>0)
      {
        p = a[n-1]-'0';
        n--;
      }
    if(m>0)
    {
      q = b[m-1]-'0';
      m--;
    }

   //cout<<"f";
    int sum = p+q+carry;
    temp.push_back((sum%10)+'0');
    carry = sum/10;
  }
  reverse(temp.begin(), temp.end());
  return temp;
}

void fib_qn_euler_proj()
{
  string a = "1", b = "1";
  int k = 1;
  while(a.length()!=1000)
  {
    string temp = add_two_string(a,b);
    a = b;
    b = temp;
    //cout<<temp;
    k++;
  }
  cout<<k;
}

ll cal_recurring(ll n)
{
  ll len = 0;
  unordered_map<ll,ll> umap;
  string a = "";
  for(ll r = 1%n;r;r = r%n)
  {
    //cout<<r<<" ";
     if(umap.find(r)!=umap.end())
     {
       len = a.length()-umap[r];
       break;
     }
     else
     {
       umap[r] = a.length();
       r*= 10;
       a+= (char)('0'+r/n);
     }

  }
 for(int i=0;i<a.length();i++)
 cout<<a[i]<<" ";
  return len;
}

ll ways_of_coin_change(int den[], int n, int N)
{
  ll ways[N+1] = {0};
  ways[0] = 1;

  for(int j=0;j<n;j++)
  {
    for(int i=1;i<=N;i++)
    {
      if(i>=den[j])
        ways[i]+= ways[i-den[j]];
    }
  }
 return ways[N];
}

bool check_pan_digital(ll a, ll b, ll c)
{
  int arr[10] = {0};
  while(a)
  {
    arr[a%10]++;
    a/= 10;
  }
  while(b)
  {
    arr[b%10]++;
    b/= 10;
  }
  while(c)
  {
    arr[c%10]++;
    c/= 10;
  }
  if(arr[0]!=0)
  return false;
  for(int i=1;i<=9;i++)
   {
     if(arr[i]!=1)
     return false;
   }
   return true;
}

string bin(int n)
{
  string res = "";
  while(n)
  {
    int x = n%2;
    n = n/2;
    res = to_string(x) + res;
  }
  return res;
}

bool is_string_pal(string str)
{
  int e = str.length()-1;
  if(str[e]=='0')
   return false;
  int s = 0;
  string temp = str;
  reverse(str.begin(), str.end());
  for(int i=0;i<=e;i++)
  {
    if(str[i]!=temp[i])
      return false;
  }
  return true;
}

ll sum_pan_digital()
{
  ll count = 0, sum = 0;
  unordered_set<int>st;
  for(int a = 1;a<=100;a++)
  {
    for(int b = 1;b<=10000;b++)
    {
      ll prod = (ll)a*b;
      if(((int)log10(prod)+(int)log10(a)+ (int)log10(b)+3==9) && st.find(prod)==st.end())
       {
         if(check_pan_digital(a,b,prod))
           {
             st.insert(prod);
             sum+= prod;

             cout<<a<<" "<<b<<" "<<prod<<"\n";
           }
       }
    }
  }
  return sum;
}

ll fact(int n)
{
  ll res = 1;
  for(int i=1;i<=n;i++) res = res*i;
  return res;
}

bool c_prime(ll n)
{
  if(n==2||n==5||n==7)
   return true;
  int n_dig = 0;
  ll temp = n;
  while(temp)
  {
    int d = temp%10;
    temp = temp/10;
    if(d==5||d==0||d%2==0)
     return false;
    n_dig++;
  }
  ll num = n;
  while(isprime(num))
  {
    int d = num%10;
    int div = num/10;
    num = power(10, n_dig-1)*d + div;
    if(n==num)
       return true;
  }
  return false;

}

ll rev_num(ll n)
{
  ll rev = 0;
  while(n)
  {
    rev = rev*10 + n%10;
    n = n/10;
  }
  return rev;
}

bool isltrunc(int n)
{
  int n_dig = 0;
  int temp = n;
  while(temp)
  {
    n_dig++;
    if(temp%10==0)
      return false;
    temp = temp/10;
  }
  while(n_dig)
  {
    n = n% power(10,n_dig);
    if(prime[n]==false)
      return false;
    n_dig--;
  }
  return true;
}

bool isrtrunc(int n)
{
  int n_dig = 0;
  int temp = n;
  while(temp)
  {
    if(prime[temp]==false)
      return false;
    temp = temp/10;
  }
  return true;
}

bool check_pan_digital_string(string str)
{
  int n = str.length();

  int arr[n+1]= {0};
  for(int i=0;i<=n;i++)  arr[str[i]-'0']++;
  if(arr[0]!=0)
   return false;
  for(int i=1;i<=n;i++)
    {
      if(arr[i]!=1)
        return false;
    }
    return true;
}

ll prob_34()
{
  ll ans = 0;
  for(int i=10;i<=100000;i++)
   {
     int x = i, num = 0;
     while(x)
     {
       num+= fact(x%10);
       x = x/10;
     }
     if(num==i)
       ans+= i;
   }
   return ans;
}

ll prob_35()
{
  ll count = 0;
    for(int i=2;i<100;i++)
    {
      if(c_prime(i))
        count++;
    }
    return count;
}

ll prob_36()
{
  ll sum = 0;
  for(int i=1;i<1000000;i++)
  {
    if(ispal(i) && is_string_pal(bin(i)))
      sum+= i;
  }
  return sum;
}

ll prob_37()
{
  ll sum = 0;
  for(int i=10;i<1000001;i++)
  {
    bool l = isltrunc(i);
    if(l && isrtrunc(i))
      sum+= i;

  }
  return sum;
}

string prob_38()
{
  string res, ans = "0";
  for(int i=1;i<10000;i++)
  {
    //cout<<i<<"\n";
    int n = 1,prod;
     res.clear();
    while(res.length()<=9)
    {
      prod = i*n;
      n++;
      res+= to_string(prod);
      if(res.length()==9)
        {

          if(check_pan_digital_string(res))
            {

              ans = max(ans, res);
              cout<<res<<"\n";
            }
            break;
        }

    }
  }
//  cout<<ans;
  return ans;
}

ll prob_39()
{
  int arr[1001] = {0};
  for(int i=1;i<1000;i++)
  {
    for(int j=i;j<1000;j++)
    {
          if(sqrt(i*i+j*j)-(int)sqrt(i*i+j*j)==0)
           {
             int c = (int)sqrt(i*i+j*j);
             if(i+j+c<=1000)
               arr[i+j+c]++;
           }

    }
  }
 int ans = -1, maxp = 0;
 for(int i=0;i<1001;i++)
 {
   if(arr[i]>maxp)
   {
     ans = i;
     maxp = arr[i];
   }
 }
 return ans;
}

ll prob_40()
{
  string res= "0";
  for(int i=1;i<=1000000;i++) res+= to_string(i);
  cout<<res.length()<<" ";
  int prod = (res[1]-'0')*(res[10]-'0')*(res[100]-'0')*(res[1000]-'0')*(res[10000]-'0')*(res[100000]-'0')*(res[1000000]-'0');
  return prod;
}

ll prob_41()
{
  ll ans = 2;
  for(int i = 1000;i<=9999;i++)
  {
    if(prime[i] && check_pan_digital_string(to_string(i)))
      ans = i;
  }
  string str = "1234567";
  while(next_permutation(str.begin(),str.end()))
  {
    if(isprime(stoi(str))&& check_pan_digital_string(str))
      {
        ans = stoi(str);
      }

  }
  return ans;
}*/

int main(int argc, char const *argv[]) {
prime = sieve(1000001);
ll ans,i,j;
ans = 0;
cout<<prob_41();












}
