/*
    27. Remove Element
    
    Given an integer array `nums` and an integer `val`, remove all occurrences of `val` in `nums` in-place. 
    The order of the elements may be changed. Then return the number of elements in `nums` which are not equal to `val`.

    Assumptions:
    - The elements not equal to `val` must be placed in the first `k` elements of `nums`.
    - The remaining elements of `nums` beyond `k` are not important.
    - The number of elements in `nums` not equal to `val` is represented as `k`.

    Custom Judge:
    The judge will test the solution using the following steps:
    1. Call the function `removeElement(nums, val)` to modify `nums` and return `k`.
    2. Verify `k` equals the expected length.
    3. Sort the first `k` elements of `nums` and ensure they match the expected result.

    Example 1:
    Input: nums = [3,2,2,3], val = 3
    Output: 2, nums = [2,2,_,_]
    Explanation:
    The function should return `k = 2`, with the first two elements of `nums` being `2`.
    The underscores (_) represent elements beyond `k` that are not important.

    Example 2:
    Input: nums = [0,1,2,2,3,0,4,2], val = 2
    Output: 5, nums = [0,1,4,0,3,_,_,_]
    Explanation:
    The function should return `k = 5`, with the first five elements of `nums` containing 0, 1, 4, 0, and 3 in any order.
    The underscores (_) represent elements beyond `k` that are not important.

    Constraints:
    - 0 <= nums.length <= 100
    - 0 <= nums[i] <= 50
    - 0 <= val <= 100
*/

/*
    Explanation of the logic:

    1. The function uses two main variables:
       - `index`: Points to the current position being evaluated in the array.
       - `currentSize`: Represents the effective size of the array after removals.

    2. The loop continues until `index` is less than `currentSize`:
       - If `nums[index] == target`, the value at `index` is replaced by the last element of the array (`nums[currentSize - 1]`), and the size is reduced (`currentSize--`).
         - This is a constant time operation and avoids shifting elements to the left.
       - If `nums[index] != target`, move to the next element (`index++`).

    3. The key idea is to shrink the array from the end whenever a target value is found, effectively removing it without requiring a separate array or shifting elements.

    4. The final `currentSize` represents the number of elements remaining in the array that are not equal to the target value.

    Advantages of this approach:
    - Time complexity: O(n), where `n` is the size of the array, as each element is processed once.
    - Space complexity: O(1), as no additional data structures are used.
*/

class Solution {
public:
    int removeElement(std::vector<int>& nums, int target) {
        // Initialize two variables:
        // - `index` tracks the current position being inspected.
        // - `currentSize` tracks the effective size of the array after removals.
        int index = 0;
        int currentSize = nums.size();

        // Iterate through the array while `index` is less than `currentSize`.
        while (index < currentSize) {
            // If the current element matches the target value,
            // replace it with the last element in the array and reduce the size.
            if (nums[index] == target) {
                nums[index] = nums[currentSize - 1];
                currentSize--; // Decrease the effective size since the last element is removed.
            } else {
                // If the current element does not match the target, move to the next element.
                index++;
            }
        }

        // Return the new size of the array after all target values are removed.
        return currentSize;
    }
};