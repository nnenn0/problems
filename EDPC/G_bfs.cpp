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

int N, M;
using Graph = vector<vector<int>>;
Graph G;
vector<int> deg;
int dp[100100];

int main() {
    cout << setprecision(15) << fixed;
    cin >> N >> M;
    G.assign(N, vector<int>());
    deg.assign(N, 0);
    rep(i, 0, M) {
        int x, y; cin >> x >> y;
        --x; --y;
        G[x].push_back(y);
        deg[y]++;
    }

    queue<int> que;
    rep(v, 0, N) if (deg[v] == 0) que.push(v);

    while (sz(que)) {
        auto v = que.front(); que.pop();
        fore(nv, G[v]) {
            deg[nv]--;
            if (deg[nv] == 0) {
                que.push(nv);
                chmax(dp[nv], dp[v]+1);
            }
        }
    }
    int res = 0;
    rep(v, 0, N) chmax(res, dp[v]);
    cout << res << endl;
    return 0;
}