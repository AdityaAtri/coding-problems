//kth largest element in the array
//leetcode prblm
//215

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int>pq; 
        //building the heap
        for(int i=0; i<nums.size(); i++){
            pq.push(nums[i]);
        }
        //extracting the root of the max heap
        for(int i=1; i<k; i++) pq.pop();
        return pq.top(); 
    }
};
