////////////////////////////////////////////////////
//
//  Name  : VIKAS VEERABATHINI
//  NU ID : 001302155
//  SOlution to Problem 1
//
////////////////////////////////////////////////////


#include<iostream>
#include<vector>
#include<list>
#include<iterator>
#include<stack>
#include<queue>

using namespace std;

// Hardcoded TRUE and FALSE enums
#define TRUE  1
#define FALSE 0

// Global Data structures to be used for the program and problem solution
vector<int>          DataStructureVector;
list<int>            DataStructureList;
stack<int>           DataStructureStack;
priority_queue<int>  DataStructurePQueue;

// API : Initialize the vector with values as mentioned in th problem
void DataStructuresInit()
{
  DataStructureVector.push_back(14);
  DataStructureVector.push_back(18);
  DataStructureVector.push_back(6);
  DataStructureVector.push_back(16);
  DataStructureVector.push_back(8);
  DataStructureVector.push_back(20);
  DataStructureVector.push_back(4);
  DataStructureVector.push_back(10);
  DataStructureVector.push_back(12);
  DataStructureVector.push_back(2);

  for(vector<int>::iterator i = DataStructureVector.begin(); i != DataStructureVector.end(); i++)
  {
    DataStructureList.push_back(*i);
    DataStructureStack.push(*i);
    DataStructurePQueue.push(*i);
  }
  
}

// API : Increase the value of each vector element by 40
void IncreaseValueVectorElem40()
{
  cout << " Increase value of all elements of vector by 40 " << endl;
  for(vector<int>::iterator i = DataStructureVector.begin(); i != DataStructureVector.end(); i++)
  {
    *i = *i + 40; 
  }
}

// API : Increase the value of each list element by 30
void IncreaseValueListElem30()
{
  cout << " Increase value of all elements of list by 30 " << endl;
  for(list<int>::iterator i = DataStructureList.begin(); i != DataStructureList.end(); i++)
  {
    *i = *i + 30; 
  } 
}

// API : Increase the value of each stack element by 20
void IncreaseValueStackElem20()
{
  cout << " Increase value of all elements of Stack by 20 " << endl;
  vector<int> TempPlaceHoldingVector;
  while(!DataStructureStack.empty())
  {
    int TopVal = DataStructureStack.top();
    TempPlaceHoldingVector.push_back(TopVal+20);
    DataStructureStack.pop();
  }
  
  for(vector<int>::iterator i=TempPlaceHoldingVector.begin();i!=TempPlaceHoldingVector.end();i++)
  {
    DataStructureStack.push(*i);
  }    
}

// API : Increase the value of each PQueue element by 10
void IncreaseValuePQueueElem10()
{
  cout << " Increasing all elements of PQueue by 10 " << endl;
  vector<int> TempPlaceHoldingVector;
  while(!DataStructurePQueue.empty())
  {
    int TopVal = DataStructurePQueue.top();
    TempPlaceHoldingVector.push_back(TopVal+10);
    DataStructurePQueue.pop();
  }
  
  for(vector<int>::iterator i=TempPlaceHoldingVector.begin();i!=TempPlaceHoldingVector.end();i++)
  {
    DataStructurePQueue.push(*i);
  } 
   
}

// API : Check if the vector contains value 44 or not
// return TRUE or FALSE

#define INVALID_DISTANCE -1

int CheckVector44()
{
  for(vector<int>::iterator i = DataStructureVector.begin(); i != DataStructureVector.end(); i++)
  {
    if(*i == 44)
    {
      return distance(DataStructureVector.begin(),i);
    } 
  }
  return INVALID_DISTANCE;  
}
 
// API : return location of first element greater than 50 for
// a vector
// returns -1 or invalid distance if not found
int CheckVectorFirstElemMoreThan50()
{
  for(vector<int>::iterator i = DataStructureVector.begin(); i != DataStructureVector.end(); i++)
  {
    if(*i > 44)
    {
      return distance(DataStructureVector.begin(),i);
    } 
  }
  return INVALID_DISTANCE;  
}
 
// API : Check whether all elements of a vector are
// greater than 45 or not
bool CheckWhetherAllElemsGreaterThan45()
{
  for(vector<int>::iterator i = DataStructureVector.begin(); i != DataStructureVector.end(); i++)
  {
    if(*i < 45)
    {
      return FALSE;
    } 
  }
  return TRUE;  
}


// API : Display Vector in a user friendly manner
void DisplayVector()
{
  cout << " DataStructureVector is : [ " ;
  for(vector<int>::iterator i = DataStructureVector.begin(); i != DataStructureVector.end(); i++)
  {
    cout << *i << ","; 
  } 
  cout << "]" << endl;
}

// API : Display List in a user friendly manner
void DisplayList()
{
  cout << " DataStructureList is : [ " ;
  for(list<int>::iterator i = DataStructureList.begin(); i != DataStructureList.end(); i++)
  {
    cout << *i << ","; 
  } 
  cout << "]" << endl;
} 

// API : Display Stack in a user friendly manner
void DisplayStack()
{
  vector<int> TempPlaceHoldingVector;
  cout << " DataStructureStack is : [ " ;
  while(!DataStructureStack.empty())
  {
    int TopVal = DataStructureStack.top();
    TempPlaceHoldingVector.push_back(TopVal);
    DataStructureStack.pop();
    cout << TopVal << ","; 
  }
  
  for(vector<int>::iterator i=TempPlaceHoldingVector.begin();i!=TempPlaceHoldingVector.end();i++)
  {
    DataStructureStack.push(*i);
  } 
   
  cout << "]" << endl;
} 

// API : Display PQueue in a user friendly manner
void DisplayPqueue()
{
  vector<int> TempPlaceHoldingVector;
  cout << " DataStructurePQueue is : [ " ;
  while(!DataStructurePQueue.empty())
  {
    int TopVal = DataStructurePQueue.top();
    TempPlaceHoldingVector.push_back(TopVal+10);
    DataStructurePQueue.pop();
    cout << TopVal << ","; 
  }
  
  for(vector<int>::iterator i=TempPlaceHoldingVector.begin();i!=TempPlaceHoldingVector.end();i++)
  {
    DataStructurePQueue.push(*i);
  } 
   
  cout << "]" << endl;
} 

int main()
{
  DataStructuresInit();
  DisplayVector();
  DisplayPqueue();
  DisplayList();
  DisplayStack();
  IncreaseValueVectorElem40();
  DisplayVector();
  IncreaseValueListElem30();
  DisplayList();
  IncreaseValueStackElem20();
  DisplayStack();
  IncreaseValuePQueueElem10();
  DisplayPqueue();
  cout << " Location of element 44 in vector is " << CheckVector44() << endl;
  cout << " Location of first element in vector that is more than 50 " << CheckVectorFirstElemMoreThan50() << endl;
  cout << " Status of all elements whether they are greater than 45 or not (1:TRUE , 0:FALSE) " << CheckWhetherAllElemsGreaterThan45() << endl;
  return 0;
} 
