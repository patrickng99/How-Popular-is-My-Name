//-----------------------------------------------------------
//  Purpose:    Implementation of BinaryTree class.
//  Author:     Patrick Karangwa
//-----------------------------------------------------------
#include "tree.h"
#include <stdlib.h>

//-----------------------------------------------------------
// Constructor function.
//-----------------------------------------------------------
BinaryTree::BinaryTree()
{
   Root = NULL;
}

//-----------------------------------------------------------
// Destructor function helper function.
//-----------------------------------------------------------
void BinaryTree::DestroyHelper(Node * Tree)
{
   // Delete node and its children
   if (Tree != NULL)
   {
      DestroyHelper(Tree->Left);
      DestroyHelper(Tree->Right);
      delete Tree;
   }
}

//-----------------------------------------------------------
// Destructor function.
//-----------------------------------------------------------
BinaryTree::~BinaryTree()
{
   // Call tree destroy function
   DestroyHelper(Root);
}

//-----------------------------------------------------------
// Search helper function.
//-----------------------------------------------------------
bool BinaryTree::SearchHelper(string name, Node * Tree)
{
   // Data value not found 
   if (Tree == NULL){
      cout << "Could not find the name." << endl;
      return false;
   }
   // Data value found 
   else if (Tree->Name == name){
      cout << Tree->Name << " ";
      cout << Tree->Count << " ";
      cout << Tree->Percentage << " ";
      cout << Tree->Rank << " ";
      cout << endl;
      return true;
   }

   // Recursively search for data value
   else if (Tree->Name > name)
      return (SearchHelper(name, Tree->Left));
   else 
      return (SearchHelper(name, Tree->Right));
}

//-----------------------------------------------------------
// Search for data in the binary tree.
//-----------------------------------------------------------
bool BinaryTree::Search(string name)
{
   // Call tree searching function
   return (SearchHelper(name, Root));
}

//-----------------------------------------------------------
// Insert helper function.
//-----------------------------------------------------------
bool BinaryTree::InsertHelper(string name, string count, string percentage,
    string rank, Node * &Tree)
{
   // Insert data into the tree
   if (Tree == NULL)
   {
      Tree = new Node;
      Tree->Name = name;
      Tree->Count = count;
      Tree->Percentage = percentage;
      Tree->Rank = rank;
      Tree->Left = NULL;
      Tree->Right = NULL;
      return true;
   }

   // Recursively search for insertion position
   else if (Tree->Name > name)
      return (InsertHelper(name, count, percentage, rank, Tree->Left));
   else 
      return (InsertHelper(name, count, percentage, rank, Tree->Right));
}

//-----------------------------------------------------------
// Insert data into the binary tree.
//-----------------------------------------------------------
bool BinaryTree::Insert(string name, string count, string percentage, string rank)
{
   // Call tree insertion function
   return (InsertHelper(name, count, percentage, rank, Root));
}

//-----------------------------------------------------------
// Delete a single node from the binary tree.
//-----------------------------------------------------------
bool BinaryTree::DeleteNode(Node * &Tree)
{
   Node *Temp = Tree;

   // Node has 0 children
   if ((Tree->Left == NULL) && (Tree->Right == NULL))
      Tree = NULL;

   // Node has 1 child
   else if (Tree->Left == NULL)
      Tree = Tree->Right;
   else if (Tree->Right == NULL)
      Tree = Tree->Left;


   // Node has 2 children
   else
   {
      // Find leftmost node in right subtree
      Node *Parent = Tree;
      Temp = Tree->Right;
      while (Temp->Left != NULL)
      {
    	 Parent = Temp;
    	 Temp = Parent->Left;
      }

      // Replace deleted data with leftmost value
      if (Parent == Tree)
	    Parent->Right = Temp->Right;
      else
	    Parent->Left = Temp->Right;
      Tree->Name = Temp->Name;
      Tree->Count = Temp->Count;
      Tree->Percentage = Temp->Percentage;
      Tree->Rank = Temp->Rank;
   }

   // Delete node
   delete Temp;
   return true;
}

//-----------------------------------------------------------
// Delete helper function.
//-----------------------------------------------------------
bool BinaryTree::DeleteHelper(string name, Node * &Tree)
{
   // Data value not found
   if (Tree == NULL)
      return false;

   // Data value found and deleted
   else if (Tree->Name == name)
      return (DeleteNode(Tree));

   // Recursively search for node to delete
   else if (Tree->Name > name)
      return (DeleteHelper(name, Tree->Left));
   else 
      return (DeleteHelper(name, Tree->Right));
}

//-----------------------------------------------------------
// Delete data from the binary tree.
//-----------------------------------------------------------
bool BinaryTree::Delete(string name)
{
   // Call tree deletion function
   return (DeleteHelper(name, Root));
}

//-----------------------------------------------------------
// Print helper function.
//-----------------------------------------------------------
void BinaryTree::PrintHelper(Node * Tree)
{
   // Check terminating condition
   if (Tree != NULL)
   {
      // Print left subtree
      PrintHelper(Tree->Left);

      // Print node value
      cout << Tree->Name << " ";
      cout << Tree->Count << " ";
      cout << Tree->Percentage << " ";
      cout << Tree->Rank << " ";
      cout << endl;

      // Print right subtree
      PrintHelper(Tree->Right);
   }
}

//-----------------------------------------------------------
// Print all records in the binary tree.
//-----------------------------------------------------------
void BinaryTree::Print()
{
   // Call tree printing function
   PrintHelper(Root);
   cout << endl;
}

