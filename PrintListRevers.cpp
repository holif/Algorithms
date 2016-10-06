#include<stdio.h>
#include<stdlib.h>
struct ListNode{
	int m_nKey;
	ListNode * n_pNext;
};

void PrintList(ListNode *pHead){
	if(pHead != NULL){
		if(pHead->n_pNext != NULL){
			PrintList(pHead->n_pNext);
		}
		printf("%d\n",pHead->m_nKey);
	}
}
void ListNodeInit(ListNode *pHead){
	int s = 10;	
	ListNode *r;
	r = pHead; 
	while(s > 0){
		ListNode *p;
        p = (ListNode *)malloc(sizeof(ListNode)); 
        p->m_nKey = s;                   
        r->n_pNext = p;                   
        r = p; 
		--s;
	}
	r->n_pNext = NULL;
}
int main(){
	ListNode *pHead;
	pHead = (ListNode*)malloc(sizeof(ListNode));
	if(pHead == NULL){
		exit;
	}
	ListNodeInit(pHead);
	PrintList(pHead->n_pNext);
	return 0;
}
