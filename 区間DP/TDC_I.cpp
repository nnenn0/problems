#include <bits/stdc++.h>
#include <atcoder/all>

using namespace atcoder;
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

// https://atcoder.jp/contests/tdpc/tasks/tdpc_iwi

int L;
string S;
vector<vector<int>> dp;

int rec(int l = 0, int r = L) {
    if (dp[l][r] != -1) return dp[l][r];
    if (r - l < 3) return 0;
    rep(m, l+1, r) {
        chmax(dp[l][r], rec(l, m) + rec(m, r));
        if (S[l] == 'i' && S[m] == 'w' && S[r-1] == 'i') {
            if (rec(l+1, m) == m - l - 1 && rec(m+1, r-1) == r - m - 2) dp[l][r] = r - l;
        }
    }
    return dp[l][r];
}

int main() {
    cin >> S;
    L = sz(S);
    dp.resize(L+1, vector<int>(L+1, -1));
    cout << rec()/3 << endl;
    return 0;
}