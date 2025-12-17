"""
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
"""

"""
    Dry Run
    
    Explanation of the code:
    1. If the input list `strs` is empty, there is no common prefix, so return "".
    2. Use the first string as a baseline for comparison.
    3. Iterate over each character position in the first string.
       - For each character, check if all other strings have the same character at this position.
       - If a mismatch is found or a string is shorter than the current position, return the substring of the first string up to this position.
    4. If the loop finishes without returning, the entire first string is the common prefix.
    
    Example:
    Input: strs = ["flower", "flow", "flight"]

    Step 1: Check if strs is empty -> No, continue.
    Step 2: first_word = "flower"

    Iterate over positions in "flower":
    
    position = 0, baseline_character = 'f'
        Compare with each string:
        "flower"[0] = 'f' -> match
        "flow"[0] = 'f' -> match
        "flight"[0] = 'f' -> match
        -> continue

    position = 1, baseline_character = 'l'
        Compare with each string:
        "flower"[1] = 'l' -> match
        "flow"[1] = 'l' -> match
        "flight"[1] = 'l' -> match
        -> continue

    position = 2, baseline_character = 'o'
        Compare with each string:
        "flower"[2] = 'o' -> match
        "flow"[2] = 'o' -> match
        "flight"[2] = 'i' -> mismatch!
        -> return first_word[:2] -> "fl"

    Output: "fl"
    
    Summary:
    The algorithm checks each character across all strings in sequence and stops as soon as a mismatch is found. 
    This guarantees that the returned substring is the longest common prefix.
"""

"""
Time and Space Complexity Analysis:

Algorithm Recap:
- The function compares characters of the first string with the same position in all other strings.
- It stops at the first mismatch or when the shortest string ends.

Time Complexity:
- Let n = number of strings in the input list `strs`.
- Let m = length of the shortest string in `strs` (worst-case prefix length).
- In the worst case, each character of the first string is compared with every other string.
- Each comparison takes O(1), so total comparisons are at most n * m.
- Therefore, the time complexity is O(n * m).

Example:
- strs = ["flower", "flow", "flight"]
- Shortest string length = 4
- Max comparisons = 3 strings * 4 characters = 12 comparisons

Space Complexity:
- No extra data structures are used that scale with input size.
- Only a few variables (position, baseline_character) are used.
- Therefore, the space complexity is O(1) — constant space.

Summary:
- Time Complexity: O(n * m), where n = number of strings, m = length of shortest string
- Space Complexity: O(1)
"""

class Solution:
    def longestCommonPrefix(self, strs: List[str]) -> str:
        # If there are no strings, there cannot be a common prefix
        if not strs:
            return ""

        # The first string is used as the baseline for comparison
        first_word = strs[0]

        # Iterate through each character position in the first word
        for position in range(len(first_word)):
            baseline_character = first_word[position]

            # Check this character against the same position in every string
            for current_word in strs:
                # Stop if:
                # 1. The current word is shorter than the current position, OR
                # 2. Characters at this position do not match
                if position == len(current_word) or current_word[position] != baseline_character:
                    # Return the common prefix identified so far
                    return first_word[:position]

        # If no mismatches were found, the entire first word is the common prefix
        return first_word