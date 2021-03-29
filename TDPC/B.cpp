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
    int A, B; cin >> A >> B;
    vector<int> a(A), b(B);
    rep(i, 0, A) cin >> a[i];
    rep(i, 0, B) cin >> b[i];
    // dp[i][j]: Aからi, Bからj取った状態から最後までの先攻の最適スコア
    vector<vector<int>> dp(A+1, vector<int>(B+1));
    dp[A][B] = 0;
    rrep(i, A, 0) {
        rrep(j, B, 0) {
            if (i == A && j == B) continue;
            
            if ((i+j) % 2 == 0) {
                // 先攻
                if (A == i) dp[i][j] = b[j] + dp[i][j+1];
                else if (B == j) dp[i][j] = a[i] + dp[i+1][j];
                else dp[i][j] = max(a[i] + dp[i+1][j], b[j] + dp[i][j+1]);
            } else {
                // 後攻
                if (i == A) dp[i][j] = dp[i][j+1];
                else if (j == B) dp[i][j] = dp[i+1][j];
                else dp[i][j] = min(dp[i+1][j], dp[i][j+1]);
            }
        }
    }
    cout << dp[0][0] << endl;
    return 0;
}