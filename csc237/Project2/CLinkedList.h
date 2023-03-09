#ifndef CLINKEDLIST_H
#define CLINKEDLIST_H

#include <iostream>

using namespace std;

template <typename eltType>
class CLinkedList;
template <typename eltType>
class CListItr;

/* NODE DECLARATION / DEFINITION */

template <typename eltType>
class Node
{
private:
  Node(eltType info, Node *link = NULL) : data(info), next(link){};

  eltType data;
  Node *next;

  friend class CLinkedList<eltType>;
  friend class CListItr<eltType>;
};

/* CLINKEDLIST DECLARATION */

template <typename eltType>
class CLinkedList
{
public:
  CLinkedList();
  CLinkedList(CLinkedList &);
  ~CLinkedList();

  CLinkedList &operator=(const CLinkedList &);

  void insert(eltType);
  bool remove(eltType);

private:
  Node<eltType> *copy(Node<eltType> *);
  void destroy(Node<eltType> *, Node<eltType> *&);

  Node<eltType> *last;

  friend class CListItr<eltType>;
};

template <typename eltType>
ostream &operator<<(ostream &, const CLinkedList<eltType> &);

/* CLISTITR DECLARATION */

template <typename eltType>
class CListItr
{
public:
  CListItr(const CLinkedList<eltType> &clist);

  void begin();
  bool isEmpty();
  bool isFirstNode();
  bool isLastNode();
  eltType &operator*();
  const eltType &operator*() const;
  void operator++();
  void operator++(int);

private:
  const CLinkedList<eltType> &clist;
  Node<eltType> *current;
};

/* CLINKEDLIST DEFINITIONS */

/**
 * @brief Construct a new CLinkedList<eltType>::CLinkedList object
 *
 * @tparam eltType
 */
template <typename eltType>
CLinkedList<eltType>::CLinkedList() : last(NULL) {}

/**
 * @brief Construct a new CLinkedList<eltType>::CLinkedList object
 *
 * @tparam eltType
 * @param cl the list copied
 */
template <typename eltType>
CLinkedList<eltType>::CLinkedList(CLinkedList<eltType> &cl)
{
  last = copy(cl.last);
}

/**
 * @brief Destroy the CLinkedList<eltType>::CLinkedList object
 *
 * @tparam eltType
 */
template <typename eltType>
CLinkedList<eltType>::~CLinkedList()
{
  destroy(last, last);
}

/**
 * @brief Copies and assigns the right CLinkedList to this CLinkedList
 *
 * @tparam eltType
 * @param right the right-side CLinkedList
 * @return CLinkedList<eltType>&
 */
template <typename eltType>
CLinkedList<eltType> &CLinkedList<eltType>::operator=(const CLinkedList<eltType> &right)
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
 * @brief Inserts data of type eltType into the circular linked list, based on its '<' value
 * 
 * @tparam eltType 
 * @param data 
 */
template <typename eltType>
void CLinkedList<eltType>::insert(eltType data)
{
  // first node, insert data and point to itself
  if (!last)
    last = new Node<eltType>(data, last); /* TEMPORARY DEFINITION */
}

/**
 * @brief Inserts the values of the circular linked list into a out stream object, with cascading
 * 
 * @tparam eltType 
 * @param out 
 * @param right 
 * @return ostream& 
 */
template <typename eltType>
ostream &operator<<(ostream &out, const CLinkedList<eltType> &right)
{
  CListItr<eltType> iter(right); /* TEMPORARY DEFINITION */
  out << *iter;
  return out;
}

/**
 * @brief Copies a circular linked list starting at Node n
 *
 * @tparam eltType
 * @param n the head node
 * @return Node<eltType>*
 */
template <typename eltType>
Node<eltType> *CLinkedList<eltType>::copy(Node<eltType> *n)
{
  // if the node is NULL, just return NULL
  if (!n)
    return NULL;

  // declare pointers to keep track of beginning for both source and destination
  Node<eltType> *start = n;
  // declare and copy first node
  Node<eltType> *first = last = new Node<eltType>(n->data, NULL);
  // copy all of the remainder nodes but stop once reach the beginning again
  for (n = n->next; n != start; n = n->next, last = last->next)
    last->next = new Node<eltType>(n->data, NULL);
  // reassign the end of the list to the beginning node
  last->next = first;
  return first;
}

/**
 * @brief Deletes the head node and every node following it
 *
 * @tparam eltType
 * @param n the head node
 */
template <class eltType>
void CLinkedList<eltType>::destroy(Node<eltType> *n, Node<eltType> *&start)
{
  if (n)
  {

    // delete the passed node and follow to the next node
    Node<eltType> *doomed = n;
    n = n->next;
    delete doomed;
    // if not back at the beginning of the list, delete the next node
    if (n != start)
      destroy(n, start);
  }
}

/* CLISTITR DEFINITIONS */

/**
 * @brief Construct a new CListItr<eltType>::CListItr object
 *
 * @tparam eltType
 * @param clist
 */
template <typename eltType>
CListItr<eltType>::CListItr(const CLinkedList<eltType> &clist) : clist(clist),
                                                                 current(clist.last) {}

/**
 * @brief Sets the iterator to the first node of the linked list, or NULL if the list is empty
 *
 * @tparam eltType
 */
template <typename eltType>
void CListItr<eltType>::begin()
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
 * @tparam eltType
 * @return true
 * @return false
 */
template <typename eltType>
bool CListItr<eltType>::isEmpty()
{
  return clist.last == NULL;
}

/**
 * @brief Returns whether the present node is the first node of the circular linked list
 *
 * @tparam eltType
 * @return true
 * @return false
 */
template <typename eltType>
bool CListItr<eltType>::isFirstNode()
{
  return current == clist.last->next;
}

/**
 * @brief Returns whether the present node is the last node of the circular liked list
 *
 * @tparam eltType
 * @return true
 * @return false
 */
template <typename eltType>
bool CListItr<eltType>::isLastNode()
{
  return current == clist.last;
}

/**
 * @brief Returns the data of the node currently pointed at
 * 
 * @tparam eltType 
 * @return eltType& 
 */
template <typename eltType>
eltType &CListItr<eltType>::operator*()
{
  return current->data;
}

/**
 * @brief Returns the !const! data of the node currently pointed at
 * 
 * @tparam eltType 
 * @return const eltType& 
 */
template <typename eltType>
const eltType &CListItr<eltType>::operator*() const
{
  return current->data;
}

#endif
