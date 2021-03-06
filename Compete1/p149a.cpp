//Optimise
#pragma comment(linker, "/stack:227420978")
#pragma GCC optimize("Ofast")
//~#pragma GCC optimize("O3")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC optimize("unroll-loops")
#define fast ios_base::sync_with_stdio(0);cin.tie(0);
//setbase - cout << setbase (16); cout << 100 << endl; Prints 64
//setfill -   cout << setfill ('x') << setw (5); cout << 77 << endl; prints xxx77
//setprecision - cout << setprecision (4) << f << endl; Prints x.xxxx

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
#define f first
#define s second
#define pb push_back
#define mp make_pair
const long long mod = 1000000007;

int main(){
    fast;
    ll x,y,a,b;
    cin >> x >> y >> a >> b;
    vector< pair<ll,ll> > Asnwer;
    for(a;a<=x;a++){
        int j = b;
        for(;j<=min(a-1,y);j++)
            Asnwer.pb(mp(a,j));
    }
    cout << Asnwer.size() << '\n';
    for(pair<ll,ll> x : Asnwer)
        cout << x.f << ' ' << x.s << '\n';
    return 0;
}