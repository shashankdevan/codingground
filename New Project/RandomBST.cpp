#include <iostream>
#include <stdlib.h>
#include <queue>
#include "RandomBST.h"
using namespace std;

node :: node(int k) { 
            key = k; 
            left = right = NULL; 
            size = 1; 
}
    

RandomisedBST :: RandomisedBST(){
    root = NULL;
    r = NULL;
    height = 0;
    randomisedHeight = 0;
    srand(123456789);
}
    
int RandomisedBST :: getSize(node* p){
    if( !p ) return 0; 
    return p->size; 
}

void RandomisedBST :: adjustSize(node* p){
    p->size = getSize(p->left)+getSize(p->right)+1; 
}

node* RandomisedBST :: rotateRight(node* p){
    node* q = p->left; 
    if( !q ) return p; 
    p->left = q->right; 
    q->right = p; 
    q->size = p->size; 
    adjustSize(p); 
    return q; 
}

node* RandomisedBST :: rotateLeft(node* p){
    node* q = p->right;
    if( !q ) return p;
    p->right = q->left;
    q->left = p;
    q->size = p->size;
    adjustSize(p);
    return q;
}

node* RandomisedBST :: insertAtRoot(node* p, int k){
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

void RandomisedBST :: insert(int k){
    BSTInsert(k);
    randomisedInsert(k);
}

void RandomisedBST :: BSTInsert(int k){
    r = BSTInsert(r,k);
}
node * RandomisedBST :: BSTInsert(node*p, int k){
    if(!p) {
        p = new node(k);
        return p;
    }
    if(k < p->key)
        p->left = BSTInsert(p->left,k);
    else
        p->right = BSTInsert(p->right,k);
    return p; 
}
void RandomisedBST :: randomisedInsert(int k){
    root = randomisedInsert(root,k);
}

int RandomisedBST :: nextInt(){
    if(root == NULL){
        return (0 + 1);
    }
    return rand() % getSize(root) + 1;
}
node* RandomisedBST :: randomisedInsert(node* p, int k){
    if(!p) {
        p = new node(k);
        return p;
    }
    int r = nextInt();
    if( r == p->size ) 
        return insertAtRoot(p,k); 
    if( p->key>k ) 
        p->left = randomisedInsert(p->left,k); 
    else
        p->right = randomisedInsert(p->right,k); 
    adjustSize(p); 
    return p; 
}

void RandomisedBST :: levelOrderPrint(){
    int l = levelOrderPrint(r);
    int level = levelOrderPrint(root);
    cout << "Height of normal BST is " << (l -1) << endl;
    cout << "Height of Randomised BST is " << (level - 1) << endl; 
}
int RandomisedBST :: levelOrderPrint(node* p){
    if (!p) return 0;
    int level = 0;
    queue<node*> currentLevel, nextLevel;
    currentLevel.push(p);
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
    level--;
    return level;
}
