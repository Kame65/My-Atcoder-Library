#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>
#include <set>
#include <queue>
using namespace std;
using ll=long long; using vl=vector<ll>;
int N,M; int field[16][16];
int dirY[]={0,1,0,-1}; int dirX[]={-1,0,1,0};
const int MAX_DEPTH=4;
pair<int,int> home[167];
struct Dice{ int x,y; int n,w,b,e,s,t; int haveSize; set<int> have;
 Dice(){y=0;x=0;n=w=b=e=s=t=-1;haveSize=0;}
 void moveR(){swap(w,b);swap(b,e);swap(e,t);}
 void moveL(){swap(w,t);swap(t,e);swap(e,b);}
 void moveU(){swap(n,t);swap(t,s);swap(s,b);}
 void moveD(){swap(n,b);swap(b,s);swap(s,t);}
 void move(int dir){ if(dir==0)moveL(); if(dir==1)moveD(); if(dir==2)moveR(); if(dir==3)moveU();
  y+=dirY[dir]; x+=dirX[dir];
  if(b>0){haveSize--;have.erase(b);}
  if(field[y][x]>0){haveSize++;have.insert(field[y][x]);}
  swap(field[y][x],b);}
 void reverse(int dir){ dir=(dir+2)%4;
  if(b>0){haveSize--;have.erase(b);}
  if(field[y][x]>0){haveSize++;have.insert(field[y][x]);}
  swap(field[y][x],b);
  if(dir==0)moveL(); if(dir==1)moveD(); if(dir==2)moveR(); if(dir==3)moveU();
  y+=dirY[dir]; x+=dirX[dir];}
 int faceOf(int v){ // 0:T 1:B 2:N 3:S 4:W 5:E
  if(t==v)return 0; if(b==v)return 1; if(n==v)return 2; if(s==v)return 3; if(w==v)return 4; if(e==v)return 5; return -1;}
};
char change(int d){return "LDRU"[d];}
// ===== 追加：目標の荷物の「残り手数」をBFSで求める =====
// 状態 = (位置, 目標の荷物が乗っている面)。配達済みマスは壁、目的地以外で目標の面が接地する移動は禁止
const int INF=1e9;
const int FT=0,FB=1,FN=2,FS=3,FW=4,FE=5;
int newFace[4][6]; int prevFace[4][6];
int fdist[16][16][6]; // fdist[y][x][f]: (y,x)にいて目標が面fにあるとき、配達までの最短手数
int target=0;
bool isWall(int y,int x){int v=field[y][x]; return v>0 && home[v]==make_pair(y,x);}
void initFace(){
 int L_[6]={FW,FE,FN,FS,FB,FT}; int D_[6]={FS,FN,FT,FB,FW,FE};
 int R_[6]={FE,FW,FN,FS,FT,FB}; int U_[6]={FN,FS,FB,FT,FW,FE};
 for(int f=0;f<6;f++){newFace[0][f]=L_[f];newFace[1][f]=D_[f];newFace[2][f]=R_[f];newFace[3][f]=U_[f];}
 for(int d=0;d<4;d++)for(int f=0;f<6;f++)prevFace[d][newFace[d][f]]=f;
}
void calcFaceDist(int v){
 for(auto&a:fdist)for(auto&b:a)for(int&c:b)c=INF;
 auto [hy,hx]=home[v]; queue<array<int,3>> q;
 for(int d=0;d<4;d++){int py=hy-dirY[d],px=hx-dirX[d];
  if(py<0||py>=N||px<0||px>=N)continue;
  int f=prevFace[d][FB]; if(fdist[py][px][f]>1){fdist[py][px][f]=1;q.push({py,px,f});}}
 while(!q.empty()){auto [y2,x2,f2]=q.front();q.pop();
  if(isWall(y2,x2))continue; if(f2==FB)continue;
  for(int d=0;d<4;d++){int y1=y2-dirY[d],x1=x2-dirX[d];
   if(y1<0||y1>=N||x1<0||x1>=N)continue;
   int f1=prevFace[d][f2];
   if(fdist[y1][x1][f1]>fdist[y2][x2][f2]+1){fdist[y1][x1][f1]=fdist[y2][x2][f2]+1;q.push({y1,x1,f1});}}}
}
int pdist[16][16];    // 空のとき: 目標の荷物の位置までの最短距離
void calcPosDist(int sy,int sx){
 for(auto&a:pdist)for(int&c:a)c=INF; queue<pair<int,int>> q; pdist[sy][sx]=0;q.push({sy,sx});
 while(!q.empty()){auto [y,x]=q.front();q.pop();
  for(int d=0;d<4;d++){int ny=y+dirY[d],nx=x+dirX[d];
   if(ny<0||ny>=N||nx<0||nx>=N||isWall(ny,nx)||pdist[ny][nx]<INF)continue;
   pdist[ny][nx]=pdist[y][x]+1;q.push({ny,nx});}}
}
// 目標の荷物を届けるまでの残り手数（状態の評価。差分ではないので往復で得をしない）
ll remaining(Dice& d){
 if(field[home[target].first][home[target].second]==target) return 0;
 int f=d.faceOf(target);
 if(f>=0) return fdist[d.y][d.x][f];
 for(int y=0;y<N;y++)for(int x=0;x<N;x++) if(field[y][x]==target)
  return (ll)pdist[d.y][d.x]+fdist[y][x][FB];
 return INF;
}
// 持っている最小番号のうち配達可能なものを目標に。空なら最寄りの未配達荷物
void chooseTarget(Dice& d){
 for(int v:d.have){ calcFaceDist(v); int f=d.faceOf(v); if(fdist[d.y][d.x][f]<INF){target=v;return;} }
 calcPosDist(d.y,d.x); ll best=INF; int bv=0;
 for(int y=0;y<N;y++)for(int x=0;x<N;x++){int v=field[y][x];
  if(v>0&&!isWall(y,x)&&pdist[y][x]<best){best=pdist[y][x];bv=v;}}
 target=bv; if(bv==0)return;
 calcFaceDist(bv);
 for(int y=0;y<N;y++)for(int x=0;x<N;x++) if(field[y][x]==bv) calcPosDist(y,x);
}
// ===============
// 葉の評価 = -(残り手数)
ll evaluate(Dice& d){ ll r=remaining(d); if(r>=INF) return -1000000; return -100*r;}
ll evaluateHand(Dice&,int,int);
int choiceHand(Dice& d){ ll mx=LLONG_MIN; vl r;
 for(int i=0;i<4;i++){ll v=evaluateHand(d,i,0); if(mx<v){mx=v;r.clear();r.push_back(i);}else if(mx==v)r.push_back(i);}
 return r[rand()%r.size()];}
