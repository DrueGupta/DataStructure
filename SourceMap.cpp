#include <iostream>
#include <string>
#include <unordered_map>
#include "List.h"
#include "OrderedList.h"
#include "Pair.h"
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

	Map<string, double> killers;
	killers.add("The Animatronic", 1);
	killers.add("The Mastermind", 2);
	killers.add("The Onyro", 3);
	killers.add("The Legion", 4);
	killers.add("The Executioner", 5);
	killers.add("The Shape", 6);
	killers.add("The Deathslinger", 7);
	killers.add("The Pig", 8);
	killers.add("The Knight", 9);
	killers.add("The Spirit", 10);
	killers.add("GhostFace", 11);
	killers.display();
	return 0;
}
