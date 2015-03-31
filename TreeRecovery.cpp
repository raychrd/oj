//UVA-536 Tree Recovery
#include <iostream>
#include <algorithm>
#include <queue>
#include <cstdio>
#include <stack>
#include <cctype>
#include <cmath>
using namespace std;

void solve(char *pre,char *in,int length){
    if (length == 0) {
        return;
    }
    
    char head = pre[0];
    
    int rootIndex = 0;
    
    for (int i = 0; i < length; i++) {
        if (in[i] == head) {
            rootIndex = i;
            break;
        }
    }
    
    solve(pre + 1, in, rootIndex);
    solve(pre + rootIndex +1, in + rootIndex + 1, length - rootIndex -1);
    
    cout<<head;
}

int main(){
    string a,b;
    char pre[60];
    char in[60];
    while (cin>>a>>b) {
        strcpy(pre, a.c_str());
        strcpy(in, b.c_str());
        solve(pre, in, (int)a.length());
        cout<<endl;
    }
    return 0;
}
