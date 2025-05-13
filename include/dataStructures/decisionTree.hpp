//
// Created by nahue on 12/5/2025.
//

#ifndef DESICIONTREE_H
#define DESICIONTREE_H
#include <iostream>

template<typename TData>
struct Nodo{
    TData decision;
    Nodo* izquierda;
    Nodo* derecha;

    explicit Nodo(const TData& d)
        : decision(d), izquierda(nullptr), derecha(nullptr) {}
};

template<typename TData>
class decisionTree {
public:
    decisionTree();
    ~decisionTree();

    void insertar(const TData& decision);
    bool buscar(const TData& decision) const;
    void eliminar(const TData& decision);
    bool estaVacio() const;
    void recorrerPreorden() const;

private:
    Nodo<TData>* raiz;

    void insertar(Nodo<TData>*& nodo, const TData& decision);
    bool buscar(Nodo<TData>* nodo, const TData& decision) const;
    void eliminarNodo(Nodo<TData>*& nodo, const TData& decision);
    void recorrerPreorden(Nodo<TData>* nodo) const;
    void destruir(Nodo<TData>* nodo);
};



#endif //DESICIONTREE_H
