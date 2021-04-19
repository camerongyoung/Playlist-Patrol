#include <iostream>
#include <string>
#include <vector>
#include <sstream>
using namespace std;
class Node {
public:
    int score;

    Node *left;
    Node *right;

    Node(){
        score = 0;
        left = NULL;
        right = NULL;
    };
    Node(int _score){
        score = _score;
        left = NULL;
        right = NULL;
    };
    Node(int _score, Node* _left, Node* _right){
        score = _score;
        left = _left;
        right = _right;
    };
};

class Tree {
private:
    int index = 0;
public:
    Node* insert(Node* root, int score);
    Node* successor(Node* root);
    Node* deleteScore(Node* root, int score);
    Node* findMaxScore(Node* root);
};

Node* Tree::insert(Node* root, int score) {

    if(root == NULL){
        return new Node(score);
    }

    if(score < root->score){
        root->left = insert(root->left, score);
    }
    else{
        root->right = insert(root->right, score);
    }

    return root;
}

Node* Tree::successor(Node* root) {
    if(root==NULL){
        return NULL;
    }
    Node* node = root;
    while(node->left != NULL){
        node = node->left;
    }
    return node;
}

Node* Tree::deleteScore(Node* root, int score) {
    if(root == NULL){
        return root;
    }

    if(score < root->score ){
        root->left = deleteScore(root->left, score);
    }

    else if(score > root->score){
        root->right = deleteScore(root->right, score);
    }

    else{
        if(root->left == NULL && root->right == NULL) {
            Node* node = nullptr;
            return node;
        }
        if(root->left == NULL){
            Node* node = root->right;
            delete root;
            return node;
        }
        if(root->right == NULL){
            Node* node = root->left;
            delete root;
            return node;
        }
        Node* temp = successor(root->right);
        root->score = temp->score;
        root->right = deleteScore(root->right, temp->score);
    }
    return root;
}

Node* Tree::findMaxScore(Node* root){

    if(root == NULL){
        return NULL;
    }
    else{
        findMaxScore(root->right);
        if(index++ < 10){
            cout << root->score << " ";
        }
        findMaxScore(root->left);
    }
}

int main() {
    Tree tree;
    Node* root = NULL;
    int index = 0;

    root = tree.insert(root, 9);
    root = tree.insert(root, 6);
    root = tree.insert(root, 10);
    root = tree.insert(root, 47);
    root = tree.insert(root, 65);
    root = tree.insert(root, 30);
    root = tree.insert(root, 8);
    root = tree.insert(root, 1);
    root = tree.insert(root, 8);
    root = tree.insert(root, 17);
    root = tree.insert(root, 29);
    root = tree.insert(root, 38);
    root = tree.insert(root, 4);

    tree.findMaxScore(root);



    return 0;
}


