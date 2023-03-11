#ifndef CLINKEDLIST_H
#define CLINKEDLIST_H

#include <iostream>

using namespace std;

template <typename T>
class CLinkedList;
template <typename T>
class CListItr;

/* NODE DECLARATION / DEFINITION */

template <typename T>
class Node
{
private:
  Node(T info, Node *link = NULL) : data(info), next(link){};

  T data;
  Node *next;

  friend class CLinkedList<T>;
  friend class CListItr<T>;
};

/* CLINKEDLIST DECLARATION */

template <typename T>
class CLinkedList
{
public:
  CLinkedList();
  CLinkedList(CLinkedList &);
  ~CLinkedList();

  CLinkedList &operator=(const CLinkedList &);

  void insert(T);
  bool remove(T);

private:
  Node<T> *copy(Node<T> *);
  void destroy(Node<T> *, Node<T> *&);

  Node<T> *last;

  friend class CListItr<T>;
};

template <typename T>
ostream &operator<<(ostream &, const CLinkedList<T> &);

/* CLISTITR DECLARATION */

template <typename T>
class CListItr
{
public:
  CListItr(const CLinkedList<T> &clist);

  void begin();
  bool isEmpty();
  bool isFirstNode();
  bool isLastNode();
  T &operator*();
  const T &operator*() const;
  void operator++();
  void operator++(int);

private:
  const CLinkedList<T> &clist;
  Node<T> *current;
};

/* CLINKEDLIST DEFINITIONS */

/**
 * @brief Construct a new CLinkedList<T>::CLinkedList object
 *
 * @tparam T
 */
template <typename T>
CLinkedList<T>::CLinkedList() : last(NULL) {}

/**
 * @brief Construct a new CLinkedList<T>::CLinkedList object
 *
 * @tparam T
 * @param cl the list copied
 */
template <typename T>
CLinkedList<T>::CLinkedList(CLinkedList<T> &cl)
{
  last = copy(cl.last);
}

/**
 * @brief Destroy the CLinkedList<T>::CLinkedList object
 *
 * @tparam T
 */
template <typename T>
CLinkedList<T>::~CLinkedList()
{
  destroy(last, last);
}

/**
 * @brief Copies and assigns the right CLinkedList to this CLinkedList
 *
 * @tparam T
 * @param right the right-side CLinkedList
 * @return CLinkedList<T>&
 */
template <typename T>
CLinkedList<T> &CLinkedList<T>::operator=(const CLinkedList<T> &right)
{
  // if refers to the same CLinkedList, just return the reference
  if (this == &right)
    return *this;
  // they are different delete the left, and copy right into lest
  destroy(last, last);
  last = copy(right.last);
  return *this;
}

/**
 * @brief Inserts data of type T into the circular linked list, based on its '<' value
 * 
 * @tparam T 
 * @param data 
 */
template <typename T>
void CLinkedList<T>::insert(T data)
{
  if (!last) // first node, insert data and point to itself
  {
    last = new Node<T>(data);
    last->next = last;
  }
  else if (data < last->next->data) // data is a minimum value, insert at head
  {
    last->next = new Node<T>(data, last->next);
  }
  else if (last->data < data) // data is a maximum value, insert at last
  {
    last->next = new Node<T>(data, last->next);
    last = last->next;
  }
  else // data is a middle value
  {
    Node<T> *trailP = last->next;
    Node<T> *p = last->next->next;
    for (; p != last && p->data < data; trailP = p, p = p->next)
      ;
    trailP->next = new Node<T>(data, p);
  }
}

/**
 * @brief Removes an element from the circular linked list
 *
 * @tparam T
 * @param data
 * @return true
 * @return false
 */
template <typename T>
bool CLinkedList<T>::remove(T data)
{
  if (!last) // empty list, return false
    return false;
  if (last->data == data && last == last->next) // removal at last and just 1 element
  {
    delete last;
    last = NULL;
    return true;
  }
  if (last->data == data) // removal at last
  {
    Node<T> *trailLast = last;
    for (; trailLast->next != last; trailLast = trailLast->next)
      ;
    trailLast->next = last->next;
    delete last;
    last = trailLast;
    return true;
  }
  else // removal at anywhere else in the list
  {
    Node<T> *trailP = last;
    Node<T> *p = last->next;
    for (; p != last && p->data != data; trailP = p, p = p->next)
      ;
    if (p == last) // data was not found in the list, return false
      return false;
    // data was found in the list, remove and return true
    trailP->next = p->next;
    delete p;
    return true;
  }
}

