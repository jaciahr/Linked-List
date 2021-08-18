//Part 1

//#pragma once
//#include <iostream>
//using namespace std;
//
//template <typename T>
//class LinkedList {
//public:
//    struct Node {
//        T data;
//        Node* next;
//        Node* prev;
//    };
//
//    //Ways to add information to the container
//    void AddHead(const T& data);
//    void AddTail(const T& data);
//    void AddNodesHead(const T* data, unsigned int count);
//    void AddNodesTail(const T* data, unsigned int count);
//
//    //A way to get some information about the container
//    unsigned int NodeCount() const;
//
//    //Ways to see the data in the container
//    void PrintForward() const;
//    void PrintReverse() const;
//
//    //Some essentials for any class
//    LinkedList();
//    ~LinkedList();
//
//private:
//    unsigned int count;
//    Node* head;
//    Node* tail;
//};
//
//
////Create a new Node at the front of the list to store the passed in parameter.
//template <typename T>
//void LinkedList<T>::AddHead(const T& data) {
//    Node* n = new Node;
//    n->data = data;
//    if (head == nullptr) {
//        head = n;
//        tail = n;
//    }
//    else {
//        n->next = head;
//        head->prev = n;
//        head = n;
//    }
//    count++;
//}
//
////Create a new Node at the end of the list to store the passed in parameter.
//template <typename T>
//void LinkedList<T>::AddTail(const T& data) {
//    if (count == 0)
//        AddHead(data);
//    else {
//        Node* n = new Node;
//        n->data = data;
//        tail->next = n;
//        n->prev = tail;
//        tail = n;
//        count++;
//    }
//}
//
////Given an array of values, insert a node for each of those at the beginning of the list, maintaining the original order.
//template <typename T>
//void LinkedList<T>::AddNodesHead(const T* data, unsigned int count) {
//    for (int i = (count - 1); i > -1; i--) {
//        AddHead(data[i]);
//    }
//}
//
////Ditto, except adding to the end of the list.
//template <typename T>
//void LinkedList<T>::AddNodesTail(const T* data, unsigned int count) {
//    for (unsigned int i = 0; i < count; i++) {
//        AddTail(data[i]);
//    }
//}
//
////How many things are stored in this list?
//template <typename T>
//unsigned int LinkedList<T>::NodeCount() const {
//    return count;
//}
//
////Iterate through all of the nodes and print out their values, one a time.
//template <typename T>
//void LinkedList<T>::PrintForward() const {
//    Node* n = head;
//    for (unsigned int i = 0; i < count; i++) {
//        cout << n->data << endl;
//        n = n->next;
//    }
//}
//
////Exactly the same as PrintForward, except completely the opposite.
////^ Lol to whoever wrote that! I knew what you meant but it still made me laugh.
//template <typename T>
//void LinkedList<T>::PrintReverse() const {
//    Node* n = tail;
//    for (unsigned int i = 0; i < count; i++) {
//        cout << n->data << endl;
//        n = n->prev;
//    }
//}
//
////Default constructor. How many nodes in an empty list? What is head pointing to? What is tail pointing to? 
////Initialize your variables!
//template <typename T>
//LinkedList<T>::LinkedList() {
//    count = 0;
//    head = nullptr;
//    tail = nullptr;
//}
//
////The usual. Clean up your mess. (Delete all the nodes created by the list.)
//template <typename T>
//LinkedList<T>::~LinkedList() {
//    Node* n = head;
//    while (n != nullptr) {
//        head = head->next;
//        delete n;
//        n = head;
//    }
//    count = 0;
//    head = nullptr;
//    tail = nullptr;
//}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

