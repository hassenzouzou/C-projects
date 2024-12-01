#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct Node{
    int data;
    struct Node*  right;
    struct Node*  left;
};
int COUNTER1;
int COUNTER2;
struct Node* createNode(int c){
    struct Node* temp=(struct Node*) malloc(sizeof(struct Node));
    temp->data=c;
    temp->right=NULL;
    temp->left=NULL;
    return temp;
}
//it will display the values in increasing orer.
void inOrderTraversal(struct Node* root){
    if(root!=NULL){
        inOrderTraversal(root->left);
        printf(" %d - ",root->data);
        inOrderTraversal(root->right);
    }
}

bool existV1(struct Node* root,int x){
  COUNTER2++;
  if(root==NULL) return false;
  else if(root->data==x) return true;
  else { 
      /* bool found=exist(root->left,x);
      if(found==true) return true;
      else {
          return exist(root->right,x);
      }*/
      return existV1(root->left,x)||existV1(root->right,x);
  }
}
bool exist(struct Node* root, int x){
    COUNTER1++;
    if(root==NULL) return false;
    else if(root->data==x) return true;
    else if(x>root->data) return exist(root->right,x);
    else return exist(root->left,x);
}
bool deadTree(struct Node* root){
    if(root==NULL)return true;
    else if((root->left!=NULL)&&(root->right!=NULL)) return false;
    else if(root->left!=NULL) return deadTree(root->left);
    else return deadTree(root->right);
}
int countLeaves(struct Node* root){
    if(root==NULL) return 0;
    else if((root->left==NULL)&&(root->right==NULL))
            return 1;
    else return countLeaves(root->left)+countLeaves(root->right);
}

//find the maximum value in BST (Binary Search Tree)
int max(struct Node* root){
    if(root==NULL){
        printf("Error the tree is empty");
        return -1;
    }
    else {
        if(root->right==NULL) return root->data;
        else return max(root->right);
    }
}
int max_iterative(struct Node* root){
    struct Node* p=root;
    if(p!=NULL){
        while (p->right!=NULL)
        {
            p=p->right;
        }
        return p->data;
    }
}

int min(struct Node* root){
    if(root==NULL){
        printf("Error the tree is empty!");
        return -1;
    }
    else{
        if(root->left==NULL) return root->data;
        else return min(root->left);
    }
}
int min_iterative(struct Node* root){
    struct Node* p=root;
    if(p!=NULL){
        while (p->left!=NULL)
        {
            p=p->left;
        }
        return p->data;
    }
}
//compute the sum of the values of a binary tree.
int sum(struct Node* root){
    if(root==NULL) return 0;
    else return root->data+sum(root->left)+sum(root->right);
}
//Counte the number of occurence of X in the binary tree.
int nbrOC(struct Node* root,int x){
    if(root==NULL) return 0;
    else if(root->data==x)
          return 1+nbrOC(root->left,x)+nbrOC(root->right,x);
        else return nbrOC(root->left,x)+nbrOC(root->right,x);
}

void PrintDescendants(struct Node* root, int x) {
    if (root == NULL) {
        return;
    }
    if (root->data == x) {
        printf("Descendants of %d are: ", x);
        inOrderTraversal(root->left);
        inOrderTraversal(root->right);
        return;
    } else {
        PrintDescendants(root->left, x);
        PrintDescendants(root->right, x);
    }
}



int main(){
    // left < root < right
    struct Node* root=NULL;
    root=createNode(4);
    root->left=createNode(2);
    root->left->left=createNode(1);
    root->left->right=createNode(3);
    root->left->right->left=createNode(7);
    root->left->right->right=createNode(7);
    root->right=createNode(6);
    root->right->left=createNode(5);
    root->right->right=createNode(7);
    root->right->right->right=createNode(8);
    root->right->right->right->left=createNode(7);
    inOrderTraversal(root);
    printf("\nPlease enter the value of the node you are looking for?");
    int x;
    scanf("%d",&x);
    COUNTER1=0;
    COUNTER2=0;
    bool found=exist(root,x);
    bool foundV1=existV1(root,x);
    if(found)printf("\n%d exist ",x);
    else printf("\n%d Does'nt exist",x);
    printf("\n Counter1=%d",COUNTER1);
    printf("\n Counter2=%d",COUNTER2);
    bool isDead=deadTree(root);
    if(isDead)printf("\nThe Tree is Dead!");
    else printf("\nThe Tree is alive!");
    int numberOfLeaves=countLeaves(root);
    printf("\n The number of leaves is %d",numberOfLeaves);
    printf("\nThe maximum value of the tree is %d",max(root));
    printf("\nThe minimum value of the tree is %d",min(root));
    printf("\n min %d  max %d",min_iterative(root),max_iterative(root));
    printf("\nThe sum of the nodes value is %d",sum(root));
    printf("Please enter the value of the node to count its occurences");
    scanf("%d",&x);
    printf("\n%d exists in the tree %d times",x,nbrOC(root,x));
    printf("\nPlease enter the value of the node to print its descendants: ", findAndPrintDescendants(root, x));
    scanf("%d", &x);
}