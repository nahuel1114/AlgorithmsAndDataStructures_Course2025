//
// Created by nahue on 15/5/2025.
//

#include "avltree.h"
#include<iostream>;

 avltree::avltree(): root(nullptr){}

 avltree::~avltree()
 {
     destroy(root);
 }

void avltree::insert(const int outpostID, const int priority)
 {
     root = insert(root, outpostID, priority);
 }

Node* avltree::insert(Node*& node, const int outpostID, const int priority)
 {
     if (!node) return new Node(outpostID, priority);

     if (priority >= node->priority) insert(node->right, outpostID, priority);
     else insert(node->left, outpostID, priority);

     updateHeight(node);

     int b = balance(node);

     if (b > 1 && priority < node->left->priority) return rotationRight(node);

     if (b < -1 && priority > node->right->priority) return rotationLeft(node);

     if (b > 1 && priority > node->left->priority){
        node->left = rotationLeft(node->left);
        return rotationRight(node);
     }

     if (b < -1 && priority < node->right->priority){
         node->right = rotationRight(node->right);
         return rotationLeft(node);
     }

     return node;
 }

void avltree::remove(const int outpostID, const int priority)
 {
     remove(root, outpostID, priority);
 }

void avltree::remove(Node*& node, const int outpostID, const int priority)
 {
     if (!node) return;
     if (priority > node->priority) remove(node->right, outpostID, priority);
     else if (priority < node->priority) remove(node->left, outpostID, priority);
     else
     {
         if (node->outpostID == outpostID)
         {
             if (node->left == nullptr && node->right == nullptr) delete node;
             else if (node->left == nullptr)
             {
                 Node* temp = node->right;
                 delete node;
                 node = temp;
             }
             else if (node->right == nullptr)
             {
                 Node* temp = node->left;
                 delete node;
                 node = temp;
             }
             else
             {
                 Node* temp = node->left;
                 while (!temp->right)
                 {
                     temp = temp->right;
                 }
                 delete node;
                 node = temp;
             }
         }
         else if (!node->right) remove(node->right, outpostID, priority);
     }

     checks_rotation(node);
 }

void avltree::checks_rotation(Node*& node)
 {
     updateHeight(node);
     int b = balance(node);

     if (b > 1 && !node->left->left) rotationRight(node);

     if (b < -1 && !node->right->right) rotationLeft(node);

     if (b > 1 && !node->left->right){
         node->left = rotationLeft(node->left);
         rotationRight(node);
     }

     if (b < -1 && !node->right->left){
         node->right = rotationRight(node->right);
         rotationLeft(node);
     }

 }

bool avltree::contain(const int outpostID,const int priority)
 {
     return contain(root, outpostID, priority);
 }

bool avltree::contain(Node*& node, const int outpostID, const int priority) const
 {
     if (!node) return false;
     if (priority > node->priority) contain(node->right, outpostID, priority);
     else if (priority < node->priority) contain(node->left, outpostID, priority);
     else
     {
         if (node->outpostID == outpostID) return true;
         else if(!node->right) contain(node->right, outpostID, priority);
     }
 }

int avltree::findMIn()
 {
     return find(root, false);
 }

int avltree::findMax()
 {
     return find(root, true);
 }

int avltree::find(Node*& node, bool action)
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
     printInOrder(root);
 }

void avltree::printInOrder(Node*& node) const
 {
     if (!node) return;

     printInOrder(node->left);
     std::cout<<("Identificacion del puesto de avanzada: ")<<node->outpostID<<", prioridad: "<<node->priority<<std::endl;
     printInOrder(node->right);
 }

void avltree::printStats() const
 {
     printStats();
 }

void avltree::printStats_p() const
{
    std::cout<<"Cantidad de nodos en el arbol: "<<number_of_nodes<<std::endl;
     std::cout<<"Altura maxima del arbol: "<<root->height<<std::endl;
}

void avltree::destroy(Node*& node)
{
     if (!node)
     {
         destroy(node->left);
         destroy(node->right);
         delete node;
     }
}

void avltree::updateHeight(Node*& node) const
{
    if (!node) return;

    node->height = 1 + std::max(node->left->height, node->right->height);
}

int avltree::balance(Node*& node)
 {
     if (!node) return 0;

     return node->left->height - node->right->height;
 }

Node* avltree::rotationLeft(Node*& node)
{
     Node* aux1 = node->right;
     Node* aux2 = aux1->left;

     aux1->left = node;
     node->right = aux2;

     updateHeight(node);
     updateHeight(aux1);

     return aux1;
}

Node* avltree::rotationRight(Node*& node)
 {
     Node* aux1 = node->left;
     Node* aux2 = aux1->right;

     aux1->right = node;
     node->left = aux2;

     updateHeight(node);
     updateHeight(aux1);

     return aux1;
 }









