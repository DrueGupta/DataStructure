#include <iostream>
#include <string>
#include <unordered_map>
#include "List.h"
#include "OrderedList.h"
#include "Pair.h"
#include "Stack.h"
#include "Linter.h"
#include "Queue.h"
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

	Stack<string> robloxGames;
	robloxGames.push("Nullscape");
	robloxGames.push("Pressure");
	robloxGames.push("Grace(RIP)");
	robloxGames.push("Outcome Memories(RIP)");
	robloxGames.push("Bite By Night");
	robloxGames.push("Violence District");
	robloxGames.push("Starfall");
	robloxGames.pop();
	cout << robloxGames.read() << endl;
	cout << robloxGames << endl;

	Queue<string> MIBOMBOCLAT;
	MIBOMBOCLAT.enqueue("oh my gah bruuuuuuh");
	MIBOMBOCLAT.enqueue("7 * 7 = 47");
	MIBOMBOCLAT.enqueue("my name is carl winston AAAAAAAAAAAAAH");
	MIBOMBOCLAT.enqueue("FRAUD TOMORROW!!!!1!");
	MIBOMBOCLAT.enqueue("Thank you... Chainsaw Man.");
	MIBOMBOCLAT.dequeue();
	cout << MIBOMBOCLAT.read() << endl;
	cout << MIBOMBOCLAT << endl;

	Linter linter;
	cout << linter.lint("(I am a {sigma sigma} boy yea im so [sigma sigma} such an alpha male)") << endl;
}
