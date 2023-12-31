// Test driver
#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
#include <cstring>
#include <cstdlib>

#include "unsorted.h"

using namespace std;
void PrintList(ofstream& outFile, UnsortedType& list);
void PrintString(ofstream& dataFile, string& msg);

int main()
{

  ifstream inFile;       // file containing operations
  ofstream outFile;      // file containing output
  string inFileName;     // input file external name
  string outFileName;    // output file external name
  string outputLabel;     
  string command;        // operation to be executed
  
  int number;
  ItemType item;
  ItemType pivotItem;
  ItemType itemSplit; // item to be split on
  UnsortedType list;
  UnsortedType list1;
  UnsortedType list2;
  UnsortedType listSplitTest;
  UnsortedType listToCount;
  const int pivotNumber = 10;
  int lessThanOrEqual = 0;
  int greaterThan = 0;
  bool found;
  int numCommands;

  // Prompt for file names, read file names, and prepare files
  cout << "Enter name of input command file; press return." << endl;
  cin  >> inFileName;
  inFile.open(inFileName.c_str());

  cout << "Enter name of output file; press return." << endl;
  cin  >> outFileName;
  outFile.open(outFileName.c_str());

  cout << "Enter name of test run; press return." << endl;
  cin  >> outputLabel;
  outFile << outputLabel << endl;
  if (!inFile)
  {
    cout << "file not found" << endl;
	exit(2);
  }
  inFile >> command;

  numCommands = 0;
  while (command != "Quit")
  { 
    if (command == "PutItem")
    {
      inFile >> number; 
      item.Initialize(number);
      list.PutItem(item);
      item.Print(outFile);
      outFile << " is in list" << endl;
    }
    if (command == "Reverse"){
      list.reverseLists();
      outFile << " Reverse ran" << endl;
    }
    else if (command == "DeleteItem")
    {
      inFile >> number;
      item.Initialize(number);
      list.DeleteItem(item);
      item.Print(outFile);
      outFile << " is deleted" << endl;
    }
    else if (command == "GetItem")
    {
      inFile >> number;
      item.Initialize(number);
      item = list.GetItem(item, found);
      item.Print(outFile);
      if (found)
        outFile << " found in list." << endl;
      else outFile <<  " not in list."  << endl;  
    } 
    else if (command == "GetLength")  
      outFile << "Length is " << list.GetLength() << endl;
    else if (command == "IsFull")
      if (list.IsFull())
        outFile << "List is full." << endl;
      else outFile << "List is not full."  << endl;  
    else if (command == "MakeEmpty")
	  list.MakeEmpty();
	else if (command == "PrintList")
	  PrintList(outFile, list);
	else if (command == "CountList") {
		item.Initialize(2);
		listToCount.PutItem(item);
		item.Initialize(5);
	    listToCount.PutItem(item);
	    item.Initialize(9);
	    listToCount.PutItem(item);
	    item.Initialize(14);
	    listToCount.PutItem(item);
	    item.Initialize(20);
	    listToCount.PutItem(item);
	    item.Initialize(27);
	    listToCount.PutItem(item);
	    pivotItem.Initialize(pivotNumber);

	    string msg = "Testing CountLists\n";
	    PrintString(outFile, msg);
	    PrintList(outFile, listToCount);
	    outFile << "Pivot number " << pivotNumber << endl;

	    listToCount.CountLists(listToCount, pivotItem, lessThanOrEqual, greaterThan );
	    outFile << "number of less or equal elements " << lessThanOrEqual << endl;
	    outFile << "number of greater elements " << greaterThan << endl;

	}

	else if (command == "SplitList"){
	      inFile >> number;
	      itemSplit.Initialize(number); // itemSplit initialized to the value of number
	      itemSplit = list.GetItem(itemSplit, found);


	      	item.Initialize(9);
	      	listSplitTest.PutItem(item);
			item.Initialize(5);
			listSplitTest.PutItem(item);
			item.Initialize(14);
			listSplitTest.PutItem(item);
			item.Initialize(2);
			listSplitTest.PutItem(item);
			item.Initialize(27);
			listSplitTest.PutItem(item);
      item.Initialize(20);
      listSplitTest.PutItem(item);
      item.Initialize(3);
      listSplitTest.PutItem(item);
      item.Initialize(11);
      listSplitTest.PutItem(item);
      item.Initialize(25);
      listSplitTest.PutItem(item);
      item.Initialize(1);
      listSplitTest.PutItem(item);
      item.Initialize(22);
      listSplitTest.PutItem(item);


	      outFile << "Initial List: ";
	      PrintList(outFile, listSplitTest);
	      outFile << endl;
	      outFile << "list split at key: ";
	      itemSplit.Print(outFile);
	      outFile << endl;


	      listSplitTest.splitLists(itemSplit, list1, list2);
	      list1.reverseLists();
        list2.reverseLists();
        outFile << endl;


	      outFile << "List 1:  " << endl;
	      PrintList(outFile, list1);

	      outFile << "List 2:  " << endl;
	      PrintList(outFile, list2);

	    }
	else
	  cout << command << " is not a valid command." << endl;
	numCommands++;
    cout <<  " Command number " << numCommands << " completed." 
         << endl;
    inFile >> command;
  };
 
  cout << "Testing completed."  << endl;
  inFile.close();
  outFile.close();
  exit(0);
}

void PrintString(ofstream& dataFile, string& msg) {
	dataFile << msg << endl;
}


// Need to modify this to separate lists with spaces 

void PrintList(ofstream& dataFile, UnsortedType& list)
// Pre:  list has been initialized.      
//       dataFile is open for writing.   
// Post: Each component in list has been written to dataFile.
//       dataFile is still open.         
{
  int length;
  ItemType item;
  string space = " ";
  list.ResetList(); // Sets current pos to null
  length = list.GetLength(); // Gets length of list and stores in length
  dataFile << "Print Length: ";
  dataFile << length << endl;
  for (int counter = 1; counter <= length; counter++)
  {
    item = list.GetNextItem();
    item.Print(dataFile);
    dataFile << " ";
    //PrintString(dataFile, space);
  }
  dataFile << endl;
}

