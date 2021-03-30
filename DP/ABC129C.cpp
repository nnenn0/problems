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
const int MOD = 1000000007;
int main() {
    int N, M; cin >> N >> M;
    vector<bool> check(100100, false);
    rep(i, 0, M) {
        int a; cin >> a;
        check[a] = true;
    }
    vector<int> dp(N+1, 0);
    dp[0] = 1;
    rep(i, 0, N) {
        if (check[i]) continue;
        (dp[i+1] += dp[i]) %= MOD;
        if (N >= i+2) (dp[i+2] += dp[i]) %= MOD;
    }
    cout << dp[N] << endl;
    return 0;
}