/**
 * @brief Inserts the values of the circular linked list into a out stream object, with cascading
 *
 * @tparam T
 * @param out
 * @param right
 * @return ostream&
 */
template <typename T>
ostream &operator<<(ostream &out, const CLinkedList<T> &right)
{
  CListItr<T> iter(right);
  if (!iter.isEmpty())
  {
    for (iter.begin(); !iter.isLastNode(); iter++)
      out << *iter << " ";
    out << *iter;
  }
  return out;
}

/**
 * @brief Copies a circular linked list starting at Node n
 *
 * @tparam T
 * @param n the head node
 * @return Node<T>*
 */
template <typename T>
Node<T> *CLinkedList<T>::copy(Node<T> *n)
{
  // if the node is NULL, just return NULL
  if (!n)
    return NULL;

  // declare pointers to keep track of beginning for both source and destination
  Node<T> *start = n;
  // declare and copy first node
  Node<T> *first = last = new Node<T>(n->data);
  // copy all of the remainder nodes but stop once reach the beginning again
  for (n = n->next; n != start; n = n->next, last = last->next)
    last->next = new Node<T>(n->data);
  // reassign the end of the list to the beginning node
  last->next = first;
  return first;
}

/**
 * @brief Deletes the head node and every node following it
 *
 * @tparam T
 * @param n the head node
 */
template <class T>
void CLinkedList<T>::destroy(Node<T> *n, Node<T> *&start)
{
  if (n)
  {
    // delete the passed node and follow to the next node
    Node<T> *doomed = n;
    n = n->next;
    delete doomed;
    // if not back at the beginning of the list, delete the next node
    if (n != start)
      destroy(n, start);
  }
}

/* CLISTITR DEFINITIONS */

/**
 * @brief Construct a new CListItr<T>::CListItr object
 *
 * @tparam T
 * @param clist
 */
template <typename T>
CListItr<T>::CListItr(const CLinkedList<T> &clist) : clist(clist),
                                                     current(clist.last) {}

/**
 * @brief Sets the iterator to the first node of the linked list, or NULL if the list is empty
 *
 * @tparam T
 */
template <typename T>
void CListItr<T>::begin()
{
  // list has at least one element
  if (clist.last)
    current = clist.last->next;
  // list has NO elements
  else
    current = NULL;
}

/**
 * @brief Returns whether or not the circular linked list is empty
 *
 * @tparam T
 * @return true
 * @return false
 */
template <typename T>
bool CListItr<T>::isEmpty()
{
  return clist.last == NULL;
}

/**
 * @brief Returns whether the present node is the first node of the circular linked list
 *
 * @tparam T
 * @return true
 * @return false
 */
template <typename T>
bool CListItr<T>::isFirstNode()
{
  return current == clist.last->next;
}

/**
 * @brief Returns whether the present node is the last node of the circular liked list
 *
 * @tparam T
 * @return true
 * @return false
 */
template <typename T>
bool CListItr<T>::isLastNode()
{
  return current == clist.last;
}

/**
 * @brief Returns the data of the node currently pointed at
 *
 * @tparam T
 * @return T&
 */
template <typename T>
T &CListItr<T>::operator*()
{
  return current->data;
}

/**
 * @brief Returns the !const! data of the node currently pointed at
 *
 * @tparam T
 * @return const T&
 */
template <typename T>
const T &CListItr<T>::operator*() const
{
  return current->data;
}

/**
 * @brief Pre-increment, advances the pointer to the next node, if there is one
 *
 * @tparam T
 */
template <typename T>
void CListItr<T>::operator++()
{
  if (current)
    current = current->next;
}

/**
 * @brief Post-increment, advances the pointer to the next node, if there is one
 *
 * @tparam T
 */
template <typename T>
void CListItr<T>::operator++(int)
{
  if (current)
    current = current->next;
}

#endif