ll evaluateHand(Dice& dice,int hand,int depth){
 int ny=dice.y+dirY[hand], nx=dice.x+dirX[hand]; ll ret=0;
 if(ny<0||ny>=N||nx<0||nx>=N) return LLONG_MIN;
 dice.move(hand);
 int putNum=field[dice.y][dice.x];
 if(putNum>0&&home[putNum]==make_pair(dice.y,dice.x)) ret+=10000*(MAX_DEPTH+1-depth);
 int g=dice.b; if(g>0&&home[g]==make_pair(dice.y,dice.x)) ret-=100000;
 if(depth==MAX_DEPTH){ll v=evaluate(dice);dice.reverse(hand);return v+ret;}
 ll mx=LLONG_MIN; for(int i=0;i<4;i++){ll v=evaluateHand(dice,i,depth+1); if(v>mx)mx=v;}
 dice.reverse(hand); return mx+ret;}
int main(){cin>>N>>M; initFace();
 for(int y=0;y<N;y++)for(int x=0;x<N;x++)cin>>field[y][x];
 int h; for(int y=0;y<N;y++)for(int x=0;x<N;x++){cin>>h;if(h>0)home[h]={y,x};}
 Dice d; int deliv=0; for(int y=0;y<N;y++)for(int x=0;x<N;x++) if(isWall(y,x))deliv++;
 int T=0;
 for(int i=0;i<10000&&deliv<M;i++){ // 全部配ったら終了
  chooseTarget(d); if(target==0)break;
  int dir=choiceHand(d); d.move(dir); T++;
  int f=field[d.y][d.x]; if(f>0&&home[f]==make_pair(d.y,d.x))deliv++;
  cout<<change(dir)<<'\n';
 }
 cerr<<"T="<<T<<" delivered="<<deliv<<"/"<<M<<"\n";
}