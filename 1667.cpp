
// Problem: Message Route
// Contest: CSES - CSES Problem Set
// URL: https://cses.fi/problemset/task/1667
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
 int P[100001];

vector<int>adj[100001];
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
 queue<pii>q;
 q.push({1,1});
 P[1]=1;
 int ans=-1;
 while(!q.empty())
 {
 	pii curr=q.front();
 	q.pop();
 	int cnt=curr.si;
 	int x=curr.fi;
 	if(x==n)
 	{
 		ans=cnt;
 		break;
 	}
 	for(int i:adj[x])
 	{
 		if(P[i]==0)
 		{
 			q.push({i,cnt+1});
 			P[i]=x;
 		}
 	}
 }

 //cout<<endl;
 if(ans==-1)
 {
 	cout<<"IMPOSSIBLE"<<endl;
 }
 else
 {
 	cout<<ans<<endl;
 	int i=n;
 	vi temp;
 	while(P[i]!=i)
 	{
 		temp.pb(i);
         i=P[i];
 	}
 	cout<<1<<" ";
 	for(int i=sz(temp)-1;i>=0;i--)
 	{
 		cout<<temp[i]<<" ";
 	}
 }
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