#include "Declarations.h"

template<typename T>
Node<T>* create_node(T node_key){
    Node<T>* node  = new Node<T>(node_key, nullptr, nullptr);
    return node;
}
template<typename T>
Node<T>* search(Node<T> *root,T need_key){
    if(root == nullptr)return nullptr;
    queue<Node<T>*> queue;
    Node<T>* answer = nullptr;
    queue.push(root);

    while (!queue.empty()){
        Node<T>* temporary = queue.front();
        queue.pop();

        if(temporary->node_key == need_key)answer = temporary;
        if(temporary->left_child != nullptr)queue.push(temporary->left_child);
        if(temporary->right_child != nullptr)queue.push(temporary->right_child);

    }

    return answer;
}
template<typename T>
void insert_node(Node<T> *&root, T node_key){
    if(root == nullptr){
        root = create_node(node_key);
        return;
    }else if(root!= nullptr && root->node_key) {
        Node<T> *temporary = nullptr;
        queue<Node<T>*> queue;
        queue.push(root);
        while (!queue.empty()) {
            temporary = queue.front();
            queue.pop();

            if (temporary->left_child != nullptr) {
                queue.push(temporary->left_child);
            }
            if (temporary->right_child != nullptr) {
                queue.push(temporary->right_child);
            }
            if (temporary->left_child == nullptr) {
                temporary->left_child = create_node(node_key);
                return;
            }
            if (temporary->right_child == nullptr && temporary->left_child != nullptr) {
                temporary->right_child = create_node(node_key);
                return;
            }
        }
    }else if(root) {
        root = create_node(node_key);
        return;
    }

}
template<typename T>
void delete_node(Node<T> *&root, int node_key){
    Node<T>* node_to_delete = search(root,node_key);
    if(node_to_delete != nullptr) {
        Node<T>* temporary = nullptr;
        queue<Node<T>*> queue;
        int deepest_node_key_value = 0;
        Node<T> *deepest_element_branch = nullptr;

        queue.push(root);
        while (!queue.empty()) {
            temporary = queue.front();
            queue.pop();

            if (temporary->left_child != nullptr)queue.push(temporary->left_child);
            if (temporary->right_child != nullptr)queue.push(temporary->right_child);

        }
        node_to_delete->node_key = temporary->node_key;
        Node<T> *temporary_2 = nullptr;
        queue.push(root);
        while (!queue.empty()) {
            temporary_2 = queue.front();
            queue.pop();

            if (temporary_2->left_child != nullptr)queue.push(temporary_2->left_child);
            if (temporary_2->right_child != nullptr)queue.push(temporary_2->right_child);

            if (temporary_2->left_child != nullptr && temporary_2->left_child == temporary) {
                temporary_2->left_child = nullptr;
                return;
            }
            if (temporary_2->right_child != nullptr && temporary_2->right_child == temporary) {
                temporary_2->right_child = nullptr;
                return;
            }

        }
    }
}
template<typename T>
void print(struct Node<T> *root, int space)
{
    if (root == NULL)return;

    space += COUNT;

    print(root->right_child, space);

    cout<<endl;
    for (int i = COUNT; i < space; i++)cout<<" ";
    cout<<root->node_key<<endl;

    print(root->left_child, space);
}
template<typename T>
void print_tree(struct Node<T> *root){
    cout<<endl<<endl;
    cout<<"BINARY_TREE: "<<endl;
    print(root, 0);
    cout<<endl<<endl;
}

