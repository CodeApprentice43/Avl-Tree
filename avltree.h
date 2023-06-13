/* AvlTree.h contains the declaration of class template AvlTree.
   Basic operations:
     Constructor: Constructs an empty AvlTree
     empty:       Checks if a AvlTree is empty
     search:      Search a AvlTree for an item
     insert:      Inserts a value into a AvlTree
     remove:      Removes a value from a AvlTree
     inorder:     Inorder traversal of a AvlTree -- output the data values
     graph:       Output a grapical representation of a AvlTree
   Private utility helper operations:
     search2:     Used by delete
     inorderAux:  Used by inorder
     graphAux:    Used by graph
     insertAux:   Used by insert
     getHeight:   Returns the height of a subtree at a given node
     balance:     Balances the subtree at a given node //THIS NEEDS TO BE DEFINED
   Other operations:
     destructor
     copy constructor
     assignment operator
     preorder, postorder, and level-by-level traversals
     level finder
   Note: Execution terminates if memory isn't available for a new AvlTree node.
---------------------------------------------------------------------------*/

#include <iostream>
#include<queue>
#include<stack>
using namespace std;

#ifndef BINARY_SEARCH_TREE
#define BINARY_SEARCH_TREE

template <typename DataType>
class AvlTree
{
public:
    /***** Function Members *****/
    AvlTree();
    /*------------------------------------------------------------------------
      Construct a AvlTree object.

      Precondition:  None.
      Postcondition: An empty AvlTree has been constructed.
     -----------------------------------------------------------------------*/

    bool empty() const;
    /*------------------------------------------------------------------------
      Check if AvlTree is empty.

      Precondition:  None.
      Postcondition: Returns true if AvlTree is empty and false otherwise.
     -----------------------------------------------------------------------*/

    bool search(const DataType& item) const;
    /*------------------------------------------------------------------------
      Search the AvlTree for item.

      Precondition:  None.
      Postcondition: Returns true if item found, and false otherwise.
     -----------------------------------------------------------------------*/

    void insert(const DataType& item);
    /*------------------------------------------------------------------------
      Insert item into AvlTree.

      Precondition:  None.
      Postcondition: AvlTree has been modified with item inserted at proper
          position to maintain AvlTree property.
    ------------------------------------------------------------------------*/

    void remove(const DataType& item);
    /*------------------------------------------------------------------------
      Remove item from AvlTree.

      Precondition:  None.
      Postcondition: AvlTree has been modified with item removed (if present);
          AvlTree property is maintained.
      Note: remove uses auxiliary function search2() to locate the node
            containing item and its parent.
   ------------------------------------------------------------------------*/

    void inorder(ostream& out) const;
    /*------------------------------------------------------------------------
      Inorder traversal of AvlTree.

      Precondition:  ostream out is open.
      Postcondition: AvlTree has been inorder traversed and values in nodes
          have been output to out.
      Note: inorder uses private auxiliary function inorderAux().
   ------------------------------------------------------------------------*/

    void topDownLR(ostream& out);

    void bottomUpRL(ostream& out);



    void graph(ostream& out) const;
    /*------------------------------------------------------------------------
      Graphic output of AvlTree.

      Precondition:  ostream out is open.
      Postcondition: Graphical representation of AvlTree has been output to out.
      Note: graph() uses private auxiliary function graphAux().
   ------------------------------------------------------------------------*/

  
private:
    /***** Node class *****/
    class AvlNode
    {
    public:
        DataType data;
        AvlNode* left;
        AvlNode* right;
        int height;
        // AvlNode constructors
        // Default -- data part is default DataType value; both links are null.
        AvlNode()
            : left(0), right(0)
        {}

        // Explicit Value -- data part contains item; both links are null, height is zero
        AvlNode(DataType item)
            : data(item), left(0), right(0), height(0)
        {}

    };// end of class AvlNode declaration

    typedef AvlNode* AvlNodePointer;

