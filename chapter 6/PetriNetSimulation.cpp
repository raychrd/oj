//UVa 804 - Petri Net Simulation
//almost did it in one :P
//Happy April Fools' Day!
//I really (almost) figure it out in one

#include <iostream>
#include <algorithm>
#include <queue>
#include <cstdio>
#include <stack>
#include <cctype>
#include <cmath>
#include <map>
#include <sstream>
using namespace std;

//std::ios::sync_with_stdio(false);
//std::cin.tie(0);

const int N = 108;

bool runable[N];

struct node {
    vector<int> input;
    int inputarray[N] = {0};
    vector<int> output;
    int outputarray[N] = {0};
    node(int in=0,int out=0):input(in),output(out){};
};

vector<node> NT;
int NP[N];
string temp;
int times;
int cycletimes = 1;
void init() {
    NT.clear();
    memset(NP, 0, sizeof(NP));
    memset(runable, false, sizeof(runable));
}

bool check(node &a) {
    int status = false;
    for (int i = 0; i < N; i++) {
        if (a.inputarray[i] > NP[i]) {
            status = true;
            break;
        }
    }
    
    if (status) {
        return false;
    } else {
        return true;
    }
    
}

void checkall() {
    vector<node>::iterator it = NT.begin();
    while (it != NT.end()) {
        bool ans = check(*it);
        if (ans) {
            runable[it - NT.begin() + 1] = true;
        } else {
            runable[it - NT.begin() + 1] = false;
        }
        it++;
    }
}

bool stillCanRun() {
    for (int i = 0; i < N; i++) {
        if (runable[i]) {
            return true;
            break;
        }
    }
    return false;
}

void run() {
    vector<node>::iterator it = NT.begin();
    node a;
    while (it != NT.end()) {
        if (check(*it)) {
            a = *it;
            break;
        }
        it++;
    }
    for (int i = 0; i < N; i++) {
        NP[i] -= a.inputarray[i];
        NP[i] += a.outputarray[i];
    }
}

int main() {
    /*
    2
    1 0
    2
    -1 2 0
    -2 1 0
    100
     */
    int np,nt;
    
    while (cin>>np && np!=0) {               //np
        init();                              //initialize
        for (int i = 1; i <= np; i++) {
            cin>>NP[i];                      //place
        }
        cin>>nt;                             //nt
        
        for (int i = 0; i < nt; i++) {       //transition
            node a(0,0);
            int tnum;
            while (cin>>tnum && tnum != 0) {
                if (tnum > 0) {
                    a.output.push_back(tnum);
                    a.outputarray[tnum] += 1;
                } else {
                    a.input.push_back(tnum * -1);
                    a.inputarray[tnum * -1] += 1;
                }
            }
            NT.push_back(a);
        }
        
        cin>>times;
        checkall();
        
        bool isCompleted = true;
        int ttttt = times;
        
        
        printf("Case %d: ",cycletimes++);
        while (ttttt--) {
            if (stillCanRun()) {
                run();
                checkall();
            } else {
                isCompleted = false;
                printf("dead after %d transitions\n",times - ttttt -1);
                break;
            }
            
        }
        
        if (isCompleted) {
            printf("still live after %d transitions\n",times);
        }
        
        printf("Places with tokens: ");
        for (int i = 0; i < N; i++) {
            if (NP[i] > 0) {
                printf("%d (%d) ",i,NP[i]);
            }
        }
        printf("\n\n");
    }
    
}
