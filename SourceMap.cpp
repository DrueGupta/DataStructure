#include <iostream>
#include <string>
#include <unordered_map>
#include "List.h"
#include "OrderedList.h"
using namespace std;

int main()
{
	unordered_map<string, double> menu;
	menu["Chicken Curry"] = 12.99;
	menu["Fish Curry"] = 10.99;
	menu["Goat Curry"] = 13.99;
	menu["Roti"] = 2.00;
	menu["Garlic Roti"] = 4.99;
	menu["Lassi"] = 4.99;
	menu["Mango Lassi"] = 6.99;
	menu["Faluta"] = 5.00;
	menu["Gulab Jamin"] = 6.99;
	cout << menu["Mango Lassi"] << endl;
	return 0;
}
