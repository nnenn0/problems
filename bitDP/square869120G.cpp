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

// https://atcoder.jp/contests/s8pc-1/tasks/s8pc_1_g

struct Edge {
    ll d;
    ll time;
};
Edge G[16][16];

ll N, M;
pair<ll, ll> dp[1<<16][16];

pair<ll, ll> rec(ll S, ll v) {
    if (S == 0) {
        if (v == 0) return make_pair(0, 1);
        else make_pair(LINF, 0);
    }

    if ((S & (1<<v)) == 0) return make_pair(LINF, 0);

    auto& ret = dp[S][v];
    if (ret.first) return ret;

    ret = make_pair(LINF, 0);
    rep(u, 0, N) {
        auto p = rec(S ^ (1<<v), u);
        p.first += G[u][v].d;
        if (p.first <= G[u][v].time) {
            if (ret.first > p.first) ret = p;
            else if (ret.first == p.first) ret.second += p.second;
        }
    }
    return ret;
}

int main() {
    cin >> N >> M;
    rep(i, 0, 16) rep(j, 0, 16) {
        G[i][j].d = LINF;
        G[i][j].time = 0;
    }
    rep(i, 0, M) {
        ll s, t, d, time; cin >> s >> t >> d >> time;
        --s, --t;
        G[s][t].d = d;
        G[s][t].time = time;
        G[t][s].d = d;
        G[t][s].time = time;
    }

    pair<ll, ll> res = rec((1<<N)-1, 0);

    if (res.first != LINF) cout << res.first << " " << res.second << endl;
    else cout << "IMPOSSIBLE" << endl;

    return 0;
}