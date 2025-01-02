#include <iostream>
#include <vector>
#include <climits>
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

    // DP table to store minimum product of weights
    std::vector<std::vector<long long>> minProduct(n + 1, std::vector<long long>(target + 1, LLONG_MAX));
    minProduct[0][0] = 1;

    // Fill the DP table
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= target; ++j) {
            if (nums[i - 1] <= j && dp[i - 1][j - nums[i - 1]]) {
                minProduct[i][j] = std::min(minProduct[i][j], minProduct[i - 1][j - nums[i - 1]] * nums[i - 1]);
            }
            minProduct[i][j] = std::min(minProduct[i][j], minProduct[i - 1][j]);
        }
    }

    // Trace back the subset from the DP table
    std::vector<int> result;
    int currTarget = target;
    for (int i = n; i > 0 && currTarget > 0; --i) {
        if (minProduct[i][currTarget] != minProduct[i - 1][currTarget]) { // Current number was included
            result.push_back(nums[i - 1]);
            currTarget -= nums[i - 1];
        }
    }

    return result;
}