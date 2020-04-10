#include<stdio.h> 
#include<stdlib.h> 
struct node 
{ 
    int key; 
    struct node *left, *right; 
}; 
struct node *newNode(int item) 
{ 
    struct node *temp =  (struct node *)malloc(sizeof(struct node)); 
    temp->key = item; 
    temp->left = temp->right = NULL; 
    return temp; 
} 
struct node* insert(struct node* node, int key) 
{ 
    if (node == NULL) return newNode(key); 
    if (key < node->key) 
    node->left  = insert(node->left, key); 
    else if (key > node->key) 
    node->right = insert(node->right, key);    
    return node; 
} 
struct node *find_min(struct node *root)
{
    if(root==NULL)
    {
        return 0;
    }
    else if(root->left==NULL)
    {
        return root;
    }
    else
    {
        return(find_min(root->left));
    }
}
struct node* removee(struct node *root,int item)
{
    struct node *temp;
    if(root==NULL)
    {
        printf("the tree is empty");
    }
    else if(item<root->key)
    {
        root->left=removee(root->left,item);
    }
    else if(item>root->key)
    {
        root->right=removee(root->right,item);
    }
    else
    {
        struct node *temp;
        if(root->left==NULL && root->right==NULL)
	    {
		    free(root);
		    return NULL;
	    }
        else if(root->left!=NULL && root->right!=NULL)
        {
            temp=find_min(root->right);
            root->key=temp->key;
            root->right=removee(root->right,root->key);
        }
        else
        {
            temp=root;
            if(root->left==NULL)
            {
                root=root->right;
            }
            else if(root->right==NULL)
            {
                root=root->left;
            }
            free(temp);
        }
        return root;
    }
}
void inorder(struct node *root) 
{ 
    if (root != NULL) 
    { 
    inorder(root->left); 
    printf("%d \n", root->key); 
    inorder(root->right); 
    } 
}
void main() 
{
    int item,k,ch;
    char i;
    struct node *root = NULL; 
    root = insert(root, 3);
    do{
	printf("MENU \n1.Insert\n2.Delete\n3.Display\n4.exit\n");
	scanf("%d",&ch);
	if(ch==1)
	{
    		
        		printf("\nEnter the value :");
        		scanf("%d",&k);
        		insert(root,k);
	}
	else if(ch==2)
	{
		printf("Enter the element to be removed\n");
		scanf("%d",&k);
		root = removee(root, k);
	}
	else if(ch==3)
	{
		printf("Displaying\n");
		inorder(root);
	}
	else if(ch==4){
		exit(0);
	    }
	
	else{
		printf("wrong Input");
	    }
    }while(ch!=4);
}