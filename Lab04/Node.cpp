#include "Node.h"

void Node::SetLeft(Node *temp) { m_left = temp; }

void Node::SetRight(Node *temp) { m_right = temp; }

Node *Node::GetLeft() { return m_left; }

Node *Node::GetRight() { return m_right; }

void Node::SetValue(int temp) { value = temp; }

int Node::GetValue() { return value; }

Node::Node() {
  m_left = nullptr;
  m_right = nullptr;
  value = 0;
}

Node::Node(int value) {
  m_left = m_right = nullptr;
  this->value = value;
}

Node::~Node() {}
