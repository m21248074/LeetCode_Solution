class Solution {
public:
    int minNumberOfHours(int initialEnergy, int initialExperience, vector<int>& energy, vector<int>& experience) {
        int result=0;
        int curExp=initialExperience;
        int totalEnergy=1;
        for(int e:energy)
            totalEnergy+=e;
        result=(totalEnergy>initialEnergy)?totalEnergy-initialEnergy:0;
        for(int exp:experience)
        {
            if(curExp>exp)
                curExp+=exp;
            else
            {
                int trainExp=exp-curExp+1;
                result+=trainExp;
                curExp+=trainExp+exp;
            }
        }
        return result;
    }
};