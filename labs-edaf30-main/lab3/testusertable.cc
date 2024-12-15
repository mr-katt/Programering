#include "User.h"
#include "UserTable.h"
#include <iostream>
#include <cassert>
#include <ostream>

void testUserTable() {
    // Test default constructor
    UserTable ut;
    assert(ut.getNbrUsers() == 0);

    // Test adding users
    ut.addUser(User(12345, "Alice"));
    ut.addUser(User(67890, "Bob"));
    assert(ut.getNbrUsers() == 2);

    // Test finding users by card number
    User foundUser = ut.find(12345);
    assert(foundUser.getCardNbr() == 12345);
    assert(foundUser.getName() == "Alice");

    foundUser = ut.find(67890);
    assert(foundUser.getCardNbr() == 67890);
    assert(foundUser.getName() == "Bob");

    // Test finding user by name
    foundUser = ut.find("Alice");
    assert(foundUser.getCardNbr() == 12345);
    assert(foundUser.getName() == "Alice");

    foundUser = ut.find("Bob");
    assert(foundUser.getCardNbr() == 67890);
    assert(foundUser.getName() == "Bob");

    // Test finding non-existent user
    foundUser = ut.find(11111);
    assert(foundUser == UserTable::user_not_found);

    foundUser = ut.find("Charlie");
    assert(foundUser == UserTable::user_not_found);

    // Test printing users
    ut.print(std::cout);

    // Test loading users from file
    UserTable utFromFile("users.txt");
    assert(utFromFile.getNbrUsers() > 0); // Assuming users.txt has users

    // Test printing users in a larger area
    // utFromFile.print(std::cout);
    std::cout << "numbers of users :" <<utFromFile.getNbrUsers() << endl;

    // Test to find user with cardnumber 21330 with name Irene Danielsson
    assert(utFromFile.find(21330).getCardNbr() == 21330);
    assert(utFromFile.find(21330).getName() == "Irene Danielsson");

    // Test to find user with cardnumber 21331 Tony Hansen
    assert(utFromFile.find(21331).getName() == "Tony Hansen");
    assert(utFromFile.find(21331).getCardNbr() == 21331);

    // Test to find user named "Jens Holmgren"
    assert(utFromFile.find("Jens Holmgren").getName() == "Jens Holmgren");

    // Test binary search
    assert(testFindNbr(utFromFile) == 0); // All users should be found

    std::cout << "All UserTable tests passed!" << std::endl;
}

int main() {
    testUserTable();
    return 0;
}