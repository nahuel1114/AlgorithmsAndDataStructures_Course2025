//
// Created by nahue on 5/4/2025.
//

#include "../include/dataStructures/stack.hpp"

#include <iostream>

template<typename TData>
Stack<TData>::Stack()
    : m_top(nullptr), m_size(0) {}

template<typename TData>
Stack<TData>::~Stack()
{
    while(isEmpty()){
        pop();
    }
}

template<typename TData>
void Stack<TData>::push(const TData& value)
{
    Node* newNode = new Node(value, m_top);
    m_top = newNode;
    ++m_size;
}

template<typename TData>
void Stack<TData>::pop()
{
    if (isEmpty())
    {
        throw std::underflow_error("Stack is empty");
    }

    auto newNode = m_top;
    m_top = m_top->next;
    --m_size;
    delete newNode;
}

template<typename TData>
TData& Stack<TData>::top()
{
    if (isEmpty()){
        throw std::underflow_error("Stack is empty");
    }
    return m_top->data;
}

template<typename TData>
const TData& Stack<TData>::top() const
{
    if (isEmpty()){
        throw std::underflow_error("Stack is empty");
    }
    return m_top->data;
}

template<typename TData>
bool Stack<TData>::isEmpty() const
{
    return m_top == nullptr;
}

template<typename TData>
size_t Stack<TData>::size() const
{
    return m_size;
}

template<typename TData>
void Stack<TData>::print() const
{
    auto temp = m_top;
    while(temp != nullptr)
    {
        std::cout << temp->data << " ";
        temp = temp->next;
    }
}
