  
#include "doctest.h"
#include "FamilyTree.hpp"
#include <string>
using namespace std;
using namespace family;

TEST_CASE("Test addFather(), relation() and find()") {
    //Case 1:
    //Init:
    Tree y("Yossef");
    y.addFather("Yossef","Moshe");
    y.addFather("Moshe","Avraham");
    y.addFather("Avraham","Yakov");
    y.addFather("Yakov","Menashe");

    //Checks:
    CHECK_THROWS_AS(y.addFather("Yossef","David"),std::exception);
    CHECK_THROWS_AS(y.addFather("Moshe","David"),std::exception);
    CHECK_THROWS_AS(y.addFather("Avraham","David"),std::exception);
    CHECK_THROWS_AS(y.addFather("Yakov","David"),std::exception);

    CHECK(y.relation("Yossef") == string("me"));
    CHECK(y.relation("Moshe") == string("father"));
    CHECK(y.relation("Avraham") == string("grandfather"));
    CHECK(y.relation("Yakov") == string("great-grandfather"));
    CHECK(y.relation("Menashe") == string("great-great-grandfather"));
    CHECK(y.relation("Naftali") == string("unrelated"));

    CHECK(y.find("father") == string("Moshe"));
    CHECK(y.find("grandfather") == string("Avraham"));
    CHECK(y.find("great-grandfather") == string("Yakov"));
    CHECK(y.find("great-great-grandfather") == string("Menashe"));

    CHECK_THROWS_AS(y.find("me"),std::exception);
    CHECK_THROWS_AS(y.find("uncle"),std::exception);
    CHECK_THROWS_AS(y.find("great-great-great-grandfather"),std::exception);

    //Case 2:
    //Init:
    Tree m("Menashe");
    m.addFather("Menashe","Naftali");
    m.addFather("Naftali","Reuven");
    m.addFather("Reuven","Shimon");
    m.addFather("Shimon","Levi");

    //Checks:
    CHECK_THROWS_AS(m.addFather("Menashe","David"),std::exception);
    CHECK_THROWS_AS(m.addFather("Naftali","David"),std::exception);
    CHECK_THROWS_AS(m.addFather("Reuven","David"),std::exception);
    CHECK_THROWS_AS(m.addFather("Shimon","David"),std::exception);

    CHECK(m.relation("Menashe") == string("me"));
    CHECK(m.relation("Naftali") == string("father"));
    CHECK(m.relation("Reuven") == string("grandfather"));
    CHECK(m.relation("Shimon") == string("great-grandfather"));
    CHECK(m.relation("Levi") == string("great-great-grandfather"));
    CHECK(m.relation("Yossef") == string("unrelated"));

    CHECK(m.find("father") == string("Naftali"));
    CHECK(m.find("grandfather") == string("Reuven"));
    CHECK(m.find("great-grandfather") == string("Shimon"));
    CHECK(m.find("great-great-grandfather") == string("Levi"));

    CHECK_THROWS_AS(m.find("me"),std::exception);
    CHECK_THROWS_AS(m.find("uncle"),std::exception);
    CHECK_THROWS_AS(m.find("great-great-great-grandfather"),std::exception);

    //Case 3:
    //Init:
    Tree l("Levi");
    l.addFather("Levi","Yehuda");
    l.addFather("Yehuda","Dan");
    l.addFather("Dan","Gad");
    l.addFather("Gad","Asher");

    //Checks:
    CHECK_THROWS_AS(l.addFather("Levi","David"),std::exception);
    CHECK_THROWS_AS(l.addFather("Yehuda","David"),std::exception);
    CHECK_THROWS_AS(l.addFather("Dan","David"),std::exception);
    CHECK_THROWS_AS(l.addFather("Gad","David"),std::exception);

    CHECK(l.relation("Levi") == string("me"));
    CHECK(l.relation("Yehuda") == string("father"));
    CHECK(l.relation("Dan") == string("grandfather"));
    CHECK(l.relation("Gad") == string("great-grandfather"));
    CHECK(l.relation("Asher") == string("great-great-grandfather"));
    CHECK(l.relation("Yossef") == string("unrelated"));

    CHECK(l.find("father") == string("Yehuda"));
    CHECK(l.find("grandfather") == string("Dan"));
    CHECK(l.find("great-grandfather") == string("Gad"));
    CHECK(l.find("great-great-grandfather") == string("Asher"));

    CHECK_THROWS_AS(l.find("me"),std::exception);
    CHECK_THROWS_AS(l.find("uncle"),std::exception);
    CHECK_THROWS_AS(l.find("great-great-great-grandfather"),std::exception);
}

