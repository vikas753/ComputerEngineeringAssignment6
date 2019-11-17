//////////////////////////////////////////////////////
//
//
//  Problem 2 Solution , for implementing dynamic
//  programming solution for rod cutting as well
//  as non dynamic programming and comparing their
//  results
//  Name : VIKAS VEERABATHINI
//  NU ID : 001302155
//
//////////////////////////////////////////////////////

#include<iostream>
#include<vector>
#include<cmath>
#include<ctime>

using namespace std;

// API : Get the price of cut length of rod
float GetPrice(int LengthRod,int CutLength)
{
  if(CutLength == 1)
  {
    return 2;
  }
  else if(CutLength < LengthRod)
  {
    return floor(CutLength*2.5);
  }
  else
  {
    return (CutLength*2.5) -1;
  }
}


vector<float> RodLengthPriceDirectory;
#define INVALID_ROD_LENGTH -1

// Initializes the Rod length directory with invalid lengths . 
void InitRodLength(int Length)
{
  for(int i=0;i<=Length;i++)
  {
    RodLengthPriceDirectory.push_back(INVALID_ROD_LENGTH);
  }
  return;
}

// API : Returns MAX price for a cut of a rod without any dynamic programming
float MEMOIZED_ROD_CUT_MAX_PRICE(int Length)
{
  if(RodLengthPriceDirectory[Length] != INVALID_ROD_LENGTH)
  {
    return RodLengthPriceDirectory[Length];
  }
 
  int max = GetPrice(Length,Length);
  for(int i=1;i < Length;i++)
  {
    int CutLengthVal = (GetPrice(Length,i) + MEMOIZED_ROD_CUT_MAX_PRICE(Length-i));
    if(CutLengthVal > max)
    {
      max = CutLengthVal;
    }
  }
  
  RodLengthPriceDirectory[Length] = max;
  return max; 
}

// Wraparound api with an inbuilt time profiling code
// for dynamic programming solution for rod cutting problem
float MEMOIZED_ROD_CUT_MAX_PRICE_WRAPPER(int Length)
{
  InitRodLength(Length);
  clock_t timeProf = clock();
  float MaxPrice =  MEMOIZED_ROD_CUT_MAX_PRICE(Length);
  timeProf = clock() - timeProf;
  cout << " Time taken by memoized algorithm in clocks is : " << (float)timeProf << endl;
  return MaxPrice;
}

// API : Returns MAX price for a cut of a rod without any dynamic programming
float ROD_CUT_MAX_PRICE(int Length)
{
  int max = GetPrice(Length,Length);
  for(int i=1;i < Length;i++)
  {
    int CutLengthVal = (GetPrice(Length,i) + ROD_CUT_MAX_PRICE(Length-i));
    if(CutLengthVal > max)
    {
      max = CutLengthVal;
    }
  }
  return max; 
}

// Wraparound api with in an inbuilt time profiling code
// using a normal solution for rod cutting problem
float ROD_CUT_MAX_PRICE_WRAPPER(int Length)
{
  clock_t TimeProf = clock();
  float maxPrice = ROD_CUT_MAX_PRICE(Length);
  TimeProf = clock() - TimeProf;
  cout << " Time taken by normal algorithm in clocks is : " << (float)TimeProf << endl; 
  return maxPrice;
}


#define MAX_LENGTH_ITER 30

int main()
{
  for(int i=5;i<=MAX_LENGTH_ITER;i=i+5)
  {
    cout << " Max price of a rod cut :  " << i << " is : " << ROD_CUT_MAX_PRICE_WRAPPER(i) << endl;
  }
  cout << endl;
  for(int i=5;i<=MAX_LENGTH_ITER;i=i+5)
  {
    cout << "Memoized Max price of a rod cut :  " << i << " is : " << MEMOIZED_ROD_CUT_MAX_PRICE_WRAPPER(i) << endl;
  }
  return 0;
}