    /***** Private Function Members *****/
    void search2(const DataType& item, bool& found,
        AvlNodePointer& locptr, AvlNodePointer& parent) const;
    /*------------------------------------------------------------------------
      Locate a node containing item and its parent.

      Precondition:  None.
      Postcondition: locptr points to node containing item or is null if
          not found, and parent points to its parent.#include <iostream>
    ------------------------------------------------------------------------*/


    void inorderAux(ostream& out,
        AvlNodePointer subtreePtr) const;
    /*------------------------------------------------------------------------
      Inorder traversal auxiliary function.

      Precondition:  ostream out is open; subtreePtr points to a subtree
          of this AvlTree.
      Postcondition: Subtree with root pointed to by subtreePtr has been
          output to out.
   ------------------------------------------------------------------------*/

    void graphAux(ostream& out, int indent,
        AvlNodePointer subtreeRoot) const;
    /*------------------------------------------------------------------------
      Graph auxiliary function.

      Precondition:  ostream out is open; subtreePtr points to a subtree
          of this AvlTree.
      Postcondition: Graphical representation of subtree with root pointed
          to by subtreePtr has been output to out, indented indent spaces.
   ------------------------------------------------------------------------*/

    void insertAux(const DataType& x, AvlNodePointer& t);

   

    int getHeight(AvlNodePointer t);

    void rotateRight(AvlNodePointer, AvlNodePointer, AvlNodePointer);

    void rotateLeft(AvlNodePointer, AvlNodePointer, AvlNodePointer);

    void balance(AvlNodePointer& t);
    
    //Functions I Defined and documented in the definition
    /********************************/
    int max(int lhs, int rhs) const;

    void rotateright(AvlNodePointer& );

    void rotateleft(AvlNodePointer& );

    void rotateleftright(AvlNodePointer& );

    void rotaterightleft(AvlNodePointer& );
    /********************************/
    /***** Data Members *****/
    AvlNodePointer myRoot;

}; // end of class template declaration

//--- Definition of constructor
template <typename DataType>
inline AvlTree<DataType>::AvlTree()
    : myRoot(0)
{}

//--- Definition of empty()
template <typename DataType>
inline bool AvlTree<DataType>::empty() const
{
    return myRoot == 0;
}

//--- Definition of search()
template <typename DataType>
bool AvlTree<DataType>::search(const DataType& item) const
{
    AvlTree<DataType>::AvlNodePointer locptr = myRoot;
    bool found = false;
    while (!found && locptr != 0)
    {
        if (item < locptr->data)       // descend left
            locptr = locptr->left;
        else if (locptr->data < item)  // descend right
            locptr = locptr->right;
        else                           // item found
            found = true;
    }
    return found;
}

//--- Definition of insert()
template <typename DataType>
inline void AvlTree<DataType>::insert(const DataType& item)
{
    insertAux(item, myRoot);
}


template <typename DataType>
void AvlTree<DataType>::insertAux(const DataType& x, AvlNodePointer& t)
{
    if (t == nullptr)
        t = new AvlNode(x);
    else if (x < t->data)
        insertAux(x, t->left);
    else if (t->data < x)
        insertAux(x, t->right);

    balance(t);
}


template <typename DataType>
int AvlTree<DataType>::getHeight(AvlNodePointer t)
{
    return t == NULL ? -1 : t->height;
}

//--- Definition of remove()
template <typename DataType>
void AvlTree<DataType>::remove(const DataType& item)
{
    bool found;                      // signals if item is found
    AvlTree<DataType>::AvlNodePointer
        x,                            // points to node to be deleted
        parent;                       //    "    " parent of x and xSucc
    search2(item, found, x, parent);

    if (!found)
    {
        cout << "Item not in the AvlTree\n";
        return;
    }
    //else
    if (x->left != 0 && x->right != 0)
    {                                // node has 2 children
       // Find x's inorder successor and its parent
        AvlTree<DataType>::AvlNodePointer xSucc = x->right;
        parent = x;
        while (xSucc->left != 0)       // descend left
        {
            parent = xSucc;
            xSucc = xSucc->left;
        }

        // Move contents of xSucc to x and change x 
        // to point to successor, which will be removed.
        x->data = xSucc->data;
        x = xSucc;
    } // end if node has 2 children

    // Now proceed with case where node has 0 or 1 child
    AvlTree<DataType>::AvlNodePointer
        subtree = x->left;             // pointer to a subtree of x
    if (subtree == 0)
        subtree = x->right;
    if (parent == 0)                  // root being removed
        myRoot = subtree;
    else if (parent->left == x)       // left child of parent
        parent->left = subtree;
    else                              // right child of parent
        parent->right = subtree;
    delete x;
}

