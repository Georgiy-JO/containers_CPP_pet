#pragma once

#include <iostream>
#include <stdexcept>
#include <limits>
#include <typeinfo>
#include <cmath>
#include "../stack/stack.hpp"
#include "../vector/s21_vector.h"

//* end() - is not standart

namespace s21 {
template <typename Key_T, typename T>
class Tree {
    private:
        class node_;
    public:
        class iterator_;
        class constIterator_;
    public:
        using value_type = T;
        using key_type = Key_T;
        using const_key_type = const Key_T;
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
                key_type key_;
                value_type data_{value_type()};
                node_ *left_{nullptr};
                node_ *right_{nullptr};
                node_ *parent_{nullptr};
/*ok*/                node_()=default;
/*ok*/                node_(const key_type &key, node_* parent=nullptr):key_{key}, data_{key}, parent_{parent}{}/*,hight_{1}*/
/*ok*/                node_(const key_type &key, const value_type &data, node_* parent=nullptr):key_{key}, data_{data}, parent_{parent}{}/*,hight_{1}*/

        };
        node_ *root_{nullptr};
        size_type size_ {0};
        node_* end_node{nullptr};

/*ok*/        node_* find_(node_ * root, const_key_type &key) const;
/*ok*/        node_* find__(node_ * root, const_value_type &value) const;
/*ok*/        inline node_* find_( const_key_type &key) const{return find_(root_,key);}
/*ok*/        inline node_* find__( const_value_type &value) const{return find__(root_,value);}
/*ok*/        void addParents(node_ *& root);
/*ok*/        void addParents();
/*ok*/        inline node_* getParent(const_key_type &key)const;
/*ok*/        node_* remove(node_ *& root, const_key_type &key);
/*ok*/        inline void removeNode(node_ *& root);
/*ok*/        inline int getBalanceFactor(const node_ * node)const;
/*ok*/        bool insert(node_ *& root,const_key_type& key, const_value_type& value);
/*ok*/        void balancerInsert(node_ *& root,const_key_type &key);
/*ok*/        void balancerRemove(node_ *& root);
/*ok*/        void rotateLeft(node_ *& root);
/*ok*/        void rotateRight(node_ *& root);
/*ok*/        unsigned int getHight(const node_* root) const;
/*ok*/        void clear(node_*& root);
/*ok*/        void setNull();
/*ok*/        void copyTreeNode(const node_* from,node_*& to) const;  
/*ok*/        static node_* getBeginig(node_* root);
/*ok*/        static node_* getEnd(node_* root);

/*ok*/        Stack<key_type>& getTree(const node_ *node,Stack<key_type>& stack)const;
/*ok*/        std::pair<Stack<key_type>, Stack<value_type>>& getTree(const node_ *node, std::pair<Stack<key_type>, Stack<value_type>>& stack)const;
    protected:
/*ok*/        const node_* getBeginig()const{return getBeginig(root_);} 
// /*ok*/        const node_* getEnd()const{ return getEnd(root_);}
    public:
/*ok*/        inline Tree():root_{nullptr},size_ {0},end_node{nullptr}{}
/*ok*/        inline Tree(const_key_type key):Tree(key,key){}
/*ok*/        inline Tree(const_key_type key, const_value_type value):Tree(){insert(key,value);}
/*ok*/        Tree(std::initializer_list<key_type> const &items);
/*ok*/        Tree(std::initializer_list<std::pair<key_type, value_type>> const &items);
/*ok*/        Tree(const Tree &other):Tree(){(*this)=other;}       //copy
/*ok*/        Tree(Tree &&other):Tree(){(*this)=std::move(other);} //move
/*ok*/        inline ~Tree(){clear();}

/*ok*/        Tree &operator=(const Tree &other);         //copy
/*ok*/        Tree &operator=(Tree &&other);              //move
/*ok*/        inline bool contains(const_key_type key)const {return find_(key)?1:0;}
/*ok*/        inline bool containsVal(const_value_type value)const {return find__(value)?1:0;}
/*ok*/        inline iterator find(const_key_type& key) const;
/*ok*/        std::pair<iterator, bool> insert(const_key_type& key){return insert(key,key);}
/*ok*/        std::pair<iterator, bool> insert(const_key_type& key, const_value_type &value);
/*ok*/        void remove(const_key_type key){root_=remove(root_,key);}
/*ok*/        void erase(iterator pos){if(pos.assigned())remove(pos.getKey());}
/*ok*/        inline bool empty(){return root_==nullptr;}
/*ok*/        void swap(Tree& other) noexcept;
/*ok*/        void merge(Tree& other);
/*ok*/        inline size_type max_size() const noexcept;
/*ok*/        inline size_type size(){return size_;}
/*ok*/        inline void clear();
/*ok*/        void copyTree(Tree<Key_T,T>& TO) const; 
/*ok*/        iterator_ begin(){return iterator_(getBeginig(root_));} 
/*ok*/        iterator_ end();

