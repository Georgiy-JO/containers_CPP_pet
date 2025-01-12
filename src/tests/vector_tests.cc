
#include "global_tests.h"
// #include "../containers/vector/vector.h"
#include <vector>

class MyClass {
 private:
  std::string name_;

 public:
  MyClass() : name_("") {}
  MyClass(const std::string& name) : name_(name) {}
  std::string getName() const { return name_; }
};

// Vector Member functions

TEST(Vector_Member_functions, test_1) {
  my_containers::vector<int> my_Vec;
  std::vector<int> std_Vec;
  EXPECT_EQ(std_Vec.capacity(), my_Vec.capacity());
  EXPECT_EQ(std_Vec.size(), my_Vec.size());
  EXPECT_EQ(std_Vec.data(), my_Vec.data());
  EXPECT_EQ(nullptr, my_Vec.data());
}

TEST(Vector_Member_functions, test_2) {
  size_t size = 10;
  my_containers::vector<int> my_Vec(size);
  std::vector<int> std_Vec(size);
  EXPECT_EQ(std_Vec.capacity(), my_Vec.capacity());
  EXPECT_EQ(std_Vec.capacity(), my_Vec.size());
  for (size_t i = 0; i < size; ++i) {
    EXPECT_EQ(std_Vec[i], my_Vec[i]);
  }
}

TEST(Vector_Member_functions, test_3) {
  my_containers::vector<int> my_Vec = {1, 2, 3, 4, 5};
  std::vector<int> std_Vec = {1, 2, 3, 4, 5};
  EXPECT_EQ(5, my_Vec.capacity());
  EXPECT_EQ(5, my_Vec.size());
  for (size_t i = 0; i < my_Vec.size(); ++i) {
    EXPECT_EQ(i + 1, my_Vec[i]);
  }
  EXPECT_EQ(std_Vec.capacity(), my_Vec.capacity());
  EXPECT_EQ(std_Vec.size(), my_Vec.size());
  for (size_t i = 0; i < my_Vec.size(); ++i) {
    EXPECT_EQ(std_Vec[i], my_Vec[i]);
  }
}

TEST(Vector_Member_functions, test_4) {
  size_t size = 10;
  my_containers::vector<int> my_Vec1(size);
  for (size_t i = 0; i < size; ++i) {
    my_Vec1[i] = i + 1;
  }
  my_containers::vector<int> my_Vec2(my_Vec1);
  EXPECT_EQ(my_Vec1.capacity(), my_Vec2.capacity());
  EXPECT_EQ(my_Vec1.size(), my_Vec2.size());
  for (size_t i = 0; i < size; ++i) {
    EXPECT_EQ(my_Vec1[i], my_Vec2[i]);
  }
}

TEST(Vector_Member_functions, test_5) {
  size_t size = 10;
  my_containers::vector<int> my_Vec1(size);
  for (size_t i = 0; i < size; ++i) {
    my_Vec1[i] = i + 1;
  }
  my_containers::vector<int> my_Vec2 = my_Vec1;
  EXPECT_EQ(my_Vec1.capacity(), my_Vec2.capacity());
  EXPECT_EQ(my_Vec1.size(), my_Vec2.size());
  for (size_t i = 0; i < size; ++i) {
    EXPECT_EQ(my_Vec1[i], my_Vec2[i]);
  }
}

TEST(Vector_Member_functions, test_6) {
  size_t size = 10;
  my_containers::vector<int> my_Vec1(size);
  std::vector<int> std_Vec1(size);
  for (size_t i = 0; i < size; ++i) {
    my_Vec1[i] = i + 1;
    std_Vec1[i] = i + 1;
  }
  my_containers::vector<int> my_Vec2(std::move(my_Vec1));
  EXPECT_EQ(10, my_Vec2.capacity());
  EXPECT_EQ(10, my_Vec2.size());
  for (size_t i = 0; i < size; ++i) {
    EXPECT_EQ(i + 1, my_Vec2[i]);
  }
  EXPECT_EQ(0, my_Vec1.capacity());
  EXPECT_EQ(0, my_Vec1.size());
  EXPECT_EQ(nullptr, my_Vec1.data());
  std::vector<int> std_Vec2(std::move(std_Vec1));
  EXPECT_EQ(std_Vec2.capacity(), my_Vec2.capacity());
  EXPECT_EQ(std_Vec2.size(), my_Vec2.size());
  for (size_t i = 0; i < size; ++i) {
    EXPECT_EQ(std_Vec2[i], my_Vec2[i]);
  }
  EXPECT_EQ(std_Vec1.capacity(), my_Vec1.capacity());
  EXPECT_EQ(std_Vec1.size(), my_Vec1.size());
  EXPECT_EQ(std_Vec1.data(), my_Vec1.data());
}

