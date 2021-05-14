#include<stdio.h>
#include<stdlib.h>

struct BSTNode{
    int data ;
    struct BSTNode *left;
    struct BSTNode *right;
};

struct BSTNode *START  = NULL;

void Insert(struct BSTNode *root,int info){
    struct BSTNode *n = malloc(sizeof(struct BSTNode));
    n->left = NULL ;
    n->right  = NULL ;
    n->data = info ;
    if(root==NULL){
        START = n ;
    }
    else{
        while(root != NULL){
            if(root->data > info ){
                if(root->left == NULL){
                    root->left = n ;
                    root = n->left;
                    }
                else                   
                root = root->left;
            }            
            else if(root->data< info){
                if(root->right == NULL){
                    root->right = n;
                    root = n->right;
                    }
                else    
                root = root->right;                           
            }   
        }
    }
}

struct BSTNode* Findmax(struct BSTNode *root){
    if(root->right == NULL)
        return(root);
    else if(root->right != NULL)
        return(Findmax(root->right));                
}

struct BSTNode* Delete(struct BSTNode *root,int info){
    struct BSTNode *temp;
    if(root == NULL)
        printf("\nNo such element exist");
    else if(info < root->data)
        root->left = Delete(root->left,info);
    else if(info > root->data)
        root->right =Delete(root->right,info);    
    else{// element found
        if(root->left && root->right){
            temp = Findmax(root->left);
            root->data = temp->data;
            root->left = Delete(root->left,root->data);
        }
        else{ 
            //one or none child
            temp = root ;
            if(root->left == NULL)
                root = root -> right ;
            else if(root->right == NULL)
                root = root->left;
            free(temp);        
        }
    }
return(root);
}

void Traverse(struct BSTNode *root){ //Preorder traversing 
    if(root){
    printf(" %d ",root->data);
    Traverse(root->left);
    Traverse(root->right);
    }
}

int menu(){
    int ch ; 
    printf("\n1.Add value to the Binary Tree");
    printf("\n2.view Tree");
    printf("\n3.Delete item");
    printf("\nenter your choice");
    scanf("%d",&ch);
    return (ch);
}

void main(){
int data;   
    while(1){
        switch (menu()){
            case 1:
            printf("\nenter a value");
            scanf("%d",&data);
            Insert(START,data);
            break;
            case 2:
            Traverse(START);
            break;
            case 3:
            printf("\nenter value to delete");
            scanf("%d",&data);
            START = Delete(START,data);
            break;
            default:
            printf("\ninvalid choice");
        }
    }
}