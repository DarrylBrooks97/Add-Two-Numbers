#include <iostream>
#include <cstdlib>
#include <string>
#include <sstream>
#include <stack>

using namespace std;

class Node{
	public:
		int num;
		Node *next;
		static Node* Ans;
	
		Node(int l){
			num = l;
			next = NULL;
		}
		Node(){
			next = NULL;
		}
		void setNext(Node &x){
			next = &x;
		}
		~Node(){
			next = NULL;
			delete next;
		}
		
};

Node* Node::Ans=NULL;

class Operations{
	public:
		void printList(Node*);
		int addNumberList(Node*,Node*);
	    void reverseNumber(Node*);
		Node* reverseSum(int*);
};

void userNumbers(Node&,Node&,Node&,Node&,Node&,Node&);

int main(){
	Node* num1Ptr = NULL;
	Node* num2Ptr = NULL;
	Node* Ans = NULL;
	Node* ansPtr = new Node;
    Operations opObj;
    int *sum = new int;
    Node third;
    Node second;
    Node first;
    Node end;
    Node midpoint;
    Node begin;
    
    userNumbers(first,second,third,begin,midpoint,end);               //User can input their numbers
    
	num1Ptr = &third;                                                 //Points to first number's digit
	
	third.setNext(second);
	second.setNext(first);
    
	num2Ptr = &end;                                                   //Points to second number's digit
	
	end.setNext(midpoint);
	midpoint.setNext(begin);
	
	opObj.reverseNumber(num1Ptr);                                     //Reverses the first number
	opObj.reverseNumber(num2Ptr);                                     //Reverses the second number

	*sum = opObj.addNumberList(num1Ptr,num2Ptr);                      //Adds the two numbers together
	
	
	Ans = opObj.reverseSum(sum);                                     //Reverses Answer
	cout<<"Answer: ";
	opObj.printList(ansPtr->Ans);
	cout<<"\n";
	
	opObj.reverseNumber(Ans);
	cout<<"Reversed Answer: ";
	opObj.printList(Ans);                                            //Prints reversed Answer
	cout<<"\n";
	 
    delete sum;
	delete ansPtr;
	return 0;
}

void Operations::printList(Node* nodePtr){
	while(nodePtr!=NULL){
		cout<<nodePtr->num;
		nodePtr = nodePtr->next;
	}
}

void Operations::reverseNumber(Node *head){
			stack<int> container;
			Node* curr = head;                 
			while(curr!=NULL){
				container.push(curr->num);                          //Pushes numbers into a stack
				curr = curr->next;
			
			}
			curr = head;                                           //Re-asssigns current node pointer back to head
			while((container.size()>0) && (curr!=NULL)){
				curr->num = container.top();                       //Assigns top number of stack to the node
				container.pop();                                   //Pops off the top most value of the stack
				curr = curr->next;
			}
			
			delete curr;
}

int Operations::addNumberList(Node* num1,Node* num2){
	Node* curr = num1;
	Node* curr2 = num2;
	string number;
	string number2;
    stringstream temp;
	stringstream temp2;
	int *x = new int;
	int *y = new int;
	
	while((curr!=NULL) && (curr2!=NULL)){
		temp << curr->num;                                         //Places each number of linked list into a string stream
		temp2 << curr2->num;                                       //Places each number of linked list into a string stream
		curr = curr->next;
		curr2 = curr2->next;
	}
	
	number = temp.str();                                            //Converts the combination of numbers into a string
	number2 = temp2.str();                                          //Converts the combination of numbers into a string
	
	*x = atoi(number.c_str());                                      //Converts string back into int
	*y = atoi(number2.c_str());                                    //Converts string back into int
	
	return *x + *y;
	
	delete x;
	delete y; 
	delete curr;
	delete curr2;
}

Node* Operations::reverseSum(int *x){
	Node* head = NULL;
	Node* curr = NULL;
	Node* temp = NULL;
	string number = "";
	stringstream numString;
	Node* nodePtr = new Node;
	int k=0;
	
	numString << *x;
	number = numString.str();

	while(k<number.size()){
		if(!head){                                                  //If head is NULL create a node for head
			head = new Node;
			curr = head;
		}
		curr->num = (int)number[k] - 48;                           //Transforms the character into int using ASCII vblue using ASCII arthmetic
		if(k!=number.size()-1){                                    //Makes sure that an additonal node is not being created right before it end
			temp = new Node;
			curr->next = temp;
		    curr = curr->next;
		}else{
			curr->next = NULL;
			curr = curr->next;
		}
        k += 1;
	}
	nodePtr->Ans = head;                                           //Assigns the normal order of answer to static member
	                       
	
	delete curr;
	delete nodePtr;
	return head;
}

void userNumbers(Node& first,Node& second,Node& third,Node& begin,Node& midpoint,Node& end){
    int *intPtr = new int;
    for(int i=0;i<6;++i){
        switch(i){
            case 0:
                cout<<"Enter the first digit of the first number: ";
                cin>>*intPtr;
                while(cin.fail()){
                    cout<<"Enter only integers: ";
                    cin>>*intPtr;
                }
                third.num = *intPtr;
                break;
            case 1:
                cout<<"Enter the second digit of the first number: ";
                cin>>*intPtr;
                while(cin.fail()){
                    cout<<"Enter only integers: ";
                    cin>>*intPtr;
                }
                second.num = *intPtr;
                break;
            case 2:
                cout<<"Enter the third digit of the first number: ";
                cin>>*intPtr;
                while(cin.fail()){
                    cout<<"Enter only integers: ";
                    cin>>*intPtr;
                }
                first.num = *intPtr;
                break;
            case 3:
                cout<<"Enter the first digit of the second number: ";
                cin>>*intPtr;
                while(cin.fail()){
                    cout<<"Enter only integers: ";
                    cin>>*intPtr;
                }
                end.num = *intPtr;
                break;
            case 4:
                cout<<"Enter the second digit of the second number: ";
                cin>>*intPtr;
                while(cin.fail()){
                    cout<<"Enter only integers: ";
                    cin>>*intPtr;
                }
                midpoint.num = *intPtr;
                break;
            default:
                cout<<"Enter the third digit of the second number: ";
                cin>>*intPtr;
                while(cin.fail()){
                    cout<<"Enter only integers: ";
                    cin>>*intPtr;
                }
                begin.num = *intPtr;
                break;
        }
    }
    delete intPtr;
}




