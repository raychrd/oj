//UVA-673
#include <iostream>
#include <algorithm>
#include <queue>
#include <cstdio>
#include <stack>
using namespace std;

int main(){
    int times = 0;
    cin>>times;
    cin.ignore();
    while (times--) {
        stack<char> base;
        string temp;
        getline(cin, temp);
        
        //case1
        if (temp.empty()) {
            cout<<"Yes"<<endl;
        } else {
            
            for (size_t i = 0,sz = temp.length(); i < sz; i++) {
                char t = temp[i];
                
                if (t == '(' || t == '[') {
                    base.push(temp[i]);
                } else {
                    if (!base.empty()) {
                        char ch = base.top();
                        if ((t == ')' && ch == '(') || (t == ']' && ch == '[')) {
                            base.pop();
                        } else {
                            base.push(t);
                        }
                        
                    } else {
                        base.push(t);
                    }
                }
            }
            
            if (base.empty()) {
                cout<<"Yes"<<endl;
            } else {
                cout<<"No"<<endl;
            }
        }
    }
    return 0;
}