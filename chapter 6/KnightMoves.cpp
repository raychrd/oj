//UVA-439 Knight Moves
#include <iostream>
#include <algorithm>
#include <queue>
#include <cstdio>
#include <stack>
#include <cctype>
#include <cmath>
using namespace std;
const int N = 8;
int visited[N][N];
int x1;
int x2;
int y11;
int y2;
const int xxx[8]={-2,-1,1,2,2,1,-1,-2};
const int yyy[8]={1,2,2,1,-1,-2,-2,-1};

struct node {
    int x,y;
    int cnt;
    node(int x = 0,int y = 0,int cnt = 0):x(x),y(y),cnt(cnt){};
    bool operator == (const node& rhs){
        return x == rhs.x && y == rhs.y;
    }
};

void trans(char* s,int &x,int&y) {
    x = s[0] - 'a';
    y = s[1] - '1';
}




int bfs(){
    node begin(x1,y11,0);
    node end(x2,y2);
    
    queue<node> nodes;
    
    nodes.push(begin);
    
    visited[x1][y11] = 1;
    
    while (!nodes.empty()) {
        node temp = nodes.front();
        nodes.pop();
        
        if (temp == end) {
            return temp.cnt;
        } else {
            for (int i = 0; i < 8; i++) {
                int tx = temp.x + xxx[i];
                int ty = temp.y + yyy[i];
                
                if (tx >= 0 && tx < 8 && ty >= 0 && ty < 8 && !visited[tx][ty]) {
                    nodes.push(node(tx,ty,temp.cnt + 1));
                    visited[tx][ty] = 1;
                }
                
            }
        }
    }
    
    
    
    return -1;
}


int main(){
    char start[3];
    char end[3];
    
    
    
    while (cin>>start>>end) {
        trans(start,x1,y11);
        trans(end,x2,y2);
        memset(visited, 0, sizeof(visited));
        int ans = bfs();
        printf("To get from %s to %s takes %d knight moves.\n", start, end, ans);
    }
    
    return 0;
}