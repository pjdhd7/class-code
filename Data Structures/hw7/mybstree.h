//Name: Peter Dolan     ID: 12410657
//Instructor: Morales    Section: A     Date: 05/04/2015
//File: mybstree.h      Desc: Implements a BSTree

#ifndef MYBSTREE_H
#define MYBSTREE_H
#include "abstractbstree.h"

//Treenode class 
template <typename T>
struct TreeNode
{
   T m_data;
   TreeNode<T>* m_right;
   TreeNode<T>* m_left;
   
   TreeNode<T>(const T x, TreeNode<T>* left, TreeNode<T>* right)
   {
     m_data = x;
     m_right = right;
     m_left = left;
   }
   
   ~TreeNode()
   {
	   
   }
};

//Encapsulating class to point to the tree's root
template <typename T>
class MyBSTree : public AbstractBSTree<T>
{
  public:
    TreeNode<T>* m_root;
    int m_size;
    
    // Operator =
    MyBSTree<T> operator=(MyBSTree<T> &t)
    {
      m_root = clone(t.m_root);
      m_size = t.m_size;
      return *this;
    }
    
    
    
    MyBSTree(){ m_size=0; m_root=NULL; }
    
    MyBSTree(MyBSTree<T>& t) 
    {
      m_root = clone(t.m_root);
      m_size = t.m_size;
    }
    
    ~MyBSTree()
    {
		clear();
    }

    virtual int size() const { return m_size; }

    virtual bool isEmpty() const
    {
        if (m_root == NULL)
            return true;
        return false;
    }

    virtual int height() const
    {
        int l;
        int r;
        TreeNode<T>* tmp = m_root;
        if (tmp != NULL)
        {
            l = theHeight(tmp->m_left);
            r = theHeight(tmp->m_right);
            if (r > l)
                return r+1;
            else
                return l+1;
        } 
        return 0;
    }

    virtual const T& findMax() const throw (Oops)
    {
        Oops err("OOPS! : Tree is Empty!!");
        if (m_root == NULL)
        {
            throw err;
        }
        else
	{
	  if (m_root->m_right != NULL)
		return Max(m_root->m_right);
        }
    }

    virtual const T& findMin() const throw (Oops)
    {
        Oops err("OOPS! : Tree is Empty!!");
        if (m_root == NULL)
        {
            throw err;
        }
        else
        {
            if (m_root->m_left != NULL)
                return Min(m_root->m_left); //Calls recursive function
        }
        return m_root->m_data;
    }

    virtual int find(const T& x) const
    {
        if (m_root != NULL)
            return findIt(m_root, x);
        return -1;
    }

	virtual void clear()
	{  //accounts for the empty tree
           //Without this, it WILL segfault
	  if (m_root != NULL) 
	  {
            //Using recursive functions to remove everything form the tree
	    while (m_root->m_left != NULL)
		removeIt(m_root->m_left->m_data, m_root->m_left);
	    while (m_root->m_right != NULL)
		removeIt(m_root->m_right->m_data, m_root->m_right);
	    delete m_root;
	    m_root = NULL;
	  }
		return;
    }

    virtual void insert(const T& x)
    {
        if (m_root == NULL)
        {
            m_root = new TreeNode<T>(x, m_root, m_root);
            m_size++;
        }
        else if(findIt(m_root, x) < 0)
        {
            insertIt(x, m_root); //Calls recursive function
            m_size++;
        }
        return;
    }

    virtual void remove(const T& x)
    {
        if (m_root != NULL && findIt(m_root, x) > 0)
        {
	  if (x < m_root->m_data)
	    	removeIt(x, m_root->m_left);
	  else if (x > m_root->m_data)
		removeIt(x, m_root->m_right);
	  else
	  {
		m_root->m_data = Max(m_root->m_left);
		removeIt(m_root->m_data, m_root->m_left);
	  }
          m_size--;
        }
        return;
    }
    
    virtual void printPreOrder() const
    {
        if(m_root != NULL)
        {
            cout<< m_root->m_data <<endl;
            printPre(m_root->m_left);
            printPre(m_root->m_right);
        }
    }
    
