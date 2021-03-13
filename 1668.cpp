
// Problem: Building Teams
// Contest: CSES - CSES Problem Set
// URL: https://cses.fi/problemset/task/1668
// Memory Limit: 512 MB
// Time Limit: 1000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#define ll          long long
#define pb          push_back
#define eb 			emplace_back
#define MP 			make_pair
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
vi adj[100001];
int visited[100001];
unordered_map<int,int>mp;
int dfs(int x,int cnt)
{
	mp[x]=cnt;
	visited[x]=1;
  for(auto i:adj[x])	
	{
		if(visited[i]==1)
		{
			if((mp[i]-mp[x]+1)%2)
			{
				return 0;
			}
		}
		else
		{
			if(dfs(i,cnt+1)==0)
			{
				return 0;
			}
		}
	}
	return 1;
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
 	if(visited[i]==0)
 	{
 		if(dfs(i,1)==0)
 		{
 			cout<<"IMPOSSIBLE"<<endl;
 			return;
 		}
 	}
 }
 
 queue<pii>q;
 mset(visited,0);
rep(i,1,n+1)
 {
 	if(visited[i]==0)
 {
 	q.push({i,1});
 visited[i]=1;
 
 while(!q.empty())
 {
 	pii curr=q.front();
 	q.pop();
 	int x=curr.fi;
 	int y=curr.si;
    for(auto i:adj[x])
    {
    	if(visited[i]==0)
    	{
    		if(y==1){
    		visited[i]=2;
    		q.push({i,2});
    		}
    		else
    		{visited[i]=1;
    		q.push({i,1});
    		}
    	}
    }  	
 }
 }
 }
 rep(i,1,n+1)
 {
 	cout<<visited[i]<<" ";
 }
 cout<<endl;
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