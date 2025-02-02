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

/*
=========================================================
  Sample Run of Merge Sort Algorithm
  Input: nums = {5, 3, 8, 4, 2}
=========================================================

### Step 1: Initial Input
   Array before sorting: [5, 3, 8, 4, 2]

### Step 2: Recursively Split the Array
---------------------------------------------------------

1st Split: performMergeSort(array, 0, 4)
    - Splitting into two halves: Left (0-2) and Right (3-4)

    Left Half: performMergeSort(array, 0, 2) → [5, 3, 8]
        - Splitting into: Left (0-1) and Right (2-2)

        Left Sub-Half: performMergeSort(array, 0, 1) → [5, 3]
            - Splitting into: Left (0-0) and Right (1-1)

            * Base case reached: Left (0-0) → [5] (already sorted)
            * Base case reached: Right (1-1) → [3] (already sorted)
            
            - Merging: [5] and [3] → [3, 5]
        
        * Base case reached: Right (2-2) → [8] (already sorted)

        - Merging: [3, 5] and [8] → [3, 5, 8]
    
    Right Half: performMergeSort(array, 3, 4) → [4, 2]
        - Splitting into: Left (3-3) and Right (4-4)

        * Base case reached: Left (3-3) → [4] (already sorted)
        * Base case reached: Right (4-4) → [2] (already sorted)

        - Merging: [4] and [2] → [2, 4]

### Step 3: Merge Sorted Halves
---------------------------------------------------------

Merging Left and Right Halves:
    Left Sorted Half  → [3, 5, 8]
    Right Sorted Half → [2, 4]

    - Compare first elements: 3 vs 2 → Insert 2
    - Compare next: 3 vs 4 → Insert 3
    - Compare next: 5 vs 4 → Insert 4
    - Compare next: 5 vs 8 → Insert 5
    - Last element remaining: Insert 8

    - Final sorted array: [2, 3, 4, 5, 8]

=========================================================
  Final Output:
  Sorted Array → [2, 3, 4, 5, 8]
=========================================================
*/

class Solution {
public:
    // Function to sort an array using Merge Sort algorithm
    vector<int> sortArray(vector<int>& nums) {
        // Call the merge sort helper function to sort the array
        performMergeSort(nums, 0, nums.size() - 1);
        
        // Return the sorted array
        return nums; 
    }

private:
    // Function to recursively divide the array into smaller subarrays and sort them
    void performMergeSort(vector<int>& array, int left, int right) {
        // Base case: If the subarray has one or zero elements, it is already sorted
        if (left >= right) return;
        
        // Calculate the middle index to split the array into two halves  // Prevents potential overflow
        int middle = left + (right - left) / 2; 
        
        // Recursively sort the left half of the array (from index 'left' to 'middle')
        performMergeSort(array, left, middle);
        
        // Recursively sort the right half of the array (from index 'middle + 1' to 'right')
        performMergeSort(array, middle + 1, right);
        
        // Merge the sorted halves back together to form a sorted array
        mergeSortedHalves(array, left, middle, right);
    }

    // Function to merge two sorted halves of an array into a single sorted sequence
    void mergeSortedHalves(vector<int>& array, int left, int middle, int right) {
        // Create temporary vectors to store the left and right halves of the array
        vector<int> leftHalf(array.begin() + left, array.begin() + middle + 1);
        vector<int> rightHalf(array.begin() + middle + 1, array.begin() + right + 1);
        
        // Indices to track the current positions in the left and right halves
        int leftIndex = 0;      // Pointer to track position in leftHalf
        int rightIndex = 0;     // Pointer to track position in rightHalf
        int sortedIndex = left; // Pointer to track position in the original array
        
        // Merge elements from both halves back into the original array in sorted order
        while (leftIndex < leftHalf.size() && rightIndex < rightHalf.size()) {
            if (leftHalf[leftIndex] <= rightHalf[rightIndex]) {
                // If leftHalf's current element is smaller, place it in the array
                array[sortedIndex++] = leftHalf[leftIndex++];
            } else {
                // Otherwise, place rightHalf's current element in the array
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
        
        // At this point, the merged portion of the array is sorted
    }
};