//Part 2
/*
#pragma once
#include <iostream>
#include <vector>
using namespace std;

template <typename T>
class LinkedList{
   public:
      struct Node{
         T data;
         Node* next;
         Node* prev;
      };

      //Ways to add information to the container
      void AddHead(const T& data);
      void AddTail(const T& data);
      void AddNodesHead(const T* data, unsigned int count);
      void AddNodesTail(const T* data, unsigned int count);

      //A way to get some information about the container
      unsigned int NodeCount() const;

      //Ways to see the data in the container
      void PrintForward() const;
      void PrintReverse() const;

      //Some essentials for any class
      LinkedList();
      ~LinkedList();

      //Getting the head and tail nodes:
      Node* Head();
      const Node* Head() const;
      Node* Tail();
      const Node* Tail() const;

      //Getting a specific node based on an index--allowing this container to be used as though it were an array
      Node* GetNode(unsigned int index);
      const Node* GetNode(unsigned int index) const;
      T& operator[](unsigned int index);
      const T& operator[](unsigned index) const;

      //Finding the FIRST node based on a value
      Node* Find(const T& data);
      const Node* Find(const T& data) const;

      //Finding ALL nodes based on a value
      void FindAll(vector<Node*>& outData, const T& value) const;

      //The other two members of the Big Three
      LinkedList(const LinkedList<T>& list);
      LinkedList<T>& operator=(const LinkedList<T>& rhs);

   private:
      Node* head;
      Node* tail;
      unsigned int count;
};

//Create a new Node at the front of the list to store the passed in parameter.
template <typename T>
void LinkedList<T>::AddHead(const T& data){
   Node* n = new Node;
   n->data = data;
   if (head == nullptr){
      head = n;
      tail = n;
   }
   else{
      n->next = head;
      head->prev = n;
      head = n;
   }
   count++;
}

//Create a new Node at the end of the list to store the passed in parameter.
template <typename T>
void LinkedList<T>::AddTail(const T& data){
   if (count == 0)
      AddHead(data);
   else{
      Node* n = new Node;
      n->data = data;
      tail->next = n;
      n->prev = tail;
      tail = n;
      count++;
   }
}

//Given an array of values, insert a node for each of those at the beginning of the list, maintaining the original order.
template <typename T>
void LinkedList<T>::AddNodesHead(const T* data, unsigned int count){
   for (int i = (count - 1); i > -1; i--){
      AddHead(data[i]);
   }
}

//Ditto, except adding to the end of the list.
template <typename T>
void LinkedList<T>::AddNodesTail(const T* data, unsigned int count){
   for (unsigned int i = 0; i < count; i++){
      AddTail(data[i]);
   }
}

//How many things are stored in this list?
template <typename T>
unsigned int LinkedList<T>::NodeCount() const{
   return count;
}

//Iterate through all of the nodes and print out their values, one a time.
template <typename T>
void LinkedList<T>::PrintForward() const{
   Node* n = head;
   for (unsigned int i = 0; i < count; i++){
      cout << n->data << endl;
      n = n->next;
   }
}

//Exactly the same as PrintForward, except completely the opposite.
//^ Lol to whoever wrote that! I knew what you meant but it still made me laugh.
template <typename T>
void LinkedList<T>::PrintReverse() const{
   Node* n = tail;
   for (unsigned int i = 0; i < count; i++){
      cout << n->data << endl;
      n = n->prev;
   }
}

//Default constructor. How many nodes in an empty list? What is head pointing to? What is tail pointing to?
//Initialize your variables!
template <typename T>
LinkedList<T>::LinkedList(){
   count = 0;
   head = nullptr;
   tail = nullptr;
}

//The usual. Clean up your mess. (Delete all the nodes created by the list.)
template <typename T>
LinkedList<T>::~LinkedList(){
   Node* n = head;
   while (n != nullptr){
      head = head->next;
      delete n;
      n = head;
   }
   count = 0;
   head = nullptr;
   tail = nullptr;
}

//Returns the head pointer (non-const version).
template <typename T>
typename LinkedList<T>::Node* LinkedList<T>::Head(){
      return head;
}

//Returns the head pointer (const version).
template <typename T>
const typename LinkedList<T>::Node* LinkedList<T>::Head() const{
      return head;
}

//Returns the tail pointer (non-const version).
template <typename T>
typename LinkedList<T>::Node* LinkedList<T>::Tail(){
      return tail;
}

//Returns the tail pointer (const version).
template <typename T>
const typename LinkedList<T>::Node* LinkedList<T>::Tail() const{
      return tail;
}

//Given an index, return a pointer to the node at that index.
//Throws an exception of type out_of_range if the index is out of range (non-const version).
template <typename T>
typename LinkedList<T>::Node* LinkedList<T>::GetNode(unsigned int index){
      if (index >= count){
         throw out_of_range("Error from index.");
      }
      else{
         Node* n = head;
         for (unsigned int i = 0; i <= index; i++){
            n = n->next;
         }
      return n;
      }
}

//Given an index, return a pointer to the node at that index.
//Throws an exception of type out_of_range if the index is out of range (const version).
template <typename T>
const typename LinkedList<T>::Node* LinkedList<T>::GetNode(unsigned int index) const{
      if (index >= count){
         throw out_of_range("Invalid index.");
      }
      else{
         Node* n = head;
         for (unsigned int i = 0; i <= index; i++){
            n = n->next;
         }
      return n;
      }
}

//Overloaded subscript operator. Takes an index, and returns data from the indexth node.
//Throws an out_of_range exception for an invalid index (non-const version).
template <typename T>
T& LinkedList<T>::operator[](unsigned int index){
   Node* n = head;
   if (index < 0){
      throw out_of_range("Invalid index.");
   }
   for (unsigned int i = 0; i < index; i++){
      if (n->next == nullptr){
         throw out_of_range("Invalid index.");
      }
      n = n->next;
   }
   return n->data;
}

//Overloaded subscript operator. Takes an index, and returns data from the indexth node.
//Throws an out_of_range exception for an invalid index (non-const version).
template <typename T>
const T& LinkedList<T>::operator[](unsigned index) const{
   Node* n = GetNode(index);
   return n->data;
}

//Find the first node with a data value matching the passed in parameter, returning a pointer to that node.
//Returns nullptr if no matching node found (non-const version).
template <typename T>
typename LinkedList<T>::Node* LinkedList<T>::Find(const T& data){
   Node* n = head;
   for (int i = 0; i < count; i++){
      if (n->data == data){
         break;
      }
      n = n->next;
   }
   return n;
}

//Find the first node with a data value matching the passed in parameter, returning a pointer to that node.
//Returns nullptr if no matching node found (const version).
template <typename T>
const typename LinkedList<T>::Node* LinkedList<T>::Find(const T& data) const{
   Node* n = head;
   for (unsigned int i = 0; i < count; i++){
      if (n->data == data){
         break;
      }
      n = n->next;
   }
   return n;
}

//Find all nodes which match the passed in parameter value, and store a pointer to that node in the passed in vector.
template <typename T>
void LinkedList<T>::FindAll(vector<Node*>& outData, const T& value) const{
   Node* n = head;
   for (unsigned int i = 0; i < count; i++){
      if (n->data == value){
         outData.push_back(n);
      }
      n = n->next;
   }
}

//Sets "this" to a copy of the passed in LinkedList.
//For example, if the other list has 10 nodes, with values of 1-10? "this" should have a copy of that same data.
template <typename T>
LinkedList<T>::LinkedList(const LinkedList<T>& list){
   count = 0;
   head = nullptr;
   tail = nullptr;
   Node* n = list.head;
   AddHead(n->data);
   n = n->next;
   while (n != nullptr){
      this->AddTail(n->data);
      n = n->next;
   }
}

//Assignment operator. After listA = listB, listA == listB is true.
template <typename T>
LinkedList<T>& LinkedList<T>::operator=(const LinkedList<T>& rhs){
   Node* temp = head;
   while (temp != nullptr){
        head = head->next;
        delete temp;
        temp = head;
    }
   count = 0;
   head = nullptr;
   tail = nullptr;
   Node* n = rhs.head;
   while (n != nullptr){
      AddTail(n->data);
      n = n->next;
   }
   return *this;
}
*/

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//Part 3

