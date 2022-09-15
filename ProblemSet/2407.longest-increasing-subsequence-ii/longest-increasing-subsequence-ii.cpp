class SegmentTree
{
    private:
        int n;
        vector<int> tree;
        void update(int node,int start,int end,int i,int value)
        {
            if(start==end)
            {
                tree[node]=value;
                return;
            }
            int mid=(start+end)/2;
            int left_node=2*node+1;
            int right_node=left_node+1; // 2*node+2
            if(start<=i&&i<=mid)
                update(left_node,start,mid,i,value);
            else
                update(right_node,mid+1,end,i,value);
            tree[node]=max(tree[left_node],tree[right_node]);
        }
        int query(int node,int start,int end,int l,int r)
        {
            if(r<start||l>end) return 0; // out of range
            else if(l<=start&&end<=r)
                return tree[node];
            else if(start==end)
                return tree[node];
            int mid=(start+end)/2;
            int left_node=2*node+1;
            int right_node=left_node+1; // 2*node+2
            int sum_left=query(left_node,start,mid,l,r);
            int sum_right=query(right_node,mid+1,end,l,r);
            return max(sum_left,sum_right);
        }
    public:
        SegmentTree(int n)
        {
            this->n=n;
            tree=vector<int>(4*n,0);
        }
        int query(int left,int right)
        {
            return query(0,0,n-1,left,right);
        }
        void update(int i,int value)
        {
            update(0,0,n-1,i,value);
        }
};

class Solution {
public:
    int lengthOfLIS(vector<int>& nums, int k) {
        int n=*max_element(nums.begin(),nums.end());
        SegmentTree st(n);
        int result=1;
        for(int num:nums)
        {
            num-=1;
            int preMax=st.query(max(0,num-k),num-1);
            st.update(num,preMax+1);
            result=max(result,preMax+1);
        }
        return result;
    }
};