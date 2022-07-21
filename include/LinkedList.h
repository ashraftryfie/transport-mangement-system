#ifndef LINKEDLIST_H
#define LINKEDLIST_H



/*---------------------------- Linked List ----------------------------*/
template<class T>
class LinkedList
{
    struct Node
    {
        T *item;
        Node *next;
    };
    Node *head, *tail;
    int length;
public:
    LinkedList()
    {
        head = tail = NULL;
        length = 0;
    }
    bool isEmpty()
    {
        return length == 0; //or: head == NULL
    }

    void insertLast(T *element,long long id=0)
    {
        Node *newNode = new Node;
        newNode->item = element;
        element->SetData(id);
        if (isEmpty())  //or: head == NULL
        {
            head = tail = newNode;
            newNode->next = NULL;
        }
        else
        {
            tail->next = newNode;
            newNode->next = NULL;
            tail = newNode;
        }
        length++;
    }

    void Read(T *element)
    {
        Node *newNode = new Node;
        newNode->item = element;
        if (isEmpty())  //or: head == NULL
        {
            head = tail = newNode;
            newNode->next = NULL;
        }
        else
        {
            tail->next = newNode;
            newNode->next = NULL;
            tail = newNode;
        }
        length++;
    }

    void print()
    {
        if (isEmpty())
            cout << "List is Empty..!";
        Node *Cur = head;
        cout << "\nfrom the Linked List:" << endl;
        while (Cur != NULL)
        {
            Cur->item->print();
            Cur = Cur->next;
        }
    }

    void Search(long long id)
    {
        bool found = false;
        if (isEmpty())
            cout << "List is Empty..!";
        Node *Cur = head;
        cout << "from the Linked List:" << endl;
        while (Cur != NULL )
        {
            if (id == Cur->item->get_number())
            {
                found = true;
                cout << Cur->item->get_type() << endl;
            }
            Cur = Cur->next;
        }

        if (found == false)
            cout << "\nNot found..!!!" << endl;
    }


    void Search(long long id,char *to, char *from)
    {
        bool found = false;
        if (isEmpty())
            cout << "List is Empty..!";

        Node *Cur = head;
        cout << "from the Linked List:" << endl;
        while (Cur != NULL)
        {
            if (id == Cur->item->get_number())
            {
                if(strcmp(from, Cur->item->get_from())==0 && strcmp(to, Cur->item->get_to())==0){
                    cout << Cur->item->get_FlightNum() << endl;
                    found = true;
                }
            }
            Cur = Cur->next;
        }
        if (found == false)
            cout << "\nNot found..!!!" << endl;

    }

    void  Print_journy_data(long long id)
    {
        bool found = false;
        if (isEmpty())
            cout << "List is Empty..!";
        Node *Cur = head;
        cout << "from the Linked List:" << endl;
        while (Cur != NULL )
        {
            if (id == Cur->item->get_number())
            {
                found = true;
                Cur->item->print();
            }
            Cur = Cur->next;
        }
        if (found == false)
            cout << "\nNot found..!!!" << endl;
    }

    bool check_id(long long id)
    {
        bool found = false;
        Node *Cur = head;
        while (Cur != NULL )
        {
            if (id == Cur->item->get_number())
            {
                found = true;
            }
            Cur = Cur->next;
        }
        return found;
    }

};

#endif // LINKEDLIST_H
