#include <iostream>

using namespace std;

//Creating a blueprint for node
class Node {
  public: int listValue;
  Node * previous;
  Node * next;
};

//Creating a blueprint for double linked list
class DoubleLinkedList {
  public: Node * start;                                                                                                  //A
                                                                                                                         //B
  public:                                                                                                                //I
    //constructor                                                                                                        //N
    DoubleLinkedList() {                                                                                                 //A
      start = NULL;                                                                                                      //Y
    }                                                                                                                    //A
                                                                                                                         //N
  //Function for inserting a node at the beginning of the list
  void insertBeg(int value) {
    Node * newPtr = new Node;
    newPtr -> listValue = value;

    //checking whether there is no nodes in the list and if not, assigning the new node as first element
    //if there is already nodes in the linked list, then add the new node at the beginning
    if (start == NULL) {
      start = newPtr;
      start -> next = NULL;
      start -> previous = NULL;
    } else {
      newPtr -> next = start;
      newPtr -> previous = NULL;
      start -> previous = newPtr;
      start = newPtr;
    }
  };

  //Function for inserting a node at the beginning of the list
  void insertEnd() {
    int value;
    cout << "Please type the value you want to insert : ";
    cin >> value;
    cout << endl;
    Node * newPtr = new Node;
    Node * temp = new Node;
    temp = start;
    newPtr -> listValue = value;
    if (start == NULL) {
      start = newPtr;
      start -> next = NULL;
      start -> previous = NULL;
    } else {
      start = temp;
      while (temp -> next != NULL) {
        temp = temp -> next;
      }
      newPtr -> next = NULL;
      newPtr -> previous = temp;
      temp -> next = newPtr;

    }

  };

  //Function for deleting a node at the beginning of the list
  void deleteBeg() {
    if (start == NULL) {
      cout << "Please add something in the list before deleting " << endl;
    } else {
      Node * temp = new Node;
      temp = start;
      if (temp -> next != NULL) {
        start = temp -> next;
        temp -> next -> previous = NULL;
        delete temp;

      } else {
        delete temp;
        start = NULL;
      }
      cout << "Deleted successfully " << endl;

    }

  };

  //Function for deleting a node at the end of the list
  void deleteEnd() {
    if (start == NULL) {
      cout << "Please add something in the list before deleting " << endl;
    } else {
      if (start -> next != NULL) {
        Node * temp = new Node;
        Node * before_temp = new Node;
        temp = start -> next;
        before_temp = start;
        while (temp -> next != NULL) {
          temp = temp -> next;
          before_temp = before_temp -> next;
        }
        before_temp -> next = NULL;
        delete temp;
      } else {
        Node * temp = new Node;
        temp = start;
        delete temp;
        start = NULL;
      }

      cout << "Deleted successfully " << endl;
    }

  };

  //Function for deleting a node with certain value at the list
  void deleteNode(int D) {
    bool isItemAvailable;
    Node * temp1 = new Node;
    Node * temp2 = new Node;
    temp1 = start;
    if (start == NULL) {
      cout << "Please add something in the list before deleting " << endl;
    } else {

      while (temp1 != NULL) {
        if (temp1 -> listValue == D) {
          //Deleting the first node
          if (temp1 == start) {
            if (temp1 -> next != NULL) {
              temp1 -> next -> previous = NULL;
              start = temp1 -> next;
              delete temp1;
              cout << "Item Deleted Successfully." << endl;
              isItemAvailable = true;
              return;
            } else {
              delete temp1;
              start = NULL;
              isItemAvailable = true;
              cout << "Item Deleted Successfully." << endl;
              return;
            }
          }
          //Deleting the last node
          else if (temp1 -> next == NULL) {
            temp1 -> previous -> next = NULL;
            delete temp1;
            cout << "Item Deleted Successfully." << endl;
            isItemAvailable = true;
            return;
          }
          //Deleting the node other than first and last
          else {
            temp2 = temp1;
            temp2 -> previous -> next = temp2 -> next;
            temp2 -> next -> previous = temp2 -> previous;
            delete temp2;
            cout << "Item Deleted Successfully." << endl;
            isItemAvailable = true;
            return;
          }

        }
        temp1 = temp1 -> next;
      }

    }

    //Output a message if the value is not available.
    if (isItemAvailable == false) {
      cout << "Value not found in the list. " << endl;
    }

  };

  //Function to print the values in the linked list
  void print() {
    if (start == NULL) {
      cout << "Please add something first !" << endl;

    } else {
      cout << "The following values are in the list : ";
      Node * temp = new Node;
      temp = start;
      while (temp != NULL) {
        cout << temp -> listValue << " ";
        temp = temp -> next;
      }
      cout << endl << endl;
    }

  };

