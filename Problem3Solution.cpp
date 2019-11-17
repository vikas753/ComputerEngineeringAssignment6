//////////////////////////////////////////////////////////////
//
//  Problem 3 Solution : 
//  Devise a HUFFMAN encoded tree with a charachter and it's
//  frequency provided
//
//  Name  : VIKAS VEERABATHINI
//  NU ID : 001302155
//
/////////////////////////////////////////////////////////////

#include<iostream>
#include<queue>
#include<string>
using namespace std;


// Typedef for encoding a charachter and frequency in a node
class huffmanEncDataStruct
{ 
public:
  char letter;
  int  frequency;
  int  lhchildidx;
  int  rhchildidx;

  huffmanEncDataStruct(char letter,int frequency,int lhchild,int rhchild):letter(letter),frequency(frequency),lhchildidx(lhchild),rhchildidx(rhchild)
  {
  } 
};


bool operator<(const huffmanEncDataStruct& Node1,const huffmanEncDataStruct& Node2)
{
  return (Node1.frequency > Node2.frequency);
}


// Priority Queue type , with an overload operator
priority_queue<huffmanEncDataStruct> HuffmanPQueueData;

#define INVALID_CHILD_IDX 0xffffffff

// Initialize Priority Queue Data Structure
void initPriorityQueue()
{
  HuffmanPQueueData.push(huffmanEncDataStruct('Z',2,INVALID_CHILD_IDX,INVALID_CHILD_IDX));
  HuffmanPQueueData.push(huffmanEncDataStruct('K',7,INVALID_CHILD_IDX,INVALID_CHILD_IDX));
  HuffmanPQueueData.push(huffmanEncDataStruct('M',24,INVALID_CHILD_IDX,INVALID_CHILD_IDX));
  HuffmanPQueueData.push(huffmanEncDataStruct('C',32,INVALID_CHILD_IDX,INVALID_CHILD_IDX));
  HuffmanPQueueData.push(huffmanEncDataStruct('U',37,INVALID_CHILD_IDX,INVALID_CHILD_IDX));
  HuffmanPQueueData.push(huffmanEncDataStruct('D',42,INVALID_CHILD_IDX,INVALID_CHILD_IDX));
  HuffmanPQueueData.push(huffmanEncDataStruct('L',42,INVALID_CHILD_IDX,INVALID_CHILD_IDX));
  HuffmanPQueueData.push(huffmanEncDataStruct('E',120,INVALID_CHILD_IDX,INVALID_CHILD_IDX));
}

// Below would indicate it is just a parent charachter with frequency = lchild+rchild
#define PARENT_CHAR 0xf

vector<huffmanEncDataStruct> NodeObjs;

// Build Min Heap of Priority Queue below for huffman encoding purpose
huffmanEncDataStruct BuildMinHeap()
{
  while(HuffmanPQueueData.size()>=2)
  {
    huffmanEncDataStruct TopObj = HuffmanPQueueData.top();
    NodeObjs.push_back(TopObj);
    int lchild_idx = NodeObjs.size()-1;
    int lchildFrequency = TopObj.frequency;

    HuffmanPQueueData.pop();

    TopObj = HuffmanPQueueData.top();
    NodeObjs.push_back(TopObj);
    int rchild_idx = NodeObjs.size()-1;
    int rchildFrequency = TopObj.frequency;

    HuffmanPQueueData.pop();

    huffmanEncDataStruct ParentNode(PARENT_CHAR,(lchildFrequency+rchildFrequency),lchild_idx,rchild_idx);
 
    HuffmanPQueueData.push(ParentNode);
    
  }
   
  return HuffmanPQueueData.top();
}

void DisplayHuffmanCode(huffmanEncDataStruct root,string PreviousPath);

// Wrapper api to display huffman code for all nodes
void DisplayHuffmanCodeWrapper(huffmanEncDataStruct root)
{
  DisplayHuffmanCode(root,"");
}

// Display Huffman Codes for all Nodes
void DisplayHuffmanCode(huffmanEncDataStruct root,string PreviousPath)
{

  if(root.letter!= PARENT_CHAR)
  {
    cout << " Huffman code for charachter : " << root.letter << " is : " << PreviousPath << endl;
  }
  
  if(root.lhchildidx != INVALID_CHILD_IDX )
  {
    PreviousPath = PreviousPath + "0";
    DisplayHuffmanCode(NodeObjs[root.lhchildidx],PreviousPath);
  }

  if(root.rhchildidx != INVALID_CHILD_IDX)
  {
    PreviousPath = PreviousPath + "1";
    DisplayHuffmanCode(NodeObjs[root.rhchildidx],PreviousPath);
  }

  return;
  
}

int main()
{
  // Initialize the priority queue with required entries
  initPriorityQueue();
  
  // Display huffman code for all nodes in the heap tree . 
  DisplayHuffmanCodeWrapper(BuildMinHeap());
}
