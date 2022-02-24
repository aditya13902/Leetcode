/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    static bool cmp(ListNode* node1,ListNode* node2){
        return node1->val<node2->val;
    }
    ListNode* sortList(ListNode* head) {
        if(head==NULL){
            return NULL;
        }
        vector<ListNode*>vec;
        ListNode* ptr=head;
        while(ptr!=NULL){
            vec.push_back(ptr);
            ptr=ptr->next;
        }
        sort(vec.begin(),vec.end(),cmp);
        for(int i=0;i<vec.size();i++){
            if(i==vec.size()-1){
                vec[i]->next=NULL;
                continue;
            }
            vec[i]->next=vec[i+1];
        }
        return vec[0];
    }
};