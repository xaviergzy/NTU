////////////////////////////////////////////////////////////////////

/* This program takes two Linked Lists, merges intersecting elements into a third Linked List,
removes duplicates from that list, sorts them in ascending order, and reverses it. */


#include <stdio.h>
#include <stdlib.h>

////////////////////////////////////////////////////////////////////


typedef struct _listnode{
	int num;
	struct _listnode *next;
} ListNode;
typedef struct _linkedlist{
	ListNode *head;
	int size;
} LinkedList;
typedef struct _dbllistnode{
	int num;
	struct _dbllistnode *pre;
	struct _dbllistnode *next;
} DblListNode;

////////////////////////////////////////////////////////////////////
////////////

void printList(ListNode *head);
ListNode * findNode(ListNode *head, int index);
int insertNode(ListNode **ptrHead, int index, int value);

int RemoveDuplicatesIntersectSortandReverseLL(ListNode **ptrHead, ListNode *head1, ListNode *head2);
void printDblList(DblListNode *head);

////////////////////////////////////////////////////////////////////
////////////

int main()
{
	int i;
	ListNode *head = NULL;
	ListNode *dupRevHead = NULL;
	ListNode *oddHead = NULL;
	ListNode *evenHead = NULL;
	ListNode *list1Head = NULL, *list2Head = NULL;
	ListNode *combAltHead = NULL;
	DblListNode *dblHead = NULL;
	LinkedList llist;
	int size = 0;


	////////////////////////////////////////////////////////////////////////

	printf("\n************** Impossible LL function *******************\n(Remove duplicates, merge intersecting, sort and reverse a LL)\n");
	for (i = 0; i < 10; i++)				//build linked list 1
		insertNode(&list1Head, i, i);
	for (int j = 5; j<18; j++)			//build linked list 2
		insertNode(&list2Head, 0, j);
	printf("List 1:");
	printList(list1Head);
	printf("List 2: ");
	printList(list2Head);
	RemoveDuplicatesIntersectSortandReverseLL(&combAltHead, list1Head, list2Head);
	printf("After implementing the impossible function: ");
	printList(combAltHead);

}

////////////////////////////////////////////////////////////////////
////////////

void printList(ListNode *head){
	ListNode *cur = head;

	if (cur == NULL)
		return;

	printf("the current linked list is:\n");
	while (cur != NULL){
		printf("%d ", cur->num);
		cur = cur->next;
	}
	printf("\n");
}

void printDblList(DblListNode *head){
	if (head == NULL) return;
	while (head != NULL){
		printf("%d ", head->num);
		head = head->next;
	}
	printf("\n");
}

ListNode * findNode(ListNode *head, int index){
	if (head == NULL || index < 0) return NULL;
	while (index > 0){
		head = head->next;
		if (head == NULL)
			return NULL;
		index--;
	}
	return head;
}


int insertNode(ListNode **ptrHead, int index, int value){
	ListNode *pre, *cur;
	// If empty list or inserting first node, need to update head pointer
	if (*ptrHead == NULL || index == 0){
		cur = *ptrHead;
		*ptrHead = malloc(sizeof(ListNode));
		(*ptrHead)->num = value;
		(*ptrHead)->next = cur;
		return 0;
	}
	// Find the nodes before and at the target position
	// Create a new node and reconnect the links
	if ((pre = findNode(*ptrHead, index - 1)) != NULL){
		cur = pre->next;
		pre->next = malloc(sizeof(ListNode));
		pre->next->num = value;
		pre->next->next = cur;
		return 0;
	}
	return -1;
}


////////////////////////////////////////////////////////////////////
////////////

int RemoveDuplicatesIntersectSortandReverseLL(ListNode **ptrHead, ListNode *head1, ListNode *head2){


	ListNode *temp, *cur, *cur2;
	cur = head1;
	int i = 0;

	while (cur != NULL) {

        cur2 = cur;

        while (cur2->next != NULL) {
            if (cur->num == cur2->next->num) {
                temp = cur->next;
                cur2->next = cur->next->next;
                free(temp);
            } else {
            cur2 = cur2->next;
            }
        }

        cur = cur->next;

	}

	cur = head1;
	cur2 = head2;



	while (cur != NULL) {

        while (cur2 != NULL) {

            if (cur->num == cur2->num) {
                insertNode(ptrHead, i, cur->num);
                i++;
                break;
            } else {
                cur2 = cur2->next;
            }

        }

        cur = cur->next;
        cur2 = head2;
	}

	cur = *ptrHead;

	while (cur != NULL) {
        cur2 = cur;

        while (cur2->next != NULL) {
            if (cur->num > cur2->next->num) {
                int temp = cur->num;
                cur2->num = cur2->next->num;
                cur2->next->num = temp;
            } else {
                cur2 = cur2->next;
            }
        }

        cur = cur->next;


	}

	cur = *ptrHead;
	ListNode *pre, *next;

	while (cur != NULL) {
        next = cur->next;
        cur->next = pre;
        pre = cur;
        cur = next;
	}

	*ptrHead = pre;

}


