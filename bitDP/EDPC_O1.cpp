#include <bits/stdc++.h>
#include <atcoder/all>

using namespace atcoder;
using namespace std;
#define rep(i,a,b) for(int i = a; i < b; i++)
#define rrep(i,a,b) for(int i = a; i >= b; i--)
#define fore(i,a) for(auto& i : a)
#define sz(x) (int)(x).size()
#define all(x) (x).begin(),(x).end()
using ll = long long;
using pint = pair<int, int>;
using pll = pair<long long, long long>;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
const int IINF = 1000100100;
const long long LINF = 1LL << 60;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

// https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_2_A&lang=ja

int V, E;
int G[20][20];
int dp[50000][20];

int rec(int S, int v) {
    if (S == 0) {
        if (v == 0) {
            return 0;
        } else {
            return IINF;
        }
    }
    if ((S & (1 << v)) == 0) {
        return IINF;
    }

    int& ret = dp[S][v];
    if (ret) return ret;

    ret = IINF;
    rep(u, 0, V) { chmin(ret, rec(S ^ (1 << v), u) + G[u][v]); };
    return ret;
}

int main() {
    cin >> V >> E;
    rep(i, 0, 20) rep(j, 0, 20) G[i][j] = IINF;
    rep(i, 0, E) {
        int s, t, d; cin >> s >> t >> d;
        G[s][t] = d;
    }

    int res = rec((1<<V) - 1, 0);

    if (res != IINF) cout << res << endl;
    else cout << -1 << endl;

    return 0;
}