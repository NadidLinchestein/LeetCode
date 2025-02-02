/*
    75. Sort Colors
    
    Given an array nums with n objects colored red, white, or blue, sort them in-place so that objects of the same color are adjacent, 
    with the colors in the order red, white, and blue.
    
    We will use the integers 0, 1, and 2 to represent the color red, white, and blue, respectively.
    You must solve this problem without using the library's sort function.

    Example 1:
    Input: nums = [2,0,2,1,1,0]
    Output: [0,0,1,1,2,2]

    Example 2:
    Input: nums = [2,0,1]
    Output: [0,1,2]

    Constraints:
    - n == nums.length
    - 1 <= n <= 300
    - nums[i] is either 0, 1, or 2.

    Follow up: Could you come up with a one-pass algorithm using only constant extra space?
*/

/*
    Dry Run Simulation of sortColors

    ===========================
     Example 1: nums = [2, 0, 2, 1, 1, 0]
    ===========================

    Step 1: Initialize colorCount
    ------------------------------------
    vector<int> colorCount(3, 0);
    Initial state:
        colorCount = [0, 0, 0]

    Step 2: Count occurrences of each color
    ------------------------------------
    for (int num : nums) { 
        colorCount[num]++; 
    }

    Iteration-wise breakdown:
        nums[0] = 2 -> colorCount = [0, 0, 1]
        nums[1] = 0 -> colorCount = [1, 0, 1]
        nums[2] = 2 -> colorCount = [1, 0, 2]
        nums[3] = 1 -> colorCount = [1, 1, 2]
        nums[4] = 1 -> colorCount = [1, 2, 2]
        nums[5] = 0 -> colorCount = [2, 2, 2]

    Final state after counting:
        colorCount = [2, 2, 2]

    Step 3: Overwrite nums with sorted values
    ------------------------------------
    int index = 0;
    for (int color = 0; color < 3; color++) { 
        while (colorCount[color] > 0) { 
            nums[index] = color; 
            index++; 
            colorCount[color]--; 
        }
    }

    Processing color = 0:
        nums[0] = 0 -> colorCount = [1, 2, 2]
        nums[1] = 0 -> colorCount = [0, 2, 2]

    Processing color = 1:
        nums[2] = 1 -> colorCount = [0, 1, 2]
        nums[3] = 1 -> colorCount = [0, 0, 2]

    Processing color = 2:
        nums[4] = 2 -> colorCount = [0, 0, 1]
        nums[5] = 2 -> colorCount = [0, 0, 0]

    Final sorted array:
        nums = [0, 0, 1, 1, 2, 2]


    ===========================
     Example 2: nums = [2, 1, 2, 0, 1, 0, 1]
    ===========================


    Step 1: Initialize colorCount
    ------------------------------------
    vector<int> colorCount(3, 0);
    Initial state:
        colorCount = [0, 0, 0]

    Step 2: Count occurrences of each color
    ------------------------------------
    Iteration-wise breakdown:
        nums[0] = 2 -> colorCount = [0, 0, 1]
        nums[1] = 1 -> colorCount = [0, 1, 1]
        nums[2] = 2 -> colorCount = [0, 1, 2]
        nums[3] = 0 -> colorCount = [1, 1, 2]
        nums[4] = 1 -> colorCount = [1, 2, 2]
        nums[5] = 0 -> colorCount = [2, 2, 2]
        nums[6] = 1 -> colorCount = [2, 3, 2]

    Final state after counting:
        colorCount = [2, 3, 2]

    Step 3: Overwrite nums with sorted values
    ------------------------------------
    Processing color = 0:
        nums[0] = 0 -> colorCount = [1, 3, 2]
        nums[1] = 0 -> colorCount = [0, 3, 2]

    Processing color = 1:
        nums[2] = 1 -> colorCount = [0, 2, 2]
        nums[3] = 1 -> colorCount = [0, 1, 2]
        nums[4] = 1 -> colorCount = [0, 0, 2]

    Processing color = 2:
        nums[5] = 2 -> colorCount = [0, 0, 1]
        nums[6] = 2 -> colorCount = [0, 0, 0]

    Final sorted array:
        nums = [0, 0, 1, 1, 1, 2, 2]
*/

/*
    Time Complexity Analysis:
    - Counting occurrences takes O(N) time, where N is the size of the input array.
    - Overwriting the original array also takes O(N) time.
    - Therefore, the overall time complexity is O(N) + O(N) = O(N).

    Space Complexity Analysis:
    - We use an additional vector of size 3 (constant space) to store the counts.
    - Other variables like `index` and `color` use negligible space.
    - Since no extra space is used proportional to N, the overall space complexity is O(1) (constant space).

    This approach efficiently sorts the input array in-place without using built-in sorting functions.
    It follows a counting sort mechanism, ensuring a stable and efficient sorting process.
*/

class Solution {
public:
    void sortColors(vector<int>& nums) {
        // Step 1: Create an array to store the count of each color (0, 1, and 2)
        // Since there are only three possible values, we use a fixed-size array of size 3
        // Index 0 -> count of 0s, 1 -> count of 1s, 2 -> count of 2s
        vector<int> colorCount(3, 0); 
        
        // Step 2: Traverse the input array and count occurrences of each color
        for (int num : nums) {
            // Increment the respective index in colorCount 
            colorCount[num]++;
        }

        // Keeps track of the current position in the original array
        int index = 0;
        
        // Step 3: Overwrite the original array with sorted colors based on the counts
        for (int color = 0; color < 3; color++) { 
            while (colorCount[color] > 0) { 
                nums[index] = color;    // Assign the correct color at this index
                index++;                // Move to the next index
                colorCount[color]--;    // Decrease the count of this color
            }
        }
    }
};