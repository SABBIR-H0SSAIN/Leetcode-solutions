// Author: Sabbir Hossain
// Problem Link: https://leetcode.com/problems/merge-k-sorted-lists

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

 // @1st Approch ( Brute Force Solution )

class Solution {

    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        
        if(!list1 && !list2 ) return nullptr;
        if(!list1) return list2;
        if(!list2) return list1;
        
        ListNode *dummy= new ListNode(-1);
        ListNode *ptr=dummy;
        
        while(list1 && list2){
            if(list1->val < list2->val){
                ptr->next=list1;
                list1=list1->next;
            }else{
                ptr->next=list2;
                list2=list2->next;
            }
            ptr=ptr->next;
        }
        if(list1)ptr->next=list1;
        else if(list2) ptr->next=list2;
        return dummy->next;
    }

public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(!lists.size()) return nullptr;

        ListNode *res=lists[0];
        for(int i=1;i<lists.size();i++){
           res = mergeTwoLists(res,lists[i]);
        }
        return res;
    }
};

// @2nd Approch ( Using Min Heap )

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {

        if(!lists.size()) return nullptr;

        ListNode *dummy = new ListNode(-1);
        ListNode *ptr = dummy;
        priority_queue<pair<int,ListNode*>,vector<pair<int,ListNode *>>,greater<pair<int,ListNode *>>> pq;

        for(int i=0;i<lists.size();i++){
            if(lists[i]){
                pq.push({lists[i]->val,lists[i]});
            }
        }

        while(!pq.empty()){

            ListNode *top=pq.top().second;
            ptr->next = top;
            pq.pop();

            if(top->next){
                pq.push({top->next->val,top->next});
            }

            ptr=ptr->next;
        }

        return dummy->next;
    }
};
