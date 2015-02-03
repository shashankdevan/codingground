#include <iostream>
#include <stdlib.h>
#include <queue>
#include <fstream>
#include "RandomBST.h"
using namespace std;

int main(int argc, char * argv[])
{
  RandomisedBST rbst;
  ifstream f;
  char temp;
  int a;
  cout << "L is :" << argv[1] << endl;
  f.open(argv[2]);
  while(f >> a){
   rbst.insert(a);       
 }
  rbst.levelOrderPrint();
}
