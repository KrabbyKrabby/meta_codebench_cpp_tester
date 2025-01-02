#include <iostream>
#include <vector>
#include <climits>
using namespace std;

vector<int> subsetSum(const vector<int>& nums, int target) {
    int n = nums.size();
    
    // DP tables for sums and products
    vector<vector<bool>> dp(n + 1, vector<bool>(target + 1, false));
    vector<vector<long long>> products(n + 1, vector<long long>(target + 1, LLONG_MAX));
    
    // Base case: empty subset sums to 0
    for (int i = 0; i <= n; ++i) {
        dp[i][0] = true;
        products[i][0] = 1;  // Product of empty set is 1
    }
    
    // Fill the DP tables
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j <= target; ++j) {
            // Exclude current number
            dp[i][j] = dp[i-1][j];
            if (dp[i-1][j]) {
                products[i][j] = products[i-1][j];
            }
            
            // Include current number if possible
            if (j >= nums[i-1] && dp[i-1][j-nums[i-1]]) {
                dp[i][j] = true;
                long long newProduct = products[i-1][j-nums[i-1]] == LLONG_MAX ? 
                                     LLONG_MAX : 
                                     products[i-1][j-nums[i-1]] * nums[i-1];
                                     
                if (newProduct < products[i][j]) {
                    products[i][j] = newProduct;
                }
            }
        }
    }
    
    // If no valid subset exists
    if (!dp[n][target]) {
        return {};
    }
    
    // Trace back to find the subset with minimum product
    vector<int> result;
    int currSum = target;
    for (int i = n; i > 0 && currSum > 0; --i) {
        if (currSum >= nums[i-1] && dp[i-1][currSum-nums[i-1]]) {
            long long productWithCurrent = products[i-1][currSum-nums[i-1]] == LLONG_MAX ? 
                                         LLONG_MAX : 
                                         products[i-1][currSum-nums[i-1]] * nums[i-1];
            
            if (productWithCurrent == products[i][currSum]) {
                result.push_back(nums[i-1]);
                currSum -= nums[i-1];
            }
        }
    }
    
    return result;
}