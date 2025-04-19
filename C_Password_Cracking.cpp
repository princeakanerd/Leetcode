#define _Alignof alignof
#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define gc getchar_unlocked
#define fo(i, n) for (i = 0; i < n; i++)
#define Fo(i, k, n) for (i = k; k < n ? i < n : i > n; k < n ? i += 1 : i -= 1)
#define si(x) scanf("%d", &x)
#define sl(x) scanf("%lld", &x)
#define ss(s) scanf("%s", s)
#define pi(x) printf("%d\n", x)
#define pl(x) printf("%lld\n", x)
#define ps(s) printf("%s\n", s)
#define deb(x) cout << #x << "=" << x << endl
#define deb2(x, y) cout << #x << "=" << x << "," << #y << "=" << y << endl
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define all(x) x.begin(), x.end()
#define clr(x) memset(x, 0, sizeof(x))
#define sortall(x) sort(all(x))
#define tr(it, a) for (auto it = a.begin(); it != a.end(); it++)
#define PI 3.1415926535897932384626
#define MOD 1000000007
typedef pair<int, int> pii;
typedef pair<ll, ll> pl;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pii> vpii;
typedef vector<pl> vpl;
typedef vector<vi> vvi;
typedef vector<vl> vvl;

int ask(string t) {
    cout << "? " << t << endl ;
    int num ; cin>> num; return num ;
}
void tell(string s){
    cout << "! " << s << endl;
}

void solve() {
    ll n ;
    cin >> n;
    string res = "";
    while(true) {
        res.pb('0');
        if(!ask(res)){
            res.pop_back();
            res.pb('1') ;
            if(!ask(res)) {
                res.pop_back();
                break;
            }
        }
        if(res.length() == n){
            tell(res) ; return;
        } 
        
    }

    while(true) {
        res.insert(res.begin() , '0') ;
        if(!ask(res)){
            res.erase(res.begin());
            res.insert(res.begin() , '1') ;
        }
        if(res.length() == n) break ;
        
    }
    

}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc = 1;
    // Uncomment the next line to read multiple test cases.
    cin >> tc;
    for (int t = 1; t <= tc; t++) {
        
        // cout << "Case #" << t << ": ";
        solve();
    }
    return 0;
}