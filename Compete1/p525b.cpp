//Optimise
#pragma comment(linker, "/stack:227420978")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#define fast ios_base::sync_with_stdio(0);cin.tie(0);
//setbase - cout << setbase (16); cout << 100 << endl; Prints 64
//setfill -   cout << setfill ('x') << setw (5); cout << 77 << endl; prints xxx77
//setprecision - cout << setprecision (4) << f << endl; Prints x.xxxx

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define f first
#define s second
#define pb push_back
#define mp make_pair
const long long mod = 1000000007;

int main(){
    fast;
    ll i,n,k,sub,x;
    cin >> n >> k;
    set<ll> Myset;
    for(i=0;i<n;i++){
        cin >> x;
        Myset.insert(x);
    }
    sub = 0;
    while(k--){
        if(Myset.empty()==true) cout << 0 << '\n';
        else{
            cout << *Myset.begin() - sub << '\n';
            sub += *Myset.begin()- sub;
            Myset.erase(Myset.begin());
        }        
    }
    return 0;
}