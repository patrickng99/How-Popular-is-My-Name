//-----------------------------------------------------------
//  Purpose:    Header file for the BinaryTree class.
//  Author:     Patrick Karangwa
//-----------------------------------------------------------

#include <iostream>
#include <fstream>
using namespace std;

//-----------------------------------------------------------
// BinaryTree data node definition
//-----------------------------------------------------------
class Node
{
 public: 
   string Name;
   string Count;
   string Percentage;
   string Rank;
   Node *Left;
   Node *Right;
};

//-----------------------------------------------------------
// Define the BinaryTree class interface 
//-----------------------------------------------------------
class BinaryTree
{
 public:
   // Constructor functions
   BinaryTree();
  ~BinaryTree();

   // General binary tree operations
   bool Search(string name);
   bool Insert(string name, string count, string percentage, string rank);
   bool Delete(string name);
   void Print();

 private:
   // Helper functions
   void DestroyHelper(Node * Tree);
   bool SearchHelper(string name, Node * Tree);
   bool InsertHelper(string name, string count, string percentage, string rank, 
    Node * &Tree);
   bool DeleteNode(Node * &Tree);
   bool DeleteHelper(string name, Node * &Tree);
   void PrintHelper(Node * Tree);

   // Tree pointer
   Node *Root;
};