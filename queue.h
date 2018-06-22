#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>

using namespace std;

template <class TYPE>
struct Node
{
    TYPE m_data; // data of Queue
    Node<TYPE>* m_next; // pointer pointing to next Node of Queue
    Node<TYPE>* m_previous; // pointer pointing to previous Node of Queue
    Node(TYPE data, Node<TYPE>* next = nullptr, Node<TYPE>* previous = nullptr) : m_data(data), m_next(next), m_previous(previous) // constructor
    {

    }
};

template <class TYPE>
class Queue
{

// the public constructors and operators
public:
    Queue(); // default constructor
    Queue(const Queue& other); // copy constructor
    Queue<TYPE>& operator =(const Queue& other); // assignment operator
    bool operator ==(const Queue& other); // returns true if two queues are equal
    bool operator !=(const Queue& other); // returns true if two queues are different
    bool operator <(const Queue& other); // returns true if first queue is smaller than second queue
    bool operator >(const Queue& other); // returns true if first queue is bigger than second queue
    bool operator <=(const Queue& other); // returns true if first queue is smaller than or equal to second queue
    bool operator >=(const Queue& other); // returns true if first queue is bigger than or equal to second queue
    ~Queue(); // destructor

// the public methods
public:
    void swap(Queue& other); // swaps two queues
    void enqueue(const TYPE& data); // adds element in front of queue
    void dequeue(); // removes element in back of queue

    bool empty() const; // returns true if queue is empty
    TYPE& front() const; // returns front data of queue
    TYPE& back() const; // returns back data of queue
    size_t size() const; // returns size of queue
    void print() const; // prints queue


// the private methods
private:
    void destroy(); // destroys queue
    void copy(const Queue& other); // copies one queue to another

// the private members
private:
    Node<TYPE>* m_head; // pointer for front of queue
    Node<TYPE>* m_tail; // pointer for back of queue
    size_t m_size; // size of queue
};

template <class TYPE>
Queue<TYPE>::Queue() : m_head(nullptr), m_tail(nullptr), m_size(0)
{

}

template <class TYPE>
Queue<TYPE>::Queue(const Queue& other)
{
    if(this != &other)
    {
        copy(other);
    }
}

template <class TYPE>
Queue<TYPE>& Queue<TYPE>::operator =(const Queue& other)
{
    if(this != &other)
    {
        copy(other);
    }
    return* this;
}

template <class  TYPE>
bool Queue<TYPE>::operator ==(const Queue& other)
{
    if(m_size == other.m_size)
    {
        Node<TYPE>* ours = m_head;
        Node<TYPE>* theirs = other.m_head;
        while(ours != nullptr && theirs != nullptr)
        {
            if(ours->m_data == theirs->m_data)
            {
                ours = ours->m_next;
                theirs = theirs->m_next;
            }
            else
            {
                return false;
            }

        }
        return true;
    }
    return false;
}

template <class  TYPE>
bool Queue<TYPE>::operator !=(const Queue& other)
{
    return !(operator ==(other));
}

template <class  TYPE>
bool Queue<TYPE>::operator <(const Queue& other)
{
    if(m_size < other.m_size)
    {
        return true;
    }
    else if(m_size == other.m_size)
    {
        Node<TYPE>* ours = m_head;
        Node<TYPE>* theirs = other.m_head;
        while(ours != nullptr && theirs != nullptr)
        {
            if(ours->m_data < theirs->m_data)
            {
                ours = ours->m_next;
                theirs = theirs->m_next;
            }
            else
            {
                return false;
            }
        }
        return true;
    }
    return false;
}

template <class  TYPE>
bool Queue<TYPE>::operator >(const Queue& other)
{
    if(m_size > other.m_size)
    {
        return true;
    }
    else if(m_size == other.m_size)
    {
        Node<TYPE>* ours = m_head;
        Node<TYPE>* theirs = other.m_head;
        while(ours != nullptr && theirs != nullptr)
        {
            if(ours->m_data > theirs->m_data)
            {
                ours = ours->m_next;
                theirs = theirs->m_next;
            }
            else
            {
                return false;
            }
        }
        return true;
    }
    return false;
}

template <class  TYPE>
bool Queue<TYPE>::operator <=(const Queue& other)
{
    return !(operator >(other));
}

template <class  TYPE>
bool Queue<TYPE>::operator >=(const Queue& other)
{
    return !(operator <(other));
}

template <class TYPE>
Queue<TYPE>::~Queue()
{
    destroy();
}

template <class TYPE>
void Queue<TYPE>::swap(Queue& other)
{
    Node<TYPE>* ours = m_head;
    size_t temp = m_size;
    if(this != &other)
    {
        copy(other);
    }
    other.m_head = ours;
    while(ours->m_next != nullptr)
    {
        ours = ours->m_next;
    }
    other.m_tail = ours;
    other.m_size = temp;
}

template <class TYPE>
void Queue<TYPE>::enqueue(const TYPE& data)
{
    Node<TYPE>* temp = new Node<TYPE>(data);
    if(empty() == true)
    {
        m_head = temp;
        m_tail = temp;
    }
    else
    {
        temp->m_next = m_head;
        m_head->m_previous = temp;
        m_head = temp;
    }
    m_size++;
}

template <class TYPE>
void Queue<TYPE>::dequeue()
{
    if(empty() == false)
    {
        Node<TYPE>* temp = m_tail;
        m_tail = m_tail->m_previous;
        if(m_tail != nullptr)
        {
            m_tail->m_next = nullptr;
        }
        else
        {
            m_head = nullptr;
        }
        delete temp;
        m_size--;
    }
}

template <class TYPE>
bool Queue<TYPE>::empty() const
{
    return m_size == 0;
}

template <class TYPE>
TYPE& Queue<TYPE>::front() const
{
    return m_head->m_data;
}

template <class TYPE>
TYPE& Queue<TYPE>::back() const
{
    return m_tail->m_data;
}

template <class TYPE>
size_t Queue<TYPE>::size() const
{
    return m_size;
}

template <class TYPE>
void Queue<TYPE>::print() const
{
    Node<TYPE>* temp = m_head;
    while(temp != nullptr)
    {
        cout << temp->m_data << " ";
        temp = temp->m_next;
    }
}

template <class TYPE>
void Queue<TYPE>::destroy()
{
    while(empty() == false)
    {
        dequeue();
    }
}

template <class TYPE>
void Queue<TYPE>::copy(const Queue& other)
{
    m_size = other.m_size;
    m_head = new Node<TYPE>(other.m_head->m_data);
    Node<TYPE>* ours,* theirs;
    ours = m_head;
    theirs = other.m_head->m_next;
    while(theirs != nullptr)
    {
        ours->m_next = new Node<TYPE>(theirs->m_data);
        ours->m_next->m_previous = ours;
        m_tail = ours->m_next;
        ours = ours->m_next;
        theirs = theirs->m_next;
    }
}

#endif // QUEUE_H
