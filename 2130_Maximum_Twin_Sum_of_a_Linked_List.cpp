// Author: Sabbir Hossain
// Problem Link: https://leetcode.com/problems/maximum-twin-sum-of-a-linked-list

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
 
//  @1st approch using extra O(n) space 
class Solution {
public:
    int pairSum(ListNode* head) {
        vector<int>nodes;
        ListNode *temp=head;
        int maxsum=0;

        while(temp){
            nodes.push_back(temp->val);
            temp=temp->next;
        }

        int l=0,r=nodes.size()-1;
        while(l<r){
            maxsum=max(maxsum,nodes[l++]+nodes[r--]);
        }
        return maxsum;

    }
};
