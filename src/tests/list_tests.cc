
#include "global_tests.h"
#include <iostream>
#include <list>
#include <string>
// #include "../containers/list/s21_list.h"

// Тест для функции insert_many
TEST(ListTest, InsertMany) {
  // Создаём экземпляр списка s21::list<int>
  s21::list<int> s21_list;

  // Вставляем элементы с помощью insert_many
  s21_list.insert_many(s21_list.begin(), 1, 2, 3, 4, 5);

  // Создаём ожидаемый список (используем стандартный список для сравнения)
  std::list<int> expected_list = {1, 2, 3, 4, 5};

  // Итерируем по обоим спискам, чтобы проверить их элементы
  auto s21_iter = s21_list.begin();
  auto std_iter = expected_list.begin();

  // Сравниваем элементы обоих списков
  for (; s21_iter != s21_list.end(); ++s21_iter, ++std_iter) {
    EXPECT_EQ(*s21_iter, *std_iter);
  }
}

// Тест для функции insert_many_back
TEST(ListTest, InsertManyBack) {
  // Создаём экземпляр списка s21::list<int>
  s21::list<int> s21_list;

  // Вставляем элементы в конец списка с помощью insert_many_back
  s21_list.insert_many_back(1, 2, 3, 4, 5);

  // Создаём ожидаемый список (используем стандартный список для сравнения)
  std::list<int> expected_list = {1, 2, 3, 4, 5};

  // Итерируем по обоим спискам, чтобы проверить их элементы
  auto s21_iter = s21_list.begin();
  auto std_iter = expected_list.begin();

  // Сравниваем элементы обоих списков
  for (; s21_iter != s21_list.end(); ++s21_iter, ++std_iter) {
    EXPECT_EQ(*s21_iter, *std_iter);
  }
}

TEST(list_test, constructor_default) {
  s21::list<int> s21_list;
  std::list<int> std_list;
  EXPECT_EQ(s21_list.empty(), std_list.empty());
}

TEST(list_test, constructor_with_size) {
  s21::list<int> s21_list(5);
  std::list<int> std_list(5);
  EXPECT_EQ(s21_list.empty(), std_list.empty());
  EXPECT_EQ(s21_list.size(), std_list.size());
}

TEST(list_test, constructor_with_size_throw) {}

TEST(list_test, init_constructor) {
  s21::list<int> s21_list{1, 2, 3, 4, 5, 6};
  std::list<int> std_list{1, 2, 3, 4, 5, 6};
  EXPECT_EQ(s21_list.size(), std_list.size());
  auto s21_iterator = s21_list.begin();
  auto std_iterator = std_list.begin();
  bool result = true;
  for (size_t i = 0; i < s21_list.size(); i++) {
    if (*s21_iterator != *std_iterator) {
      result = false;
      break;
    }
    s21_iterator++;
    std_iterator++;
  }
  EXPECT_TRUE(result);
}

TEST(list_test, copy_constructor) {
  s21::list<int> s21_list{1, 2, 3, 4, 5};
  std::list<int> std_list{1, 2, 3, 4, 5};
  s21::list<int> s21_copy(s21_list);
  std::list<int> std_copy(std_list);
  EXPECT_EQ(s21_copy.size(), std_copy.size());
  auto s21_iterator = s21_copy.begin();
  auto std_iterator = std_copy.begin();
  bool result = true;
  for (size_t i = 0; i < s21_copy.size(); i++) {
    if (*s21_iterator != *std_iterator) {
      result = false;
      break;
    }
    s21_iterator++;
    std_iterator++;
  }
  EXPECT_TRUE(result);
}

TEST(list_test, copy_constructor_empty) {
  s21::list<int> s21_list;
  s21::list<int> s21_copy(s21_list);
  std::list<int> std_list;
  std::list<int> std_copy(std_list);
  EXPECT_EQ(s21_copy.size(), std_copy.size());
  auto s21_iterator = s21_copy.begin();
  auto std_iterator = std_copy.begin();
  bool result = true;
  for (size_t i = 0; i < s21_copy.size(); i++) {
    if (*s21_iterator != *std_iterator) {
      result = false;
      break;
    }
    s21_iterator++;
    std_iterator++;
  }
  EXPECT_TRUE(result);
}

