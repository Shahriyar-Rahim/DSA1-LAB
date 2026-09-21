#include <iostream>
using namespace std;

// Class representing an individual element (Node) in memory
class Node
{
public:
    int data;   // Payload
    Node *next; // Pointer to the next node in heap memory

    // Constructor initializes data and sets next pointer to nullptr
    Node(int val)
    {
        data = val;
        next = nullptr;
    }
};

class SinglyLinkedList
{
private:
    Node *head; // Stores memory address of the 1st node
    Node *tail; // Stores memory address of the last node

public:
    // Constructor initializes an empty list
    SinglyLinkedList()
    {
        head = nullptr;
        tail = nullptr;
    }

    // Destructor to deallocate memory and avoid memory leaks
    ~SinglyLinkedList()
    {
        Node *current = head;
        while (current != nullptr)
        {
            Node *nextNode = current->next;
            delete current;
            current = nextNode;
        }
    }

    // Returns head pointer for node inspection
    Node *getHead() { return head; }

    // Helper method to count total nodes
    int getLength()
    {
        int count = 0;
        Node *curr = head;
        while (curr != nullptr)
        {
            count++;
            curr = curr->next;
        }
        return count;
    }

    // ==========================================
    // 1. TRAVERSAL & DISPLAY
    // ==========================================
    void traverse()
    {
        // Edge Case: Empty List
        if (head == nullptr)
        {
            cout << "\n[List is Empty: nullptr]\n";
            return;
        }

        Node *current = head;
        int nodeIndex = 1;
        cout << "\nCurrent List State:\n";
        cout << "-----------------------------------------------\n";
        while (current != nullptr)
        {
            cout << current->data << " -> ";
            current = current->next;
            nodeIndex++;
        }
        cout << "nullptr\n";
        cout << "-----------------------------------------------\n";
    }

    // ==========================================
    // 2. SEARCH OPERATION
    // ==========================================
    void search(int target)
    {
        if (head == nullptr)
        {
            cout << "Search Failed: List is empty.\n";
            return;
        }

        Node *current = head;
        int position = 1;
        bool found = false;

        while (current != nullptr)
        {
            if (current->data == target)
            {
                cout << "SUCCESS: Found " << target << " at Node Position "
                     << position << " (Memory Address: " << current << ")\n";
                found = true;
                break;
            }
            current = current->next;
            position++;
        }

        if (!found)
        {
            cout << "NOT FOUND: Value " << target << " does not exist in the list.\n";
        }
    }

    // ==========================================
    // 3. INSERTION OPERATIONS
    // ==========================================

    // Variant A: Insert at Beginning (Head)
    void insertAtBeginning(int val)
    {
        Node *newNode = new Node(val);

        // Edge Case: Empty List
        if (head == nullptr)
        {
            head = tail = newNode;
            cout << "Inserted " << val << " as the FIRST & ONLY Node at address: " << newNode << "\n";
            return;
        }

        // Standard Case: Wire new node behind head
        newNode->next = head;
        head = newNode;
        cout << "Inserted " << val << " at Node Position 1 (New Head) at address: " << newNode << "\n";
    }

    // Variant B: Insert at End (Tail)
    void insertAtEnd(int val)
    {
        Node *newNode = new Node(val);

        // Edge Case: Empty List
        if (head == nullptr)
        {
            head = tail = newNode;
            cout << "Inserted " << val << " as the FIRST & ONLY Node at address: " << newNode << "\n";
            return;
        }

        // Standard Case: Wire new node after tail
        tail->next = newNode;
        tail = newNode;
        cout << "Inserted " << val << " at Node Position " << getLength()
             << " (New Tail) at address: " << newNode << "\n";
    }

    // Variant C: Insert After Given Node Value
    void insertAfterValue(int targetVal, int val)
    {
        if (head == nullptr)
        {
            cout << "Operation Failed: List is empty.\n";
            return;
        }

        Node *current = head;
        int pos = 1;
        while (current != nullptr && current->data != targetVal)
        {
            current = current->next;
            pos++;
        }

        // Edge Case: Target value not found
        if (current == nullptr)
        {
            cout << "Operation Failed: Target value " << targetVal << " not found in list.\n";
            return;
        }

        // Edge Case: Target is the Tail Node
        if (current == tail)
        {
            insertAtEnd(val);
            return;
        }

        // Standard Case: Wire node in middle
        Node *newNode = new Node(val);
        newNode->next = current->next;
        current->next = newNode;
        cout << "Inserted " << val << " immediately AFTER Node " << pos
             << " (Value: " << targetVal << ") at address: " << newNode << "\n";
    }

