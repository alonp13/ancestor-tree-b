#include <iostream>
#include <string>
#include <stdexcept>
using namespace std;

typedef enum gender
{
    MALE,
    FEMALE,
    UNI
} gender;

namespace family
{
class Node
{
private:
    string m_name;
    Node *m_father;
    Node *m_mother;
    int m_level;
    string m_relation;

public:
    Node(string name);
    void setFather(Node *father);
    void setMother(Node *mother);
    void setLevel(int level);
    void setRelation(gender g, int level);
    string getName();
    Node *getFather();
    Node *getMother();
    int getLevel();
    string getRelation();
};

class Tree
{

private:
    Node *m_root;
    Node *findChild(Node *node, string name);

public:
    Tree(string name);
    Tree &addFather(string child, string father);
    Tree &addMother(string child, string mother);
    string relation(string name);
    string find(string name);
    void display(Node *r);
    void display();
    void remove(string name);
};
}; // namespace family