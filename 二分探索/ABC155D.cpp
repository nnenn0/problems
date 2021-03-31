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

int main() {
    ll N, K; cin >> N >> K;
    vector<ll> A(N);
    rep(i, 0, N) cin >> A[i];
    sort(all(A));
    ll left = -LINF, right = LINF;
    while (right - left > 1) {
        ll x = (left+right)/2;
        ll S = 0, T = 0;
        rep(i, 0, N) {
            if (A[i] > 0) {
                int l2 = -1, r2 = N;
                while (r2 - l2 > 1) {
                    int m = (l2+r2)/2;
                    if (A[i]*A[m] <= x) l2 = m;
                    else r2 = m;
                }
                S += r2;
            } else if (A[i] < 0) {
                int l2 = -1, r2 = N;
                while (r2 - l2 > 1) {
                    int m = (l2+r2)/2;
                    if (A[i]*A[m] <= x) r2 = m;
                    else l2 = m;
                }
                S += N - r2;
            } else if (x >= 0) S += N;
            if (A[i] * A[i] <= x) ++T;
        }
        ll num = (S - T) / 2;
        if (num >= K) right = x;
        else left = x;
    }
    cout << right << endl;
    return 0;
}