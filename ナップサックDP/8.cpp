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
    string S, T; cin >> S >> T;
    auto n = sz(S), m = sz(T);
    vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
    rep(i, 0, n) rep(j, 0, m) {
        if (S[i] == T[j]) chmax(dp[i+1][j+1], dp[i][j]+1);
        chmax(dp[i+1][j+1], dp[i+1][j]);
        chmax(dp[i+1][j+1], dp[i][j+1]);
    }
    cout << dp[n][m] << endl;
    return 0;
}