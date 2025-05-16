//
// Created by nahue on 15/5/2025.
//

#ifndef AVLTREE_H
#define AVLTREE_H

struct Node{
    int outpostID;
    int height;
    int priority;
    Node* left;
    Node* right;

    explicit Node(const int d, const int p)
        : outpostID(d), height(0), priority(p), left(nullptr), right(nullptr) {}
};

class avltree {
public:
    avltree();
    ~avltree();
    void insert(const int outpostID, const int priority);
    void remove(const int outpostID, const int priority);
    bool contain(const int outpostID,const int priority);
    int findMIn();
    int findMax();
    void printInOrder();
    void printStats() const;

private:
    Node* root;
    int number_of_nodes;

    Node* insert(Node*& node, const int outpostID, const int priority);
    Node* remove(Node*& node, const int outpostID, const int priority);
    Node* checks_rotation(Node*& node);
    bool contain(Node*& node, const int outpostID, const int priority) const;
    int find(Node*& node, bool action);
    void printInOrder(Node*& node) const;
    void printStats_p() const;
    void destroy(Node*& node);
    void updateHeight(Node*& node) const;
    int height(Node*& node) const;
    int balance(Node*& node);
    Node* rotationLeft(Node*& node);
    Node* rotationRight(Node*& node);
};


#endif //AVLTREE_H