TEST(list_test, move_constructor_empty) {
  s21::list<int> s21_list;
  s21::list<int> s21_copy(s21_list);
  s21::list<int> s21_move(std::move(s21_list));
  std::list<int> std_list;
  std::list<int> std_copy(std_list);
  std::list<int> std_move(std::move(std_list));
  EXPECT_EQ(s21_move.size(), std_move.size());
  auto s21_iterator = s21_move.begin();
  auto std_iterator = std_move.begin();
  bool result = true;
  for (size_t i = 0; i < s21_move.size(); i++) {
    if (*s21_iterator != *std_iterator) {
      result = false;
      break;
    }
    s21_iterator++;
    std_iterator++;
  }
  EXPECT_TRUE(result);
}

TEST(list_test, front) {
  s21::list<int> s21_list{462, 32, 3, 4, 5};
  std::list<int> std_list{462, 32, 3, 4, 5};
  EXPECT_EQ(s21_list.front(), std_list.front());
}

TEST(list_test, back) {
  s21::list<int> s21_list{462, 32, 3, 4, 5};
  std::list<int> std_list{462, 32, 3, 4, 5};
  EXPECT_EQ(s21_list.back(), std_list.back());
}

TEST(list_test, begin) {
  s21::list<int> s21_list{5, 6, 2};
  std::list<int> std_list{5, 6, 2};
  EXPECT_EQ(*s21_list.begin(), *std_list.begin());
}

TEST(list_test, begin_throw) {
  s21::list<int> s21_list;
  std::list<int> std_list;
  EXPECT_EQ(*s21_list.begin(), 0);
}

TEST(list_test, end) {
  s21::list<int> s21_list{5, 6, 2};
  std::list<int> std_list{5, 6, 2};
  EXPECT_EQ(*s21_list.end(), *std_list.end());
}

TEST(list_test, end_empty) {
  s21::list<int> s21_list;
  std::list<int> std_list;
  EXPECT_EQ(*s21_list.end(), *std_list.end());
}

TEST(list_test, empty) {
  s21::list<int> s21_list;
  std::list<int> std_list;
  EXPECT_EQ(s21_list.empty(), std_list.empty());
}

TEST(list_test, not_empty) {
  s21::list<int> s21_list{1, 22};
  std::list<int> std_list{1, 22};
  EXPECT_EQ(s21_list.empty(), std_list.empty());
}

TEST(list_test, clear) {
  s21::list<int> s21_list{1, 2, 3, 4, 5};
  std::list<int> std_list{1, 2, 3, 4, 5};
  s21_list.clear();
  std_list.clear();
  EXPECT_EQ(s21_list.size(), std_list.size());
  auto s21_iterator = s21_list.begin();
  auto std_iterator = std_list.begin();
  bool result = true;
  for (size_t i = 0; i < s21_list.size(); i++) {
    if (*s21_iterator != *std_iterator) {
      result = false;
      break;
    }
    s21_iterator++;
    std_iterator++;
  }
  EXPECT_TRUE(result);
}

TEST(list_test, insert_begin) {
  s21::list<int> s21_list{1, 9999, 20000};
  s21_list.insert(s21_list.begin(), 5);
  std::list<int> std_list{1, 9999, 20000};
  std_list.insert(std_list.begin(), 5);
  EXPECT_EQ(s21_list.size(), std_list.size());
  auto s21_iterator = s21_list.begin();
  auto std_iterator = std_list.begin();
  bool result = true;
  for (size_t i = 0; i < s21_list.size(); i++) {
    if (*s21_iterator != *std_iterator) {
      result = false;
      break;
    }
    s21_iterator++;
    std_iterator++;
  }
  EXPECT_TRUE(result);
}

TEST(list_test, insert_end) {
  s21::list<int> s21_list{1, 2, 3};
  s21_list.insert(s21_list.end(), 5);
  std::list<int> std_list{1, 2, 3};
  std_list.insert(std_list.end(), 5);
  EXPECT_EQ(s21_list.size(), std_list.size());
  auto s21_iterator = s21_list.begin();
  auto std_iterator = std_list.begin();
  bool result = true;
  for (size_t i = 0; i < s21_list.size(); i++) {
    if (*s21_iterator != *std_iterator) {
      result = false;
      break;
    }
    s21_iterator++;
    std_iterator++;
  }
  EXPECT_TRUE(result);
}

