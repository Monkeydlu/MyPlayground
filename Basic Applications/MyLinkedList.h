#include <iostream>



template <typename T>
class MyLinkedList
{
	//Since we're using only a very basic struct for the Node,
	//we put it inside the class MyLinkedList. This way, the struct Node inherits the 
	//typename T and can use it freely without worry. 
	struct Node
	{
		T data;
		Node *next;
		Node *prev;

		/*Node Constructor*/
		Node(T dataForNode, Node *tempNext = NULL, Node *tempPrev = NULL)
			:data(dataForNode), next(tempNext), prev(tempPrev){}
	};

public:
	MyLinkedList() :headLinkedListNode(NULL), tailLinkedListNode(NULL), listSize(0){}
	//MyLinkedList(Node * h) :headLinkedListNode(h), tailLinkedListNode(h), listSize(1){}
	~MyLinkedList();
	void insert(Node *location, T data);
	void push_back(T data);
	void push_front(T data);
	T pop_back();
	T pop_front();
	void erase(Node *location);
	void display();
	Node* search(T data);

private:
	Node *headLinkedListNode;
	Node *tailLinkedListNode;
	unsigned int listSize;
};

//destructor
template<typename T>
MyLinkedList<T>::~MyLinkedList(){
	Node* temp;
	while (headLinkedListNode){			//while there is still a valid pointer in the head pointer, delete it. 
		temp = headLinkedListNode;
		headLinkedListNode = headLinkedListNode->next;
		delete temp;
	}
}

//insert the T data BEFORE the Node location (location must be inside the linked list) 
template<typename T>
void MyLinkedList<T>::insert(Node *location, T data){
	Node * newNode = new Node(data); //create a new node using the data we wish to store. 

	//we need to check to make sure the location is inside the linked list. 

	//first we check if the linked list has any members currently. 
	if (!headLinkedListNode){
		//if the linked list is empty, simple set the new node to be the head node. 
		headLinkedListNode = newNode;
		return;
	}
	if (location == headLinkedListNode){
		//if location is the head, we are trying to insert right in front of head, aka, the front of the linked list. 
		push_front(data);
		return;
	}
	//It is not possible to call an insert to be the END of the list (as we are inserting BEFORE the location given.)
	//With bases cases checked, we move on.
	//we start walking down the linked list to find the node we are inserting in front of. 
	Node *curNode = headLinkedListNode;		//Acts as a tracker as we traverse down the linked list
	while (curNode->next)	//while there is still more nodes in the linked list. 
	{
		if (curNode->next == location){		//if the current node is in front of the location we are searching for
			newNode->next = curNode->next;		//insert the newly created newNode
			newNode->prev = curNode;
			curNode->next->prev = newNode;
			curNode->next = newNode;	//(Node)curNode is current == (Node)location 
			return;
		}
		//if curNode is not in front of location, we move on to the next node and continue. 
		curNode = curNode->next;
	}
	//if curNode has no more nodes following it, there are no more "locations" to consider. The given location was not apart of the linked list. 
	//delete newNode because it will become a memory leak now. 
	delete newNode;
	std::cout << "ERROR: given location for insert(Node* location, T data) was invalid for the target linked list" << std::endl;
	return;
}

template<typename T>
void MyLinkedList<T>::push_back(T data){
	Node * newNode = new Node(data);

	//if the list is empty, then set both head AND tail. 
	if (headLinkedListNode == NULL && tailLinkedListNode == NULL){
		headLinkedListNode = newNode;
		tailLinkedListNode = newNode;
		return;
	}
	//update the new tail node; 
	newNode->prev = tailLinkedListNode;
	tailLinkedListNode->next = newNode;
	tailLinkedListNode = newNode;
	return;
}

template<typename T>
void MyLinkedList<T>::push_front(T data){
	Node * newNode = new Node(data);

	//if the list is empty, then set both head AND tail. 
	if (headLinkedListNode == NULL && tailLinkedListNode == NULL){
		headLinkedListNode = newNode;
		tailLinkedListNode = newNode;
		return;
	}
	//simply update the new head node; 
	headLinkedListNode->prev = newNode;
	newNode->next = headLinkedListNode;
	headLinkedListNode = newNode;
	return;
}

template<typename T>
T MyLinkedList<T>::pop_back(){
	T temp = tailLinkedListNode->data;	//save the data to return
	Node* oldTail = tailLinkedListNode;	//save a reference to the old tail

	tailLinkedListNode = tailLinkedListNode->prev;	//set the new tail to be the current second to last node.
	tailLinkedListNode->next = NULL;	//set the next of tail to null.

	delete oldTail;	//delete the old tail.
	return temp;
}

template<typename T>
T MyLinkedList<T>::pop_front(){
	T temp = headLinkedListNode->data;	//save the data to return
	Node* oldHead = headLinkedListNode;	//save a reference to the old tail

	headLinkedListNode = headLinkedListNode->next;	//set the new head to be the current second from the front node.
	headLinkedListNode->prev = NULL;	//set the prev of the new head to null.

	delete oldHead;	//delete the old head.
	return temp;
}

//erase a given node, only if it exists inside the list, and update the list accordingly. 
template<typename T>
void MyLinkedList<T>::erase(Node *location){
	//check if the node is the head or tail. 
	if (location == headLinkedListNode)
	{
		Node* temp = headLinkedListNode;
		headLinkedListNode = headLinkedListNode->next;
		headLinkedListNode->prev = NULL;
		delete temp;
		return;
	}
	if (location == tailLinkedListNode)
	{
		Node* temp = tailLinkedListNode;
		tailLinkedListNode = tailLinkedListNode->prev;
		tailLinkedListNode->next = NULL;
		delete temp;
		return;
	}
	Node* curNode; //we traverse the linked list to find if the node exists in our list. 
	while (curNode)
	{
		if (curNode->next == location)
		{
			curNode->next = location->next;
			location->next->prev = curNode;
			delete location;
			return;
		}
		curNode = curNode->next;
	}
	//if we make it here, that means the given node was not inside of our list. 
	std::cout << "ERROR: The given node 'location' to erase(Node* location) did not exist inside its linked list." << std::endl;
	return;
}

template<typename T>
void MyLinkedList<T>::display(){
	Node* curNode = headLinkedListNode;	//keep track of our current location as we traverse the node.

	while (curNode){	//while there is still a node
		std::cout << curNode->data << " -> ";
		curNode = curNode->next;
	}
	std::cout << " NULL";
}

template<typename T>
//the reason for the extra typename is because we are turning a Node Struct that exists only within the class myLinkedList
typename MyLinkedList<T>::Node* MyLinkedList<T>::search(T data){
	return NULL;
}

void testLinkedList(){
	MyLinkedList<std::string> testList;

	std::cout << "Please keep entering names to store away in the linked list. Enter <stop> to end." << std::endl;
	std::string nameInput = "";
	std::cin >> nameInput;
	while (nameInput != "stop")
	{
		testList.push_back(nameInput);
		std::cin >> nameInput;
		std::cin.get();
	}

	testList.display();
}