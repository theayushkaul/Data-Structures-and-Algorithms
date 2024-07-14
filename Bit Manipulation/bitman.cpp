#include<bits/stdc++.h>
using namespace std;

int getBit(int n, int pos){
    return ((n & (1<<pos)) != 0);
}

int setBit(int n, int pos){
    return ((n | (1<<pos)));
}

int clearBit(int n, int pos){
    return (n & ~(1<<pos));
}

int updateBit(int n, int pos, int val){
    int mask = ~(1<<pos);
    n = n & mask;

    // val: can be 0 or 1
    // first: clear the bit then set the bit to the val
    return (n | (val << pos)); 
}

int main(){

    return 0;
}