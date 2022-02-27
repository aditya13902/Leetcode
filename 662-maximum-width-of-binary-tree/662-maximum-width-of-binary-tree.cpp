#define ull unsigned long long
class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        ull maxWidth = 0;
		
		// queue's element will be pair<TreeNode*, int> 
		// first attribute will be storing TreeNode* and int will be the index of the node at particular level
		queue<pair<TreeNode*, int>> q;
       
        q.push({root, 0});
		
        while(!q.empty()) {
            int n = q.size();
            pair<TreeNode*, ull> p = q.front();
            ull start =  p.second, end = p.second;
            
			// exploring all the nodes level wise  and pushing nodes of upcoming level
			// and changing 'end' to keep track of last node at current particular level
			
            while(n--) {
                p = q.front();
                TreeNode *curNode = p.first;
                ull curIdx = p.second;
                end = curIdx;
                
                if(curNode->left != nullptr) q.push({curNode->left, 2*curIdx});
                if(curNode->right != nullptr) q.push({curNode->right, 2*curIdx+1});
                q.pop();
            }
			
            maxWidth = max(maxWidth, end-start+1);
        }
		
        return maxWidth;
    }
};