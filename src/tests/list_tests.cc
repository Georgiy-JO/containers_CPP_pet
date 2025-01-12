
#include <iostream>
#include <list>
#include <string>

#include "global_tests.h"
// #include "../containers/list/list.h"

// Тест для функции insert_many
TEST(ListTest, InsertMany) {
  // Создаём экземпляр списка my_containers::list<int>
  my_containers::list<int> my_list;

  // Вставляем элементы с помощью insert_many
  my_list.insert_many(my_list.begin(), 1, 2, 3, 4, 5);

  // Создаём ожидаемый список (используем стандартный список для сравнения)
  std::list<int> expected_list = {1, 2, 3, 4, 5};

  // Итерируем по обоим спискам, чтобы проверить их элементы
  auto my_iter = my_list.begin();
  auto std_iter = expected_list.begin();

  // Сравниваем элементы обоих списков
  for (; my_iter != my_list.end(); ++my_iter, ++std_iter) {
    EXPECT_EQ(*my_iter, *std_iter);
  }
}

// Тест для функции insert_many_back
TEST(ListTest, InsertManyBack) {
  // Создаём экземпляр списка my_containers::list<int>
  my_containers::list<int> my_list;

  // Вставляем элементы в конец списка с помощью insert_many_back
  my_list.insert_many_back(1, 2, 3, 4, 5);

  // Создаём ожидаемый список (используем стандартный список для сравнения)
  std::list<int> expected_list = {1, 2, 3, 4, 5};

  // Итерируем по обоим спискам, чтобы проверить их элементы
  auto my_iter = my_list.begin();
  auto std_iter = expected_list.begin();

  // Сравниваем элементы обоих списков
  for (; my_iter != my_list.end(); ++my_iter, ++std_iter) {
    EXPECT_EQ(*my_iter, *std_iter);
  }
}

TEST(list_test, constructor_default) {
  my_containers::list<int> my_list;
  std::list<int> std_list;
  EXPECT_EQ(my_list.empty(), std_list.empty());
}

TEST(list_test, constructor_with_size) {
  my_containers::list<int> my_list(5);
  std::list<int> std_list(5);
  EXPECT_EQ(my_list.empty(), std_list.empty());
  EXPECT_EQ(my_list.size(), std_list.size());
}

TEST(list_test, constructor_with_size_throw) {}

TEST(list_test, init_constructor) {
  my_containers::list<int> my_list{1, 2, 3, 4, 5, 6};
  std::list<int> std_list{1, 2, 3, 4, 5, 6};
  EXPECT_EQ(my_list.size(), std_list.size());
  auto my_iterator = my_list.begin();
  auto std_iterator = std_list.begin();
  bool result = true;
  for (size_t i = 0; i < my_list.size(); i++) {
    if (*my_iterator != *std_iterator) {
      result = false;
      break;
    }
    my_iterator++;
    std_iterator++;
  }
  EXPECT_TRUE(result);
}

TEST(list_test, copy_constructor) {
  my_containers::list<int> my_list{1, 2, 3, 4, 5};
  std::list<int> std_list{1, 2, 3, 4, 5};
  my_containers::list<int> my_copy(my_list);
  std::list<int> std_copy(std_list);
  EXPECT_EQ(my_copy.size(), std_copy.size());
  auto my_iterator = my_copy.begin();
  auto std_iterator = std_copy.begin();
  bool result = true;
  for (size_t i = 0; i < my_copy.size(); i++) {
    if (*my_iterator != *std_iterator) {
      result = false;
      break;
    }
    my_iterator++;
    std_iterator++;
  }
  EXPECT_TRUE(result);
}

TEST(list_test, copy_constructor_empty) {
  my_containers::list<int> my_list;
  my_containers::list<int> my_copy(my_list);
  std::list<int> std_list;
  std::list<int> std_copy(std_list);
  EXPECT_EQ(my_copy.size(), std_copy.size());
  auto my_iterator = my_copy.begin();
  auto std_iterator = std_copy.begin();
  bool result = true;
  for (size_t i = 0; i < my_copy.size(); i++) {
    if (*my_iterator != *std_iterator) {
      result = false;
      break;
    }
    my_iterator++;
    std_iterator++;
  }
  EXPECT_TRUE(result);
}