//--- Definition of inorder()
template <typename DataType>
inline void AvlTree<DataType>::inorder(ostream& out) const
{
    inorderAux(out, myRoot);
}

template <typename DataType>
void AvlTree<DataType>::topDownLR(ostream& out)
{
    queue<AvlNodePointer> Q;
    AvlNodePointer p = myRoot;

    if (p != NULL)
    {
        Q.push(p);
        while (!Q.empty())
        {
            p = Q.front();
            out << p->data << ' ';
            Q.pop();
            if (p->left != NULL)
                Q.push(p->left);
            if (p->right != NULL)
                Q.push(p->right);
        }
    }
}

template <typename DataType>
void AvlTree<DataType>::bottomUpRL(ostream& out)
{
    queue<AvlNodePointer> Q;
    stack<AvlNodePointer> S;
    AvlNodePointer p = myRoot;
    if (p != NULL)
    {
        Q.push(p);
        while (!Q.empty())
        {
            p = Q.front();
            S.push(p);
            Q.pop();
            if (p->left != NULL)
                Q.push(p->left);
            if (p->right != NULL)
                Q.push(p->right);
        }
    }

    while (!S.empty())
    {
        out << S.top()->data << ' ';
        S.pop();
    }
}

template <typename DataType>
void AvlTree<DataType>::rotateRight(AvlNodePointer G, AvlNodePointer P, AvlNodePointer ch)
{  //this rotates around the PARENT, moving the child UP
    if (G != NULL)
        G->right = P->left;
    P->left = ch->right;
    ch->right = P;
    if (P == myRoot)
        myRoot = ch;
}

template <typename DataType>
void AvlTree<DataType>::rotateLeft(AvlNodePointer G, AvlNodePointer P, AvlNodePointer C)
{   //this rotates around the CHILD, moving the parent DOWN
    P->right = C->left;
    C->left = P;
    if (P == myRoot)
        myRoot = C;
    else
        G->right = C;
}
/*
* STEPS TO THE BALANCE FUNCTION:
*1. Check if there is an imbalance to the left of the current node
*2. If there is, enter the if condition
*3. Check if there is an imbalance to the right of the child
*4. If imbalance does not exist, simply rotate right since we know there is an imbalance to the left from STEP 1
*5 If an imbalance doest exist to the right of the child, rotate left right
* IF AN IMBALANCE TO THE LEFT OF THE NODE DOES NOT EXIST, CHECK FOR AN IMBALANCE TO THE RIGHT 
* Follow the same procedures/steps mentioned 1-5 except we check for an imbalance to the left of the child
* 
 */
template <typename DataType>
void AvlTree<DataType>::balance(AvlNodePointer& t)
{
    if (t == nullptr)
        return;

    //checks for imbalance to the left of the node 
    if (getHeight(t->left) - getHeight(t->right) > 1)
        //checking for imbalance to the right of the CHILD
        if (getHeight(t->left->left) < getHeight(t->left->right))
            //since there is an imbalance to the RIGHT of the child we rotate left first
         
            rotateleftright(t);
        else 
           
            rotateright(t);
        
            
    else
        //checks for an imbalance to the right of the node 
        if (getHeight(t->right) - getHeight(t->left) > 1)
            //checking for an imbalance to the left of the CHILD
            if (getHeight(t->right->right) < getHeight(t->right->left))
                //since there is an imbalance to the left of the child we rotate right first
               
                rotaterightleft(t);
            else
             
                rotateleft(t);
               
    //adjust the height of the node (Since the insert is recursive it goes back up from the very bottom thus heights need to be adjusted
    t->height = max(getHeight(t->left), getHeight(t->right)) + 1;

}


