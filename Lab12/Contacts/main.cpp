#include <iostream>
#include "Contact.h"
using namespace std;



int main()
{
    AddressBook book;

    Contact* f1 = new Friend("Alice");
    Contact* f2 = new Friend("Bob");
    Contact* a1 = new Acquaintance("Charlie");
    Contact* c1 = new Colleague("David");

    book.addContact(f1);
    book.addContact(f2);
    book.addContact(a1);
    book.addContact(c1);

    std::cout << "Searching for Bob:\n";
    Contact* found = book.searchByName("Bob");
    if(found)
        std::cout << "Found: " << found->GetName() << std::endl;
    else
        std::cout << "Not found\n";

    std::cout << "\nFriends list:\n";
    Friend** friends = book.getFriends();

    for(int i = 0; i < 2; i++)   // we know we added 2 friends
        std::cout << friends[i]->GetName() << std::endl;

    std::cout << "\nDeleting Charlie...\n";
    book.deleteContact("Charlie");

    Contact* test = book.searchByName("Charlie");
    if(test == nullptr)
        std::cout << "Charlie deleted successfully\n";

    delete f1;
    delete f2;
    delete a1;
    delete c1;

    return 0;
}
