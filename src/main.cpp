
#include "./binarytree/binarytree.h"
#include "./database/database.h"
#include "./datastructure/datastructure.h"
#include "./hashtable/hashtable.h"
#include <cstdlib>
#include <iostream>
#include <string>

using namespace BT_std;
using namespace Database_std;
using namespace datastructure_std;
using namespace HashT_std;
using namespace std;

int main(int argc, char** argv)
{



	// DATA TO BE USED IN TESTING
	// int ss[16] = { 100001, 100002, 100003, 100004,
	// 	100005, 100006, 100007 };

	// int temp = 100001;

	int sos = 120000;

	string names[16] = { "Meldin", "Adila", "Seio" , "Dad",
		"Mom", "Brother", "Sister", "Cousin", "Sam", "Mike",
		"Veronica", "Jon", "Jannise", "Liz", "Isabella",
		"Victor" };

	string jobs[16] = { "developer", "Marketing", "IT" , "Retired",
		"Cleaning", "Bank", "Consultant", "Waiter", "LS Sales", "TV Sales",
		"Paper Sales", "Fighter", "Secretary", "Driver", "Racer",
		"Intern" };





	// TESTING NEW DATASTRUCTURE ADDELEMENT
	Datastructure dt;

	// Adding the elements
	for (int i = 0; i < 16; i++)
	{
		cout << i << endl;
		dt.AddElem(sos+i, names[i], jobs[i]);
	}

	// Printing the elements
	dt.PrintDatabaseInOrder();

	dt.AddElem(120000, "Meldinpt2", "Software Engineer (Hopefully)");
	dt.PrintDatabaseInOrder();










	/*BTree objt;
	objt.PrintInOrder();

	for (int i = 0; i < 16; i++)
	{
		objt.AddLeaf(temp, names[i], jobs[i]);
		temp++;
	}

	objt.PrintInOrder();*/

	/*for (int i = 0; i < 16; i++)
	{
		objt.PrintChildren(names[i]);
	}*/
	/*objt.RemoveNode("Meldin");
	objt.PrintInOrder();*/


	//int input = 0;
	//cout << "E: \n";
	//while (input != 1)
	//{
	//	cout << "delete node: ";
	//	cin >> input;
	//	{
	//		if (input != 1)
	//		{
	//			cout << endl;
	//			objt.RemoveNode(input);
	//			objt.PrintInOrder();
	//			cout << endl;
	//		}
	//	}
	//}





	/*HashT obj;
	obj.AddItem(100001, "Meldin", "Sales");
	obj.AddItem(100002, "Paul", "Locha");
	obj.AddItem(100003, "Kim", "Iced Mocha");
	obj.AddItem(100004, "Emma", "Strawberry Smoothie");
	obj.AddItem(100005, "Annie", "Hot Chocolate");
	obj.AddItem(100006, "Sarah", "Passion Tea");
	obj.AddItem(100007, "Pepper", "Caramel Mocha");
	obj.AddItem(100008, "Mike", "Chai Tea");
	obj.AddItem(100009, "Steve", "Apple Cider");
	obj.AddItem(100010, "Bill", "Root Beer");
	obj.AddItem(100011, "Marie", "Skinny Latte");
	obj.AddItem(100012, "Susan", "Water");
	obj.AddItem(100013, "Joe", "Green Tea");
	obj.PrintTable();


	obj.PrintItemsInBucket(3);
	obj.FindOccupation(100002);
	obj.FindOccupation(100100);

	obj.RemoveItem(100001);
	obj.RemoveItem(100003);
	obj.RemoveItem(100005);
	obj.RemoveItem(100007);
	obj.RemoveItem(100009);
	obj.PrintTable();*/


	// Database open;
	// open.WriteData();
	// open.ReadInData();

	return 0;
}