TEST_CASE("Test addMother(), relation() and find()") {
    //Case 1:
    //Init:
    Tree y("Yossef");
    y.addMother("Yossef","Sara");
    y.addMother("Sara","Rivka");
    y.addMother("Rivka","Rachel");
    y.addMother("Rachel","Leah");

    //Checks:
    CHECK_THROWS_AS(y.addMother("Yossef","Dana"),std::exception);
    CHECK_THROWS_AS(y.addMother("Sara","Dana"),std::exception);
    CHECK_THROWS_AS(y.addMother("Rivka","Dana"),std::exception);
    CHECK_THROWS_AS(y.addMother("Rachel","Dana"),std::exception);

    CHECK(y.relation("Yossef") == string("me"));
    CHECK(y.relation("Sara") == string("mother"));
    CHECK(y.relation("Rivka") == string("grandmother"));
    CHECK(y.relation("Rachel") == string("great-grandmother"));
    CHECK(y.relation("Leah") == string("great-great-grandmother"));
    CHECK(y.relation("Dana") == string("unrelated"));

    CHECK(y.find("mother") == string("Sara"));
    CHECK(y.find("grandmother") == string("Rivka"));
    CHECK(y.find("great-grandmother") == string("Rachel"));
    CHECK(y.find("great-great-grandmother") == string("Leah"));

    CHECK_THROWS_AS(y.find("me"),std::exception);
    CHECK_THROWS_AS(y.find("uncle"),std::exception);
    CHECK_THROWS_AS(y.find("great-great-great-grandmother"),std::exception);

    //Case 2:
    //Init:
    Tree m("Menashe");
    m.addMother("Menashe","Dana");
    m.addMother("Dana","Lee");
    m.addMother("Lee","Noffar");
    m.addMother("Noffar","Yana");

    //Checks:
    CHECK_THROWS_AS(m.addMother("Yossef","Sara"),std::exception);
    CHECK_THROWS_AS(m.addMother("SaLeera","Sara"),std::exception);
    CHECK_THROWS_AS(m.addMother("Noffar","Sara"),std::exception);
    CHECK_THROWS_AS(m.addMother("Yana","Sara"),std::exception);

    CHECK(m.relation("Menashe") == string("me"));
    CHECK(m.relation("Dana") == string("mother"));
    CHECK(m.relation("Lee") == string("grandmother"));
    CHECK(m.relation("Noffar") == string("great-grandmother"));
    CHECK(m.relation("Yana") == string("great-great-grandmother"));
    CHECK(m.relation("Sara") == string("unrelated"));

    CHECK(m.find("mother") == string("Dana"));
    CHECK(m.find("grandmother") == string("Lee"));
    CHECK(m.find("great-grandmother") == string("Noffar"));
    CHECK(m.find("great-great-grandmother") == string("Yana"));

    CHECK_THROWS_AS(m.find("me"),std::exception);
    CHECK_THROWS_AS(m.find("uncle"),std::exception);
    CHECK_THROWS_AS(m.find("great-great-great-grandmother"),std::exception);

    //Case 3:
    //Init:
    Tree l("Levi");
    l.addMother("Levi","Hadar");
    l.addMother("Hadar","Michal");
    l.addMother("Michal","Bruria");
    l.addMother("Bruria","Hagar");

    //Checks:
    CHECK_THROWS_AS(l.addMother("Levi","Meytal"),std::exception);
    CHECK_THROWS_AS(l.addMother("Hadar","Meytal"),std::exception);
    CHECK_THROWS_AS(l.addMother("Michal","Meytal"),std::exception);
    CHECK_THROWS_AS(l.addMother("Bruria","Meytal"),std::exception);

    CHECK(l.relation("Levi") == string("me"));
    CHECK(l.relation("Hadar") == string("mother"));
    CHECK(l.relation("Michal") == string("grandmother"));
    CHECK(l.relation("Bruria") == string("great-grandmother"));
    CHECK(l.relation("Hagar") == string("great-great-grandmother"));
    CHECK(l.relation("Sara") == string("unrelated"));

    CHECK(l.find("mother") == string("Hadar"));
    CHECK(l.find("grandmother") == string("Michal"));
    CHECK(l.find("great-grandmother") == string("Bruria"));
    CHECK(l.find("great-great-grandmother") == string("Hagar"));

    CHECK_THROWS_AS(l.find("me"),std::exception);
    CHECK_THROWS_AS(l.find("uncle"),std::exception);
    CHECK_THROWS_AS(l.find("great-great-great-grandmother"),std::exception);
}

TEST_CASE("Test remove()") {
    Tree y("Yossef");
    y.addFather("Yossef","Moshe");
    y.addMother("Yossef","Sara");
    y.addFather("Moshe","Avraham");
    y.addMother("Moshe","Rachel");

    y.remove("Avraham");
    CHECK_THROWS_AS(y.find("grandfather"),std::exception);
    CHECK(y.relation("Avraham") == string("unrelated"));

    y.remove("Rachel");
    CHECK_THROWS_AS(y.find("grandmother"),std::exception);
    CHECK(y.relation("Rachel") == string("unrelated"));

    y.remove("Moshe");
    CHECK_THROWS_AS(y.find("father"),std::exception);
    CHECK(y.relation("Moshe") == string("unrelated"));

    y.remove("Sara");
    CHECK_THROWS_AS(y.find("mother"),std::exception);
    CHECK(y.relation("Sara") == string("unrelated"));

    y.remove("Yossef");
    CHECK(y.relation("Yossef") == string("unrelated"));

    
}