/*
    912. Sort an Array
    Given an array of integers nums, sort the array in ascending order and return it.
    You must solve the problem without using any built-in functions in O(n log n) time complexity
    and with the smallest space complexity possible.

    Example 1:
    Input: nums = [5,2,3,1]
    Output: [1,2,3,5]
    Explanation: After sorting the array, the positions of some numbers are not changed (for example, 2 and 3), while the positions of other numbers are changed (for example, 1 and 5).

    Example 2:
    Input: nums = [5,1,1,2,0,0]
    Output: [0,0,1,1,2,5]
    Explanation: Note that the values of nums are not necessarily unique.

    Constraints:
    - 1 <= nums.length <= 5 * 10^4
    - -5 * 10^4 <= nums[i] <= 5 * 10^4
*/

/*
    Merge Sort is a sorting algorithm that follows the divide-and-conquer approach. It recursively splits the array into two halves until each subarray contains a single element. Then, it merges these sorted halves back together to produce a fully sorted array.
    
    Steps of the algorithm:
    1. Divide: Recursively divide the array into two halves until each half has only one element.
    2. Conquer: Sort and merge each half in sorted order.
    3. Merge: Combine the sorted halves back into a single sorted array.
    
    Time Complexity:
    Best Case: O(n log n)
    Average Case: O(n log n)
    Worst Case: O(n log n)
    This occurs because the array is repeatedly split into two halves (log n levels of recursion), and merging takes O(n) time at each level.
    
    Space Complexity:
    O(n) due to the use of temporary arrays to store the left and right halves during merging. This is an inherent space cost of the merge sort algorithm since merging requires extra space proportional to the size of the input array.
*/

class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        // Call the merge sort helper function
        performMergeSort(nums, 0, nums.size() - 1);
        return nums;
    }

private:
    // This function recursively divides the array into smaller parts
    void performMergeSort(vector<int>& array, int left, int right) {
        // Base case: If the subarray has one or zero elements, it is already sorted
        if (left >= right) return;
        
        // Calculate the middle index to split the array into two halves
        int middle = left + (right - left) / 2;
        
        // Recursively sort the left half
        performMergeSort(array, left, middle);
        
        // Recursively sort the right half
        performMergeSort(array, middle + 1, right);
        
        // Merge the sorted halves back together
        mergeSortedHalves(array, left, middle, right);
    }

    // This function merges two sorted halves of an array into a single sorted sequence
    void mergeSortedHalves(vector<int>& array, int left, int middle, int right) {
        // Temporary vectors to hold the left and right halves of the array
        vector<int> leftHalf(array.begin() + left, array.begin() + middle + 1);
        vector<int> rightHalf(array.begin() + middle + 1, array.begin() + right + 1);
        
        // Indices to track positions in the left and right halves
        int leftIndex = 0, rightIndex = 0, sortedIndex = left;
        
        // Merge elements from both halves back into the original array in sorted order
        while (leftIndex < leftHalf.size() && rightIndex < rightHalf.size()) {
            if (leftHalf[leftIndex] <= rightHalf[rightIndex]) {
                array[sortedIndex++] = leftHalf[leftIndex++];
            } else {
                array[sortedIndex++] = rightHalf[rightIndex++];
            }
        }
        
        // Copy any remaining elements from the left half into the main array
        while (leftIndex < leftHalf.size()) {
            array[sortedIndex++] = leftHalf[leftIndex++];
        }
        
        // Copy any remaining elements from the right half into the main array
        while (rightIndex < rightHalf.size()) {
            array[sortedIndex++] = rightHalf[rightIndex++];
        }
    }
};