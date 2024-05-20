class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        int n=s.length();
        int cnt1=count(s.begin(),s.end(),'1');
        return string(cnt1-1,'1')+string(n-cnt1,'0')+"1";
    }
};