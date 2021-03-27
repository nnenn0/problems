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

ll dp[110][100100];

int main() {
    int N, W; cin >> N >> W;
    vector<int> weight(N), value(N);
    rep(i, 0, N) cin >> weight[i] >> value[i];
    rep(i, 0, 110) rep(j, 0, 100100) dp[i][j] = LINF;
    dp[0][0] = 0;
    rep(i, 0, N) rep(j, 0, 100001) {
        chmin(dp[i+1][j], dp[i][j]);
        if (j < value[i]) continue;
        chmin(dp[i+1][j], dp[i][j-value[i]] + weight[i]);
    } 
    int res = 100000;
    while (dp[N][res] > W) res--;
    cout << res << endl;
    return 0;
}