  //function for searching a node with certain value
  Node * search(int F) {
    bool isItemAvailable;
    int number = 0;
    Node * temp1 = new Node;
    temp1 = start;
    if (start == NULL) {
      cout << "Please add something in the list before deleting " << endl;
    } else {

      while (temp1 != NULL) {
        number++;
        if (temp1 -> listValue == F) {

          if (temp1 == start) {
            cout << "The node with value " << F << " is the first node of the list" << endl;
            isItemAvailable = true;
            cout << "memory location : " << temp1 << endl;
            return temp1;
          } else if (temp1 -> next == NULL) {
            cout << "The node with value " << F << " is the last node of the list" << endl;
            isItemAvailable = true;
            cout << "memory location : " << temp1 << endl;
            return temp1;
          } else {
            cout << "value of previous node of " << F << " : " << temp1 -> previous -> listValue << endl;
            cout << "value of next node of " << F << " : " << temp1 -> next -> listValue << endl;
            cout << "The index of " << F << " is " << number << endl;
            cout << "memory location : " << temp1 << endl;
            isItemAvailable = true;
            return temp1;
          }

        }
        temp1 = temp1 -> next;
      }

    }
    if (isItemAvailable == false) {
      cout << "Value not found in the list. " << endl;
    }

  };

  //Function to get the total sum of the values in the linked list
  int sum() {
    if (start == NULL) {
      cout << "Please add something first !" << endl;

    } else {
      Node * temp = new Node;
      temp = start;
      int sum_value = 0;
      int value;
      while (temp != NULL) {
        value = temp -> listValue;
        sum_value = sum_value + value;
        temp = temp -> next;
      }
      cout << "The sum is " << sum_value << endl;
    }
  };

};

int main() {
  //Creating an object for double linked list
  DoubleLinkedList list;

  int number_of_nodes, value, input = 10;

  cout << "\t\t..Doubly Linked List..\n\n\t\t  (By : Abinayan)\n\n" << endl;
  cout << "Number of nodes (press enter after entering each value) : ";
  cin >> number_of_nodes;

  for (int i = 1; i <= number_of_nodes; i++) {
    cout << "Input data : ";
    cin >> value;
    list.insertBeg(value);
  }
  cout << endl;
  list.print();
  while (input != 0) {
    cout << "\n\t\t.....Please select one of the following.....\n" << endl;
    cout << "\t 1. Inset beginning \n" << endl;
    cout << "\t 2. Insert End \n" << endl;
    cout << "\t 3. delete beginning\n" << endl;
    cout << "\t 4. delete end\n" << endl;
    cout << "\t 5. delete value\n" << endl;
    cout << "\t 6. Print\n" << endl;
    cout << "\t 7. Search\n" << endl;
    cout << "\t 8. Sum\n" << endl;
    cout << "\t 0. Exit\n" << endl;
    cout << "Enter your choice : ";
    cin >> input;
    //validating the input by checking whether the input is integer or not
    while (!cin) {
      cin.clear();
      cin.ignore();
      cout << "Please input a integer value !" << endl << endl;
      cout << "Enter your choice : ";
      cin >> input;
    }
    cout << endl;

    switch (input) {
    case 1: {
      cout << "Input data to add beginning : ";
      cin >> value;
      list.insertBeg(value);
      cout << endl;
      list.print();
      break;
    };
    case 2: {
      list.insertEnd();
      cout << endl;
      list.print();
      break;
    };
    case 3: {
      if (list.start != NULL) {
        list.deleteBeg();
        cout << endl;
      } else {
        cout << "List is empty! Please add something before deleting." << endl;
      }
      if (list.start != NULL) {
        list.print();
      }
      break;
    };
    case 4: {
      if (list.start != NULL) {
        list.deleteEnd();
        cout << endl;
      } else {
        cout << "List is empty! Please add something before deleting." << endl;
      }
      if (list.start != NULL) {
        list.print();
      }
      break;
    };
    case 5: {
      if (list.start != NULL) {
        cout << "Input data to delete : ";
        cin >> value;
        list.deleteNode(value);
        cout << endl;
      } else {
        cout << "List is empty! Please add something before deleting." << endl;
      }
      if (list.start != NULL) {
        list.print();
      }

      break;
    };
    case 6: {
      cout << endl;
      list.print();
      break;
    };
    case 7: {
      if (list.start != NULL) {
        cout << "Input data to search : ";
        cin >> value;
        list.search(value);
        cout << endl;
      } else {
        cout << "List is empty! Please add something before deleting." << endl;
      }
      break;
    };
    case 8: {
      if (list.start != NULL) {
        cout << endl;
        list.print();
        cout << endl;
        list.sum();
      } else {
        cout << "List is empty! Please add something before deleting." << endl;
      }

      break;
    };
    case 0: {
      return 0;
    };
    default: {
      cout << "Please type the correct choice number!" << endl;
    }

    }
  }

  return 0;
}