TEST(list_test, move_constructor_empty) {
  my_containers::list<int> my_list;
  my_containers::list<int> my_copy(my_list);
  my_containers::list<int> my_move(std::move(my_list));
  std::list<int> std_list;
  std::list<int> std_copy(std_list);
  std::list<int> std_move(std::move(std_list));
  EXPECT_EQ(my_move.size(), std_move.size());
  auto my_iterator = my_move.begin();
  auto std_iterator = std_move.begin();
  bool result = true;
  for (size_t i = 0; i < my_move.size(); i++) {
    if (*my_iterator != *std_iterator) {
      result = false;
      break;
    }
    my_iterator++;
    std_iterator++;
  }
  EXPECT_TRUE(result);
}

TEST(list_test, front) {
  my_containers::list<int> my_list{462, 32, 3, 4, 5};
  std::list<int> std_list{462, 32, 3, 4, 5};
  EXPECT_EQ(my_list.front(), std_list.front());
}

TEST(list_test, back) {
  my_containers::list<int> my_list{462, 32, 3, 4, 5};
  std::list<int> std_list{462, 32, 3, 4, 5};
  EXPECT_EQ(my_list.back(), std_list.back());
}

TEST(list_test, begin) {
  my_containers::list<int> my_list{5, 6, 2};
  std::list<int> std_list{5, 6, 2};
  EXPECT_EQ(*my_list.begin(), *std_list.begin());
}

TEST(list_test, begin_throw) {
  my_containers::list<int> my_list;
  std::list<int> std_list;
  EXPECT_EQ(*my_list.begin(), 0);
}

TEST(list_test, end) {
  my_containers::list<int> my_list{5, 6, 2};
  std::list<int> std_list{5, 6, 2};
  EXPECT_EQ(*my_list.end(), *std_list.end());
}

TEST(list_test, end_empty) {
  my_containers::list<int> my_list;
  std::list<int> std_list;
  EXPECT_EQ(*my_list.end(), *std_list.end());
}

TEST(list_test, empty) {
  my_containers::list<int> my_list;
  std::list<int> std_list;
  EXPECT_EQ(my_list.empty(), std_list.empty());
}

TEST(list_test, not_empty) {
  my_containers::list<int> my_list{1, 22};
  std::list<int> std_list{1, 22};
  EXPECT_EQ(my_list.empty(), std_list.empty());
}

TEST(list_test, clear) {
  my_containers::list<int> my_list{1, 2, 3, 4, 5};
  std::list<int> std_list{1, 2, 3, 4, 5};
  my_list.clear();
  std_list.clear();
  EXPECT_EQ(my_list.size(), std_list.size());
  auto my_iterator = my_list.begin();
  auto std_iterator = std_list.begin();
  bool result = true;
  for (size_t i = 0; i < my_list.size(); i++) {
    if (*my_iterator != *std_iterator) {
      result = false;
      break;
    }
    my_iterator++;
    std_iterator++;
  }
  EXPECT_TRUE(result);
}

TEST(list_test, insert_begin) {
  my_containers::list<int> my_list{1, 9999, 20000};
  my_list.insert(my_list.begin(), 5);
  std::list<int> std_list{1, 9999, 20000};
  std_list.insert(std_list.begin(), 5);
  EXPECT_EQ(my_list.size(), std_list.size());
  auto my_iterator = my_list.begin();
  auto std_iterator = std_list.begin();
  bool result = true;
  for (size_t i = 0; i < my_list.size(); i++) {
    if (*my_iterator != *std_iterator) {
      result = false;
      break;
    }
    my_iterator++;
    std_iterator++;
  }
  EXPECT_TRUE(result);
}

