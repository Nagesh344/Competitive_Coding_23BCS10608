class Solution {
public:
    vector<int>dp;
    int solve(int i, vector<int>& arr, int k) {
        int n = arr.size();
        if (i == n) return 0;  
        if(dp[i]!=-1) return dp[i];      
        int maxi = 0;
        int ans = 0;
        for (int j = i; j < min(n, i + k); j++) {
            maxi = max(maxi, arr[j]);            
            int len = j - i + 1;
            int sum = maxi * len + solve(j + 1, arr, k);            
            ans = max(ans, sum);
        }        
        return dp[i]=ans;
    }

    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        dp.resize(arr.size(),-1);
        return solve(0, arr, k);
    }
};
