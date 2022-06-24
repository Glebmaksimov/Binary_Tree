#include "Declarations.h"
int main(){

    Node<int>* root = create_node(1);
    root->left_child = create_node(2);
    root->left_child->left_child = create_node(8);
    root->right_child = create_node(4);
    root->right_child->left_child = create_node(3);
    root->right_child->right_child = create_node(7);
    Node<int>* need_node = search(root,7);
    cout<<endl;
    cout<<"Found node with key "<<need_node->node_key<<endl;
    insert_node(root,5);
    delete_node(root,8);
    print_tree(root);



    return 0;
};



