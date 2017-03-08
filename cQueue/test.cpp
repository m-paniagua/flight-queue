#include <iostream>
#include <string>
#include "cqueue.h"
using namespace std;

enum choice { BOOKED, WAITING };
const int LINES = 2;
int showMenu(void);
void addPassenger(CQueue*);
void deletePassenger(CQueue*);
void showPassengers(CQueue*);

int main(void)
{
	CQueue qPassengers[LINES];
	int x;
	do {
		x = showMenu();
		switch (x)
		{
		case 1: addPassenger(qPassengers);
			break;
		case 2: deletePassenger(qPassengers);
			break;
		case 3: showPassengers(qPassengers);
			break;
		}
	} while (x != 4);
	return 0;
}

int showMenu(void)
{
	int select;

	cout << "Menu\n";
	cout << "========\n";
	cout << "1. Add Passenger\n";
	cout << "2. Delete Passenger\n";
	cout << "3. Show Passengers\n";
	cout << "4. Exit\n";
	cout << "Enter choice: ";
	cin >> select;
	return select;
}

// To do: implement addPassenger, deletePassenger and showPassengers

void addPassenger(CQueue* qP)
{
	Passenger pas;

	if (!qP[BOOKED].IsFull())
	{
		cout << "Enter name: ";
		cin >> pas.name;
		cout << "Booking " << pas.name << " on flight." << endl;
		qP[BOOKED].Enqueue(pas);
	}
	else 
	{
		if (!qP[WAITING].IsFull())
		{
			cout << "Enter name: ";
			cin >> pas.name;
			cout << "Sorry. Plane fully booked. Adding " << pas.name << " to waiting list" << endl;
			qP[WAITING].Enqueue(pas);
		}
		else
		{
			cout << "Sorry. Plane and waiting list fully booked. Try later" << endl;
		}
	}
	
}

void deletePassenger(CQueue* qP)
{
	Passenger pas;
	if (qP[BOOKED].IsEmpty())
	{
		cout << "No passengers to delete\n";
	}
		
	else

	{

		if (!qP[BOOKED].IsEmpty())

		{	

			// removing first person from booked list
			pas = qP[BOOKED].Front();
			cout << "Removing " << pas.name << " from booked passengers." << endl;
			qP[BOOKED].Dequeue();
			
			if (!qP[WAITING].IsEmpty())
			{

				//Adding first passenger from waiting list to booked list
				pas = qP[WAITING].Front();
				cout << "Adding " << pas.name << " from waiting list." << endl;
				qP[BOOKED].Enqueue(pas);

				//delete passenger from front of waiting list
				qP[WAITING].Dequeue();
			}
		}

	}
}

void showPassengers(CQueue* qP)
{
	CQueue tempB = qP[BOOKED];
	CQueue tempW = qP[WAITING];
	Passenger pas;
	//no passengers to display if booked empty
	if (tempB.IsEmpty())
	{
		cout << "No passengers to display" << endl;
		return;
	}

	//show passengers on BOOKED
	//display, dequeue until empty
	if (!tempB.IsEmpty())
	{
		cout << "Booked Passengers" << endl;
		cout << "========\n";
		while (!tempB.IsEmpty())
		{

			pas = tempB.Front();
			cout << pas.name << endl;
			tempB.Dequeue();
		}
	}
	

	//show passengers on WAITING
	//get front, display until empty
	
	if (!tempW.IsEmpty())
	{
		cout << "Waiting List" << endl;
		cout << "========\n";
		while (!tempW.IsEmpty())
		{

			pas = tempW.Front();
			cout << pas.name << endl;
			tempW.Dequeue();
		}
	}
	else
	{
		cout << "No passengers on waiting list" << endl;
	}
}