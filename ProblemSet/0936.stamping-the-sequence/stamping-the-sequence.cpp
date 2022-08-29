class Solution {
public:
    vector<int> movesToStamp(string stamp, string target) {
        vector<int> result;
        int total=0;
        int n=stamp.length();
        while(true)
        {
            bool isStamped=false;
            for(int i=n;i>0;i--)
            {
                for(int j=0;j<=n-i;j++)
                {
                    string t=string(j,'?')+stamp.substr(j,i)+string(n-i-j,'?');
                    auto pos=target.find(t);
                    while(pos!=string::npos)
                    {
                        result.push_back(pos);
                        isStamped=true;
                        total+=i;
                        fill(begin(target)+pos,begin(target)+pos+n,'?');
                        pos=target.find(t);
                    }
                }
            }
            if(!isStamped) break;
        }
        reverse(result.begin(),result.end());
        return (total==target.length())?result:vector<int>();
    }
};