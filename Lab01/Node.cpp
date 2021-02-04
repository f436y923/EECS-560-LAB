#include "Node.h"

Node::Node(int value)
{
    m_value = value;
    m_next = nullptr;
    m_pre = nullptr;
}

void Node::setNext(Node *next)
{
    m_next = next;
}

void Node::setPre(Node *pre)
{
    m_pre = pre;
}

Node *Node::getNext()
{
    return m_next;
}

Node *Node::getPre()
{
    return m_pre;
}

Node::~Node()
{
}

int Node::getValue()
{
    return m_value;
}

void Node::setValue(int _value)
{
    m_value = _value;
}