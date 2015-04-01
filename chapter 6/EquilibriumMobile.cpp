//UVA-12166 Equilibrium Mobile
#include <iostream>
#include <algorithm>
#include <queue>
#include <cstdio>
#include <stack>
#include <cctype>
#include <cmath>
#include <map>
using namespace std;
string line;
map<long long, int> base;
int sum;//叶子总数

//std::ios::sync_with_stdio(false);
//std::cin.tie(0);

void dfs(int depth,int s,int e) {
    if (line[s] == '[') {
        int p = 0;
        for (int i = s + 1; i != e; i++) {
            if (line[i] == '[') {
                ++p;
            }
            if (line[i] == ']') {
                --p;
            }
            if (p == 0 && line[i] == ',') { //用,来限制循环次数，每次遇到,DFS,左右
                dfs(depth + 1, s + 1, i - 1);
                dfs(depth + 1, i + 1, e - 1);
            }
        }
    } else {
        long long w = 0;
        for (int i = s; i <= e; i++) {
            w = w * 10 + line[i] - '0';
        }
        sum++;
        base[w << depth]++;
        
    }
}

int main(){
    ios::sync_with_stdio(false);
    
    int T;
    cin>>T;
    while (T--) {
        cin>>line;
        base.clear();
        sum = 0;
        
        dfs(0, 0, line.size() - 1);
        
        int maxn = 0;
        
        for (auto it = base.begin(); it != base.end(); it++) {
            maxn = max(maxn,it -> second);
            
        }
        
        cout << sum - maxn << endl;
        
        
    }
}

/*
 thanks to KWY-Q

 给出数个天平，每个天平的结构都类似于二叉树，只有左右重量都相等时才平衡，求每个天平最少改多少个秤砣，也就是叶子结点可以使得整个天平平衡。天平的深度不超过16。
 　　要使得改动的数量最少，那么就至少有一个秤砣不变，然后以这个秤砣为基准来调整整个天平。天平的结构是二叉树，那么由此我们可以得出，如果以深度为d重量为w的秤砣为基准，那么整个天平的重量就是w * pow(2, d)，即w << d。
 　　当然，可能会有一些秤砣算出的以各自为基准的天平总重量相同，设天平总重量为sumw，那么这些秤砣的数量就表示了如果使天平的总重量为sumw需要使多少个秤砣保持不变。
 　　基于上面的想法，就可以得到算法了。求出所有可能的sumw值以及其对应的秤砣数量，然后在这些sumw值中找到保持不变的秤砣数量中的最大值，设为maxn，设秤砣总数量为sum。那么sum - maxn即为所求。
 　　为了求出sumw对应的秤砣数量，这里用到了STL里的map结构，设为base，那么base[x]表示使天平的重量为x时保持不变的秤砣的数量。在建树时，每当扫描到叶子结点，即秤砣时，算出对应的sumw值，然后另base[sumw]自增1，这样所有的叶子节点都扫完之后，所有可能的sumw值也就算完了。接下来就只需要遍历一遍，找出最大值即可了。
*/
