#include <iostream>
#include <string>
#include "List.h"
#include "OrderedList.h"
using namespace std;

int main() 
{
    List<string> crew;
    crew.insert("Picard");
    crew.insert("Riker");
    crew.insert("Data", 1);
    crew.insert("Geordi");
    crew.insert("Worf");
    crew.insert("Crusher", 0);
    crew.insert("Thomas");
    crew.insert("Troi", 1);
    crew.insert("W. Crusher");
    crew.insert("O'Brien");
    crew.insert("Bob", 5);
    cout << crew << endl;;

    crew.remove();
    crew.remove();
    crew.remove(3);
    cout << crew << endl;
    cout << crew.read(6) << endl;
}
