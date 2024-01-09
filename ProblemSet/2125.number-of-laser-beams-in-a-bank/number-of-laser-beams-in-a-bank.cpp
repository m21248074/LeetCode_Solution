class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int m=bank.size();
        int n=bank[0].length();
        vector<int> data;
        for(int i=0;i<m;i++)
        {
            int cnt=0;
            for(int j=0;j<n;j++)
            {
                if(bank[i][j]=='1')
                    cnt++;
            }
            if(cnt)
                data.push_back(cnt);
        }
        if(data.size()==1) return 0;
        int result=0;
        for(int i=1;i<data.size();i++)
            result+=data[i-1]*data[i];
        return result;
    }
};