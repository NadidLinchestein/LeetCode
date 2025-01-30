/*
    705. Design HashSet
    Design a HashSet without using any built-in hash table libraries.
    
    Implement MyHashSet class:
    - void add(key): Inserts the value key into the HashSet.
    - bool contains(key): Returns whether the value key exists in the HashSet or not.
    - void remove(key): Removes the value key in the HashSet. If key does not exist, do nothing.
    
    Example 1:
    Input:
    ["MyHashSet", "add", "add", "contains", "contains", "add", "contains", "remove", "contains"]
    [[], [1], [2], [1], [3], [2], [2], [2], [2]]
    Output:
    [null, null, null, true, false, null, true, null, false]
    
    Explanation:
    MyHashSet myHashSet = new MyHashSet();
    myHashSet.add(1);      // set = [1]
    myHashSet.add(2);      // set = [1, 2]
    myHashSet.contains(1); // return True
    myHashSet.contains(3); // return False, (not found)
    myHashSet.add(2);      // set = [1, 2]
    myHashSet.contains(2); // return True
    myHashSet.remove(2);   // set = [1]
    myHashSet.contains(2); // return False, (already removed)
    
    Constraints:
    - 0 <= key <= 10^6
    - At most 10^4 calls will be made to add, remove, and contains.
*/

/*
    Usage Example:
    MyHashSet* obj = new MyHashSet();
    obj->add(5); // Adds key 5 to the hash set.
    obj->remove(5); // Removes key 5 from the hash set.
    bool exists = obj->contains(5); // Checks if key 5 is present (returns false after removal).
*/

/*
    Time Complexity:
    - add(int key)     -> O(1)
    - remove(int key)  -> O(1)
    - contains(int key) -> O(1)

    Space Complexity:
    - O(N), where N = 1,000,001 (≈ O(10^6))
*/

#include <vector>

class MyHashSet {
private:
    // We use a vector<bool> to represent our hash set, where index represents the key.
    // The value at each index is true if the key is present, false otherwise.
    std::vector<bool> data;

public:
    // Constructor: Initialize the hash set with a fixed size of 1,000,001 elements.
    // We choose 1,000,001 because the problem constraints usually specify a max key value of 10^6.
    // Space Complexity: O(N), where N is the range of possible keys (1,000,001 in this case).
    MyHashSet() : data(1000001, false) {}

    // Adds a key to the hash set.
    // Since vector<bool> allows direct index access, setting a value is O(1) time complexity.
    void add(int key) {
        data[key] = true;
    }

    // Removes a key from the hash set.
    // Again, since we use direct indexing, removing an element is O(1) time complexity.
    void remove(int key) {
        data[key] = false;
    }

    // Checks if a key exists in the hash set.
    // Returns true if the key is present, otherwise false.
    // Since we are directly accessing an index in the vector, this is also O(1) time complexity.
    bool contains(int key) {
        return data[key];
    }
};