TEST(Vector_Member_functions, test_7) {
  size_t size = 10;
  my_containers::vector<int> my_Vec1(size);
  std::vector<int> std_Vec1(size);
  for (size_t i = 0; i < size; ++i) {
    my_Vec1[i] = i + 1;
    std_Vec1[i] = i + 1;
  }
  my_containers::vector<int> my_Vec2 = std::move(my_Vec1);
  EXPECT_EQ(10, my_Vec2.capacity());
  EXPECT_EQ(10, my_Vec2.size());
  for (size_t i = 0; i < size; ++i) {
    EXPECT_EQ(i + 1, my_Vec2[i]);
  }
  EXPECT_EQ(0, my_Vec1.capacity());
  EXPECT_EQ(0, my_Vec1.size());
  EXPECT_EQ(nullptr, my_Vec1.data());
  std::vector<int> std_Vec2 = std::move(std_Vec1);
  EXPECT_EQ(std_Vec2.capacity(), my_Vec2.capacity());
  EXPECT_EQ(std_Vec2.size(), my_Vec2.size());
  for (size_t i = 0; i < size; ++i) {
    EXPECT_EQ(std_Vec2[i], my_Vec2[i]);
  }
  EXPECT_EQ(std_Vec1.capacity(), my_Vec1.capacity());
  EXPECT_EQ(std_Vec1.size(), my_Vec1.size());
  EXPECT_EQ(std_Vec1.data(), my_Vec1.data());
}

// Vector Element access

TEST(Vector_Element_access, test_1) {
  my_containers::vector<int> my_Vec = {1, 2, 3, 4, 5};
  std::vector<int> std_Vec = {1, 2, 3, 4, 5};
  for (size_t i = 0; i < my_Vec.size(); ++i) {
    EXPECT_EQ(std_Vec.at(i), my_Vec.at(i));
  }
}

TEST(Vector_Element_access, test_2) {
  my_containers::vector<int> my_Vec = {1, 2, 3, 4, 5};
  std::vector<int> std_Vec = {1, 2, 3, 4, 5};
  for (size_t i = 0; i < my_Vec.size(); ++i) {
    EXPECT_EQ(std_Vec[i], my_Vec[i]);
  }
}

TEST(Vector_Element_access, test_3) {
  my_containers::vector<int> my_Vec = {1, 2, 3, 4, 5};
  std::vector<int> std_Vec = {1, 2, 3, 4, 5};
  EXPECT_EQ(1, my_Vec.front());
  EXPECT_EQ(std_Vec.front(), my_Vec.front());
}

TEST(Vector_Element_access, test_4) {
  my_containers::vector<int> my_Vec = {1, 2, 3, 4, 5};
  std::vector<int> std_Vec = {1, 2, 3, 4, 5};
  EXPECT_EQ(5, my_Vec.back());
  EXPECT_EQ(std_Vec.back(), my_Vec.back());
}

// Vector Iterators

TEST(Vector_Iterators, test_1) {
  my_containers::vector<int> my_Vec = {1, 2, 3, 4, 5};
  std::vector<int> std_Vec = {1, 2, 3, 4, 5};
  EXPECT_EQ(1, *my_Vec.begin());
  EXPECT_EQ(5, *(my_Vec.end() - 1));
  EXPECT_EQ(*std_Vec.begin(), *my_Vec.begin());
  EXPECT_EQ(*(std_Vec.end() - 1), *(my_Vec.end() - 1));
}

// Vector capacity

TEST(Vector_capacity, test_1) {
  my_containers::vector<int> my_Vec;
  std::vector<int> std_Vec;
  EXPECT_EQ(std_Vec.empty(), my_Vec.empty());
  EXPECT_EQ(true, my_Vec.empty());
}

TEST(Vector_capacity, test_2) {
  size_t size = 10;
  my_containers::vector<int> my_Vec(size);
  std::vector<int> std_Vec(size);
  EXPECT_EQ(std_Vec.size(), my_Vec.size());
  EXPECT_EQ(10, my_Vec.size());
}

TEST(Vector_capacity, test_3) {
  my_containers::vector<int> my_Vec;
  std::vector<int> std_Vec;
  EXPECT_EQ(std_Vec.size(), my_Vec.size());
  EXPECT_EQ(0, my_Vec.size());
}

