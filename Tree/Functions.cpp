#include <conio.h>
#include <iostream>

#include "Functions.h"

using namespace std;

void Insert(Tree& tree)
{
    system("chcp 1251>nul");
    system("cls");

    cout << "Enter a quantity of elements to add: ";

    unsigned int count = 0U;
    cin >> count;

    for (unsigned int i = 0U; i < count; ++i)
    {
        Node* temp = new Node;

        cout << endl << "Enter an english word " << i + 1 << endl;
        cin >> temp->GetEnglish();

        cout << endl << "Enter a russian word " << i + 1 << endl;
        cin >> temp->GetRussian();

        tree.Insert(temp);
    }
}

void Print(const Tree& tree)
{
    system("cls");

    tree.Print(tree.GetRoot());

    _getch();
}

void PrintMenu()
{
    char menu[] = "1. Insert node\n2. Remove node\n3. Print node\n4. Search node\n5. Edit\n6. Add to file\n7. Exit\n";

    system("cls");

    cout << menu;
}

void Remove(Tree& tree)
{
    system("cls");
    cout << "Enter an english word to remove:" << endl;

    char buffer[15] = {};
    cin >> buffer;

    Node* node = tree.Search(tree.GetRoot(), buffer);

    tree.Remove(node);
}

void Search(const Tree& tree)
{
    system("chcp 1251>nul");
    system("cls");

    cout << "Enter an english word to search:" << endl;

    char buffer[15] = {};
    cin >> buffer;

    Node* node = tree.Search(tree.GetRoot(), buffer);

    if (node != nullptr)
    {
        cout << node->GetRussian();
    }
    else
    {
        cout << "Word not found" << endl;
    }

    _getch();
}

void Edit(Tree& tree) {
    system("chcp 1251>nul");
    system("cls");

    cout << "Enter an english word to edit:" << endl;

    char buff1[15] = {};
    cin >> buff1;

    Node* node = tree.Search(tree.GetRoot(), buff1);

    if (node != nullptr)
    {
        cout << "\nEnter new translation:" << endl;
        char buff2[15] = {};
        cin >> buff2;
        node->SetEnglish(buff2);
        Print(tree);
    }
    else
    {
        cout << "Word not found" << endl;
    }
    _getch();
}

void AddFile(const Tree& tree) {
    FILE* fp;
    fopen_s(&fp, "translation.txt", "w");

    if (fp == nullptr)
        cout << "EROR" << endl;
    else {

        tree.AddFile(tree.GetRoot(), fp);
        fclose(fp);
    }
}