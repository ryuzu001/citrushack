#include "BSTree.h"

BSTree::BSTree() {
    root = 0;
}

BSTree::~BSTree() {
    // if(root != 0) {
    //     delete root->getLeft();
    //     cout << "1" << endl;
    //     delete root->getRight();
    //     cout << "2" << endl;
    //     delete root;
    //     cout << "3" << endl;
    //     root = 0;
    //     cout << "destructor finished" << endl;
    // }
}

void BSTree::preOrder(Node* n) const {
    if(n != 0) {
        cout << n->getData() << "(" << n->getCount() << "), ";
        preOrder(n->getLeft());
        preOrder(n->getRight());
    }
}

void BSTree::inOrder(Node* n) const {
    if(n != 0) {
        inOrder(n->getLeft());
        cout << n->getData() << "(" << n->getCount() << "), ";
        inOrder(n->getRight());
    }
}

void BSTree::postOrder(Node* n) const {
    if(n != 0) {
        postOrder(n->getLeft());
        postOrder(n->getRight());
        cout << n->getData() << "(" << n->getCount() << "), ";
    }
}

Node* BSTree::search(Node* x, const string& s) const {
    if(x != 0) {
        if(s == x->getData()) {
            return x;
        }
        else if(s < x->getData()) {
            if(x->getLeft() != 0) {
                return search(x->getLeft(), s);
            }
        }
        else {
            if(x->getRight() != 0) {
                return search(x->getRight(), s);
            }
        }
    }
    return 0;
}

// TreeInsert(tree, node) {
//   if (tree->root is 0)
//     tree->root = node
//     node->left = 0
//     node->right = 0
//   else
//     cur = tree->root
//     while (cur is not 0) 
//       if (node->key < cur->key)
//          if (cur->left is 0)
//           cur->left = node
//           cur = 0
//          else
//           cur = cur->left
//       else 
//          if (cur->right is 0)
//           cur->right = node
//           cur = 0
//          else
//           cur = cur->right       
//     node->left = 0
//     node->right = 0
// }

void BSTree::insert(const string& s) {
    Node* toInsert = new Node(s);
    // if(search(s)) {
    //     search(root, s)->incrementCount();
    // }
    if(root == 0) {
        root = toInsert;
        root->incrementCount();
    }
    else {
        Node* current = root;
        while(current != 0) {
            if(current->getData() == s) {
                current->incrementCount();
                return;
            }
            if(toInsert->getData() < current->getData()) { //if toInsert's string is smaller than the root/node's string
                if(current->getLeft() == 0) { //if current node's left is empty
                    current->setLeft(toInsert); //set current's left to toInsert
                    current->getLeft()->incrementCount(); //increment string's count
                    toInsert->setParent(current); //set parent pointer to previous node
                    current = 0; //set current to 0
                }
                else {
                    current = current->getLeft();
                }
            }
            else {
                if(current->getRight() == 0) { //if current node's right is empty
                    current->setRight(toInsert); //set current's right to toInsert
                    current->getRight()->incrementCount(); //increment string's count
                    toInsert->setParent(current);
                    current = 0; //set current to 0
                }
                else {
                    current = current->getRight();
                }
            }
        }
    }
}

// TreeSearch(tree, key) {
//   cur = tree->root   
//   while (cur is not 0)
//       if (key == cur->key)
//          return cur // Found
//       else if (key < cur->key)
//          cur = cur->left
//       else
//          cur = cur->right
//   return 0 // Not found
// }

bool BSTree::search(const string& s) const {
        if(root == 0) {
            return false;
        }
        // else if(s < root->getData()) {
        //     if(root->getLeft() != 0) {
        //         if(search(root->getLeft(), s) != 0) {
        //             return true;
        //         }
        //     }
        // }
        // else {
        //     if(root->getRight() != 0) {
        //         if(search(root->getRight(), s) != 0) {
        //             return true;
        //         }
        //     }
        // }
        else {
            if(search(root, s) != 0) {
                return true;
            }
        }
    return false;
}