    // Variant D: Insert Before Given Node Value
    void insertBeforeValue(int targetVal, int val)
    {
        if (head == nullptr)
        {
            cout << "Operation Failed: List is empty.\n";
            return;
        }

        // Edge Case: Target is Head Node
        if (head->data == targetVal)
        {
            insertAtBeginning(val);
            return;
        }

        Node *prev = nullptr;
        Node *current = head;
        int pos = 1;

        while (current != nullptr && current->data != targetVal)
        {
            prev = current;
            current = current->next;
            pos++;
        }

        // Edge Case: Target not found
        if (current == nullptr)
        {
            cout << "Operation Failed: Target value " << targetVal << " not found in list.\n";
            return;
        }

        // Standard Case: Wire node before current
        Node *newNode = new Node(val);
        newNode->next = current;
        prev->next = newNode;
        cout << "Inserted " << val << " immediately BEFORE Node " << pos
             << " (Value: " << targetVal << ") at address: " << newNode << "\n";
    }

    // Variant E: Insert from Any Position (1-Based Indexing)
    void insertAtPosition(int pos, int val)
    {
        int totalNodes = getLength();

        if (pos < 1 || pos > totalNodes + 1)
        {
            cout << "Invalid Position! Valid range is 1 to " << (totalNodes + 1) << "\n";
            return;
        }

        if (pos == 1)
        {
            insertAtBeginning(val);
            return;
        }

        if (pos == totalNodes + 1)
        {
            insertAtEnd(val);
            return;
        }

        Node *current = head;
        for (int i = 1; i < pos - 1; ++i)
        {
            current = current->next;
        }

        Node *newNode = new Node(val);
        newNode->next = current->next;
        current->next = newNode;
        cout << "Inserted " << val << " at Node Position " << pos
             << " at address: " << newNode << "\n";
    }

    // ==========================================
    // 4. DELETION OPERATIONS
    // ==========================================

    // Variant A: Delete First Node (Head)
    void deleteFirst()
    {
        // Edge Case 1: Empty List
        if (head == nullptr)
        {
            cout << "Deletion Failed: List is empty.\n";
            return;
        }

        Node *temp = head;

        // Edge Case 2: Single Node in List
        if (head == tail)
        {
            head = tail = nullptr;
            cout << "Deleted ONLY Node (Value: " << temp->data << ") from list.\n";
            delete temp;
            return;
        }

        head = head->next;
        cout << "Deleted Head Node (Value: " << temp->data << "). New Head is now at: " << head << "\n";
        delete temp;
    }

    // Variant B: Delete Last Node (Tail)
    void deleteLast()
    {
        if (head == nullptr)
        {
            cout << "Deletion Failed: List is empty.\n";
            return;
        }

        // Edge Case: Single Node List
        if (head == tail)
        {
            deleteFirst();
            return;
        }

        Node *current = head;
        while (current->next != tail)
        {
            current = current->next;
        }

        Node *temp = tail;
        tail = current;
        tail->next = nullptr;
        cout << "Deleted Tail Node (Value: " << temp->data << "). New Tail is now at: " << tail << "\n";
        delete temp;
    }

    // Variant C: Delete After Given Node Value
    void deleteAfterValue(int targetVal)
    {
        if (head == nullptr)
        {
            cout << "Deletion Failed: List is empty.\n";
            return;
        }

        Node *current = head;
        while (current != nullptr && current->data != targetVal)
        {
            current = current->next;
        }

        if (current == nullptr)
        {
            cout << "Deletion Failed: Target value " << targetVal << " not found.\n";
            return;
        }

        // Edge Case: Target is Tail (No node exists after tail)
        if (current == tail || current->next == nullptr)
        {
            cout << "Deletion Failed: No node exists AFTER Node with value " << targetVal << "\n";
            return;
        }

        Node *temp = current->next;

        // Edge Case: Deleting the Tail node
        if (temp == tail)
        {
            tail = current;
            tail->next = nullptr;
        }
        else
        {
            current->next = temp->next;
        }

        cout << "Deleted Node (Value: " << temp->data << ") which was located after value " << targetVal << "\n";
        delete temp;
    }

