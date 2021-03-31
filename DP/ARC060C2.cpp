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

ll dp[55][5000];
const int GETA = 2500;

int main() {
    int N, A; cin >> N >> A;
    vector<int> x(N);
    rep(i, 0, N) {
        cin >> x[i];
        x[i] -= A;
    }
    dp[0][GETA] = 1;
    rep(i, 0, N) for (int s = 0; s+x[i] < 5000; ++s)  {
        if (dp[i][s] == 0) continue;
        dp[i+1][s] += dp[i][s];
        dp[i+1][s+x[i]] += dp[i][s];
    }
    cout << dp[N][GETA] - 1 << endl;
    return 0;
}