#if !defined(BST_H)
#define BST_H

#include <iostream>
#include <string>
#include <queue>

using namespace std;

#include "NodeT.h"

template <typename T>
class BST {
private:
    NodeT<T>* root;

    void printTree(NodeT<T>* node, string prefix, bool isRight, bool isRoot);
    void preOrder(NodeT<T>* node);
    void inOrder(NodeT<T>* node);
    void postOrder(NodeT<T>* node);
    int height(NodeT<T>* node);

public:
    BST() : root(nullptr) {}

    void insert(T data);
    bool find(T data);
    void print();
    void visit(string method);
    void remove(T data);

    int height();
    void ancestors(T data);
    int whatLevelAmI(T data);
};


// INSERT
template <typename T>
void BST<T>::insert(T data) {

    if (root == nullptr) {
        root = new NodeT<T>(data);
        return;
    }

    NodeT<T>* current = root;

    while (true) {

        // Si el dato ya existe, no se vuelve a insertar
        if (data == current->data) {
            return;
        }

        if (data < current->data) {

            if (current->left == nullptr) {
                current->left = new NodeT<T>(data);
                return;
            }

            current = current->left;

        } else {

            if (current->right == nullptr) {
                current->right = new NodeT<T>(data);
                return;
            }

            current = current->right;
        }
    }
}


// FIND
template <typename T>
bool BST<T>::find(T data) {

    NodeT<T>* current = root;

    while (current != nullptr) {

        if (current->data == data) {
            return true;
        }

        if (data < current->data) {
            current = current->left;
        } else {
            current = current->right;
        }
    }

    return false;
}


// REMOVE
template <typename T>
void BST<T>::remove(T data) {

    NodeT<T>* current = root;
    NodeT<T>* parent = nullptr;

    // Buscamos el nodo
    while (current != nullptr && current->data != data) {

        parent = current;

        if (data < current->data) {
            current = current->left;
        } else {
            current = current->right;
        }
    }

    // No se encontró
    if (current == nullptr) {
        cout << "El dato no se encuentra en el BST." << endl;
        return;
    }


    // CASO 1: NO TIENE HIJOS
    if (current->left == nullptr && current->right == nullptr) {

        if (current == root) {
            root = nullptr;
        } else if (parent->left == current) {
            parent->left = nullptr;
        } else {
            parent->right = nullptr;
        }

        delete current;
    }


    // CASO 2: SOLO TIENE HIJO DERECHO
    else if (current->left == nullptr) {

        if (current == root) {
            root = current->right;
        } else if (parent->left == current) {
            parent->left = current->right;
        } else {
            parent->right = current->right;
        }

        delete current;
    }


    // CASO 3: SOLO TIENE HIJO IZQUIERDO
    else if (current->right == nullptr) {

        if (current == root) {
            root = current->left;
        } else if (parent->left == current) {
            parent->left = current->left;
        } else {
            parent->right = current->left;
        }

        delete current;
    }


    // CASO 4: TIENE DOS HIJOS
    else {

        NodeT<T>* successor = current->right;
        NodeT<T>* successorParent = current;

        while (successor->left != nullptr) {
            successorParent = successor;
            successor = successor->left;
        }

        current->data = successor->data;

        if (successorParent->left == successor) {
            successorParent->left = successor->right;
        } else {
            successorParent->right = successor->right;
        }

        delete successor;
    }
}


// PRINT TREE
template <typename T>
void BST<T>::printTree(NodeT<T>* node, string prefix, bool isRight, bool isRoot) {

    if (node == nullptr) {
        return;
    }

    printTree(
        node->right,
        prefix + (isRoot ? "" : (isRight ? "      " : "|     ")),
        true,
        false
    );

    cout << prefix
         << (isRoot ? "" : (isRight ? ".---- " : "`---- "))
         << node->data << endl;

    printTree(
        node->left,
        prefix + (isRoot ? "" : (isRight ? "|     " : "      ")),
        false,
        false
    );
}


// PRINT
template <typename T>
void BST<T>::print() {

    if (root == nullptr) {
        cout << "(arbol vacio)" << endl;
        return;
    }

    printTree(root, "", false, true);
}


// PREORDER
template <typename T>
void BST<T>::preOrder(NodeT<T>* node) {

    if (node != nullptr) {

        cout << node->data << " ";

        preOrder(node->left);
        preOrder(node->right);
    }
}


// INORDER
template <typename T>
void BST<T>::inOrder(NodeT<T>* node) {

    if (node != nullptr) {

        inOrder(node->left);

        cout << node->data << " ";

        inOrder(node->right);
    }
}


// POSTORDER
template <typename T>
void BST<T>::postOrder(NodeT<T>* node) {

    if (node != nullptr) {

        postOrder(node->left);
        postOrder(node->right);

        cout << node->data << " ";
    }
}


// VISIT
template <typename T>
void BST<T>::visit(string method) {

    if (method == "preOrder") {

        cout << "Preorder: ";
        preOrder(root);
        cout << endl;

    } else if (method == "inOrder") {

        cout << "Inorder: ";
        inOrder(root);
        cout << endl;

    } else if (method == "postOrder") {

        cout << "Postorder: ";
        postOrder(root);
        cout << endl;

    } else if (method == "levelByLevel") {

        cout << "Level by level: ";

        if (root == nullptr) {
            cout << endl;
            return;
        }

        queue<NodeT<T>*> fila;

        fila.push(root);

        while (!fila.empty()) {

            NodeT<T>* current = fila.front();
            fila.pop();

            cout << current->data << " ";

            if (current->left != nullptr) {
                fila.push(current->left);
            }

            if (current->right != nullptr) {
                fila.push(current->right);
            }
        }

        cout << endl;

    } else {

        cout << "Metodo de recorrido invalido." << endl;
    }
}


// HEIGHT PRIVADO
template <typename T>
int BST<T>::height(NodeT<T>* node) {

    if (node == nullptr) {
        return 0;
    }

    int leftHeight = height(node->left);
    int rightHeight = height(node->right);

    if (leftHeight > rightHeight) {
        return leftHeight + 1;
    } else {
        return rightHeight + 1;
    }
}


// HEIGHT PUBLICO
template <typename T>
int BST<T>::height() {

    return height(root);
}


// ANCESTORS
template <typename T>
void BST<T>::ancestors(T data) {

    if (root == nullptr) {
        cout << "El BST esta vacio." << endl;
        return;
    }

    if (!find(data)) {
        cout << "El dato no se encuentra en el BST." << endl;
        return;
    }

    if (root->data == data) {
        cout << "La raiz no tiene ancestros." << endl;
        return;
    }

    NodeT<T>* current = root;

    cout << "Ancestros de " << data << ": ";

    while (current != nullptr && current->data != data) {

        cout << current->data << " ";

        if (data < current->data) {
            current = current->left;
        } else {
            current = current->right;
        }
    }

    cout << endl;
}


// WHAT LEVEL AM I
template <typename T>
int BST<T>::whatLevelAmI(T data) {

    NodeT<T>* current = root;
    int level = 0;

    while (current != nullptr) {

        if (current->data == data) {
            return level;
        }

        if (data < current->data) {
            current = current->left;
        } else {
            current = current->right;
        }

        level++;
    }

    return -1;
}


#endif // BST_H