TEST(list_test, insert_end) {
  my_containers::list<int> my_list{1, 2, 3};
  my_list.insert(my_list.end(), 5);
  std::list<int> std_list{1, 2, 3};
  std_list.insert(std_list.end(), 5);
  EXPECT_EQ(my_list.size(), std_list.size());
  auto my_iterator = my_list.begin();
  auto std_iterator = std_list.begin();
  bool result = true;
  for (size_t i = 0; i < my_list.size(); i++) {
    if (*my_iterator != *std_iterator) {
      result = false;
      break;
    }
    my_iterator++;
    std_iterator++;
  }
  EXPECT_TRUE(result);
}

TEST(list_test, insert_random) {
  my_containers::list<int> my_list{1, 2, 3};
  my_list.insert(my_list[2], 5);
  std::list<int> std_list{1, 2, 3};
  auto std_temp_iterator = std_list.begin();
  std_temp_iterator++;
  std_temp_iterator++;
  std_list.insert(std_temp_iterator, 5);
  EXPECT_EQ(my_list.size(), std_list.size());
  auto my_iterator = my_list.begin();
  auto std_iterator = std_list.begin();
  bool result = true;
  for (size_t i = 0; i < my_list.size(); i++) {
    if (*my_iterator != *std_iterator) {
      result = false;
      break;
    }
    my_iterator++;
    std_iterator++;
  }
  EXPECT_TRUE(result);
}

TEST(list_test, insert_empty) {
  my_containers::list<int> my_list;
  my_list.insert(my_list.begin(), 5);
  std::list<int> std_list;
  std_list.insert(std_list.begin(), 5);
  EXPECT_EQ(my_list.size(), std_list.size());
  auto my_iterator = my_list.begin();
  auto std_iterator = std_list.begin();
  bool result = true;
  for (size_t i = 0; i < my_list.size(); i++) {
    if (*my_iterator != *std_iterator) {
      result = false;
      break;
    }
    my_iterator++;
    std_iterator++;
  }
  EXPECT_TRUE(result);
}

TEST(list_test, erase_begin) {
  my_containers::list<int> my_list{1, 2, 3};
  my_list.erase(my_list.begin());
  std::list<int> std_list{1, 2, 3};
  std_list.erase(std_list.begin());
  EXPECT_EQ(my_list.size(), std_list.size());
  auto my_iterator = my_list.begin();
  auto std_iterator = std_list.begin();
  bool result = true;
  for (size_t i = 0; i < my_list.size(); i++) {
    if (*my_iterator != *std_iterator) {
      result = false;
      break;
    }
    my_iterator++;
    std_iterator++;
  }
  EXPECT_TRUE(result);
}

TEST(list_test, erase_throw) {
  my_containers::list<int> my_list{1, 2, 3};
  EXPECT_THROW(my_list.erase(my_list.end()), std::invalid_argument);
}

TEST(list_test, erase_end) {
  my_containers::list<int> my_list{1, 2, 3};
  my_list.erase(--my_list.end());
  std::list<int> std_list{1, 2, 3};
  std_list.erase(std_list.end().operator--());
  EXPECT_EQ(my_list.size(), std_list.size());
  auto my_iterator = my_list.begin();
  auto std_iterator = std_list.begin();
  bool result = true;
  for (size_t i = 0; i < my_list.size(); i++) {
    if (*my_iterator != *std_iterator) {
      result = false;
      break;
    }
    my_iterator++;
    std_iterator++;
  }
  EXPECT_TRUE(result);
}

TEST(list_test, erase_throw_end) {
  my_containers::list<int> my_list;
  EXPECT_THROW(my_list.erase(my_list.end()--), std::invalid_argument);
}

TEST(list_test, erase_enother_end) {
  my_containers::list<int> my_list(5);
  my_list.erase(--my_list.end());
  std::list<int> std_list(5);
  std_list.erase(std_list.end().operator--());
  EXPECT_EQ(my_list.size(), std_list.size());
  auto my_iterator = my_list.begin();
  auto std_iterator = std_list.begin();
  bool result = true;
  for (size_t i = 0; i < my_list.size(); i++) {
    if (*my_iterator != *std_iterator) {
      result = false;
      break;
    }
    my_iterator++;
    std_iterator++;
  }
  EXPECT_TRUE(result);
}

