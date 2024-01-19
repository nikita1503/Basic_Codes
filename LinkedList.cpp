// ****** LINKEDLIST CLASS - unlikely to change ******
template<class E>
class LinkedList{
		public:
			LinkedList(){								//default constructor
				head=NULL;
				tail=NULL;
				elements=0;
			}

			class Node{					//Single unit of LL-Node	//note:change class to template
						Node *prev;
						E element;
						Node* next;
				public:
					Node(Node *prev,E element,Node* next){
						this->prev=prev;
						this->element=element;
						this->next=next;
					}
          Node(E element){
						this->prev=NULL;
						this->element=element;
						this->next=NULL;
					}
          Node () {
            this->prev=NULL;
						this->next=NULL;
          }
					void setElement(E element){
						this->element=element;
					}
					E* getElementPtr(){
						return &element;
					}
					Node* getNextNode(){
						return next;
					}
					void setNextNode(Node * next){
						this->next=next;
					}
					Node* getPrevNode(){
						return prev;
					}
					void setPrevNode(Node * prev){
						this->prev=prev;
					}

          void print() {
            this->element.print();
          }
			};
			Node* head;					//pointer to head of LinkedList
			Node* tail;					//pointer to tail of LinkedList
	    int elements;

      Node* addFirst(E n){				//function to insert data at 1st location
      	Node *newNode=new Node(NULL,n,head);
      	if(head==NULL)
      		tail=newNode;
      	else
      		head->setPrevNode(newNode);
      	head=newNode;
      	elements++;
        return newNode;
      }

      E* removeFirst(){					//function to remove data at 1st location
      	if(head!=NULL){
      		Node * deletedNode=head;
      		head=head->getNextNode();
      		deletedNode->setNextNode(NULL);
      		E* removedNode=deletedNode->getElementPtr();
      		delete deletedNode;
      		elements--;
      		if(head==NULL)
      			tail=NULL;
      		else
      			head->setPrevNode(NULL);
      		return removedNode;
      	}
      }

      Node* addLast(E element){   //function to add element at last location
      	Node *newNode=new Node(tail,element,NULL);
      	if(tail==NULL)
      		head=newNode;
      	else
      		tail->setNextNode(newNode);
      	tail=newNode;
      	elements++;
        return newNode;
      }

      E* removeLast(){  //function to remove element at last location
      	if(tail!=NULL){
      		Node * deletedNode=tail;
      		tail=tail->getPrevNode();
      		deletedNode->setPrevNode(NULL);
      		E* removedNode=deletedNode->getElementPtr();
      		delete deletedNode;
      		elements--;
      		if(tail==NULL)
      			head=NULL;
      		else
      			tail->setNextNode(NULL);
      		return removedNode;
      	}
      }

      int size(){						//returns size of linkedList
      	return elements;
      }

      E* remove(Node* removedNode){ //function to delete node
      	E* returnedElement=removedNode->getElementPtr();
      	Node *next=removedNode->getNextNode();
      	Node *prev=removedNode->getPrevNode();

      	if(prev==NULL){
      		head=next;
      	}else{
      		prev->setNextNode(next);
      		removedNode->setPrevNode(NULL);
      	}
      	if(next==NULL){
      		tail=prev;
      	}else{
      		next->setPrevNode(prev);
      		removedNode->setNextNode(NULL);
      	}
      	delete removedNode;
      	elements--;
      	return returnedElement;
      }

      void print() {
        Node * curr = head;
        cout<<"Size: "<<elements<<'\n';
        while(curr!=NULL){
          curr->print();
          curr=curr->getNextNode();
          if(curr!=NULL) cout<<" ---> ";
        }
        cout<<'\n';
      }
};

//**** END LINKEDLIST CLASS****

//******USAGE******

//Declate element or value of the node
struct element {
	int attack, defence;
	bool alive=true;

  void print() {
    cout<<attack<<' '<<defence<<' '<<alive;
  }
};


//****LINKED LIST****
//Create linkedlist
LinkedList<element>linkedlist;

//Creat an element/value
element curr; curr.attack=a[i]; curr.defence=d[i];

//Add a node at start of linked list
LinkedList<element>::Node* node = nodes.addFirst(curr);

//Add a node at end of linked list
LinkedList<element>::Node* node = nodes.addLast(curr);


//Remove the node at start of linked list
nodes.removeFirst();

//Remove the node at end of linked list
nodes.removeLast();

//Get size of linked list
int n = nodes.size();

//Remove a node from linkedlist
nodes.remove(&curr);

//Print linkedlist, note - you need to define the print funtion in element class
nodes.print()

//****END LINKED LIST****


  
//****LINKEDLIST NODE****
  
//Datatype of node
LinkedList<element>::Node

//construction
1. LinkedList<element>::Node node (prev_node_pointer, element, next_node_pointer);
2. LinkedList<element>::Node node (element);
3. LinkedList<element>::Node node ();

//set element
node.setElement(element);

//get element
LinkedList<element>::Node* element_pointer = node.getElementPtr();

//get next node
LinkedList<element>::Node* next_node_pointer = node.getNextNode();

//set next node
node.setNextNode(node_pointer);

//get prev node
LinkedList<element>::Node* prev_node_pointer = node.getPrevNode();

//set prev node
node.setPrevNode(node_pointer);

//Print node, note - you need to define the print funtion in element class
node.print()
