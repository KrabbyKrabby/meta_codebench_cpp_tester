#include <iostream>
#include <vector>
#include <utility>
#include <climits>

std::vector<int> subsetSum(const std::vector<int>& nums, int target) {
    int n = nums.size();
    using ll = long long;
    
    // DP table stores {is_possible, min_product}
    std::vector<std::vector<std::pair<bool, ll>>> dp(n + 1, 
        std::vector<std::pair<bool, ll>>(target + 1, {false, LLONG_MAX}));
    
    // Base case: empty subset sums to 0
    for (int i = 0; i <= n; ++i) {
        dp[i][0] = {true, 1};
    }
    
    // Fill the DP table
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= target; ++j) {
            // First, copy the state without including current number
            dp[i][j] = dp[i - 1][j];
            
            // Try including current number if it fits
            if (nums[i - 1] <= j && dp[i - 1][j - nums[i - 1]].first) {
                bool possible = true;
                ll new_product = dp[i - 1][j - nums[i - 1]].second;
                
                // Check for overflow
                if (new_product != LLONG_MAX && 
                    new_product <= LLONG_MAX / nums[i - 1]) {
                    new_product *= nums[i - 1];
                    
                    // Update if this gives a better product or if previous wasn't possible
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
    
    // Trace back to find the subset with minimum product
    std::vector<int> result;
    int curr_target = target;
    for (int i = n; i > 0 && curr_target > 0; --i) {
        // Check if current number was included in minimum product path
        ll prod_with = LLONG_MAX;
        if (nums[i - 1] <= curr_target && dp[i - 1][curr_target - nums[i - 1]].first) {
            prod_with = dp[i - 1][curr_target - nums[i - 1]].second * nums[i - 1];
        }
        
        if (prod_with == dp[i][curr_target].second) {
            result.push_back(nums[i - 1]);
            curr_target -= nums[i - 1];
        }
    }
    
    return result;
}