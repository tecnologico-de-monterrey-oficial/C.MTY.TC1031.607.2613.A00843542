#ifndef BSTIP_h
#define BSTIP_h

#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct NodeIP {

    unsigned int ip;
    string ipTexto;
    int count;

    NodeIP* left;
    NodeIP* right;

    NodeIP(unsigned int value, string texto) {

        ip = value;
        ipTexto = texto;
        count = 1;

        left = nullptr;
        right = nullptr;
    }
};


class BSTIP {

private:

    NodeIP* root;
    int nodeCount;

    int height(NodeIP* node) const {

        if (node == nullptr) {
            return 0;
        }

        int leftHeight = height(node->left);
        int rightHeight = height(node->right);

        if (leftHeight > rightHeight) {
            return leftHeight + 1;
        }

        return rightHeight + 1;
    }


    void inorder(NodeIP* node, vector<NodeIP*>& result) const {

        if (node == nullptr) {
            return;
        }

        inorder(node->left, result);

        result.push_back(node);

        inorder(node->right, result);
    }


    void deleteTree(NodeIP* node) {

        if (node == nullptr) {
            return;
        }

        deleteTree(node->left);
        deleteTree(node->right);

        delete node;
    }


public:

    BSTIP() {

        root = nullptr;
        nodeCount = 0;
    }


    ~BSTIP() {

        deleteTree(root);
    }


    void insert(unsigned int ip, string ipTexto) {

        if (root == nullptr) {

            root = new NodeIP(ip, ipTexto);
            nodeCount++;

            return;
        }

        NodeIP* current = root;

        while (true) {

            if (ip == current->ip) {

                current->count++;
                return;
            }

            if (ip < current->ip) {

                if (current->left == nullptr) {

                    current->left = new NodeIP(ip, ipTexto);
                    nodeCount++;

                    return;
                }

                current = current->left;

            } else {

                if (current->right == nullptr) {

                    current->right = new NodeIP(ip, ipTexto);
                    nodeCount++;

                    return;
                }

                current = current->right;
            }
        }
    }


    int search(unsigned int ip, int& comparisons) const {

        comparisons = 0;

        NodeIP* current = root;

        while (current != nullptr) {

            comparisons++;

            if (ip == current->ip) {
                return current->count;
            }

            if (ip < current->ip) {
                current = current->left;
            } else {
                current = current->right;
            }
        }

        return 0;
    }


    int size() const {

        return nodeCount;
    }


    int height() const {

        return height(root);
    }


    vector<NodeIP*> getInorder() const {

        vector<NodeIP*> result;

        inorder(root, result);

        return result;
    }
};

#endif