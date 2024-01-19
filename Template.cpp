#include<bits/stdc++.h>
#define REP(i,n) for (int i=0;i<n;i++)
#define FOR(i,a,b) for (int i=a;i<=b;i++)
#define pb push_back
#define mp make_pair
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<int> VI;
typedef pair<int,int> PII;
typedef vector<ll> VL;
typedef pair<ll,ll> PLL;
const ll mod=1000000007;
const ll INF=1000000007;
ll powmod(ll a,ll b) {ll res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
void printV(VI&v) {REP(i,v.size())cout<<v[i]<<' ';cout<<'\n';};
void printV(VL&v) {REP(i,v.size())cout<<v[i]<<' ';cout<<'\n';};
//Your magic 
