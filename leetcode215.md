# 215. Kth Largest Element in an Array

题目很简单，但是有多种解法。下面一一介绍：

## 优先队列
```
int findKthLargest(vector<int> nums, int k){
    PriorityQueue<int> p =new PriorityQueue<int>();
    for(int i =0;i <nums.size();i++){
        p.add(nums[i]);
        if(p.size()>k) p.poll();
    }
    return p.poll();
}
```
另一种写法
```
int findkthLargest(vector<int> nums,int k){
    priority_queue<int> q(nums.begin(),nums.end());
    for(int i=0;i<k-1;i++){
        q.pop();
    }
    return q.top();
}
```

## 排序法
```
int findKthLargest(vector<int> nums, int k){
    sort(nums.begin(),nums.end());
    return nums[nums.size()-k];
}
```


## 最朴素的解法 Quick Sort
```
int findKthLargest(vector<int>& nums,int k){
    int left =0,right =nums.size()-1;
    while(1){
        int pos =partition(nums,left,right);
        if(pos ==k-1) return nums[pos];
        else if (pos > k-1) right =pos-1;
        else left =pos +1;
    }
    int partition(vector<int>&nums,int left,int right){
        int pivot =nums[left],l=left+1,r =right;
        while(1<=r){
            if(nums[l]<pivot && nums[r] >pivot){
                swap(nums[l++],nums[r--]);
            }
            if(nums[l]>= pivot) ++l;
            if(nums[r]<= pivot) --r;
        }
        swap(nums[left],nums[r]);
        return r;
    }
}
```