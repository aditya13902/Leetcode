class Bank {
public:
    vector<long long>bal;
    Bank(vector<long long>& balance) {
        bal.push_back(0);
        for(auto ele:balance){
            bal.push_back(ele);
        }
    }
    
    bool transfer(int account1, int account2, long long money) {
        if(account1>bal.size() || account2>bal.size()){
            return false;
        }
        if(bal[account1]<money){
            return false;
        }
        bal[account1]-=money;
        bal[account2]+=money;
        return true;
    }
    
    
    bool deposit(int account, long long money) {
        // long long curr=bal[]
        if(account>bal.size()){
            return false;
        }
        bal[account]+=money;
        return true;
    }
    
    bool withdraw(int account, long long money) {
        if(account>bal.size() || bal[account]<money){
            return false;
        }
        bal[account]-=money;
        return true;
    }
};

/**
 * Your Bank object will be instantiated and called as such:
 * Bank* obj = new Bank(balance);
 * bool param_1 = obj->transfer(account1,account2,money);
 * bool param_2 = obj->deposit(account,money);
 * bool param_3 = obj->withdraw(account,money);
 */