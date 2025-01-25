#include<bits/stdc++.h>
//***********UNCOMMENT BEFORE SUBMITTING IF REQUIRED************** */
//#define ONLINE_JUDGE
//***********UNCOMMENT BEFORE SUBMITTING IF REQUIRED************** */
#ifndef ONLINE_JUDGE
#include "debug_template.cpp"
#else
#define debug(...)
#define debugArr(...)
#endif
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
typedef vector<vector<int>> VVI;
typedef pair<ll,ll> PLL;
const ll mod=1000000007;
const ll INF=1000000007;
ll powmod(ll a,ll b) {ll res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
void printV(VI&v) {REP(i,v.size())cout<<v[i]<<' ';cout<<'\n';};
void printV(VL&v) {REP(i,v.size())cout<<v[i]<<' ';cout<<'\n';};
template <typename T>
T loci(const vector<T>& arr, int index, T defaultValue = T()) {
    if (index >= 0 && index < arr.size()) {
        return arr[index];
    }
    return defaultValue;
}
//Your magic 	
int solve(){
    
    return 0;
}
void tests() {int t; cin>>t;while(t--){cout<<solve()<<'\n';}}
//void tests() {int t; cin>>t;while(t--){solve();}}

int main(){tests(); return 0;}
//int main(){cout<<solve()<<'\n'; return 0;}
//int main(){solve(); return 0;}
