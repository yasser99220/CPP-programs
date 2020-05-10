#include <iostream>
using namespace std;
struct node
{
    int data;
    struct node *next;
};

int main()
{
    cout << "Welcome to Linked List" << endl;
    struct node *head = nullptr;
    while (1)
    {
        int choice = 0;
        cout << "1-add node at beginning\n2-exit\n3-print complete list\n4-add at the end\n5-Print perticular node\n6-Delete front Node\n7-Delete last node\n8-count nodes" << endl;
        cin >> choice;
        switch (choice)
        {
        case 8:
        {
            int count = 1;
            struct node *ptr = head;
            if (head == nullptr)
            {
                cout << "total nodes " << 0 << endl;
                break;
            }

            while (ptr->next)
            {
                count++;
                ptr = ptr->next;
            }
            cout << "total nodes " << count << endl;
            break;
        }
        case 7:
        {

            if (head == NULL)
            {
                cout << "Empty list" << endl;
                break;
            }
            if (head->next == nullptr)
            {
                delete head;
                head = nullptr;
                break;
            }

            auto traversalNode = head;
            auto prevNode = head;
            while (traversalNode->next)
            {
                prevNode = traversalNode;
                traversalNode = traversalNode->next;
            }
            delete traversalNode;
            prevNode->next = nullptr;
            break;
        }
        case 5:
        {
            int pos;
            cout << "Enter the Position of node to print" << endl;
            cin >> pos;
            int posCopy = pos;
            auto traversalNode = head;
            if (head == NULL)
            {
                cout << "empty List" << endl;
                break;
            }
            bool invalid = false;

            for (int i = 1; i < pos; ++i, traversalNode = traversalNode->next)
            {
                if (traversalNode->next == NULL)
                {
                    cout << "invalid Position" << endl;
                    invalid = true;
                    break;
                }
            }
            if (!invalid)
                cout << "data at " << posCopy << " is " << traversalNode->data << endl;
            break;
        }
        case 6:
        {
            if (head == NULL)
            {
                cout << "Empty list" << endl;
                break;
            }
            auto ptr = head;
            head = head->next;
            delete ptr;
            cout << "Head Node deleted" << endl;
            break;
        }
        case 1:
        {
            int data;
            cout << "enter data " << endl;
            cin >> data;
            if (head == nullptr)
            {
                struct node *ptr = new node;
                ptr->next = nullptr;
                ptr->data = data;
                head = ptr;
            }
            else
            {
                struct node *ptr = new node;
                ptr->data = data;
                ptr->next = head;
                head = ptr;
            }
            break;
        }
        case 4:
        {
            int data;
            cout << "enter Data to be added at the end" << endl;
            cin >> data;
            if (head == nullptr)
            {
                struct node *ptr = new node;
                ptr->next = nullptr;
                ptr->data = data;
                head = ptr;
            }
            else
            {
                auto traversalNode = head;
                while (traversalNode->next)
                {
                    traversalNode = traversalNode->next;
                }
                auto ptr = new node;
                ptr->data = data;
                ptr->next = nullptr;
                traversalNode->next = ptr;
            }
            break;
        }
        case 3:
        {
            if (!head)
            {
                cout << "Empty List" << endl;
                break;
            }

            cout << "The Entered data " << endl;
            struct node *traversalptr = head;

            while (traversalptr)
            {
                cout << traversalptr->data << endl;
                traversalptr = traversalptr->next;
            }
            break;
        }
        case 2:
        {
            return EXIT_SUCCESS;
        }
        default:
            return EXIT_SUCCESS;
        }
    }
    return EXIT_SUCCESS;
}