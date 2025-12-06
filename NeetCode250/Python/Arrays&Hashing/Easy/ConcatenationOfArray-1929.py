"""
    1929. Concatenation of Array
    
    Given an integer array nums of length n, create an array ans of length 2n where:
      - ans[i] == nums[i]
      - ans[i + n] == nums[i] for 0 <= i < n (0-indexed).

    Specifically, ans is the concatenation of two nums arrays.

    Example 1:
    Input: nums = [1,2,1]
    Output: [1,2,1,1,2,1]

    Explanation:
    - ans = [nums[0], nums[1], nums[2], nums[0], nums[1], nums[2]]
    - ans = [1,2,1,1,2,1]

    Example 2:
    Input: nums = [1,3,2,1]
    Output: [1,3,2,1,1,3,2,1]

    Explanation:
    - ans = [nums[0], nums[1], nums[2], nums[3], nums[0], nums[1], nums[2], nums[3]]
    - ans = [1,3,2,1,1,3,2,1]

    Constraints:
    - n == nums.length
    - 1 <= n <= 1000
    - 1 <= nums[i] <= 1000
"""

"""
Time Complexity: O(n)
- Let n be the length of the input list `nums`.
- The outer loop runs 2 times, and the inner loop iterates through all n elements of `nums`.
- Each iteration performs a constant-time operation (append).
- Total operations: 2 * n → O(n).

Space Complexity: O(2n)
- The resulting list `ans` stores twice the elements of `nums`.
- Additional space for loop variables (`repeat_index` and `item`) is negligible.
- Total space usage grows linearly with input size → O(2n).
"""

from typing import List

class Solution:
    def getConcatenation(self, nums: List[int]) -> List[int]:
        # Initialize an empty list to store the repeated elements
        ans = []

        # Repeat the process twice
        for repeat_index in range(2):   # Outer loop controls repetition
            for item in nums:           # Inner loop iterates through each element
                ans.append(item)        # Append current element to 'ans'

        # Return the concatenated list
        return ans