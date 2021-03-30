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
    string S, X; cin >> S >> X;
    vector<int> a(N);
    rep(i, 0, N) a[i] = (S[i] - '0');
    vector<vector<int>> dp(N+1, vector<int>(7, 0));
    dp[N][0] = 1;
    rrep(i, N-1, 0) {
        rep(k, 0, 7) {
            if (X[i] == 'T') dp[i][k] = dp[i+1][(10*k)%7] | dp[i+1][(10*k+a[i])%7];
            else dp[i][k] = dp[i+1][(10*k)%7] & dp[i+1][(10*k+a[i])%7];
        }
    }
    cout << (dp[0][0] ? "Takahashi" : "Aoki") << endl;
    return 0;
}