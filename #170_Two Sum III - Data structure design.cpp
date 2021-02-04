class TwoSum {
public:
    /** Initialize your data structure here. */
    unordered_multiset<long int> ms;
    TwoSum() {
        
    }
    
    /** Add the number to an internal data structure.. */
    void add(int number) {
        ms.insert(number);
    }
    
    /** Find if there exists any pair of numbers which sum is equal to the value. */
    bool find(int value) {
        for(auto num : ms){
            int count = num == value - num ? 1 : 0;
            if(ms.count(value - num) > count)
                return true;    
        }
        return false;
    }
};

/**
 * Your TwoSum object will be instantiated and called as such:
 * TwoSum* obj = new TwoSum();
 * obj->add(number);
 * bool param_2 = obj->find(value);
 */