#include <cmath>
#include <vector>
#include<iostream>
#include<algorithm>
#include <cfloat>
using namespace std;

std::vector<int> subsetSum(const std::vector<int>& nums, int target) {
    int n = nums.size();
    std::vector<std::vector<double>> dp(n + 1, std::vector<double>(target + 1, DBL_MAX));
    std::vector<std::vector<int>> parent(n + 1, std::vector<int>(target + 1, -1));

    for (int i = 0; i <= n; ++i) {
        dp[i][0] = 0.0; // log(1) = 0
    }

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= target; ++j) {
            dp[i][j] = dp[i - 1][j]; // Exclude current number
            if (nums[i - 1] <= j && dp[i - 1][j - nums[i - 1]] != DBL_MAX) {
                double newLogProduct = dp[i - 1][j - nums[i - 1]] + log(nums[i - 1]);
                if (newLogProduct < dp[i][j]) {
                    dp[i][j] = newLogProduct;
                    parent[i][j] = j - nums[i - 1];
                }
            }
        }
    }

    if (dp[n][target] == DBL_MAX) {
        return {};
    }

    std::vector<int> result;
    int currTarget = target;
    for (int i = n; i > 0 && currTarget > 0; --i) {
        if (parent[i][currTarget] != -1) {
            result.push_back(nums[i - 1]);
            currTarget = parent[i][currTarget];
        }
    }
    return result;
}