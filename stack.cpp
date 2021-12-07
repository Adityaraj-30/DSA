/*  Stack---->Stores a list of items in which an item can be added to or removed
            from the list only at one end. (LIFO) 
    Operations--->  push(x) //for insertation
                    pop( ) //for remove
                    top( )  //front value
                    empty( )   //       
*/

//Stack using Array Implementation.

#include <iostream>
#define n 20

class stack
{
private:
    int* arr;
    int top;

public:
    stack(){
        arr = new int[n];
        top = -1;

    }

    void push(int x){
        if(top == n-1){
            std::cout<<"Stack overflow"<<"\n";
            return;
        }
        top++;
        arr[top]=x;

    }

    void pop(){
        if(top == -1){
            std::cout<<"No element to pop\n";
            return;
        }
        std::cout<<"The popped element is "<< arr[top] <<"\n";
        top--;
    }

    int Top(){
        if(top == -1){
            std::cout<<"No element in stack\n";
            return -1;
        }
        return arr[top];
    }

    bool empty(){
        if(top == -1){
            return true;
        }
        return false;
    }
    void display() {
        if(top>=0) {
            std::cout<<"Stack elements are:";
            for(int i=top; i>=0; i--)
            std::cout<<arr[i]<<" ";
            std::cout<<"\n";
        }else
            std::cout<<"Stack is empty\n";
    }
    
};


int main()
{
    // stack s;
    // s.push(1);
    // s.push(2);
    // s.push(3);
    // s.push(4);

    // std::cout<<s.Top()<<"\n";
    // s.pop();
    // std::cout<<s.Top()<<"\n";

    // std::cout<<s.empty()<<"\n";

    stack s;
    int ch, x;
    std::cout<<"1) Push in stack \n";
    std::cout<<"2) Pop from stack\n";
    std::cout<<"3) Display stack\n";
    std::cout<<"4) Exit\n";
    do {
        std::cout<<"Enter choice: \n";
        std::cin>>ch;
        switch(ch) {
            case 1: {
            std::cout<<"Enter value to be pushed:\n";
            std::cin>>x;
            s.push(x);
            break;
            }
            case 2: {
            s.pop();
            break;
            }
            case 3: {
            s.display();
            break;
            }
            case 4: {
            std::cout<<"Exit\n";
            break;
            }
            default: {
            std::cout<<"Invalid Choice\n";
            }
        }
   }while(ch!=4);

   return 0;
}
