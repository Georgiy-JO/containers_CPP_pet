#include <set>

#include "global_tests.h"
// #include "../containers/set/set.hpp"

// temple
#include <vector>

TEST(SetTest, ConstructorList) {
  my_containers::set<int> set_int{10, 2, 3,  44, 5,  66, -5, -100, 0,   0,
                                  0,  5, 33, 23, 64, 55, 0,  1,    1000};
  std::set<int> set_int_2{10, 2, 3,  44, 5,  66, -5, -100, 0,   0,
                          0,  5, 33, 23, 64, 55, 0,  1,    1000};
  my_containers::set<double> set_double{
      555.55, 423.2, 2, 1000, -55.55, -33.3, -1000, 100, 1000, 100, -5.5};
  std::set<double> set_double_2{555.55, 423.2, 2,    1000, -55.55, -33.3,
                                -1000,  100,   1000, 100,  -5.5};
  my_containers::set<std::string> set_str{"Jazz",  "Me",       "played", "with",
                                          "Blues", "brothers", "like",   "Yoda",
                                          "Wow",   "!"};
  std::set<std::string> set_str_2{"Jazz",     "Me",   "played", "with", "Blues",
                                  "brothers", "like", "Yoda",   "Wow",  "!"};
  my_containers::set<char> set_char{'a',  'b', 'c', 'd', '5', '1',
                                    'a',  '-', '=', '+', 'q', '\n',
                                    '\t', 'y', ']', '[', '(', '`'};
  std::set<char> set_char_2{'a', 'b', 'c',  'd',  '5', '1', 'a', '-', '=',
                            '+', 'q', '\n', '\t', 'y', ']', '[', '(', '`'};
  EXPECT_EQ(set_int.size(), 15);
  EXPECT_EQ(set_int_2.size(), 15);
  EXPECT_EQ(set_double.size(), 9);
  EXPECT_EQ(set_double_2.size(), 9);
  EXPECT_EQ(set_str.size(), 10);
  EXPECT_EQ(set_str_2.size(), 10);
  EXPECT_EQ(set_char.size(), 17);
  EXPECT_EQ(set_char_2.size(), 17);

  EXPECT_EQ(set_int.empty(), false);
  EXPECT_EQ(set_int_2.empty(), false);
  EXPECT_EQ(set_double.empty(), false);
  EXPECT_EQ(set_double_2.empty(), false);
  EXPECT_EQ(set_str.empty(), false);
  EXPECT_EQ(set_str_2.empty(), false);
  EXPECT_EQ(set_char.empty(), false);
  EXPECT_EQ(set_char_2.empty(), false);

  EXPECT_EQ(set_int.contains(66), true);
  EXPECT_EQ(set_int.contains(666), false);
}
TEST(SetTest, ConstructorDefault) {
  my_containers::set<int> set_int;
  std::set<int> set_int_2;
  my_containers::set<double> set_double;
  std::set<double> set_double_2;
  my_containers::set<std::string> set_str;
  std::set<std::string> set_str_2;
  my_containers::set<char> set_char;
  std::set<char> set_char_2;
  EXPECT_EQ(set_int.size(), 0);
  EXPECT_EQ(set_int_2.size(), 0);
  EXPECT_EQ(set_double.size(), 0);
  EXPECT_EQ(set_double_2.size(), 0);
  EXPECT_EQ(set_str.size(), 0);
  EXPECT_EQ(set_str_2.size(), 0);
  EXPECT_EQ(set_char.size(), 0);
  EXPECT_EQ(set_char_2.size(), 0);

  EXPECT_EQ(set_int.empty(), true);
  EXPECT_EQ(set_int_2.empty(), true);
  EXPECT_EQ(set_double.empty(), true);
  EXPECT_EQ(set_double_2.empty(), true);
  EXPECT_EQ(set_str.empty(), true);
  EXPECT_EQ(set_str_2.empty(), true);
  EXPECT_EQ(set_char.empty(), true);
  EXPECT_EQ(set_char_2.empty(), true);

  EXPECT_EQ(set_int.contains(66), false);
  EXPECT_EQ(set_int.contains(666), false);
}
TEST(SetTest, ConstructorMove) {
  my_containers::set<int> set_int{10, 2, 3,  44, 5,  66, -5, -100, 0,   0,
                                  0,  5, 33, 23, 64, 55, 0,  1,    1000};
  std::set<int> set_int_2{10, 2, 3,  44, 5,  66, -5, -100, 0,   0,
                          0,  5, 33, 23, 64, 55, 0,  1,    1000};
  my_containers::set<double> set_double{
      555.55, 423.2, 2, 1000, -55.55, -33.3, -1000, 100, 1000, 100, -5.5};
  std::set<double> set_double_2{555.55, 423.2, 2,    1000, -55.55, -33.3,
                                -1000,  100,   1000, 100,  -5.5};
  my_containers::set<std::string> set_str{"Jazz",  "Me",       "played", "with",
                                          "Blues", "brothers", "like",   "Yoda",
                                          "Wow",   "!"};
  std::set<std::string> set_str_2{"Jazz",     "Me",   "played", "with", "Blues",
                                  "brothers", "like", "Yoda",   "Wow",  "!"};
  my_containers::set<char> set_char{'a',  'b', 'c', 'd', '5', '1',
                                    'a',  '-', '=', '+', 'q', '\n',
                                    '\t', 'y', ']', '[', '(', '`'};
  std::set<char> set_char_2{'a', 'b', 'c',  'd',  '5', '1', 'a', '-', '=',
                            '+', 'q', '\n', '\t', 'y', ']', '[', '(', '`'};
  EXPECT_EQ(set_int.size(), 15);
  EXPECT_EQ(set_int_2.size(), 15);
  EXPECT_EQ(set_double.size(), 9);
  EXPECT_EQ(set_double_2.size(), 9);
  EXPECT_EQ(set_str.size(), 10);
  EXPECT_EQ(set_str_2.size(), 10);
  EXPECT_EQ(set_char.size(), 17);
  EXPECT_EQ(set_char_2.size(), 17);

  my_containers::set<int> set_int_3(std::move(set_int));
  std::set<int> set_int_4(std::move(set_int_2));
  my_containers::set<double> set_double_3(std::move(set_double));
  std::set<double> set_double_4(std::move(set_double_2));
  my_containers::set<std::string> set_str_3(std::move(set_str));
  std::set<std::string> set_str_4(std::move(set_str_2));
  my_containers::set<char> set_char_3(std::move(set_char));
  std::set<char> set_char_4(std::move(set_char_2));
  EXPECT_EQ(set_int.size(), 0);
  EXPECT_EQ(set_int_2.size(), 0);
  EXPECT_EQ(set_double.size(), 0);
  EXPECT_EQ(set_double_2.size(), 0);
  EXPECT_EQ(set_str.size(), 0);
  EXPECT_EQ(set_str_2.size(), 0);
  EXPECT_EQ(set_char.size(), 0);
  EXPECT_EQ(set_char_2.size(), 0);
  EXPECT_EQ(set_int_3.size(), 15);
  EXPECT_EQ(set_int_4.size(), 15);
  EXPECT_EQ(set_double_3.size(), 9);
  EXPECT_EQ(set_double_4.size(), 9);
  EXPECT_EQ(set_str_3.size(), 10);
  EXPECT_EQ(set_str_4.size(), 10);
  EXPECT_EQ(set_char_3.size(), 17);
  EXPECT_EQ(set_char_4.size(), 17);

  EXPECT_EQ(set_int.empty(), true);
  EXPECT_EQ(set_int_2.empty(), true);
  EXPECT_EQ(set_double.empty(), true);
  EXPECT_EQ(set_double_2.empty(), true);
  EXPECT_EQ(set_str.empty(), true);
  EXPECT_EQ(set_str_2.empty(), true);
  EXPECT_EQ(set_char.empty(), true);
  EXPECT_EQ(set_char_2.empty(), true);
  EXPECT_EQ(set_int_3.empty(), false);
  EXPECT_EQ(set_int_4.empty(), false);
  EXPECT_EQ(set_double_3.empty(), false);
  EXPECT_EQ(set_double_4.empty(), false);
  EXPECT_EQ(set_str_3.empty(), false);
  EXPECT_EQ(set_str_4.empty(), false);
  EXPECT_EQ(set_char_3.empty(), false);
  EXPECT_EQ(set_char_4.empty(), false);

  EXPECT_EQ(set_int.contains(66), false);
  EXPECT_EQ(set_int_3.contains(66), true);
}
TEST(SetTest, ConstructorCopy) {
  my_containers::set<int> set_int{10, 2, 3,  44, 5,  66, -5, -100, 0,   0,
                                  0,  5, 33, 23, 64, 55, 0,  1,    1000};
  std::set<int> set_int_2{10, 2, 3,  44, 5,  66, -5, -100, 0,   0,
                          0,  5, 33, 23, 64, 55, 0,  1,    1000};
  my_containers::set<double> set_double{
      555.55, 423.2, 2, 1000, -55.55, -33.3, -1000, 100, 1000, 100, -5.5};
  std::set<double> set_double_2{555.55, 423.2, 2,    1000, -55.55, -33.3,
                                -1000,  100,   1000, 100,  -5.5};
  my_containers::set<std::string> set_str{"Jazz",  "Me",       "played", "with",
                                          "Blues", "brothers", "like",   "Yoda",
                                          "Wow",   "!"};
  std::set<std::string> set_str_2{"Jazz",     "Me",   "played", "with", "Blues",
                                  "brothers", "like", "Yoda",   "Wow",  "!"};
  my_containers::set<char> set_char{'a',  'b', 'c', 'd', '5', '1',
                                    'a',  '-', '=', '+', 'q', '\n',
                                    '\t', 'y', ']', '[', '(', '`'};
  std::set<char> set_char_2{'a', 'b', 'c',  'd',  '5', '1', 'a', '-', '=',
                            '+', 'q', '\n', '\t', 'y', ']', '[', '(', '`'};
  EXPECT_EQ(set_int.size(), 15);
  EXPECT_EQ(set_int_2.size(), 15);
  EXPECT_EQ(set_double.size(), 9);
  EXPECT_EQ(set_double_2.size(), 9);
  EXPECT_EQ(set_str.size(), 10);
  EXPECT_EQ(set_str_2.size(), 10);
  EXPECT_EQ(set_char.size(), 17);
  EXPECT_EQ(set_char_2.size(), 17);

  my_containers::set<int> set_int_3(set_int);
  std::set<int> set_int_4(set_int_2);
  my_containers::set<double> set_double_3(set_double);
  std::set<double> set_double_4(set_double_2);
  my_containers::set<std::string> set_str_3(set_str);
  std::set<std::string> set_str_4(set_str_2);
  my_containers::set<char> set_char_3(set_char);
  std::set<char> set_char_4(set_char_2);
  EXPECT_EQ(set_int.size(), 15);
  EXPECT_EQ(set_int_2.size(), 15);
  EXPECT_EQ(set_double.size(), 9);
  EXPECT_EQ(set_double_2.size(), 9);
  EXPECT_EQ(set_str.size(), 10);
  EXPECT_EQ(set_str_2.size(), 10);
  EXPECT_EQ(set_char.size(), 17);
  EXPECT_EQ(set_char_2.size(), 17);
  EXPECT_EQ(set_int_3.size(), 15);
  EXPECT_EQ(set_int_4.size(), 15);
  EXPECT_EQ(set_double_3.size(), 9);
  EXPECT_EQ(set_double_4.size(), 9);
  EXPECT_EQ(set_str_3.size(), 10);
  EXPECT_EQ(set_str_4.size(), 10);
  EXPECT_EQ(set_char_3.size(), 17);
  EXPECT_EQ(set_char_4.size(), 17);

  EXPECT_EQ(set_int.empty(), false);
  EXPECT_EQ(set_int_2.empty(), false);
  EXPECT_EQ(set_double.empty(), false);
  EXPECT_EQ(set_double_2.empty(), false);
  EXPECT_EQ(set_str.empty(), false);
  EXPECT_EQ(set_str_2.empty(), false);
  EXPECT_EQ(set_char.empty(), false);
  EXPECT_EQ(set_char_2.empty(), false);
  EXPECT_EQ(set_int_3.empty(), false);
  EXPECT_EQ(set_int_4.empty(), false);
  EXPECT_EQ(set_double_3.empty(), false);
  EXPECT_EQ(set_double_4.empty(), false);
  EXPECT_EQ(set_str_3.empty(), false);
  EXPECT_EQ(set_str_4.empty(), false);
  EXPECT_EQ(set_char_3.empty(), false);
  EXPECT_EQ(set_char_4.empty(), false);

  EXPECT_EQ(set_int.contains(66), true);
  EXPECT_EQ(set_int_3.contains(66), true);
  EXPECT_EQ(set_str_3.contains("Jazz"), true);
}
TEST(SetTest, MoveAssignment) {
  my_containers::set<int> set_int_1{10, 2, 3,  44, 5,  66, -5, -100, 0,   0,
                                    0,  5, 33, 23, 64, 55, 0,  1,    1000};
  std::set<int> set_int_2{10, 2, 3,  44, 5,  66, -5, -100, 0,   0,
                          0,  5, 33, 23, 64, 55, 0,  1,    1000};
  my_containers::set<double> set_double_1{
      555.55, 423.2, 2, 1000, -55.55, -33.3, -1000, 100, 1000, 100, -5.5};
  std::set<double> set_double_2{555.55, 423.2, 2,    1000, -55.55, -33.3,
                                -1000,  100,   1000, 100,  -5.5};
  my_containers::set<std::string> set_str_1{
      "Jazz",     "Me",   "played", "with", "Blues",
      "brothers", "like", "Yoda",   "Wow",  "!"};
  std::set<std::string> set_str_2{"Jazz",     "Me",   "played", "with", "Blues",
                                  "brothers", "like", "Yoda",   "Wow",  "!"};
  my_containers::set<char> set_char_1{'a',  'b', 'c', 'd', '5', '1',
                                      'a',  '-', '=', '+', 'q', '\n',
                                      '\t', 'y', ']', '[', '(', '`'};
  std::set<char> set_char_2{'a', 'b', 'c',  'd',  '5', '1', 'a', '-', '=',
                            '+', 'q', '\n', '\t', 'y', ']', '[', '(', '`'};
  EXPECT_EQ(set_int_1.size(), 15);
  EXPECT_EQ(set_int_2.size(), 15);
  EXPECT_EQ(set_double_1.size(), 9);
  EXPECT_EQ(set_double_2.size(), 9);
  EXPECT_EQ(set_str_1.size(), 10);
  EXPECT_EQ(set_str_2.size(), 10);
  EXPECT_EQ(set_char_1.size(), 17);
  EXPECT_EQ(set_char_2.size(), 17);

  my_containers::set<int> set_int_3;
  std::set<int> set_int_4;
  my_containers::set<double> set_double_3;
  std::set<double> set_double_4;
  my_containers::set<std::string> set_str_3;
  std::set<std::string> set_str_4;
  my_containers::set<char> set_char_3;
  std::set<char> set_char_4;
  EXPECT_EQ(set_int_3.empty(), true);
  EXPECT_EQ(set_int_4.empty(), true);
  EXPECT_EQ(set_double_3.empty(), true);
  EXPECT_EQ(set_double_4.empty(), true);
  EXPECT_EQ(set_str_3.empty(), true);
  EXPECT_EQ(set_str_4.empty(), true);

  set_int_3 = std::move(set_int_1);
  set_int_4 = std::move(set_int_2);
  set_double_3 = std::move(set_double_1);
  set_double_4 = std::move(set_double_2);
  set_str_3 = std::move(set_str_1);
  set_str_4 = std::move(set_str_2);
  set_char_3 = std::move(set_char_1);
  set_char_4 = std::move(set_char_2);

  EXPECT_EQ(set_int_1.size(), 0);
  EXPECT_EQ(set_int_2.size(), 0);
  EXPECT_EQ(set_double_1.size(), 0);
  EXPECT_EQ(set_double_2.size(), 0);
  EXPECT_EQ(set_str_1.size(), 0);
  EXPECT_EQ(set_str_2.size(), 0);
  EXPECT_EQ(set_char_1.size(), 0);
  EXPECT_EQ(set_char_2.size(), 0);
  EXPECT_EQ(set_int_3.size(), 15);
  EXPECT_EQ(set_int_4.size(), 15);
  EXPECT_EQ(set_double_3.size(), 9);
  EXPECT_EQ(set_double_4.size(), 9);
  EXPECT_EQ(set_str_3.size(), 10);
  EXPECT_EQ(set_str_4.size(), 10);
  EXPECT_EQ(set_char_3.size(), 17);
  EXPECT_EQ(set_char_4.size(), 17);
  EXPECT_EQ(set_int_1.empty(), true);
  EXPECT_EQ(set_int_2.empty(), true);
  EXPECT_EQ(set_double_1.empty(), true);
  EXPECT_EQ(set_double_2.empty(), true);
  EXPECT_EQ(set_str_1.empty(), true);
  EXPECT_EQ(set_str_2.empty(), true);
  EXPECT_EQ(set_char_1.empty(), true);
  EXPECT_EQ(set_char_2.empty(), true);
}
TEST(SetTest, CopyAssignment) {
  my_containers::set<int> set_int_1{10, 2, 3,  44, 5,  66, -5, -100, 0,   0,
                                    0,  5, 33, 23, 64, 55, 0,  1,    1000};
  std::set<int> set_int_2{10, 2, 3,  44, 5,  66, -5, -100, 0,   0,
                          0,  5, 33, 23, 64, 55, 0,  1,    1000};
  my_containers::set<double> set_double_1{
      555.55, 423.2, 2, 1000, -55.55, -33.3, -1000, 100, 1000, 100, -5.5};
  std::set<double> set_double_2{555.55, 423.2, 2,    1000, -55.55, -33.3,
                                -1000,  100,   1000, 100,  -5.5};
  my_containers::set<std::string> set_str_1{
      "Jazz",     "Me",   "played", "with", "Blues",
      "brothers", "like", "Yoda",   "Wow",  "!"};
  std::set<std::string> set_str_2{"Jazz",     "Me",   "played", "with", "Blues",
                                  "brothers", "like", "Yoda",   "Wow",  "!"};
  my_containers::set<char> set_char_1{'a',  'b', 'c', 'd', '5', '1',
                                      'a',  '-', '=', '+', 'q', '\n',
                                      '\t', 'y', ']', '[', '(', '`'};
  std::set<char> set_char_2{'a', 'b', 'c',  'd',  '5', '1', 'a', '-', '=',
                            '+', 'q', '\n', '\t', 'y', ']', '[', '(', '`'};
  EXPECT_EQ(set_int_1.size(), 15);
  EXPECT_EQ(set_int_2.size(), 15);
  EXPECT_EQ(set_double_1.size(), 9);
  EXPECT_EQ(set_double_2.size(), 9);
  EXPECT_EQ(set_str_1.size(), 10);
  EXPECT_EQ(set_str_2.size(), 10);
  EXPECT_EQ(set_char_1.size(), 17);
  EXPECT_EQ(set_char_2.size(), 17);

  my_containers::set<int> set_int_3;
  std::set<int> set_int_4;
  my_containers::set<double> set_double_3;
  std::set<double> set_double_4;
  my_containers::set<std::string> set_str_3;
  std::set<std::string> set_str_4;
  my_containers::set<char> set_char_3;
  std::set<char> set_char_4;
  EXPECT_EQ(set_int_3.empty(), true);
  EXPECT_EQ(set_int_4.empty(), true);
  EXPECT_EQ(set_double_3.empty(), true);
  EXPECT_EQ(set_double_4.empty(), true);
  EXPECT_EQ(set_str_3.empty(), true);
  EXPECT_EQ(set_str_4.empty(), true);
  EXPECT_EQ(set_char_3.empty(), true);
  EXPECT_EQ(set_char_4.empty(), true);

  set_int_3 = set_int_1;
  set_int_4 = set_int_2;
  set_double_3 = set_double_1;
  set_double_4 = set_double_2;
  set_str_3 = set_str_1;
  set_str_4 = set_str_2;
  set_char_3 = set_char_1;
  set_char_4 = set_char_2;
  EXPECT_EQ(set_int_1.size(), 15);
  EXPECT_EQ(set_int_2.size(), 15);
  EXPECT_EQ(set_double_1.size(), 9);
  EXPECT_EQ(set_double_2.size(), 9);
  EXPECT_EQ(set_str_1.size(), 10);
  EXPECT_EQ(set_str_2.size(), 10);
  EXPECT_EQ(set_char_1.size(), 17);
  EXPECT_EQ(set_char_2.size(), 17);
  EXPECT_EQ(set_int_3.size(), 15);
  EXPECT_EQ(set_int_4.size(), 15);
  EXPECT_EQ(set_double_3.size(), 9);
  EXPECT_EQ(set_double_4.size(), 9);
  EXPECT_EQ(set_str_3.size(), 10);
  EXPECT_EQ(set_str_4.size(), 10);
  EXPECT_EQ(set_int_1.contains(-100), true);
  EXPECT_EQ(set_int_3.contains(-100), true);
  EXPECT_EQ(set_int_1.contains(-10000), false);
  EXPECT_EQ(set_int_3.contains(-10000), false);
  EXPECT_EQ(set_double_1.contains(-33.3), true);
  EXPECT_EQ(set_double_3.contains(-33.3), true);
  EXPECT_EQ(set_double_1.contains(-99999), false);
  EXPECT_EQ(set_double_3.contains(-99999), false);
  EXPECT_EQ(set_str_1.contains("played"), true);
  EXPECT_EQ(set_str_3.contains("played"), true);
  EXPECT_EQ(set_str_1.contains("trains"), false);
  EXPECT_EQ(set_str_3.contains("trains"), false);
  EXPECT_EQ(set_char_1.contains('a'), true);
  EXPECT_EQ(set_char_3.contains('a'), true);
  EXPECT_EQ(set_char_1.contains('z'), false);
  EXPECT_EQ(set_char_3.contains('z'), false);

  my_containers::set<int> set_int_5;
  std::set<int> set_int_6;
  my_containers::set<double> set_double_5;
  std::set<double> set_double_6;
  my_containers::set<std::string> set_str_5;
  std::set<std::string> set_str_6;
  my_containers::set<char> set_char_5;
  std::set<char> set_char_6;
  EXPECT_EQ(set_int_5.empty(), true);
  EXPECT_EQ(set_int_6.empty(), true);
  EXPECT_EQ(set_double_5.empty(), true);
  EXPECT_EQ(set_double_6.empty(), true);
  EXPECT_EQ(set_str_5.empty(), true);
  EXPECT_EQ(set_str_6.empty(), true);
  EXPECT_EQ(set_char_5.empty(), true);
  EXPECT_EQ(set_char_6.empty(), true);

  set_int_3 = set_int_5;
  set_int_4 = set_int_6;
  set_double_3 = set_double_5;
  set_double_4 = set_double_6;
  set_str_3 = set_str_5;
  set_str_4 = set_str_6;
  set_char_3 = set_char_5;
  set_char_4 = set_char_6;
  EXPECT_EQ(set_int_3.empty(), true);
  EXPECT_EQ(set_int_4.empty(), true);
  EXPECT_EQ(set_double_3.empty(), true);
  EXPECT_EQ(set_double_4.empty(), true);
  EXPECT_EQ(set_str_3.empty(), true);
  EXPECT_EQ(set_str_4.empty(), true);
  EXPECT_EQ(set_char_3.empty(), true);
  EXPECT_EQ(set_char_4.empty(), true);

  my_containers::set<int> set_int_7{10, 2, 3, 44, 5};
  std::set<int> set_int_8{10, 2, 3, 44, 5};
  my_containers::set<double> set_double_7{
      555.55, 423.2, 2, 1000, -55.55,
  };
  std::set<double> set_double_8{
      555.55, 423.2, 2, 1000, -55.55,
  };
  my_containers::set<std::string> set_str_7{"Jazz", "Me", "played", "with",
                                            "Blues"};
  std::set<std::string> set_str_8{"Jazz", "Me", "played", "with", "Blues"};
  my_containers::set<char> set_char_7{'a', 'b', 'c', 'd', '5'};
  std::set<char> set_char_8{'a', 'b', 'c', 'd', '5'};
  EXPECT_EQ(set_int_7.size(), 5);
  EXPECT_EQ(set_int_8.size(), 5);
  EXPECT_EQ(set_double_7.size(), 5);
  EXPECT_EQ(set_double_8.size(), 5);
  EXPECT_EQ(set_str_7.size(), 5);
  EXPECT_EQ(set_str_8.size(), 5);
  EXPECT_EQ(set_char_7.size(), 5);
  EXPECT_EQ(set_char_8.size(), 5);

  set_int_1 = set_int_7;
  set_int_2 = set_int_8;
  set_double_1 = set_double_7;
  set_double_2 = set_double_8;
  set_str_1 = set_str_7;
  set_str_2 = set_str_8;
  set_char_1 = set_char_7;
  set_char_2 = set_char_8;
  EXPECT_EQ(set_int_1.size(), 5);
  EXPECT_EQ(set_int_2.size(), 5);
  EXPECT_EQ(set_double_1.size(), 5);
  EXPECT_EQ(set_double_2.size(), 5);
  EXPECT_EQ(set_str_1.size(), 5);
  EXPECT_EQ(set_str_2.size(), 5);
  EXPECT_EQ(set_char_1.size(), 5);
  EXPECT_EQ(set_char_2.size(), 5);
  EXPECT_EQ(set_int_1.empty(), false);
  EXPECT_EQ(set_int_2.empty(), false);
  EXPECT_EQ(set_double_1.empty(), false);
  EXPECT_EQ(set_double_2.empty(), false);
  EXPECT_EQ(set_str_1.empty(), false);
  EXPECT_EQ(set_str_2.empty(), false);
  EXPECT_EQ(set_char_1.empty(), false);
  EXPECT_EQ(set_char_2.empty(), false);

  set_int_1.clear();
  set_int_2.clear();
  set_double_1.clear();
  set_double_2.clear();
  set_str_1.clear();
  set_str_2.clear();
  set_char_1.clear();
  set_char_2.clear();
  EXPECT_EQ(set_int_1.empty(), true);
  EXPECT_EQ(set_int_2.empty(), true);
  EXPECT_EQ(set_double_1.empty(), true);
  EXPECT_EQ(set_double_2.empty(), true);
  EXPECT_EQ(set_str_1.empty(), true);
  EXPECT_EQ(set_str_2.empty(), true);
  EXPECT_EQ(set_char_1.empty(), true);
  EXPECT_EQ(set_char_2.empty(), true);
  EXPECT_EQ(set_int_7.empty(), false);
  EXPECT_EQ(set_int_8.empty(), false);
  EXPECT_EQ(set_double_7.empty(), false);
  EXPECT_EQ(set_double_8.empty(), false);
  EXPECT_EQ(set_str_7.empty(), false);
  EXPECT_EQ(set_str_8.empty(), false);
  EXPECT_EQ(set_char_7.empty(), false);
  EXPECT_EQ(set_char_8.empty(), false);
}
/*
// This thest is systrm dependent -- may cause errors
TEST(SetTest, MaxSize) {
    my_containers::set<int>
set_int_1{10,2,3,44,5,66,-5,-100,0,0,0,5,33,23,64,55,0,1,1000}; std::set<int>
set_int_2{10,2,3,44,5,66,-5,-100,0,0,0,5,33,23,64,55,0,1,1000};
my_containers::set<double> set_double_1{555.55,
423.2,2,1000,-55.55,-33.3,-1000,100,1000,100,-5.5}; std::set<double>
set_double_2{555.55, 423.2,2,1000,-55.55,-33.3,-1000,100,1000,100,-5.5};
my_containers::set<std::string> set_str_1{"Jazz", "Me", "played", "with",
"Blues", "brothers", "like", "Yoda", "Wow", "!"}; std::set<std::string>
set_str_2{"Jazz", "Me", "played", "with", "Blues", "brothers", "like", "Yoda",
"Wow", "!"}; my_containers::set<char> set_char_1{'a', 'b', 'c',
'd','5','1','a','-','=','+','q','\n','\t','y',']','[','(','`'}; std::set<char>
set_char_2{'a', 'b', 'c',
'd','5','1','a','-','=','+','q','\n','\t','y',']','[','(','`'};
    EXPECT_EQ(set_int_1.max_size(), 576460752303423487);
    EXPECT_EQ(set_double_1.max_size(), 461168601842738790);
    EXPECT_EQ(set_str_1.max_size(), 209622091746699450);
    EXPECT_EQ(set_char_1.max_size(), 576460752303423487);
}
*/
TEST(SetTest, Swap) {
  my_containers::set<int> set_int_1{10, 2, 3,  44, 5,  66, -5, -100, 0,   0,
                                    0,  5, 33, 23, 64, 55, 0,  1,    1000};
  std::set<int> set_int_2{10, 2, 3,  44, 5,  66, -5, -100, 0,   0,
                          0,  5, 33, 23, 64, 55, 0,  1,    1000};
  my_containers::set<double> set_double_1{
      555.55, 423.2, 2, 1000, -55.55, -33.3, -1000, 100, 1000, 100, -5.5};
  std::set<double> set_double_2{555.55, 423.2, 2,    1000, -55.55, -33.3,
                                -1000,  100,   1000, 100,  -5.5};
  my_containers::set<std::string> set_str_1{
      "Jazz",     "Me",   "played", "with", "Blues",
      "brothers", "like", "Yoda",   "Wow",  "!"};
  std::set<std::string> set_str_2{"Jazz",     "Me",   "played", "with", "Blues",
                                  "brothers", "like", "Yoda",   "Wow",  "!"};
  my_containers::set<char> set_char_1{'a',  'b', 'c', 'd', '5', '1',
                                      'a',  '-', '=', '+', 'q', '\n',
                                      '\t', 'y', ']', '[', '(', '`'};
  std::set<char> set_char_2{'a', 'b', 'c',  'd',  '5', '1', 'a', '-', '=',
                            '+', 'q', '\n', '\t', 'y', ']', '[', '(', '`'};
  EXPECT_EQ(set_int_1.size(), 15);
  EXPECT_EQ(set_int_2.size(), 15);
  EXPECT_EQ(set_double_1.size(), 9);
  EXPECT_EQ(set_double_2.size(), 9);
  EXPECT_EQ(set_str_1.size(), 10);
  EXPECT_EQ(set_str_2.size(), 10);
  EXPECT_EQ(set_char_1.size(), 17);
  EXPECT_EQ(set_char_2.size(), 17);
  my_containers::set<int> set_int_7{10, 2, 3, 44, 5};
  std::set<int> set_int_8{10, 2, 3, 44, 5};
  my_containers::set<double> set_double_7{555.55, 423.2, 2, 1000, -55.55};
  std::set<double> set_double_8{555.55, 423.2, 2, 1000, -55.55};
  my_containers::set<std::string> set_str_7{"Jazz", "Me", "played", "with",
                                            "Blues"};
  std::set<std::string> set_str_8{"Jazz", "Me", "played", "with", "Blues"};
  my_containers::set<char> set_char_7{'a', 'b', 'c', 'd', '5'};
  std::set<char> set_char_8{'a', 'b', 'c', 'd', '5'};
  EXPECT_EQ(set_int_7.size(), 5);
  EXPECT_EQ(set_int_8.size(), 5);
  EXPECT_EQ(set_double_7.size(), 5);
  EXPECT_EQ(set_double_8.size(), 5);
  EXPECT_EQ(set_str_7.size(), 5);
  EXPECT_EQ(set_str_8.size(), 5);
  EXPECT_EQ(set_char_7.size(), 5);
  EXPECT_EQ(set_char_8.size(), 5);
  my_containers::set<int> set_int_3;
  std::set<int> set_int_4;
  my_containers::set<double> set_double_3;
  std::set<double> set_double_4;
  my_containers::set<std::string> set_str_3;
  std::set<std::string> set_str_4;
  my_containers::set<char> set_char_3;
  std::set<char> set_char_4;
  EXPECT_EQ(set_int_3.empty(), true);
  EXPECT_EQ(set_int_4.empty(), true);
  EXPECT_EQ(set_double_3.empty(), true);
  EXPECT_EQ(set_double_4.empty(), true);
  EXPECT_EQ(set_str_3.empty(), true);
  EXPECT_EQ(set_str_4.empty(), true);
  EXPECT_EQ(set_char_3.empty(), true);
  EXPECT_EQ(set_char_4.empty(), true);

  set_int_1.swap(set_int_7);
  set_int_2.swap(set_int_8);
  set_double_1.swap(set_double_7);
  set_double_2.swap(set_double_8);
  set_str_1.swap(set_str_7);
  set_str_2.swap(set_str_8);
  set_char_1.swap(set_char_7);
  set_char_2.swap(set_char_8);
  EXPECT_EQ(set_int_1.size(), 5);
  EXPECT_EQ(set_int_2.size(), 5);
  EXPECT_EQ(set_double_1.size(), 5);
  EXPECT_EQ(set_double_2.size(), 5);
  EXPECT_EQ(set_str_1.size(), 5);
  EXPECT_EQ(set_str_2.size(), 5);
  EXPECT_EQ(set_char_1.size(), 5);
  EXPECT_EQ(set_char_2.size(), 5);
  EXPECT_EQ(set_int_7.size(), 15);
  EXPECT_EQ(set_int_8.size(), 15);
  EXPECT_EQ(set_double_7.size(), 9);
  EXPECT_EQ(set_double_8.size(), 9);
  EXPECT_EQ(set_str_7.size(), 10);
  EXPECT_EQ(set_str_8.size(), 10);
  EXPECT_EQ(set_char_7.size(), 17);
  EXPECT_EQ(set_char_8.size(), 17);

  set_int_7.swap(set_int_3);
  set_int_8.swap(set_int_4);
  set_double_7.swap(set_double_3);
  set_double_8.swap(set_double_4);
  set_str_7.swap(set_str_3);
  set_str_8.swap(set_str_4);
  set_char_7.swap(set_char_3);
  set_char_8.swap(set_char_4);
  EXPECT_EQ(set_int_7.size(), 0);
  EXPECT_EQ(set_int_8.size(), 0);
  EXPECT_EQ(set_double_7.size(), 0);
  EXPECT_EQ(set_double_8.size(), 0);
  EXPECT_EQ(set_str_7.size(), 0);
  EXPECT_EQ(set_str_8.size(), 0);
  EXPECT_EQ(set_char_7.size(), 0);
  EXPECT_EQ(set_char_8.size(), 0);
  EXPECT_EQ(set_int_3.size(), 15);
  EXPECT_EQ(set_int_4.size(), 15);
  EXPECT_EQ(set_double_3.size(), 9);
  EXPECT_EQ(set_double_4.size(), 9);
  EXPECT_EQ(set_str_3.size(), 10);
  EXPECT_EQ(set_str_4.size(), 10);
  EXPECT_EQ(set_char_3.size(), 17);
  EXPECT_EQ(set_char_4.size(), 17);
}
TEST(SetTest, Merge) {
  my_containers::set<int> set_int_1{10, 2, 3,  44, 5,  66, -5, -100, 0,   0,
                                    0,  5, 33, 23, 64, 55, 0,  1,    1000};
  std::set<int> set_int_2{10, 2, 3,  44, 5,  66, -5, -100, 0,   0,
                          0,  5, 33, 23, 64, 55, 0,  1,    1000};
  my_containers::set<double> set_double_1{
      555.55, 423.2, 2, 1000, -55.55, -33.3, -1000, 100, 1000, 100, -5.5};
  std::set<double> set_double_2{555.55, 423.2, 2,    1000, -55.55, -33.3,
                                -1000,  100,   1000, 100,  -5.5};
  my_containers::set<std::string> set_str_1{
      "Jazz",     "Me",   "played", "with", "Blues",
      "brothers", "like", "Yoda",   "Wow",  "!"};
  std::set<std::string> set_str_2{"Jazz",     "Me",   "played", "with", "Blues",
                                  "brothers", "like", "Yoda",   "Wow",  "!"};
  my_containers::set<char> set_char_1{'a',  'b', 'c', 'd', '5', '1',
                                      'a',  '-', '=', '+', 'q', '\n',
                                      '\t', 'y', ']', '[', '(', '`'};
  std::set<char> set_char_2{'a', 'b', 'c',  'd',  '5', '1', 'a', '-', '=',
                            '+', 'q', '\n', '\t', 'y', ']', '[', '(', '`'};
  EXPECT_EQ(set_int_1.size(), 15);
  EXPECT_EQ(set_int_2.size(), 15);
  EXPECT_EQ(set_double_1.size(), 9);
  EXPECT_EQ(set_double_2.size(), 9);
  EXPECT_EQ(set_str_1.size(), 10);
  EXPECT_EQ(set_str_2.size(), 10);
  EXPECT_EQ(set_char_1.size(), 17);
  EXPECT_EQ(set_char_2.size(), 17);
  my_containers::set<int> set_int_7{10, 2, 3, 44, 5};
  std::set<int> set_int_8{10, 2, 3, 44, 5};
  my_containers::set<double> set_double_7{555.55, 423.2, 2, 1000, -55.55};
  std::set<double> set_double_8{555.55, 423.2, 2, 1000, -55.55};
  my_containers::set<std::string> set_str_7{"Jazz", "Me", "played", "with",
                                            "Blues"};
  std::set<std::string> set_str_8{"Jazz", "Me", "played", "with", "Blues"};
  my_containers::set<char> set_char_7{'a', 'b', 'c', 'd', '5'};
  std::set<char> set_char_8{'a', 'b', 'c', 'd', '5'};
  EXPECT_EQ(set_int_7.size(), 5);
  EXPECT_EQ(set_int_8.size(), 5);
  EXPECT_EQ(set_double_7.size(), 5);
  EXPECT_EQ(set_double_8.size(), 5);
  EXPECT_EQ(set_str_7.size(), 5);
  EXPECT_EQ(set_str_8.size(), 5);
  EXPECT_EQ(set_char_7.size(), 5);
  EXPECT_EQ(set_char_8.size(), 5);
  my_containers::set<int> set_int_3;
  std::set<int> set_int_4;
  my_containers::set<double> set_double_3;
  std::set<double> set_double_4;
  my_containers::set<std::string> set_str_3;
  std::set<std::string> set_str_4;
  my_containers::set<char> set_char_3;
  std::set<char> set_char_4;
  EXPECT_EQ(set_int_3.empty(), true);
  EXPECT_EQ(set_int_4.empty(), true);
  EXPECT_EQ(set_double_3.empty(), true);
  EXPECT_EQ(set_double_4.empty(), true);
  EXPECT_EQ(set_str_3.empty(), true);
  EXPECT_EQ(set_str_4.empty(), true);
  EXPECT_EQ(set_char_3.empty(), true);
  EXPECT_EQ(set_char_4.empty(), true);

  set_int_1.merge(set_int_3);
  set_int_2.merge(set_int_4);
  set_double_1.merge(set_double_3);
  set_double_2.merge(set_double_4);
  set_str_1.merge(set_str_3);
  set_str_2.merge(set_str_4);
  set_char_1.merge(set_char_3);
  set_char_2.merge(set_char_4);
  EXPECT_EQ(set_int_1.size(), 15);
  EXPECT_EQ(set_int_2.size(), 15);
  EXPECT_EQ(set_double_1.size(), 9);
  EXPECT_EQ(set_double_2.size(), 9);
  EXPECT_EQ(set_str_1.size(), 10);
  EXPECT_EQ(set_str_2.size(), 10);
  EXPECT_EQ(set_char_1.size(), 17);
  EXPECT_EQ(set_char_2.size(), 17);
  EXPECT_EQ(set_int_3.empty(), true);
  EXPECT_EQ(set_int_4.empty(), true);
  EXPECT_EQ(set_double_3.empty(), true);
  EXPECT_EQ(set_double_4.empty(), true);
  EXPECT_EQ(set_str_3.empty(), true);
  EXPECT_EQ(set_str_4.empty(), true);
  EXPECT_EQ(set_char_3.empty(), true);
  EXPECT_EQ(set_char_4.empty(), true);

  set_int_3.merge(set_int_1);
  set_int_4.merge(set_int_2);
  set_double_3.merge(set_double_1);
  set_double_4.merge(set_double_2);
  set_str_3.merge(set_str_1);
  set_str_4.merge(set_str_2);
  set_char_3.merge(set_char_1);
  set_char_4.merge(set_char_2);
  EXPECT_EQ(set_int_3.size(), 15);
  EXPECT_EQ(set_int_4.size(), 15);
  EXPECT_EQ(set_double_3.size(), 9);
  EXPECT_EQ(set_double_4.size(), 9);
  EXPECT_EQ(set_str_3.size(), 10);
  EXPECT_EQ(set_str_4.size(), 10);
  EXPECT_EQ(set_char_3.size(), 17);
  EXPECT_EQ(set_char_4.size(), 17);
  EXPECT_EQ(set_int_1.empty(), true);
  EXPECT_EQ(set_int_2.empty(), true);
  EXPECT_EQ(set_double_1.empty(), true);
  EXPECT_EQ(set_double_2.empty(), true);
  EXPECT_EQ(set_str_1.empty(), true);
  EXPECT_EQ(set_str_2.empty(), true);
  EXPECT_EQ(set_char_1.empty(), true);
  EXPECT_EQ(set_char_2.empty(), true);

  set_int_3.merge(set_int_7);
  set_int_4.merge(set_int_8);
  set_double_3.merge(set_double_7);
  set_double_4.merge(set_double_8);
  set_str_3.merge(set_str_7);
  set_str_4.merge(set_str_8);
  set_char_3.merge(set_char_7);
  set_char_4.merge(set_char_8);
  EXPECT_EQ(set_int_3.size(), 15);
  EXPECT_EQ(set_int_4.size(), 15);
  EXPECT_EQ(set_double_3.size(), 9);
  EXPECT_EQ(set_double_4.size(), 9);
  EXPECT_EQ(set_str_3.size(), 10);
  EXPECT_EQ(set_str_4.size(), 10);
  EXPECT_EQ(set_char_3.size(), 17);
  EXPECT_EQ(set_char_4.size(), 17);
  EXPECT_EQ(set_int_7.size(), 5);
  EXPECT_EQ(set_int_8.size(), 5);
  EXPECT_EQ(set_double_7.size(), 5);
  EXPECT_EQ(set_double_8.size(), 5);
  EXPECT_EQ(set_str_7.size(), 5);
  EXPECT_EQ(set_str_8.size(), 5);
  EXPECT_EQ(set_char_7.size(), 5);
  EXPECT_EQ(set_char_8.size(), 5);

  set_int_7.insert(777);
  set_int_8.insert(777);
  set_double_7.insert(77.77);
  set_double_8.insert(77.77);
  set_str_7.insert("Rock");
  set_str_8.insert("Rock");
  set_char_7.insert('R');
  set_char_8.insert('R');
  EXPECT_EQ(set_int_7.size(), 6);
  EXPECT_EQ(set_int_8.size(), 6);
  EXPECT_EQ(set_double_7.size(), 6);
  EXPECT_EQ(set_double_8.size(), 6);
  EXPECT_EQ(set_str_7.size(), 6);
  EXPECT_EQ(set_str_8.size(), 6);
  EXPECT_EQ(set_char_7.size(), 6);
  EXPECT_EQ(set_char_8.size(), 6);
  set_int_3.merge(set_int_7);
  set_int_4.merge(set_int_8);
  set_double_3.merge(set_double_7);
  set_double_4.merge(set_double_8);
  set_str_3.merge(set_str_7);
  set_str_4.merge(set_str_8);
  set_char_3.merge(set_char_7);
  set_char_4.merge(set_char_8);
  EXPECT_EQ(set_int_3.size(), 16);
  EXPECT_EQ(set_int_4.size(), 16);
  EXPECT_EQ(set_double_3.size(), 10);
  EXPECT_EQ(set_double_4.size(), 10);
  EXPECT_EQ(set_str_3.size(), 11);
  EXPECT_EQ(set_str_4.size(), 11);
  EXPECT_EQ(set_char_3.size(), 18);
  EXPECT_EQ(set_char_4.size(), 18);
  EXPECT_EQ(set_int_7.size(), 5);
  EXPECT_EQ(set_int_8.size(), 5);
  EXPECT_EQ(set_double_7.size(), 5);
  EXPECT_EQ(set_double_8.size(), 5);
  EXPECT_EQ(set_str_7.size(), 5);
  EXPECT_EQ(set_str_8.size(), 5);
  EXPECT_EQ(set_char_7.size(), 5);
  EXPECT_EQ(set_char_8.size(), 5);

  set_int_7.merge(set_int_3);
  set_int_8.merge(set_int_4);
  set_double_7.merge(set_double_3);
  set_double_8.merge(set_double_4);
  set_str_7.merge(set_str_3);
  set_str_8.merge(set_str_4);
  set_char_7.merge(set_char_3);
  set_char_8.merge(set_char_4);
  EXPECT_EQ(set_int_7.size(), 16);
  EXPECT_EQ(set_int_8.size(), 16);
  EXPECT_EQ(set_double_7.size(), 10);
  EXPECT_EQ(set_double_8.size(), 10);
  EXPECT_EQ(set_str_7.size(), 11);
  EXPECT_EQ(set_str_8.size(), 11);
  EXPECT_EQ(set_char_7.size(), 18);
  EXPECT_EQ(set_char_8.size(), 18);
  EXPECT_EQ(set_int_3.size(), 5);
  EXPECT_EQ(set_int_4.size(), 5);
  EXPECT_EQ(set_double_3.size(), 5);
  EXPECT_EQ(set_double_4.size(), 5);
  EXPECT_EQ(set_str_3.size(), 5);
  EXPECT_EQ(set_str_4.size(), 5);
  EXPECT_EQ(set_char_3.size(), 5);
  EXPECT_EQ(set_char_4.size(), 5);
}
TEST(SetTest, Erase_Begin_End) {
  my_containers::set<int> set_int_1{10, 2, 3,  44, 5,  66, -5, -100, 0,   0,
                                    0,  5, 33, 23, 64, 55, 0,  1,    1000};
  std::set<int> set_int_2{10, 2, 3,  44, 5,  66, -5, -100, 0,   0,
                          0,  5, 33, 23, 64, 55, 0,  1,    1000};
  my_containers::set<double> set_double_1{
      555.55, 423.2, 2, 1000, -55.55, -33.3, -1000, 100, 1000, 100, -5.5};
  std::set<double> set_double_2{555.55, 423.2, 2,    1000, -55.55, -33.3,
                                -1000,  100,   1000, 100,  -5.5};
  my_containers::set<std::string> set_str_1{
      "Jazz",     "Me",   "played", "with", "Blues",
      "brothers", "like", "Yoda",   "Wow",  "!"};
  std::set<std::string> set_str_2{"Jazz",     "Me",   "played", "with", "Blues",
                                  "brothers", "like", "Yoda",   "Wow",  "!"};
  my_containers::set<char> set_char_1{'a',  'b', 'c', 'd', '5', '1',
                                      'a',  '-', '=', '+', 'q', '\n',
                                      '\t', 'y', ']', '[', '(', '`'};
  std::set<char> set_char_2{'a', 'b', 'c',  'd',  '5', '1', 'a', '-', '=',
                            '+', 'q', '\n', '\t', 'y', ']', '[', '(', '`'};
  EXPECT_EQ(set_int_1.size(), 15);
  EXPECT_EQ(set_int_2.size(), 15);
  EXPECT_EQ(set_double_1.size(), 9);
  EXPECT_EQ(set_double_2.size(), 9);
  EXPECT_EQ(set_str_1.size(), 10);
  EXPECT_EQ(set_str_2.size(), 10);
  EXPECT_EQ(set_char_1.size(), 17);
  EXPECT_EQ(set_char_2.size(), 17);
  my_containers::set<int> set_int_5{10, 2, 3, 44, 5};
  std::set<int> set_int_6{10, 2, 3, 44, 5};
  my_containers::set<double> set_double_5{555.55, 423.2, 2, 1000, -55.55};
  std::set<double> set_double_6{555.55, 423.2, 2, 1000, -55.55};
  my_containers::set<std::string> set_str_5{"Jazz", "Me", "played", "with",
                                            "Blues"};
  std::set<std::string> set_str_6{"Jazz", "Me", "played", "with", "Blues"};
  my_containers::set<char> set_char_5{'a', 'b', 'c', 'd', '5'};
  std::set<char> set_char_6{'a', 'b', 'c', 'd', '5'};
  EXPECT_EQ(set_int_5.size(), 5);
  EXPECT_EQ(set_int_6.size(), 5);
  EXPECT_EQ(set_double_5.size(), 5);
  EXPECT_EQ(set_double_6.size(), 5);
  EXPECT_EQ(set_str_5.size(), 5);
  EXPECT_EQ(set_str_6.size(), 5);
  EXPECT_EQ(set_char_5.size(), 5);
  EXPECT_EQ(set_char_6.size(), 5);
  my_containers::set<int> set_int_3;
  std::set<int> set_int_4;
  my_containers::set<double> set_double_3;
  std::set<double> set_double_4;
  my_containers::set<std::string> set_str_3;
  std::set<std::string> set_str_4;
  my_containers::set<char> set_char_3;
  std::set<char> set_char_4;
  EXPECT_EQ(set_int_3.empty(), true);
  EXPECT_EQ(set_int_4.empty(), true);
  EXPECT_EQ(set_double_3.empty(), true);
  EXPECT_EQ(set_double_4.empty(), true);
  EXPECT_EQ(set_str_3.empty(), true);
  EXPECT_EQ(set_str_4.empty(), true);
  EXPECT_EQ(set_char_3.empty(), true);
  EXPECT_EQ(set_char_4.empty(), true);

  my_containers::set<int>::iterator int_it_1;
  std::set<int>::iterator int_it_2;
  my_containers::set<int>::iterator int_it_3;
  std::set<int>::iterator int_it_4;
  my_containers::set<int>::iterator int_it_5;
  std::set<int>::iterator int_it_6;
  my_containers::set<double>::iterator double_it_1;
  std::set<double>::iterator double_it_2;
  my_containers::set<double>::iterator double_it_3;
  std::set<double>::iterator double_it_4;
  my_containers::set<double>::iterator double_it_5;
  std::set<double>::iterator double_it_6;
  my_containers::set<std::string>::iterator str_it_1;
  std::set<std::string>::iterator str_it_2;
  my_containers::set<std::string>::iterator str_it_3;
  std::set<std::string>::iterator str_it_4;
  my_containers::set<std::string>::iterator str_it_5;
  std::set<std::string>::iterator str_it_6;
  my_containers::set<char>::iterator char_it_1;
  std::set<char>::iterator char_it_2;
  my_containers::set<char>::iterator char_it_3;
  std::set<char>::iterator char_it_4;
  my_containers::set<char>::iterator char_it_5;
  std::set<char>::iterator char_it_6;

  int_it_1 = set_int_1.begin();
  int_it_2 = set_int_2.begin();
  int_it_3 = set_int_3.begin();
  int_it_4 = set_int_4.begin();
  int_it_5 = set_int_5.end();
  int_it_6 = set_int_6.end();
  double_it_1 = set_double_1.begin();
  double_it_2 = set_double_2.begin();
  double_it_3 = set_double_3.begin();
  double_it_4 = set_double_4.begin();
  double_it_5 = set_double_5.end();
  double_it_6 = set_double_6.end();
  str_it_1 = set_str_1.begin();
  str_it_2 = set_str_2.begin();
  str_it_3 = set_str_3.begin();
  str_it_4 = set_str_4.begin();
  str_it_5 = set_str_5.end();
  str_it_6 = set_str_6.end();
  char_it_1 = set_char_1.begin();
  char_it_2 = set_char_2.begin();
  char_it_3 = set_char_3.begin();
  char_it_4 = set_char_4.begin();
  char_it_5 = set_char_5.end();
  char_it_6 = set_char_6.end();
  EXPECT_EQ(set_int_1.contains(*int_it_1), true);
  EXPECT_EQ(int_it_3.assigned(), false);
  EXPECT_EQ(set_int_5.contains(*int_it_5), true);
  EXPECT_EQ(set_double_1.contains(*double_it_1), true);
  EXPECT_EQ(double_it_3.assigned(), false);
  EXPECT_EQ(set_double_5.contains(*double_it_5), true);
  EXPECT_EQ(set_str_1.contains(*str_it_1), true);
  EXPECT_EQ(str_it_3.assigned(), false);
  EXPECT_EQ(set_str_5.contains(*str_it_5), true);
  EXPECT_EQ(set_char_1.contains(*char_it_1), true);
  EXPECT_EQ(char_it_3.assigned(), false);
  EXPECT_EQ(set_char_5.contains(*char_it_5), true);
  EXPECT_EQ(*int_it_1, -100);
  EXPECT_EQ(*int_it_2, -100);
  EXPECT_EQ(*int_it_5, 44);
  EXPECT_EQ(*double_it_1, -1000);
  EXPECT_EQ(*double_it_2, -1000);
  EXPECT_EQ(*double_it_5, 1000);
  EXPECT_EQ(*str_it_1, "!");
  EXPECT_EQ(*str_it_2, "!");
  EXPECT_EQ(*str_it_5, "with");
  EXPECT_EQ(*char_it_1, '\t');
  EXPECT_EQ(*char_it_2, '\t');
  EXPECT_EQ(*char_it_5, 'd');

  int int_1 = *int_it_1;
  int int_5 = *int_it_5;
  double double_1 = *double_it_1;
  double double_5 = *double_it_5;
  std::string str_1 = *str_it_1;
  std::string str_5 = *str_it_5;
  char char_1 = *char_it_1;
  char char_5 = *char_it_5;

  set_int_1.erase(int_it_1);
  set_int_2.erase(int_it_2);
  set_int_3.erase(int_it_3);
  // set_int_4.erase(int_it_4);   //XD - that's nice that there is no exception
  // for that
  set_int_5.erase(int_it_5);

  set_double_1.erase(double_it_1);
  set_double_2.erase(double_it_2);
  set_double_3.erase(double_it_3);
  // set_double_4.erase(double_it_4);   //XD
  set_double_5.erase(double_it_5);
  set_str_1.erase(str_it_1);
  set_str_2.erase(str_it_2);
  set_str_3.erase(str_it_3);
  // set_str_4.erase(str_it_4);   //XD
  set_str_5.erase(str_it_5);
  set_char_1.erase(char_it_1);
  set_char_2.erase(char_it_2);
  set_char_3.erase(char_it_3);
  // set_char_4.erase(char_it_4);   //XD
  set_char_5.erase(char_it_5);
  EXPECT_EQ(set_int_1.size(), 14);
  EXPECT_EQ(set_int_2.size(), 14);
  EXPECT_EQ(set_double_1.size(), 8);
  EXPECT_EQ(set_double_2.size(), 8);
  EXPECT_EQ(set_str_1.size(), 9);
  EXPECT_EQ(set_str_2.size(), 9);
  EXPECT_EQ(set_char_1.size(), 16);
  EXPECT_EQ(set_char_2.size(), 16);
  EXPECT_EQ(set_int_3.size(), 0);
  EXPECT_EQ(set_int_4.size(), 0);
  EXPECT_EQ(set_double_3.size(), 0);
  EXPECT_EQ(set_double_4.size(), 0);
  EXPECT_EQ(set_str_3.size(), 0);
  EXPECT_EQ(set_str_4.size(), 0);
  EXPECT_EQ(set_char_3.size(), 0);
  EXPECT_EQ(set_char_4.size(), 0);
  EXPECT_EQ(set_int_5.size(), 4);
  EXPECT_EQ(set_double_5.size(), 4);
  EXPECT_EQ(set_str_5.size(), 4);
  EXPECT_EQ(set_char_5.size(), 4);
  EXPECT_EQ(set_int_1.contains(int_1), false);
  EXPECT_EQ(set_int_5.contains(int_5), false);
  EXPECT_EQ(set_double_1.contains(double_1), false);
  EXPECT_EQ(set_double_5.contains(double_5), false);
  EXPECT_EQ(set_str_1.contains(str_1), false);
  EXPECT_EQ(set_str_5.contains(str_5), false);
  EXPECT_EQ(set_char_1.contains(char_1), false);
  EXPECT_EQ(set_char_5.contains(char_5), false);
}
TEST(SetTest, Insert_Find) {
  my_containers::set<int> set_int_1{10, 2, 3,  44, 5,  66, -5, -100, 0,   0,
                                    0,  5, 33, 23, 64, 55, 0,  1,    1000};
  std::set<int> set_int_2{10, 2, 3,  44, 5,  66, -5, -100, 0,   0,
                          0,  5, 33, 23, 64, 55, 0,  1,    1000};
  my_containers::set<double> set_double_1{
      555.55, 423.2, 2, 1000, -55.55, -33.3, -1000, 100, 1000, 100, -5.5};
  std::set<double> set_double_2{555.55, 423.2, 2,    1000, -55.55, -33.3,
                                -1000,  100,   1000, 100,  -5.5};
  my_containers::set<std::string> set_str_1{
      "Jazz",     "Me",   "played", "with", "Blues",
      "brothers", "like", "Yoda",   "Wow",  "!"};
  std::set<std::string> set_str_2{"Jazz",     "Me",   "played", "with", "Blues",
                                  "brothers", "like", "Yoda",   "Wow",  "!"};
  my_containers::set<char> set_char_1{'a', 'b', 'c', 'd', '5', '1',
                                      'a', '-', '=', '+', 'q', '\n',
                                      'h', 'y', ']', '[', '(', '`'};
  std::set<char> set_char_2{'a', 'b', 'c',  'd', '5', '1', 'a', '-', '=',
                            '+', 'q', '\n', 'h', 'y', ']', '[', '(', '`'};
  EXPECT_EQ(set_int_1.size(), 15);
  EXPECT_EQ(set_int_2.size(), 15);
  EXPECT_EQ(set_double_1.size(), 9);
  EXPECT_EQ(set_double_2.size(), 9);
  EXPECT_EQ(set_str_1.size(), 10);
  EXPECT_EQ(set_str_2.size(), 10);
  EXPECT_EQ(set_char_1.size(), 17);
  EXPECT_EQ(set_char_2.size(), 17);
  my_containers::set<int> set_int_5{10, 2, 3, 44, 5};
  std::set<int> set_int_6{10, 2, 3, 44, 5};
  my_containers::set<double> set_double_5{555.55, 423.2, 2, 1000, -55.55};
  std::set<double> set_double_6{555.55, 423.2, 2, 1000, -55.55};
  my_containers::set<std::string> set_str_5{"Jazz", "Me", "played", "with",
                                            "Blues"};
  std::set<std::string> set_str_6{"Jazz", "Me", "played", "with", "Blues"};
  my_containers::set<char> set_char_5{'a', 'b', 'c', 'd', '5'};
  std::set<char> set_char_6{'a', 'b', 'c', 'd', '5'};
  EXPECT_EQ(set_int_5.size(), 5);
  EXPECT_EQ(set_int_6.size(), 5);
  EXPECT_EQ(set_double_5.size(), 5);
  EXPECT_EQ(set_double_6.size(), 5);
  EXPECT_EQ(set_str_5.size(), 5);
  EXPECT_EQ(set_str_6.size(), 5);
  EXPECT_EQ(set_char_5.size(), 5);
  EXPECT_EQ(set_char_6.size(), 5);
  my_containers::set<int> set_int_3;
  std::set<int> set_int_4;
  my_containers::set<double> set_double_3;
  std::set<double> set_double_4;
  my_containers::set<std::string> set_str_3;
  std::set<std::string> set_str_4;
  my_containers::set<char> set_char_3;
  std::set<char> set_char_4;
  EXPECT_EQ(set_int_3.empty(), true);
  EXPECT_EQ(set_int_4.empty(), true);
  EXPECT_EQ(set_double_3.empty(), true);
  EXPECT_EQ(set_double_4.empty(), true);
  EXPECT_EQ(set_str_3.empty(), true);
  EXPECT_EQ(set_str_4.empty(), true);
  EXPECT_EQ(set_char_3.empty(), true);
  EXPECT_EQ(set_char_4.empty(), true);

  my_containers::set<int>::iterator int_it_1;
  std::set<int>::iterator int_it_2;
  my_containers::set<int>::iterator int_it_3;
  std::set<int>::iterator int_it_4;
  my_containers::set<int>::iterator int_it_5;
  std::set<int>::iterator int_it_6;
  my_containers::set<double>::iterator double_it_1;
  std::set<double>::iterator double_it_2;
  my_containers::set<double>::iterator double_it_3;
  std::set<double>::iterator double_it_4;
  my_containers::set<double>::iterator double_it_5;
  std::set<double>::iterator double_it_6;
  my_containers::set<std::string>::iterator str_it_1;
  std::set<std::string>::iterator str_it_2;
  my_containers::set<std::string>::iterator str_it_3;
  std::set<std::string>::iterator str_it_4;
  my_containers::set<std::string>::iterator str_it_5;
  std::set<std::string>::iterator str_it_6;
  my_containers::set<char>::iterator char_it_1;
  std::set<char>::iterator char_it_2;
  my_containers::set<char>::iterator char_it_3;
  std::set<char>::iterator char_it_4;
  my_containers::set<char>::iterator char_it_5;
  std::set<char>::iterator char_it_6;

  int_it_1 = set_int_1.find(-5);
  int_it_2 = set_int_2.find(-5);
  int_it_3 = set_int_3.find(-5);
  int_it_4 = set_int_4.find(-5);
  int_it_5 = set_int_5.find(-5);
  int_it_6 = set_int_6.find(-5);
  double_it_1 = set_double_1.find(-5.5);
  double_it_2 = set_double_2.find(-5.5);
  double_it_3 = set_double_3.find(-5.5);
  double_it_4 = set_double_4.find(-5.5);
  double_it_5 = set_double_5.find(-5.5);
  double_it_6 = set_double_6.find(-5.5);
  str_it_1 = set_str_1.find("Yoda");
  str_it_2 = set_str_2.find("Yoda");
  str_it_3 = set_str_3.find("Yoda");
  str_it_4 = set_str_4.find("Yoda");
  str_it_5 = set_str_5.find("Yoda");
  str_it_6 = set_str_6.find("Yoda");
  char_it_1 = set_char_1.find('\n');
  char_it_2 = set_char_2.find('\n');
  char_it_3 = set_char_3.find('\n');
  char_it_4 = set_char_4.find('\n');
  char_it_5 = set_char_5.find('\n');
  char_it_6 = set_char_6.find('\n');
  EXPECT_EQ(*int_it_1, -5);
  EXPECT_EQ(*int_it_2, -5);
  EXPECT_EQ(int_it_3.assigned(), false);
  EXPECT_EQ(int_it_5.assigned(), false);
  EXPECT_EQ(*double_it_1, -5.5);
  EXPECT_EQ(*double_it_2, -5.5);
  EXPECT_EQ(double_it_3.assigned(), false);
  EXPECT_EQ(double_it_5.assigned(), false);
  EXPECT_EQ(*str_it_1, "Yoda");
  EXPECT_EQ(*str_it_2, "Yoda");
  EXPECT_EQ(str_it_3.assigned(), false);
  EXPECT_EQ(str_it_5.assigned(), false);
  EXPECT_EQ(*char_it_1, '\n');
  EXPECT_EQ(*char_it_2, '\n');
  EXPECT_EQ(char_it_3.assigned(), false);
  EXPECT_EQ(char_it_5.assigned(), false);

  std::pair<my_containers::set<int>::iterator, bool> pair_int_1;
  std::pair<std::set<int>::iterator, bool> pair_int_2;
  std::pair<my_containers::set<int>::iterator, bool> pair_int_3;
  std::pair<std::set<int>::iterator, bool> pair_int_4;
  std::pair<my_containers::set<int>::iterator, bool> pair_int_5;
  std::pair<std::set<int>::iterator, bool> pair_int_6;
  std::pair<my_containers::set<double>::iterator, bool> pair_double_1;
  std::pair<std::set<double>::iterator, bool> pair_double_2;
  std::pair<my_containers::set<double>::iterator, bool> pair_double_3;
  std::pair<std::set<double>::iterator, bool> pair_double_4;
  std::pair<my_containers::set<double>::iterator, bool> pair_double_5;
  std::pair<std::set<double>::iterator, bool> pair_double_6;
  std::pair<my_containers::set<std::string>::iterator, bool> pair_str_1;
  std::pair<std::set<std::string>::iterator, bool> pair_str_2;
  std::pair<my_containers::set<std::string>::iterator, bool> pair_str_3;
  std::pair<std::set<std::string>::iterator, bool> pair_str_4;
  std::pair<my_containers::set<std::string>::iterator, bool> pair_str_5;
  std::pair<std::set<std::string>::iterator, bool> pair_str_6;
  std::pair<my_containers::set<char>::iterator, bool> pair_char_1;
  std::pair<std::set<char>::iterator, bool> pair_char_2;
  std::pair<my_containers::set<char>::iterator, bool> pair_char_3;
  std::pair<std::set<char>::iterator, bool> pair_char_4;
  std::pair<my_containers::set<char>::iterator, bool> pair_char_5;
  std::pair<std::set<char>::iterator, bool> pair_char_6;

  pair_int_1 = set_int_1.insert(-55555);
  pair_int_2 = set_int_2.insert(-55555);
  pair_int_3 = set_int_3.insert(-55555);
  pair_int_4 = set_int_4.insert(-55555);
  pair_int_5 = set_int_5.insert(-55555);
  pair_int_6 = set_int_6.insert(-55555);
  pair_double_1 = set_double_1.insert(-55555.55555);
  pair_double_2 = set_double_2.insert(-55555.55555);
  pair_double_3 = set_double_3.insert(-55555.55555);
  pair_double_4 = set_double_4.insert(-55555.55555);
  pair_double_5 = set_double_5.insert(-55555.55555);
  pair_double_6 = set_double_6.insert(-55555.55555);
  pair_str_1 = set_str_1.insert(" Jack O'Neill");
  pair_str_2 = set_str_2.insert(" Jack O'Neill");
  pair_str_3 = set_str_3.insert(" Jack O'Neill");
  pair_str_4 = set_str_4.insert(" Jack O'Neill");
  pair_str_5 = set_str_5.insert(" Jack O'Neill");
  pair_str_6 = set_str_6.insert(" Jack O'Neill");
  pair_char_1 = set_char_1.insert('\t');
  pair_char_2 = set_char_2.insert('\t');
  pair_char_3 = set_char_3.insert('\t');
  pair_char_4 = set_char_4.insert('\t');
  pair_char_5 = set_char_5.insert('\t');
  pair_char_6 = set_char_6.insert('\t');
  EXPECT_EQ(pair_int_1.second, true);
  EXPECT_EQ(pair_int_2.second, true);
  EXPECT_EQ(pair_int_3.second, true);
  EXPECT_EQ(pair_int_4.second, true);
  EXPECT_EQ(pair_int_5.second, true);
  EXPECT_EQ(pair_int_6.second, true);
  EXPECT_EQ(pair_double_1.second, true);
  EXPECT_EQ(pair_double_2.second, true);
  EXPECT_EQ(pair_double_3.second, true);
  EXPECT_EQ(pair_double_4.second, true);
  EXPECT_EQ(pair_double_5.second, true);
  EXPECT_EQ(pair_double_6.second, true);
  EXPECT_EQ(pair_str_1.second, true);
  EXPECT_EQ(pair_str_2.second, true);
  EXPECT_EQ(pair_str_3.second, true);
  EXPECT_EQ(pair_str_4.second, true);
  EXPECT_EQ(pair_str_5.second, true);
  EXPECT_EQ(pair_str_6.second, true);
  EXPECT_EQ(pair_char_1.second, true);
  EXPECT_EQ(pair_char_2.second, true);
  EXPECT_EQ(pair_char_3.second, true);
  EXPECT_EQ(pair_char_4.second, true);
  EXPECT_EQ(pair_char_5.second, true);
  EXPECT_EQ(pair_char_6.second, true);
  EXPECT_EQ(set_int_1.contains(-55555), true);
  EXPECT_EQ(set_int_3.contains(-55555), true);
  EXPECT_EQ(set_int_5.contains(-55555), true);
  EXPECT_EQ(set_double_1.contains(-55555.55555), true);
  EXPECT_EQ(set_double_3.contains(-55555.55555), true);
  EXPECT_EQ(set_double_5.contains(-55555.55555), true);
  EXPECT_EQ(set_str_1.contains(" Jack O'Neill"), true);
  EXPECT_EQ(set_str_3.contains(" Jack O'Neill"), true);
  EXPECT_EQ(set_str_5.contains(" Jack O'Neill"), true);
  EXPECT_EQ(set_char_1.contains('\t'), true);
  EXPECT_EQ(set_char_3.contains('\t'), true);
  EXPECT_EQ(set_char_5.contains('\t'), true);
  EXPECT_EQ(*pair_int_1.first, -55555);
  EXPECT_EQ(*pair_int_2.first, -55555);
  EXPECT_EQ(*pair_int_3.first, -55555);
  EXPECT_EQ(*pair_int_4.first, -55555);
  EXPECT_EQ(*pair_int_5.first, -55555);
  EXPECT_EQ(*pair_int_6.first, -55555);
  EXPECT_EQ(*pair_double_1.first, -55555.55555);
  EXPECT_EQ(*pair_double_2.first, -55555.55555);
  EXPECT_EQ(*pair_double_3.first, -55555.55555);
  EXPECT_EQ(*pair_double_4.first, -55555.55555);
  EXPECT_EQ(*pair_double_5.first, -55555.55555);
  EXPECT_EQ(*pair_double_6.first, -55555.55555);
  EXPECT_EQ(*pair_str_1.first, " Jack O'Neill");
  EXPECT_EQ(*pair_str_2.first, " Jack O'Neill");
  EXPECT_EQ(*pair_str_3.first, " Jack O'Neill");
  EXPECT_EQ(*pair_str_4.first, " Jack O'Neill");
  EXPECT_EQ(*pair_str_5.first, " Jack O'Neill");
  EXPECT_EQ(*pair_str_6.first, " Jack O'Neill");
  EXPECT_EQ(*pair_char_1.first, '\t');
  EXPECT_EQ(*pair_char_2.first, '\t');
  EXPECT_EQ(*pair_char_3.first, '\t');
  EXPECT_EQ(*pair_char_4.first, '\t');
  EXPECT_EQ(*pair_char_5.first, '\t');
  EXPECT_EQ(*pair_char_6.first, '\t');
  EXPECT_EQ(*pair_int_1.first, *set_int_1.begin());
  EXPECT_EQ(*pair_int_2.first, *set_int_2.begin());
  EXPECT_EQ(*pair_int_3.first, *set_int_3.begin());
  EXPECT_EQ(*pair_int_4.first, *set_int_4.begin());
  EXPECT_EQ(*pair_int_5.first, *set_int_5.begin());
  EXPECT_EQ(*pair_int_6.first, *set_int_6.begin());
  EXPECT_EQ(*pair_double_1.first, *set_double_1.begin());
  EXPECT_EQ(*pair_double_2.first, *set_double_2.begin());
  EXPECT_EQ(*pair_double_3.first, *set_double_3.begin());
  EXPECT_EQ(*pair_double_4.first, *set_double_4.begin());
  EXPECT_EQ(*pair_double_5.first, *set_double_5.begin());
  EXPECT_EQ(*pair_double_6.first, *set_double_6.begin());
  EXPECT_EQ(*pair_str_1.first, *set_str_1.begin());
  EXPECT_EQ(*pair_str_2.first, *set_str_2.begin());
  EXPECT_EQ(*pair_str_3.first, *set_str_3.begin());
  EXPECT_EQ(*pair_str_4.first, *set_str_4.begin());
  EXPECT_EQ(*pair_str_5.first, *set_str_5.begin());
  EXPECT_EQ(*pair_str_6.first, *set_str_6.begin());
  EXPECT_EQ(*pair_char_1.first, *set_char_1.begin());
  EXPECT_EQ(*pair_char_2.first, *set_char_2.begin());
  EXPECT_EQ(*pair_char_3.first, *set_char_3.begin());
  EXPECT_EQ(*pair_char_4.first, *set_char_4.begin());
  EXPECT_EQ(*pair_char_5.first, *set_char_5.begin());
  EXPECT_EQ(*pair_char_6.first, *set_char_6.begin());

  pair_int_1 = set_int_1.insert(-55555);
  pair_int_2 = set_int_2.insert(-55555);
  pair_int_3 = set_int_3.insert(-55555);
  pair_int_4 = set_int_4.insert(-55555);
  pair_int_5 = set_int_5.insert(-55555);
  pair_int_6 = set_int_6.insert(-55555);
  pair_double_1 = set_double_1.insert(-55555.55555);
  pair_double_2 = set_double_2.insert(-55555.55555);
  pair_double_3 = set_double_3.insert(-55555.55555);
  pair_double_4 = set_double_4.insert(-55555.55555);
  pair_double_5 = set_double_5.insert(-55555.55555);
  pair_double_6 = set_double_6.insert(-55555.55555);
  pair_str_1 = set_str_1.insert(" Jack O'Neill");
  pair_str_2 = set_str_2.insert(" Jack O'Neill");
  pair_str_3 = set_str_3.insert(" Jack O'Neill");
  pair_str_4 = set_str_4.insert(" Jack O'Neill");
  pair_str_5 = set_str_5.insert(" Jack O'Neill");
  pair_str_6 = set_str_6.insert(" Jack O'Neill");
  pair_char_1 = set_char_1.insert('\t');
  pair_char_2 = set_char_2.insert('\t');
  pair_char_3 = set_char_3.insert('\t');
  pair_char_4 = set_char_4.insert('\t');
  pair_char_5 = set_char_5.insert('\t');
  pair_char_6 = set_char_6.insert('\t');
  EXPECT_EQ(pair_int_1.second, false);
  EXPECT_EQ(pair_int_2.second, false);
  EXPECT_EQ(pair_int_3.second, false);
  EXPECT_EQ(pair_int_4.second, false);
  EXPECT_EQ(pair_int_5.second, false);
  EXPECT_EQ(pair_int_6.second, false);
  EXPECT_EQ(pair_double_1.second, false);
  EXPECT_EQ(pair_double_2.second, false);
  EXPECT_EQ(pair_double_3.second, false);
  EXPECT_EQ(pair_double_4.second, false);
  EXPECT_EQ(pair_double_5.second, false);
  EXPECT_EQ(pair_double_6.second, false);
  EXPECT_EQ(pair_str_1.second, false);
  EXPECT_EQ(pair_str_2.second, false);
  EXPECT_EQ(pair_str_3.second, false);
  EXPECT_EQ(pair_str_4.second, false);
  EXPECT_EQ(pair_str_5.second, false);
  EXPECT_EQ(pair_str_6.second, false);
  EXPECT_EQ(pair_char_1.second, false);
  EXPECT_EQ(pair_char_2.second, false);
  EXPECT_EQ(pair_char_3.second, false);
  EXPECT_EQ(pair_char_4.second, false);
  EXPECT_EQ(pair_char_5.second, false);
  EXPECT_EQ(pair_char_6.second, false);
  EXPECT_EQ(set_int_1.contains(-55555), true);
  EXPECT_EQ(set_int_3.contains(-55555), true);
  EXPECT_EQ(set_int_5.contains(-55555), true);
  EXPECT_EQ(set_double_1.contains(-55555.55555), true);
  EXPECT_EQ(set_double_3.contains(-55555.55555), true);
  EXPECT_EQ(set_double_5.contains(-55555.55555), true);
  EXPECT_EQ(set_str_1.contains(" Jack O'Neill"), true);
  EXPECT_EQ(set_str_3.contains(" Jack O'Neill"), true);
  EXPECT_EQ(set_str_5.contains(" Jack O'Neill"), true);
  EXPECT_EQ(set_char_1.contains('\t'), true);
  EXPECT_EQ(set_char_3.contains('\t'), true);
  EXPECT_EQ(set_char_5.contains('\t'), true);
}
TEST(SetTest, Bonus) {
  my_containers::set<int> set_int_1;
  my_containers::set<double> set_double_1;
  my_containers::set<std::string> set_str_1;
  my_containers::set<char> set_char_1;
  EXPECT_EQ(set_int_1.size(), 0);
  EXPECT_EQ(set_double_1.size(), 0);
  EXPECT_EQ(set_str_1.size(), 0);
  EXPECT_EQ(set_char_1.size(), 0);

  set_int_1.insert_many();
  set_double_1.insert_many();
  set_str_1.insert_many();
  set_char_1.insert_many();
  EXPECT_EQ(set_int_1.size(), 0);
  EXPECT_EQ(set_double_1.size(), 0);
  EXPECT_EQ(set_str_1.size(), 0);
  EXPECT_EQ(set_char_1.size(), 0);

  set_int_1.insert_many(10, 2, 3, 44, 5, 66, -5, -100, 0, 0, 0, 5, 33, 23, 64,
                        55, 0, 1, 1000);
  set_double_1.insert_many(555.55, 423.2, 2, 1000, -55.55, -33.3, -1000, 100,
                           1000, 100, -5.5);
  set_str_1.insert_many("Jazz", "Me", "played", "with", "Blues", "brothers",
                        "like", "Yoda", "Wow", "!");
  set_char_1.insert_many('a', 'b', 'c', 'd', '5', '1', 'a', '-', '=', '+', 'q',
                         '\n', 'h', 'y', ']', '[', '(', '`');
  EXPECT_EQ(set_int_1.size(), 15);
  EXPECT_EQ(set_double_1.size(), 9);
  EXPECT_EQ(set_str_1.size(), 10);
  EXPECT_EQ(set_char_1.size(), 17);

  set_int_1.insert_many(100000);
  set_double_1.insert_many(555.55555);
  set_str_1.insert_many("J", "K");
  set_char_1.insert_many('}');
  EXPECT_EQ(set_int_1.size(), 16);
  EXPECT_EQ(set_double_1.size(), 10);
  EXPECT_EQ(set_str_1.size(), 12);
  EXPECT_EQ(set_char_1.size(), 18);

  my_containers::vector<
      std::pair<my_containers::set<std::string>::iterator, bool>>
      vec;
  vec = set_str_1.insert_many("agents", "J", "and", "K", "were not", "brothers",
                              "but", "played", "together", "like", "one", "!");
  EXPECT_EQ(vec.size(), 12);
  EXPECT_EQ(*vec[0].first, "agents");

  for (size_t i = 0; i < vec.size(); i++) {
    if (i % 2)
      EXPECT_EQ(vec[i].second, false);
    else {
      EXPECT_EQ(vec[i].second, true);
      EXPECT_EQ(set_str_1.contains(*vec[i].first), true);
    }
  }
}