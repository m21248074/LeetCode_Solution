class SummaryRanges {
private:
    vector<vector<int>> result;
public:
    SummaryRanges() {}
    
    void addNum(int value) {
        vector<int> newInterval({value,value});
        vector<vector<int>> r;
        int cur=0;
        for(auto i:result)
        {
            if(newInterval[1]+1<i[0])
                r.push_back(i);
            else if(newInterval[0]>i[1]+1)
            {
                r.push_back(i);
                cur++;
            }
            else
            {
                newInterval[0]=min(newInterval[0],i[0]);
                newInterval[1]=max(newInterval[1],i[1]);
            }
        }
        r.insert(r.begin()+cur,newInterval);
        result=r;
    }
    
    vector<vector<int>> getIntervals() {
        return result;
    }
};