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

int a[10010];
int memo[100][10010];

bool rec(int i, int v) {
    if (memo[i][v] != -1) return memo[i][v];
    if (i == 0) {
        if (v == 0) return memo[i][v] = true;
        else return memo[i][v] = false;
    }
    if (rec(i-1, v-a[i-1])) return memo[i][v] = true;
    if (rec(i-1, v)) return memo[i][v] = true;
    return false;
}

int main() {
    int N, A; cin >> N >> A;
    rep(i, 0, N) cin >> a[i];
    rep(i, 0, 100) rep(j, 0, 10010) memo[i][j] = -1;
    if (rec(N, A)) cout << "YES" << endl;
    else cout << "NO" << endl;
    return 0;
}