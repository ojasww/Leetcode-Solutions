class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int start=0, tank=0, sumGas = 0, sumCost=0;
        for(int i=0; i<cost.size(); i++){
            sumGas+=gas[i];
            sumCost+=cost[i];
            tank+=gas[i]-cost[i];
            if(tank<0){
                start = i+1;
                tank=0;
            }
        }
        if(sumGas-sumCost<0)
            return -1;
        else
            return start;
    }
};