    virtual void printPostOrder() const
    {
        if(m_root != NULL)
        {
            printPost(m_root->m_left);
            printPost(m_root->m_right);
            cout<< m_root->m_data <<endl;
        }
    }

    virtual void print() const
    {
        int pad = 0;
        if (m_root == NULL)
            cout << endl;
        else{
            prettyPrint(m_root->m_right, pad + 4);
            cout<< m_root->m_data << endl;
            prettyPrint(m_root->m_left, pad + 4);
        }
    }
};

//Recursive find function
template <typename T>
int findIt(TreeNode<T>* t, const T& x)
{
    int height = 0;
    if (t == NULL)
        return -1;
    else if (x < t->m_data)
    {
        height = findIt(t->m_left, x);
        if (height < 0)
            return height - 1;
        else
            return height + 1;
    }
    else if (x>t->m_data)
    {
        height = findIt(t->m_right, x);
        if (height < 0)
            return height - 1;
        else
            return height + 1;
    }
	return height + 1;
}

//Recursive height function
template <typename T>
int theHeight(TreeNode<T>* count)
{
    int l;
    int r;
    if (count == NULL)
    {
        return 0;
    }
    l = theHeight(count->m_left);
    r = theHeight(count->m_right);
    if (l > r || l == r)
    {
        return (l + 1);
    }
    else
    {
        return (r + 1);
    }
}

//Recursive Max function
template <typename T>
const T& Max(TreeNode<T>* &t)
{
    TreeNode<T>* p = t;
    while (p->m_right != NULL)
    {
        p = p->m_right;
    }
    return p->m_data;
}

//Recursive min function
template <typename T>
const T& Min(TreeNode<T>* &t)
{
    TreeNode<T>* p = t;
    while (p->m_left != NULL)
    {
        p = p->m_left;
    }
    return p->m_data;
}


//Recursive insert function
template <typename T>
void insertIt(const T& x, TreeNode<T>* &t)
{
    if (t == NULL)
        t = new TreeNode<T>(x, t, t);
    else if (x > t->m_data)
        insertIt(x, t->m_right);
    else if (x < t->m_data)
        insertIt(x, t->m_left);
    return;
}

//Recursive remove function
template <typename T>
void removeIt(const T& x, TreeNode<T>*& t)
{
    if (t != NULL)
    {
        if (x < t->m_data)
            removeIt(x, t->m_left);
        else if (x > t->m_data)
            removeIt(x, t->m_right);
        else
        {
            if (t->m_left == NULL && t->m_right == NULL)
            {
                delete t;
                t = NULL;
            }
            else if (t->m_left == NULL || t->m_right == NULL)
            {
		TreeNode<T>* child = t->m_left;

                if (child == NULL)
                    child = t->m_right;
                delete t;
		t = child;
            }
            else
            {
                t->m_data = Max(t->m_left);
                removeIt(t->m_data, t->m_left);
            }
        }
    }
    return;
}

template <typename T>
void printPre(TreeNode<T>* t)
{
    if(t!= NULL)
    {
        cout<< t->m_data <<endl;
        printPre(t->m_left);
        printPre(t->m_right);
    }
}

template <typename T>
void printPost(TreeNode<T>* t)
{
    if(t!= NULL)
    {
        printPost(t->m_left);
        printPost(t->m_right);
        cout<< t->m_data <<endl;
    }
}

//copied from Morales
template <typename T>
void prettyPrint (const TreeNode<T>* t, int pad)
{
   string s(pad, ' ');
   if (t == NULL)
     cout << endl;
   else{
     prettyPrint(t->m_right, pad+4);
     cout << s << t->m_data << endl;
     prettyPrint(t->m_left, pad+4);
   }  
}

//copied from Morales
template <typename T>
TreeNode<T>* clone(const TreeNode<T>* t)
{
  TreeNode<T>* tmp = NULL;
  if (t != NULL){
     tmp = new TreeNode<T>(t->m_data, clone(t->m_left), clone(t->m_right));
     return tmp;
  }  
  return tmp;
}

#endif
