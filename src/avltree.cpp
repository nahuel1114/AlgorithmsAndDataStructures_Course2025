//
// Created by nahue on 15/5/2025.
//

#include "avltree.h"
#include<iostream>;

 avltree::avltree(): root(nullptr){}

 avltree::~avltree()
 {
     destroy();
 }

void avltree::insert(const int outpostID, const int priority)
 {
     insert_p(root, outpostID, priority);
 }

void avltree::insert_p(Node*& node, const int outpostID, const int priority)
 {
     if (!node)
     {
         node = new Node(outpostID, priority);
         actualizarAltura_p(root);
         return;
     }
     if (priority >= node->priority) insert_p(node->right, outpostID, priority);
     else insert_p(node->left, outpostID, priority);
 }

void avltree::remove(const int outpostID, const int priority)
 {
     remove_p(root, outpostID, priority);
 }

void avltree::remove_p(Node*& node, const int outpostID, const int priority)
 {
     if (!node) return;
     if (priority > node->priority) remove_p(node->right, outpostID, priority);
     else if (priority < node->priority) remove_p(node->left, outpostID, priority);
     else
     {
         if (node->outpostID == outpostID) REMOVE & actualizarAltura_p();
         else if (!node->right) remove_p(node->right, outpostID, priority);
     }
 }

bool avltree::contain(const int outpostID,const int priority)
 {
     return contain_p(root, outpostID, priority);
 }

bool avltree::contain_p(Node*& node, const int outpostID, const int priority) const
 {
     if (!node) return false;
     if (priority > node->priority) contain_p(node->right, outpostID, priority);
     else if (priority < node->priority) contain_p(node->left, outpostID, priority);
     else
     {
         if (node->outpostID == outpostID) return true;
         else if(!node->right) contain_p(node->right, outpostID, priority);
     }
 }

int avltree::findMIn()
 {
     return find_p(root, false);
 }

int avltree::findMax()
 {
     return find_p(root, true);
 }

int avltree::find_p(Node*& node, bool action)
 {
     if (!node) return 0;

     int min_max = 0;
     if (action)
     {
         while (!node->right)
         {
             node = node->right;
         }
         min_max = node->priority;
     }
     else
     {
         while (!node->left)
         {
             node = node->left;
         }
         min_max = node->priority;
     }
     return min_max;
 }

void avltree::printInOrder()
 {
     printInOrder_p(root);
 }

void avltree::printInOrder_p(Node*& node) const
 {
     if (!node) return;

     printInOrder_p(node->left);
     std::cout<<("Identificacion del puesto de avanzada: ")<<node->outpostID<<", prioridad: "<<node->priority<<std::endl;
     printInOrder_p(node->right);
 }

void avltree::printStats() const
 {
     printStats_p();
 }

void avltree::printStats_p() const
{
    std::cout<<""<<number_of_nodes<<std::endl;
}






