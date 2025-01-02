#include <iostream>
#include <vector>
#include <climits>
using namespace std;

vector<int> subsetSum(const vector<int>& nums, int target) {
    int n = nums.size();
    
    // DP table to store {possible, min_product}
    vector<vector<pair<bool, long long>>> dp(n + 1, 
        vector<pair<bool, long long>>(target + 1, {false, LLONG_MAX}));
    
    // Base case: Empty subset for sum 0
    for (int i = 0; i <= n; ++i) {
        dp[i][0] = {true, 1};
    }
    
    // Fill the DP table
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= target; ++j) {
            // Exclude current number
            dp[i][j] = dp[i - 1][j];
            
            // Include current number if it fits
            if (nums[i - 1] <= j && dp[i - 1][j - nums[i - 1]].first) {
                bool possible = true;
                long long new_product = dp[i - 1][j - nums[i - 1]].second;
                
                // Check for overflow
                if (new_product != LLONG_MAX && 
                    new_product <= LLONG_MAX / nums[i - 1]) {
                    new_product *= nums[i - 1];
                    
                    // Update if new product is smaller
                    if (!dp[i][j].first || new_product < dp[i][j].second) {
                        dp[i][j] = {true, new_product};
                    }
                }
            }
        }
    }
    
    // If no valid subset exists
    if (!dp[n][target].first) {
        return {};
    }
    
    // Trace back to find the subset
    vector<int> result;
    int currTarget = target;
    for (int i = n; i > 0 && currTarget > 0; --i) {
        // Check if current number was included
        if (currTarget >= nums[i - 1] && 
            dp[i - 1][currTarget - nums[i - 1]].first && 
            dp[i][currTarget].second == 
            dp[i - 1][currTarget - nums[i - 1]].second * nums[i - 1]) {
            result.push_back(nums[i - 1]);
            currTarget -= nums[i - 1];
        }
    }
    
    return result;
}