TEST(Vector_capacity, test_4) {
  my_containers::vector<int> my_Vec = {1, 2, 3, 4, 5};
  std::vector<int> std_Vec = {1, 2, 3, 4, 5};
  EXPECT_EQ(my_Vec.max_size(), std_Vec.max_size());
}

TEST(Vector_capacity, test_5) {
  size_t new_size = 10;
  my_containers::vector<int> my_Vec = {1, 2, 3, 4, 5};
  std::vector<int> std_Vec = {1, 2, 3, 4, 5};
  my_Vec.reserve(new_size);
  std_Vec.reserve(new_size);
  EXPECT_EQ(std_Vec.capacity(), my_Vec.capacity());
  EXPECT_EQ(new_size, my_Vec.capacity());
}

TEST(Vector_capacity, test_6) {
  size_t size = 10;
  my_containers::vector<int> my_Vec(size);
  std::vector<int> std_Vec(size);
  EXPECT_EQ(std_Vec.capacity(), my_Vec.capacity());
  EXPECT_EQ(10, my_Vec.capacity());
}

TEST(Vector_capacity, test_7) {
  my_containers::vector<int> my_Vec;
  std::vector<int> std_Vec;
  EXPECT_EQ(std_Vec.capacity(), my_Vec.capacity());
  EXPECT_EQ(0, my_Vec.capacity());
}

TEST(Vector_capacity, test_8) {
  size_t new_size = 10;
  my_containers::vector<int> my_Vec = {1, 2, 3, 4, 5};
  std::vector<int> std_Vec = {1, 2, 3, 4, 5};
  my_Vec.reserve(new_size);
  std_Vec.reserve(new_size);
  EXPECT_EQ(std_Vec.capacity(), my_Vec.capacity());
  EXPECT_EQ(new_size, my_Vec.capacity());
}

TEST(Vector_capacity, test_9) {
  my_containers::vector<int> my_Vec = {1, 2, 3, 4, 5};
  std::vector<int> std_Vec = {1, 2, 3, 4, 5};
  my_Vec.push_back(6);
  std_Vec.push_back(6);
  EXPECT_EQ(std_Vec.capacity(), my_Vec.capacity());
  EXPECT_EQ(10, my_Vec.capacity());
  my_Vec.shrink_to_fit();
  std_Vec.shrink_to_fit();
  EXPECT_EQ(std_Vec.capacity(), my_Vec.capacity());
  EXPECT_EQ(6, my_Vec.capacity());
}

// Vector Modifiers

TEST(Vector_Modifiers, test_1) {
  my_containers::vector<int> my_Vec = {1, 2, 3, 4, 5};
  std::vector<int> std_Vec = {1, 2, 3, 4, 5};
  my_Vec.push_back(6);
  std_Vec.push_back(6);
  EXPECT_EQ(std_Vec.size(), my_Vec.size());
  EXPECT_EQ(6, my_Vec.size());
  my_Vec.clear();
  std_Vec.clear();
  for (size_t i = 0; i < my_Vec.size(); i++) {
    EXPECT_EQ(std_Vec[i], my_Vec[i]);
    EXPECT_EQ(0, my_Vec[i]);
  }
}

TEST(Vector_Modifiers, test_2) {
  my_containers::vector<int> my_Vec = {1, 2, 3, 4, 5};
  std::vector<int> std_Vec = {1, 2, 3, 4, 5};
  my_Vec.insert(my_Vec.begin() + 2, 9);
  std_Vec.insert(std_Vec.begin() + 2, 9);
  EXPECT_EQ(std_Vec.capacity(), my_Vec.capacity());
  EXPECT_EQ(10, my_Vec.capacity());
  EXPECT_EQ(std_Vec.size(), my_Vec.size());
  EXPECT_EQ(6, my_Vec.size());
  EXPECT_EQ(std_Vec[2], my_Vec[2]);
  EXPECT_EQ(9, my_Vec[2]);
}

TEST(Vector_Modifiers, test_3) {
  my_containers::vector<int> my_Vec = {1, 2, 3, 4, 5};
  std::vector<int> std_Vec = {1, 2, 3, 4, 5};
  my_Vec.erase(my_Vec.begin() + 2);
  std_Vec.erase(std_Vec.begin() + 2);
  EXPECT_EQ(std_Vec.size(), my_Vec.size());
  EXPECT_EQ(4, my_Vec.size());
  EXPECT_EQ(std_Vec[2], my_Vec[2]);
  EXPECT_EQ(4, my_Vec[2]);
}

