/*
    14. Longest Common Prefix
    Write a function to find the longest common prefix string amongst an array of strings.
    If there is no common prefix, return an empty string "".

    Example 1:
    Input: strs = ["flower", "flow", "flight"]
    Output: "fl"

    Example 2:
    Input: strs = ["dog", "racecar", "car"]
    Output: ""

    Explanation:
    There is no common prefix among the input strings.

    Constraints:
    1 <= strs.length <= 200
    0 <= strs[i].length <= 200
    strs[i] consists of only lowercase English letters if it is non-empty.
*/

/* 
    Explanation of Logic:

    1. Input Handling:
       - The function takes a vector of strings `words` as input.
       - If the input is empty, it immediately returns an empty string, which handles edge cases gracefully.

    2. Character-by-Character Comparison:
       - The outer loop goes through the indices of characters in the first string (`words[0]`).
       - For each index, the inner loop ensures that the character matches across all strings in the list.

    3. Mismatch Detection:
       - The function checks two critical conditions during comparison:
         - If the current character index exceeds the length of any string, it means we have reached the end of that string.
         - If characters at the current index do not match across all strings, it signifies the end of the common prefix.
       - In either case, the substring from the start to the current index is returned as the result.

    4. Complete Match:
       - If no mismatches occur throughout the iteration, the entire first string is considered the common prefix and is returned.

    Time Complexity:
    - Let `n` represent the number of strings in the input vector, and `m` denote the length of the shortest string in the input.
    - The outer loop runs up to `m` iterations, determined by the shortest string length.
    - The inner loop checks all `n` strings at each character index.
    - Hence, the total time complexity is O(n * m).

    Space Complexity:
    - The algorithm uses a constant amount of extra space, as it only declares a few variables for iteration and comparison.
    - Therefore, the space complexity is O(1).

    Edge Cases:
    - The input vector is empty, and the function returns an empty string.
    - One or more strings in the list are empty, resulting in an empty string as the common prefix.
    - All strings are identical, in which case the entire first string is the prefix.
    - No common prefix exists, so an empty string is returned.
*/

#include <string>
#include <vector>
#include <iostream>

class Solution {
public:
    // Function to find the longest common prefix among a list of strings
    std::string longestCommonPrefix(std::vector<std::string>& words) {
        // Base case: if the list is empty, return an empty string
        if (words.empty()) return "";

        // Loop through each character index of the first string
        for (int charIndex = 0; charIndex < words[0].length(); charIndex++) {
            // Compare the current character with the corresponding character in all other strings
            for (const std::string& currentWord : words) {
                // Check if we have reached the end of the current word 
                // or if the characters do not match
                if (charIndex == currentWord.length() || currentWord[charIndex] != words[0][charIndex]) {
                    // Return the substring from the start to the current character index
                    return words[0].substr(0, charIndex);
                }
            }
        }

        // If the loop completes, the entire first string is the common prefix
        return words[0];
    }
};