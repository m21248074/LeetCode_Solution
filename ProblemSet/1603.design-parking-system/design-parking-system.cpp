class ParkingSystem {
private:
    vector<int> size;
public:
    ParkingSystem(int big, int medium, int small) {
        size=vector<int>({big,medium,small});
    }
    bool addCar(int carType) {
        if(!size[carType-1])
            return false;
        size[carType-1]--;
        return true;
    }
};

/**
 * Your ParkingSystem object will be instantiated and called as such:
 * ParkingSystem* obj = new ParkingSystem(big, medium, small);
 * bool param_1 = obj->addCar(carType);
 */