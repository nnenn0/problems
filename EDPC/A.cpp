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
    int N; cin >> N;
    vector<int> h(N);
    rep(i, 0, N) cin >> h[i];
    vector<int> dp(N+1, IINF);
    dp[0] = 0;
    for (int i = 0; i < N-1; ++i) {
        chmin(dp[i+1], dp[i] + abs(h[i+1] - h[i]));
        if (i+2 <= N-1) chmin(dp[i+2], dp[i] + abs(h[i+2] - h[i]));
    }
    cout << dp[N-1] << endl;
    return 0;
}