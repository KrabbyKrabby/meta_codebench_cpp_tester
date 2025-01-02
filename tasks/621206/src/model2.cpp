#include <iostream>
#include <vector>
#include <limits>
#include <utility>

std::vector<int> subsetSum(const std::vector<int>& nums, int target) {
    int n = nums.size();
    using ll = long long;
    const ll INF = std::numeric_limits<ll>::max();
    
    // DP table stores {possible, min_product}
    std::vector<std::vector<std::pair<bool, ll>>> dp(n + 1, 
        std::vector<std::pair<bool, ll>>(target + 1, {false, INF}));
    
    // Base case: empty subset for sum 0
    for (int i = 0; i <= n; ++i) {
        dp[i][0] = {true, 1};
    }
    
    // Fill the DP table
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= target; ++j) {
            // Copy state from excluding current number
            dp[i][j] = dp[i - 1][j];
            
            if (nums[i - 1] <= j && dp[i - 1][j - nums[i - 1]].first) {
                bool possible = true;
                ll new_product = dp[i - 1][j - nums[i - 1]].second;
                
                // Check for overflow
                if (new_product != INF && new_product <= INF / nums[i - 1]) {
                    new_product *= nums[i - 1];
                    
                    // Update if new product is smaller or if current state was impossible
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
    int curr_sum = target;
    for (int i = n; i > 0 && curr_sum > 0; --i) {
        if (curr_sum >= nums[i-1]) {
            ll prod_with = dp[i-1][curr_sum - nums[i-1]].second;
            if (prod_with != INF && prod_with <= INF / nums[i-1]) {
                prod_with *= nums[i-1];
                if (dp[i-1][curr_sum].first) {
                    if (prod_with < dp[i-1][curr_sum].second) {
                        result.push_back(nums[i-1]);
                        curr_sum -= nums[i-1];
                    }
                } else {
                    result.push_back(nums[i-1]);
                    curr_sum -= nums[i-1];
                }
            }
        }
    }
    
    return result;
}