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

// https://atcoder.jp/contests/abc130/tasks/abc130_d

int main() {
    ll N, K; cin >> N >> K;
    vector<ll> a(N);
    rep(i, 0, N) cin >> a[i];
    int right = 0;
    ll sum = 0, res = 0;
    rep(left, 0, N) {
        while (sum < K) {
            if (right == N) break;
            else {
                sum += a[right];
                ++right;
            }
        }
        if (sum < K) break;
        res += N-right+1;
        sum -= a[left];
    }
    cout << res << endl;
    return 0;
}