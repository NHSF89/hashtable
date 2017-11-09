#include "hash.h"

hash::hash()
{
	for (int i =0; i < table; i++)
	{
		hashTable[i] = new item;
		hashTable[i]->number = -1;
		hashTable[i]->name = "none";
		hashTable[i]->nextItem = NULL;
	}
}

int hash::Hash(string key)
{
	int hash = 0;
	int index;

	for (int i = 0; i < key.length(); i++)
		hash = ((hash + (int)key[i])*3)^2;
	
	index = hash % table;
	
	return index;
}

void hash::AddItem(int number, string name)
{
	int index = Hash(name);
	
	if (hashTable[index]->name == "none")
	{
		hashTable[index]->name = name;
		hashTable[index]->number = number;
	}
	else
	{
		item* Ptr = hashTable[index];
		item* newPtr = new item;
		
		newPtr->name = name;
		newPtr->number = number;
		newPtr->nextItem = NULL;
		
		while(Ptr->nextItem != NULL)
		{
			Ptr = Ptr->nextItem;
		}
		
		Ptr->nextItem = newPtr;
	}
}

int hash::NumItemsInIndex(int index)
{
	int count = 0;
	
	if (hashTable[index]->name == "none")
		return count;
	else
	{
		count++;
		item* Ptr = hashTable[index];
		
		while (Ptr->nextItem != NULL)
		{
			count++;
			Ptr=Ptr->nextItem;
		}
	}
	
	return count;
}

void hash::printTable()
{
	int numElements;
	
	for (int i = 0; i < table; i++)
	{
		numElements = NumItemsInIndex(i);
		cout << "#########################" << endl;
		cout << "_________________________" << endl;
		cout << "Index = " << i << endl;
		cout << "Name: " << hashTable[i]->name << endl;
		cout << "Number Attached: " << hashTable[i]->number << endl;
		cout << "Items In Current Table: " << numElements << endl;
		cout << "_________________________" << endl;
		cout << "#########################" << endl;
	}
}

void hash::printIndex(int index)
{
	item* Ptr = hashTable[index];
	
	if (Ptr->name == "none")
		cout << "Index " << index << " is empty" << endl;
	else
	{	
		cout << "Index " << index << " contains: " << endl;
		
		while (Ptr != NULL)
		{
		cout << "#########################" << endl;
		cout << "_________________________" << endl;
		cout << "Name: " << Ptr->name << endl;
		cout << "Number: " << Ptr->number << endl;
		cout << "_________________________" << endl;
		cout << "#########################" << endl;
		
		Ptr = Ptr->nextItem;

		}
		
	}
}

void hash::findNumber(string name)
{
	int index = Hash(name);
	bool success = false;
	int numReturn;
	item* Ptr = hashTable[index];
	
	while (Ptr!=NULL)
		{
			if(Ptr->name == name)
			{
				success = true;
				numReturn = Ptr->number;
			}
		
		Ptr=Ptr->nextItem;
		}
		
		if (success)
			cout << "Number: " << numReturn << endl;
		else
			cout << "Number not found in table" << endl;
	
	}

void hash::removeItem(string name)
{
	int index = Hash(name);
	item* dPtr;
	item* Ptr1;
	item* Ptr2;
	
	if (hashTable[index]->name == "none" && hashTable[index]->number == -1)
	{
		cout << name << " was not located in the table." << endl;
	}
	else if (hashTable[index]->name == name && hashTable[index]->nextItem == NULL)
	{
		hashTable[index]->name = "none";
		hashTable[index]->number = -1;
		cout << name << " was successfully removed from the table." << endl; 
	}
	else if( hashTable[index]->name == name)
	{
		dPtr = hashTable[index];
		hashTable[index]=hashTable[index]->nextItem;
		delete dPtr;
		
		cout << name << " was successfully removed from the table." << endl;
	}	
	else
	{
		Ptr1 = hashTable[index]->nextItem;
		Ptr2 = hashTable[index];
		
		while (Ptr1 != NULL && Ptr1->name !=name)
		{
			Ptr2 = Ptr1;
			Ptr1 = Ptr1->nextItem;
		}
		
		if (Ptr1 == NULL)
		{
			cout << name << " was not located in the table." << endl;
		}
		else
		{
			dPtr = Ptr1;
			Ptr1 = Ptr1->nextItem;
			Ptr2->nextItem = Ptr1;
			
			delete dPtr;
			
			cout << name << " was successfully removed from the table." << endl; 
		}
	}
}
