/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 * �鲢�����㷨 
 */
class Solution {
public:
    ListNode *sortList(ListNode *head) {
        //ListNode* merge( ListNode *leftPtr, ListNode *rightPtr );
          
          
        if( !head || !head->next ) return head;
        else
        {
            ListNode *midPtr,  *rightPtr, *leftPtr ;
            ListNode *newHead ;
            ListNode *slowPtr, *fastPtr ;
            slowPtr = fastPtr = head ;

           //���ֻ��һ����㣬��������fast->next->next
           while(  fastPtr->next && fastPtr->next->next )
            {
                slowPtr = slowPtr->next ;
                fastPtr = fastPtr->next->next ;
            }
            midPtr = slowPtr ;
            rightPtr = midPtr->next ;
            midPtr->next = NULL ;
            leftPtr = head ;  

            leftPtr = sortList( leftPtr)  ;//�����
            rightPtr = sortList( rightPtr  ) ;//���ұ�
            newHead = merge(  leftPtr , rightPtr  ) ;//�ϲ�Ϊ������

            return newHead ;         
        }
      }
    
    
    ListNode* merge( ListNode *leftPtr, ListNode *rightPtr )
    {

        ListNode *newPtr = NULL , *newHead = NULL ;

        if( leftPtr->val < rightPtr->val )
        {
            newPtr = leftPtr ;
            leftPtr = leftPtr->next ;   
        }
        else
        {
            newPtr = rightPtr ;
            rightPtr = rightPtr->next ;
        }
        newHead = newPtr ;

        //��ʼ��leftPtr��rightPtrһ����Ϊ��
        while( leftPtr && rightPtr )
        {
            if(  leftPtr->val < rightPtr->val  )
            {
                 newPtr->next = leftPtr ;
                 leftPtr = leftPtr->next ;
            }
            else
            {
                newPtr->next = rightPtr ;
                rightPtr = rightPtr->next ;               
            }
            newPtr = newPtr->next ;
        }

        if(  leftPtr   )//���������ʣ��ڵ�
        {
            newPtr->next = leftPtr ;    
        }
        if( rightPtr )
        {
            newPtr->next = rightPtr ;
        }
        return newHead ;  
    }
    
};
