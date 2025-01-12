#pragma ones

#include <iostream>
#include "../AVLtree/avl_tree.hpp"

namespace s21 {
template <typename Key>
class Set: public Tree<Key, Key> {
    public:
        using key_type = Key;
        using value_type = Key;
        using reference = value_type &;
        using const_reference = const value_type &;
        using iterator = typename Tree<Key, Key>::iterator_;
        using const_iterator = typename Tree<Key, Key>::constIterator_;
        using size_type = size_t;

        set()	
        set(std::initializer_list<value_type> const &items)
        set(const set &s)
        set(set &&s)
        ~set()

        operator=(set &&s) //assignment moving
        operator=(const set &s) //assignment copying
        bool empty()
        size_type size()
        size_type max_size()
        void clear()	//clears the contents
        std::pair<iterator, bool> insert(const value_type& value)	//inserts a node and returns an iterator to where the element is in the container and bool denoting whether the insertion took place
        void erase(iterator pos)	//erases an element at pos
        void swap(set& other)	//swaps the contents
        void merge(set& other);	//splices nodes from another container
        iterator find(const Key& key)	//finds an element with a specific key
        bool contains(const Key& key)	//checks if the container contains an element with a specific key

        iterator begin(); //returns an iterator to the beginning
        iterator end();   //returns an iterator to the end

};



}  // namespace s21