//Optimise
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
#define f first
#define s second
#define pb push_back
#define mp make_pair
const long long mod = 1000000007;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin.exceptions(cin.failbit);
    ll i,n, a, b;
    cin >> n >> a >> b;
    vector<ll> Vect(n,0);
    for(i=0;i<a;i++)
        Vect[i]++;
    for(ll j = 0;j<b;j++)
        Vect[(j+a)%n]++;
    ll ans = 0;
    for(ll i =0;i<n;i++)
        ans += (Vect[i]==2);
    cout << min(a,b) << ' ' << ans;
    return 0;
}