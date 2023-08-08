#include <iostream>
using namespace std;

int noCoins(int height){
    // Gives the number of coins for a certain height
    int sum=0;
    for(int i=1;i<=height;i++){
        sum+=i;
    }
    return sum;
}

int heightofTriangle(int n){
    int ans;
    int s=2,e=n;
    while(s<=e){
        int mid=(s+e)/2;
        if(noCoins(mid)==n){
            ans=mid;
            break;
        }
        else if(noCoins(mid)<n){
            ans=mid;
            s=mid+1;
        }
        else{
            e=mid-1;
        }
    }
    
    return ans;
}

int main() {
    int q;
    cin>>q;
    for(int i=0;i<q;i++){
        int num;
        cin>>num;
        cout<<heightofTriangle(num)<<endl;
    }
	return 0;
}