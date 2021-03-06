#include<cstdio>
#include<vector>
#include<set>
#include<map>
#include<queue>
#include<algorithm>
#include<string>
#include<utility>
#include<cassert>
using namespace std;

#define REP(i,a,b) for(i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)

#define ll long long
#define INF 1000000001

ll read_int(ll mn, ll mx, char next){
  int c, fg = 1, res = 0;
  c=getchar();
  if(c=='-') fg = -1, c = getchar();
  assert('0'<=c && c<='9');
  res = c - '0';
  for(;;){
    c = getchar();
    if(c==next) break;
    assert(res!=0);
    assert('0'<=c && c<='9');
    res = res * 10 + (c - '0');
  }
  res *= fg;
  assert(mn<=res && res<=mx);
  return res;
}

int is_connect(ll dx, ll dy, ll r){
  if(dx*dx+dy*dy <= r*r) return 1;
  return 0;
}

int N, X[250], Y[250];
int M, R[250], C[250];
int W;

int cost[250][250], visited[250][250];
pair<int,int> pii[250];

int edge[250][250][250];

int main(){
  int T;

  T = read_int(1, 15, '\n');

  while(T--){
    int i,j,k,l,next;
    int a,b;
    int res = INF;
    priority_queue< pair<int,int> > q;

    N = read_int(1, 250, ' ');
    M = read_int(1, 250, ' ');
    W = read_int(1, 1000000000, '\n');
    rep(i,N){
      X[i] = read_int(0, 1000000000, ' ');
      Y[i] = read_int(1, W-1, '\n');
    }
    rep(i,M){
      R[i] = read_int(1, 1000000000, ' ');
      C[i] = read_int(1, 1000000, '\n');
    }

    /* sorting disks: C[i] < C[i+1], R[i] < R[i+1] */
    rep(i,M) pii[i].first=R[i], pii[i].second=C[i];
    sort(pii, pii+M);
    rep(i,M) R[i]=pii[i].first, C[i]=pii[i].second;

    /* deleting (C[i], R[i]) if such j exists: C[i]>=C[j], R[i]<=R[j] */
    k = 1;
    REP(i,1,M){
      while(k>0 && C[i] <= C[k-1]) k--;
      C[k] = C[i]; R[k] = R[i]; k++;
    }
    M = k;

    /* precalclation */
    /* edge[i][j][a] = b means piles i and j are connected if pile i has disk a, and pile j has disk b or b+1, ..., or M-1 */
    /* edge[i][j][a] = -1 means piles i and j cannot be connected if pile i has disk a */
    rep(i,N) rep(j,N){
      b = M-1;
      rep(a,M){
        if(!is_connect(X[i]-X[j], Y[i]-Y[j], R[a]+R[b])){
          edge[i][j][a] = -1;
          continue;
        }
        while(b-1>=0 && is_connect(X[i]-X[j], Y[i]-Y[j], R[a]+R[b-1])) b--;
        edge[i][j][a] = b;
      }
    }

    /* do dijkstra */
    /* state (i,j) denotes: Ciel now is on disk j which center is pile i */
    /* Let Ciel can move (i,a) -> (i,a-1) without any costs, then we don't consider moving (i,a) -> (j,edge[i][j][a]+1) and so on */
    rep(i,N) rep(j,M) cost[i][j] = INF, visited[i][j] = 0;
    rep(i,N) rep(j,M) if(Y[i] <= R[j]){
      cost[i][j] = C[j];
      q.push( make_pair(-cost[i][j], i*M+j) );
    }

    while(q.size()){
      i = q.top().second / M;
      j = q.top().second % M;
      q.pop();
      if(visited[i][j]) continue;
      visited[i][j] = 1;

      if(Y[i]+R[j] >= W){
        res = cost[i][j];
        break;
      }

      if(j+1 < M){
        next = cost[i][j] + C[j+1]-C[j];
        if(cost[i][j+1] > next){
          cost[i][j+1] = next;
          q.push( make_pair(-cost[i][j+1], i*M+j+1) );
        }
      }

      rep(k,N) if(k!=i) if(edge[i][k][j]>=0) {
        l = edge[i][k][j];
        next = cost[i][j] + C[l];
        if(cost[k][l] > next){
          cost[k][l] = next;
          q.push( make_pair(-cost[k][l], k*M+l) );
        }
      }
    }

    if(res == INF) puts("impossible");
    else           printf("%d\n",res);
  }

  return 0;
}
