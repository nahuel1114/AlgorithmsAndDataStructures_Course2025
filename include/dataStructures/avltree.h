//
// Created by nahue on 15/5/2025.
//

#ifndef AVLTREE_H
#define AVLTREE_H

struct Node{
    int outpostID;
    int hight;
    int priority;
    Node* left;
    Node* right;

    explicit Node(const int d, const int p)
        : outpostID(d), hight(0), priority(p), left(nullptr), right(nullptr) {}
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

    void insert_p(Node*& node, const int outpostID, const int priority);
    void remove_p(Node*& node, const int outpostID, const int priority);
    bool contain_p(Node*& node, const int outpostID, const int priority) const;
    int find_p(Node*& node, bool action);
    void printInOrder_p(Node*& node) const;
    void printStats_p() const;
    void destroy(Node*& node);
    void actualizarAltura_p(Node*& node) const;
    void rotacion_p(Node*& node);
};


#endif //AVLTREE_H