/*
#pragma once
#include <iostream>
#include <vector>
using namespace std;

template <typename T>
class LinkedList{
   public:
      struct Node{
         T data;
         Node* next;
         Node* prev;
      };

      //Ways to add information to the container
      void AddHead(const T& data);
      void AddTail(const T& data);
      void AddNodesHead(const T* data, unsigned int count);
      void AddNodesTail(const T* data, unsigned int count);

      //A way to get some information about the container
      unsigned int NodeCount() const;

      //Ways to see the data in the container
      void PrintForward() const;
      void PrintReverse() const;

      //Some essentials for any class
      LinkedList();
      ~LinkedList();

      //Getting the head and tail nodes:
      Node* Head();
      const Node* Head() const;
      Node* Tail();
      const Node* Tail() const;

      //Getting a specific node based on an index--allowing this container to be used as though it were an array
      Node* GetNode(unsigned int index);
      const Node* GetNode(unsigned int index) const;
      T& operator[](unsigned int index);
      const T& operator[](unsigned index) const;

      //Finding the FIRST node based on a value
      Node* Find(const T& data);
      const Node* Find(const T& data) const;

      //Finding ALL nodes based on a value
      void FindAll(vector<Node*>& outData, const T& value) const;

      //The other two members of the Big Three
      LinkedList(const LinkedList<T>& list);
      LinkedList<T>& operator=(const LinkedList<T>& rhs);

      //Insert elements into the linked list
      void InsertBefore(Node* node, const T& data);
      void InsertAfter(Node* node, const T& data);
      void InsertAt(const T& data, unsigned int index);

      //Test if two lists are equal to one another
      bool operator==(const LinkedList <T>& rhs) const;

   private:
      Node* head;
      Node* tail;
      unsigned int count;
};

//Create a new Node at the front of the list to store the passed in parameter.
template <typename T>
void LinkedList<T>::AddHead(const T& data){
   Node* n = new Node;
   n->data = data;
   if (head == nullptr){
      head = n;
      tail = n;
   }
   else{
      n->next = head;
      head->prev = n;
      head = n;
   }
   count++;
}

//Create a new Node at the end of the list to store the passed in parameter.
template <typename T>
void LinkedList<T>::AddTail(const T& data){
   if (count == 0)
      AddHead(data);
   else{
      Node* n = new Node;
      n->data = data;
      tail->next = n;
      n->prev = tail;
      tail = n;
      count++;
   }
}

//Given an array of values, insert a node for each of those at the beginning of the list, maintaining the original order.
template <typename T>
void LinkedList<T>::AddNodesHead(const T* data, unsigned int count){
   for (int i = (count - 1); i > -1; i--){
      AddHead(data[i]);
   }
}

//Ditto, except adding to the end of the list.
template <typename T>
void LinkedList<T>::AddNodesTail(const T* data, unsigned int count){
   for (unsigned int i = 0; i < count; i++){
      AddTail(data[i]);
   }
}

//How many things are stored in this list?
template <typename T>
unsigned int LinkedList<T>::NodeCount() const{
   return count;
}

//Iterate through all of the nodes and print out their values, one a time.
template <typename T>
void LinkedList<T>::PrintForward() const{
   Node* n = head;
   for (unsigned int i = 0; i < count; i++){
      cout << n->data << endl;
      n = n->next;
   }
}

//Exactly the same as PrintForward, except completely the opposite.
//^ Lol to whoever wrote that! I knew what you meant but it still made me laugh.
template <typename T>
void LinkedList<T>::PrintReverse() const{
   Node* n = tail;
   for (unsigned int i = 0; i < count; i++){
      cout << n->data << endl;
      n = n->prev;
   }
}

//Default constructor. How many nodes in an empty list? What is head pointing to? What is tail pointing to?
//Initialize your variables!
template <typename T>
LinkedList<T>::LinkedList(){
   count = 0;
   head = nullptr;
   tail = nullptr;
}

//The usual. Clean up your mess. (Delete all the nodes created by the list.)
template <typename T>
LinkedList<T>::~LinkedList(){
   Node* n = head;
   while (n != nullptr){
      head = head->next;
      delete n;
      n = head;
   }
   count = 0;
   head = nullptr;
   tail = nullptr;
}

//Returns the head pointer (non-const version).
template <typename T>
typename LinkedList<T>::Node* LinkedList<T>::Head(){
      return head;
}

//Returns the head pointer (const version).
template <typename T>
const typename LinkedList<T>::Node* LinkedList<T>::Head() const{
      return head;
}

//Returns the tail pointer (non-const version).
template <typename T>
typename LinkedList<T>::Node* LinkedList<T>::Tail(){
      return tail;
}

//Returns the tail pointer (const version).
template <typename T>
const typename LinkedList<T>::Node* LinkedList<T>::Tail() const{
      return tail;
}

//Given an index, return a pointer to the node at that index.
//Throws an exception of type out_of_range if the index is out of range (non-const version).
template <typename T>
typename LinkedList<T>::Node* LinkedList<T>::GetNode(unsigned int index){
      if (index >= count){
         throw out_of_range("Error from index.");
      }
      else{
         Node* n = head;
         for (unsigned int i = 0; i <= index; i++){
            n = n->next;
         }
      return n;
      }
}

//Given an index, return a pointer to the node at that index.
//Throws an exception of type out_of_range if the index is out of range (const version).
template <typename T>
const typename LinkedList<T>::Node* LinkedList<T>::GetNode(unsigned int index) const{
      if (index >= count){
         throw out_of_range("Invalid index.");
      }
      else{
         Node* n = head;
         for (unsigned int i = 0; i <= index; i++){
            n = n->next;
         }
      return n;
      }
}

//Overloaded subscript operator. Takes an index, and returns data from the indexth node.
//Throws an out_of_range exception for an invalid index (non-const version).
template <typename T>
T& LinkedList<T>::operator[](unsigned int index){
   Node* n = head;
   if (index < 0){
      throw out_of_range("Invalid index.");
   }
   for (unsigned int i = 0; i < index; i++){
      if (n->next == nullptr){
         throw out_of_range("Invalid index.");
      }
      n = n->next;
   }
   return n->data;
}

//Overloaded subscript operator. Takes an index, and returns data from the indexth node.
//Throws an out_of_range exception for an invalid index (non-const version).
template <typename T>
const T& LinkedList<T>::operator[](unsigned index) const{
   Node* n = GetNode(index);
   return n->data;
}

//Find the first node with a data value matching the passed in parameter, returning a pointer to that node.
//Returns nullptr if no matching node found (non-const version).
template <typename T>
typename LinkedList<T>::Node* LinkedList<T>::Find(const T& data){
   Node* n = head;
   for (unsigned int i = 0; i < count; i++){
      if (n->data == data){
         break;
      }
      n = n->next;
   }
   return n;
}

//Find the first node with a data value matching the passed in parameter, returning a pointer to that node.
//Returns nullptr if no matching node found (const version).
template <typename T>
const typename LinkedList<T>::Node* LinkedList<T>::Find(const T& data) const{
   Node* n = head;
   for (unsigned int i = 0; i < count; i++){
      if (n->data == data){
         break;
      }
      n = n->next;
   }
   return n;
}

//Find all nodes which match the passed in parameter value, and store a pointer to that node in the passed in vector.
template <typename T>
void LinkedList<T>::FindAll(vector<Node*>& outData, const T& value) const{
   Node* n = head;
   for (unsigned int i = 0; i < count; i++){
      if (n->data == value){
         outData.push_back(n);
      }
      n = n->next;
   }
}

//Sets "this" to a copy of the passed in LinkedList.
//For example, if the other list has 10 nodes, with values of 1-10? "this" should have a copy of that same data.
template <typename T>
LinkedList<T>::LinkedList(const LinkedList<T>& list){
   count = 0;
   head = nullptr;
   tail = nullptr;
   Node* n = list.head;
   AddHead(n->data);
   n = n->next;
   while (n != nullptr){
      this->AddTail(n->data);
      n = n->next;
   }
}

//Assignment operator. After listA = listB, listA == listB is true.
template <typename T>
LinkedList<T>& LinkedList<T>::operator=(const LinkedList<T>& rhs){
   Node* temp = head;
   while (temp != nullptr){
        head = head->next;
        delete temp;
        temp = head;
    }
   count = 0;
   head = nullptr;
   tail = nullptr;
   Node* n = rhs.head;
   while (n != nullptr){
      AddTail(n->data);
      n = n->next;
   }
   return *this;
}

//Given a pointer to a node, create a new node to store the passed in value, before the indicated node.
template <typename T>
void LinkedList<T>::InsertBefore(Node* node, const T& data){
   if (node->prev == nullptr){
      AddHead(data);
   }
   else{
      Node* n = new Node;
      n->data = data;
      n->prev = node->prev;
      node->prev->next = n;
      n->next = node;
      node->prev = n;
      count++;
   }
}

//Ditto, except insert the new node after the indicated node.
template <typename T>
void LinkedList<T>::InsertAfter(Node* node, const T& data){
   if (node->next == nullptr){
      AddHead(data);
   }
   else{
      Node* n = new Node;
      n->data = data;
      n->next = node->next;
      n->prev = node;
      node->next = n;
      node->next->prev = n;
      count++;
   }
}

//Inserts a new Node to store the first parameter, at the indexth location. So if you specified 3 as the index,
//the new Node should have 3 Nodes before it. Throws an out_of_range exception if given an invalid index.
template <typename T>
void LinkedList<T>::InsertAt(const T& data, unsigned int index){
   Node* n = head;
   if (index > count)
      throw out_of_range("Invalid index.");
   else if (index == count)
      AddTail(data);
   else{
      for (unsigned int i = 0; i < index; i++)
         n = n->next;
      InsertBefore(n, data);
   }
}

//Test if two lists are equal to one another.
template <typename T>
bool LinkedList<T>::operator==(const LinkedList <T>& rhs) const{
   if(count != rhs.count){
        return false;
    }
    Node* n1 = rhs.head;
    Node* n2 = this->head;
    for(unsigned int i = 0; i < count; i++){
        if (n1->data != n2->data){
            return false;
        }
        n1 = n1->next;
        n2 = n2->next;
    }
    return true;
}
*/

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//Part 4

