"""
    1. Two Sum
    Given an array of integers `nums` and an integer `target`, 
    return the indices of the two numbers such that they add up to the target.

    Assumptions:
    - Each input has exactly one solution.
    - The same element cannot be used twice.

    Example 1:
    Input: nums = [2,7,11,15], target = 9
    Output: [0,1]

    Explanation:
    nums[0] + nums[1] == 9, so return [0, 1].

    Example 2:
    Input: nums = [3,2,4], target = 6
    Output: [1,2]

    Example 3:
    Input: nums = [3,3], target = 6
    Output: [0,1]

    Constraints:
    - 2 <= nums.length <= 10^4
    - -10^9 <= nums[i] <= 10^9
    - -10^9 <= target <= 10^9
    - Only one valid answer exists.

    Follow-up:
    Can you solve it with a time complexity less than O(n^2)?
"""

"""
Dry Run:

Algorithm Overview:
- We use a single-pass hash table (dictionary) approach.
- The dictionary `values_seen` maps numbers we've seen so far to their indices.
- For each number in the list, we check if the complement (target - current number) exists in the dictionary.
- If it does, we've found the solution.
- Otherwise, we add the current number to the dictionary and continue.

Data Structure:
- Dictionary (hash map) is chosen because:
  1. It allows O(1) average time complexity for lookups.
  2. It can store both the value and its index for quick retrieval.

Step-by-step Algorithm:
1. Initialize an empty dictionary: values_seen = {}
2. Iterate through 'nums' with both index and value using enumerate().
3. For each number, compute the required complement: required_number = target - current_number
4. Check if required_number exists in values_seen:
   - If yes, return the pair of indices [values_seen[required_number], current_index]
5. If no, add current_number to values_seen with its index: values_seen[current_number] = current_index
6. Continue until the pair is found.

Example:

Input: nums = [2, 7, 11, 15], target = 9

Step 0: Initialize dictionary
values_seen = {}

Step 1: i = 0, current_number = 2
  required_number = 9 - 2 = 7
  7 not in values_seen
  Add current number to dictionary:
  values_seen = {2: 0}

Step 2: i = 1, current_number = 7
  required_number = 9 - 7 = 2
  2 is in values_seen → pair found
  Return [values_seen[2], 1] → [0, 1]

Step 3: Not executed (solution already found)

Key Points:
- Time Complexity: O(n) → we traverse the list once.
- Space Complexity: O(n) → in worst-case, dictionary stores all numbers.
- Dictionary allows us to check for the complement in constant time, making this approach efficient.

Conclusion:
- Using a dictionary is optimal for this problem.
- This method avoids nested loops, which would result in O(n^2) complexity.
"""

"""
Time and Space Complexity Analysis:

Algorithm Recap:
- We iterate through the list 'nums' once.
- For each number, we compute its complement (target - current_number).
- We check if the complement exists in the dictionary 'values_seen'.
- If not, we store the current number and its index in the dictionary.

Time Complexity:
1. The for-loop iterates over all n elements exactly once → O(n)
2. Dictionary lookups (to check if complement exists) and insertions are O(1) on average.
3. Therefore, total time complexity = O(n) * O(1) = O(n)
4. This is optimal because every element may need to be checked at least once.

Space Complexity:
1. We store each number in the dictionary along with its index.
2. In the worst case (no solution until the last pair), the dictionary will contain all n numbers → O(n)
3. No other significant extra memory is used.
4. Therefore, total space complexity = O(n)

Key Points:
- The dictionary allows constant-time lookups, which is why the algorithm avoids O(n^2) nested loops.
- Space grows linearly with input size, but this is necessary to achieve linear time complexity.
- Trade-off: using extra space (O(n)) reduces time from O(n^2) to O(n).

Summary:
- Time Complexity: O(n)
- Space Complexity: O(n)
- This combination makes the hash map approach both efficient and scalable for large input arrays.
"""

from typing import List

class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        # stores numbers already processed with their indices
        values_seen = {}

        # iterate through each number while tracking its position
        for current_index, current_number in enumerate(nums):

            # compute the number needed so the sum equals the target
            required_number = target - current_number

            # if the required number was seen before, a valid pair is found
            if required_number in values_seen:
                # return indices of the two numbers that add up to target
                return [values_seen[required_number], current_index]

            # save the current number and its index for future comparisons
            values_seen[current_number] = current_index