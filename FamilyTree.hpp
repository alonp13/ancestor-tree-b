#include <iostream>
#include <string>
#include <stdexcept>
using namespace std;

typedef enum search_type
{
    BY_NAME,
    BY_RELATION
} search_type;

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
   // ~Node();
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

    Node *findChild(Node *node, string name, search_type st);
    void remove(Node* node);

public:
    Node *m_root; // need to be private
    Tree(string name);
    Tree &addFather(string child, string father);
    Tree &addMother(string child, string mother);
    string relation(string name);
    string find(string relation);
    void display(Node *r);
    void display();
    Node* findChild(Node *node, string tosearch);
    void remove(string name);
    
};
}; // namespace family