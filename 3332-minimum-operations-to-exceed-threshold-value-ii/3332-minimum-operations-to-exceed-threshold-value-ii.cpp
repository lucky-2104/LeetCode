class Solution {
public:
int minOperations(vector<int>& nums, int k) {
    // Create a min-heap (priority queue in C++ is max-heap by default, so we use greater<int>)
    priority_queue<long long, vector<long long>, greater<long long>> minHeap(nums.begin(), nums.end());
    
    int operations = 0;
    
    // Continue until all elements are >= k
    while (!minHeap.empty() && minHeap.top() < k) {
        if (minHeap.size() < 2) {
            return -1; // Not possible to make all elements >= k
        }
        
        // Extract the two smallest elements
        long long x = minHeap.top();
        minHeap.pop();
        long long y = minHeap.top();
        minHeap.pop();
        
        // Perform the operation
        long long newElement = min(x, y) * 2 + max(x, y);
        
        // Add the new element back to the heap
        minHeap.push(newElement);
        
        // Increment the operation count
        operations++;
    }
    
    return operations;
}

};