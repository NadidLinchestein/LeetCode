/*
    706. Design HashMap
    Design a HashMap without using any built-in hash table libraries.

    Implement the MyHashMap class:
    - MyHashMap(): Initializes the object with an empty map.
    - void put(int key, int value): Inserts a (key, value) pair into the HashMap. 
      If the key already exists in the map, update the corresponding value.
    - int get(int key): Returns the value to which the specified key is mapped, 
      or -1 if this map contains no mapping for the key.
    - void remove(int key): Removes the key and its corresponding value if the map 
      contains the mapping for the key.

    Example 1:
    Input:
    ["MyHashMap", "put", "put", "get", "get", "put", "get", "remove", "get"]
    [[], [1, 1], [2, 2], [1], [3], [2, 1], [2], [2], [2]]
    Output:
    [null, null, null, 1, -1, null, 1, null, -1]

    Explanation:
    MyHashMap myHashMap = new MyHashMap();
    myHashMap.put(1, 1); // The map is now [[1,1]]
    myHashMap.put(2, 2); // The map is now [[1,1], [2,2]]
    myHashMap.get(1);    // return 1, The map is now [[1,1], [2,2]]
    myHashMap.get(3);    // return -1 (i.e., not found), The map is now [[1,1], [2,2]]
    myHashMap.put(2, 1); // The map is now [[1,1], [2,1]] (i.e., update the existing value)
    myHashMap.get(2);    // return 1, The map is now [[1,1], [2,1]]
    myHashMap.remove(2); // remove the mapping for 2, The map is now [[1,1]]
    myHashMap.get(2);    // return -1 (i.e., not found), The map is now [[1,1]]

    Constraints:
    - 0 <= key, value <= 10^6
    - At most 10^4 calls will be made to put, get, and remove.
*/

/*
    Time Complexity: O(1) for each function call.
    Space Complexity: O(1000000) since the key is in the range [0,1000000].

    Time Complexity:
        - put(): O(1) (Direct array access to store the value)
        - get(): O(1) (Direct array access to retrieve the value)
        - remove(): O(1) (Direct array access to mark the key as deleted)

    Space Complexity:
        - O(N), where N = 10^6 + 1 (Fixed size array to store values for all possible keys)
        - This is a trade-off for fast O(1) access times, but it consumes more memory.
*/

#include <vector>

using namespace std;

class MyHashMap {
private:
    // We use a vector to store key-value pairs.
    // The size is set to 1000001 because the constraints ensure keys are in range [0, 10^6].
    // Initially, all values are set to -1 to indicate an empty state.
    vector<int> map;

public:
    // Constructor initializes the hashmap with a fixed size of 1000001 and sets all values to -1.
    MyHashMap() : map(1000001, -1) {}

    // Inserts a key-value pair into the hashmap.
    // If the key already exists, it updates the value.
    void put(int key, int value) {
        map[key] = value;
    }

    // Retrieves the value associated with the given key.
    // Returns -1 if the key does not exist in the hashmap.
    int get(int key) {
        return map[key];
    }

    // Removes the key-value pair by setting the value to -1.
    // This effectively marks the key as deleted.
    void remove(int key) {
        map[key] = -1;
    }
};