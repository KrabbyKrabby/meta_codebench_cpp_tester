#include <gtest/gtest.h>
#include <algorithm>

//This header "test_class.h" contains the model implementation to test. 
//Just create this file, copy the model implementation into it and compile the code
#include WRAPPER_FILE //

TEST(FileSystemTest, NormalizePath) {
    FileSystem fs;
    // GTEST_SKIP();

    EXPECT_EQ(fs.normalizePath("/a/b/../c/./d//"), "/a/c/d");
    EXPECT_EQ(fs.normalizePath("/../"), "/");
    EXPECT_EQ(fs.normalizePath("//a//b///c"), "/a/b/c");
    EXPECT_EQ(fs.normalizePath("/a/././b/../c/"), "/a/c");
}

TEST(FileSystemTest, ListFilesInDirectory) {
    FileSystem fs;
    // GTEST_SKIP();

    fs.addFilePath("/a/b/c.txt");
    fs.addFilePath("/a/b/d.txt");
    fs.addFilePath("/a/e/f.txt");

    //sort result before comparing
    auto sortedResult = fs.listFilesInDirectory("/a/b/");
    std::sort(sortedResult.begin(), sortedResult.end());
    EXPECT_EQ(sortedResult, (std::vector<std::string>{"/a/b/c.txt", "/a/b/d.txt"}));

    EXPECT_EQ(fs.listFilesInDirectory("/a/e"), (std::vector<std::string>{"/a/e/f.txt"}));
    EXPECT_EQ(fs.listFilesInDirectory("/nonexistent"), std::vector<std::string>{});
}

TEST(FileSystemTest, EdgeCases) {
    FileSystem fs;
    // GTEST_SKIP();

    // Root directory normalization
    EXPECT_EQ(fs.normalizePath("/"), "/");
    EXPECT_EQ(fs.normalizePath("///"), "/");

    // Nested directories
    fs.addFilePath("/a/b/c.txt");
    fs.addFilePath("/a/bb/d.txt");
    fs.addFilePath("/a/bbb.txt");
    EXPECT_EQ(fs.listFilesInDirectory("/a/"), std::vector<std::string>{"/a/bbb.txt"});

    // Add root path
    EXPECT_NO_THROW(fs.addFilePath("/root/file.txt"));
    EXPECT_TRUE(fs.filePathExists("/root/file.txt"));

    // Adding and checking paths with trailing slashes
    EXPECT_NO_THROW(fs.addFilePath("/trailing/slashes/"));
    EXPECT_FALSE(fs.filePathExists("/trailing/slashes/"));  
    EXPECT_TRUE(fs.filePathExists("/trailing/slashes"));

    // Verify filePathExists does not confuse partial overlaps
    fs.addFilePath("/a/b/c");
    EXPECT_FALSE(fs.filePathExists("/a/b"));  // "/a/b" is not the same as "/a/b/c"
}

// Test addFilePath, filePathExists and basic functionality
TEST(FileSystemTest, AddFilePathValid) {
    FileSystem fs;

    // Add valid file paths
    EXPECT_NO_THROW(fs.addFilePath("/a/b/c.txt"));
    EXPECT_NO_THROW(fs.addFilePath("/x/y/z.txt"));

    // Check existence of paths
    EXPECT_TRUE(fs.filePathExists("/a/b/c.txt"));
    EXPECT_TRUE(fs.filePathExists("/x/y/z.txt"));

    // Check non-existing paths
    EXPECT_FALSE(fs.filePathExists("/non/existent/path"));
    EXPECT_FALSE(fs.filePathExists("/a/b"));
    EXPECT_FALSE(fs.filePathExists("/x/y"));

    // Adding an already existing path shouldn't raise any errow
    fs.addFilePath("/a/b/c.txt");
    EXPECT_NO_THROW(fs.addFilePath("/a/b/c.txt")); 
}

// Test adding invalid file paths
TEST(FileSystemTest, AddFilePathInvalid) {
    FileSystem fs;

    // Overlapping paths
    fs.addFilePath("/a/b/c.txt");
    EXPECT_THROW(fs.addFilePath("/a/b"), std::invalid_argument);

    // Invalid paths
    EXPECT_THROW(fs.addFilePath("a/c.txt"), std::invalid_argument);   // Missing leading '/'
}



