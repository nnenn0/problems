#include <bits/stdc++.h>

using namespace std;
#define rep(i,a,b) for(int i = a; i < b; i++)
#define rrep(i,a,b) for(int i = a; i >= b; i--)
#define fore(i,a) for(auto& i : a)
#define sz(x) (int)(x).size()
using ll = long long;
using pint = pair<int, int>;
using pll = pair<long long, long long>;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
const int IINF = INT_MAX;
const long long LINF = 1LL << 60;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

// https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1611&lang=jp

int N;
vector<int> W;
vector<vector<int>> dp;

int rec(int l = 0, int r = N) {
    if (dp[l][r] != -1) return dp[l][r];
    if (r - l <= 1) return 0;
    if (r - l == 2) {
        if (abs(W[l] - W[l+1]) <= 1) return 2;
        else return 0;
    }
    if (abs(W[l] - W[r-1]) <= 1 && rec(l + 1, r - 1) == r - l - 2) chmax(dp[l][r], r - l);
    else for (int i = l + 1; i <= r - 1; ++i) chmax(dp[l][r], rec(l, i) + rec(i, r));
    return dp[l][r];
}

int main() {
    vector<int> res;
    while(1) {
        cin >> N;
        if (N == 0) break;
        W.resize(N);
        rep(i, 0, N) cin >> W[i];
        dp.assign(N+1, vector<int>(N+1, -1));
        res.push_back(rec());
    }
    fore(r, res) cout << r << endl;
    return 0;
}