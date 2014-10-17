#include<iostream>

using namespace std;
// the simplest way is just swap the data domain of every two node
class node;

class node {
    public:
        int data;
        node* next;
    public:
        node(int idata):data(idata), next(NULL) {
        }
};

class LinkList {
    public:
        LinkList() {
            head = new node(0);
            curr = head;
        }

        void build(int size) {
            int input;
            for (int i = 1; i <= size; i++) {
                //cout<<"input elements"<<endl;
//                cin >> input ; 
                input = i;
                node * tmp = new node(input);
                curr -> next = tmp;
                curr = curr -> next;
                if (head == NULL) {
                    head = curr;
                }
            }
        }

        void print() {
            curr = head -> next;
            while(curr != NULL) {
                cout<< curr->data <<endl;
                curr = curr -> next;
            }
        }

        void pairwiseSwap() {
            node * inext, *now;
            curr = head -> next;
            if (! curr ||  !curr -> next) {
                print();
                return;
            } else {
                inext = curr->next ;
                head -> next = inext;
                now = curr;
            }

            while( curr!= NULL && inext != NULL ) {
                //cout <<"|"<< curr->data<<endl;
                curr -> next = inext -> next;
                inext -> next = curr;
                curr = curr -> next;
                if (curr != NULL)
                    inext = curr-> next;
                else 
                    inext = NULL;

                now -> next = inext;
                now = curr;
            }
        }

        void pairwseSwap2() {

        }

    private:
        node* head;
        node* curr;
};

int main() {
    LinkList *my = new LinkList();

    my->build(7);
    my->print();
    cout<< "========" <<endl;
    my->pairwiseSwap();
    my->print();
}
