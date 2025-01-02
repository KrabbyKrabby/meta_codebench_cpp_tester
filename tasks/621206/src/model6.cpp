#include <iostream>
#include <vector>
#include <limits>
using namespace std;

std::vector<int> subsetSum(const std::vector<int>& nums, int target) {
    int n = nums.size();

    // DP table to store possible subset sums
    std::vector<std::vector<bool>> dp(n + 1, std::vector<bool>(target + 1, false));

    // DP table to store minimum product of weights for each subset sum
    std::vector<std::vector<long long>> minProduct(n + 1, std::vector<long long>(target + 1, std::numeric_limits<long long>::max()));

    // Base case: Subset with sum 0 is always possible (empty set)
    for (int i = 0; i <= n; ++i) {
        dp[i][0] = true;
        minProduct[i][0] = 1;  // Minimum product for sum 0 is 1 (empty set)
    }

    // Fill the DP tables
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= target; ++j) {
            dp[i][j] = dp[i - 1][j]; // Exclude current number
            if (nums[i - 1] <= j) { // Include current number if it fits
                dp[i][j] = dp[i][j] || dp[i - 1][j - nums[i - 1]];
            }

            // Update minimum product
            if (dp[i][j]) {
                if (nums[i - 1] <= j && dp[i - 1][j - nums[i - 1]]) {
                    minProduct[i][j] = std::min(minProduct[i][j], minProduct[i - 1][j - nums[i - 1]] * nums[i - 1]);
                }
                minProduct[i][j] = std::min(minProduct[i][j], minProduct[i - 1][j]);
            }
        }
    }

    // If no subset sums to the target, return an empty vector
    if (!dp[n][target]) {
        return {};
    }

    // Trace back the subset from the DP tables
    std::vector<int> result;
    int currTarget = target;
    for (int i = n; i > 0 && currTarget > 0; --i) {
        if (currTarget >= nums[i - 1] && minProduct[i][currTarget] == minProduct[i - 1][currTarget - nums[i - 1]] * nums[i - 1]) {
            result.push_back(nums[i - 1]);
            currTarget -= nums[i - 1];
        }
    }

    return result;
}