TEST(list_test, insert_random) {
  s21::list<int> s21_list{1, 2, 3};
  s21_list.insert(s21_list[2], 5);
  std::list<int> std_list{1, 2, 3};
  auto std_temp_iterator = std_list.begin();
  std_temp_iterator++;
  std_temp_iterator++;
  std_list.insert(std_temp_iterator, 5);
  EXPECT_EQ(s21_list.size(), std_list.size());
  auto s21_iterator = s21_list.begin();
  auto std_iterator = std_list.begin();
  bool result = true;
  for (size_t i = 0; i < s21_list.size(); i++) {
    if (*s21_iterator != *std_iterator) {
      result = false;
      break;
    }
    s21_iterator++;
    std_iterator++;
  }
  EXPECT_TRUE(result);
}

TEST(list_test, insert_empty) {
  s21::list<int> s21_list;
  s21_list.insert(s21_list.begin(), 5);
  std::list<int> std_list;
  std_list.insert(std_list.begin(), 5);
  EXPECT_EQ(s21_list.size(), std_list.size());
  auto s21_iterator = s21_list.begin();
  auto std_iterator = std_list.begin();
  bool result = true;
  for (size_t i = 0; i < s21_list.size(); i++) {
    if (*s21_iterator != *std_iterator) {
      result = false;
      break;
    }
    s21_iterator++;
    std_iterator++;
  }
  EXPECT_TRUE(result);
}

TEST(list_test, erase_begin) {
  s21::list<int> s21_list{1, 2, 3};
  s21_list.erase(s21_list.begin());
  std::list<int> std_list{1, 2, 3};
  std_list.erase(std_list.begin());
  EXPECT_EQ(s21_list.size(), std_list.size());
  auto s21_iterator = s21_list.begin();
  auto std_iterator = std_list.begin();
  bool result = true;
  for (size_t i = 0; i < s21_list.size(); i++) {
    if (*s21_iterator != *std_iterator) {
      result = false;
      break;
    }
    s21_iterator++;
    std_iterator++;
  }
  EXPECT_TRUE(result);
}

TEST(list_test, erase_throw) {
  s21::list<int> s21_list{1, 2, 3};
  EXPECT_THROW(s21_list.erase(s21_list.end()), std::invalid_argument);
}

TEST(list_test, erase_end) {
  s21::list<int> s21_list{1, 2, 3};
  s21_list.erase(--s21_list.end());
  std::list<int> std_list{1, 2, 3};
  std_list.erase(std_list.end().operator--());
  EXPECT_EQ(s21_list.size(), std_list.size());
  auto s21_iterator = s21_list.begin();
  auto std_iterator = std_list.begin();
  bool result = true;
  for (size_t i = 0; i < s21_list.size(); i++) {
    if (*s21_iterator != *std_iterator) {
      result = false;
      break;
    }
    s21_iterator++;
    std_iterator++;
  }
  EXPECT_TRUE(result);
}

TEST(list_test, erase_throw_end) {
  s21::list<int> s21_list;
  EXPECT_THROW(s21_list.erase(s21_list.end()--), std::invalid_argument);
}

TEST(list_test, erase_enother_end) {
  s21::list<int> s21_list(5);
  s21_list.erase(--s21_list.end());
  std::list<int> std_list(5);
  std_list.erase(std_list.end().operator--());
  EXPECT_EQ(s21_list.size(), std_list.size());
  auto s21_iterator = s21_list.begin();
  auto std_iterator = std_list.begin();
  bool result = true;
  for (size_t i = 0; i < s21_list.size(); i++) {
    if (*s21_iterator != *std_iterator) {
      result = false;
      break;
    }
    s21_iterator++;
    std_iterator++;
  }
  EXPECT_TRUE(result);
}