    // Variant D: Delete from Any Position / Value
    void deleteByValue(int val)
    {
        if (head == nullptr)
        {
            cout << "Deletion Failed: List is empty.\n";
            return;
        }

        // Edge Case: Target is Head Node
        if (head->data == val)
        {
            deleteFirst();
            return;
        }

        Node *prev = nullptr;
        Node *current = head;

        while (current != nullptr && current->data != val)
        {
            prev = current;
            current = current->next;
        }

        if (current == nullptr)
        {
            cout << "Deletion Failed: Value " << val << " not found in list.\n";
            return;
        }

        // Edge Case: Target is Tail Node
        if (current == tail)
        {
            tail = prev;
            tail->next = nullptr;
            cout << "Deleted Tail Node (Value: " << val << ")\n";
            delete current;
            return;
        }

        // Standard Case: Bypass middle node
        prev->next = current->next;
        cout << "Deleted Node (Value: " << val << ") from list.\n";
        delete current;
    }

    // ==========================================
    // 5. IN-PLACE REVERSAL ALGORITHM
    // ==========================================
    void reverse()
    {
        // Edge Case: Empty list or single node requires no pointer modification
        if (head == nullptr || head->next == nullptr)
        {
            cout << "Reversal Complete: List has 0 or 1 element, no changes made.\n";
            return;
        }

        Node *prev = nullptr;
        Node *current = head;
        Node *nextNode = nullptr;

        // Old Head becomes New Tail
        tail = head;

        while (current != nullptr)
        {
            nextNode = current->next; // 1. Save reference to next node
            current->next = prev;     // 2. Reverse link direction
            prev = current;           // 3. Advance prev pointer
            current = nextNode;       // 4. Advance current pointer
        }

        // Update head to point to new first node
        head = prev;
        cout << "SUCCESS: List reversed in-place successfully!\n";
    }
};

int main()
{
    SinglyLinkedList list;
    int choice, val, target, pos;

    cout << "=====================================================\n";
    cout << "  INTERACTIVE SINGLY LINKED LIST SIMULATOR ENGINE   \n";
    cout << "=====================================================\n";

    // Initial List Creation via User Input
    int initialCount;
    cout << "How many initial nodes do you want to create? ";
    cin >> initialCount;

    for (int i = 1; i <= initialCount; ++i)
    {
        cout << "Enter value for Node " << i << ": ";
        cin >> val;
        list.insertAtEnd(val);
    }

    list.traverse();

    // Menu Driven Command Loop
    do
    {
        cout << "\n------------------- MENU OPERATIONS -------------------\n";
        cout << "1. Display / Traverse List\n";
        cout << "2. Search for Value\n";
        cout << "3. Insert at Beginning\n";
        cout << "4. Insert at End\n";
        cout << "5. Insert Before Given Value\n";
        cout << "6. Insert After Given Value\n";
        cout << "7. Insert at Specific Position\n";
        cout << "8. Delete First Node\n";
        cout << "9. Delete Last Node\n";
        cout << "10. Delete After Given Value\n";
        cout << "11. Delete Specific Value\n";
        cout << "12. Reverse List In-Place\n";
        cout << "13. Exit\n";
        cout << "Enter your choice (1-13): ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            list.traverse();
            break;
        case 2:
            cout << "Enter target value to search: ";
            cin >> target;
            list.search(target);
            break;
        case 3:
            cout << "Enter value to insert at beginning: ";
            cin >> val;
            list.insertAtBeginning(val);
            list.traverse();
            break;
        case 4:
            cout << "Enter value to insert at end: ";
            cin >> val;
            list.insertAtEnd(val);
            list.traverse();
            break;
        case 5:
            cout << "Enter target value: ";
            cin >> target;
            cout << "Enter new value to insert BEFORE " << target << ": ";
            cin >> val;
            list.insertBeforeValue(target, val);
            list.traverse();
            break;
        case 6:
            cout << "Enter target value: ";
            cin >> target;
            cout << "Enter new value to insert AFTER " << target << ": ";
            cin >> val;
            list.insertAfterValue(target, val);
            list.traverse();
            break;
        case 7:
            cout << "Enter position index (1-based): ";
            cin >> pos;
            cout << "Enter value to insert at position " << pos << ": ";
            cin >> val;
            list.insertAtPosition(pos, val);
            list.traverse();
            break;
        case 8:
            list.deleteFirst();
            list.traverse();
            break;
        case 9:
            list.deleteLast();
            list.traverse();
            break;
        case 10:
            cout << "Enter target value: ";
            cin >> target;
            list.deleteAfterValue(target);
            list.traverse();
            break;
        case 11:
            cout << "Enter value to delete: ";
            cin >> val;
            list.deleteByValue(val);
            list.traverse();
            break;
        case 12:
            list.reverse();
            list.traverse();
            break;
        case 13:
            cout << "\nExiting Program. Deallocating memory...\n";
            break;
        default:
            cout << "Invalid choice! Please select between 1 and 13.\n";
        }
    } while (choice != 13);

    return 0;
}