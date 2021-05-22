////////////////////////////////////////////////////////////////////////
// Lab8 : Tree Build, Traverse & Evaluation
// Name : ±Ë¿ÁπŒ
// ID : 20181592
/////////////////////////////////////////////////////////////////////////
#include <iostream>
#include <cstring>
using namespace std;

class Node {
private:
    char data;
    int priority;
    Node* left;
    Node* right;

public:
    Node(int value) : data(value),
        priority(4), left(0), right(0) {}
    friend class Tree;
};

class Tree {
public:
    Node* root;
    Tree() { root = 0; };
    ~Tree() {}
    void insert(char data);
    void buildTree(string expression);
    void inOrder(Node* node);
    void postOrder(Node* node);
    void preOrder(Node* node);
    void Operand(Node* node);
    void Operator(Node* node);
    int evalTree(Node* p);
    void PrintTree(Node* P, int level);
};

char prec[4][2] = { {'*', 2}, {'/', 2}, {'+', 1}, {'-', 1} };

void Tree::insert(char data) {
    Node* p = new Node(data);
    int i;
    for (i = 0; i < 4; i++)
    {
        if (p->data == prec[i][0])
        {
            p->priority = prec[i][1];
            break;
        }
    }
    if (i == 4) Operand(p);
    else Operator(p);
}

void Tree::buildTree(string expression) {
    int i = 0;
    while (expression[i] != '\0') {
        insert(expression[i]);
        i++;
    }
}

void Tree::inOrder(Node* node) {
    if (node) {
        inOrder(node->left);
        cout << node->data << " ";
        inOrder(node->right);
    }
}
void Tree::postOrder(Node* node) {
    if (node) {
        postOrder(node->left);
        postOrder(node->right);
        cout << node->data << " ";
    }
}
void Tree::preOrder(Node* node) {
    if (node) {
        cout << node->data << " ";
        preOrder(node->left);
        preOrder(node->right);
    }
}

void Tree::Operand(Node* node) {
    if (root == NULL) {
        root = node;
        return;
    }
    Node* p = root;
    while (p->right != NULL) {
        p = p->right;
    }
    p->right = node;
}
void Tree::Operator(Node* node) {
    if (root->priority >= node->priority) {
        node->left = root;
        root = node;
    }
    else {
        node->left = root->right;
        root->right = node;
    }
}

int Tree::evalTree(Node* p) {
    int value;
    int left;
    int right;
    if (p != NULL) {
        for (int i = 0; i < 10; i++) {
            if (i == (int)p->data - '0')
                value = (int)p->data - '0';
            else {
                left = evalTree(p->left);
                right = evalTree(p->right);

                switch (p->data) {
                case '+':
                    value = left + right;
                    break;
                case '-':
                    value = left - right;
                    break;
                case '*':
                    value = left * right;
                    break;
                case '/':
                    value = left / right;
                    break;
                }
            }
        }
        return value;
    }
}

void Tree::PrintTree(Node* P, int level) {
    int j = 1;
    if (P != NULL) {
        PrintTree(P->right, level + 1); //Space over (skip levels)
        while (j++ < level)
            cout << "    "; // Print data
        cout << P->data;

        if (P->left != 0 && P->right != 0)
            cout << " <"; //two child
        else if (P->right != 0)
            cout << " /"; //only right child
        else if (P->left != 0)
            cout << " \\"; //only left child
        cout << endl;

        PrintTree(P->left, level + 1);
    }
}

int main() {
    string exp1 = "8+9-2*3";
    Tree tree;
    tree.buildTree(exp1);
    cout << "1. Infix Expression1 : 8+9-2*3" << endl << endl;
    cout << "Inorder : ";
    tree.inOrder(tree.root);
    cout << endl;
    cout << "Postorder : ";
    tree.postOrder(tree.root);
    cout << endl;
    cout << "Preorder : ";
    tree.preOrder(tree.root);
    cout << endl;
    cout << "Evaluation : " << tree.evalTree(tree.root);
    cout << endl;
    tree.PrintTree(tree.root, exp1.length());
    cout << endl;

    string exp2 = "A/B*C*D+E";
    Tree tree2;
    tree2.buildTree(exp2);
    cout << "2. Infix Expression1 : A/B*C*D+E" << endl << endl;
    cout << "Inorder : ";
    tree2.inOrder(tree2.root);
    cout << endl;
    cout << "Postorder : ";
    tree2.postOrder(tree2.root);
    cout << endl;
    cout << "Preorder : ";
    tree2.preOrder(tree2.root);
    cout << endl;
    tree2.PrintTree(tree2.root, exp2.length());
    return 0;
}