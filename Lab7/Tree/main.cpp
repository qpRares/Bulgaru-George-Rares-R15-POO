#include <iostream>
#include "Tree.h"

using namespace std;

bool compareEqual(int a, int b)
{
    return a == b;
}

bool compareAscending(int a, int b)
{
    return a > b;
}

int main()
{
    Tree<int> tree;

    tree.add_node(nullptr, 10);

    tree.add_node(tree.root, 5);
    tree.add_node(tree.root, 20);
    tree.add_node(tree.root, 15);

    cout << "Children before insert:\n";
    for(int i = 0; i < tree.root->count; i++)
        cout << tree.root->next[i]->info << " ";
    cout << endl;

    tree.insert(tree.root, 1, 7);

    cout << "After insert at index 1:\n";
    for(int i = 0; i < tree.root->count; i++)
        cout << tree.root->next[i]->info << " ";
    cout << endl;

    Tree<int>::node* found =
        tree.find(tree.root, 15, compareEqual);

    if(found != nullptr)
        cout << "Found node with value: " << found->info << endl;
    else
        cout << "Value not found\n";

    cout << "Total nodes in tree: "
         << tree.count(tree.root) << endl;

    tree.sort(tree.root, nullptr);

    cout << "After default sort:\n";
    for(int i = 0; i < tree.root->count; i++)
        cout << tree.root->next[i]->info << " ";
    cout << endl;

    tree.sort(tree.root, compareAscending);

    cout << "After callback sort:\n";
    for(int i = 0; i < tree.root->count; i++)
        cout << tree.root->next[i]->info << " ";
    cout << endl;

    tree.delete_node(tree.root);

    return 0;
}
