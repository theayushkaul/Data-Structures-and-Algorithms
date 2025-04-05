#include<bits/stdc++.h>
using namespace std;

// Segment Trees are used to solve range based problems
int a[100005], seg[4*100005], lazy[4*100005];

// Build on the basis if we need maximum in a range
void build(int index, int start, int end){
    if(start == end){
        seg[index] = a[start];
    }
    int mid= (start + end)/2;
    build(2*index + 1,start,mid);
    build(2*index + 2,mid + 1, end);

    seg[index] = max(seg[2*index + 1], seg[2*index + 2]);
}

// Querying the segment tree
int query(int index, int low, int high, int l, int r){
    // Completely overlaps
    if(low >= l && high <= r){
        return seg[index];
    }
    // Doesn't lie in the range
    if(high < l  || low > r) return INT_MIN;

    int mid = (low + high)/2;
    int left = query(2*index + 1,low,mid,l,r);
    int right = query(2*index + 2,mid,high,l,r);

    return max(left,right);
}

// Updation of arr[index]  = arr[index] + X
// For sum not max 
void pointUpdate(int index, int low, int high, int node, int val){
    if(low == high){
        seg[low] += val;
    }else{
        int mid = (low + high) >> 1;
        if(node <= mid && node >= low) pointUpdate(2*index + 1, low,mid,node,val);
        else pointUpdate(2*index + 2, mid + 1, high, node,val);

        seg[index] = seg[2*index + 1] + seg[2*index + 2];
    }
}

// Lazy Propagation: Suspend updates in present and update in future
// l, r -> range to increase value with val.
void rangeUpdate(int ind, int low, int high, int l, int r, int val) {
    if (lazy[ind] != 0) {
        seg[ind] += (high - low + 1) * lazy[ind];
        if (low != high) {
            lazy[2 * ind + 1] += lazy[ind];
            lazy[2 * ind + 2] += lazy[ind];
        }
        lazy[ind] = 0;
    }

    if (r < low || l > high || low > high) return;

    if (low >= l && high <= r) {
        seg[ind] += (high - low + 1) * val;
        if (low != high) {
            lazy[2 * ind + 1] += val;
            lazy[2 * ind + 2] += val;
        }
        return;
    }

    int mid = (low + high) >> 1;
    rangeUpdate(2 * ind + 1, low, mid, l, r, val);
    rangeUpdate(2 * ind + 2, mid + 1, high, l, r, val);
    seg[ind] = seg[2 * ind + 1] + seg[2 * ind + 2];
}

int querySumLazy(int ind, int low, int high, int l, int r) {
    if (lazy[ind] != 0) {
        seg[ind] += (high - low + 1) * lazy[ind];
        if (low != high) {
            lazy[2 * ind + 1] += lazy[ind];
            lazy[2 * ind + 2] += lazy[ind];
        }
        lazy[ind] = 0;
    }

    if (r < low || l > high || low > high) return 0;

    if (low >= l && high <= r) {
        return seg[ind];
    }

    int mid = (low + high) >> 1;
    return querySumLazy(2 * ind + 1, low, mid, l, r) +
           querySumLazy(2 * ind + 2, mid + 1, high, l, r);
}

int main(){
    int n;
    cin>>n;
    for(int i=0; i<n;i++){
        cin>>a[i];
    }

    build(0,0,n-1);

    // Get the queries from the user
    int q;
    cin>>q;
    while(q--){
        int l, r;
        cin>>l>>r;
    }
    return 0;
}