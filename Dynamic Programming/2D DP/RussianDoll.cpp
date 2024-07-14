#include<bits/stdc++.h>
using namespace std;

class cmp {
public:
    bool operator()(vector<int>& a, vector<int>& b) {
        if (a[0] == b[0]) {
            return a[1] > b[1];
        }
        return a[0] < b[0];  // Sort by width in ascending order, if widths are the same, sort by height in descending order
    }
};

class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        if (envelopes.empty()) return 0;

        sort(envelopes.begin(), envelopes.end(), cmp());
        
        vector<int> dp;
        for (const auto& envelope : envelopes) {
            auto it = lower_bound(dp.begin(), dp.end(), envelope[1]);
            if (it == dp.end()) {
                dp.push_back(envelope[1]);
            } else {
                *it = envelope[1];
            }
        }
        
        return dp.size();
    }
};
 
int main(){

    return 0;
}