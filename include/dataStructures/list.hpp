#ifndef LIST_HPP
#define LIST_HPP

#include <iostream>

/**
 * @brief Nodo de lista simplemente enlazada
 *
 * @tparam TData Tipo de dato almacenado
 */
template<typename TData>
struct ListNode
{
    TData data;
    ListNode* next;

    explicit ListNode(const TData& value)
        : data(value)
        , next(nullptr)
    {
    }
};

/**
 * @brief Implementación de una lista simplemente enlazada
 *
 * @tparam TData Tipo de dato almacenado
 */
template<typename TData>
class LinkedList
{
private:
    ListNode<TData>* head;

public:
    LinkedList()
        : head(nullptr)
    {
    }

    ~LinkedList()
    {
        while(head != nullptr){
            auto temp = head;
            head = head->next;
            delete temp;
        }
    }

    /**
     * @brief Inserta un nuevo elemento al inicio de la lista
     *
     * @param value Valor a insertar
     */
    void push_front(const TData& value)
    {
        auto temp = new ListNode<TData>(value);
        temp->next = head;
        head = temp;
    }

    /**
    * @brief Remueve un elemento de la lista dada su posición
    *
    * @param position Posición del elemento a remover
    */
    void remove_at(size_t position)
    {
        if(position < 1 or head == nullptr){
            std::cout << "Numero de posicion invalido."<< std::endl;
            return;
        }

        ListNode<TData>* actual = head;

        if (position == 1) {
            head = actual->next;
            delete actual;
            return;
        }

        ListNode<TData>* previous = nullptr;
        for (size_t i = 1; i < position && actual != nullptr; i++) {
            previous = actual;
            actual = actual->next;
        }
        if(actual != nullptr){
            previous->next = actual->next;
            delete actual;
            return;
        }
        std::cout << "Numero de posicion invalido."<< std::endl;
    }

    /**
    * @brief Crea una lista nueva de n elementos a partir de una posición dada
    *
    */
    LinkedList<TData>* take(size_t startPosition, size_t nElements)  //retornaba un ListNode, ahora una LinkedList, si nElements es tipo size_t no se puede corrdborar que no sea negativo
    {
        if(startPosition < 1 or nElements == 0 or head == nullptr){
            std::cout << "Parametros incorrectos."<< std::endl;
            return nullptr;
        }
        LinkedList<TData>* nueva = new LinkedList<TData>();
        ListNode<TData>* temporal = head;
        for (size_t i = 1; i < startPosition && temporal != nullptr; i++) {
            temporal = temporal->next;
        }

        nueva->head = temporal;

        if(temporal != nullptr){
            for (size_t i = 1; i < nElements && temporal != nullptr; i++) {
                temporal = temporal->next;
            }
            if(temporal != nullptr){
                temporal->next = nullptr;
            }
        }
        return nueva;
    }

    /**
     * @brief Imprime todos los elementos de la lista
     */
    void print() const
    {
        ListNode<TData>* current = head;
        while (current != nullptr)
        {
            std::cout << current->data << " -> ";
            current = current->next;
        }
        std::cout << "nullptr" << std::endl;
    }
};

/**
 * @brief Nodo de lista doblemente enlazada
 *
 * @tparam TData Tipo de dato almacenado
 */
template<typename TData>
struct DoublyListNode
{
    TData data;
    DoublyListNode* next;
    DoublyListNode* prev;

    explicit DoublyListNode(const TData& value)
        : data(value)
        , next(nullptr)
        , prev(nullptr)
    {
    }
};

/**
 * @brief Implementación de una lista doblemente enlazada
 *
 * @tparam TData Tipo de dato almacenado
 */
template<typename TData>
class DoublyLinkedList
{
private:
    DoublyListNode<TData>* head;

public:
    DoublyLinkedList()
        : head(nullptr)
    {
    }

    ~DoublyLinkedList()
    {
        while(head != nullptr){
            auto temp = head;
            head = head->next;
            delete temp;
        }
    }

    /**
     * @brief Inserta un nuevo elemento al inicio de la lista
     *
     * @param value Valor a insertar
     */
    void push_front(const TData& value)
    {
        auto temp = new DoublyListNode<TData>(value);
        if (head == nullptr) {
            head = temp;
        } else {
            temp->next = head;
            head->prev = temp;
            head = temp;
        }
    }

    /**
     * @brief Inserta un nuevo elemento al final de la lista
     *
     * @param value Valor a insertar
     */
    void push_back(const TData& value)
    {
        auto temp = new DoublyListNode<TData>(value);

        if (head == nullptr) {
            head = temp;
        }
        else {
            auto current = head;
            while (current->next != nullptr) {
                current = current->next;
            }
            current->next = temp;
            temp->prev = current;
        }
    }

    /**
    * @brief Remueve un elemento de la lista dada su posición
    *
    * @param position Posición del elemento a remover
    */
    void remove_at(size_t position)
    {
        if (position < 1 or head == nullptr) {
            std::cout << "Numero de posicion invalido."<< std::endl;
            return;
        }

        DoublyListNode<TData>* actual = head;

        if (position == 1) {
            head = actual->next;
            if (head != nullptr) {
                head->prev = nullptr;
            }
            delete actual;
            return;
        }

        for (size_t i = 1; i < position && actual != nullptr; i++) {
            actual = actual->next;
        }

        if(actual != nullptr){
            auto prev = actual->prev;
            auto sig = actual->next;
            prev->next = sig;
            if(sig != nullptr){
                sig->prev = prev;
            }
            delete actual;
            return;
        }
        std::cout << "Numero de posicion invalido."<< std::endl;
    }

    /**
    * @brief Copia los elementos de otra lista
    *
    * @param other Lista de la cual copiar los elementos
    */
    void copy_list(const DoublyLinkedList& other)
    {
        throw std::runtime_error("Not implemented yet");
    }

    /**
     * @brief Imprime todos los elementos de la lista
     */
    void print() const
    {
        DoublyListNode<TData>* current = head;
        while (current != nullptr)
        {
            std::cout << current->data << " <-> ";
            current = current->next;
        }
        std::cout << "nullptr" << std::endl;
    }
};

#endif // LIST_HPP
