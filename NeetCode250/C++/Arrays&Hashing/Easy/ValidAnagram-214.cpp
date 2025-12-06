/*
    Given two strings s and t, return true if t is an anagram of s, and false otherwise.

    Example 1:
    Input: s = "anagram", t = "nagaram"
    Output: true

    Example 2:
    Input: s = "rat", t = "car"
    Output: false

    Constraints:
    1 <= s.length, t.length <= 5 * 10^4
    s and t consist of lowercase English letters.
*/

/*
    Time Complexity:
    - O(n), where n is the length of the strings 's' and 't'. 
      We iterate through each character of the strings once and perform constant time operations for each character.

    Space Complexity:
    - O(1), as the space used by the 'count' vector is fixed at 26, 
      regardless of the size of the input strings. This makes the space usage constant.
*/

class Solution {
public:
    bool isAnagram(string s, string t) {
        // If the lengths of the two strings are not the same, they cannot be anagrams
        if (s.length() != t.length()) {
            return false;
        }

        // Create a vector of size 26 (for each letter of the alphabet) initialized to 0
        // This will be used to count the frequency of each character in the strings
        vector<int> count(26, 0);

        // Iterate through each character of the two strings
        for (int i = 0; i < s.length(); i++) {
            // Increment the count for the character in 's'
            count[s[i] - 'a']++;
            // Decrement the count for the character in 't'
            count[t[i] - 'a']--;
        }

        // Check if all counts are zero
        // If any count is not zero, it means 's' and 't' are not anagrams
        for (int val : count) {
            if (val != 0) {
                return false;
            }
        }

        // If all counts are zero, 's' and 't' are anagrams
        return true;
    }
};