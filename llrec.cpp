#include "llrec.h"

//*********************************************
// Provide your implementation of llpivot below
//*********************************************

void llpivot(Node *&head, Node *&smaller, Node *&larger, int pivot) {
	if (head == nullptr) {
		return;
	}
	smaller = nullptr;
	larger = nullptr;
	llpivot_helper(head, smaller, larger, pivot);
	return;
}

void llpivot_helper(Node *&head, Node *&smaller, Node *&larger, int pivot) {
	if (head == nullptr) {
		return;
	}
	else {
		Node* temp = head->next;
		if (head->val <= pivot) {
			if (smaller != nullptr) {
				smaller = smaller->next;
			}
			smaller = head;
			smaller->next = NULL;
			head = NULL;
			llpivot(temp, smaller->next, larger, pivot);
		}
		else {
			if (larger != nullptr) {
				larger = larger->next;
			}
			larger = head;
			larger->next = NULL;
			head = NULL;
			llpivot(temp, smaller, larger->next, pivot);
		}
	}
}