TEST(Vector_Modifiers, test_4) {
  size_t size = 10;
  my_containers::vector<int> my_Vec1;
  std::vector<int> std_Vec1;
  for (size_t i = 0; i < size; ++i) {
    my_Vec1.push_back(i + 1);
    std_Vec1.push_back(i + 1);
  }
  for (size_t i = 0; i < size; ++i) {
    EXPECT_EQ(i + 1, my_Vec1[i]);
  }
  EXPECT_EQ(10, my_Vec1.size());
  EXPECT_EQ(16, my_Vec1.capacity());
  for (size_t i = 0; i < size; ++i) {
    EXPECT_EQ(std_Vec1[i], my_Vec1[i]);
  }
  EXPECT_EQ(std_Vec1.size(), my_Vec1.size());
  EXPECT_EQ(std_Vec1.capacity(), my_Vec1.capacity());
}

TEST(Vector_Modifiers, test_5) {
  size_t size = 10;
  my_containers::vector<int> my_Vec1(size);
  std::vector<int> std_Vec1(size);
  my_Vec1.push_back(3);
  std_Vec1.push_back(3);
  for (size_t i = 0; i < size; ++i) {
    EXPECT_EQ(0, my_Vec1[i]);
  }
  EXPECT_EQ(3, my_Vec1[size]);
  EXPECT_EQ(11, my_Vec1.size());
  EXPECT_EQ(20, my_Vec1.capacity());
  for (size_t i = 0; i < size; ++i) {
    EXPECT_EQ(std_Vec1[i], my_Vec1[i]);
  }
  EXPECT_EQ(std_Vec1[size], my_Vec1[size]);
  EXPECT_EQ(std_Vec1.size(), my_Vec1.size());
  EXPECT_EQ(std_Vec1.capacity(), my_Vec1.capacity());
}

TEST(Vector_Modifiers, test_6) {
  my_containers::vector<int> my_Vec = {1, 2, 3, 4, 5};
  std::vector<int> std_Vec = {1, 2, 3, 4, 5};
  my_Vec.pop_back();
  std_Vec.pop_back();
  EXPECT_EQ(std_Vec.size(), my_Vec.size());
  EXPECT_EQ(4, my_Vec.size());
  EXPECT_EQ(0, my_Vec[4]);
}

TEST(Vector_Modifiers, test_7) {
  my_containers::vector<int> my_Vec1 = {1, 2, 3, 4, 5};
  my_containers::vector<int> my_Vec2 = {6, 7, 8, 9};
  std::vector<int> std_Vec1 = {1, 2, 3, 4, 5};
  std::vector<int> std_Vec2 = {6, 7, 8, 9};
  my_Vec1.swap(my_Vec2);
  std_Vec1.swap(std_Vec2);
  EXPECT_EQ(4, my_Vec1.size());
  EXPECT_EQ(5, my_Vec2.size());
  EXPECT_EQ(4, std_Vec1.size());
  EXPECT_EQ(5, std_Vec2.size());
  for (size_t i = 0; i < 4; ++i) {
    EXPECT_EQ(i + 6, my_Vec1[i]);
    EXPECT_EQ(i + 6, std_Vec1[i]);
  }
  for (size_t i = 0; i < 5; ++i) {
    EXPECT_EQ(i + 1, my_Vec2[i]);
    EXPECT_EQ(i + 1, std_Vec2[i]);
  }
}

TEST(Vector_Modifiers, test_8) {
  size_t size = 10;
  my_containers::vector<double> my_Vec1;
  std::vector<double> std_Vec1;
  for (size_t i = 0; i < size; ++i) {
    my_Vec1.push_back(i + 1.1);
    std_Vec1.push_back(i + 1.1);
  }
  for (size_t i = 0; i < size; ++i) {
    EXPECT_EQ(i + 1.1, my_Vec1[i]);
  }
  EXPECT_EQ(10, my_Vec1.size());
  EXPECT_EQ(16, my_Vec1.capacity());
  for (size_t i = 0; i < size; ++i) {
    EXPECT_EQ(std_Vec1[i], my_Vec1[i]);
  }
  EXPECT_EQ(std_Vec1.size(), my_Vec1.size());
  EXPECT_EQ(std_Vec1.capacity(), my_Vec1.capacity());
}

