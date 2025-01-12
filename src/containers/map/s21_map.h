#ifndef S21_MAP_H
#define S21_MAP_H

#include "../AVLtree/avl_tree.hpp"
#include "../vector/s21_vector.h"

namespace s21 {
template <typename key, typename t>
class map : public avl_tree<key, t> {
 public:
  class map_iterator;
  class const_map_iterator;
  map() : avl_tree<key, t>(){};
  map(std::initializer_list<std::pair<const key, t>> const &items);
  map(const map &other) : avl_tree<key, t>(other){};
  map(map &&other) noexcept : avl_tree<key, t>(std::move(other)){};
  map &operator=(map &&other) noexcept;
  map &operator=(const map &other);
  ~map() = default;

  map_iterator begin();
  map_iterator end();
  const_map_iterator cbegin() const;
  const_map_iterator cend() const;
  void merge(map &other);

  class map_iterator : public avl_tree<key, t>::iterator {
   public:
    friend class map;
    map_iterator() : avl_tree<key, t>::iterator(){};
    map_iterator(typename avl_tree<key, t>::tree_node *node,
             typename avl_tree<key, t>::tree_node *past_node = nullptr)
        : avl_tree<key, t>::iterator(node, past_node = nullptr){};
    std::pair<const key, t> operator*();

   protected:
    t &return_value();
  };

  class const_map_iterator : public map_iterator {
   public:
    friend class map;
    const_map_iterator() : map_iterator(){};
    const_map_iterator(typename avl_tree<key, t>::tree_node *node,
                   typename avl_tree<key, t>::tree_node *past_node = nullptr)
        : map_iterator(node, past_node = nullptr){};
    const std::pair<const key, t> &operator*() const {
      return map_iterator::operator*();
    };
  };
  t &at(const key &map_key);
  t &operator[](const key &map_key);
  std::pair<map_iterator, bool> insert(const std::pair<const key, t> &map_value);
  std::pair<map_iterator, bool> insert(const key &map_key, const t &obj);
  std::pair<map_iterator, bool> insert_or_assign(const key &map_key, const t &obj);
  template <class... args>
  s21::vector<std::pair<map_iterator, bool>> insert_many(args &&...args_);
  void erase(map_iterator pos);

 private:
  map_iterator find(const key &tree_key);
};

}  // namespace s21
#include "s21_map.tpp"
#endif