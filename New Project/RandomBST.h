#include <iostream>
#include <stdlib.h>
#include <queue>

using namespace std; 

  class node
   {
       public:
       int key;  
       int size; 
       node* left; 
       node* right; 
       node(int k);
   };
   
   class RandomisedBST {
       node* root;
       node* r;
       int height;
       int randomisedHeight;
       public:
       RandomisedBST();
       int getSize(node* p);
       void adjustSize(node* p);
       node* rotateRight(node* p);
       node* rotateLeft(node* p);
       node* insertAtRoot(node* p, int k);
       void insert(int k);
       void BSTInsert(int k);
       node * BSTInsert(node*p, int k);
       void randomisedInsert(int k);
       node* randomisedInsert(node* p, int k);
       void levelOrderPrint();
       int levelOrderPrint(node* p);
   };