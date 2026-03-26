#pragma once
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

struct ListNode {
	int val;
	ListNode* next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Leetcode21 {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
		if (list1 == nullptr || list2 == nullptr) {
			ListNode* ans;
			ans = (list1 == nullptr) ? list2 : list1;
			return ans;
		}

		ListNode ans(0);
		ListNode* cur = &ans;
			

		while ( list1!=nullptr && list2 != nullptr) {
			cur->next = list1->val >= list2->val ? list2 : list1;
			
			if (list1->val >= list2->val) {
				list2 = list2->next;
			}
			else {
				list1 = list1->next;
			}
			cur = cur->next;
		}
		
		if (list1 == nullptr) {
			cur->next = list2;
		}
		else if (list2 == nullptr) {
			cur->next = list1;
		}
		return ans.next;
    }
};