#pragma once
#include <iostream>
#include <vector>
using namespace std;

template <typename T>
class LinkedList {
public:
    struct Node {
        T data;
        Node* next;
        Node* prev;
    };

    //Ways to add information to the container
    void AddHead(const T& data);
    void AddTail(const T& data);
    void AddNodesHead(const T* data, unsigned int count);
    void AddNodesTail(const T* data, unsigned int count);

    //A way to get some information about the container
    unsigned int NodeCount() const;

    //Ways to see the data in the container
    void PrintForward() const;
    void PrintReverse() const;

    //Some essentials for any class
    LinkedList();
    ~LinkedList();

    //Getting the head and tail nodes:
    Node* Head();
    const Node* Head() const;
    Node* Tail();
    const Node* Tail() const;

    //Getting a specific node based on an index--allowing this container to be used as though it were an array
    Node* GetNode(unsigned int index);
    const Node* GetNode(unsigned int index) const;
    T& operator[](unsigned int index);
    const T& operator[](unsigned index) const;

    //Finding the FIRST node based on a value
    Node* Find(const T& data);
    const Node* Find(const T& data) const;

    //Finding ALL nodes based on a value
    void FindAll(vector<Node*>& outData, const T& value) const;

    //The other two members of the Big Three
    LinkedList(const LinkedList<T>& list);
    LinkedList<T>& operator=(const LinkedList<T>& rhs);

