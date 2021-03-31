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

struct Edge {
    long long to;
    long long cost;
};
using Graph = vector<vector<Edge>>;
using P = pair<long, int>;
constexpr long long INF = 1LL << 60;

void dijkstra(const Graph& G, int s, vector<long long>& dist) {
    size_t N = G.size();
    dist = vector<long long>(N, INF);
    priority_queue<P, vector<P>, greater<P>> pq;
    dist[s] = 0;
    pq.emplace(dist[s], s);
    while (!pq.empty()) {
        P p = pq.top();
        pq.pop();
        int v = p.second;
        if (dist[v] < p.first) {
            continue;
        }
        for (auto& e : G[v]) {
            if (dist[e.to] > dist[v] + e.cost) {
                dist[e.to] = dist[v] + e.cost;
                pq.emplace(dist[e.to], e.to);
            }
        }
    }
}

int main() {
    int N, K; cin >> N >> K;
    Graph G(N);
    vector<ll> dist;
    rep(i, 0, K) {
        int type; cin >> type;
        if (type == 0) {
            int a, b; cin >> a >> b;
            --a, --b;
            dijkstra(G, a, dist);
            if (dist[b] != INF) cout << dist[b] << endl;
            else cout << -1 << endl; 
        } else {
            int c, d, e; cin >> c >> d >> e;
            --c, --d;
            G[c].push_back({d, e});
            G[d].push_back({c, e});
        }
    }
    return 0;
}