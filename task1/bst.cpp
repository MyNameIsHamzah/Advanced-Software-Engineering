#include "bst.h"
#include <cassert>
#include <iostream>

struct BST::Node
{
    Node(KeyType, ItemType);
    BST::KeyType key;
    BST::ItemType item;
    Node* leftChild;
    Node* rightChild;
};

BST::Node::Node(KeyType key, ItemType item)
{
    this->key = key;
    this->item = item;
    this->leftChild = BST::leaf();
    this->rightChild = BST::leaf();
}

BST::Node* BST::leaf()
{
    return nullptr;
}

bool BST::isLeaf(Node* n)
{
    return (n == nullptr);
}

BST::ItemType* BST::lookup(KeyType soughtKey)
{
    return lookupRec(soughtKey, this->root);
}

BST::ItemType* BST::lookupRec(KeyType soughtKey, Node* currentNode)
{
    if(!isLeaf(currentNode))
    {
        if (soughtKey == currentNode->key)
        {
            return &currentNode->item;
        }
        else if (soughtKey < currentNode->key)
        {
            return lookupRec(soughtKey, currentNode->leftChild);
        }
        else if (soughtKey > currentNode->key)
        {
            return lookupRec(soughtKey, currentNode->rightChild);
        }
    }
    return nullptr;
}

void BST::insert(KeyType newKey, ItemType newItem)
{
    insertRec(newKey, newItem, this->root);
}

void BST::insertRec(KeyType newKey, ItemType newItem, Node* &currentNode)
{
    if (isLeaf(currentNode))
    {
        Node* newNode = new Node(newKey, newItem);
        currentNode = newNode;
    }
    else if (newKey == currentNode->key)
    {
        currentNode->item = newItem;
    }
    else if (newKey < currentNode->key)

    {
        insertRec(newKey, newItem, currentNode->leftChild);
    }
    else if (newKey > currentNode->key)
    {
        insertRec(newKey, newItem, currentNode->rightChild);
    }
}

void BST::remove(KeyType soughtKey)
{

    if (!isLeaf(this->root))
    {
        if (!isLeaf(this->root->leftChild) || !isLeaf(this->root->rightChild))
        {
            removeRec(this->root, soughtKey);
        }
        else if (this->root->key == soughtKey)
        {
            this->root = leaf();
        }
    }
}

void BST::removeRec(Node * & currentNode, KeyType soughtKey)
{
    if (!isLeaf(currentNode))
    {
        if (soughtKey == currentNode->key)
        {
            if (!isLeaf(currentNode->leftChild) && !isLeaf(currentNode->rightChild))
            {

                Node* minimumNode = detachMinimumNode(currentNode->rightChild);
                currentNode->key = minimumNode->key;
                currentNode->item = minimumNode->item;
            }
            else if(isLeaf(currentNode->leftChild) && isLeaf(currentNode->rightChild))
            {
                currentNode = leaf();
            }
            else if(!isLeaf(currentNode->leftChild))
            {
                Node* tempNode = currentNode;
                currentNode = currentNode->leftChild;
                delete(tempNode);
            }
            else if(!isLeaf(currentNode->rightChild))
            {
                Node* tempNode = currentNode;
                currentNode = currentNode->rightChild;
                delete(tempNode);
            }
        }
        else if (soughtKey < currentNode->key)
        {
            removeRec(currentNode->leftChild, soughtKey);
        }
        else if (soughtKey > currentNode->key)
        {
            removeRec(currentNode->rightChild, soughtKey);
        }
    }
}


BST::Node* BST::detachMinimumNode(Node * & currentNode)
{
    if(isLeaf(currentNode->leftChild))
    {

        Node* minimumNode = new Node(currentNode->key, currentNode->item);
        currentNode = leaf();
        return minimumNode;
    }
    else
    {
        return detachMinimumNode(currentNode->leftChild);
    }
}

void BST::displayEntries()
{
    inOrderTraversal(this->root);
}

void BST::inOrderTraversal(Node * & currentNode)
{
    if (!isLeaf(currentNode))
    {
        // Traverses the left branch
        if (!isLeaf(currentNode->leftChild))
        {
            inOrderTraversal(currentNode->leftChild);
        }

        std::cout << currentNode->key << '\t' << currentNode->item << std::endl;

        // Traverses the right branch
        if (!isLeaf(currentNode->rightChild))
        {
            inOrderTraversal(currentNode->rightChild);
        }
    }
}

void BST::displayTree()
{
    if (!isLeaf(root))
    {
        preOrderTraversal(this->root, "");
    }
    else
    {
        std::cout << '*' << std::endl;
    }
}

void BST::preOrderTraversal(Node * &currentNode, std::string tab)
{
    tab += "\t";

    std::cout << tab << currentNode->key << std::endl;

    if (!isLeaf(currentNode->leftChild))
    {
        preOrderTraversal(currentNode->leftChild, tab);
    }
    else
    {
       std::cout << tab << "*" << std::endl;
    }

    if (!isLeaf(currentNode->rightChild))
    {
        preOrderTraversal(currentNode->rightChild, tab);
    }
    else
    {
        std::cout << tab << "*" << std::endl;
    }
}

void BST::deepDelete(Node * current)
{
    if (!isLeaf(current))
    {
        deepDelete(current->leftChild);
        deepDelete(current->rightChild);

        delete(current);
    }
}

BST::Node* BST::deepCopy(Node * originalNode)
{
    if (!isLeaf(originalNode))
    {
        Node* newNode = new Node(originalNode->key, originalNode->item);
        newNode->leftChild = deepCopy(originalNode->leftChild);
        newNode->rightChild = deepCopy(originalNode->rightChild);
        return newNode;
    }
    return originalNode;
}


//week 5 move functionalities

BST::BST(const BST & originalTree)
{
    this->root = deepCopy(originalTree.root);
}
// same time complexity as deepcopy

BST::~BST()
{
    deepDelete(root);
}
// same time complexity as deep delete

BST & BST::operator=(const BST & bstToCopy)
{
    if (this != &bstToCopy)
    {
        deepDelete(this->root);
    }
    this->root = deepCopy(bstToCopy.root);
    return *this;
}
// same time complexity of deepDelete and deepCopy O(2), simplifies to O(1)


BST::BST(BST && originalTree)
{
    this->root = originalTree.root;
    originalTree.root = leaf();
}
//O(1)

BST & BST::operator=(BST && bstToMove)
{
    this->root = bstToMove.root;
    if (this != &bstToMove)
    {
        bstToMove.root = leaf();
    }
    return *this;
}
//O(1)
