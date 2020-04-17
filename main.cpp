#include<iostream>
#include "FamilyTree.hpp"

int main()
{
    family::Tree T ("Yosef"); // Yosef is the "root" of the tree (the youngest person).
	T.addFather("Yosef", "Yaakov")   // Tells the tree that the father of Yosef is Yaakov.
	 .addMother("Yosef", "Rachel")   // Tells the tree that the mother of Yosef is Rachel.
	 .addFather("Yaakov", "Isaac")
	 .addMother("Yaakov", "Rivka")
	 .addFather("Isaac", "Avraham")
	 .addFather("Avraham", "Terah");
     T.display();

    cout << T.relation("Yaakov") << endl;  // prints "father"
    cout << T.relation("Rachel") << endl;  // prints "mother"
    cout << T.relation("Rivka") << endl;   // prints "grandmother"
    cout << T.relation("Avraham") << endl; // prints "great-grandfather"
    cout << T.relation("Terah") << endl;   // prints "great-great-grandfather"
    cout << T.relation("xyz") << endl;     // prints "unrelated"
    cout << T.relation("Yosef") << endl;   // prints "me"


}