    //Insert elements into the linked list
    void InsertBefore(Node* node, const T& data);
    void InsertAfter(Node* node, const T& data);
    void InsertAt(const T& data, unsigned int index);

    //Test if two lists are equal to one another
    bool operator==(const LinkedList <T>& rhs) const;

    //Removal functions
    bool RemoveHead();
    bool RemoveTail();
    bool RemoveAt(unsigned int index);
    unsigned int Remove(const T& data);
    void Clear();

    //Recursive Print Functions
    void PrintForwardRecursive(const Node* node) const;
    void PrintReverseRecursive(const Node* node) const;

private:
    Node* head;
    Node* tail;
    unsigned int count;
};

//Create a new Node at the front of the list to store the passed in parameter.
template <typename T>
void LinkedList<T>::AddHead(const T& data) {
    Node* n = new Node;
    n->data = data;
    if (head == nullptr) {
        head = n;
        tail = n;
    }
    else {
        n->next = head;
        head->prev = n;
        head = n;
    }
    count++;
}

//Create a new Node at the end of the list to store the passed in parameter.
template <typename T>
void LinkedList<T>::AddTail(const T& data) {
    //NOTE: Prior version was incorrect according to this part's unit tests.
    if (count == 0)
        AddHead(data);
    else {
        Node* n = new Node;
        n->data = data;
        tail->next = n;
        n->prev = tail;
        tail = n;
        count++;
    }
}