TEST(list_test, merge) {
  s21::list<int> s21_this{1, 46, 234};
  s21::list<int> s21_other{50, 357, 6028};
  s21_this.merge(s21_other);
  std::list<int> std_this{1, 46, 234};
  std::list<int> std_other{50, 357, 6028};
  std_this.merge(std_other);
  auto s21_iterator = s21_this.begin();
  auto std_iterator = std_this.begin();
  bool result = true;
  EXPECT_EQ(s21_this.size(), std_this.size());
  for (size_t i = 0; i < s21_this.size(); i++) {
    if (*s21_iterator != *std_iterator) {
      result = false;
      break;
    }
    s21_iterator++;
    std_iterator++;
  }
  EXPECT_TRUE(result);
}

TEST(list_test, merge_different_size) {
  s21::list<int> s21_this{1, 2, 234};
  s21::list<int> s21_other{7584, 154, 453, 9876};
  s21_this.merge(s21_other);
  std::list<int> std_this{1, 2, 234};
  std::list<int> std_other{7584, 154, 453, 9876};
  std_this.merge(std_other);
  auto s21_iterator = s21_this.begin();
  auto std_iterator = std_this.begin();
  bool result = true;
  EXPECT_EQ(s21_this.size(), std_this.size());
  for (size_t i = 0; i < s21_this.size(); i++) {
    if (*s21_iterator != *std_iterator) {
      result = false;
      break;
    }
    s21_iterator++;
    std_iterator++;
  }
  EXPECT_TRUE(result);
}

TEST(list_test, merge_with_this_empty) {
  s21::list<int> s21_this;
  s21::list<int> s21_other{7584, 154, 453, 9876};
  s21_this.merge(s21_other);
  std::list<int> std_this;
  std::list<int> std_other{7584, 154, 453, 9876};
  std_this.merge(std_other);
  auto s21_iterator = s21_this.begin();
  auto std_iterator = std_this.begin();
  bool result = true;
  EXPECT_EQ(s21_this.size(), std_this.size());
  for (size_t i = 0; i < s21_this.size(); i++) {
    if (*s21_iterator != *std_iterator) {
      result = false;
      break;
    }
    s21_iterator++;
    std_iterator++;
  }
  EXPECT_TRUE(result);
}

TEST(list_test, merge_with_other_empty) {
  s21::list<int> s21_this{7584, 154, 453, 9876};
  s21::list<int> s21_other;
  s21_this.merge(s21_other);
  std::list<int> std_this{7584, 154, 453, 9876};
  std::list<int> std_other;
  std_this.merge(std_other);
  auto s21_iterator = s21_this.begin();
  auto std_iterator = std_this.begin();
  bool result = true;
  EXPECT_EQ(s21_this.size(), std_this.size());
  for (size_t i = 0; i < s21_this.size(); i++) {
    if (*s21_iterator != *std_iterator) {
      result = false;
      break;
    }
    s21_iterator++;
    std_iterator++;
  }
  EXPECT_TRUE(result);
}

TEST(list_test, merge_empty) {
  s21::list<int> s21_this;
  s21::list<int> s21_other;
  s21_this.merge(s21_other);
  std::list<int> std_this;
  std::list<int> std_other;
  std_this.merge(std_other);
  auto s21_iterator = s21_this.begin();
  auto std_iterator = std_this.begin();
  bool result = true;
  EXPECT_EQ(s21_this.size(), std_this.size());
  for (size_t i = 0; i < s21_this.size(); i++) {
    if (*s21_iterator != *std_iterator) {
      result = false;
      break;
    }
    s21_iterator++;
    std_iterator++;
  }
  EXPECT_TRUE(result);
}

TEST(list_test, splice) {
  s21::list<int> s21_this{1, 2, 234};
  s21::list<int> s21_other{7584, 154, 453, 9876};
  s21_this.splice(s21_this.begin(), s21_other);
  std::list<int> std_this{1, 2, 234};
  std::list<int> std_other{7584, 154, 453, 9876};
  std_this.splice(std_this.begin(), std_other);
  auto s21_iterator = s21_this.begin();
  auto std_iterator = std_this.begin();
  bool result = true;
  EXPECT_EQ(s21_this.size(), std_this.size());
  for (size_t i = 0; i < s21_this.size(); i++) {
    if (*s21_iterator != *std_iterator) {
      result = false;
      break;
    }
    s21_iterator++;
    std_iterator++;
  }
  EXPECT_TRUE(result);
}

