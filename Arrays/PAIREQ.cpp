#include <iostream>
using namespace std;


void getAnswer(int a[],int n){
    
    int num[10]={0};
    int count=num[0];
    
    for (int i = 0; i < n; i++) {
        num[a[i]]++;
    }
    
    for(int i=1;i<10;i++){
        count=max(count,num[i]);
    }
    
    cout<<n-count<<endl;
    
}

int main() {
    int q;
    cin>>q;
    
    for (int i = 0; i < q; i++) {
        
        int n;
        cin>>n;
        int* a=new int[n];
        
        for(int j=0;j<n;j++){
            cin>>a[j];
        }
        
        getAnswer(a,n);
        delete []a;
    }
	return 0;
}