//Given an array of values, insert a node for each of those at the beginning of the list, maintaining the original order.
template <typename T>
void LinkedList<T>::AddNodesHead(const T* data, unsigned int count) {
    for (int i = (count - 1); i > -1; i--) {
        AddHead(data[i]);
    }
}

//Ditto, except adding to the end of the list.
template <typename T>
void LinkedList<T>::AddNodesTail(const T* data, unsigned int count) {
    for (unsigned int i = 0; i < count; i++) {
        AddTail(data[i]);
    }
}

//How many things are stored in this list?
template <typename T>
unsigned int LinkedList<T>::NodeCount() const {
    return count;
}

//Iterate through all of the nodes and print out their values, one a time.
template <typename T>
void LinkedList<T>::PrintForward() const {
    Node* n = head;
    for (unsigned int i = 0; i < count; i++) {
        cout << n->data << endl;
        n = n->next;
    }
}

//Exactly the same as PrintForward, except completely the opposite.
//^ Lol to whoever wrote that! I knew what you meant but it still made me laugh.
template <typename T>
void LinkedList<T>::PrintReverse() const {
    Node* n = tail;
    for (unsigned int i = 0; i < count; i++) {
        cout << n->data << endl;
        n = n->prev;
    }
}

//Default constructor. How many nodes in an empty list? What is head pointing to? What is tail pointing to? 
//Initialize your variables!
template <typename T>
LinkedList<T>::LinkedList() {
    count = 0;
    head = nullptr;
    tail = nullptr;
}

//The usual. Clean up your mess. (Delete all the nodes created by the list.)
template <typename T>
LinkedList<T>::~LinkedList() {
    Node* n = head;
    while (n != nullptr) {
        head = head->next;
        delete n;
        n = head;
    }
    count = 0;
    head = nullptr;
    tail = nullptr;
}

