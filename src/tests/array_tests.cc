
#include "global_tests.h"
// #include "../containers/array/array.h"

TEST(array_test, constructor_default) {
  const size_t size = 0;
  my_containers::array<int, size> my_array;
  std::array<int, size> std_array;
  EXPECT_EQ(my_array.empty(), std_array.empty());
}

TEST(array_test, constructor_with_no_data) {
  const size_t size = 5;
  my_containers::array<int, size> my_array;
  std::array<int, size> std_array;
  EXPECT_EQ(my_array.empty(), std_array.empty());
}

TEST(array_test, constructor_with_data) {
  const size_t size = 5;
  my_containers::array<int, size> my_array = {1, 2, 3, 4, 5};
  std::array<int, size> std_array = {1, 2, 3, 4, 5};
  EXPECT_EQ(my_array.empty(), std_array.empty());
  EXPECT_EQ(my_array.size(), std_array.size());
  EXPECT_EQ(my_array.max_size(), my_array.max_size());
}

TEST(array_test, copy_constructor) {
  const size_t size = 5;
  my_containers::array<int, size> my_array{1, 2, 3, 4, 5};
  std::array<int, size> std_array{1, 2, 3, 4, 5};
  EXPECT_EQ(my_array.size(), std_array.size());
  auto my_iterator = my_array.begin();
  auto std_iterator = std_array.begin();
  bool result = true;
  for (size_t i = 0; i < my_array.size(); i++) {
    if (*my_iterator != *std_iterator) {
      result = false;
      break;
    }
    my_iterator++;
    std_iterator++;
  }
  EXPECT_TRUE(result);
}

TEST(array_test, funcTest) {
  my_containers::array<int, 5> a1 = {1, 2, 3, 4, 5};
  my_containers::array<int, 5> a2 = {1, 2, 3, 2, 1};
  a1.swap(a2);
  ASSERT_EQ(a2.back(), 5);
  ASSERT_EQ(a1.back(), 1);
  a1.fill(2);
  ASSERT_EQ(a1.back(), 2);
  ASSERT_EQ(a1.front(), 2);
}

TEST(array_test, elaccessorTest) {
  my_containers::array<int, 5> a = {1, 2, 3, 4, 5};
  EXPECT_TRUE(a.front() == 1);
  EXPECT_TRUE(a.back() == 5);
  EXPECT_TRUE(a.at(2) == 3);
  EXPECT_TRUE(a[1] == 2);
  my_containers::ArrayIterator f = a.data();
  EXPECT_TRUE(*f == 1);
}

TEST(array_test, iterator_operator_minus) {
  my_containers::array<int, 5> arrays21{1, 2, 3, 4, 5};
  std::array<int, 5> arraystd{1, 2, 3, 4, 5};
  EXPECT_EQ(arrays21.at(2) - arrays21.at(1), arraystd.at(2) - arraystd.at(1));
}

TEST(array_test, front) {
  my_containers::array<int, 3> arr = {99, 88, 77};
  ASSERT_EQ(99, arr.front());

  my_containers::array<int, 0> empty_arr;
  EXPECT_THROW({ empty_arr.front(); }, std::out_of_range);
}

TEST(array_test, back) {
  my_containers::array<int, 3> arr = {33, 44, 55};
  ASSERT_EQ(55, arr.back());

  my_containers::array<int, 0> empty_arr;
  EXPECT_THROW({ empty_arr.back(); }, std::out_of_range);
}
// capacity

TEST(array_test, empty) {
  my_containers::array<int, 0> empty_arr;
  my_containers::array<int, 3> not_empty_arr = {1, 2, 3};

  ASSERT_EQ(1, empty_arr.empty());
  ASSERT_EQ(0, not_empty_arr.empty());
}

// modifiers
TEST(my_containers_array, swap) {
  my_containers::array<int, 3> arr1 = {11, 22, 33};
  my_containers::array<int, 3> arr2 = {77, 88, 99};

  ASSERT_EQ(11, arr1[0]);
  ASSERT_EQ(22, arr1[1]);
  ASSERT_EQ(33, arr1[2]);

  ASSERT_EQ(77, arr2[0]);
  ASSERT_EQ(88, arr2[1]);
  ASSERT_EQ(99, arr2[2]);

  arr1.swap(arr2);

  ASSERT_EQ(77, arr1[0]);
  ASSERT_EQ(88, arr1[1]);
  ASSERT_EQ(99, arr1[2]);

  ASSERT_EQ(11, arr2[0]);
  ASSERT_EQ(22, arr2[1]);
  ASSERT_EQ(33, arr2[2]);
}
