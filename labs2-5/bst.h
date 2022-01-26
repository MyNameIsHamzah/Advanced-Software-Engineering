#ifndef BST_H
#define BST_H

#endif // BST_H
#include <iostream>


using namespace std;

struct Node
{
  int key;
  std::string item;
  Node* leftChild;
  Node* rightChild;


  Node(int,std::string);

};

class BST
{
public:
    using KeyType = int;
    using ItemType = std::string;
    //using KeyType = K;
    //using ItemType = I;
    BST() = default;
    ~BST();
    BST(const BST &);
    BST & operator=(const BST &);
    BST(BST &&);
    BST & operator=(BST &&);
    ItemType* lookup(KeyType);
    void insert(KeyType, ItemType);
    void remove(KeyType);
    void displayEntries();
    void displayTree();
    //void removeIf(std::function <bool(KeyType)>);

private:
    struct Node;
    Node* root = leaf();
    static Node* leaf();
    static bool isLeaf(Node*);
    ItemType* lookupRec(KeyType, Node*);
    void insertRec(KeyType, ItemType, Node* &);
    void inOrderTraversal(Node* &);
    void preOrderDisplay(Node* &, std::string);
    void removeRec(Node* &, KeyType);
    Node* detachMinimumNode(Node* &);
    void deepDelete(Node*);
    Node* deepCopy(Node*);

};