void BSTree::inOrder( ) const {
    if(root == 0) {
        cout << endl;
        return;
    }
    
    inOrder(root);
    cout << endl;
}

void BSTree::postOrder( ) const {
    if(root == 0) {
        cout << endl;
        return;
    }
    
    postOrder(root);
    cout << endl;
}

void BSTree::preOrder( ) const {
    if(root == 0) {
        cout << endl;
        return;
    }
    
    preOrder(root);
    cout << endl;
}

string BSTree::largest( ) const {
    if(root == 0) {
        return "";
    }
    
    string largest = findLargest(root)->getData();
    
    return largest;
}

string BSTree::smallest( ) const {
    if(root == 0) {
        return "";
    }
    
    string smallest = findSmallest(root)->getData();
    
    return smallest;
}

int BSTree::height(const string& s) const {
    if(!search(s)) {
        return -1;
    }
    // if(s == root->getData()) {
    //     return 0;
    // }
    else {
        Node* toFind = search(root, s);
        return height(toFind);
    }
}

int BSTree::height(Node* x) const {
    if(x == 0) {
        return 0;
    }
    if(x->getLeft() == 0 && x->getRight() == 0) {
        return 0;
    }
    else {
        int heightLeft = 1 + height(x->getLeft());
        int heightRight = 1 + height(x->getRight());
        
        if(heightLeft > heightRight) {
            return heightLeft;
        }
        else {
            return heightRight;
        }
    }
}

void BSTree::remove(const string& s) {
    if(root == 0) {
        return;
    }
    if(!search(s)) {
        return;
    }
    else {
        Node* toRemove = search(root, s);
        if(toRemove->getCount() > 1) {
            toRemove->decrementCount();
            return;
        }
        else {
            remove(toRemove);
        }
    }
}

void BSTree::remove(Node* x) {
    // if(s > x->getData()) {
    //     remove(x->getRight(), s);
    // }
    // else if(s < x->getData()) {
    //     remove(x->getLeft(), s);
    // }
    // else {
    //     if(x->getRight() != 0) {
    //         Node* t = findSmallest(x->getRight());
    //         x->setData(t->getData());
    //         remove(x->getRight(), x->getData());
    //     }
    //     else if(x->getLeft() != 0) {
    //         Node* t = findLargest(x->getLeft());
    //         x->setData(t->getData());
    //         remove(x->getLeft(), x->getData());
    //     }
    //     else {
    //         delete x;
    //         x = 0;
    //     }
    // }
    if(x == root && x->getLeft() == 0 && x->getRight() == 0) {
        delete x;
        root = 0;
    }
    else if(x->getLeft() == 0 && x->getRight() == 0) {
        if(x == x->getParent()->getLeft()) {
            //Node* parentLeft = x->getParent()->getLeft();
            x->getParent()->setLeft(0);
            return;
        }
        else {
            //Node* parentRight = x->getParent()->getRight();
            x->getParent()->setRight(0);
            return;
        }
    }
    else if(!x->getLeft()) {
        string smallestRight = findSmallest(x->getRight())->getData(); //find the smallest string on the right of x
        Node* smallestRightNode = search(x->getRight(), smallestRight); //find the smallest node on the right of x
        x->setData(smallestRight); //set x's data to that string
        x->setCount(smallestRightNode->getCount()); //set x's count to that node's
        remove(smallestRightNode);
    }
    else {
        string biggestLeft = findLargest(x->getLeft())->getData(); //find the largest string on the left of x
        Node* biggestLeftNode = search(x->getLeft(), biggestLeft); //find the largest node on the left of x
        x->setData(biggestLeft); //set x's data to that string
        x->setCount(biggestLeftNode->getCount()); //set x's count to that node's
        remove(biggestLeftNode);
    }
}

Node* BSTree::findSmallest(Node* x) const {
    if(x == 0) {
        return x;
    }
    
    while(x->getLeft() != 0) {
        x = x->getLeft();
    }
    return x;
}

Node* BSTree::findLargest(Node* x) const {
    if(x == 0) {
        return x;
    }
    
    while(x->getRight() != 0) {
        x = x->getRight();
    }
    return x;
}