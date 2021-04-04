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

template <class T>
struct Edge {
    int rev, from, to;
    T cap, original_cap;
    Edge(int r, int f, int t, T c) : rev(r), from(f), to(t), cap(c), original_cap(c) {}
};
template <class T>
struct Graph {
    vector<vector<Edge<T>>> G;
    Graph(int n = 0) : G(n) {}
    vector<Edge<T>>& operator[](int i) { return G[i]; }
    const size_t size() const { return G.size(); }
    Edge<T>& redge(Edge<T> e) {
        return G[e.to][e.rev];
    }
    void add_edge(int from, int to, T cap) {
        G[from].push_back(Edge<T>((int)G[to].size(), from, to, cap));
        G[to].push_back(Edge<T>((int)G[from].size() - 1, to, from, 0));
    }
};

template <class T>
struct FordFulkerson {
    const T INF = 1e9;
    vector<int> used;
    FordFulkerson(){};
    T dfs(Graph<T>& G, int v, int t, T f) {
        if (v == t) return f;
        used[v] = true;
        for (auto& e : G[v]) {
            if (!used[e.to] && e.cap > 0) {
                T d = dfs(G, e.to, t, min(f, e.cap));
                if (d > 0) {
                    e.cap -= d;
                    G.redge(e).cap += d;
                    return d;
                }
            }
        }
        return 0;
    }
    T max_flow(Graph<T>& G, int s, int t) {
        T flow = 0;
        while (true) {
            used.assign(G.size(), 0);
            T f = dfs(G, s, t, INF);
            if (f == 0) {
                return flow;
            } else {
                flow += f;
            }
        }
        return 0;
    }
};

int N, M, Q, W[50], V[50], X[50];
int L, R;

int solve() {
    mcf_graph<int, ll> mcf(N+M+2);
    int st = N+M;
    int gl = st+1;
    int MAX = 1010101;

    rep(i, 0, N) mcf.add_edge(st, i, 1, 0);
    rep(i, 0, N) rep(j, 0, M) {
        if (L-1 <= j && j <= R-1) continue;
        mcf.add_edge(i, N+j, (W[i] <= X[j]), MAX - V[i]);
    }
    rep(j, 0, M) mcf.add_edge(N+j, gl, 1, 0);

    auto [flow, cost] = mcf.flow(st, gl);
    return 1LL * MAX * flow - cost;
}

int main() {
    cin >> N >> M >> Q;
    rep(i, 0, N) cin >> W[i] >> V[i];
    rep(i, 0, M) cin >> X[i];
    rep(i, 0, Q) {
        cin >> L >> R;
        cout << solve() << endl;
    }
    return 0;
}