class Solution 
{
public:
	int minOperations(vector<int>& nums, vector<int>& numsDivide) 
	{ 
		int x=numsDivide[0];
		for(auto p:numsDivide) x=__gcd(x,p);
		sort(nums.begin(),nums.end());
		int i;
		for(i=0;i<nums.size();i++)
			if(x%nums[i]==0) break;
		if(i==nums.size()) return -1;
		return i;
	}
};