#include "hash.h"

int main(int argc, char *argv[]) {
	
	hash obj;
	string name = "";
	
	/*
	--Template--
	obj.AddItem( 0, "name");
	*/

	obj.AddItem( 456, "Bill");
	obj.AddItem( 95932, "Tara");
	obj.AddItem( 45687,"Steve");
	obj.AddItem( 98465, "Jim");
	obj.AddItem( 325235, "Jane");
	obj.AddItem( 23, "Laura");
	
	//obj.printTable();
	
	//obj.printIndex(8);
	
	/*test search function*/
	
	
	while (name != "END")
	{
		cout << "What name would you like to search up (\"END\" to exit): ";
		cin >> name;
		
		if (name !="END")
			obj.removeItem(name);
		
	}
	
	
	
	
	
	
	return 0;
}
