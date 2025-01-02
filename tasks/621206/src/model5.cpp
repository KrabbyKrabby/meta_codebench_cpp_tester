#include <iostream>
#include <vector>
#include <climits>
using namespace std;

vector<int> subsetSum(const vector<int>& nums, int target) {
    int n = nums.size();
    
    // DP tables for possibility and minimum products
    vector<vector<bool>> dp_possible(n + 1, vector<bool>(target + 1, false));
    vector<vector<long long>> dp_product(n + 1, vector<long long>(target + 1, LLONG_MAX));
    
    // Base case: empty subset sums to 0
    for (int i = 0; i <= n; ++i) {
        dp_possible[i][0] = true;
        dp_product[i][0] = 1; // Product of empty set is 1
    }
    
    // Fill the DP tables
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j <= target; ++j) {
            // Don't include current number
            dp_possible[i][j] = dp_possible[i-1][j];
            if (dp_possible[i-1][j]) {
                dp_product[i][j] = dp_product[i-1][j];
            }
            
            // Include current number if possible
            if (j >= nums[i-1] && dp_possible[i-1][j-nums[i-1]]) {
                dp_possible[i][j] = true;
                if (dp_product[i-1][j-nums[i-1]] != LLONG_MAX) {
                    long long new_product = dp_product[i-1][j-nums[i-1]] * nums[i-1];
                    // Check for overflow
                    if (new_product / nums[i-1] == dp_product[i-1][j-nums[i-1]]) {
                        dp_product[i][j] = min(dp_product[i][j], new_product);
                    }
                }
            }
        }
    }
    
    // If no valid subset exists
    if (!dp_possible[n][target]) {
        return {};
    }
    
    // Reconstruct the subset with minimum product
    vector<int> result;
    int curr_sum = target;
    for (int i = n; i > 0 && curr_sum > 0; --i) {
        if (curr_sum >= nums[i-1] && dp_possible[i-1][curr_sum-nums[i-1]] &&
            dp_product[i-1][curr_sum-nums[i-1]] != LLONG_MAX &&
            dp_product[i][curr_sum] == dp_product[i-1][curr_sum-nums[i-1]] * nums[i-1]) {
            result.push_back(nums[i-1]);
            curr_sum -= nums[i-1];
        }
    }
    
    return result;
}