            //extra functions
/*ok*/        void showTreeVertical();
/*ok*/        void showTreeVertical(const node_ *node);
/*ok*/        void showTreeVerticalVal();
/*ok*/        void showTreeVerticalVal(const node_ *node);
/*ok*/        Stack<key_type>& getTree(Stack<key_type>& stack)const{return getTree(root_, stack);}
/*ok*/        std::pair<Stack<key_type>, Stack<value_type>>& getTree(std::pair<Stack<key_type>, Stack<value_type>>& stack)const{return getTree(root_, stack);}
/*ok*/        key_type getParentData(const_key_type key)const;
/*ok*/        void crazyPrinter(const node_* root)const;
/*ok*/        void crazyPrinter()const{crazyPrinter(root_);}

            //bonus functions
            template <typename...Args>
/*ok*/            s21::vector<std::pair<iterator,bool>> insert_many(Args&&... args);
/*ok*/            iterator insertMult(const_key_type& key){return insertMult(key,key);}
/*ok*/            iterator insertMult(const_key_type& key,const_value_type& value);
/*ok*/            node_* insertMult(node_ *& root,const_key_type& key,const_value_type& value);
        

    friend class iterator_;
        class iterator_{
                node_* element_{nullptr};
                node_* end_node_{nullptr};
                // Tree* three_ptr_{nullptr};
/*ok*/                node_* getNext(){return element_?getNext(element_):nullptr;}
/*ok*/                node_* getNext(node_* node);
/*ok*/                node_* getPrev(){return element_?getPrev(element_):nullptr;}
/*ok*/                node_* getPrev(node_* node);
/*ok*/                inline void ifElement()const;

            public:
                    friend class constIterator_;
/*ok*/                iterator_(node_* element=nullptr, node_* end_n=nullptr):element_{element}, end_node_{end_n}{}
/*ok*/                iterator_(const iterator_& other):iterator_(other.element_, other.end_node_){}
/*ok*/                iterator_& operator=(const iterator_& other);
/*ok*/                iterator_& operator=(const Tree<Key_T,T>& tree);
/*ok*/                iterator_& operator=(const node_*& node);
/*ok*/                iterator_& operator++();
/*ok*/                iterator_& operator--();
/*ok*/                iterator_& operator+=(int n);
/*ok*/                iterator_& operator-=(int n);
/*ok*/                iterator_ operator++(int);
/*ok*/                iterator_ operator--(int);
/*ok*/                auto operator*()const{return getValue();}
// /**/                const_pointer operator->()const;
/*ok*/                bool operator==(const iterator_& other)const{return element_==other.element_;}
/*ok*/                bool operator!=(const iterator_& other)const{return element_!=other.element_;}
/*ok*/                inline const_value_type& getValue()const;
/*ok*/                inline const_key_type& getKey()const;
/*ok*/                auto getPair()const;
/*ok*/                bool assigned()const{return element_!=nullptr;}
        };
        
        class constIterator_: public iterator_{
            public:
/*ok*/                constIterator_(node_* element=nullptr):iterator_(element){}
/*ok*/                constIterator_(const iterator_& other):iterator_(other.element_){}
/*ok*/                constIterator_(const constIterator_& other):iterator_(other.element_){}
/*ok*/                auto operator*() const {return iterator_::operator*();}
// /**/                const_pointer operator->() const {return iterator_::operator->();}
/*ok*/                bool operator==(const iterator_& other)const{return iterator_:: operator==(other);}
/*ok*/                bool operator!=(const iterator_& other)const{return iterator_::operator!=(other);}
        };
};

#include "avl_tree.tpp"
//Iterator
#include "avl_tree_irterator.tpp"
//Multiset module
#include "avl_tree_multiset.tpp"

template <typename Key_T, typename T>
typename Tree<Key_T,T>::iterator_ Tree<Key_T,T>::end(){
    if(root_){
        std::cout<<"here"<<std::endl;
        if(!end_node)
            end_node = new node_();
        end_node->parent_=getEnd(root_);
    }
    return iterator_(end_node);
}

}


