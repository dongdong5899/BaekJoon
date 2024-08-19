#include <iostream>

using namespace std;

struct node
{
    int data = 0;
    node* left;
    node* right;
};

void findNode(node* currentNode, int findNum) 
{
    if (currentNode->data == 0)
    {
        currentNode->data = findNum;
        return;
    }

    if (currentNode->data > findNum)
    {
        if (currentNode->left == nullptr) currentNode->left = new node();
        findNode(currentNode->left, findNum);
    }
    else
    {
        if (currentNode->right == nullptr) currentNode->right = new node();
        findNode(currentNode->right, findNum);
    }
}

void backTree(node* currentNode)
{
    if (currentNode == nullptr) return;
    backTree(currentNode->left);
    backTree(currentNode->right);
    cout << currentNode->data << "\n";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int num;
    node* startNode = new node();
    while (cin >> num)
    {
        findNode(startNode, num);
    }

    backTree(startNode);

    return 0;
}