/*
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
*/

/*
Explanation:

1. Input and Output:
    - Input: A vector `numbers` and an integer `targetSum`.
    - Output: A vector containing the indices of the two numbers that add up to `targetSum`.

2. Algorithm:
    - Use an unordered map `numToIndex` to store the number and its corresponding index as we iterate through the array.
    - For each number in the array:
        - Compute the `requiredNumber` needed to reach `targetSum`.
        - Check if `requiredNumber` is already in the map.
        - If yes, return the indices of the current number and its complement.
        - Otherwise, add the current number and its index to the map.

3. Time Complexity:
    - Each lookup and insertion operation in the unordered map is O(1) on average.
    - With `n` being the number of elements in the array, the total time complexity is O(n).

4. Space Complexity:
    - The unordered map stores up to `n` elements in the worst case, so the space complexity is O(n).
*/

#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int targetSum) {
        // Store the index of each number as we iterate through the array
        unordered_map<int, int> numToIndex;

        // Iterate through the numbers to find the pair that adds up to the targetSum
        for (int currentIndex = 0; currentIndex < numbers.size(); currentIndex++) {
            int currentNumber = numbers[currentIndex];

            // Calculate the required complement to reach the targetSum
            int requiredNumber = targetSum - currentNumber;

            // Check if the required complement has been seen before
            if (numToIndex.find(requiredNumber) != numToIndex.end()) {
                // If found, return the indices of the two numbers
                return {numToIndex[requiredNumber], currentIndex};
            }

            // Store the current number's index in the map
            numToIndex[currentNumber] = currentIndex;
        }

        // Return an empty vector if no solution exists (though the problem guarantees one)
        return {};
    }
};