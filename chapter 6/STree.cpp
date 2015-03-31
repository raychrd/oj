//UVA-712 S-Trees
#include <iostream>
#include <algorithm>
#include <queue>
#include <cstdio>
#include <stack>
#include <cctype>
#include <cmath>
using namespace std;
int order[10];
int lefts[130];
int ans[10];
int xi[10];
int finalorder[10];
inline void init(){
    memset(order, 0, sizeof(order));
    memset(lefts, -1, sizeof(lefts));
    memset(ans, -1, sizeof(ans));
    memset(xi, -1, sizeof(xi));
}
int main(){
    int depth = 0;
    int sizeofxi = 1;
    int queries = 0;
    int order_i = 0;
    while (scanf("%d",&depth) && depth) {
        int times = 1<<depth;
        init();
        
        string temp;
        cin.ignore();
        getline(cin, temp);
        
        
        for (size_t i = 0,sz = temp.length(); i < sz; i++) {
            if (isdigit(temp[i])) {
                order[++order_i] = temp[i]-'0';
            }
        }
        
        getline(cin, temp);
        for (int i = 0; i < times; i++) {
            lefts[i] = temp[i] - '0';
        }
        
        //getline(cin, temp);
        
        scanf("%d",&queries);
        
        getchar();
        
        for (int i = 0; i < queries; i++) {
            
            getline(cin, temp);
            
            for (int i = 0; i < depth; i++) {
                xi[i+1] = temp[i] - '0';
            }
            
            //xi value of x0-xn
            for (int i = 1; i <= depth; i++) {
                finalorder[i] = xi[order[i]];
            }
            
            int answer = 0;
            for (int i = 0; i < depth; i++) {
                answer += finalorder[i+1] * (int)pow(2.0, depth-i-1);
            }
            
            ans[i] = lefts[answer];
            
        }
        
        cout<<"S-Tree #"<<order_i++<<endl;
        for (int i = 0; i < queries; i++) {
            printf("%d",ans[i]);
        }
        cout<<endl;
        cout<<endl;
    }
   
    return 0;
}