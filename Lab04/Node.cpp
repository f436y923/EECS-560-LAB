#include "Node.h"

void Node::SetLeft(Node *temp) { m_left = temp; }

void Node::SetRight(Node *temp) { m_right = temp; }

void Node::SetParent(Node *temp) { m_parent = temp; }

Node *Node::GetLeft() { return m_left; }

Node *Node::GetRight() { return m_right; }

Node *Node::GetParent() { return m_parent; }

void Node::SetValue(int temp) { value = temp; }

int Node::GetValue() { return value; }

Node::Node() {
  m_left = nullptr;
  m_right = nullptr;
  m_parent = nullptr;
  value = 0;
}

Node::Node(int value) {
  m_left = m_right = m_parent = nullptr;
  this->value = value;
}

Node::~Node() {}
