class KthLargest {
public:
    priority_queue<int, vector<int>, greater<int> > q;
    int k;
    KthLargest(int k, vector<int>& nums) {
        this->k = k;
        for(auto num: nums){
            this->add(num);
        }
    }
    
    int add(int val) {
        int i = 0;
        this->q.push(val);
        if(this->q.size() > this->k){
            this->q.pop();
        }
        return this->q.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */