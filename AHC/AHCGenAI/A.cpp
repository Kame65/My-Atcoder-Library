#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <queue>
#include <set>
#include <atcoder/all>

using namespace std;
using ll = long long;
using vl = vector<ll>;

int N, M;
int field[16][16];
int dice[6];
// L, D, R, U
int dirY[] = {0, 1, 0, -1};
int dirX[] = {-1, 0, 1, 0};
const int MAX_DEPTH = 4;
pair<int, int> numP[167]; //1indexed
pair<int, int> home[167]; //1indexed

pair<int, int> HOLD = make_pair(-1, -1);

struct Dice{
    int x, y;
    int n, w, b, e, s, t;
    int haveSize;  
    set<int> have;
    Dice(){
        y = 0; x = 0;
        n = -1, w = -1, b = -1, e = -1, s = -1, t = -1;
        haveSize = 0;
    }

    void moveR(){
        // cerr << "movedR\n";
        swap(w, b);
        swap(b, e);
        swap(e, t);
    }
    void moveL(){
        // cerr << "movedL\n";
        swap(w, t);
        swap(t, e);
        swap(e, b);
    }
    void moveU(){
        // cerr << "movedU\n";
        swap(n, t);
        swap(t, s);
        swap(s, b);
    }
    void moveD(){
        // cerr << "movedD\n";
        swap(n, b);
        swap(b, s);
        swap(s, t);
    }

    
    public: 
    void move(int dir){
        if(dir == 0) moveL(); //Left
        if(dir == 1) moveD(); //Up
        if(dir == 2) moveR(); //Right
        if(dir == 3) moveU(); //Down
        y += dirY[dir];
        x += dirX[dir];
        if(b > 0) {//下側がすでに所持の場合
            haveSize --;
            have.erase(b);
            numP[b] = make_pair(y, x);
        }
        if(field[y][x] > 0) {//ついたマスに数字がある場合
            haveSize ++;
            numP[field[y][x]] = make_pair(-1, -1);
            have.insert(field[y][x]);
        }
        swap(field[y][x], b);
        // cerr << "swap: " << field[y][x] << " " << haveNum[dirIdx[2]] << "\n";

    }
    void reverse(int dir){ //dirに移動した処理を戻す
        dir += 2;
        dir %= 4;
        if(b > 0) {//下側がすでに所持の場合
            haveSize --;
            numP[b] = make_pair(y, x);
            have.erase(b);
        }
        if(field[y][x] > 0) {//ついたマスに数字がある場合
            haveSize ++;
            numP[field[y][x]] = make_pair(-1, -1);
            have.insert(field[y][x]);
        }
        swap(field[y][x], b);
        if(dir == 0) moveL(); //Left
        if(dir == 1) moveD(); //Up
        if(dir == 2) moveR(); //Right
        if(dir == 3) moveU(); //Down
        y += dirY[dir];
        x += dirX[dir];
    }

};

char change(int dir){
    if(dir == 0) return 'L';
    if(dir == 1) return 'D';
    if(dir == 2) return 'R';
    if(dir == 3) return 'U';
    return 'E';
}

void showField(){
    cout << "show field\n";
    for(int y = 0; y < N; y ++){
        for(int x = 0;x < N; x ++){
            cout << field[y][x] << " ";
        }
        cout << "\n";
    }
    cout << "\n";
}

void showDice(Dice& d){
    cout << "show dice\n";
    cout << d.haveSize << "\n";
    cout << d.y << " " << d.x << " \n";
}



ll evaluateHand(Dice&, int, int);
ll evaluate(Dice& dice){

    ll val = 0;
    if(dice.have.size() == 0) val -= 10;
    int dist = 0;
    val -= dist;
    return val;

}

int choiceHand(Dice& dice){
    ll max = LONG_MIN;
    vl result;
    for(int i = 0; i < 4; i ++){
        ll val = evaluateHand(dice, i, 0);
        cerr << "hand = " << change(i) << endl;
        cerr << "val = " << val << "\n";
        if(max < val){
            max = val;
            result.clear();
            result.push_back(i);
        }else if(max == val){
            result.push_back(i);
        }
    }
    // cerr << "choice = " << choice << " " << "val = " << max << "\n";
    // cerr << "sameHand: " << result.size() << "\n";
    // cerr << "score = " << max << "\n";
    return result[rand() % result.size()];

}
ll evaluateHand(Dice& dice, int hand, int depth){ // hand -> 動く方向
    int ny = dice.y + dirY[hand];
    int nx = dice.x + dirX[hand];
    ll ret = 0; //返却値
    if(ny < 0 || ny >= N || nx < 0 || nx >= N) return LONG_MIN;
    int by = dice.y;
    int bx = dice.x;


    int bNum = 0;
    if(dice.haveSize > 0) bNum = *dice.have.begin();
    dice.move(hand);
    // 家にnumを返す時
    int putNum = field[dice.y][dice.x];
    if(putNum > 0 && home[putNum].first == dice.y && home[putNum].second == dice.x ){
        // cerr << "putNum = " << putNum << endl;
        // cerr << "back home\n";
        ret += 10000 * (MAX_DEPTH + 1 - depth);
    }
    int aNum = 0;
    if(dice.haveSize > 0) aNum = *dice.have.begin();

    // cerr << "bNum = " << bNum << " aNum = " << aNum << " \n";
    if(bNum > 0 && aNum > bNum){
        ret -= 100;
    } 
    if(aNum == bNum && aNum > 0){
        ret += abs(by - home[aNum].first) + abs(bx - home[aNum].second);
        ret -= abs(ny - home[aNum].first) + abs(nx - home[aNum].second);
    }


    // 家からnumを取る場合
    int getNum = dice.b;
    if(getNum > 0 && home[getNum].first == dice.y && home[getNum].second == dice.x){
        ret -= 100000;
    }



    if(depth == MAX_DEPTH){
        int val = evaluate(dice);
        dice.reverse(hand);
        return val + ret;
    } 
    ll max = LONG_MIN;
    for(int i = 0; i < 4; i ++){
        ll val = evaluateHand(dice, i, depth + 1);
        if(val > max) max = val;
    }
    dice.reverse(hand);
    return max + ret;


}

int main(){
    cin >> N >> M;
    for(int y = 0; y < N; y ++){
        for(int x = 0; x < N; x ++){
            cin >> field[y][x];
            if(field[y][x] > 0) numP[field[y][x]] = make_pair(y, x);
        }
    }
    int h;
    for(int y = 0; y < N; y ++){
        for(int x = 0; x < N; x ++){
            cin >> h;
            if(h > 0) home[h] = make_pair(y, x); 
        }
    }
    Dice dice = Dice();

    for(int i = 0; i < 10000; i ++){
        int dir = choiceHand(dice);
        // cout << "dir = " << dir << "\n";
        // cerr << "t = " << i + 1 << endl;
        dice.move(dir);
        // cerr << "first num" << *dice.have.begin() << "\n";

        cout << change(dir) << '\n';
        // cerr << "move: " << change(dir) << "\n";
        // cerr << "ev: " << evaluate(dice) << "\n";
        // showDice(dice);
        // showField();


    }




    



    




    
    

    
}
