//-----------------------------------------------------------
//  Purpose:    Main program for the BinaryTree class.
//  Author:     Patrick Karangwa
//-----------------------------------------------------------

#include "tree.h"

//-----------------------------------------------------------
// Main program tests the BinaryTree class.
//-----------------------------------------------------------
int main()
{
   //Initializing variables
   BinaryTree tree;
   string fileName;
   string name;
   string count;
   string percentage;
   string rank;
   
   //Testing with files
   cout << "Enter the file name" << endl;
   cin >> fileName;
   ifstream din;
   din.open(fileName);
   if (din.fail()){ 
        cout << "Error! " << fileName << " is not in this directory." << endl;
        return 0;
   }        
   while (din >> name >> count >> percentage >> rank){
       tree.Insert(name, count, percentage, rank);
   }
   int action;
   while(action != -1){
       cout << "Choose which action you want to execute:"<< endl;
       cout << "1: Search name\n2: See the list\n3: Quit" << endl;
       cin >> action;
       
       switch (action){
           case 1:
                cout << "Type the name you want to search: ";
                cin >> name;
                //convert the first letter to uppercase
                name[0] = toupper(name[0]);
                cout << "Your search: ";
                tree.Search(name);
                break;
                
           case 2:
                tree.Print();
                break;
           
           case 3:
                cout << "Quitting..." << endl;
                action = -1;
                break;
                
           default:
                cout << "Invalid input, please try again." << endl;
                break;
       }
   }
   
   return 0;
}