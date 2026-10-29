// #include <iostream>
// #include <vector>
// #include <algorithm>
// #include <set>
// #include <queue>
// #include <climits>
// #include <unordered_map>

// using namespace std;
// using ll = long long;


// ll N, K;
// int S;
// ll nowScore = 0;
// ll nowCost = 0;


// // field[y][x]

// struct Place{
//     public:
//     static int placeCnt;
//     bool ground;
//     int slimeNum;
//     int hole;
//     vector<int> slimeId;
//     Place(){
//         ground = false;
//         slimeNum = 0;
//         hole = -1;
//     }
//     Place(char c){
//         if(c == '#'){
//             slimeNum = 0;
//             ground = false;
//             hole = -1;
//         }else{
//             ground = true;
//             if(0 <= c - 'A' && c - 'A' <= 'Z' - 'A'){
//                 hole = c - 'A';
//                 slimeNum = 0;
//             }else{
//                 hole = -1;
//                 if(0 <= c - 'a' && c - 'a' <= 'z' - 'a'){
//                     slimeNum = 1;
//                     slimeId.push_back(placeCnt);
//                     placeCnt ++;
//                 }else{
//                     slimeNum = 0;
//                 }
//             }
            
//         }
//     }
// };
// int Place::placeCnt = 0;

// struct UndoRec {
//     Hand h;
//     int m;            // 動かした匹数
//     int rs, rd;       // 元のマス / 行き先で消えた匹数
//     int remS[16], remD[16];  // 消えたスライムのID(消えた順)
//     int prevCost;     // 差分評価を使うなら、move 前のコスト
// };

// struct Hand { int y, x, k, d, j; };   // vector を持たない

// struct Slime{
//     int y;
//     int x;
//     int c;
//     int k;//下から何番目か 地面の場合0
//     int id;
//     bool remain;//fieldに残っているか
//     int canMoveNum;

//     Slime(int y_, int x_, int c_, int k_, int id_){
//         y = y_;
//         x = x_;
//         c = c_;
//         k = k_;
//         id = id_;
//         remain = true;
//         canMoveNum = 0;
//     }

//     Slime(){
//         y = -1;
//         x = -1;
//         c = -1;
//         k = -1;
//         id = -1;
//         remain = false;
//     }

// };

// struct Hole{
//     public:
//     int y;
//     int x;
//     Hole(){
//         y = -1;
//         x = -1;
//     }
//     Hole(int y_, int x_){
//         y = y_;
//         x = x_;
//     };

// };



// vector<vector<vector<vector<int>>>> placetoPlace;
// vector<vector<int>>placeWeight;
// vector<Hole> vecHole;
// vector<vector<Place>> field;
// vector<Slime>slimes;
// unordered_map<ll, bool> memo;
// const int DEPTHLIMIT = 1;
// bool RETREAT = false;
// // 160000 * y + 8000 * x + 400 * k + 20 * disNum + l をhashとする。

// Place NONE = Place('.');
// int dirX[] = {-1, 0, 1, 0}, dirY[] = {0, -1, 0, 1};
// pair<int, int> GOAL = make_pair(-2, -2);
// pair<int, int> START = make_pair(-3, -3);


// bool inField(int y, int x){
//     if(0 <= x && x <= N - 1 && 0 <= y && y <= N - 1 && field[y][x].ground){
//         return true;
//     }
//     return false;
// }

// char getDirection(int nowY, int nowX, int afterY, int afterX){
//     if(afterY - nowY > 0){
//         return 'D';
//     }
//     if(afterY - nowY < 0){
//         return 'U';
//     }
//     if(afterX - nowX > 0){
//         return 'R';
//     }
//     if(afterX - nowX < 0){
//         return 'L';
//     }
//     return 'E';
// }

// char getDirection(int d){
//     if(d == 0) return 'L';
//     if(d == 1) return 'U';
//     if(d == 2) return 'R';
//     if(d == 3) return 'D';
// }

// int getDist(int nowY, int nowX, int afterY, int afterX){
//     return abs(afterY - nowY) + abs(afterX - nowX);
// }

// int remainCount(){
//     int r = 0;
//     for(auto& s : slimes){
//         r += s.remain;
//     }  
//     return r; 
// }


// void put(Hand);
// void move(Hand);
// void undo(Hand);
// vector<Hand> makeHand(bool, bool);


// int evaluateScore(Hand hand, int depth = 0){
//     int score = nowScore;
//     vector<Slime>movedSlime; //一番上から下へ
//     int nextY = hand.y + dirY[hand.d] * hand.j;
//     int nextX = hand.x + dirX[hand.d] * hand.j;
//     for(int i = field[hand.y][hand.x].slimeNum - 1; i >= hand.k; i --){
//         movedSlime.push_back(slimes[field[hand.y][hand.x].slimeId[i]]);
//     }
//     for(auto &sl: movedSlime){
//         score += placetoPlace[sl.y][sl.x][vecHole[sl.c].y][vecHole[sl.c].x];
//         score -= placetoPlace[nextY][nextX][vecHole[sl.c].y][vecHole[sl.x].x];
//     }
    
