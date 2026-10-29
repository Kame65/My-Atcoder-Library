#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <numeric>
#include <queue>
#include <assert.h>
#include <iomanip>
#include <functional>
#include <string>

using namespace std;
using ll = long long int;
using vl = vector<ll>;
using vvl = vector<vl>;
using vc = vector<char>;
using vvc = vector<vc>;
using vvvl  = vector<vvl>;
using vb = vector<bool>;


template <typename T, typename F>
struct LazySegmentTree {
  ll n;
  T e; // Tの初期値
  F id;// Fの初期値(変更なしの時の値(NULLなど))
  vector<T> tree; //実際のデータvector
  vector<F> lazy; //遅延を記録しているvector
  function<T(T, T)> merge;
  function<T(T, F)> apply;
  function<F(F, F)> compose;

  LazySegmentTree(ll n, T e, F id, function<T(T, T)> merge, function<T(T, F)> apply, function<F(F, F)> compose) 
            : n(bit_ceil((unsigned)n)), e(e), id(id), merge(merge), apply(apply), compose(compose) {
                // メンバに代入, nはn以上の最小の2の冪乗
    tree.assign(2 * this->n, e);
    lazy.assign(2 * this->n, id);
  }

  // vectorの中身をLazySegTreeに入れる
  LazySegmentTree(vector<T> a, T e, F id, function<T(T, T)> merge, function<T(T, F)> apply, function<F(F, F)> compose) 
            : n(bit_ceil(a.size())), e(e), id(id), merge(merge), apply(apply), compose(compose) {
    tree.assign(2 * n, e);
    lazy.assign(2 * n, id);
    for (int i = 0; i < a.size(); i++) tree[n + i] = a[i];
    for (int i = n - 1; i > 0; i--) tree[i] = merge(tree[i << 1 | 0], tree[i << 1 | 1]);
  }

  void apply_lazy(int i) {
    if (i == 0) return;
    if (lazy[i] == id) return;
    if (i < n) {// dataの入った枠より上のそうであれば
      lazy[i << 1 | 0] = compose(lazy[i << 1 | 0], lazy[i]);
      lazy[i << 1 | 1] = compose(lazy[i << 1 | 1], lazy[i]);
    }
    tree[i] = apply(tree[i], lazy[i]);
    lazy[i] = id;
  }

  // [l, r)を更新
  void update(int l, int r, F f) {
    _inner_update(1, 0, n, l, r, f);
  }

  // [l, r)のmerge関数の結果を返すmergeがmaxなら最大値など
  T query(int l, int r) {
    return _inner_query(1, 0, n, l, r);
  }

private:

  void _inner_update(int i, int l, int r, int ql, int qr, F f) {
    apply_lazy(i);
    if (l > qr || r < ql) return;
    if (ql <= l && r <= qr) {
      lazy[i] = f;
      apply_lazy(i);
      return;
    }
    if (i < n) {
      int m = (l + r) >> 1;
      _inner_update(i << 1, l, m, ql, qr, f);
      _inner_update(i << 1 | 1, m, r, ql, qr, f);
      tree[i] = merge(tree[i << 1], tree[i << 1 | 1]);
    }
  }

  T _inner_query(int i, int l, int r, int ql, int qr) {
    apply_lazy(i);
    if (l >= qr || r <= ql) return e;
    if (l >= ql && r <= qr) return tree[i];
    int m = (l + r) >> 1;
    return merge(_inner_query(i << 1, l, m, ql, qr), _inner_query(i << 1 | 1, m, r, ql, qr));
  }
};

// https://judge.yosupo.jp/problem/range_affine_range_sum

// 区間和
// ll merge(ll a, ll b){
//     return a + b;
// }

// 区間最大
ll mergeFunc(ll a, ll b){
    return max(a, b);
}

ll applyFunc(ll a, ll b){ //aの値をbに変更
    return b;
}

ll composeFunc(ll a, ll b){// 親aから子bへ変更の値を伝播
    return b;
}








int main () {
    ll W, N;
    cin >> W >> N;

 
    LazySegmentTree<int, int> seg(W, 0, -1, mergeFunc, applyFunc, composeFunc);

    for(ll i = 0; i < N; i ++){
        ll l, r;
        cin >> l >> r;
        ll max = seg.query(l - 1, r);
        seg.update(l - 1, r, max + 1);
        cout << max + 1 << endl;


    }


    
}
