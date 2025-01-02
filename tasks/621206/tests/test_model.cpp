#include <gtest/gtest.h>
#include WRAPPER_FILE //

TEST(SubsetSumTest, Test1) {
    std::vector<int> nums = {3, 5, 7};
    int target = 2;
    auto result = subsetSum(nums, target);
    std::sort(result.begin(), result.end());
    EXPECT_EQ(result, std::vector<int>({}));
}

TEST(SubsetSumTest, Test2) {
    std::vector<int> nums = {3, 5, 7};
    int target = 8;
    auto result = subsetSum(nums, target);
    std::sort(result.begin(), result.end());
    EXPECT_EQ(result, std::vector<int>({3, 5}));
}

TEST(SubsetSumTest, Test3) {
    std::vector<int> nums = {3, 5, 2};
    int target = 5;
    auto result = subsetSum(nums, target);
    EXPECT_EQ(result, std::vector<int>({5}));
}

TEST(SubsetSumTest, Test4) {
    std::vector<int> nums = {100000, 50000, 25000};
    int target = 100000;
    auto result = subsetSum(nums, target);
    EXPECT_EQ(result, std::vector<int>({100000}));
}

TEST(SubsetSumTest, Test5) {
    std::vector<int> nums = {1, 2, 3, 4, 5};
    int target = 9;
    auto result = subsetSum(nums, target);
    std::sort(result.begin(), result.end());
    EXPECT_EQ(result, std::vector<int>({1, 3, 5}));
}

TEST(SubsetSumTest, Test6) {
    std::vector<int> nums = {10, 20, 30};
    int target = 20;
    auto result = subsetSum(nums, target);
    EXPECT_EQ(result, std::vector<int>({20}));
}

TEST(SubsetSumTest, Test7) {
    std::vector<int> nums = {100000, 100000, 100000, 100000, 100000, 50000, 50000};
    int target = 500000;
    auto result = subsetSum(nums, target);
    std::sort(result.begin(), result.end());
    EXPECT_EQ(result, std::vector<int>({100000, 100000, 100000, 100000, 100000}));
}