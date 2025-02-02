/*
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
*/

/*
Time Complexity: O(n)
- The for loop iterates through the array `nums` once, where `n` is the size of `nums`.
- Each iteration performs a constant amount of work.

Space Complexity: O(2n)
- The result vector `ans` requires space proportional to twice the size of the input array `nums`.
- Additional space used is minimal (e.g., for variables like `n`).
*/

#include <vector>

class Solution {
public:
    std::vector<int> getConcatenation(std::vector<int>& nums) {
        // Get the size of the input array `nums`
        int n = nums.size();

        // Create a new vector `ans` with size 2 * n to store the result
        std::vector<int> ans(2 * n);

        // Populate the `ans` vector with elements from `nums`
        for (int i = 0; i < n; ++i) {
            // Copy the elements of `nums` into the first half of `ans`
            ans[i] = nums[i];
            // Copy the elements of `nums` into the second half of `ans`
            ans[i + n] = nums[i];
        }

        // Return the concatenated array
        return ans;
    }
};