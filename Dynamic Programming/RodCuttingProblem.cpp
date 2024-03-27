#include<bits/stdc++.h>
using namespace std;

// Dp[i]: i length of rod ke maximum segments kitne hoskte hai

// Using Tabulation
int solve(int n, int x, int y, int z){
	vector<int> dp(n+1,INT_MIN);
	dp[0] = 0;
	for(int i = 1; i<=n;i++){
		if(i-x>=0){
			dp[i] = max(dp[i],dp[i-x]+1);
		}
		if(i-y>=0){
			dp[i] = max(dp[i],dp[i-y]+1);
		}
		if(i-z>=0){
			dp[i] = max(dp[i],dp[i-z]+1);
		}
	}
	if(dp[n]<0){
		return 0;
	}
	return dp[n];

}
// Using Memoization
int solve(int n, int x, int y, int z,vector<int>& dp){
	if(n == 0){
		return 0;
	}
	if(n<0){
		return INT_MIN;
	}

	if(dp[n] != -1){
		return dp[n];
	}
	
	int ifX = solve(n-x, x, y, z, dp);
	int ifZ = solve(n-z, x, y, z, dp);
	int ifY = solve(n-y, x, y, z, dp);

	dp[n] = max(ifX,max(ifZ,ifY))+1;
	return dp[n];
}
// Using Recurrsion:
int solve(int n, int x, int y, int z){
	if(n == 0){
		return 0;
	}
	if(n<0){
		return INT_MIN;
	}
	int ifX = solve(n-x, x, y, z);
	int ifZ = solve(n-z, x, y, z);
	int ifY = solve(n-y, x, y, z);

	return max(ifX,max(ifZ,ifY))+1;
}
int cutSegments(int n, int x, int y, int z) {
    // For Memoization: vector<int> dp(n+1,-1);
    // int ans = solve(n,x,y,z,dp);
	int ans = solve(n,x,y,z);
	if(ans<0){
		return 0;
	}

	return ans;
}
int main(){

    return 0;
}