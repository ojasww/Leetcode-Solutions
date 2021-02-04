/*
// Definition for Employee.
class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};
*/

class Solution {
public:
    int getImportance(vector<Employee*> employees, int id) {
        int sum=0;
        recursion(employees, sum, id);
        return sum;
        
    }
private:
    void recursion(vector<Employee*>& employees, int& sum, int id){
        for(int i=0; i<employees.size(); i++){
            if(id==employees[i]->id){
                sum+=employees[i]->importance;
                for(int j=0; j<employees[i]->subordinates.size(); j++){
                    recursion(employees, sum, employees[i]->subordinates[j]);
                }
            }     
        }
        return;
    }
};