#include "AVL_TREE.h"
#include "operation.h"
#include "user.h"


void main() {

    //chack for my self
    AVLNode* root = NULL;
    
    User user1 = { "dor", "mor", "a", 'c' };
    User user2 = { "dor", "mor", "b", 'c' };
    User user3 = { "dor", "mor", "z", 'c' };
    User user4 = { "dor", "mor", "y", 'c' };
    User user5 = { "dor", "mor", "e", 'c' };
    
    root = insert(root, createUser("dor", "mor", "a", "c"), compare_users_by_email);
    root = insert(root, createUser("dor", "mor", "b", "c"), compare_users_by_email);
    root = insert(root, createUser("dor", "mor", "z", "c"), compare_users_by_email);
    root = insert(root, createUser("dor", "mor", "y", "c"), compare_users_by_email);
    root = insert(root, createUser("dor", "mor", "x", "c"), compare_users_by_email);

    inorderTraversal(root, printUser);
    
    /*
    root = insert(root, createOperation("send", NULL, NULL), compare_operations_by_id);
    root = insert(root, createOperation("send", NULL, NULL), compare_operations_by_id);
    root = insert(root, createOperation("send", NULL, NULL), compare_operations_by_id);
    root = insert(root, createOperation("send", NULL, NULL), compare_operations_by_id);
    root = insert(root, createOperation("send", NULL, NULL), compare_operations_by_id);
    
    inorderTraversal(root, printOperation);
    */
}