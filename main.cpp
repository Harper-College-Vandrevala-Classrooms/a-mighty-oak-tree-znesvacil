//
//  main.cpp
//  A Mighty Oak Tree
//
//  Created by Zachary Nesvacil on 12/8/24.
//

#include <iostream>

using namespace std;

class Squirrel {
  private:
    string name;

  public:
    Squirrel(string name) {
      this->name = name;
    }

    string get_name() {
      return this->name;
    }
};

struct Node {

    Squirrel *branch;
    Node *left_node;
    Node *right_node;
    
    Node(Squirrel *data)
    {
        this->branch = data;
        this->left_node = nullptr;
        this->right_node = nullptr;
    }
    
    void set_left(Node *left)
    {
        if (left) {
            this->left_node = left;
        }
    }
    
    void set_right(Node *right)
    {
        if (right) {
            this->right_node = right;
        }
    }
    
    Node* left()
    {
        return this->left_node;
    }
    
    Node* right()
    {
        return this->right_node;
    }
    
    string data()
    {
        return this->branch->get_name();
    }
};


int main() {
    Squirrel cheeks = Squirrel("Cheeks");
    Node* node_one = new Node(&cheeks);

    Squirrel squeaks = Squirrel("Squeaks");
    Node* node_two = new Node(&squeaks);

    Squirrel fluffybutt = Squirrel("Mr. Fluffy Butt");
    Node* node_three = new Node(&fluffybutt);

    node_one->set_left(node_two);
    node_one->set_right(node_three);

    Node* retrieved_node_one = node_one->left(); // This should retrieve the left node
    Node* retrieved_node_two = node_one->right(); // This should retrieve the right node
    
    cout << retrieved_node_one->data() << endl;
    cout << retrieved_node_two->data() << endl;
    
}
