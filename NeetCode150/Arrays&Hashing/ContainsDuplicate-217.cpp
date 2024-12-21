/*
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
*/

/*
    Time complexity: O(n)
    Space complexity: O(n)
*/

#include <unordered_set>  // For unordered_set (hash-based set)
#include <vector>         // For vector

class Solution {
public:
    bool containsDuplicate(std::vector<int>& nums) {
        std::unordered_set<int> seen;  // Set to store unique elements

        // Iterate through each number in the vector
        for (int num : nums) {
            /*                 
                If the element is found in the set: 
                find() returns an iterator pointing to the element in the set. This iterator is a valid pointer to the element.
                
                If the element is NOT found in the set:
                find() returns seen.end(), which is a special iterator that points past the last element in the set. It's not pointing to an actual element but is used as a boundary marker indicating the end of the set.
                
                If num is found in the set, find() will return a valid iterator, which is not equal to seen.end(). So, the condition find(num) != seen.end() will be true, indicating the element is in the set. Therefore running the if statement returning true.
                If num is not found, find() will return seen.end(), and the condition find(num) != seen.end() will be false. Therefore skipping the if statement and going to seen.insert(num).
            */
            if (seen.find(num) != seen.end()) {
                return true;  // Duplicate found
            }

            seen.insert(num);  // Add the number to the set
        }
        
        return false; // No duplicates
    }
};