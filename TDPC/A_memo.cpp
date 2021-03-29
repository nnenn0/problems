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

vector<int> p;
vector<vector<int>> memo;

bool rec(int i, int v) {
    if (memo[i][v] != -1) return memo[i][v] == 1;
    
    if (i == 0) return v == 0;

    if (v - p[i-1] < 0) {
        if (rec(i-1, v)) {
            memo[i][v] = 1;
            return true;
        }
        else {
            memo[i][v] = 0;
            return false;
        }
    } else {
        if (rec(i-1, v - p[i-1]) || rec(i-1, v)) {
            memo[i][v] = 1;
            return true;
        }
        else {
            memo[i][v] = 0;
            return false;
        }
    }
}

int main() {
    int N; cin >> N;
    p.resize(N);
    int v_sum = 0;
    rep(i, 0, N) {
        cin >> p[i];
        v_sum += p[i];
    }
    memo.assign(N+1, vector<int>(v_sum+1, -1));
    
    int res = 0;
    rep(i, 0, v_sum+1) if (rec(N, i)) ++res;
    cout << res << endl;
    return 0;
}