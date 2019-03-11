// Edit this file as required
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include "hw18.h"


#ifdef TEST_MAIN
void deleteTreeNode(TreeNode* node)  
{ 
    if (node == NULL) return; 
  
    deleteTreeNode(node->left); 
    deleteTreeNode(node->right); 
    free(node->data); 
    free(node); 
}

int main(int argc, char * * argv)
{
	// check for input error
        if (argc < 2)
        {
          fprintf(stderr, "Wrong input arguments\n");
          return EXIT_FAILURE;
        }
  
	// open the file
        FILE *fptr = fopen(argv[1], "r");
	// input file is in argv[1]

	// n is the element in the file

	// dim is the second element in the file

	// the rest of the data in the file are the datapoints.

	// call LinkedListCreate

	// call FindMin
	
        /*int x;
        int count = 0;
        while(fscanf(f, "%d", &x) == 1)
        {
          count++;
        }*/

        //int *arr = malloc(sizeof(int)*count);

        /*if (arr==NULL)
        {
           fprintf(stderr, "Error in allocating memory\n");
        }*/

        fseek(fptr, 0, SEEK_SET);
        //int index = 0;
        //for (index = 0; index < count; index++)
        //{
        //  fscanf(f, "%d", &arr[index]);
        //}

        int n, dim;
        fscanf(fptr, "%d", &n);
        fscanf(fptr, "%d", &dim);
        
        ListNode * list = NULL;

        LinkedListCreate(&list, n, dim, fptr);
        FindMin(list);
        fclose(fptr);
         
        ListNode* current = list; 
        ListNode* next; 
  
        while (current != NULL)  
        {   
          next = current->next; 
          deleteTreeNode(current->treenode);
          free(current); 
          current = next; 
        }       
}
#endif
