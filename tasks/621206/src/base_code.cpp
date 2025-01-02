#include <iostream>
#include <vector>
using namespace std;


std::vector<int> subsetSum(const std::vector<int>& nums, int target) {
    int n = nums.size();

    // DP table to store possible subset sums
    std::vector<std::vector<bool>> dp(n + 1, std::vector<bool>(target + 1, false));

    // Base case: Subset with sum 0 is always possible (empty set)
    for (int i = 0; i <= n; ++i) {
        dp[i][0] = true;
    }

    // Fill the DP table
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= target; ++j) {
            dp[i][j] = dp[i - 1][j]; // Exclude current number
            if (nums[i - 1] <= j) { // Include current number if it fits
                dp[i][j] = dp[i][j] || dp[i - 1][j - nums[i - 1]];
            }
        }
    }

    // If no subset sums to the target, return an empty vector
    if (!dp[n][target]) {
        return {};
    }

    // Trace back the subset from the DP table
    std::vector<int> result;
    int currTarget = target;
    for (int i = n; i > 0 && currTarget > 0; --i) {
        if (!dp[i - 1][currTarget]) { // Current number was included
            result.push_back(nums[i - 1]);
            currTarget -= nums[i - 1];
        }
    }

    return result;
}