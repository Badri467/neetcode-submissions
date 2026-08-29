class KthLargest {
public:
    priority_queue<int, vector<int>, greater<int>>pq;
    int k=1;
    KthLargest(int ki, vector<int>& nums) {
        k=ki;
        for(int i=0;i<nums.size();i++){
        pq.push(nums[i]);
        if((i+1)>k)
        pq.pop();
        }
    }
    
    int add(int val) {
        pq.push(val);
        if(pq.size()>k)
        pq.pop();
        return pq.top();
    }
};
