void rotate(vector<int>& a, int k) {
        
        int n=a.size();
       vector<int> temp(n);
        for(int i=0;i<n;i++){
            temp[(i+k)%n]=a[i];
        }
        
//         Copy in a
        for(int i=0;i<n;i++){
            a[i]=temp[i];
        }
    }