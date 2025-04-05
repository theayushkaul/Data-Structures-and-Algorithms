#include<bits/stdc++.h>
using namespace std;

// (1<<i): 
// (1>>i): 
class fenTree{
    int n;
    vector<int> fen;
    public:
    fenTree(int n){
        this->n = n;
    }
    void sum(){

    }
    void update(){

    }
    int lowerBound(int k){
        int curr = 0, ans = 0, prevSum = 0;
        for(int i = log2(n);i>=0;i--){
            if(fen[curr + (1<<i)] + prevSum < k){
                curr = curr + (1<<i);
                prevSum += fen[curr];
            }
        }

        return (curr + 1);
    }
};

int main(){

    return 0;
}