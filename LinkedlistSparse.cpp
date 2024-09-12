#include <iostream>
using namespace std;

struct Node
{
    int row, col, value;
    Node* next;
};

class SparseMatrixLinkedList 
{
public:
    Node* head;

    SparseMatrixLinkedList()
    {
        head = nullptr;
    }

    void insert(int row, int col, int value)
    {
        Node* newNode = new Node();
        newNode->row = row;
        newNode->col = col;
        newNode->value = value;
        newNode->next = nullptr;

        if (head == nullptr)
        {
            head = newNode;
        } else 
        {
            Node* temp = head;
            while (temp->next != nullptr) 
            {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }

    void display() 
    {
        Node* temp = head;
        cout << "Row\tColumn\tValue\n";
        while (temp != nullptr) 
        {
            cout << temp->row << "\t" << temp->col << "\t" << temp->value << endl;
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
};

int main() 
{

    int m = 4, n = 5;
    int matrix[4][5] = {
        {0, 0, 3, 0, 4},
        {0, 0, 5, 7, 0},
        {0, 0, 0, 0, 0},
        {0, 2, 6, 0, 0}
    };
    SparseMatrixLinkedList sparseMatrix;

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (matrix[i][j] != 0) {
                sparseMatrix.insert(i, j, matrix[i][j]);
            }
        }
    }
    sparseMatrix.display();

    return 0;
}















