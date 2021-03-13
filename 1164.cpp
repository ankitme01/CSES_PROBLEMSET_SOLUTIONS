
// Problem: Room Allocation
// Contest: CSES - CSES Problem Set
// URL: https://cses.fi/problemset/task/1164
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
 bool cmp(pair<int,pii>&a,pair<int,pii>&b)
 {
 	if(a.si.fi==b.si.fi)
 	return a.si.si<b.si.si;
 	return a.si.fi<b.si.fi;
 }
void solve() {
 int n;
 cin>>n;
 vector<pair<int,pii>>arr;
 rep(i,0,n)
 {
 	int a,b;
 	cin>>a>>b;
 	arr.pb({i,{a,b}});
}
sort(all(arr),cmp);
set<pii>s;

vector<int>ans(n,0);
int cnt=0;
rep(i,0,n)
{
	if(s.empty())
	{
		s.insert({arr[i].si.si,1});
		ans[arr[i].fi]=1;
		cnt++;
		continue;
	}
 auto x=s.lower_bound({arr[i].si.fi,0});
 //deb2(x->fi,x->si);
 if(x==s.begin())
 {
 	//cout<<"yes"<<endl;
  cnt++;
  s.insert({arr[i].si.si,cnt});
  ans[arr[i].fi]=(cnt);  
 }
else
{
	x--;
	s.erase(x);
  s.insert({arr[i].si.si,x->si});
  ans[arr[i].fi]=(x->si);	
}	
}
cout<<cnt<<endl;
for(int i:ans)
cout<<i<<" ";
cout<<endl;
}
 
int32_t main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    srand(chrono::high_resolution_clock::now().time_since_epoch().count());
 
   int t = 1;
   // cin >> t;
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