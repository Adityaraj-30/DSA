/* Queue--->Store a list of items in which an item can be inserted at one end 
            and remove from the other end only.(FIFO)
    Operations--->  enqueue(x) //for insertation
                    dequeue( ) //for remove
                    peek( )    //front value
                    empty( )   //
*/
//Queue using Array Implementation.

#include <iostream>
#define n 20
class queue
{
private:
    int* arr;
    int front;
    int back;

public:
    queue(){
        arr = new int[n];
        front = -1;
        back = -1;
    }
    
    void push(int x){
        if(back == n-1){
            std::cout<<"Queue overflow\n";
            return;
        }
        back++;
        arr[back] = x;

        if(front == -1){
            front++;
        }
    }

    void pop(){
        if(front ==-1 || front>back){
            std::cout<<"No element in queue\n";
            return;
        }
        front++;
    }

    int peek(){
        if(front ==-1 || front>back){
            std::cout<<"No element in queue\n";
            return -1;
        }
        return arr[front];
    }

    bool empty(){
        if(front ==-1 || front>back){
            return true;
        }
        return false;
    }
};

int main()
{
    /* code */
    queue q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);

    std::cout<<q.peek()<<"\n";
    q.pop();

    std::cout<<q.peek()<<"\n";
    q.pop();

    std::cout<<q.empty()<<"\n";

    return 0;
}

