#pragma once

#include <iostream>
#include "../AVLtree/avl_tree.hpp"

namespace s21 {
template <typename Key>
class set: public Tree<Key, Key> {
    public:
        using key_type = Key;
        using value_type = Key;
        using reference = value_type &;
        using const_reference = const value_type &;
        using iterator = typename Tree<Key, Key>::iterator_;
        using const_iterator = typename Tree<Key, Key>::constIterator_;
        using size_type = size_t;

/*ok*/        set():Tree<value_type,value_type>(){}	
/*ok*/        set(std::initializer_list<value_type> const &items):Tree<value_type,value_type>(items){}
/*ok*/        set(const set &s):Tree<value_type,value_type>(s){}
/*ok*/        set(set &&s):Tree<value_type,value_type>(std::move(s)){}
/*ok*/        ~set(){Tree<value_type,value_type>::clear();}

        /*
        * Functions and operators that are defined in Tree class and can be used for set

*ok*        * bool empty()              --  checks if the set is empty
*ok*        * void clear();                  --  clear the set
*ok*        * size_type size();         --  ammount of set elements
*ok*        * size_type max_size();     --  returns the maximum possible number of elements
*ok*        * void erase(iterator pos)	--  erases an element at "pos"
*ok*        * std::pair<iterator, bool> insert(const value_type& value) --  inserts a node, returns iterator to it and success flag  
*ok*        * iterator find(const Key& key) --  finds an element with a specific key
*ok*        * bool contains(const Key& key) --  checks if the container contains an element with a specific key 
*ok*        * iterator begin();         --  returns an iterator to the beginning
*ok*        * iterator end();           --  returns an iterator to the end
*ok*        * s21::vector<std::pair<iterator,bool>> insert_many(Args&&... args); -- Inserts several new elements into the container
        */
/*ok*/        inline set& operator=(set &&s){                         // move assignment        
            Tree<value_type,value_type>::operator=(std::move(s));
            return *this;
        }
/*ok*/        inline set& operator=(const set &s){                    // copy assignment 
            Tree<value_type,value_type>::operator=(s);
            return *this;
        }      
        	
/*ok*/        void swap(set& other){Tree<value_type,value_type>::swap(other);}	    //swaps the contents
/*ok*/        void merge(set& other){Tree<value_type,value_type>::merge(other);}	//splices nodes from another container
};


}  // namespace s21