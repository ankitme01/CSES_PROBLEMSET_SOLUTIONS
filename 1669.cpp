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
 //gcd(x,y)=gcd(x-y,y)
 //gcd(x,y,z...)=gcd(x,y-x,z-x,...)
 vi P(100001,0);
 vi adj[100001];
 unordered_map<int,int>cnt;
 int dfs(int curr,int x)
 {
 	cnt[curr]=x;
    for(auto i:adj[curr])	
 	{
 		if(P[i]!=0)
 		{
 			if(cnt[curr]-cnt[i]>=2)
 			{
 				cout<<cnt[curr]-cnt[i]+2<<endl;
 				vi ans;
 				int p=curr;
 				while(P[p]!=i)
 				{
 					ans.pb(p);
 					p=P[p];
 				}
 				ans.pb(p);
 				cout<<i<<" ";
 				for(int j=ans.size()-1;j>=0;j--)
 				{
 					cout<<ans[j]<<" ";
 				}
 				cout<<i<<endl;
 				return 1;
 			}
 		}
 		else
 		{
 			P[i]=curr;
 			if(dfs(i,x+1))
 			{
 				return 1;
 			}
 		}
 	}
 	return 0;
 }
void solve() {
 int n,m;
 cin>>n>>m;
 rep(i,0,m)
 {
 	int x,y;
 	cin>>x>>y;
 	adj[x].pb(y);
 	adj[y].pb(x);
 }
 rep(i,1,n+1)
 {
 	if(P[i]==0)
 	{
 		P[i]=i;
 		if(dfs(i,1))
 		{
 			return;
 		}
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