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
   node(int k) { 
       key = k; 
       left = right = NULL; 
       size = 1; 
   }
};

class RandomisedBST {
   node* root;
   node* r;
   public:
   RandomisedBST(){
       root = NULL;
   }
   
   int getSize(node* p){
       if( !p ) return 0; 
       return p->size; 
   }
   
   void adjustSize(node* p){
       p->size = getSize(p->left)+getSize(p->right)+1; 
   }
   
   node* rotateRight(node* p){
       node* q = p->left; 
       if( !q ) return p; 
       p->left = q->right; 
       q->right = p; 
       q->size = p->size; 
       adjustSize(p); 
       return q; 
   }
   
   node* rotateLeft(node* p){
       node* q = p->right;
       if( !q ) return p;
       p->right = q->left;
       q->left = p;
       q->size = p->size;
       adjustSize(p);
       return q;
   }
   
   node* insertAtRoot(node* p, int k){
       if( !p ) return new node(k); 
       if( k<p->key ) {
           p->left = insertAtRoot(p->left,k); 
           return rotateRight(p); 
       }
       else {
           p->right = insertAtRoot(p->right,k);
           return rotateLeft(p);
       }
   }
   
   void randomisedInsert(int k){
       root = randomisedInsert(root,k);
   }
   
   node* randomisedInsert(node* p, int k){
       if(!p) {
           p = new node(k);
           return p;
       }
       srand(123456789);
       int r = rand() % (p->size) + 1;
       cout << "r is " << r << " inserting "<< p->key <<endl;
      if( r == p->size ) 
           return insertAtRoot(p,k); 
       if( p->key>k ) 
           p->left = randomisedInsert(p->left,k); 
       else
           p->right = randomisedInsert(p->right,k); 
       adjustSize(p); 
       return p; 
   }
   
   void levelOrderPrint(){
       if (!root) return;
       int level = 0;
       queue<node*> currentLevel, nextLevel;
       currentLevel.push(root);
       cout <<"Level " << level << ": " ;
       while (!currentLevel.empty()) {
           node *currNode = currentLevel.front();
           currentLevel.pop();
           if (currNode) {
               cout << currNode->key << " ";
               nextLevel.push(currNode->left);
               nextLevel.push(currNode->right);
           }
           if (currentLevel.empty()) {
               cout << endl;
               level++;    
               swap(currentLevel, nextLevel);
               if(currentLevel.empty() == false)
                   cout <<"Level " << level << ": " ;
           }
       }
   }
};

int main()
{
  RandomisedBST rbst;
  rbst.randomisedInsert(1);
  rbst.levelOrderPrint();
  rbst.randomisedInsert(3);
  rbst.levelOrderPrint();
  rbst.randomisedInsert(5);
  rbst.levelOrderPrint();
}