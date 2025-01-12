#pragma once

#include <iostream>
#include "../set/set.hpp"

//temple
#include <vector>

namespace s21 {
template <typename Key>
class multiset: public set<Key> {
    public:
        using key_type = Key;
        using value_type = Key;
        using reference = value_type &;
        using const_reference = const value_type &;
        using iterator = typename Tree<Key, Key>::iterator_;
        using const_iterator = typename Tree<Key, Key>::constIterator_;
        using size_type = size_t;

/*ok*/        multiset();	
/*ok*/        multiset(std::initializer_list<value_type> const &items);
/*ok*/        multiset(const multiset &s);
/*ok*/        multiset(multiset &&s);
/*ok*/        ~multiset();

/*ok*/        inline multiset& operator=(multiset &&s);        // move assignment 
/*ok*/        inline multiset& operator=(const multiset &s);                    // copy assignment 
        /*
        * Functions and operators that are defined in set/Tree classes and can be used for multiset
*ok*       * bool empty();              //  checks if the multiset is empty
*ok*       * void clear();                  //  clear the multiset
*ok*       * size_type size();         //  ammount of multiset elements
*ok*       * size_type max_size();     //  returns the maximum possible number of elements
*ok*       * iterator begin();         //  returns an iterator to the beginning
*ok*       * iterator end();           //  returns an iterator to the end

*ok*       * void erase(iterator pos);	//  erases an element at "pos"
*ok*       * iterator find(const Key& key); //  finds an element with a specific key
*ok*       * bool contains(const Key& key); //  checks if the container contains an element with a specific key 
        */

/*ok*/        iterator insert(const value_type& value);  //  inserts a node, returns iterator to it 
/*ok*/        std::pair<iterator,iterator> equal_range(const Key& key);//returns range of elements matching a specific key
/*ok*/        iterator lower_bound(const Key& key);        //returns an iterator to the first element not less than the given key
/*ok*/        iterator upper_bound(const Key& key); //returns an iterator to the first element greater than the given key
/*ok*/        size_type count(const Key& key); //returns the number of elements matching a specific key
/*ok*/        void swap(multiset& other);	    //swaps the contents
/*ok*/        void merge(multiset& other);		//splices nodes from another container //!
        template <typename...Args>
/*ok*/        std::vector<iterator> insert_many(Args&&... args); // Inserts several new elements into the container
};

#include "multiset.tpp"
}  // namespace s21