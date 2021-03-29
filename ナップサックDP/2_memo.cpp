#include <bits/stdc++.h>

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

int N, W;
vector<int> value, weight;
const int MAX_V = 110, MAX_W = 10010;
int memo[MAX_V][MAX_W];

int knap(int i, int w) {
    if (memo[i][w] != -1) return memo[i][w];
    if (i == N) return memo[i][w] = 0;
    else if (w - weight[i] >= 0) return memo[i][w] = max(knap(i+1, w), knap(i+1, w-weight[i]) + value[i]);
    else return memo[i][w] = knap(i+1, w);
}

int main() {
    cin >> N >> W;
    value.resize(N);
    weight.resize(N);
    rep(i, 0, N) cin >> value[i] >> weight[i];
    rep(i, 0, MAX_V) rep(j, 0, MAX_W) memo[i][j] = -1;
    cout << knap(0, W) << endl;
    return 0;
}