template<typename DataType>
int AvlTree<DataType>::max(int lhs, int rhs) const
{
    {
        return lhs > rhs ? lhs : rhs;
    }

}

template<typename DataType>
void AvlTree<DataType>::rotateright(AvlNodePointer& p)
{
    //get the left child
    AvlNode* ch = p->left;
    //the right subtree of the child becomes the left subtree of parent
    p->left = ch->right;
    //Parent rotates DOWN to the right of child
    ch->right = p;
    //adjust the heights of both nodes afer rotation
    p->height = max(getHeight(p->left), getHeight(p->right)) + 1;
    ch->height = max(getHeight(ch->left), getHeight(ch->right)) + 1;
    //Since the Parent rotates DOWN the child becomes the new parent 
    p = ch;
}
template<typename DataType>
void AvlTree<DataType>::rotateleft(AvlNodePointer& p)
{
    //get the right child
    AvlNode* ch = p->right;
    //the left subtree of the child becomes the right subtree of parent
    p->right = ch->left;
    //Parent rotates DOWN to the left of child
    ch->left = p;
    //adjust the heights of both nodes afer rotation
    p->height = max(getHeight(p->left), getHeight(p->right)) + 1;
    ch->height = max(getHeight(ch->right), getHeight(ch->left)) + 1;
    //Since the Parent rotates DOWN the child becomes the new parent 
    p = ch;
}

template<typename DataType>
void AvlTree<DataType>::rotateleftright(AvlNodePointer& p)
{
    // the same as a rotate left, and then a rotate right function documented above
    //imbalance to the right of the left child of parent so we send the left child into the rotateleft function
    rotateleft(p->left);
    //imbalance to the left of P
    rotateright(p);
}

template<typename DataType>
void AvlTree<DataType>::rotaterightleft(AvlNodePointer& p)
{
    // the same as a rotate right, and then a rotate left function documented above
     //imbalance to the left of the right child of parent so we send the left child into the rotateright function
    rotateright(p->right);
    //imbalance to the right of P
    rotateleft(p);
}

//--- Definition of graph()
template <typename DataType>
inline void AvlTree<DataType>::graph(ostream& out) const
{
    graphAux(out, 0, myRoot);
}

//--- Definition of search2()
template <typename DataType>
void AvlTree<DataType>::search2(const DataType& item, bool& found,
    AvlNodePointer& locptr,
    AvlNodePointer& parent) const
{
    locptr = myRoot;
    parent = 0;
    found = false;
    while (!found && locptr != 0)
    {
        if (item < locptr->data)       // descend left
        {
            parent = locptr;
            locptr = locptr->left;
        }
        else if (locptr->data < item)  // descend right
        {
            parent = locptr;
            locptr = locptr->right;
        }
        else                           // item found
            found = true;
    }
}

//--- Definition of inorderAux()
template <typename DataType>
void AvlTree<DataType>::inorderAux(ostream& out,
    AvlNodePointer subtreeRoot) const
{
    if (subtreeRoot != 0)
    {
        inorderAux(out, subtreeRoot->left);    // L operation
        out << subtreeRoot->data << "  ";      // V operation
        inorderAux(out, subtreeRoot->right);   // R operation
    }
}

//--- Definition of graphAux()
#include <iomanip>

template <typename DataType>
void AvlTree<DataType>::graphAux(ostream& out, int indent,
    AvlNodePointer subtreeRoot) const
{
    if (subtreeRoot != 0)
    {
        graphAux(out, indent + 8, subtreeRoot->right);
        out << setw(indent) << " " << subtreeRoot->data << endl;
        graphAux(out, indent + 8, subtreeRoot->left);
    }
}

#endif

