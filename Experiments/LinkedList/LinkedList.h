#ifndef LINKEDLIST
#define LINKEDLIST
#include <iostream>

using namespace std;

// Need to prototype template classes 
// since they are referenced as friends below
template <typename T> class LinkedList;
template <typename T> class LListIter;

/////////////////////////////////////////////////////
// define a class to contain one linked list Node
template <typename T> 
class Node {  
  private:
    Node(T value=T(), Node* ptr=NULL) {
      data= value; next= ptr;
    }

    T getData() { return data; }
    Node *getNext() { return next; }

    T data;
    Node *next;

    // must make LinkedList and LListIter friends to Node
    // otherwise, Node pointers will need to be passed around
    // allowing visiblity into LL elements
    friend class LinkedList<T>;
    friend class LListIter<T>;
};

/////////////////////////////////////////////////////
// the linked list class
template <typename T> 
class LinkedList {
  public:
    // Default constructor
    LinkedList();
    // Copy constructor
    LinkedList(LinkedList&);
    // destructor
    ~LinkedList();

    // Assignment operator
    LinkedList& operator=(const LinkedList&);

    // Ordered insert/remove
    void insert(T); 
    bool remove(T);

    // Is the LinkedList empty?
    bool empty();
    // is a value in the list?
    bool exists(T);
    // count the Nodes in the list
    int countNodes();
    // count nodes (use recursion)
    int countNodesRecursive();

  private:
    // linked list pointer
    Node<T>* first;

    // get the pointer to the first node
    Node<T>* getFirst() { return first; }
    // Do a deep copy 
    Node<T>* copyList(Node<T> *);
    // Free Nodes of a linked list
    void destroy(Node<T> *);

    // Need this to count nodes recursively
    int countNodesRec(Node<T> *);

    // make iterator a friend
    friend class LListIter<T>;
};
 
/////////////////////////////////////////////////////
// Define an iterator object for the LinkedList
template <typename T>
class LListIter {
  public:
    // Construct a List Iterator
    LListIter(const LinkedList<T> &list);

    // Reset current to point at the first node of llist
    void reset();
    // Are we at the end?
    bool end();
    // Go to current->next (true if not NULL)
    bool next();
    // Get the value from the current node
    T getValue();
  private:
    const LinkedList<T> &LL;
    Node<T> *current;
};

// Output a linked list, using a list iterator
template <typename T> 
ostream& operator<<(ostream &os,const LinkedList<T> &llist) {  
  LListIter<T>  iter(llist);
  if(!iter.end()) { 
    do {
      os << iter.getValue() << " ";
    } while(iter.next());
  }
  return os;
}

/////////////////////////////////////////////////////
// Linked List Implementations
/////////////////////////////////////////////////////

// Construct empty LinkedList
template <typename T> 
LinkedList<T>::LinkedList() {
  first= NULL;
}

// Copy constructor
template <typename T> 
LinkedList<T>::LinkedList(LinkedList<T> &list) {
  first = copyList(list.first);
}

// Free all Nodes
template <typename T> 
LinkedList<T>::~LinkedList() {
  destroy(first);
}

// Assignment operator
template <typename T> 
LinkedList<T> &LinkedList<T>::operator=(const LinkedList<T>& list) {  
  if (this != &list) {  
    destroy(first);
    first = copyList(list.first);
  }
  return *this;
}

// Copy the list
template <typename T> 
Node<T>* LinkedList<T>::copyList(Node<T> *list) {  
  Node<T>* nptr = NULL; // ptr to beginning of new (copied) LinkedList
  Node<T>* last = NULL; // ptr to last item inserted in the copy
  Node<T>* iter = list; // ptr to current item in list to be copied
  if (list != NULL) {  
    // add the first Node
    nptr= last= new Node<T>(iter->data,NULL); 
    while(iter->next) {
      iter= iter->next;
      last->next= new Node<T>(iter->data,NULL);
      last=last->next;
    }
  }
  return nptr;
}

// Place val into the list in order (increasing)
template <typename T> 
void LinkedList<T>::insert(T val) {  
  // if list is empty, or val is smaller than the first data value
  if(empty() || val < first->data) {
    first=new Node<T>(val,first);
  } 
  // otherwise, start checking 2nd Node...already checked first Node
  else {
    Node<T>* current= first;
    while(current->next != NULL && val > current->next->data) {
      current= current->next;
    }
    current->next= new Node<T>(val,current->next);
  }
}

// is list empty?
// Note: inline !!!!!!!!!!!!
template <typename T> inline 
bool LinkedList<T>::empty() {
  return (first == NULL);
}

// Is this element in the linked list?
template <typename T> 
bool LinkedList<T>::exists(T val) {  
  Node<T> *ptr = first;
  while(ptr != NULL) {
    if(ptr->data == val) { return true; }
    ptr = ptr->next; 
  }
  return false;
}

// remove an item from the llist 
// return true if successful (false if not found)
template <typename T> 
bool LinkedList<T>::remove(T val) {  
  Node<T> *current= first;
  if(!empty()) {
    // val is first item, remove it
    if(val == current->data) {
      first= current->next; delete current;
      return true;
    }
    // not the first, check the rest
    while(current->next != NULL) {
      if(val == current->next->data) {
        Node<T> *temp= current->next->next;
        delete current->next; current->next= temp;
        return true;
      }
      // not found, go on to the next one
      current= current->next;
    }
  }
  return false;
}

// Remove all Nodes in the linked list, starting at ptr
template <typename T> 
void LinkedList<T>::destroy(Node<T> *ptr) {  
  while (ptr != NULL) {  
    Node<T> *doomed = ptr;
    ptr = ptr->next;
    delete doomed;
  }
}

template <typename T>
int LinkedList<T>::countNodes() { 
  Node<T> *ptr= first;
  int count=0;
  while(ptr != NULL) {
    ptr = ptr->next; count++;
  }
  return count;
}

// helper for recursive count
template <typename T>
int LinkedList<T>::countNodesRec(Node<T> *ptr) { 
  return ((ptr) ? 1+countNodesRec(ptr->next) : 0); 
}

// Return number of nodes in *this' list
template <typename T>
int LinkedList<T>::countNodesRecursive() { 
  return(countNodesRec(first)); 
}

/////////////////////////////////////////////////////
// List Iterator Implementations
/////////////////////////////////////////////////////

// LListIter constructor
template <typename T> 
LListIter<T>::LListIter(const LinkedList<T> &list) : 
  LL(list), current(LL.first) {}

// Set current to point at llist's head
template <typename T> 
void LListIter<T>::reset() {
  current = LL.getFirst();
}

// Is current at the end of the list?
template <typename T> 
bool LListIter<T>::end() {
  return current == NULL;
}

// Move current to next Node
template <typename T> 
bool LListIter<T>::next() {
  current = current->next;
  return (current != NULL);
}

// Return data in current Node
template <typename T> 
T LListIter<T>::getValue() {
  // return default value for T if current is NULL
  if(current == NULL) { return T(); }
  return current->getData();
}

#endif