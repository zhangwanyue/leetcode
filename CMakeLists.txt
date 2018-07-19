cmake_minimum_required(VERSION 3.9)
project(LeetCode)

set(CMAKE_CXX_STANDARD 11)

add_executable(LeetCode leetcode/1_TwoSum.cpp leetcode/2_AddTwoNumbers.cpp test/StlTest.cpp leetcode/3_longestSubstringWithoutRepeatingCharacters.cpp leetcode/5_longestPalindromicSubstring_false.cpp leetcode/5_longestPalindromicSubstring.cpp leetcode/6_zigzagConversion.cpp leetcode/11_containerWithMostWater.cpp)