TEST(list_test, merge) {
  my_containers::list<int> my_this{1, 46, 234};
  my_containers::list<int> my_other{50, 357, 6028};
  my_this.merge(my_other);
  std::list<int> std_this{1, 46, 234};
  std::list<int> std_other{50, 357, 6028};
  std_this.merge(std_other);
  auto my_iterator = my_this.begin();
  auto std_iterator = std_this.begin();
  bool result = true;
  EXPECT_EQ(my_this.size(), std_this.size());
  for (size_t i = 0; i < my_this.size(); i++) {
    if (*my_iterator != *std_iterator) {
      result = false;
      break;
    }
    my_iterator++;
    std_iterator++;
  }
  EXPECT_TRUE(result);
}

TEST(list_test, merge_different_size) {
  my_containers::list<int> my_this{1, 2, 234};
  my_containers::list<int> my_other{7584, 154, 453, 9876};
  my_this.merge(my_other);
  std::list<int> std_this{1, 2, 234};
  std::list<int> std_other{7584, 154, 453, 9876};
  std_this.merge(std_other);
  auto my_iterator = my_this.begin();
  auto std_iterator = std_this.begin();
  bool result = true;
  EXPECT_EQ(my_this.size(), std_this.size());
  for (size_t i = 0; i < my_this.size(); i++) {
    if (*my_iterator != *std_iterator) {
      result = false;
      break;
    }
    my_iterator++;
    std_iterator++;
  }
  EXPECT_TRUE(result);
}

TEST(list_test, merge_with_this_empty) {
  my_containers::list<int> my_this;
  my_containers::list<int> my_other{7584, 154, 453, 9876};
  my_this.merge(my_other);
  std::list<int> std_this;
  std::list<int> std_other{7584, 154, 453, 9876};
  std_this.merge(std_other);
  auto my_iterator = my_this.begin();
  auto std_iterator = std_this.begin();
  bool result = true;
  EXPECT_EQ(my_this.size(), std_this.size());
  for (size_t i = 0; i < my_this.size(); i++) {
    if (*my_iterator != *std_iterator) {
      result = false;
      break;
    }
    my_iterator++;
    std_iterator++;
  }
  EXPECT_TRUE(result);
}

TEST(list_test, merge_with_other_empty) {
  my_containers::list<int> my_this{7584, 154, 453, 9876};
  my_containers::list<int> my_other;
  my_this.merge(my_other);
  std::list<int> std_this{7584, 154, 453, 9876};
  std::list<int> std_other;
  std_this.merge(std_other);
  auto my_iterator = my_this.begin();
  auto std_iterator = std_this.begin();
  bool result = true;
  EXPECT_EQ(my_this.size(), std_this.size());
  for (size_t i = 0; i < my_this.size(); i++) {
    if (*my_iterator != *std_iterator) {
      result = false;
      break;
    }
    my_iterator++;
    std_iterator++;
  }
  EXPECT_TRUE(result);
}

TEST(list_test, merge_empty) {
  my_containers::list<int> my_this;
  my_containers::list<int> my_other;
  my_this.merge(my_other);
  std::list<int> std_this;
  std::list<int> std_other;
  std_this.merge(std_other);
  auto my_iterator = my_this.begin();
  auto std_iterator = std_this.begin();
  bool result = true;
  EXPECT_EQ(my_this.size(), std_this.size());
  for (size_t i = 0; i < my_this.size(); i++) {
    if (*my_iterator != *std_iterator) {
      result = false;
      break;
    }
    my_iterator++;
    std_iterator++;
  }
  EXPECT_TRUE(result);
}

TEST(list_test, splice) {
  my_containers::list<int> my_this{1, 2, 234};
  my_containers::list<int> my_other{7584, 154, 453, 9876};
  my_this.splice(my_this.begin(), my_other);
  std::list<int> std_this{1, 2, 234};
  std::list<int> std_other{7584, 154, 453, 9876};
  std_this.splice(std_this.begin(), std_other);
  auto my_iterator = my_this.begin();
  auto std_iterator = std_this.begin();
  bool result = true;
  EXPECT_EQ(my_this.size(), std_this.size());
  for (size_t i = 0; i < my_this.size(); i++) {
    if (*my_iterator != *std_iterator) {
      result = false;
      break;
    }
    my_iterator++;
    std_iterator++;
  }
  EXPECT_TRUE(result);
}

