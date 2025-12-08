"""
    217. Contains Duplicate
    Given an integer array nums, return true if any value appears at least twice in the array, and return false if every element is distinct.

    Example 1:
    Input: nums = [1,2,3,1]
    Output: true

    Explanation:
    The element 1 occurs at the indices 0 and 3.

    Example 2:
    Input: nums = [1,2,3,4]
    Output: false

    Explanation:
    All elements are distinct.

    Example 3:
    Input: nums = [1,1,1,3,3,4,3,2,4,2]
    Output: true

    Constraints:
    1 <= nums.length <= 105^5
    -10^9 <= nums[i] <= 10^9
"""

"""
Dry Run


We iterate through each number in the list while keeping track of the numbers we have already seen
using a set, which only stores unique values. 

For each number:
    - If it is already in the set, it means we have found a duplicate and return True immediately.
    - If it is not in the set, we add it and continue checking the next numbers.

If we finish checking all numbers without finding any duplicates, we return False. 
This approach is efficient because it stops as soon as a duplicate is found and allows fast lookups.


Example 1:
nums = [1, 2, 3, 1]

Start: seen_numbers = {}

Step 1: number = 1
    1 not in set → add it
    seen_numbers = {1}

Step 2: number = 2
    2 not in set → add it
    seen_numbers = {1, 2}

Step 3: number = 3
    3 not in set → add it
    seen_numbers = {1, 2, 3}

Step 4: number = 1
    1 *is already in* seen_numbers → duplicate found
Return True


Example 2:
nums = [1, 2, 3, 4]

Start: seen_numbers = {}

Step 1: number = 1 → add → {1}
Step 2: number = 2 → add → {1, 2}
Step 3: number = 3 → add → {1, 2, 3}
Step 4: number = 4 → add → {1, 2, 3, 4}

No duplicates → return False


Example 3:
nums = [1, 1, 1, 3, 3, 4, 3, 2, 4, 2]

Start: seen_numbers = {}

Step 1: number = 1 → add → {1}
Step 2: number = 1 → already in set → duplicate
Return True

We stop early because we don't need to check further.
"""

"""
Time and Space Complexity

Time Complexity: O(n)
    - We scan the list once.
    - Each check "number in set" is O(1) on average.
    - Each insertion into the set is also O(1) on average.
    - Therefore total = n operations = O(n).

Space Complexity: O(n)
    - In the worst case (no duplicates), the set must store every number once.
    - That means up to n elements → O(n) space.

Why a set?
    - Because sets allow fast lookups, which makes duplicate detection efficient.
"""

from typing import List

class Solution:
    def containsDuplicate(self, nums: List[int]) -> bool:
        # Set to keep track of numbers we've already encountered
        seen_numbers = set()

        # Check each number in the list
        for number in nums:
            # If the number is already in the set, we found a duplicate
            if number in seen_numbers:
                return True
            # Otherwise, add it to the set
            seen_numbers.add(number)

        # If we finish the loop with no duplicates, return False
        return False