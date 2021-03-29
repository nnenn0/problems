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

int dp[3100][3100];

int main() {
    string s, t; cin >> s >> t;
    rep(i, 0, sz(s)) rep(j, 0, sz(t)) {
        if (s[i] == t[j]) chmax(dp[i+1][j+1], dp[i][j] + 1);
        chmax(dp[i+1][j+1], dp[i+1][j]);
        chmax(dp[i+1][j+1], dp[i][j+1]);
    }

    string res;
    int i = sz(s), j = sz(t);
    while (i > 0 && j > 0) {
        if (dp[i][j] == dp[i-1][j]) --i;
        else if (dp[i][j] == dp[i][j-1]) --j;
        else {
            res = s[i-1] + res;
            --i; --j;
        }
    }
    cout << res << endl;
    return 0;
}