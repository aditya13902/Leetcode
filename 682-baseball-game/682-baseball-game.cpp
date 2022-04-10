class Solution {
public:
    int calPoints(vector<string>& ops) {
        vector<int> record;
        int sum = 0;
        
        for(string op : ops) {
            if(op == "+") {
                record.push_back(record[record.size()-1]+record[record.size()-2]);
            }   else if(op == "D") {
                record.push_back(2*record[record.size()-1]);
            } else if(op == "C") {
                record.pop_back();
            } else {
                record.push_back(stoi(op));
            }
        }
        
        for(int num : record) {
            sum += num;
        }
        
        return sum;
    }
};