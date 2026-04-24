#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);

        // Step 1: Coordinate Compression
        vector<int> temp = nums;
        sort(temp.begin(), temp.end());

        unordered_map<int, int> rank;
        for (int i = 0; i < n; i++) {
            rank[temp[i]] = i + 1;  // 1-based indexing
        }

        // Fenwick Tree
        vector<int> BIT(n + 1, 0);

        // Step 2: Traverse from right
        for (int i = n - 1; i >= 0; i--) {
            int r = rank[nums[i]];

            // count of smaller elements
            ans[i] = query(BIT, r - 1);

            // update current element
            update(BIT, r);
        }

        return ans;
    }

    void update(vector<int>& BIT, int i) {
        while (i < BIT.size()) {
            BIT[i] += 1;
            i += i & -i;
        }
    }

    int query(vector<int>& BIT, int i) {
        int sum = 0;
        while (i > 0) {
            sum += BIT[i];
            i -= i & -i;
        }
        return sum;
    }
};
