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

// [i][j][k]: j/iでkになる
ll dp[55][55][2600];

int main() {
    int N, A; cin >> N >> A;
    vector<int> x(N);
    rep(i, 0, N) cin >> x[i];
    dp[0][0][0] = 1;
    rep(i, 0, N) rep(j, 0, N) rep(k, 0, A*N) {
        if (dp[i][j][k] == 0) continue;
        dp[i+1][j][k] += dp[i][j][k];
        dp[i+1][j+1][k+x[i]] += dp[i][j][k];
    }
    ll res = 0;
    rep(k, 1, N+1) res += dp[N][k][k*A];
    cout << res << endl;
    return 0;
}