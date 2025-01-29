/*
    169. Majority Element
    Given an array `nums` of size `n`, return the majority element.

    The majority element is the element that appears more than ⌊n / 2⌋ times.
    It is guaranteed that the majority element always exists in the array.

    Example 1:
    Input: nums = [3,2,3]
    Output: 3

    Example 2:
    Input: nums = [2,2,1,1,1,2,2]
    Output: 2

    Constraints:
    - n == nums.length
    - 1 <= n <= 5 * 10^4
    - -10^9 <= nums[i] <= 10^9

    Follow-up:
    Can you solve the problem in linear time and using O(1) space?
*/

/*
    Detailed Explanation of the Algorithm:
    The function aims to find the majority element in an array. A majority element is defined as the element that appears more than half the size of the array. For example, in an array of size 7, the majority element must appear at least 4 times.

    To solve this problem efficiently, we use a method known as the Boyer-Moore Voting Algorithm. Let us break down the steps and logic behind this method:

    1. Candidate Initialization:
       - We begin by assuming there is no candidate for the majority element. We use a variable `candidate` to store the potential majority element, and `candidateCount` to track how many times we have seen this candidate.

    2. Traverse the Array:
       - As we loop through each number in the array, there are two possible scenarios:
         - If `candidateCount` is 0, it means there is no active candidate. In this case, we set the current number as the new candidate and reset the count to 1 because we have seen this number once.
         - If `candidateCount` is not 0, we check whether the current number matches the candidate:
           - If it matches, we increase the count because we are seeing the candidate again.
           - If it does not match, we decrease the count because the current number "cancels out" one occurrence of the candidate.

    3. Why Does This Work?:
       - Imagine the majority element is present in the array. Since it appears more than half the time, it will survive the process of "canceling out" with other numbers. This is because for every non-majority number, the majority element will still have enough occurrences to remain the candidate by the end of the loop.

    4. Final Candidate:
       - By the time we finish traversing the array, the `candidate` variable will hold the majority element. This is guaranteed because the majority element cannot be fully canceled out by other elements.

    5. Example Walkthrough:
       - Consider the array `[3, 3, 4, 2, 3, 3, 3]`:
         - Start with `candidate = 0` and `candidateCount = 0`.
         - First element is 3: Since `candidateCount` is 0, set `candidate = 3` and `candidateCount = 1`.
         - Second element is 3: Matches the candidate, increment `candidateCount` to 2.
         - Third element is 4: Does not match the candidate, decrement `candidateCount` to 1.
         - Fourth element is 2: Does not match the candidate, decrement `candidateCount` to 0.
         - Fifth element is 3: `candidateCount` is 0, so set `candidate = 3` and `candidateCount = 1`.
         - Sixth element is 3: Matches the candidate, increment `candidateCount` to 2.
         - Seventh element is 3: Matches the candidate, increment `candidateCount` to 3.
         - Final `candidate` is 3, which is the majority element.

    This process ensures that the majority element is correctly identified in a single pass through the array without requiring additional storage or multiple loops.
*/

class Solution {
public:
    // Function to find the majority element in an array.
    // The majority element is the element that appears more than n / 2 times, where n is the array size.
    int majorityElement(vector<int>& nums) {
        // Initialize the candidate for the majority element and its count.
        int candidate = 0;
        int candidateCount = 0;

        // Loop through each number in the array.
        for (int currentNumber : nums) {
            // If the candidate count is zero, set the current number as the new candidate.
            if (candidateCount == 0) {
                candidate = currentNumber;
            }

            // Update the candidate count:
            // Increment the count if the current number matches the candidate, otherwise decrement it.
            if (currentNumber == candidate) {
                candidateCount++;
            } else {
                candidateCount--;
            }
        }

        // By the end of the loop, the `candidate` will be the majority element.
        return candidate;
    }
};