//     int underColor = -1;
//     if(hand.k > 0){
//         int underSlimeId = field[hand.y][hand.x].slimeId[hand.k - 1];
//         underColor = slimes[underSlimeId].c;
//     }
//     if((*movedSlime.rbegin()).c == underColor){
//         score -= 90;
//     }
//     if(field[nextY][nextX].slimeNum > 0){
//         if(slimes[*field[nextY][nextX].slimeId.rbegin()].c == movedSlime[0].c){
//             score += 100;
//         }
//     }

//     return score;
    
// }

// void put(Hand hand){
//     cout << hand.y << " " << hand.x << " " << hand.k << " " << getDirection(hand.d) << " " << hand.j << "\n";
// }

// UndoRec doMove(const Hand& h){
//     UndoRec u; u.h = h; u.rs = u.rd = 0; u.prevCost = nowCost;
//     int sy = h.y, sx = h.x, ty = h.y + dirY[h.d]*h.j, tx = h.x + dirX[h.d]*h.j;
//     auto& S = field[sy][sx]; auto& T = field[ty][tx];

//     nowCost -= cellCost(sy, sx) + cellCost(ty, tx);
//     u.m = (int)S.slimeId.size() - h.k;
//     while((int)S.slimeId.size() > h.k){             // 1. 上から順に移す
//         int id = S.slimeId.back(); S.slimeId.pop_back();
//         slimes[id].y = ty; slimes[id].x = tx; slimes[id].k = (int)T.slimeId.size();
//         T.slimeId.push_back(id);
//     }
//     while(T.hole >= 0 && !T.slimeId.empty() && slimes[T.slimeId.back()].c == T.hole){  // 2.
//         int id = T.slimeId.back(); T.slimeId.pop_back();
//         slimes[id].remain = false; u.remD[u.rd++] = id;
//     }
//     while(S.hole >= 0 && !S.slimeId.empty() && slimes[S.slimeId.back()].c == S.hole){  // 3.
//         int id = S.slimeId.back(); S.slimeId.pop_back();
//         slimes[id].remain = false; u.remS[u.rs++] = id;
//     }
//     S.slimeNum = S.slimeId.size(); T.slimeNum = T.slimeId.size();
//     nowCost += cellCost(sy, sx) + cellCost(ty, tx);
//     remainCnt -= u.rs + u.rd;
//     return u;
// }

// void undo(Hand choice){
//     auto unI = choice.unInfo;
//     field[unI.y0][unI.x0].slimeNum = unI.p0SlimeId.size();
//     field[unI.y0][unI.x0].slimeId = unI.p0SlimeId;
//     field[unI.y1][unI.x1].slimeNum = unI.p1SlimeId.size();
//     field[unI.y1][unI.x1].slimeId = unI.p1SlimeId;
//     int idx = 0;
//     for(int id: unI.p0SlimeId){
//         slimes[id].remain = true;
//         slimes[id].y = unI.y0;
//         slimes[id].x = unI.x0;
//         slimes[id].k = idx;
//         idx ++;
//     }
//     idx = 0;
//     for(int id: unI.p1SlimeId){
//         slimes[id].remain = true;
//         slimes[id].y = unI.y1;
//         slimes[id].x = unI.x1;
//         slimes[id].k = idx;
//         idx ++;
//     }

// }

// void makeHandLight(vector<Hand>& out, bool mxdis = true){   // 使い回すバッファに書き込む
//     out.clear();
//     for(auto& sl : slimes){
//         if(!sl.remain) continue;
//         auto& hc = vecHole[sl.c];
//         int dcur = placetoPlace[sl.y][sl.x][hc.y][hc.x];
//         int base = field[sl.y][sl.x].slimeNum - sl.k;
//         for(int i = 0; i < 4; i++) for(int j = 1; j <= sl.k + 1; j++){
//             int ny = sl.y + dirY[i]*j, nx = sl.x + dirX[i]*j;
//             if(!inField(ny, nx)) break;
//             if(field[ny][nx].slimeNum + base <= 8 && dcur > placetoPlace[ny][nx][hc.y][hc.x])
//                 out.push_back({sl.y, sl.x, sl.k, i, j});
//         }
//     }
// }

