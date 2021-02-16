#include "Node.h"




Node::Node(std::string name, int id)
{
    m_id = id;
    m_name = name;
    m_next = nullptr;
}


void Node::SetNext(Node* next)
{
    m_next = next;
}

void Node::SetID(int id)
{
    m_id = id;
}

void Node::SetName(std::string name)
{
    m_name = name;
}

int Node::GetID()
{
    return m_id;
}

std::string Node::GetName()
{
    return m_name;
}

Node* Node::getNext()
{
    return m_next;
}

Node::~Node()
{
}
