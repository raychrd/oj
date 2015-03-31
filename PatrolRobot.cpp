//UVA-1600 Patrol Robot
#include <iostream>
#include <algorithm>
#include <queue>
#include <cstdio>
#include <stack>
#include <cctype>
#include <cmath>
using namespace std;

const int maxn = 22;
int map [maxn][maxn];
int vis[maxn][maxn][maxn];
int m,n,k,ans;

int xxx[]={0,0,1,-1};
int yyy[]={1,-1,0,0};
struct node {
    int x;
    int y;
    int cnt;
    int k;
    
    node(int x=0,int y=0,int cnt=0,int k=0):x(x),y(y),cnt(cnt),k(k){}
};

void init(){
    memset(map, 0, sizeof(map));
    memset(vis, 0, sizeof(vis));
    cin>>m>>n>>k;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin>>map[i][j];
        }
    }
    
}

void bfs(){
    queue<node>nodes;
    node u(0,0,0,k);
    vis[0][0][k] = 1;
    nodes.push(u);
    node begin;
    while (!nodes.empty()) {
        begin = nodes.front();
        nodes.pop();
        
        if (begin.x == m-1 && begin.y == n-1) {
            ans = begin.cnt;
            return;
        }
        
        node end;
        for (int i = 0; i < 4; i++) {
            int tx = begin.x + xxx[i];
            int ty = begin.y + yyy[i];
            end.x = tx;
            end.y = ty;
            end.cnt = begin.cnt + 1;
            if (map[tx][ty]) {
                end.k = begin.k - 1;
            } else {
                end.k = k;
            }
            
            if (tx >= 0 && tx < m && ty >= 0 && ty < n && !vis[tx][ty][end.k] ) {
                if (end.k >= 0) {
                    nodes.push(end);
                    vis[tx][ty][end.k] = 1;
                }
            }
        }
    }
    if (nodes.empty()) {
        ans = -1;
    }
}

int main() {
    int times;
    cin>>times;
    while (times--) {
        init();
        bfs();
        cout<<ans<<endl;
    }
}