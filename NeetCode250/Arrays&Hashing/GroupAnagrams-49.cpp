/*
    49. Group Anagrams
    Given an array of strings strs, group the anagrams together. You can return the answer in any order.

    Example 1:
    Input: strs = ["eat","tea","tan","ate","nat","bat"]
    Output: [["bat"],["nat","tan"],["ate","eat","tea"]]

    Explanation:
    - The string "bat" cannot be rearranged to form any other string in strs.
    - The strings "nat" and "tan" are anagrams as they can be rearranged to form each other.
    - The strings "ate", "eat", and "tea" are anagrams as they can be rearranged to form each other.

    Example 2:
    Input: strs = [""]
    Output: [[""]]

    Example 3:
    Input: strs = ["a"]
    Output: [["a"]]

    Constraints:
    - 1 <= strs.length <= 10^4
    - 0 <= strs[i].length <= 100
    - strs[i] consists of lowercase English letters.
*/

/*
    Explanation of the Solution:

    Key Idea:
    The core idea is to group strings that are anagrams of each other. An anagram is a word formed by rearranging the letters of another, so two strings are anagrams if their letter counts are identical.

    Step-by-Step Process:

    1. Character Count as Key:
       - For each string, calculate the frequency of each character (from 'a' to 'z').
       - Store the frequencies in a vector<int> charCount of size 26.
       - This frequency vector uniquely identifies all anagrams since the character counts are identical for anagrams.

    2. Key Generation:
       - Convert the charCount vector into a string key by concatenating counts with commas.
       - This ensures a unique representation for each group of anagrams.

    3. Group Storage:
       - Use an unordered_map<string, vector<string>> to group strings by their keys.
       - The key acts as the signature for each anagram group.

    4. Result Compilation:
       - Extract the values of the map (groups of anagrams) into a vector<vector<string>> and return it as the result.

    Why Character Count Instead of Sorting:
       - Sorting each string to determine anagrams is another valid approach.
       - However, creating a frequency count is more efficient for strings with long lengths because sorting has a higher overhead.

    Time Complexity:

    1. Key Computation:
       - For each string, building the charCount vector and converting it to a key takes O(L), where L is the length of the string.
       - Over N strings, the total time for key computation is O(N * L).

    2. Map Insertion:
       - Each string insertion into the map is O(1) amortized due to hashing.

    3. Result Construction:
       - Extracting the values from the map takes O(G), where G is the total number of groups.

    Overall Time Complexity:
       - O(N * L), where N is the number of strings and L is the average length of strings.

    Space Complexity:

    1. Storage for Map:
       - The unordered_map stores all strings and their keys, requiring O(N * L) space.

    2. Intermediate Data Structures:
       - The charCount vector for each string requires O(26) = O(1) space.

    Total Space Complexity:
       - O(N * L) due to storage of strings in the map.
*/


#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        // Map to group words by their anagram signature
        unordered_map<string, vector<string>> anagramGroups;

        // Iterate over each string in the input
        for (const auto& word : strs) {
            // Create a frequency count of characters in the current word
            // The vector 'charCount' has 26 slots (for each lowercase English letter)
            // Each slot represents the frequency of a letter in the word
            vector<int> charCount(26, 0);
            
            for (char c : word) {
                // Increment the count for the corresponding character
                // The index is determined by subtracting 'a' from the character
                charCount[c - 'a']++;
            }

            // Convert the character count vector into a unique string key
            // This key will be used to group all anagrams together
            string key;
            
            for (int count : charCount) {
                // Append each count to the key, separated by a comma
                // The resulting key uniquely represents the letter frequency of the word
                key += to_string(count) + ",";
            }

            // Group the word under the corresponding anagram signature in the map
            // If the key already exists, append the word to the existing group
            // Otherwise, create a new group for this key
            anagramGroups[key].push_back(word);
        }

        // Prepare the result vector by extracting all grouped anagrams from the map
        vector<vector<string>> result;
        for (const auto& group : anagramGroups) {
            // Each entry in the map contains a vector of strings that are anagrams
            result.push_back(group.second);
        }

        // Return the grouped anagrams as the final result
        return result;
    }
};