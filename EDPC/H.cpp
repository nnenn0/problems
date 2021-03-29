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
int H, W;
vector<string> a;

int dp[1100][1100];

void add(int& a, int b) {
    a += b;
    if (a >= MOD) a -= MOD;
}

int main() {
    cout << setprecision(15) << fixed;
    cin >> H >> W;
    a.resize(H);
    rep(i, 0, H) cin >> a[i];

    dp[0][0] = 1;

    rep(i, 0, H) rep(j, 0, W) {
        if (i+1 < H && a[i+1][j] == '.') add(dp[i+1][j], dp[i][j]);
        if (j+1 < W && a[i][j+1] == '.') add(dp[i][j+1], dp[i][j]);
    }
    cout << dp[H-1][W-1] << endl;
    return 0;
}