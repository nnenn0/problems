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
    int N; cin >> N;
    vector<vector<int>> A(N, vector<int>(3, 0));
    rep(i, 0, N) rep(j, 0, 3) cin >> A[i][j];
    vector<vector<int>> dp(N+1, vector<int>(3, 0));
    rep(i, 0, N) rep(x, 0, 3) rep(y, 0, 3) {
        if (x == y) continue;
        chmax(dp[i+1][x], dp[i][y] + A[i][x]);
    }
    int res = 0;
    rep(i, 0, 3) chmax(res, dp[N][i]);
    cout << res << endl;
    return 0;
}