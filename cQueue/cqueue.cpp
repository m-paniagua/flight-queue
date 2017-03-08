#include "cqueue.h"
#include <iostream>
using namespace std;

CQueue::CQueue()
{
	front = MAX - 1;
	rear = MAX - 1;
}

bool CQueue::IsEmpty()
{
	return (front == rear);

}

bool CQueue::IsFull()
{
	return ((rear + 1) % MAX == front);

}

void CQueue::Enqueue(Passenger p)
{
	rear = (rear + 1) % MAX;
	strcpy_s(passengers[rear].name, 80, p.name);
}

Passenger CQueue::Front()
{
	return passengers[(front + 1) % MAX];
}

void CQueue::Dequeue()
{
	front = (front + 1) % MAX;
}