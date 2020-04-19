#include "FamilyTree.hpp"
using namespace family;

// Node class implemntion:
Node::Node(string name)
{
    m_name = name;
    m_father = NULL;
    m_mother = NULL;
    m_level = 0;
}

void Node::setFather(Node *father)
{
    m_father = father;
}

void Node::setMother(Node *mother)
{
    m_mother = mother;
}

void Node::setLevel(int level)
{
    m_level = level;
}

string Node::getName()
{
    return m_name;
}

Node *Node::getFather()
{
    return m_father;
}

Node *Node::getMother()
{
    return m_mother;
}

int Node::getLevel()
{
    return m_level;
}

void Node::setRelation(gender g, int level)
{
    if (level == 0)
    {
        m_relation = "me";
        return;
    }

    string suffix = "";

    switch (g)
    {
    case MALE:
        suffix = "father";
        break;

    case FEMALE:
        suffix = "mother";

    case UNI:
        break;

    default:
        throw std::runtime_error("No such gender!");
        
    }

    switch (level)
    {
    case 1:
        m_relation = suffix;
        return;
    case 2:
        m_relation = "grand" + suffix;
        return;
    default:
        string tmp = "grand" + suffix;
        for (int i = 0; i < level - 2; i++)
        {
            tmp = "great-" + tmp;
        }
        m_relation = tmp;
        return;
    }
}
string Node::getRelation()
{
    return m_relation;
}

// Tree class implemention:
Tree::Tree(string name)
{
    m_root = new Node(name);
    m_root->setLevel(0);
    m_root->setRelation(MALE, 0);
}

Node *Tree::findChild(Node *node, string tosearch ,search_type st)
{
    if (node == NULL)
    {
        return NULL;
    }

   // cout << node->getName() << endl;

    switch (st)
    {
    case BY_NAME:
           if (node->getName() == tosearch)
        {
            return node;
        }
        break;

    case BY_RELATION:

        if (node->getRelation() == tosearch)
        {
            return node;
        }
        break;

    default:
       throw std::runtime_error("No search type!");
    }


    Node *father = findChild(node->getFather(), tosearch, st);

    if (father != NULL)
    {
        return father;
    }

    return findChild(node->getMother(), tosearch, st);
}

Tree &Tree::addFather(string child, string father)
{
    Node *child_found = findChild(m_root, child, BY_NAME);

    if (child_found == NULL)
    {
        throw std::runtime_error("No such child!");
    }

    if (child_found->getFather() != NULL)
    {
        throw std::runtime_error("The child is already has a father!");
    }

    Node *new_node = new Node(father);
    int level = child_found->getLevel() + 1;
    new_node->setLevel(level);
    new_node->setRelation(MALE, level);
    child_found->setFather(new_node);

    return *this;
}

Tree &Tree::addMother(string child, string mother)
{
    Node *child_found = findChild(m_root, child, BY_NAME);

    if (child_found == NULL)
    {
        throw std::runtime_error("No such child!");
    }

    if (child_found->getMother() != NULL)
    {
        throw std::runtime_error("The child is already has a mother!");
    }

    Node *new_node = new Node(mother);
    int level = child_found->getLevel() + 1;
    new_node->setLevel(level);
    new_node->setRelation(FEMALE, level);
    child_found->setMother(new_node);

    return *this;
}

string Tree::relation(string name)
{
    Node *child_found = findChild(m_root, name, BY_NAME);
    if (child_found == NULL)
    {
        return string("unrelated");
    }
    return child_found->getRelation();
}

string Tree::find(string relation)
{
    Node* child_found = findChild(m_root,relation,BY_RELATION);

    if(child_found == NULL)
    {
        throw std::runtime_error("No such relation!");
    }
    return child_found->getName();
}

void Tree::display(Node *r)
{
    if (r == NULL)
        return;
    
    cout << r->getName() << "|" << r->getLevel() << "," << r->getRelation() << endl;
    display(r->getFather());
    display(r->getMother());
}

void Tree::display()
{
    display(m_root);
    cout << endl;
}


void Tree::remove(Node* node)
{
    if(node == NULL)
    {
        return;
    }
    
    remove(node->getFather());
    remove(node->getMother());

    delete node;
}


Node *Tree::findChild(Node *node, string name)
{
    if(node != NULL)
    {
        if(node->getFather() != NULL)
        {
            if(node->getFather()->getName() == name)
            {
                return node;
            }
        }
        if(node->getMother() != NULL)
        {
            if(node->getMother()->getName() == name)
            {
                return node;
            }
        }
    } else {
        return NULL;
    }

    Node *father = findChild(node->getFather(), name);

    if (father != NULL)
    {
        return father;
    }

    return findChild(node->getMother(), name);

}


void Tree::remove(string name)
{
    Node* child_found = findChild(m_root,name);

    if(child_found == NULL)
    {
        throw std::runtime_error("No such child!");
    }

    if(m_root->getName() == name)
    {
        throw std::runtime_error("Cannot remove the root!");
    }

    if(child_found->getFather() != NULL && child_found->getFather()->getName() == name)
    {
        remove(child_found->getFather());
        child_found->setFather(NULL);
    }

    if(child_found->getMother() != NULL && child_found->getMother()->getName() == name)
    {
        remove(child_found->getMother());
        child_found->setMother(NULL);
    }

}



// Node::~Node()
// {
//     delete[] &m_relation;
//     delete[] &m_name;
//     m_father = NULL;
//     m_mother = NULL;
// }
