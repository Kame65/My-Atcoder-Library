#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <numeric>
#include <queue>
#include <climits>

using namespace std;
using ll = long long int;
using vl = vector<ll>;
using vvl = vector<vl>;
using vc = vector<char>;
using vvc = vector<vc>;
using vvvl  = vector<vvl>;



static const int max_n = 1 << 18; //数列a_iの最大の要素数を設定する
pair<int, int> seg_treeMin[2 * max_n];
int n;

// Min側
//初期化を行う関数
void initMin(int n_) {
	//完全二分木にするため、データ数を2の倍数にする。
	n = 1;
	while (n < n_) n *= 2;

	//RMQを考えたいので、セグ木の各値はINT_MAXに設定しておく
    for(ll i = 0; i < 2 * n; i ++){
        seg_treeMin[i] = make_pair(INT_MAX, -1);
    }

}

//index番目の値をxに変更する関数
void updateMin(int index, int x) {
	index += n - 1; //最も下のレイヤーにおいて、1番目の値はseg_treeの中ではn番目だから
	seg_treeMin[index] = make_pair(x, index - n + 1);
	while (index > 0) {
		index = (index - 1) / 2; //親のノードのindex
		seg_treeMin[index] = min(seg_treeMin[2 * index + 1], seg_treeMin[2 * index + 2]);
	}
}

//区間[a,b)における最小値を求める関数
//indexはseg_treeMinにおける番号で、left,rightはseg_treeMin[index]の区間に対応
//query(a,b,0,0,n)として呼ぶことを考える。
pair<int, int> queryMin(int a, int b, int index, int left, int right) {
	//考えようとしている区間が、[a,b)に全く含まれないなら、INT_MAXを返して、操作に影響しないようにする。
	if (a >= right || b <= left) return make_pair(INT_MAX, -1);

	//考えようとしている区間が[a,b)に完全に含まれているなら、その値を返せばよい。
	if (a <= left && b >= right) return seg_treeMin[index];

	//どちらでもない場合、seg_treeMin[index]の2つの子ノードに対して再帰的に操作を行う。
	pair<int, int> value_1 = queryMin(a, b, 2 * index + 1, left, (left + right) / 2);
	pair<int, int> value_2 = queryMin(a, b, 2 * index + 2, (left + right) / 2, right);
    if(value_1.first > value_2.first){
        return value_2;
    }else{
        return value_1;
    }

}

pair<int, int> seg_treeMax[2 * max_n];

//初期化を行う関数
void initMax(int n_) {
	//完全二分木にするため、データ数を2の倍数にする。
	n = 1;
	while (n < n_) n *= 2;

	//RMQを考えたいので、セグ木の各値はINT_MAXに設定しておく
    for(ll i = 0; i < 2 * n; i ++){
        seg_treeMax[i] = make_pair(INT_MIN, -1);
    }

}

//index番目の値をxに変更する関数
void updateMax(int index, int x) {
	index += n - 1; //最も下のレイヤーにおいて、1番目の値はseg_treeMaxの中ではn番目だから
	seg_treeMax[index] = make_pair(x, index - n + 1);
	while (index > 0) {
		index = (index - 1) / 2; //親のノードのindex
		seg_treeMax[index] = max(seg_treeMax[2 * index + 1], seg_treeMax[2 * index + 2]);
	}
}

//区間[a,b)における最小値を求める関数
//indexはseg_treeMaxにおける番号で、left,rightはseg_treeMax[index]の区間に対応
//query(a,b,0,0,n)として呼ぶことを考える。
pair<int, int> queryMax(int a, int b, int index, int left, int right) {
	//考えようとしている区間が、[a,b)に全く含まれないなら、INT_MAXを返して、操作に影響しないようにする。
	if (a >= right || b <= left) return make_pair(INT_MIN, -1);

	//考えようとしている区間が[a,b)に完全に含まれているなら、その値を返せばよい。
	if (a <= left && b >= right) return seg_treeMax[index];

	//どちらでもない場合、seg_treeMax[index]の2つの子ノードに対して再帰的に操作を行う。
	pair<int, int> value_1 = queryMax(a, b, 2 * index + 1, left, (left + right) / 2);
	pair<int, int> value_2 = queryMax(a, b, 2 * index + 2, (left + right) / 2, right);
    if(value_1.first < value_2.first){
        return value_2;
    }else{
        return value_1;
    }

}

int main(){
    ll N, M;
    cin >> N >> M;
    vl vecP(N);
    for(ll i = 0; i < N; i ++){
        cin >> vecP[i];
    }
    initMin(N);
    initMax(N);
    for(ll i = 0; i < N; i ++){
        updateMax(i, vecP[i]);
        updateMin(i, vecP[i]);
    }
    // cout << "val = " << endl;
    // for(ll i = 0; i < N; i ++){
    //     int val = queryMin(i, i + 1, 0, 0, n).first;
    //     cout << val << " ";
    // }
    // cout << endl;


    for(ll i = 0; i < M; i ++){
        ll l, r;
        cin >> l >> r;

        auto[max, idxMax] = queryMax(l - 1 ,r, 0, 0, n);
        auto[min, idxMin] = queryMin(l - 1 ,r, 0, 0, n);

        // cout << "res: " << min << " idx: " << idxMin << " max: " << max << " maxidx: " << idxMax  << endl;

        updateMax(idxMax, min);
        updateMax(idxMin, max);
        updateMin(idxMax, min);
        updateMin(idxMin, max);


    }
    for(ll i = 0; i < N; i ++){
        int val = queryMin(i, i + 1, 0, 0, n).first;
        cout << val << " ";
    }
    cout << endl;

}