// vector<vector<vector<vector<int>>>> makePlaceToPlace(){
//     vector<vector<vector<vector<int>>>>result(N, vector<vector<vector<int>>>(N, vector<vector<int>>(N, vector<int>(N, -1))));
//     for(int y0 = 0; y0 < N; y0 ++){
//         for(int x0 = 0; x0 < N; x0 ++){
//             queue<vector<int>> q;
//             q.push({y0, x0, 0});
//             vector<vector<int>>&place = result[y0][x0];
//             place[y0][x0] = 0;
//             while(q.size() > 0){
//                 auto nowPlace = q.front();
//                 q.pop();
//                 int pY = nowPlace[0];
//                 int pX = nowPlace[1];
//                 int dist = nowPlace[2];
//                 int nextY, nextX;
//                 for(int i = 0; i < 4; i ++){
//                     nextY = pY + dirY[i];
//                     nextX = pX + dirX[i];
                    
//                     if(inField(nextY, nextX) && place[nextY][nextX] < 0){
//                         q.push({nextY, nextX, dist + 1});
//                         place[nextY][nextX] = dist + 1;
//                     }
//                 }

//             }

//         }
//     }
//     return result;
// }

// vector<vector<int>> makePlaceWeight(){
//     vector<vector<int>>result(N, vector<int>(N, 0));
//     int sum = 0;
//     for(int y0 = 0; y0 < N; y0 ++){
//         for(int x0 = 0; x0 < N; x0 ++){
//             for(int i = 0; i < 4; i ++){
//                 for(int j = 1; j < 3; j ++){
//                     int nextY = y0 + dirY[i] * j;
//                     int nextX = x0 + dirX[i] * j;
//                     if(inField(nextY, nextX)){
//                         result[y0][x0] ++;
//                         sum ++;
//                     }else{
//                         break;
//                     }
//                 }
//             }
//         }
//     }
//     int ave = sum / N / N;
//     for(int y = 0; y < N; y ++){
//         for(int x = 0; x < N; x ++){
//             result[y][x] -= ave;
//             result[y][x] = result[y][x] * result[y][x];
//         }
//     }
//     return result;
// }

// int main(){
//     cin >> N >> K;
//     field = vector<vector<Place>>(N, vector<Place>(N));
//     vecHole = vector<Hole>(K);
//     int slimeCnt = 0;

//     for(ll y = 0; y < N; y ++){
//         string strC;
//         cin >> strC;
//         for(ll x = 0; x < N; x ++){
//             field[y][x] = Place(strC[x]);
//             if(field[y][x].slimeNum > 0){
//                 slimes.push_back(Slime(y, x, (strC[x] - 'a'), 0, slimeCnt));
//                 slimeCnt ++;
//             }
//             if(field[y][x].hole >= 0){
//                 vecHole[field[y][x].hole] = Hole(y, x);
//             }
//         }
//     }
//     S = slimes.size();

//     placetoPlace = makePlaceToPlace();
//     placeWeight = makePlaceWeight();
//     for(auto& sl: slimes){
//         nowScore += placetoPlace[sl.y][sl.x][vecHole[sl.c].y][vecHole[sl.c].x];
//     }

//     //初期化処理完了

//     int cnt = 0;
//     while(true){
        
//         auto allhand = makeHand(true, true);
//         if(allhand.size() == 0) allhand = makeHand(false, true);
//         if(allhand.size() == 0) allhand = makeHand(false, false);
//         if(allhand.size() == 0){
//             if(remainCount() == 0) break;          // 全部帰ったら終了
//             RETREAT = true;
//             allhand = makeHand(false, true);
//             if(allhand.size() == 0) allhand = makeHand(false, false);
//             RETREAT = false;
//             if(allhand.size() == 0) break;
//         }
//         int max = INT_MIN;
//         int choice = 0;
        
//         for(int i = 0; i < allhand.size(); i ++){
//             Hand hand = allhand[i];

//             int score = evaluateScore(hand);

//             if(score > max){
//                 max = score;
//                 choice = i;
//             }

//         }       
//         cnt ++;
        
//         auto& hand = allhand[choice];
//         put(hand);
//         move(allhand[choice]);
//         vector<Slime>movedSlimeID;
//         int nextY = hand.y + dirY[hand.d] * hand.j;
//         int nextX = hand.x + dirX[hand.d] * hand.j;
//         for(int i = field[hand.y][hand.x].slimeNum - 1; i >= hand.k; i --){
//             movedSlimeID.push_back(slimes[field[hand.y][hand.x].slimeId[i]]);
//         }
//         for(auto &sl: movedSlimeID){
//             nowScore -= placetoPlace[sl.y][sl.x][vecHole[sl.c].y][vecHole[sl.c].x];
//             nowScore += placetoPlace[nextY][nextX][vecHole[sl.c].y][vecHole[sl.c].x];
//         }


//     }
//     // for(auto sl: slimes){
//     //     if(sl.remain){
//     //         cout << "remain" << endl;
//     //         break;
//     //     }
//     // }
//     // cout << "score = " << cnt << endl;



    

// }




