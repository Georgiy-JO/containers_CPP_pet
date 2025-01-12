#pragma once

#include <iostream>
#include <stdexcept>
#include <limits>
#include <cmath>
#include "../stack/stack.hpp"

//* add exceptions?
//* add key type?

namespace s21 {
template <typename T>
class Tree {
    private:
        class node_;
    public:
        class iterator_;
        class constIterator_;
    public:
        using value_type = T;
        using const_value_type = const T;
        using reference = T &;
        using const_reference = const T &;
        using size_type = size_t;
        using pointer = T *;
        using const_pointer = const T *;
        using iterator = iterator_;
        using constIterator = constIterator_;
    private:
        class node_{
            public:
                T data_{value_type()};
                node_ *left_{nullptr};
                node_ *right_{nullptr};
                node_ *parent_{nullptr};
                // unsigned int hight_{0};
                node_()=default;
                node_(const T &data, node_* parent=nullptr):data_{data}, parent_{parent}{}/*,hight_{1}*/

        };
        node_ *root_{nullptr};
        size_type size_ {0};

/*ok*/        node_* find(node_ * root, const value_type &value) const;
/*ok*/        inline node_* find( const value_type &value) const{return find(root_,value);}
/*ok*/        void addParents(node_ *& root);
/*ok*/        void addParents(){addParents(root_);}
/*ok*/        inline node_* getParent(const value_type &value)const;
/*ok*/        node_* remove(node_ *& root, const value_type &value);
/*ok*/        inline void removeNode(node_ *& root);
/*ok*/        inline int getBalanceFactor(const node_ * node)const;
/*ok*/        bool insert(node_ *& root,const value_type& value);
// /**/        unsigned int hightCounter(node_ * root);
// /**/        void hightCounter(){ hightCounter(root_);}
/*ok*/        void balancerInsert(node_ *& root,const value_type &value);
/*ok*/        void balancerRemove(node_ *& root);
/*ok*/        void rotateLeft(node_ *& root);
/*ok*/        void rotateRight(node_ *& root);
/*ok*/        unsigned int getHight(const node_* root) const;
/*ok*/        void clear(node_*& root);
/*ok*/        void setNull();
/*ok*/        void copyTreeNode(const node_* from,node_*& to) const;  
/*ok*/        Stack<T>& getTree(const node_ *node,Stack<T>& stack)const;
/*ok*/        static node_* getBeginig(node_* root);
/*ok*/        static node_* getEnd(node_* root);
    protected:
/*ok*/        const node_* getBeginig(){return getBeginig(root_);} 
/*ok*/        const node_* getEnd(){ return getEnd(root_);} 
    public:
/*ok*/        inline Tree():root_{nullptr},size_ {0}{}
/*ok*/        inline Tree(const value_type& value):Tree(){insert(value);}
/*ok*/        Tree(std::initializer_list<value_type> const &items);
/*ok*/        Tree(const Tree &other):Tree(){(*this)=other;}       //copy
/*ok*/        Tree(Tree &&other):Tree(){(*this)=std::move(other);} //move
/*ok*/        inline ~Tree(){clear();}

/*ok*/        Tree &operator=(const Tree &other);         //copy
/*ok*/        Tree &operator=(Tree &&other);              //move
/*ok*/        inline bool contains(const value_type &value)const {return find(value)?1:0;}
/*ok*/        void insert(const value_type &value);
/*ok*/        void remove(const value_type &value){remove(root_,value);}
/*ok*/        inline bool empty(){return root_==nullptr;}
/*ok*/        void swap(Tree& other) noexcept;
/*ok*/        inline size_type max_size() const noexcept;
/*ok*/        inline size_type size(){return size_;}
/*ok*/        inline void clear(){clear(root_);}
/*ok*/        void copyTree(Tree<T>& TO) const; 
/*ok*/        iterator_ begin(){return iterator_(getBeginig(root_));} 
/*ok*/        iterator_ end(){return iterator_(getEnd(root_));}

            //extra functions
/*ok*/        void showTreeVertical();
/*ok*/        void showTreeVertical(const node_ *node);
/*ok*/        Stack<T>& getTree(Stack<T>& stack)const{return getTree(root_, stack);}
/*ok*/        value_type getParentData(const value_type &value)const;
/*ok*/        void crazyPrinter(const node_* root)const;
/*ok*/        void crazyPrinter()const{crazyPrinter(root_);}
        

    friend class iterator_;
        class iterator_{
                node_* element_{nullptr};
                // Tree* three_ptr_{nullptr};
/*ok*/                node_* getNext(){return element_?getNext(element_):nullptr;}
/*ok*/                node_* getNext(node_* node);
/*ok*/                node_* getPrev(){return element_?getPrev(element_):nullptr;}
/*ok*/                node_* getPrev(node_* node);
            public:
                    friend class constIterator_;
/*ok*/                iterator_(node_* element=nullptr):element_{element}{}
/*ok*/                iterator_(const iterator_& other):iterator_(other.element_){}
/*ok*/                iterator_& operator=(const iterator_& other);
/*ok*/                iterator_& operator=(const Tree<T>& tree);
/*ok*/                iterator_& operator=(const node_*& node);
/*ok*/                iterator_& operator++();
/*ok*/                iterator_& operator--();
/*ok*/                iterator_& operator+=(int n);
/*ok*/                iterator_& operator-=(int n);
/*ok*/                iterator_ operator++(int);
/*ok*/                iterator_ operator--(int);
/*ok*/                const_reference operator*()const;
// /**/                const_pointer operator->()const;
/*ok*/                bool operator==(const iterator_& other)const{return element_==other.element_;}
/*ok*/                bool operator!=(const iterator_& other)const{return element_!=other.element_;}
        };
        
        class constIterator_: public iterator_{
            public:
/*ok*/                constIterator_(node_* element=nullptr):iterator_(element){}
/*ok*/                constIterator_(const iterator_& other):iterator_(other.element_){}
/*ok*/                constIterator_(const constIterator_& other):iterator_(other.element_){}
/*ok*/                const_reference operator*() const {return iterator_::operator*();}
// /**/                const_pointer operator->() const {return iterator_::operator->();}
/*ok*/                bool operator==(const iterator_& other)const{return iterator_:: operator==(other);}
/*ok*/                bool operator!=(const iterator_& other)const{return iterator_::operator!=(other);}
        };
};

#include "avl_tree.tpp"
//Iterator
#include "avl_tree_irterator.tpp"

}


