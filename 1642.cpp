
// Problem: Sum of Four Values
// Contest: CSES - CSES Problem Set
// URL: https://cses.fi/problemset/task/1642
// Memory Limit: 512 MB
// Time Limit: 1000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#define ll          long long
#define pb          push_back
#define eb 			emplace_back
#define mp 			make_pair
#define pii         pair<ll,ll>
#define vi          vector<int>
#define vii         vector<pii>
#define mi          map<ll,ll>
#define mii         map<pii,ll>
#define all(a)      (a).begin(),(a).end()
#define fi          first
#define si          second
#define sz(x)       (ll)x.size()
#define endl        "\n"
#define checkbit(n, b) ((n >> b) & 1)
#define mod        1000000007
#define inf        1000000000000000000
#define puts(n)		cout<<n;
#define um           unordered_map<ll,ll>
#define rep(i,a,b)  for(int i=a;i<b;i++)
#define setbits(x) __builtin_popcount(x)
#define mset(m,v) memset(m,v,sizeof(m))
#define int ll 
#define deb(x) cout << #x << "=" << x << endl
#define deb2(x, y) cout << #x << "=" << x << "," << #y << "=" << y << endl
using namespace std;
int power(int base, int exp); 
 
//=======================
 
 // USED UNORDERED_MAP????????
 // INT_MAX and LONG_MAX range???
array<int,2>arr[1000];
void solve() {
	int n,x;
	cin>>n>>x;
 rep(i,0,n)
 {
 	cin>>arr[i][0];
 	arr[i][1]=i+1;
 }
 sort(arr,arr+n);
 int i=0,j=n-1;
 while(i+2<j)
 {
 	
 		int k=i+1,l=j-1;
 	    int sum=x-arr[i][0]-arr[j][0];
 	    while(k<l)
 	    {
 	      int p=arr[k][0]+arr[l][0];
 	      if(p==sum)
 	      {
 	      	cout<<arr[i][1]<<" "<<arr[j][1]<<" "<<arr[k][1]<<" "<<arr[l][1]<<endl;
 	      	return;
 	      }
 	     else if(p>sum)
 	      {
 	      	l--;
 	      }
 	      else
 	      {
 	      	k++;
 	      }	
 	    }
    if(arr[i][0]+arr[j][0]+arr[i+1][0]+arr[j-1][0]>x)
    {
    	j--;
    }
    else
    {
    	i++;
    }	
 }
 cout<<"IMPOSSIBLE"<<endl;
}
 
int32_t main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    srand(chrono::high_resolution_clock::now().time_since_epoch().count());
 
   int t = 1;
  
    while(t--) {
      solve();
    }
 
    return 0;
}
 
int power(int base, int exp) {
  base %= mod;
  int result = 1;
  while (exp > 0) {
    if (exp & 1) result = ((ll)result * base) % mod;
    base = ((ll)base * base) % mod;
    exp >>= 1;
  }
  return result;
}