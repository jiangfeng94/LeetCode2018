> Given an array nums, there is a sliding window of size k which is moving from the very left of the array to the very right. You can only see the k numbers in the window. Each time the sliding window moves right by one position.
> For example,
Given nums = [1,3,-1,-3,5,3,6,7], and k = 3.

> Window position               --- Max

> [1  3  -1] -3  5  3  6  7     ---  3  
> 1 [3  -1  -3] 5  3  6  7      --- 3  
 1  3 [-1  -3  5] 3  6  7      --- 5  
 1  3  -1 [-3  5  3] 6  7   ---    5   
 1  3  -1  -3 [5  3  6] 7    ---   6  
 1  3  -1  -3  5 [3  6  7]   ---   7   
 
 
 **分析**：双向队列deque来解题，q用来记录nums的下标，遍历nums，如果队首是i-k，那么，移除队首，插入i；如果队尾下标对应nums 小于nums[i]，则移除队尾元素，插入新元素。
 ```
 class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> res;
        deque<int> q;
        for(int i=0;i<nums.size();i++){
            if(!q.empty() && q.front() ==i-k)  q.pop_front();
            while(!q.empty() && nums[q.back()]<nums[i]) q.pop_back();
            q.push_back(i);
            if(i>=k-1) res.push_back(nums[q.front()]);
        }
        return res;
    }
};
 ```