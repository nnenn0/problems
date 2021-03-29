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

int dp[110][10010];

int main() {
    int N, K; cin >> N >> K;
    vector<int> a(N), m(N);
    rep(i, 0, N) cin >> a[i];
    rep(i, 0, N) cin >> m[i];
    rep(i, 0, 110) rep(j, 0, 10010) dp[i][j] = -1;
    dp[0][0] = 0;
    rep(i, 0, N) rep(j, 0, K+1) {
        if (dp[i][j] >= 0) dp[i+1][j] = m[i];
        else if (j < a[i] || dp[i+1][j-a[i]] > 0) dp[i+1][j] = dp[i+1][j-a[i]] - 1;
        else dp[i+1][j] = -1;
    }
    if (dp[N][K] >= 0) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}