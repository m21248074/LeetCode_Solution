class UndergroundSystem {
private:
    unordered_map<int,pair<string,int>> in;
    unordered_map<string,pair<int,int>> out;
public:
    UndergroundSystem() {
        
    }
    
    void checkIn(int id, string stationName, int t) {
        in[id]=make_pair(stationName,t);
    }
    
    void checkOut(int id, string stationName, int t) {
        auto inInfo=in[id];
        string route=inInfo.first+"_"+stationName;
        int time=t-inInfo.second;
        if(!out.count(route))
            out[route]=make_pair(0,0);
        auto origin=out[route];
        out[route]=make_pair(origin.first+time,origin.second+1);
    }
    
    double getAverageTime(string startStation, string endStation) {
        string route=startStation+"_"+endStation;
        auto result=out[route];
        return (double)result.first/(double)result.second;
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */