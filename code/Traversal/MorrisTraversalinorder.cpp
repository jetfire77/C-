
#include <bits/stdc++.h>
using namespace std;


struct Node
{
  int data;          
  struct Node* right;
  struct Node* left;
  int height;       ///////////////////////////////
};

Node* newNode(int key)
{
  Node* temp = new Node;
  temp->data = key;
  temp->right = NULL;
  temp->left = NULL;
  temp->height = 1; /////////////////////////
  return temp;
}


void inorder(Node *root )
{
  if(root == NULL)
    return;
  
  inorder(root->left);
  
  cout<<root->data<<" ";

  inorder(root->right );

}

void morrisTraversalInorder(Node *root)
{

    while(root != NULL)
    {
      if(root->left == NULL)
            {
              cout<<root->data<<" ";
              root = root->right;
            }

      else {

            Node* predecessor = root->left;

            while(predecessor->right != NULL && predecessor->right != root)
            {
              predecessor = predecessor->right;
            }

            if(predecessor->right == NULL)
            {
              predecessor->right = root;
              root = root->left;
            }

            else
            {
              predecessor->right = NULL;
              cout<<root->data<<" ";
              root= root->right;
            }   
          }
    }


}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  Node* tree = newNode(1);
  tree->left = newNode(2);
  tree->right = newNode(3);
  tree->left->left = newNode(4);
  tree->left->right = newNode(5);
  tree->right->right = newNode(6);
  tree->left->left->right = newNode(7);


  inorder(tree);
  
  cout<<"\n";
  
  morrisTraversalInorder(tree);
  
  



  return 0;
    














}