TEST(list_test, splice_this_empty) {
  s21::list<int> s21_this;
  s21::list<int> s21_other{7584, 154, 453, 9876};
  s21_this.splice(s21_this.begin(), s21_other);
  std::list<int> std_this;
  std::list<int> std_other{7584, 154, 453, 9876};
  std_this.splice(std_this.begin(), std_other);
  auto s21_iterator = s21_this.begin();
  auto std_iterator = std_this.begin();
  bool result = true;
  EXPECT_EQ(s21_this.size(), std_this.size());
  for (size_t i = 0; i < s21_this.size(); i++) {
    if (*s21_iterator != *std_iterator) {
      result = false;
      break;
    }
    s21_iterator++;
    std_iterator++;
  }
  EXPECT_TRUE(result);
}

TEST(list_test, splice_other_empty) {
  s21::list<int> s21_this{1, 2, 234};
  s21::list<int> s21_other;
  s21_this.splice(s21_this.begin(), s21_other);
  std::list<int> std_this{1, 2, 234};
  std::list<int> std_other;
  std_this.splice(std_this.begin(), std_other);
  auto s21_iterator = s21_this.begin();
  auto std_iterator = std_this.begin();
  bool result = true;
  EXPECT_EQ(s21_this.size(), std_this.size());
  for (size_t i = 0; i < s21_this.size(); i++) {
    if (*s21_iterator != *std_iterator) {
      result = false;
      break;
    }
    s21_iterator++;
    std_iterator++;
  }
  EXPECT_TRUE(result);
}

TEST(list_test, splice_empty) {
  s21::list<int> s21_this;
  s21::list<int> s21_other;
  s21_this.splice(s21_this.begin(), s21_other);
  std::list<int> std_this;
  std::list<int> std_other;
  std_this.splice(std_this.begin(), std_other);
  auto s21_iterator = s21_this.begin();
  auto std_iterator = std_this.begin();
  bool result = true;
  EXPECT_EQ(s21_this.size(), std_this.size());
  for (size_t i = 0; i < s21_this.size(); i++) {
    if (*s21_iterator != *std_iterator) {
      result = false;
      break;
    }
    s21_iterator++;
    std_iterator++;
  }
  EXPECT_TRUE(result);
}

TEST(list_test, reverse) {
  s21::list<int> s21_list = {1, 2, 3, 4, 5, 6};
  std::list<int> std_list = {1, 2, 3, 4, 5, 6};
  s21_list.reverse();
  std_list.reverse();
  auto s21_iterator = s21_list.begin();
  auto std_iterator = std_list.begin();
  bool result = true;
  for (size_t i = 0; i < s21_list.size(); i++) {
    if (*s21_iterator != *std_iterator) {
      result = false;
      break;
    }
    s21_iterator++;
    std_iterator++;
  }
  EXPECT_TRUE(result);
}

TEST(list_test, reverse_empty) {
  s21::list<int> s21_list;
  std::list<int> std_list;
  s21_list.reverse();
  std_list.reverse();
  auto s21_iterator = s21_list.begin();
  auto std_iterator = std_list.begin();
  bool result = true;
  for (size_t i = 0; i < s21_list.size(); i++) {
    if (*s21_iterator != *std_iterator) {
      result = false;
      break;
    }
    s21_iterator++;
    std_iterator++;
  }
  EXPECT_TRUE(result);
}

TEST(list_test, sort) {
  s21::list<int> s21_list{4, 2, 5, 1, 9, 10, 25, 392, 5};
  std::list<int> std_list{4, 2, 5, 1, 9, 10, 25, 392, 5};
  s21_list.sort();
  std_list.sort();
  auto s21_iterator = s21_list.begin();
  auto std_iterator = std_list.begin();
  bool result = true;
  for (size_t i = 0; i < s21_list.size(); i++) {
    if (*s21_iterator != *std_iterator) {
      result = false;
      break;
    }
    s21_iterator++;
    std_iterator++;
  }
  EXPECT_TRUE(result);
}

