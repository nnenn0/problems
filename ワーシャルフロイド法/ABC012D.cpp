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

void warshall_floyd(vector<vector<int>>& dist) {
    size_t V = dist.size();
    for (int k = 0; k < V; ++k) {
        for (int i = 0; i < V; ++i) {
            for (int j = 0; j < V; ++j) {
                if (dist[i][k] != IINF && dist[k][j] != IINF) {
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
    }
}

int main() {
    cout << setprecision(15) << fixed;
    int N, M; cin >> N >> M;
    vector<vector<int>> cost(N, vector<int>(N, IINF));
    for (int i = 0; i < N; ++i) cost[i][i] = 0;
    rep(i, 0, M) {
        int a, b, t; cin >> a >> b >> t;
        --a, --b;
        cost[a][b] = t;
        cost[b][a] = t;
    }
    warshall_floyd(cost);
    int res = IINF;
    rep(i, 0, N) {
        int tmp = 0;
        rep(j, 0, N) {
            if (i == j) continue;
            tmp = max(tmp, cost[i][j]);
        }
        res = min(res, tmp);
    }
    cout << res << endl;
    return 0;
}