//Returns the head pointer (non-const version).
template <typename T>
typename LinkedList<T>::Node* LinkedList<T>::Head() {
    return head;
}

//Returns the head pointer (const version).
template <typename T>
const typename LinkedList<T>::Node* LinkedList<T>::Head() const {
    return head;
}

//Returns the tail pointer (non-const version).
template <typename T>
typename LinkedList<T>::Node* LinkedList<T>::Tail() {
    return tail;
}

//Returns the tail pointer (const version).
template <typename T>
const typename LinkedList<T>::Node* LinkedList<T>::Tail() const {
    return tail;
}

//Given an index, return a pointer to the node at that index. 
//Throws an exception of type out_of_range if the index is out of range (non-const version).
template <typename T>
typename LinkedList<T>::Node* LinkedList<T>::GetNode(unsigned int index) {
    if (index >= count) {
        throw out_of_range("Error from index.");
    }
    else {
        Node* n = head;
        for (unsigned int i = 0; i <= index; i++) {
            n = n->next;
        }
        return n;
    }
}

//Given an index, return a pointer to the node at that index. 
//Throws an exception of type out_of_range if the index is out of range (const version).
template <typename T>
const typename LinkedList<T>::Node* LinkedList<T>::GetNode(unsigned int index) const {
    if (index >= count) {
        throw out_of_range("Invalid index.");
    }
    else {
        Node* n = head;
        for (unsigned int i = 0; i <= index; i++) {
            n = n->next;
        }
        return n;
    }
}

//Overloaded subscript operator. Takes an index, and returns data from the indexth node. 
//Throws an out_of_range exception for an invalid index (non-const version).
template <typename T>
T& LinkedList<T>::operator[](unsigned int index) {
    Node* n = head;
    if (index < 0) {
        throw out_of_range("Invalid index.");
    }
    for (unsigned int i = 0; i < index; i++) {
        if (n->next == nullptr) {
            throw out_of_range("Invalid index.");
        }
        n = n->next;
    }
    return n->data;
}

//Overloaded subscript operator. Takes an index, and returns data from the indexth node. 
//Throws an out_of_range exception for an invalid index (non-const version).
template <typename T>
const T& LinkedList<T>::operator[](unsigned index) const {
    Node* n = GetNode(index);
    return n->data;
}

//Find the first node with a data value matching the passed in parameter, returning a pointer to that node. 
//Returns nullptr if no matching node found (non-const version).
template <typename T>
typename LinkedList<T>::Node* LinkedList<T>::Find(const T& data) {
    Node* n = head;
    for (unsigned int i = 0; i < count; i++) {
        if (n->data == data) {
            break;
        }
        n = n->next;
    }
    return n;
}

//Find the first node with a data value matching the passed in parameter, returning a pointer to that node. 
//Returns nullptr if no matching node found (const version).
template <typename T>
const typename LinkedList<T>::Node* LinkedList<T>::Find(const T& data) const {
    Node* n = head;
    for (unsigned int i = 0; i < count; i++) {
        if (n->data == data) {
            break;
        }
        n = n->next;
    }
    return n;
}

//Find all nodes which match the passed in parameter value, and store a pointer to that node in the passed in vector.
template <typename T>
void LinkedList<T>::FindAll(vector<Node*>& outData, const T& value) const {
    Node* n = head;
    for (unsigned int i = 0; i < count; i++) {
        if (n->data == value) {
            outData.push_back(n);
        }
        n = n->next;
    }
}

//Sets "this" to a copy of the passed in LinkedList. 
//For example, if the other list has 10 nodes, with values of 1-10? "this" should have a copy of that same data.
template <typename T>
LinkedList<T>::LinkedList(const LinkedList<T>& list) {
    count = 0;
    head = nullptr;
    tail = nullptr;
    Node* n = list.head;
    AddHead(n->data);
    n = n->next;
    while (n != nullptr) {
        this->AddTail(n->data);
        n = n->next;
    }
}

//Assignment operator. After listA = listB, listA == listB is true. 
template <typename T>
LinkedList<T>& LinkedList<T>::operator=(const LinkedList<T>& rhs) {
    Node* temp = head;
    while (temp != nullptr) {
        head = head->next;
        delete temp;
        temp = head;
    }
    count = 0;
    head = nullptr;
    tail = nullptr;
    Node* n = rhs.head;
    while (n != nullptr) {
        AddTail(n->data);
        n = n->next;
    }
    return *this;
}

