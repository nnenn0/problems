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

template <typename T>
struct BIT {
    int n;
    std::vector<T> bit[2]; 
    BIT(int n_) { init(n_); }
    void init(int n_) {
        n = n_ + 1;
        for (int p = 0; p < 2; p++) bit[p].assign(n, 0);
    }
    void add_sub(int p, int i, T x) {
        for (int idx = i; idx < n; idx += (idx & -idx)) {
            bit[p][idx] += x;
        }
    }
    void add(int l, int r, T x) {  // [l,r) に加算
        add_sub(0, l, -x * (l - 1));
        add_sub(0, r, x * (r - 1));
        add_sub(1, l, x);
        add_sub(1, r, -x);
    }
    T sum_sub(int p, int i) {
        T s(0);
        for (int idx = i; idx > 0; idx -= (idx & -idx)) {
            s += bit[p][idx];
        }
        return s;
    }
    T sum(int i) { return sum_sub(0, i) + sum_sub(1, i) * i; }
    T query(int l, int r) { return sum(r - 1) - sum(l - 1); }
    int lower_bound(T w) {
        if (w <= 0) {
            return 0;
        } else {
            int x = 0, r = 1;
            while (r < n) r = r << 1;
            for (int len = r; len > 0; len = len >> 1) {
                if (x + len < n && bit[x + len] < w) {
                    w -= bit[x + len];
                    x += len;
                }
            }
            return x + 1;
        }
    }
};


int main() {
    int N; cin >> N;
    vector<int> A(N);
    rep(i, 0, N) {
        cin >> A[i];
        A[i]++;
    }
    BIT<int> bit(N);
    ll res = 0;
    rep(i, 0, N) {
        res += i - bit.sum(A[i]);
        bit.add(A[i], A[i]+1, 1);
    }
    rep(i, 0, N) {
        cout << res << endl;
        res -= A[i]-1;
        res += N - 1 - (A[i]-1);
    }
    return 0;
}