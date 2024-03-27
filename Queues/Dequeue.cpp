#include<bits/stdc++.h>
using namespace std;
// Input Restricted Queue: Output can be done through both rear and front positions
// Output Restricted Queue: Input can be done through both rear and front positions
// Doubly Ended Queue: Input and Output can be done through ear and front positions
// Maintains cyclic condition

class Deque
{
    int *arr;
    int front, rear, size;
public:
    // Initialize your data structure.
    Deque(int n)
    {
        size = n;
        arr = new int[size];
        front = -1;
        rear = -1;
    }

    // Pushes 'X' in the front of the deque. Returns true if it gets pushed into the deque, and false otherwise.
    bool pushFront(int x)
    {
        if ((front == 0 && rear == size - 1) || (rear == (front - 1 + size) % size)) {
            return false;
        }
        else if (front == -1) {
            front = 0;
            rear = 0;
        }
        else if (front == 0) {
            front = size - 1;
        }
        else {
            front = (front - 1) % size; // Adjusted to handle negative indices correctly
        }
        arr[front] = x;
        return true; // Change return 1; to return true;
    }

    // Pushes 'X' in the back of the deque. Returns true if it gets pushed into the deque, and false otherwise.
    bool pushRear(int x)
    {
        if ((front == 0 && rear == size - 1) || (rear == (front - 1 + size) % size)) {
            return false;
        }
        else if (front == -1) {
            front = 0;
            rear = 0;
        }
        else if (rear == size - 1) {
            rear = 0;
        }
        else {
            rear++;
        }
        arr[rear] = x;
        return true;
    }

    // Pops an element from the front of the deque. Returns -1 if the deque is empty, otherwise returns the popped element.
    int popFront()
    {
        if (front == -1) {
            return -1;
        }
        int ans = arr[front];
        arr[front] = -1;
        if (front == rear) {
            front = -1;
            rear = -1;
        }
        else {
            front = (front + 1) % size; // Adjusted to handle wrap-around correctly
        }
        return ans;
    }

    // Pops an element from the back of the deque. Returns -1 if the deque is empty, otherwise returns the popped element.
    int popRear()
    {
        if (rear == -1) {
            return -1;
        }
        int ans = arr[rear];
        arr[rear] = -1;
        if (front == rear) {
            front = -1;
            rear = -1;
        }
        else if (rear == 0) {
            rear = size - 1;
        }
        else {
            rear--;
        }
        return ans;
    }

    // Returns the first element of the deque. If the deque is empty, it returns -1.
    int getFront()
    {
        if (front == -1) {
            return -1;
        }
        return arr[front];
    }

    // Returns the last element of the deque. If the deque is empty, it returns -1.
    int getRear()
    {
        if (rear == -1) {
            return -1;
        }
        return arr[rear];
    }

    // Returns true if the deque is empty. Otherwise returns false.
    bool isEmpty()
    {
        return front == -1; // Simplified the return statement
    }

    // Returns true if the deque is full. Otherwise returns false.
    bool isFull()
    {
        return (front == 0 && rear == size - 1) || (rear == (front - 1 + size) % size); // Adjusted condition
    }
};

int main(){
    // STL
    // deque<int> d;

    // d.push_back(1);
    // d.push_front(2);
    // d.pop_back();
    // d.pop_front();
    // cout<<d.front()<<d.back()<<endl;
    // cout<<d.empty();
    return 0;
}