//Given a pointer to a node, create a new node to store the passed in value, before the indicated node.
template <typename T>
void LinkedList<T>::InsertBefore(Node* node, const T& data) {
    if (node->prev == nullptr) {
        AddHead(data);
    }
    else {
        Node* n = new Node;
        n->data = data;
        n->prev = node->prev;
        node->prev->next = n;
        n->next = node;
        node->prev = n;
        count++;
    }
}

//Ditto, except insert the new node after the indicated node.
template <typename T>
void LinkedList<T>::InsertAfter(Node* node, const T& data) {
    if (node->next == nullptr) {
        AddHead(data);
    }
    else {
        Node* n = new Node;
        n->data = data;
        n->next = node->next;
        n->prev = node;
        node->next = n;
        node->next->prev = n;
        count++;
    }
}

//Inserts a new Node to store the first parameter, at the indexth location. So if you specified 3 as the index, 
//the new Node should have 3 Nodes before it. Throws an out_of_range exception if given an invalid index.
template <typename T>
void LinkedList<T>::InsertAt(const T& data, unsigned int index) {
    Node* n = head;
    if (index > count)
        throw out_of_range("Invalid index.");
    else if (index == count)
        AddTail(data);
    else {
        for (unsigned int i = 0; i < index; i++)
            n = n->next;
        InsertBefore(n, data);
    }
}

//Test if two lists are equal to one another.
template <typename T>
bool LinkedList<T>::operator==(const LinkedList <T>& rhs) const {
    if (count != rhs.count) {
        return false;
    }
    Node* n1 = rhs.head;
    Node* n2 = this->head;
    for (unsigned int i = 0; i < count; i++) {
        if (n1->data != n2->data) {
            return false;
        }
        n1 = n1->next;
        n2 = n2->next;
    }
    return true;
}

//Deletes the first Node in the list. Returns whether or not the Node was removed.
template <typename T>
bool LinkedList<T>::RemoveHead() {
    if (count == 0)
        return false;
    Node* n = head;
    head = head->next;
    delete n;
    count--;
    if (head != nullptr)
        head->prev = nullptr;
    return true;
}

//Deletes the last Node, returning whether or not the operation was successful.
template <typename T>
bool LinkedList<T>::RemoveTail() {
    if (count == 0)
        return false;
    else if (tail == head)
        RemoveHead();
    else {
        Node* n = tail;
        tail = tail->prev;
        tail->next = nullptr;
        delete n;
        count--;
    }
    return true;
}

//Deletes the indexth Node from the list, returning whether or not the operation was successful.
template <typename T>
bool LinkedList<T>::RemoveAt(unsigned int index) {
    Node* n = head;
    if (index >= count)
        return false;
    for (unsigned int i = 0; i < index; i++) {
        if (n->next == nullptr)
            return false;
        n = n->next;
    }
    n->prev->next = n->next;
    n->next->prev = n->prev;
    delete n;
    count--;
    return true;
}

//Remove ALL Nodes containing values matching that of the passed-in parameter. Returns how many instances were removed.
template <typename T>
unsigned int LinkedList<T>::Remove(const T& data) {
    unsigned int removedVal = 0;
    Node* n = head;
    if (head->data == data) {
        RemoveHead();
        removedVal++;
    }
    else if (tail->data == data) {
        RemoveTail();
        removedVal++;
    }
    while (n != nullptr) {
        if (n->data == data) {
            n->prev->next = n->next;
            n->next->prev = n->prev;
            Node* deleting = n->next;
            delete n;
            n = deleting;
            removedVal++;
            count--;
        }
        n = n->next;
    }
    return removedVal;
}

//Deletes all Nodes. Don't forget the node count—how many nodes do you have after you deleted all of them?
template <typename T>
void LinkedList<T>::Clear() {
    Node* temp = head;
    while (temp != nullptr) {
        head = head->next;
        delete temp;
        temp = head;
    }
    count = 0;
    head = nullptr;
    tail = nullptr;
}

//This function takes in a pointer to a Node—a starting node. 
//From that node, recursively visit each node that follows, in forward order, and print their values.
//This function MUST be implemented using recursion, or tests using it will be worth no points.
template <typename T>
void LinkedList<T>::PrintForwardRecursive(const Node* node) const {
    if (node != nullptr) {
        cout << node->data << endl;
        PrintForwardRecursive(node->next);
    }
}

//Same deal as PrintForwardRecursive, but in reverse.
template <typename T>
void LinkedList<T>::PrintReverseRecursive(const Node* node) const {
    if (node != nullptr) {
        cout << node->data << endl;
        PrintReverseRecursive(node->prev);
    }
}