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
 int cnt;
 string ans;
 string s[1000];
 int visited[1000][1000];
 int n,m;
 void dfs(int x,int y,string curr,int c)
 {
 	if(s[x][y]=='B')
 	{
 		if(c<cnt)
 		{
 			cnt=c;
 			ans=curr;
 		}
 		return;
 	}
 visited[x][y]=1;
 if(x+1<n&&visited[x+1][y]==0&&s[x+1][y]!='#')
 {
 	curr.pb('D');
 	dfs(x+1,y,curr,c+1);
curr.pop_back();
 }	
 if(x-1>=0&&visited[x-1][y]==0&&s[x-1][y]!='#')
 {
 	curr.pb('U');
 	dfs(x-1,y,curr,c+1);
 curr.pop_back();
 }	
 if(y+1<m&&visited[x][y+1]==0&&s[x][y+1]!='#')
 {
 	curr.pb('R');
 	dfs(x,y+1,curr,c+1);
 curr.pop_back();
 }	
 if(y-1>=0&&visited[x][y-1]==0&&s[x][y-1]!='#')
 {
 	curr.pb('L');
 	dfs(x,y-1,curr,c+1);
 curr.pop_back();
 }		
 }
void solve() {
 
 cin>>n>>m;
 cnt=INT_MAX;
 rep(i,0,n)
 cin>>s[i];
 int x=-1,y=-1;
 rep(i,0,n)
 rep(j,0,m)
 {
 	if(s[i][j]=='A')
 	{
 		x=i,y=j;
 		break;
 	}
 }
 dfs(x,y,"",0);
 if(cnt==INT_MAX)
 {
 	cout<<"NO"<<endl;
 	
 }
 else
 {
 	cout<<"YES"<<endl;
 	cout<<cnt<<endl;
 	cout<<ans<<endl;
 }
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