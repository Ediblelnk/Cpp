// File: Node.h
// Singly-linked list node definition/implementation (also good for circular)

#ifndef NODE_H
#define NODE_H

// Need to prototype template classes if they are to be friends
template <typename eltType> class CLinkedList;
template <typename eltType> class CListItr;

template <typename eltType> class Node
{       private:
		Node(eltType info, Node* link = NULL ) :
					       data(info), next(link) 
		{};
		eltType data;
		Node *next;
        friend class CLinkedList<eltType>;
        friend class CListItr<eltType>;
};

#endif
