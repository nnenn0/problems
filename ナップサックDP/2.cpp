#include <bits/stdc++.h>

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

// https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_1_B&lang=jp

int main() {
    int N, W; cin >> N >> W;
    vector<int> value(N), weight(N);
    rep(i, 0, N) cin >> value[i] >> weight[i];
    vector<vector<int>> dp(N+1, vector<int>(W+1, 0));
    rep(i, 0, N) rep(w, 0, W+1) {
        dp[i+1][w] = dp[i][w];
        if (w - weight[i] >= 0) chmax(dp[i+1][w], dp[i][w-weight[i]] + value[i]);
    }
    cout << dp[N][W] << endl;
    return 0;
}