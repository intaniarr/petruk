#include <iostream>
#define MAX_STACK_SIZE 10
using namespace std;

struct Element {
    int data, top;
    Element *next;
};

class MyStack {
    private:
    Element stack;
    Element *head = NULL;


    public:
    	void stacktop(){
    	stack.top = -1;
    }
    bool isEmpty(){
    	if(stack.top == -1){
        return 1;
    }else{
    	return 0;
	}
		}
    bool isFull(){
    	if (stack.top == MAX_STACK_SIZE-1){
		return 1;
		}else{
			return 0;
			}
		}
        
    void push(int i){
    	if (!isFull()){
    		
    	Element *item = new Element;
		item->data = i;
		item->next = NULL;
		if (isEmpty()){
			head = item;
			head->next = NULL;
		}	else{
			item->next = head;
			head = item;
			}
			stack.top++;
		}else{
			cout<<" Stack Penuh !"<<endl;
		}
		}
    
    Element pop(){
    	
        if (isEmpty()){
            cout<<" Stack Kosong ";
        } else {
            Element *item = new Element;
            item = head;
            head = head->next;
            delete item;
            stack.top--;
        }
        
    }
    void printStackList(){
        if (!isEmpty()){
        	Element *item = new Element;
        	item = head;
        	cout<<"\nisi stack = ";
        	while(item!=NULL){
        		cout<<item->data<<" ";
        		item = item->next;
			}
            cout<<"\n";
        } else {
            cout<<"Stack Kosong"<<endl;
        }
    }
    int getTop(){
		if(isEmpty()){
			cout<<"stack kosong\n";
		} else{
			cout<<"top = "<<head->data<<endl;
		}	
	}	
};

int main()
{
    MyStack s;
    s.push(8);
    s.push(3);
    s.push(2);
    s.push(2);
    s.push(9);
	  s.pop();
    s.pop();
    s.pop();
    s.pop();
    s.printStackList();
    return 0;
}
