#include <iostream>
#include <vector>
#include <climits>
using namespace std;

std::vector<int> subsetSum(const std::vector<int>& nums, int target) {
    int n = nums.size();
    long long INF = LLONG_MAX;

    // DP table to store possible subset sums and minimum product
    std::vector<std::vector<std::pair<bool, long long>>> dp(n + 1, std::vector<std::pair<bool, long long>>(target + 1, {false, INF}));

    // Base case: Subset with sum 0 is always possible (empty set)
    for (int i = 0; i <= n; ++i) {
        dp[i][0] = {true, 1};
    }

    // Fill the DP table
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= target; ++j) {
            dp[i][j] = dp[i - 1][j]; // Exclude current number
            if (nums[i - 1] <= j) { // Include current number if it fits
                if (dp[i - 1][j - nums[i - 1]].first) {
                    long long currProduct = dp[i - 1][j - nums[i - 1]].second * nums[i - 1];
                    if (dp[i][j].first && dp[i][j].second < currProduct) {
                        dp[i][j] = {true, dp[i][j].second};
                    } else {
                        dp[i][j] = {true, currProduct};
                    }
                }
            }
        }
    }

    // If no subset sums to the target, return an empty vector
    if (!dp[n][target].first) {
        return {};
    }

    // Trace back the subset from the DP table
    std::vector<int> result;
    int currTarget = target;
    for (int i = n; i > 0 && currTarget > 0; --i) {
        if (dp[i - 1][currTarget].first && dp[i - 1][currTarget].second < dp[i][currTarget].second) { 
            continue;
        } else {
            result.push_back(nums[i - 1]);
            currTarget -= nums[i - 1];
        }
    }

    return result;
}