TEST(Vector_Modifiers, test_9) {
  my_containers::vector<MyClass> my_Vec1;
  std::vector<MyClass> std_Vec1;
  MyClass name_1("Anna");
  MyClass name_2("Maria");
  my_Vec1.push_back(name_1);
  std_Vec1.push_back(name_1);
  my_Vec1.push_back(name_2);
  std_Vec1.push_back(name_2);
  EXPECT_EQ("Anna", my_Vec1[0].getName());
  EXPECT_EQ("Maria", my_Vec1[1].getName());
  EXPECT_EQ(std_Vec1[0].getName(), my_Vec1[0].getName());
  EXPECT_EQ(std_Vec1[1].getName(), my_Vec1[1].getName());
  EXPECT_EQ(std_Vec1.size(), my_Vec1.size());
  EXPECT_EQ(std_Vec1.capacity(), my_Vec1.capacity());
}

// Insert_many
TEST(Insert_many, test_1) {
  my_containers::vector<int> my_Vec = {1, 2, 3, 4};
  my_Vec.insert_many(my_Vec.begin() + 2, 5, 6, 7);
  my_containers::vector<int> check_1 = {1, 2, 5, 6, 7, 3, 4};
  for (size_t i = 0; i < 7; ++i) {
    EXPECT_EQ(check_1[i], my_Vec[i]);
  }

  my_Vec.insert_many(my_Vec.begin(), 10, 11);
  my_containers::vector<int> check_2 = {10, 11, 1, 2, 5, 6, 7, 3, 4};
  for (size_t i = 0; i < 9; ++i) {
    EXPECT_EQ(check_2[i], my_Vec[i]);
  }

  my_Vec.insert_many(my_Vec.end(), 8, 9);
  my_containers::vector<int> check_3 = {10, 11, 1, 2, 5, 6, 7, 3, 4, 8, 9};
  for (size_t i = 0; i < 11; ++i) {
    EXPECT_EQ(check_3[i], my_Vec[i]);
  }
}

TEST(Insert_many, test_2) {
  my_containers::vector<int> my_Vec;
  my_Vec.insert_many(my_Vec.begin(), 1, 2, 3);
  my_containers::vector<int> check_1 = {1, 2, 3};
  for (size_t i = 0; i < 3; ++i) {
    EXPECT_EQ(check_1[i], my_Vec[i]);
  }
}

TEST(Insert_many, test_3) {
  my_containers::vector<MyClass> my_Vec1;
  MyClass name_1("Anna");
  MyClass name_2("Maria");
  MyClass name_3("Kate");
  MyClass name_4("Jenifer");
  my_Vec1.push_back(name_1);
  my_Vec1.push_back(name_2);
  my_Vec1.insert_many(my_Vec1.begin() + 1, name_3, name_4);
  EXPECT_EQ("Anna", my_Vec1[0].getName());
  EXPECT_EQ("Kate", my_Vec1[1].getName());
  EXPECT_EQ("Jenifer", my_Vec1[2].getName());
  EXPECT_EQ("Maria", my_Vec1[3].getName());
}

TEST(Insert_many, test_4) {
  my_containers::vector<int> my_Vec = {1, 2, 3, 4};
  my_Vec.insert_many_back(5, 6, 7);
  my_containers::vector<int> check_1 = {1, 2, 3, 4, 5, 6, 7};
  for (size_t i = 0; i < 7; ++i) {
    EXPECT_EQ(check_1[i], my_Vec[i]);
  }
}

TEST(Insert_many_back, test_5) {
  my_containers::vector<int> my_Vec;
  my_Vec.insert_many_back(1, 2, 3);
  my_containers::vector<int> check_1 = {1, 2, 3};
  for (size_t i = 0; i < 3; ++i) {
    EXPECT_EQ(check_1[i], my_Vec[i]);
  }
}

TEST(Insert_many, test_6) {
  my_containers::vector<MyClass> my_Vec1;
  MyClass name_1("Anna");
  MyClass name_2("Maria");
  MyClass name_3("Kate");
  MyClass name_4("Jenifer");
  my_Vec1.push_back(name_1);
  my_Vec1.push_back(name_2);
  my_Vec1.insert_many_back(name_3, name_4);
  EXPECT_EQ("Anna", my_Vec1[0].getName());
  EXPECT_EQ("Maria", my_Vec1[1].getName());
  EXPECT_EQ("Kate", my_Vec1[2].getName());
  EXPECT_EQ("Jenifer", my_Vec1[3].getName());
}