TEST(list_test, splice_this_empty) {
  my_containers::list<int> my_this;
  my_containers::list<int> my_other{7584, 154, 453, 9876};
  my_this.splice(my_this.begin(), my_other);
  std::list<int> std_this;
  std::list<int> std_other{7584, 154, 453, 9876};
  std_this.splice(std_this.begin(), std_other);
  auto my_iterator = my_this.begin();
  auto std_iterator = std_this.begin();
  bool result = true;
  EXPECT_EQ(my_this.size(), std_this.size());
  for (size_t i = 0; i < my_this.size(); i++) {
    if (*my_iterator != *std_iterator) {
      result = false;
      break;
    }
    my_iterator++;
    std_iterator++;
  }
  EXPECT_TRUE(result);
}

TEST(list_test, splice_other_empty) {
  my_containers::list<int> my_this{1, 2, 234};
  my_containers::list<int> my_other;
  my_this.splice(my_this.begin(), my_other);
  std::list<int> std_this{1, 2, 234};
  std::list<int> std_other;
  std_this.splice(std_this.begin(), std_other);
  auto my_iterator = my_this.begin();
  auto std_iterator = std_this.begin();
  bool result = true;
  EXPECT_EQ(my_this.size(), std_this.size());
  for (size_t i = 0; i < my_this.size(); i++) {
    if (*my_iterator != *std_iterator) {
      result = false;
      break;
    }
    my_iterator++;
    std_iterator++;
  }
  EXPECT_TRUE(result);
}

TEST(list_test, splice_empty) {
  my_containers::list<int> my_this;
  my_containers::list<int> my_other;
  my_this.splice(my_this.begin(), my_other);
  std::list<int> std_this;
  std::list<int> std_other;
  std_this.splice(std_this.begin(), std_other);
  auto my_iterator = my_this.begin();
  auto std_iterator = std_this.begin();
  bool result = true;
  EXPECT_EQ(my_this.size(), std_this.size());
  for (size_t i = 0; i < my_this.size(); i++) {
    if (*my_iterator != *std_iterator) {
      result = false;
      break;
    }
    my_iterator++;
    std_iterator++;
  }
  EXPECT_TRUE(result);
}

TEST(list_test, reverse) {
  my_containers::list<int> my_list = {1, 2, 3, 4, 5, 6};
  std::list<int> std_list = {1, 2, 3, 4, 5, 6};
  my_list.reverse();
  std_list.reverse();
  auto my_iterator = my_list.begin();
  auto std_iterator = std_list.begin();
  bool result = true;
  for (size_t i = 0; i < my_list.size(); i++) {
    if (*my_iterator != *std_iterator) {
      result = false;
      break;
    }
    my_iterator++;
    std_iterator++;
  }
  EXPECT_TRUE(result);
}

TEST(list_test, reverse_empty) {
  my_containers::list<int> my_list;
  std::list<int> std_list;
  my_list.reverse();
  std_list.reverse();
  auto my_iterator = my_list.begin();
  auto std_iterator = std_list.begin();
  bool result = true;
  for (size_t i = 0; i < my_list.size(); i++) {
    if (*my_iterator != *std_iterator) {
      result = false;
      break;
    }
    my_iterator++;
    std_iterator++;
  }
  EXPECT_TRUE(result);
}

TEST(list_test, sort) {
  my_containers::list<int> my_list{4, 2, 5, 1, 9, 10, 25, 392, 5};
  std::list<int> std_list{4, 2, 5, 1, 9, 10, 25, 392, 5};
  my_list.sort();
  std_list.sort();
  auto my_iterator = my_list.begin();
  auto std_iterator = std_list.begin();
  bool result = true;
  for (size_t i = 0; i < my_list.size(); i++) {
    if (*my_iterator != *std_iterator) {
      result = false;
      break;
    }
    my_iterator++;
    std_iterator++;
  }
  EXPECT_TRUE(result);
}
