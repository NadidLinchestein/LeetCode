"""
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
"""

"""
Dry Run and Explanation of isAnagram Algorithm:

The algorithm checks if two strings are anagrams by first counting the frequency of each character in the first string using a dictionary, 
then decrementing the counts using the second string.

If any count goes negative or a character is missing, the strings are not anagrams. Otherwise, they are.

Example:
s = "anagram"
t = "nagaram"

Step 1: Check lengths
- len(s) = 7, len(t) = 7
- Since lengths are equal, continue
- Early exit optimization ensures we don't waste time on obviously non-anagram strings

Step 2: Create a frequency map (dictionary) for characters in s
Data Structure:
- frequency_map: dict
  Key   -> character from s
  Value -> number of times the character appears in s
- This allows O(1) access to update and check character counts

Step 3: Count characters in s
Loop through s = "anagram":
  1. 'a' -> frequency_map['a'] = 1
  2. 'n' -> frequency_map['n'] = 1
  3. 'a' -> frequency_map['a'] = 2
  4. 'g' -> frequency_map['g'] = 1
  5. 'r' -> frequency_map['r'] = 1
  6. 'a' -> frequency_map['a'] = 3
  7. 'm' -> frequency_map['m'] = 1

frequency_map after counting s:
{'a': 3, 'n': 1, 'g': 1, 'r': 1, 'm': 1}

Step 4: Decrease counts using characters from t
Loop through t = "nagaram":
  1. 'n' -> frequency_map['n'] = 0
  2. 'a' -> frequency_map['a'] = 2
  3. 'g' -> frequency_map['g'] = 0
  4. 'a' -> frequency_map['a'] = 1
  5. 'r' -> frequency_map['r'] = 0
  6. 'a' -> frequency_map['a'] = 0
  7. 'm' -> frequency_map['m'] = 0

Key checks during loop:
- If character not in frequency_map → t has a character s doesn't have → return False
- If frequency_map[character] < 0 → t uses a character more times than s → return False
- These checks ensure early detection of non-anagram strings

Step 5: After processing all characters in t
- All frequency counts are 0
- This means t contains exactly the same characters as s
- Therefore, return True

Algorithm Summary:
- Check string lengths first for a quick fail
- Use a dictionary (hash map) to count character frequencies in s
- Decrement counts using characters from t
- Negative count or missing character immediately indicates t is not an anagram

This method efficiently detects anagrams using a frequency count map and handles mismatches immediately.
"""

"""
Time and Space Complexity:

- Time Complexity: O(n), where n = length of the strings.
  We make one pass to count characters in the first string and another pass to check/decrement counts using the second string.

- Space Complexity: O(k), where k = number of unique characters in the first string (up to 26 for lowercase English letters, or more for Unicode).
  The dictionary stores character frequencies, providing O(1) average-time access for updates and lookups.
  
- Reasoning:
  The algorithm is efficient because it only scans each string once and uses a hash map to track counts, avoiding nested loops or sorting.
"""

class Solution:
    def isAnagram(self, s: str, t: str) -> bool:        
        # Step 1: Anagrams must have the same length, If lengths differ, they cannot be anagrams
        if len(s) != len(t):
            return False

        # Step 2: Create a dictionary to store character frequencies
        # Key   -> character
        # Value -> number of times the character appears in s
        frequency_map = {}

        # Step 3: Count the frequency of each character in string s. We iterate through the string one character at a time
        for character in s:
            # frequency_map.get(character, 0) does the following:
            # - If 'character' already exists in the dictionary, return its current count
            # - If 'character' does not exist yet, return 0 (default value)

            # We then add 1 to represent the new occurrence of this character
            frequency_map[character] = frequency_map.get(character, 0) + 1

        # Step 4: Decrease the count using characters from string t
        for character in t:
            # If a character in t does not exist in s, t cannot be an anagram of s
            if character not in frequency_map:
                return False

            # Reduce the frequency for the matched character
            frequency_map[character] -= 1

            # If the frequency becomes negative, t has more occurrences of this character than s
            if frequency_map[character] < 0:
                return False

        # Step 5: If all character frequencies are balanced, then t is an anagram of s
        return True