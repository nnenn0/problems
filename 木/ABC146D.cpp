#include <bits/stdc++.h>
#include <atcoder/all>

using namespace atcoder;
using namespace std;
#define rep(i,a,b) for(int i = a; i < b; i++)
#define rrep(i,a,b) for(int i = a; i >= b; i--)
#define fore(i,a) for(auto& i : a)
#define sz(x) (int)(x).size()
#define all(x) (x).begin(),(x).end()
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
    cout << setprecision(15) << fixed;
    int N; cin >> N;
    using Graph = vector<vector<pint>>;
    Graph G(N);
    rep(i, 0, N-1) {
        int a, b; cin >> a >> b;
        --a, --b;
        G[a].push_back({b, i});
        G[b].push_back({a, i});
    }
    int max_color = 0;
    rep(i, 0, N) chmax(max_color, sz(G[i]));
    vector<int> res(N-1, -1);
    vector<int> dist(N, -1);
    queue<pint> que;
    que.push({0, -1});
    dist[0] = 0;
    while (que.size()) {
        auto [v, v_color] = que.front(); que.pop();
        int nv_color = 1;
        if (v_color == nv_color) ++nv_color;
        for (auto [nv, i] : G[v]) {
            if (dist[nv] != -1) continue;
            dist[nv] = dist[v] + 1;
            res[i] = nv_color;
            que.push({nv, nv_color});
            ++nv_color;
            if (v_color == nv_color) ++nv_color;
        }
    }
    cout << max_color << endl;
    fore(color, res) cout << color << endl;
    return 0;
}