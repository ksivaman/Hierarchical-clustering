//edit this file as required
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include "hw18.h"

//Do Not Change this function
void PrintAnswer(ListNode* head, ListNode* min1, ListNode* min2)
{
	ListNode* temp = head;
	int i;
	while(temp!=NULL)
	{
		i = 0;
		while(i < head -> treenode->dimension)
		{
			if(i == 0)
				printf("(%d, ", temp->treenode->data[i]);
			else if(i == head -> treenode->dimension-1)
				printf("%d)\n", temp->treenode->data[i]);
			else
				printf("%d, ", temp->treenode->data[i]);
			i+=1;

		}
		temp = temp->next;
	}

	i = 0;
	while(i < head -> treenode->dimension)
	{
		if(i == 0)
			printf("(%d, ", min1->treenode->data[i]);
		else if(i == head -> treenode->dimension-1)
			printf("%d) <-> ", min1->treenode->data[i]);
		else
			printf("%d, ", min1->treenode->data[i]);
		i+=1;
	}

	i = 0;
	while(i < head -> treenode->dimension)
	{
		if(i == 0)
			printf("(%d, ", min2->treenode->data[i]);
		else if(i == head -> treenode->dimension-1)
			printf("%d)\n", min2->treenode->data[i]);
		else
			printf("%d, ", min2->treenode->data[i]);
		i+=1;
	}
}

/*
YOU CAN EDIT BELOW THIS COMMENT
*/

#ifdef TEST_MIN
void FindMin(ListNode* head)
{
	// find pair of ListNodes with least distance between them.
	// call print Function
        ListNode * l1 = head;
        ListNode * l2 = head->next;
        ListNode * min1 = head;
        ListNode * min2 = head;
        int minDist = FindDist(l1->treenode, l2->treenode);
        int currDist;

        while (l1->next != NULL)
        {
          l2 = l1->next; 
          while (l2 != NULL)
          {
            currDist = FindDist(l1->treenode, l2->treenode);   
            if (currDist <= minDist)
            {
              minDist = currDist;
              int l = 0;
              while (l<(l1->treenode)->dimension)
              {
                if ((l1->treenode)->data[l] > (l2->treenode)->data[l]) 
                {
                  min1 = l2;
                  min2 = l1;
                  break;
                }
                else if ((l1->treenode)->data[l] < (l2->treenode)->data[l])
                {
                  min1 = l1;
                  min2 = l2;
                  break; 
                }
                else 
                {
                  l++;
                }          
              }             
            }
            l2 = l2->next;
          }
          l1 = l1->next;
        }

        PrintAnswer(head, min1, min2);
	/*
	ENSURE the 2nd parameter of the print function (min1) is smaller than
	the 3rd parameter (min2). 
	Look at README, and expected output for more details.
	*/

}
#endif


#ifdef TEST_DIST
int FindDist(TreeNode* x, TreeNode* y)
{
	//find the eucledian distance between
	// x->data and y->data
	// DO NOT FIND SQUARE ROOT (we are working with int)
	// return the distance
	int sum = 0;
        int temp;
  	int lcv;
  	for (lcv=0 ;lcv< (x->dimension); lcv++)
  	{
          temp = (x->data[lcv])-(y->data[lcv]);
    	  sum+=temp*temp;
  	}
  	return sum;
}
#endif


#ifdef TEST_CREATENODE
ListNode* CreateNode(int n, int dim, int* arr)
{
	// check for malloc error
        ListNode* list = malloc(sizeof(ListNode));
        TreeNode* tree = malloc(sizeof(TreeNode));
        tree->left=NULL;
        tree->right=NULL;
        tree->dimension=dim;
        tree->data = malloc(dim*sizeof(int));
        int j = 0;
        for (j=0; j<dim; j++)
        {
          tree->data[j] = arr[j]; 
        }
        list->treenode = tree;
        list->next = NULL;
        return list;       
	// initialize dim
	// both left and right childern will be NULL
	// allocate memory for data
	// return a ListNode
}
#endif


#ifdef TEST_LINKEDLISTCREATE
void LinkedListCreate(ListNode ** head, int n, int dim, FILE* fptr)
{
	// create temp node using CreateNode
	// read from file into an array, pass array to CreateNode
	// assign temp to that node

        int *arr = malloc(sizeof(int)*dim);

        if (arr==NULL)
        {
           fprintf(stderr, "Error in allocating memory\n");
        }

        int index=0;
        for (index = 0; index < dim; index++)
        {
          fscanf(fptr, "%d", &arr[index]);
        }
        
        ListNode * temp = CreateNode(n, dim, arr);

        *head = temp; 

        for (int k = 0; k< n-1; k++)
        {
          for (index = 0; index < dim; index++)
          {
            fscanf(fptr, "%d", &arr[index]);
          }
          temp->next = CreateNode(n,dim,arr);
          temp = temp->next; 
        }
        free(arr);               
	// use a loop to create nodes for the remaining elements of the list.
}
#endif
