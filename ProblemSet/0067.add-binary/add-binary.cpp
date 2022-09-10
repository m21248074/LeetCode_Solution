class Solution {
public:
    string addBinary(string a, string b) {
        string result="";
        int p1=a.length()-1,p2=b.length()-1;
        int sum=0;
        while(p1>=0||p2>=0)
        {
            int t1=0,t2=0;
            if(p1>=0)
            {
                t1=a.at(p1)-'0';
                p1--;
            }
            if(p2>=0)
            {
                t2=b.at(p2)-'0';
                p2--;
            }
            int temp=sum+t1+t2;
            result.insert(result.begin(),(temp%2)+'0');
            sum=(temp)>>1;
        }
        return sum==1?"1"+result:result;
    }
};