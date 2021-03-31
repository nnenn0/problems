#include <bits/stdc++.h>
#include <atcoder/all>

using namespace atcoder;
using namespace std;
#define rep(i,a,b) for(int i = a; i < b; i++)
#define rrep(i,a,b) for(int i = a; i >= b; i--)
#define fore(i,a) for(auto& i : a)
#define sz(x) (int)(x).size()
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()
using ll = long long;
using pint = pair<int, int>;
using pll = pair<long long, long long>;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
const int IINF = 1000100100;
const long long LINF = 1LL << 60;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int main() {
    string S; cin >> S;
    auto n = sz(S);
    vector<ll> val(2019, 0);
    ll fac = 1;
    ll cur = 0;
    val[cur]++;
    rep(i, 0, n) {
        ll add = S[n-1-i] - '0';
        cur = (cur + fac * add) % 2019;
        fac = (fac * 10) % 2019;
        val[cur]++;
    }
    ll res = 0;
    rep(i, 0, sz(val)) res += val[i] * (val[i] - 1) / 2;
    cout << res << endl;
    return 0;
}