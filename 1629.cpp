
// Problem: Movie Festival
// Contest: CSES - CSES Problem Set
// URL: https://cses.fi/problemset/task/1629
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
 bool cmp(pii&a,pii&b)
 {
 	if(a.si==b.si)
 	{
 		return a.fi<b.fi;
 	}
 	return a.si<b.si;
 }
void solve() {
 int n;cin>>n;
 vii arr(n);
 rep(i,0,n)
 {
 	int x,y;
 	cin>>x>>y;
 	arr[i]={x,y};
 }
 sort(all(arr),cmp);
 int cnt=1;
 int pre=arr[0].si;
 rep(i,1,n)
 {
 	if(arr[i].fi>=pre)
 	{
 		cnt++;
 		pre=arr[i].si;
 	}
 }
 cout<<cnt<<endl;
}
 
int32_t main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    srand(chrono::high_resolution_clock::now().time_since_epoch().count());
 
   int t = 1;
    //cin >> t;
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