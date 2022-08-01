class NumArray {
private:
    int n;
    vector<int> segmentTree;
public:
    NumArray(vector<int>& nums) {
        n=nums.size();
        segmentTree=vector<int>(n,0);
        for(int num:nums)
            segmentTree.push_back(num);
        for(int i=n-1;i>=0;i--)
            segmentTree[i]=segmentTree[2*i]+segmentTree[2*i+1];
    }
    void update(int index, int val) {
        int i=index+n;
        segmentTree[i]=val;
        while(i>0)
        {
            segmentTree[i/2]=segmentTree[i]+segmentTree[i^1];
            i/=2;
        }
    }
    int sumRange(int left, int right) {
        int result=0;
        for(left+=n,right+=n;left<=right;left/=2,right/=2)
        {
            if((left&1)==1)
                result+=segmentTree[left++];
            if((right&1)==0)
                result+=segmentTree[right--];
        }
        return result;
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */