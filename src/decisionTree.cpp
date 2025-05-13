//
// Created by nahue on 12/5/2025.
//

#include "../include/dataStructures/decisionTree.hpp"

template<typename TData>
decisionTree<TData>::decisionTree()
    :raiz(nullptr){}

template<typename TData>
decisionTree<TData>::~decisionTree()
{
    destruir(raiz);
}

template<typename TData>
void decisionTree<TData>::destruir(Nodo<TData>* nodo)
{
    if(nodo!=nullptr)
    {
        destruir(nodo->izquierda);
        destruir(nodo->derecha);
        delete nodo;
    }
}

template<typename TData>
void decisionTree<TData>::insertar(const TData& decision)
{
    insertar(raiz, decision);
}

template<typename TData>
void decisionTree<TData>::insertar(Nodo<TData>*& nodo, const TData& decision){
    if(nodo == nullptr){
        nodo = new Nodo(decision);
    }
    else if(decision >= nodo->decision){
        insertar(nodo->derecha, decision);
    }
    else{
        insertar(nodo->izquierda, decision);
    }
}

template<typename TData>
bool decisionTree<TData>::buscar(const TData& decision) const{
    return buscar(raiz, decision);
}

template<typename TData>
bool decisionTree<TData>::buscar(Nodo<TData>* nodo, const TData& decision) const{
    if(nodo == nullptr){
        return false;
    }
    if(nodo->decision == decision){
        return true;
    }

    if(decision > nodo->decision){
        return buscar(nodo->derecha, decision);
    }

    return buscar(nodo->izquierda, decision);
}

template<typename TData>
void decisionTree<TData>::eliminar(const TData& decision){
    eliminarNodo(raiz, decision);
}

template<typename TData>
void decisionTree<TData>::eliminarNodo(Nodo<TData>*& nodo, const TData& decision){
    if(nodo->decision == decision){
        if(nodo->izquierda == nullptr & nodo->derecha == nullptr){
            delete nodo;
        }
        else if(nodo->izquierda == nullptr){
            auto* temp = nodo->derecha;
            delete nodo;
            nodo = temp;
        }
        else if(nodo->derecha == nullptr){
            auto temp = nodo->izquierda;
            delete nodo;
            nodo = temp;
        }
        else{
            auto* temp = nodo->izquierda;
            while(temp != nullptr){
                temp = temp->derecha;
            }
            delete nodo;
            nodo = temp;
        }
    }
    else if(nodo->decision < decision){
        eliminarNodo(nodo->derecha, decision);
    }
    else{
        eliminarNodo(nodo->izquierda, decision);
    }
}

template<typename TData>
bool decisionTree<TData>::estaVacio() const{
    return raiz==nullptr;
}

template<typename TData>
void decisionTree<TData>::recorrerPreorden() const{
    recorrerPreorden(raiz);
}

template<typename TData>
void decisionTree<TData>::recorrerPreorden(Nodo<TData>* nodo) const{
    if(nodo == nullptr){ return;}
    std::cout << nodo->decision << std::endl;
    recorrerPreorden(nodo->izquierda);
    recorrerPreorden(nodo->derecha);
}