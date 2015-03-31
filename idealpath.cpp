//HDU 3760 UVA 1599
#include <iostream>
#include <algorithm>
#include <queue>
#include <cstdio>


using namespace std;
const int INF = 1000000000;
const int MAX = 210000;
int m,n;
vector<int> uv[MAX];
int ans [MAX];
int dis [MAX];


bool visited[MAX];
//int color [MAX][MAX];
vector<int> color[MAX];
int prehead[MAX];

void init(){
    for (int i = 0; i < MAX; i++) {
        uv[i].clear();
        color[i].clear();
        
    }
    memset(dis, -1, sizeof(dis));
    memset(ans, 0, sizeof(ans));
    memset(visited, false, sizeof(visited));
    memset(prehead, -1, sizeof(prehead));
}




void bfs1(){
    queue<int>q;
    q.push(n);
    //visited[n] = true;
    dis[n] = 0;
    
    while (!q.empty()) {
        
        int u = q.front();
        
        q.pop();
        
        int tailsize = (int)uv[u].size();
        
        for (int i = 0; i < tailsize; i++) {
            
            int v = uv[u][i];
            /*
            if (v == 1) {
                dis[1]=dis[u] + 1;
                return;
            }
            */
            if (dis[v] == -1) {
                
                dis[v] = dis[u] + 1;
                if (v == 1) {
                    return;
                }
                //visited[v] = true;
                q.push(v);
            }
        }
    }
    
}
void bfs2(){
    
    queue<int>q;
    q.push(1);
    
    int mincolor = INF;
    
    while (!q.empty()) {
        int head = q.front();
        if (head == 1) {
            q.pop();
        } else {
            //pop
            
            int status = false;
            for (size_t i = 0,sz = uv[head].size(); i < sz; i++) {
                int tmpans = color[head][i];
                if (tmpans == ans[dis[1]-dis[prehead[head]]] && dis[uv[head][i]] == dis[head]+1) {
                    status = true;
                    break;
                }
            }
            
            q.pop();
            if (!status) {
                continue;
            }
            
        }
        mincolor = INF;
        
        if (dis[head] == 0) {
            return;
        }
        
        int headsize = (int)uv[head].size();
        
        for (int i = 0; i < headsize; i++) {
            int v = uv[head][i];
            
            if (dis[v] == dis[head] - 1 && color[head][i] < mincolor) {
                mincolor = color[head][i];
            }
        }
        
        int a = dis[1]-dis[head];
        if (ans[a] == 0) {
            ans[a] = mincolor;
        } else {
            ans[a] = min(ans[a], mincolor);
        }
        
        //ans.push_back(mincolor);
        
        for (int i = 0; i < headsize; i++) {
            int t = uv[head][i];
            if (visited[t] == false && dis[t] == dis[head] - 1 && color[head][i] ==mincolor) {
                q.push(t);
                prehead[t] = head;
                visited[t] = true;
            }
        }
        
    }
}
int main()
{
    
    int tu,tv,tc;
    int time;
    scanf("%d",&time);
    while (time--) {
        scanf("%d %d",&n,&m);
        init();
        for (int j = 1; j <= m; j++) {
            scanf("%d %d %d",&tu,&tv,&tc);
            
            uv[tu].push_back(tv);
            uv[tv].push_back(tu);
            color[tu].push_back(tc);
            color[tv].push_back(tc);
        }
        bfs1();
        bfs2();
        printf("%d\n",dis[1]);
        for (int i = 0; i < dis[1]; i++) {
            printf("%d",ans[i]);
            if (i != dis[1]-1) {
                printf(" ");
            }
        }
        printf("\n");
    }
    /*
    while (scanf("%d %d",&n,&m) != EOF) {
        init();
        for (int j = 1; j <= m; j++) {
            scanf("%d %d %d",&tu,&tv,&tc);
            
                uv[tu].push_back(tv);
                uv[tv].push_back(tu);
                color[tu].push_back(tc);
                color[tv].push_back(tc);
        }
        bfs1();
        bfs2();
        printf("%d\n",dis[1]);
        for (int i = 0; i < dis[1]; i++) {
            printf("%d",ans[i]);
            if (i != dis[1]-1) {
                printf(" ");
            }
        }
        printf("\n");
    }
    */
    
    return 0;
}

