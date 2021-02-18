#include "Node.h"

Node::Node() {
  m_id = -1;
  m_next = nullptr;
}

void Node::SetNext(Node *next) { m_next = next; }

void Node::SetID(int id) { m_id = id; }

int Node::GetID() { return m_id; }

Node *Node::getNext() { return m_next; }

Node::~Node() {}
