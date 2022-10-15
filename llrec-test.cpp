#include <iostream>
#include <fstream>
#include <functional>
#include "llrec.h"
using namespace std;

/**
 * Reads integers (separated by whitespace) from a file
 * into a linked list.
 *
 * @param[in] filename
 *  The name of the file containing the data to read
 * @return
 *  Pointer to the linked list (or NULL if empty or the
 *  file is invalid)
 */
Node* readList(const char* filename);

/**
 * Prints the integers in a linked list pointed to
 * by head.
 */
void print(Node* head);

/**
 * Deallocates the linked list nodes
 */
void dealloc(Node* head);


Node* readList(const char* filename)
{
    Node* h = NULL;
    ifstream ifile(filename);
    int v;
    if( ! (ifile >> v) ) return h;
    h = new Node(v, NULL);
    Node *t = h;
    while ( ifile >> v ) {
        t->next = new Node(v, NULL);
        t = t->next;
    }
    return h;
}

void print(Node* head)
{
    while(head) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

void dealloc(Node* head)
{
    Node* temp;
    while(head) {
        temp = head->next;
        delete head;
        head = temp;
    }
}

// -----------------------------------------------
//   Add any helper functions or
//   function object struct declarations
// -----------------------------------------------
  struct isEven
  {
    bool operator()(int x) { return x % 2 == 0; }
  };
	isEven testEven;



int main(int argc, char* argv[])
{
    if(argc < 2) {
        cout << "Please provide an input file" << endl;
        return 1;
    }

    // -----------------------------------------------
    // Feel free to update any code below this point
    // -----------------------------------------------
		
		
		Node* head = readList(argv[1]);
    cout << "Original list: ";
    print(head);

    // Test out your linked list code
		//Testing llpivot
		cout << "--------Testing llpivot--------" <<endl;
		Node* smaller  = new Node (10, nullptr);
		Node* larger;
		cout << endl << "llpivot with 10........" << endl;
		llpivot(head, smaller, larger, 10);
		cout << "Now original:";
		print(head);
		cout << "Smaller List:";
		print(smaller);
		cout << "Larger List:";
		print(larger);

		dealloc(head);
		dealloc(smaller);
		dealloc(larger);



		//Testing llfilter
		cout << "--------Testing llpivot--------" <<endl;
		Node* new_head = readList(argv[1]);
    cout << "Original list: ";
    print(new_head);
		Node* filtered;
		cout << endl << "llfilter even numbers........" << endl;
		filtered = llfilter(new_head, testEven);
		cout << "Filtered list: ";
		print(filtered);
    return 0;

}
