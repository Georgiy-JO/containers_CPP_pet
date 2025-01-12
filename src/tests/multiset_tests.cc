#include "global_tests.h"
// #include "../containers/multiset/multiset.hpp"
#include <set>

void multisetIntConstructor(my_containers::multiset<int>& multiset_int) {
  multiset_int.insert_many(10, 2, 3, 44, 5, 66, -5, -100, 0, 0, 0, 5, 33, 23,
                           64, 55, 0, 1, 1000);
  EXPECT_EQ(multiset_int.size(), 19);
  multiset_int.insert(-100);
  multiset_int.insert(-100);
  multiset_int.insert(-100);
  multiset_int.insert(-100);
  multiset_int.insert(-100);
  multiset_int.insert(-100);
  multiset_int.insert(-100);
  multiset_int.insert(-100);
  multiset_int.insert(-100);
  multiset_int.insert(-100);
  multiset_int.insert(-100);
  multiset_int.insert(-100);
  EXPECT_EQ(multiset_int.size(), 31);
}
void multisetIntConstructorSTD(std::multiset<int>& multiset_int_2) {
  multiset_int_2.insert(10);
  multiset_int_2.insert(2);
  multiset_int_2.insert(3);
  multiset_int_2.insert(44);
  multiset_int_2.insert(5);
  multiset_int_2.insert(66);
  multiset_int_2.insert(-5);
  multiset_int_2.insert(-100);
  multiset_int_2.insert(0);
  multiset_int_2.insert(0);
  multiset_int_2.insert(0);
  multiset_int_2.insert(5);
  multiset_int_2.insert(33);
  multiset_int_2.insert(23);
  multiset_int_2.insert(64);
  multiset_int_2.insert(55);
  multiset_int_2.insert(0);
  multiset_int_2.insert(1);
  multiset_int_2.insert(1000);
  EXPECT_EQ(multiset_int_2.size(), 19);
  multiset_int_2.insert(-100);
  multiset_int_2.insert(-100);
  multiset_int_2.insert(-100);
  multiset_int_2.insert(-100);
  multiset_int_2.insert(-100);
  multiset_int_2.insert(-100);
  multiset_int_2.insert(-100);
  multiset_int_2.insert(-100);
  multiset_int_2.insert(-100);
  multiset_int_2.insert(-100);
  multiset_int_2.insert(-100);
  multiset_int_2.insert(-100);
  EXPECT_EQ(multiset_int_2.size(), 31);
}
void multisetDoubleConstructor(
    my_containers::multiset<double>& multiset_double) {
  multiset_double.insert_many(555.55, 423.2, 2, 1000, -55.55, -33.3, -1000, 100,
                              1000, 100, -5.5);
  EXPECT_EQ(multiset_double.size(), 11);
  multiset_double.insert(-55.55);
  multiset_double.insert(-55.55);
  multiset_double.insert(-55.55);
  multiset_double.insert(-55.55);
  multiset_double.insert(-55.55);
  multiset_double.insert(-55.55);
  multiset_double.insert(-55.55);
  multiset_double.insert(-55.55);
  multiset_double.insert(-55.55);
  multiset_double.insert(-55.55);
  multiset_double.insert(-55.55);
  EXPECT_EQ(multiset_double.size(), 22);
}
void multisetDoubleConstructorSTD(std::multiset<double>& multiset_double_2) {
  multiset_double_2.insert(555.55);
  multiset_double_2.insert(423.2);
  multiset_double_2.insert(2);
  multiset_double_2.insert(1000);
  multiset_double_2.insert(-55.55);
  multiset_double_2.insert(-33.3);
  multiset_double_2.insert(-1000);
  multiset_double_2.insert(100);
  multiset_double_2.insert(1000);
  multiset_double_2.insert(100);
  multiset_double_2.insert(-5.5);
  EXPECT_EQ(multiset_double_2.size(), 11);
  multiset_double_2.insert(-55.55);
  multiset_double_2.insert(-55.55);
  multiset_double_2.insert(-55.55);
  multiset_double_2.insert(-55.55);
  multiset_double_2.insert(-55.55);
  multiset_double_2.insert(-55.55);
  multiset_double_2.insert(-55.55);
  multiset_double_2.insert(-55.55);
  multiset_double_2.insert(-55.55);
  multiset_double_2.insert(-55.55);
  multiset_double_2.insert(-55.55);
  EXPECT_EQ(multiset_double_2.size(), 22);
}
void multisetStringConstructor(
    my_containers::multiset<std::string>& multiset_str) {
  multiset_str.insert_many("Jazz", "Me", "played", "with", "Blues", "brothers",
                           "like", "Yoda", "Wow", "!");
  EXPECT_EQ(multiset_str.size(), 10);
  multiset_str.insert("Rock");
  multiset_str.insert("Rock");
  multiset_str.insert("Rock");
  multiset_str.insert("Rock");
  multiset_str.insert("Rock");
  multiset_str.insert("Rock");
  multiset_str.insert("Rock");
  multiset_str.insert("Rock");
  multiset_str.insert("Rock");
  multiset_str.insert("Rock");
  multiset_str.insert("Rock");
  multiset_str.insert("Rock");
  multiset_str.insert("Rock");
  multiset_str.insert("Rock");
  multiset_str.insert("Rock");
  EXPECT_EQ(multiset_str.size(), 25);
}
void multisetStringConstructorSTD(std::multiset<std::string>& multiset_str_2) {
  multiset_str_2.insert("Jazz");
  multiset_str_2.insert("Me");
  multiset_str_2.insert("played");
  multiset_str_2.insert("with");
  multiset_str_2.insert("Blues");
  multiset_str_2.insert("brothers");
  multiset_str_2.insert("like");
  multiset_str_2.insert("Yoda");
  multiset_str_2.insert("Wow");
  multiset_str_2.insert("!");
  EXPECT_EQ(multiset_str_2.size(), 10);
  multiset_str_2.insert("Rock");
  multiset_str_2.insert("Rock");
  multiset_str_2.insert("Rock");
  multiset_str_2.insert("Rock");
  multiset_str_2.insert("Rock");
  multiset_str_2.insert("Rock");
  multiset_str_2.insert("Rock");
  multiset_str_2.insert("Rock");
  multiset_str_2.insert("Rock");
  multiset_str_2.insert("Rock");
  multiset_str_2.insert("Rock");
  multiset_str_2.insert("Rock");
  multiset_str_2.insert("Rock");
  multiset_str_2.insert("Rock");
  multiset_str_2.insert("Rock");
  EXPECT_EQ(multiset_str_2.size(), 25);
}
void multisetCharConstructor(my_containers::multiset<char>& multiset_char) {
  multiset_char.insert_many('a', 'b', 'c', 'd', '5', '1', 'a', '-', '=', '+',
                            'q', '\n', '\t', 'y', ']', '[', '(', '`');
  EXPECT_EQ(multiset_char.size(), 18);
  multiset_char.insert('-');
  multiset_char.insert('-');
  multiset_char.insert('-');
  multiset_char.insert('-');
  multiset_char.insert('-');
  multiset_char.insert('-');
  multiset_char.insert('-');
  multiset_char.insert('-');
  multiset_char.insert('-');
  multiset_char.insert('-');
  multiset_char.insert('-');
  EXPECT_EQ(multiset_char.size(), 29);
}
void multisetCharConstructorSTD(std::multiset<char>& multiset_char_2) {
  multiset_char_2.insert('a');
  multiset_char_2.insert('b');
  multiset_char_2.insert('c');
  multiset_char_2.insert('d');
  multiset_char_2.insert('5');
  multiset_char_2.insert('1');
  multiset_char_2.insert('a');
  multiset_char_2.insert('-');
  multiset_char_2.insert('=');
  multiset_char_2.insert('+');
  multiset_char_2.insert('q');
  multiset_char_2.insert('\n');
  multiset_char_2.insert('\t');
  multiset_char_2.insert('y');
  multiset_char_2.insert(']');
  multiset_char_2.insert('[');
  multiset_char_2.insert('(');
  multiset_char_2.insert('`');
  EXPECT_EQ(multiset_char_2.size(), 18);
  multiset_char_2.insert('-');
  multiset_char_2.insert('-');
  multiset_char_2.insert('-');
  multiset_char_2.insert('-');
  multiset_char_2.insert('-');
  multiset_char_2.insert('-');
  multiset_char_2.insert('-');
  multiset_char_2.insert('-');
  multiset_char_2.insert('-');
  multiset_char_2.insert('-');
  multiset_char_2.insert('-');
  EXPECT_EQ(multiset_char_2.size(), 29);
}

TEST(MultisetTest, ListConstruxtor) {
  my_containers::multiset<int> multiset_int{
      10, 2, 3, 44, 5, 66, -5, -100, 0, 0, 0, 5, 33, 23, 64, 55, 0, 1, 1000};
  std::multiset<int> multiset_int_2{10, 2, 3,  44, 5,  66, -5, -100, 0,   0,
                                    0,  5, 33, 23, 64, 55, 0,  1,    1000};
  my_containers::multiset<double> multiset_double{
      555.55, 423.2, 2, 1000, -55.55, -33.3, -1000, 100, 1000, 100, -5.5};
  std::multiset<double> multiset_double_2{
      555.55, 423.2, 2, 1000, -55.55, -33.3, -1000, 100, 1000, 100, -5.5};
  my_containers::multiset<std::string> multiset_str{
      "Jazz",     "Me",   "played", "with", "Blues",
      "brothers", "like", "Yoda",   "Wow",  "!"};
  std::multiset<std::string> multiset_str_2{
      "Jazz",     "Me",   "played", "with", "Blues",
      "brothers", "like", "Yoda",   "Wow",  "!"};
  my_containers::multiset<char> multiset_char{'a',  'b', 'c', 'd', '5', '1',
                                              'a',  '-', '=', '+', 'q', '\n',
                                              '\t', 'y', ']', '[', '(', '`'};
  std::multiset<char> multiset_char_2{'a',  'b', 'c', 'd', '5', '1',
                                      'a',  '-', '=', '+', 'q', '\n',
                                      '\t', 'y', ']', '[', '(', '`'};
  EXPECT_EQ(multiset_int.size(), 19);
  EXPECT_EQ(multiset_int_2.size(), 19);
  EXPECT_EQ(multiset_double.size(), 11);
  EXPECT_EQ(multiset_double_2.size(), 11);
  EXPECT_EQ(multiset_str.size(), 10);
  EXPECT_EQ(multiset_str_2.size(), 10);
  EXPECT_EQ(multiset_char.size(), 18);
  EXPECT_EQ(multiset_char_2.size(), 18);
  EXPECT_EQ(multiset_int.empty(), false);
  EXPECT_EQ(multiset_int_2.empty(), false);
  EXPECT_EQ(multiset_double.empty(), false);
  EXPECT_EQ(multiset_double_2.empty(), false);
  EXPECT_EQ(multiset_str.empty(), false);
  EXPECT_EQ(multiset_str_2.empty(), false);
  EXPECT_EQ(multiset_char.empty(), false);
  EXPECT_EQ(multiset_char_2.empty(), false);
  EXPECT_EQ(multiset_int.contains(66), true);
  EXPECT_EQ(multiset_int.contains(666), false);

  multiset_int.insert(-100);
  multiset_int.insert(-100);
  multiset_int.insert(-100);
  multiset_int.insert(-100);
  multiset_int.insert(-100);
  multiset_int.insert(-100);
  multiset_int.insert(-100);
  multiset_int.insert(-100);
  multiset_int.insert(-100);
  multiset_int.insert(-100);
  multiset_int.insert(-100);
  multiset_int.insert(-100);
  multiset_int_2.insert(-100);
  multiset_int_2.insert(-100);
  multiset_int_2.insert(-100);
  multiset_int_2.insert(-100);
  multiset_int_2.insert(-100);
  multiset_int_2.insert(-100);
  multiset_int_2.insert(-100);
  multiset_int_2.insert(-100);
  multiset_int_2.insert(-100);
  multiset_int_2.insert(-100);
  multiset_int_2.insert(-100);
  multiset_int_2.insert(-100);
  multiset_double.insert(-55.55);
  multiset_double.insert(-55.55);
  multiset_double.insert(-55.55);
  multiset_double.insert(-55.55);
  multiset_double.insert(-55.55);
  multiset_double.insert(-55.55);
  multiset_double.insert(-55.55);
  multiset_double.insert(-55.55);
  multiset_double.insert(-55.55);
  multiset_double.insert(-55.55);
  multiset_double.insert(-55.55);
  multiset_double_2.insert(-55.55);
  multiset_double_2.insert(-55.55);
  multiset_double_2.insert(-55.55);
  multiset_double_2.insert(-55.55);
  multiset_double_2.insert(-55.55);
  multiset_double_2.insert(-55.55);
  multiset_double_2.insert(-55.55);
  multiset_double_2.insert(-55.55);
  multiset_double_2.insert(-55.55);
  multiset_double_2.insert(-55.55);
  multiset_double_2.insert(-55.55);
  multiset_str.insert("Rock");
  multiset_str.insert("Rock");
  multiset_str.insert("Rock");
  multiset_str.insert("Rock");
  multiset_str.insert("Rock");
  multiset_str.insert("Rock");
  multiset_str.insert("Rock");
  multiset_str.insert("Rock");
  multiset_str.insert("Rock");
  multiset_str.insert("Rock");
  multiset_str.insert("Rock");
  multiset_str.insert("Rock");
  multiset_str.insert("Rock");
  multiset_str.insert("Rock");
  multiset_str.insert("Rock");
  multiset_str_2.insert("Rock");
  multiset_str_2.insert("Rock");
  multiset_str_2.insert("Rock");
  multiset_str_2.insert("Rock");
  multiset_str_2.insert("Rock");
  multiset_str_2.insert("Rock");
  multiset_str_2.insert("Rock");
  multiset_str_2.insert("Rock");
  multiset_str_2.insert("Rock");
  multiset_str_2.insert("Rock");
  multiset_str_2.insert("Rock");
  multiset_str_2.insert("Rock");
  multiset_str_2.insert("Rock");
  multiset_str_2.insert("Rock");
  multiset_str_2.insert("Rock");
  multiset_char.insert('-');
  multiset_char.insert('-');
  multiset_char.insert('-');
  multiset_char.insert('-');
  multiset_char.insert('-');
  multiset_char.insert('-');
  multiset_char.insert('-');
  multiset_char.insert('-');
  multiset_char.insert('-');
  multiset_char.insert('-');
  multiset_char.insert('-');
  multiset_char_2.insert('-');
  multiset_char_2.insert('-');
  multiset_char_2.insert('-');
  multiset_char_2.insert('-');
  multiset_char_2.insert('-');
  multiset_char_2.insert('-');
  multiset_char_2.insert('-');
  multiset_char_2.insert('-');
  multiset_char_2.insert('-');
  multiset_char_2.insert('-');
  multiset_char_2.insert('-');

  EXPECT_EQ(multiset_int.size(), 31);
  EXPECT_EQ(multiset_int_2.size(), 31);
  EXPECT_EQ(multiset_double.size(), 22);
  EXPECT_EQ(multiset_double_2.size(), 22);
  EXPECT_EQ(multiset_str.size(), 25);
  EXPECT_EQ(multiset_str_2.size(), 25);
  EXPECT_EQ(multiset_char.size(), 29);
  EXPECT_EQ(multiset_char_2.size(), 29);
}
TEST(MultisetTest, DefaultConstruxtor_Empty_Bonus) {
  my_containers::multiset<int> multiset_int;
  std::multiset<int> multiset_int_2;
  my_containers::multiset<double> multiset_double;
  std::multiset<double> multiset_double_2;
  my_containers::multiset<std::string> multiset_str;
  std::multiset<std::string> multiset_str_2;
  my_containers::multiset<char> multiset_char;
  std::multiset<char> multiset_char_2;
  EXPECT_EQ(multiset_int.size(), 0);
  EXPECT_EQ(multiset_int_2.size(), 0);
  EXPECT_EQ(multiset_double.size(), 0);
  EXPECT_EQ(multiset_double_2.size(), 0);
  EXPECT_EQ(multiset_str.size(), 0);
  EXPECT_EQ(multiset_str_2.size(), 0);
  EXPECT_EQ(multiset_char.size(), 0);
  EXPECT_EQ(multiset_char_2.size(), 0);
  EXPECT_EQ(multiset_int.empty(), true);
  EXPECT_EQ(multiset_int_2.empty(), true);
  EXPECT_EQ(multiset_double.empty(), true);
  EXPECT_EQ(multiset_double_2.empty(), true);
  EXPECT_EQ(multiset_str.empty(), true);
  EXPECT_EQ(multiset_str_2.empty(), true);
  EXPECT_EQ(multiset_char.empty(), true);
  EXPECT_EQ(multiset_char_2.empty(), true);

  multisetIntConstructor(multiset_int);
  multisetIntConstructorSTD(multiset_int_2);
  multisetDoubleConstructor(multiset_double);
  multisetDoubleConstructorSTD(multiset_double_2);
  multisetStringConstructor(multiset_str);
  multisetStringConstructorSTD(multiset_str_2);
  multisetCharConstructor(multiset_char);
  multisetCharConstructorSTD(multiset_char_2);

  EXPECT_EQ(multiset_int.size(), 31);
  EXPECT_EQ(multiset_int_2.size(), 31);
  EXPECT_EQ(multiset_double.size(), 22);
  EXPECT_EQ(multiset_double_2.size(), 22);
  EXPECT_EQ(multiset_str.size(), 25);
  EXPECT_EQ(multiset_str_2.size(), 25);
  EXPECT_EQ(multiset_char.size(), 29);
  EXPECT_EQ(multiset_char_2.size(), 29);
  EXPECT_EQ(multiset_int.empty(), false);
  EXPECT_EQ(multiset_int_2.empty(), false);
  EXPECT_EQ(multiset_double.empty(), false);
  EXPECT_EQ(multiset_double_2.empty(), false);
  EXPECT_EQ(multiset_str.empty(), false);
  EXPECT_EQ(multiset_str_2.empty(), false);
  EXPECT_EQ(multiset_char.empty(), false);
  EXPECT_EQ(multiset_char_2.empty(), false);
  EXPECT_EQ(multiset_int.contains(66), true);
  EXPECT_EQ(multiset_int.contains(666), false);

  multiset_int.clear();
  multiset_int_2.clear();
  multiset_double.clear();
  multiset_double_2.clear();
  multiset_str.clear();
  multiset_str_2.clear();
  multiset_char.clear();
  multiset_char_2.clear();
  EXPECT_EQ(multiset_int.size(), 0);
  EXPECT_EQ(multiset_int_2.size(), 0);
  EXPECT_EQ(multiset_double.size(), 0);
  EXPECT_EQ(multiset_double_2.size(), 0);
  EXPECT_EQ(multiset_str.size(), 0);
  EXPECT_EQ(multiset_str_2.size(), 0);
  EXPECT_EQ(multiset_char.size(), 0);
  EXPECT_EQ(multiset_char_2.size(), 0);
  EXPECT_EQ(multiset_int.empty(), true);
  EXPECT_EQ(multiset_int_2.empty(), true);
  EXPECT_EQ(multiset_double.empty(), true);
  EXPECT_EQ(multiset_double_2.empty(), true);
  EXPECT_EQ(multiset_str.empty(), true);
  EXPECT_EQ(multiset_str_2.empty(), true);
  EXPECT_EQ(multiset_char.empty(), true);
  EXPECT_EQ(multiset_char_2.empty(), true);
}
TEST(MultisetTest, Clear) {
  my_containers::multiset<int> multiset_int;
  std::multiset<int> multiset_int_2;
  my_containers::multiset<double> multiset_double;
  std::multiset<double> multiset_double_2;
  my_containers::multiset<std::string> multiset_str;
  std::multiset<std::string> multiset_str_2;
  my_containers::multiset<char> multiset_char;
  std::multiset<char> multiset_char_2;
  multisetIntConstructor(multiset_int);
  multisetIntConstructorSTD(multiset_int_2);
  multisetDoubleConstructor(multiset_double);
  multisetDoubleConstructorSTD(multiset_double_2);
  multisetStringConstructor(multiset_str);
  multisetStringConstructorSTD(multiset_str_2);
  multisetCharConstructor(multiset_char);
  multisetCharConstructorSTD(multiset_char_2);

  EXPECT_EQ(multiset_int.size(), 31);
  EXPECT_EQ(multiset_int_2.size(), 31);
  EXPECT_EQ(multiset_double.size(), 22);
  EXPECT_EQ(multiset_double_2.size(), 22);
  EXPECT_EQ(multiset_str.size(), 25);
  EXPECT_EQ(multiset_str_2.size(), 25);
  EXPECT_EQ(multiset_char.size(), 29);
  EXPECT_EQ(multiset_char_2.size(), 29);
  EXPECT_EQ(multiset_int.empty(), false);
  EXPECT_EQ(multiset_int_2.empty(), false);
  EXPECT_EQ(multiset_double.empty(), false);
  EXPECT_EQ(multiset_double_2.empty(), false);
  EXPECT_EQ(multiset_str.empty(), false);
  EXPECT_EQ(multiset_str_2.empty(), false);
  EXPECT_EQ(multiset_char.empty(), false);
  EXPECT_EQ(multiset_char_2.empty(), false);
  EXPECT_EQ(multiset_int.contains(66), true);
  EXPECT_EQ(multiset_int.contains(666), false);

  multiset_int.clear();
  multiset_int_2.clear();
  multiset_double.clear();
  multiset_double_2.clear();
  multiset_str.clear();
  multiset_str_2.clear();
  multiset_char.clear();
  multiset_char_2.clear();
  EXPECT_EQ(multiset_int.size(), 0);
  EXPECT_EQ(multiset_int_2.size(), 0);
  EXPECT_EQ(multiset_double.size(), 0);
  EXPECT_EQ(multiset_double_2.size(), 0);
  EXPECT_EQ(multiset_str.size(), 0);
  EXPECT_EQ(multiset_str_2.size(), 0);
  EXPECT_EQ(multiset_char.size(), 0);
  EXPECT_EQ(multiset_char_2.size(), 0);
  EXPECT_EQ(multiset_int.empty(), true);
  EXPECT_EQ(multiset_int_2.empty(), true);
  EXPECT_EQ(multiset_double.empty(), true);
  EXPECT_EQ(multiset_double_2.empty(), true);
  EXPECT_EQ(multiset_str.empty(), true);
  EXPECT_EQ(multiset_str_2.empty(), true);
  EXPECT_EQ(multiset_char.empty(), true);
  EXPECT_EQ(multiset_char_2.empty(), true);
}
TEST(MultisetTest, MoveConstruxtor) {
  my_containers::multiset<int> multiset_int_1;
  std::multiset<int> multiset_int_2;
  my_containers::multiset<double> multiset_double_1;
  std::multiset<double> multiset_double_2;
  my_containers::multiset<std::string> multiset_str_1;
  std::multiset<std::string> multiset_str_2;
  my_containers::multiset<char> multiset_char_1;
  std::multiset<char> multiset_char_2;
  multisetIntConstructor(multiset_int_1);
  multisetIntConstructorSTD(multiset_int_2);
  multisetDoubleConstructor(multiset_double_1);
  multisetDoubleConstructorSTD(multiset_double_2);
  multisetStringConstructor(multiset_str_1);
  multisetStringConstructorSTD(multiset_str_2);
  multisetCharConstructor(multiset_char_1);
  multisetCharConstructorSTD(multiset_char_2);

  my_containers::multiset<int> multiset_int_3(std::move(multiset_int_1));
  std::multiset<int> multiset_int_4(std::move(multiset_int_2));
  my_containers::multiset<double> multiset_double_3(
      std::move(multiset_double_1));
  std::multiset<double> multiset_double_4(std::move(multiset_double_2));
  my_containers::multiset<std::string> multiset_str_3(
      std::move(multiset_str_1));
  std::multiset<std::string> multiset_str_4(std::move(multiset_str_2));
  my_containers::multiset<char> multiset_char_3(std::move(multiset_char_1));
  std::multiset<char> multiset_char_4(std::move(multiset_char_2));
  EXPECT_EQ(multiset_int_3.size(), 31);
  EXPECT_EQ(multiset_int_4.size(), 31);
  EXPECT_EQ(multiset_double_3.size(), 22);
  EXPECT_EQ(multiset_double_4.size(), 22);
  EXPECT_EQ(multiset_str_3.size(), 25);
  EXPECT_EQ(multiset_str_4.size(), 25);
  EXPECT_EQ(multiset_char_3.size(), 29);
  EXPECT_EQ(multiset_char_4.size(), 29);
  EXPECT_EQ(multiset_int_3.empty(), false);
  EXPECT_EQ(multiset_int_4.empty(), false);
  EXPECT_EQ(multiset_double_3.empty(), false);
  EXPECT_EQ(multiset_double_4.empty(), false);
  EXPECT_EQ(multiset_str_3.empty(), false);
  EXPECT_EQ(multiset_str_4.empty(), false);
  EXPECT_EQ(multiset_char_3.empty(), false);
  EXPECT_EQ(multiset_char_4.empty(), false);
  EXPECT_EQ(multiset_int_1.size(), 0);
  EXPECT_EQ(multiset_int_2.size(), 0);
  EXPECT_EQ(multiset_double_1.size(), 0);
  EXPECT_EQ(multiset_double_2.size(), 0);
  EXPECT_EQ(multiset_str_1.size(), 0);
  EXPECT_EQ(multiset_str_2.size(), 0);
  EXPECT_EQ(multiset_char_1.size(), 0);
  EXPECT_EQ(multiset_char_2.size(), 0);
  EXPECT_EQ(multiset_int_1.empty(), true);
  EXPECT_EQ(multiset_int_2.empty(), true);
  EXPECT_EQ(multiset_double_1.empty(), true);
  EXPECT_EQ(multiset_double_2.empty(), true);
  EXPECT_EQ(multiset_str_1.empty(), true);
  EXPECT_EQ(multiset_str_2.empty(), true);
  EXPECT_EQ(multiset_char_1.empty(), true);
  EXPECT_EQ(multiset_char_2.empty(), true);
}
TEST(MultisetTest, CopyConstruxtor) {
  my_containers::multiset<int> multiset_int_1;
  std::multiset<int> multiset_int_2;
  my_containers::multiset<double> multiset_double_1;
  std::multiset<double> multiset_double_2;
  my_containers::multiset<std::string> multiset_str_1;
  std::multiset<std::string> multiset_str_2;
  my_containers::multiset<char> multiset_char_1;
  std::multiset<char> multiset_char_2;
  multisetIntConstructor(multiset_int_1);
  multisetIntConstructorSTD(multiset_int_2);
  multisetDoubleConstructor(multiset_double_1);
  multisetDoubleConstructorSTD(multiset_double_2);
  multisetStringConstructor(multiset_str_1);
  multisetStringConstructorSTD(multiset_str_2);
  multisetCharConstructor(multiset_char_1);
  multisetCharConstructorSTD(multiset_char_2);

  my_containers::multiset<int> multiset_int_3(multiset_int_1);
  std::multiset<int> multiset_int_4(multiset_int_2);
  my_containers::multiset<double> multiset_double_3(multiset_double_1);
  std::multiset<double> multiset_double_4(multiset_double_2);
  my_containers::multiset<std::string> multiset_str_3(multiset_str_1);
  std::multiset<std::string> multiset_str_4(multiset_str_2);
  my_containers::multiset<char> multiset_char_3(multiset_char_1);
  std::multiset<char> multiset_char_4(multiset_char_2);
  EXPECT_EQ(multiset_int_3.size(), 31);
  EXPECT_EQ(multiset_int_4.size(), 31);
  EXPECT_EQ(multiset_double_3.size(), 22);
  EXPECT_EQ(multiset_double_4.size(), 22);
  EXPECT_EQ(multiset_str_3.size(), 25);
  EXPECT_EQ(multiset_str_4.size(), 25);
  EXPECT_EQ(multiset_char_3.size(), 29);
  EXPECT_EQ(multiset_char_4.size(), 29);
  EXPECT_EQ(multiset_int_3.empty(), false);
  EXPECT_EQ(multiset_int_4.empty(), false);
  EXPECT_EQ(multiset_double_3.empty(), false);
  EXPECT_EQ(multiset_double_4.empty(), false);
  EXPECT_EQ(multiset_str_3.empty(), false);
  EXPECT_EQ(multiset_str_4.empty(), false);
  EXPECT_EQ(multiset_char_3.empty(), false);
  EXPECT_EQ(multiset_char_4.empty(), false);
  EXPECT_EQ(multiset_int_1.size(), 31);
  EXPECT_EQ(multiset_int_2.size(), 31);
  EXPECT_EQ(multiset_double_1.size(), 22);
  EXPECT_EQ(multiset_double_2.size(), 22);
  EXPECT_EQ(multiset_str_1.size(), 25);
  EXPECT_EQ(multiset_str_2.size(), 25);
  EXPECT_EQ(multiset_char_1.size(), 29);
  EXPECT_EQ(multiset_char_2.size(), 29);
  EXPECT_EQ(multiset_int_1.empty(), false);
  EXPECT_EQ(multiset_int_2.empty(), false);
  EXPECT_EQ(multiset_double_1.empty(), false);
  EXPECT_EQ(multiset_double_2.empty(), false);
  EXPECT_EQ(multiset_str_1.empty(), false);
  EXPECT_EQ(multiset_str_2.empty(), false);
  EXPECT_EQ(multiset_char_1.empty(), false);
  EXPECT_EQ(multiset_char_2.empty(), false);
}
/*
// This thest is systrm dependent -- may cause errors
TEST(MultisetTest, MaxSize) {
    my_containers::multiset<int> multiset_int_1;
    std::multiset<int> multiset_int_2;
    my_containers::multiset<double> multiset_double_1;
    std::multiset<double> multiset_double_2;
    my_containers::multiset<std::string> multiset_str_1;
    std::multiset<std::string> multiset_str_2;
    my_containers::multiset<char> multiset_char_1;
    std::multiset<char> multiset_char_2;
    multisetIntConstructor(multiset_int_1);
    multisetIntConstructorSTD(multiset_int_2);
    multisetDoubleConstructor(multiset_double_1);
    multisetDoubleConstructorSTD(multiset_double_2);
    multisetStringConstructor(multiset_str_1);
    multisetStringConstructorSTD(multiset_str_2);
    multisetCharConstructor(multiset_char_1);
    multisetCharConstructorSTD(multiset_char_2);
    EXPECT_EQ(multiset_int_1.max_size(), 576460752303423487);
    EXPECT_EQ(multiset_double_1.max_size(), 461168601842738790);
    EXPECT_EQ(multiset_str_1.max_size(), 209622091746699450);
    EXPECT_EQ(multiset_char_1.max_size(), 576460752303423487);
}
*/
TEST(MultisetTest, Begin) {
  my_containers::multiset<int> multiset_int_1;
  std::multiset<int> multiset_int_2;
  my_containers::multiset<double> multiset_double_1;
  std::multiset<double> multiset_double_2;
  my_containers::multiset<std::string> multiset_str_1;
  std::multiset<std::string> multiset_str_2;
  my_containers::multiset<char> multiset_char_1;
  std::multiset<char> multiset_char_2;
  multisetIntConstructor(multiset_int_1);
  multisetIntConstructorSTD(multiset_int_2);
  multisetDoubleConstructor(multiset_double_1);
  multisetDoubleConstructorSTD(multiset_double_2);
  multisetStringConstructor(multiset_str_1);
  multisetStringConstructorSTD(multiset_str_2);
  multisetCharConstructor(multiset_char_1);
  multisetCharConstructorSTD(multiset_char_2);

  EXPECT_EQ(*multiset_int_1.begin(), *multiset_int_2.begin());
  EXPECT_EQ(*multiset_double_1.begin(), *multiset_double_2.begin());
  EXPECT_EQ(*multiset_str_1.begin(), *multiset_str_2.begin());
  EXPECT_EQ(*multiset_char_1.begin(), *multiset_char_2.begin());
}
TEST(MultisetTest, End) {
  my_containers::multiset<int> multiset_int_1;
  std::multiset<int> multiset_int_2;
  my_containers::multiset<double> multiset_double_1;
  std::multiset<double> multiset_double_2;
  my_containers::multiset<std::string> multiset_str_1;
  std::multiset<std::string> multiset_str_2;
  my_containers::multiset<char> multiset_char_1;
  std::multiset<char> multiset_char_2;
  multisetIntConstructor(multiset_int_1);
  multisetIntConstructorSTD(multiset_int_2);
  multisetDoubleConstructor(multiset_double_1);
  multisetDoubleConstructorSTD(multiset_double_2);
  multisetStringConstructor(multiset_str_1);
  multisetStringConstructorSTD(multiset_str_2);
  multisetCharConstructor(multiset_char_1);
  multisetCharConstructorSTD(multiset_char_2);
  EXPECT_EQ(*multiset_int_1.end(), 1000);
  EXPECT_EQ(*multiset_double_1.end(), 1000.0);
  EXPECT_EQ(*multiset_str_1.end(), "with");
  EXPECT_EQ(*multiset_char_1.end(), 'y');
}
TEST(MultisetTest, Contains) {
  my_containers::multiset<int> multiset_int_1;
  std::multiset<int> multiset_int_2;
  my_containers::multiset<double> multiset_double_1;
  std::multiset<double> multiset_double_2;
  my_containers::multiset<std::string> multiset_str_1;
  std::multiset<std::string> multiset_str_2;
  my_containers::multiset<char> multiset_char_1;
  std::multiset<char> multiset_char_2;
  multisetIntConstructor(multiset_int_1);
  multisetIntConstructorSTD(multiset_int_2);
  multisetDoubleConstructor(multiset_double_1);
  multisetDoubleConstructorSTD(multiset_double_2);
  multisetStringConstructor(multiset_str_1);
  multisetStringConstructorSTD(multiset_str_2);
  multisetCharConstructor(multiset_char_1);
  multisetCharConstructorSTD(multiset_char_2);
  EXPECT_EQ(multiset_int_1.contains(1000), true);
  EXPECT_EQ(multiset_double_1.contains(1000.0), true);
  EXPECT_EQ(multiset_str_1.contains("Yoda"), true);
  EXPECT_EQ(multiset_char_1.contains('y'), true);
  EXPECT_EQ(multiset_int_1.contains(-100), true);
  EXPECT_EQ(multiset_double_1.contains(-55.55), true);
  EXPECT_EQ(multiset_str_1.contains("Rock"), true);
  EXPECT_EQ(multiset_char_1.contains('-'), true);
}
TEST(MultisetTest, MoveAssignment) {
  my_containers::multiset<int> multiset_int_1;
  std::multiset<int> multiset_int_2;
  my_containers::multiset<double> multiset_double_1;
  std::multiset<double> multiset_double_2;
  my_containers::multiset<std::string> multiset_str_1;
  std::multiset<std::string> multiset_str_2;
  my_containers::multiset<char> multiset_char_1;
  std::multiset<char> multiset_char_2;
  multisetIntConstructor(multiset_int_1);
  multisetIntConstructorSTD(multiset_int_2);
  multisetDoubleConstructor(multiset_double_1);
  multisetDoubleConstructorSTD(multiset_double_2);
  multisetStringConstructor(multiset_str_1);
  multisetStringConstructorSTD(multiset_str_2);
  multisetCharConstructor(multiset_char_1);
  multisetCharConstructorSTD(multiset_char_2);

  EXPECT_EQ(multiset_int_1.size(), 31);
  EXPECT_EQ(multiset_int_2.size(), 31);
  EXPECT_EQ(multiset_double_1.size(), 22);
  EXPECT_EQ(multiset_double_2.size(), 22);
  EXPECT_EQ(multiset_str_1.size(), 25);
  EXPECT_EQ(multiset_str_2.size(), 25);
  EXPECT_EQ(multiset_char_1.size(), 29);
  EXPECT_EQ(multiset_char_2.size(), 29);
  EXPECT_EQ(multiset_int_1.empty(), false);
  EXPECT_EQ(multiset_int_2.empty(), false);
  EXPECT_EQ(multiset_double_1.empty(), false);
  EXPECT_EQ(multiset_double_2.empty(), false);
  EXPECT_EQ(multiset_str_1.empty(), false);
  EXPECT_EQ(multiset_str_2.empty(), false);
  EXPECT_EQ(multiset_char_1.empty(), false);
  EXPECT_EQ(multiset_char_2.empty(), false);

  my_containers::multiset<int> multiset_int_3;
  std::multiset<int> multiset_int_4;
  my_containers::multiset<double> multiset_double_3;
  std::multiset<double> multiset_double_4;
  my_containers::multiset<std::string> multiset_str_3;
  std::multiset<std::string> multiset_str_4;
  my_containers::multiset<char> multiset_char_3;
  std::multiset<char> multiset_char_4;

  EXPECT_EQ(multiset_int_3.size(), 0);
  EXPECT_EQ(multiset_int_4.size(), 0);
  EXPECT_EQ(multiset_double_3.size(), 0);
  EXPECT_EQ(multiset_double_4.size(), 0);
  EXPECT_EQ(multiset_str_3.size(), 0);
  EXPECT_EQ(multiset_str_4.size(), 0);
  EXPECT_EQ(multiset_char_3.size(), 0);
  EXPECT_EQ(multiset_char_4.size(), 0);
  EXPECT_EQ(multiset_int_3.empty(), true);
  EXPECT_EQ(multiset_int_4.empty(), true);
  EXPECT_EQ(multiset_double_3.empty(), true);
  EXPECT_EQ(multiset_double_4.empty(), true);
  EXPECT_EQ(multiset_str_3.empty(), true);
  EXPECT_EQ(multiset_str_4.empty(), true);
  EXPECT_EQ(multiset_char_3.empty(), true);
  EXPECT_EQ(multiset_char_4.empty(), true);

  multiset_int_3 = std::move(multiset_int_1);
  multiset_int_4 = std::move(multiset_int_2);
  multiset_double_3 = std::move(multiset_double_1);
  multiset_double_4 = std::move(multiset_double_2);
  multiset_str_3 = std::move(multiset_str_1);
  multiset_str_4 = std::move(multiset_str_2);
  multiset_char_3 = std::move(multiset_char_1);
  multiset_char_4 = std::move(multiset_char_2);

  EXPECT_EQ(multiset_int_3.size(), 31);
  EXPECT_EQ(multiset_int_4.size(), 31);
  EXPECT_EQ(multiset_double_3.size(), 22);
  EXPECT_EQ(multiset_double_4.size(), 22);
  EXPECT_EQ(multiset_str_3.size(), 25);
  EXPECT_EQ(multiset_str_4.size(), 25);
  EXPECT_EQ(multiset_char_3.size(), 29);
  EXPECT_EQ(multiset_char_4.size(), 29);
  EXPECT_EQ(multiset_int_3.empty(), false);
  EXPECT_EQ(multiset_int_4.empty(), false);
  EXPECT_EQ(multiset_double_3.empty(), false);
  EXPECT_EQ(multiset_double_4.empty(), false);
  EXPECT_EQ(multiset_str_3.empty(), false);
  EXPECT_EQ(multiset_str_4.empty(), false);
  EXPECT_EQ(multiset_char_3.empty(), false);
  EXPECT_EQ(multiset_char_4.empty(), false);
  EXPECT_EQ(multiset_int_1.size(), 0);
  EXPECT_EQ(multiset_int_2.size(), 0);
  EXPECT_EQ(multiset_double_1.size(), 0);
  EXPECT_EQ(multiset_double_2.size(), 0);
  EXPECT_EQ(multiset_str_1.size(), 0);
  EXPECT_EQ(multiset_str_2.size(), 0);
  EXPECT_EQ(multiset_char_1.size(), 0);
  EXPECT_EQ(multiset_char_2.size(), 0);
  EXPECT_EQ(multiset_int_1.empty(), true);
  EXPECT_EQ(multiset_int_2.empty(), true);
  EXPECT_EQ(multiset_double_1.empty(), true);
  EXPECT_EQ(multiset_double_2.empty(), true);
  EXPECT_EQ(multiset_str_1.empty(), true);
  EXPECT_EQ(multiset_str_2.empty(), true);
  EXPECT_EQ(multiset_char_1.empty(), true);
  EXPECT_EQ(multiset_char_2.empty(), true);
}
TEST(MultisetTest, CopyAssignment) {
  my_containers::multiset<int> multiset_int_1;
  std::multiset<int> multiset_int_2;
  my_containers::multiset<double> multiset_double_1;
  std::multiset<double> multiset_double_2;
  my_containers::multiset<std::string> multiset_str_1;
  std::multiset<std::string> multiset_str_2;
  my_containers::multiset<char> multiset_char_1;
  std::multiset<char> multiset_char_2;
  multisetIntConstructor(multiset_int_1);
  multisetIntConstructorSTD(multiset_int_2);
  multisetDoubleConstructor(multiset_double_1);
  multisetDoubleConstructorSTD(multiset_double_2);
  multisetStringConstructor(multiset_str_1);
  multisetStringConstructorSTD(multiset_str_2);
  multisetCharConstructor(multiset_char_1);
  multisetCharConstructorSTD(multiset_char_2);

  EXPECT_EQ(multiset_int_1.size(), 31);
  EXPECT_EQ(multiset_int_2.size(), 31);
  EXPECT_EQ(multiset_double_1.size(), 22);
  EXPECT_EQ(multiset_double_2.size(), 22);
  EXPECT_EQ(multiset_str_1.size(), 25);
  EXPECT_EQ(multiset_str_2.size(), 25);
  EXPECT_EQ(multiset_char_1.size(), 29);
  EXPECT_EQ(multiset_char_2.size(), 29);
  EXPECT_EQ(multiset_int_1.empty(), false);
  EXPECT_EQ(multiset_int_2.empty(), false);
  EXPECT_EQ(multiset_double_1.empty(), false);
  EXPECT_EQ(multiset_double_2.empty(), false);
  EXPECT_EQ(multiset_str_1.empty(), false);
  EXPECT_EQ(multiset_str_2.empty(), false);
  EXPECT_EQ(multiset_char_1.empty(), false);
  EXPECT_EQ(multiset_char_2.empty(), false);

  my_containers::multiset<int> multiset_int_3;
  std::multiset<int> multiset_int_4;
  my_containers::multiset<double> multiset_double_3;
  std::multiset<double> multiset_double_4;
  my_containers::multiset<std::string> multiset_str_3;
  std::multiset<std::string> multiset_str_4;
  my_containers::multiset<char> multiset_char_3;
  std::multiset<char> multiset_char_4;

  EXPECT_EQ(multiset_int_3.size(), 0);
  EXPECT_EQ(multiset_int_4.size(), 0);
  EXPECT_EQ(multiset_double_3.size(), 0);
  EXPECT_EQ(multiset_double_4.size(), 0);
  EXPECT_EQ(multiset_str_3.size(), 0);
  EXPECT_EQ(multiset_str_4.size(), 0);
  EXPECT_EQ(multiset_char_3.size(), 0);
  EXPECT_EQ(multiset_char_4.size(), 0);
  EXPECT_EQ(multiset_int_3.empty(), true);
  EXPECT_EQ(multiset_int_4.empty(), true);
  EXPECT_EQ(multiset_double_3.empty(), true);
  EXPECT_EQ(multiset_double_4.empty(), true);
  EXPECT_EQ(multiset_str_3.empty(), true);
  EXPECT_EQ(multiset_str_4.empty(), true);
  EXPECT_EQ(multiset_char_3.empty(), true);
  EXPECT_EQ(multiset_char_4.empty(), true);

  multiset_int_3 = multiset_int_1;
  multiset_int_4 = multiset_int_2;
  multiset_double_3 = multiset_double_1;
  multiset_double_4 = multiset_double_2;
  multiset_str_3 = multiset_str_1;
  multiset_str_4 = multiset_str_2;
  multiset_char_3 = multiset_char_1;
  multiset_char_4 = multiset_char_2;

  EXPECT_EQ(multiset_int_3.size(), 31);
  EXPECT_EQ(multiset_int_4.size(), 31);
  EXPECT_EQ(multiset_double_3.size(), 22);
  EXPECT_EQ(multiset_double_4.size(), 22);
  EXPECT_EQ(multiset_str_3.size(), 25);
  EXPECT_EQ(multiset_str_4.size(), 25);
  EXPECT_EQ(multiset_char_3.size(), 29);
  EXPECT_EQ(multiset_char_4.size(), 29);
  EXPECT_EQ(multiset_int_3.empty(), false);
  EXPECT_EQ(multiset_int_4.empty(), false);
  EXPECT_EQ(multiset_double_3.empty(), false);
  EXPECT_EQ(multiset_double_4.empty(), false);
  EXPECT_EQ(multiset_str_3.empty(), false);
  EXPECT_EQ(multiset_str_4.empty(), false);
  EXPECT_EQ(multiset_char_3.empty(), false);
  EXPECT_EQ(multiset_char_4.empty(), false);
  EXPECT_EQ(multiset_int_1.size(), 31);
  EXPECT_EQ(multiset_int_2.size(), 31);
  EXPECT_EQ(multiset_double_1.size(), 22);
  EXPECT_EQ(multiset_double_2.size(), 22);
  EXPECT_EQ(multiset_str_1.size(), 25);
  EXPECT_EQ(multiset_str_2.size(), 25);
  EXPECT_EQ(multiset_char_1.size(), 29);
  EXPECT_EQ(multiset_char_2.size(), 29);
  EXPECT_EQ(multiset_int_1.empty(), false);
  EXPECT_EQ(multiset_int_2.empty(), false);
  EXPECT_EQ(multiset_double_1.empty(), false);
  EXPECT_EQ(multiset_double_2.empty(), false);
  EXPECT_EQ(multiset_str_1.empty(), false);
  EXPECT_EQ(multiset_str_2.empty(), false);
  EXPECT_EQ(multiset_char_1.empty(), false);
  EXPECT_EQ(multiset_char_2.empty(), false);
}
TEST(MultisetTest, insert_Erase) {
  my_containers::multiset<int> multiset_int_1;
  std::multiset<int> multiset_int_2;
  my_containers::multiset<double> multiset_double_1;
  std::multiset<double> multiset_double_2;
  my_containers::multiset<std::string> multiset_str_1;
  std::multiset<std::string> multiset_str_2;
  my_containers::multiset<char> multiset_char_1;
  std::multiset<char> multiset_char_2;
  multisetIntConstructor(multiset_int_1);
  multisetIntConstructorSTD(multiset_int_2);
  multisetDoubleConstructor(multiset_double_1);
  multisetDoubleConstructorSTD(multiset_double_2);
  multisetStringConstructor(multiset_str_1);
  multisetStringConstructorSTD(multiset_str_2);
  multisetCharConstructor(multiset_char_1);
  multisetCharConstructorSTD(multiset_char_2);

  my_containers::multiset<int>::iterator it_int_1 =
      multiset_int_1.insert(-55588);
  std::multiset<int>::iterator it_int_2 = multiset_int_2.insert(-55588);
  my_containers::multiset<double>::iterator it_double_1 =
      multiset_double_1.insert(555.888);
  std::multiset<double>::iterator it_double_2 =
      multiset_double_2.insert(555.888);
  my_containers::multiset<std::string>::iterator it_str_1 =
      multiset_str_1.insert("Soma");
  std::multiset<std::string>::iterator it_str_2 = multiset_str_2.insert("Soma");
  my_containers::multiset<char>::iterator it_char_1 =
      multiset_char_1.insert('$');
  std::multiset<char>::iterator it_char_2 = multiset_char_2.insert('$');
  EXPECT_EQ(*it_int_1, -55588);
  EXPECT_EQ(*it_int_2, -55588);
  EXPECT_EQ(*it_double_1, 555.888);
  EXPECT_EQ(*it_double_2, 555.888);
  EXPECT_EQ(*it_str_1, "Soma");
  EXPECT_EQ(*it_str_2, "Soma");
  EXPECT_EQ(*it_char_1, '$');
  EXPECT_EQ(*it_char_2, '$');
  my_containers::multiset<int>::iterator it_int_3 =
      multiset_int_1.insert(-55588);
  std::multiset<int>::iterator it_int_4 = multiset_int_2.insert(-55588);
  my_containers::multiset<double>::iterator it_double_3 =
      multiset_double_1.insert(555.888);
  std::multiset<double>::iterator it_double_4 =
      multiset_double_2.insert(555.888);
  my_containers::multiset<std::string>::iterator it_str_3 =
      multiset_str_1.insert("Soma");
  std::multiset<std::string>::iterator it_str_4 = multiset_str_2.insert("Soma");
  my_containers::multiset<char>::iterator it_char_3 =
      multiset_char_1.insert('$');
  std::multiset<char>::iterator it_char_4 = multiset_char_2.insert('$');
  EXPECT_EQ(*it_int_3, -55588);
  EXPECT_EQ(*it_int_4, -55588);
  EXPECT_EQ(*it_double_3, 555.888);
  EXPECT_EQ(*it_double_4, 555.888);
  EXPECT_EQ(*it_str_3, "Soma");
  EXPECT_EQ(*it_str_4, "Soma");
  EXPECT_EQ(*it_char_3, '$');
  EXPECT_EQ(*it_char_4, '$');

  EXPECT_EQ(*it_int_1, *it_int_2);
  EXPECT_EQ(*it_double_1, *it_double_2);
  EXPECT_EQ(*it_str_1, *it_str_2);
  EXPECT_EQ(*it_char_1, *it_char_2);
  EXPECT_EQ(*it_int_3, *it_int_4);
  EXPECT_EQ(*it_double_3, *it_double_4);
  EXPECT_EQ(*it_str_3, *it_str_4);
  EXPECT_EQ(*it_char_3, *it_char_4);
  EXPECT_EQ(*it_int_1, *it_int_3);
  EXPECT_EQ(*it_double_1, *it_double_3);
  EXPECT_EQ(*it_str_1, *it_str_3);
  EXPECT_EQ(*it_char_1, *it_char_3);
  EXPECT_EQ(*it_int_2, *it_int_4);
  EXPECT_EQ(*it_double_2, *it_double_4);
  EXPECT_EQ(*it_str_2, *it_str_4);
  EXPECT_EQ(*it_char_2, *it_char_4);
  EXPECT_EQ(*it_int_1, *it_int_4);
  EXPECT_EQ(*it_double_1, *it_double_4);
  EXPECT_EQ(*it_str_1, *it_str_4);
  EXPECT_EQ(*it_char_1, *it_char_4);
  EXPECT_EQ(*it_int_2, *it_int_3);
  EXPECT_EQ(*it_double_2, *it_double_3);
  EXPECT_EQ(*it_str_2, *it_str_3);
  EXPECT_EQ(*it_char_2, *it_char_3);
  EXPECT_NE(it_int_1, it_int_3);
  EXPECT_NE(it_int_2, it_int_4);
  EXPECT_NE(it_double_1, it_double_3);
  EXPECT_NE(it_double_2, it_double_4);
  EXPECT_NE(it_str_1, it_str_3);
  EXPECT_NE(it_str_2, it_str_4);
  EXPECT_NE(it_char_1, it_char_3);
  EXPECT_NE(it_char_2, it_char_4);

  multiset_int_1.erase(it_int_1);
  multiset_int_2.erase(it_int_2);
  multiset_double_1.erase(it_double_1);
  multiset_double_2.erase(it_double_2);
  multiset_str_1.erase(it_str_1);
  multiset_str_2.erase(it_str_2);
  multiset_char_1.erase(it_char_1);
  multiset_char_2.erase(it_char_2);

  EXPECT_EQ(*it_int_3, -55588);
  EXPECT_EQ(*it_int_4, -55588);
  EXPECT_EQ(*it_double_3, 555.888);
  EXPECT_EQ(*it_double_4, 555.888);
  EXPECT_EQ(*it_str_3, "Soma");
  EXPECT_EQ(*it_str_4, "Soma");
  EXPECT_EQ(*it_char_3, '$');
  EXPECT_EQ(*it_char_4, '$');
  EXPECT_EQ(multiset_int_1.contains(-55588), true);
  EXPECT_EQ(multiset_double_1.contains(555.888), true);
  EXPECT_EQ(multiset_str_1.contains("Soma"), true);
  EXPECT_EQ(multiset_char_1.contains('$'), true);
}
TEST(MultisetTest, Find) {
  my_containers::multiset<int> multiset_int_1;
  std::multiset<int> multiset_int_2;
  my_containers::multiset<double> multiset_double_1;
  std::multiset<double> multiset_double_2;
  my_containers::multiset<std::string> multiset_str_1;
  std::multiset<std::string> multiset_str_2;
  my_containers::multiset<char> multiset_char_1;
  std::multiset<char> multiset_char_2;
  multisetIntConstructor(multiset_int_1);
  multisetIntConstructorSTD(multiset_int_2);
  multisetDoubleConstructor(multiset_double_1);
  multisetDoubleConstructorSTD(multiset_double_2);
  multisetStringConstructor(multiset_str_1);
  multisetStringConstructorSTD(multiset_str_2);
  multisetCharConstructor(multiset_char_1);
  multisetCharConstructorSTD(multiset_char_2);

  my_containers::multiset<int>::iterator it_int_1 =
      multiset_int_1.insert(-55588);
  std::multiset<int>::iterator it_int_2 = multiset_int_2.insert(-55588);
  my_containers::multiset<double>::iterator it_double_1 =
      multiset_double_1.insert(555.888);
  std::multiset<double>::iterator it_double_2 =
      multiset_double_2.insert(555.888);
  my_containers::multiset<std::string>::iterator it_str_1 =
      multiset_str_1.insert("Soma");
  std::multiset<std::string>::iterator it_str_2 = multiset_str_2.insert("Soma");
  my_containers::multiset<char>::iterator it_char_1 =
      multiset_char_1.insert('$');
  std::multiset<char>::iterator it_char_2 = multiset_char_2.insert('$');
  EXPECT_EQ(*it_int_1, -55588);

  EXPECT_EQ(multiset_int_1.contains(-55588), true);
  EXPECT_EQ(multiset_double_1.contains(555.888), true);
  EXPECT_EQ(multiset_str_1.contains("Soma"), true);
  EXPECT_EQ(multiset_char_1.contains('$'), true);

  my_containers::multiset<int>::iterator it_int_3 = multiset_int_1.find(-55588);
  std::multiset<int>::iterator it_int_4 = multiset_int_2.find(-55588);
  my_containers::multiset<double>::iterator it_double_3 =
      multiset_double_1.find(555.888);
  std::multiset<double>::iterator it_double_4 = multiset_double_2.find(555.888);
  my_containers::multiset<std::string>::iterator it_str_3 =
      multiset_str_1.find("Soma");
  std::multiset<std::string>::iterator it_str_4 = multiset_str_2.find("Soma");
  my_containers::multiset<char>::iterator it_char_3 = multiset_char_1.find('$');
  std::multiset<char>::iterator it_char_4 = multiset_char_2.find('$');

  EXPECT_EQ(it_int_1, it_int_3);
  EXPECT_EQ(it_int_2, it_int_4);
  EXPECT_EQ(it_double_1, it_double_3);
  EXPECT_EQ(it_double_2, it_double_4);
  EXPECT_EQ(it_str_1, it_str_3);
  EXPECT_EQ(it_str_2, it_str_4);
  EXPECT_EQ(it_char_1, it_char_3);
  EXPECT_EQ(it_char_2, it_char_4);
  EXPECT_EQ(*it_int_1, *it_int_3);
  EXPECT_EQ(*it_int_2, *it_int_4);
  EXPECT_EQ(*it_double_1, *it_double_3);
  EXPECT_EQ(*it_double_2, *it_double_4);
  EXPECT_EQ(*it_str_1, *it_str_3);
  EXPECT_EQ(*it_str_2, *it_str_4);
  EXPECT_EQ(*it_char_1, *it_char_3);
  EXPECT_EQ(*it_char_2, *it_char_4);

  multiset_int_1.erase(it_int_1);
  multiset_int_2.erase(it_int_2);
  multiset_double_1.erase(it_double_1);
  multiset_double_2.erase(it_double_2);
  multiset_str_1.erase(it_str_1);
  multiset_str_2.erase(it_str_2);
  multiset_char_1.erase(it_char_1);
  multiset_char_2.erase(it_char_2);
  EXPECT_EQ(it_int_1, it_int_3);
  EXPECT_EQ(it_int_2, it_int_4);
  EXPECT_EQ(it_double_1, it_double_3);
  EXPECT_EQ(it_double_2, it_double_4);
  EXPECT_EQ(it_str_1, it_str_3);
  EXPECT_EQ(it_str_2, it_str_4);
  EXPECT_EQ(it_char_1, it_char_3);
  EXPECT_EQ(it_char_2, it_char_4);

  EXPECT_EQ(multiset_int_1.contains(-55588), false);
  EXPECT_EQ(multiset_double_1.contains(555.888), false);
  EXPECT_EQ(multiset_str_1.contains("Soma"), false);
  EXPECT_EQ(multiset_char_1.contains('$'), false);
}
TEST(MultisetTest, Swap) {
  my_containers::multiset<int> multiset_int_1;
  std::multiset<int> multiset_int_2;
  my_containers::multiset<double> multiset_double_1;
  std::multiset<double> multiset_double_2;
  my_containers::multiset<std::string> multiset_str_1;
  std::multiset<std::string> multiset_str_2;
  my_containers::multiset<char> multiset_char_1;
  std::multiset<char> multiset_char_2;
  multisetIntConstructor(multiset_int_1);
  multisetIntConstructorSTD(multiset_int_2);
  multisetDoubleConstructor(multiset_double_1);
  multisetDoubleConstructorSTD(multiset_double_2);
  multisetStringConstructor(multiset_str_1);
  multisetStringConstructorSTD(multiset_str_2);
  multisetCharConstructor(multiset_char_1);
  multisetCharConstructorSTD(multiset_char_2);
  my_containers::multiset<int> multiset_int_7{10, 2, 3, 44, 5, 5, 5, 5, 5, 5};
  std::multiset<int> multiset_int_8{10, 2, 3, 44, 5, 5, 5, 5, 5, 5};
  my_containers::multiset<double> multiset_double_7{
      555.55, 423.2, 2, 1000, -55.55, -55.55, -55.55, -55.55, -55.55, -55.55};
  std::multiset<double> multiset_double_8{
      555.55, 423.2, 2, 1000, -55.55, -55.55, -55.55, -55.55, -55.55, -55.55};
  my_containers::multiset<std::string> multiset_str_7{
      "Jazz",  "Me",    "played", "with",  "Blues",
      "Blues", "Blues", "Blues",  "Blues", "Blues"};
  std::multiset<std::string> multiset_str_8{"Jazz",  "Me",    "played", "with",
                                            "Blues", "Blues", "Blues",  "Blues",
                                            "Blues", "Blues"};
  my_containers::multiset<char> multiset_char_7{'a', 'b', 'c', 'd', '5',
                                                '5', '5', '5', '5', '5'};
  std::multiset<char> multiset_char_8{'a', 'b', 'c', 'd', '5',
                                      '5', '5', '5', '5', '5'};
  EXPECT_EQ(multiset_int_7.size(), 10);
  EXPECT_EQ(multiset_int_8.size(), 10);
  EXPECT_EQ(multiset_double_7.size(), 10);
  EXPECT_EQ(multiset_double_8.size(), 10);
  EXPECT_EQ(multiset_str_7.size(), 10);
  EXPECT_EQ(multiset_str_8.size(), 10);
  EXPECT_EQ(multiset_char_7.size(), 10);
  EXPECT_EQ(multiset_char_8.size(), 10);
  my_containers::multiset<int> multiset_int_3;
  std::multiset<int> multiset_int_4;
  my_containers::multiset<double> multiset_double_3;
  std::multiset<double> multiset_double_4;
  my_containers::multiset<std::string> multiset_str_3;
  std::multiset<std::string> multiset_str_4;
  my_containers::multiset<char> multiset_char_3;
  std::multiset<char> multiset_char_4;
  EXPECT_EQ(multiset_int_3.empty(), true);
  EXPECT_EQ(multiset_int_4.empty(), true);
  EXPECT_EQ(multiset_double_3.empty(), true);
  EXPECT_EQ(multiset_double_4.empty(), true);
  EXPECT_EQ(multiset_str_3.empty(), true);
  EXPECT_EQ(multiset_str_4.empty(), true);
  EXPECT_EQ(multiset_char_3.empty(), true);
  EXPECT_EQ(multiset_char_4.empty(), true);

  multiset_int_1.swap(multiset_int_7);
  multiset_int_2.swap(multiset_int_8);
  multiset_double_1.swap(multiset_double_7);
  multiset_double_2.swap(multiset_double_8);
  multiset_str_1.swap(multiset_str_7);
  multiset_str_2.swap(multiset_str_8);
  multiset_char_1.swap(multiset_char_7);
  multiset_char_2.swap(multiset_char_8);
  EXPECT_EQ(multiset_int_1.size(), 10);
  EXPECT_EQ(multiset_int_2.size(), 10);
  EXPECT_EQ(multiset_double_1.size(), 10);
  EXPECT_EQ(multiset_double_2.size(), 10);
  EXPECT_EQ(multiset_str_1.size(), 10);
  EXPECT_EQ(multiset_str_2.size(), 10);
  EXPECT_EQ(multiset_char_1.size(), 10);
  EXPECT_EQ(multiset_char_2.size(), 10);
  EXPECT_EQ(multiset_int_7.size(), 31);
  EXPECT_EQ(multiset_int_8.size(), 31);
  EXPECT_EQ(multiset_double_7.size(), 22);
  EXPECT_EQ(multiset_double_8.size(), 22);
  EXPECT_EQ(multiset_str_7.size(), 25);
  EXPECT_EQ(multiset_str_8.size(), 25);
  EXPECT_EQ(multiset_char_7.size(), 29);
  EXPECT_EQ(multiset_char_8.size(), 29);

  multiset_int_7.swap(multiset_int_3);
  multiset_int_8.swap(multiset_int_4);
  multiset_double_7.swap(multiset_double_3);
  multiset_double_8.swap(multiset_double_4);
  multiset_str_7.swap(multiset_str_3);
  multiset_str_8.swap(multiset_str_4);
  multiset_char_7.swap(multiset_char_3);
  multiset_char_8.swap(multiset_char_4);
  EXPECT_EQ(multiset_int_7.size(), 0);
  EXPECT_EQ(multiset_int_8.size(), 0);
  EXPECT_EQ(multiset_double_7.size(), 0);
  EXPECT_EQ(multiset_double_8.size(), 0);
  EXPECT_EQ(multiset_str_7.size(), 0);
  EXPECT_EQ(multiset_str_8.size(), 0);
  EXPECT_EQ(multiset_char_7.size(), 0);
  EXPECT_EQ(multiset_char_8.size(), 0);
  EXPECT_EQ(multiset_int_3.size(), 31);
  EXPECT_EQ(multiset_int_4.size(), 31);
  EXPECT_EQ(multiset_double_3.size(), 22);
  EXPECT_EQ(multiset_double_4.size(), 22);
  EXPECT_EQ(multiset_str_3.size(), 25);
  EXPECT_EQ(multiset_str_4.size(), 25);
  EXPECT_EQ(multiset_char_3.size(), 29);
  EXPECT_EQ(multiset_char_4.size(), 29);
}
TEST(MultisetTest, Merge) {
  my_containers::multiset<int> multiset_int_1;
  std::multiset<int> multiset_int_2;
  my_containers::multiset<double> multiset_double_1;
  std::multiset<double> multiset_double_2;
  my_containers::multiset<std::string> multiset_str_1;
  std::multiset<std::string> multiset_str_2;
  my_containers::multiset<char> multiset_char_1;
  std::multiset<char> multiset_char_2;
  multisetIntConstructor(multiset_int_1);
  multisetIntConstructorSTD(multiset_int_2);
  multisetDoubleConstructor(multiset_double_1);
  multisetDoubleConstructorSTD(multiset_double_2);
  multisetStringConstructor(multiset_str_1);
  multisetStringConstructorSTD(multiset_str_2);
  multisetCharConstructor(multiset_char_1);
  multisetCharConstructorSTD(multiset_char_2);
  my_containers::multiset<int> multiset_int_7{10, 2, 3, 44, 5, 5, 5, 5, 5, 5};
  std::multiset<int> multiset_int_8{10, 2, 3, 44, 5, 5, 5, 5, 5, 5};
  my_containers::multiset<double> multiset_double_7{
      555.55, 423.2, 2, 1000, -55.55, -55.55, -55.55, -55.55, -55.55, -55.55};
  std::multiset<double> multiset_double_8{
      555.55, 423.2, 2, 1000, -55.55, -55.55, -55.55, -55.55, -55.55, -55.55};
  my_containers::multiset<std::string> multiset_str_7{
      "Jazz",  "Me",    "played", "with",  "Blues",
      "Blues", "Blues", "Blues",  "Blues", "Blues"};
  std::multiset<std::string> multiset_str_8{"Jazz",  "Me",    "played", "with",
                                            "Blues", "Blues", "Blues",  "Blues",
                                            "Blues", "Blues"};
  my_containers::multiset<char> multiset_char_7{'a', 'b', 'c', 'd', '5',
                                                '5', '5', '5', '5', '5'};
  std::multiset<char> multiset_char_8{'a', 'b', 'c', 'd', '5',
                                      '5', '5', '5', '5', '5'};
  EXPECT_EQ(multiset_int_7.size(), 10);
  EXPECT_EQ(multiset_int_8.size(), 10);
  EXPECT_EQ(multiset_double_7.size(), 10);
  EXPECT_EQ(multiset_double_8.size(), 10);
  EXPECT_EQ(multiset_str_7.size(), 10);
  EXPECT_EQ(multiset_str_8.size(), 10);
  EXPECT_EQ(multiset_char_7.size(), 10);
  EXPECT_EQ(multiset_char_8.size(), 10);
  my_containers::multiset<int> multiset_int_3;
  std::multiset<int> multiset_int_4;
  my_containers::multiset<double> multiset_double_3;
  std::multiset<double> multiset_double_4;
  my_containers::multiset<std::string> multiset_str_3;
  std::multiset<std::string> multiset_str_4;
  my_containers::multiset<char> multiset_char_3;
  std::multiset<char> multiset_char_4;
  EXPECT_EQ(multiset_int_3.empty(), true);
  EXPECT_EQ(multiset_int_4.empty(), true);
  EXPECT_EQ(multiset_double_3.empty(), true);
  EXPECT_EQ(multiset_double_4.empty(), true);
  EXPECT_EQ(multiset_str_3.empty(), true);
  EXPECT_EQ(multiset_str_4.empty(), true);
  EXPECT_EQ(multiset_char_3.empty(), true);
  EXPECT_EQ(multiset_char_4.empty(), true);

  multiset_int_1.merge(multiset_int_3);
  multiset_int_2.merge(multiset_int_4);
  multiset_double_1.merge(multiset_double_3);
  multiset_double_2.merge(multiset_double_4);
  multiset_str_1.merge(multiset_str_3);
  multiset_str_2.merge(multiset_str_4);
  multiset_char_1.merge(multiset_char_3);
  multiset_char_2.merge(multiset_char_4);
  EXPECT_EQ(multiset_int_1.size(), 31);
  EXPECT_EQ(multiset_int_2.size(), 31);
  EXPECT_EQ(multiset_double_1.size(), 22);
  EXPECT_EQ(multiset_double_2.size(), 22);
  EXPECT_EQ(multiset_str_1.size(), 25);
  EXPECT_EQ(multiset_str_2.size(), 25);
  EXPECT_EQ(multiset_char_1.size(), 29);
  EXPECT_EQ(multiset_char_2.size(), 29);
  EXPECT_EQ(multiset_int_3.empty(), true);
  EXPECT_EQ(multiset_int_4.empty(), true);
  EXPECT_EQ(multiset_double_3.empty(), true);
  EXPECT_EQ(multiset_double_4.empty(), true);
  EXPECT_EQ(multiset_str_3.empty(), true);
  EXPECT_EQ(multiset_str_4.empty(), true);
  EXPECT_EQ(multiset_char_3.empty(), true);
  EXPECT_EQ(multiset_char_4.empty(), true);

  multiset_int_3.merge(multiset_int_1);
  multiset_int_4.merge(multiset_int_2);
  multiset_double_3.merge(multiset_double_1);
  multiset_double_4.merge(multiset_double_2);
  multiset_str_3.merge(multiset_str_1);
  multiset_str_4.merge(multiset_str_2);
  multiset_char_3.merge(multiset_char_1);
  multiset_char_4.merge(multiset_char_2);
  EXPECT_EQ(multiset_int_3.size(), 31);
  EXPECT_EQ(multiset_int_4.size(), 31);
  EXPECT_EQ(multiset_double_3.size(), 22);
  EXPECT_EQ(multiset_double_4.size(), 22);
  EXPECT_EQ(multiset_str_3.size(), 25);
  EXPECT_EQ(multiset_str_4.size(), 25);
  EXPECT_EQ(multiset_char_3.size(), 29);
  EXPECT_EQ(multiset_char_4.size(), 29);
  EXPECT_EQ(multiset_int_1.empty(), true);
  EXPECT_EQ(multiset_int_2.empty(), true);
  EXPECT_EQ(multiset_double_1.empty(), true);
  EXPECT_EQ(multiset_double_2.empty(), true);
  EXPECT_EQ(multiset_str_1.empty(), true);
  EXPECT_EQ(multiset_str_2.empty(), true);
  EXPECT_EQ(multiset_char_1.empty(), true);
  EXPECT_EQ(multiset_char_2.empty(), true);

  multiset_int_3.merge(multiset_int_7);
  multiset_int_4.merge(multiset_int_8);
  multiset_double_3.merge(multiset_double_7);
  multiset_double_4.merge(multiset_double_8);
  multiset_str_3.merge(multiset_str_7);
  multiset_str_4.merge(multiset_str_8);
  EXPECT_EQ(multiset_int_3.size(), 41);
  EXPECT_EQ(multiset_int_4.size(), 41);
  EXPECT_EQ(multiset_double_3.size(), 32);
  EXPECT_EQ(multiset_double_4.size(), 32);
  EXPECT_EQ(multiset_str_3.size(), 35);
  EXPECT_EQ(multiset_str_4.size(), 35);
  EXPECT_EQ(multiset_int_7.size(), 0);
  EXPECT_EQ(multiset_int_8.size(), 0);
  EXPECT_EQ(multiset_double_7.size(), 0);
  EXPECT_EQ(multiset_double_8.size(), 0);
  EXPECT_EQ(multiset_str_7.size(), 0);
  EXPECT_EQ(multiset_str_8.size(), 0);
}
TEST(MultisetTest, LowerBound) {
  my_containers::multiset<int> multiset_int_1;
  std::multiset<int> multiset_int_2;
  my_containers::multiset<double> multiset_double_1;
  std::multiset<double> multiset_double_2;
  my_containers::multiset<std::string> multiset_str_1;
  std::multiset<std::string> multiset_str_2;
  my_containers::multiset<char> multiset_char_1;
  std::multiset<char> multiset_char_2;
  multisetIntConstructor(multiset_int_1);
  multisetIntConstructorSTD(multiset_int_2);
  multisetDoubleConstructor(multiset_double_1);
  multisetDoubleConstructorSTD(multiset_double_2);
  multisetStringConstructor(multiset_str_1);
  multisetStringConstructorSTD(multiset_str_2);
  multisetCharConstructor(multiset_char_1);
  multisetCharConstructorSTD(multiset_char_2);

  EXPECT_EQ(*multiset_int_1.lower_bound(-100),
            *multiset_int_2.lower_bound(-100));
  EXPECT_EQ(*multiset_double_1.lower_bound(-55.55),
            *multiset_double_2.lower_bound(-55.55));
  EXPECT_EQ(*multiset_str_1.lower_bound("Rock"),
            *multiset_str_2.lower_bound("Rock"));
  EXPECT_EQ(*multiset_char_1.lower_bound('a'),
            *multiset_char_2.lower_bound('a'));
  EXPECT_EQ(*(multiset_int_1.lower_bound(-100)), -100);
  EXPECT_EQ(*(multiset_int_2.lower_bound(-100)), -100);
  EXPECT_EQ(*(++multiset_int_1.lower_bound(-100)), -100);
  EXPECT_EQ(*(++multiset_int_2.lower_bound(-100)), -100);
  EXPECT_EQ(*(multiset_double_1.lower_bound(-55.55)), -55.55);
  EXPECT_EQ(*(multiset_double_2.lower_bound(-55.55)), -55.55);
  EXPECT_EQ(*(++multiset_double_1.lower_bound(-55.55)), -55.55);
  EXPECT_EQ(*(++multiset_double_2.lower_bound(-55.55)), -55.55);
  EXPECT_EQ(*(--multiset_double_1.lower_bound(-55.55)), -1000);
  EXPECT_EQ(*(--multiset_double_2.lower_bound(-55.55)), -1000);
  EXPECT_EQ(*(multiset_str_1.lower_bound("Rock")), "Rock");
  EXPECT_EQ(*(multiset_str_2.lower_bound("Rock")), "Rock");
  EXPECT_EQ(*(++multiset_str_1.lower_bound("Rock")), "Rock");
  EXPECT_EQ(*(++multiset_str_2.lower_bound("Rock")), "Rock");
  EXPECT_EQ(*(--multiset_str_1.lower_bound("Rock")), "Me");
  EXPECT_EQ(*(--multiset_str_2.lower_bound("Rock")), "Me");
  EXPECT_EQ(*(multiset_char_1.lower_bound('a')), 'a');
  EXPECT_EQ(*(multiset_char_2.lower_bound('a')), 'a');
  EXPECT_EQ(*(++multiset_char_1.lower_bound('a')), 'a');
  EXPECT_EQ(*(++multiset_char_2.lower_bound('a')), 'a');
  EXPECT_EQ(*(multiset_char_1.lower_bound('b')), 'b');
  EXPECT_EQ(*(multiset_char_2.lower_bound('b')), 'b');
  EXPECT_EQ(*(++multiset_char_1.lower_bound('b')), 'c');
  EXPECT_EQ(*(++multiset_char_2.lower_bound('b')), 'c');
  EXPECT_EQ(*(--multiset_char_2.lower_bound('b')), 'a');
  EXPECT_EQ(*(--multiset_char_1.lower_bound('b')), 'a');
}
TEST(MultisetTest, UpperBound) {
  my_containers::multiset<int> multiset_int_1;
  std::multiset<int> multiset_int_2;
  my_containers::multiset<double> multiset_double_1;
  std::multiset<double> multiset_double_2;
  my_containers::multiset<std::string> multiset_str_1;
  std::multiset<std::string> multiset_str_2;
  my_containers::multiset<char> multiset_char_1;
  std::multiset<char> multiset_char_2;
  multisetIntConstructor(multiset_int_1);
  multisetIntConstructorSTD(multiset_int_2);
  multisetDoubleConstructor(multiset_double_1);
  multisetDoubleConstructorSTD(multiset_double_2);
  multisetStringConstructor(multiset_str_1);
  multisetStringConstructorSTD(multiset_str_2);
  multisetCharConstructor(multiset_char_1);
  multisetCharConstructorSTD(multiset_char_2);

  EXPECT_EQ(*multiset_int_1.upper_bound(-100),
            *multiset_int_2.upper_bound(-100));
  EXPECT_EQ(*multiset_double_1.upper_bound(-55.55),
            *multiset_double_2.upper_bound(-55.55));
  EXPECT_EQ(*multiset_str_1.upper_bound("Rock"),
            *multiset_str_2.upper_bound("Rock"));
  EXPECT_EQ(*multiset_char_1.upper_bound('a'),
            *multiset_char_2.upper_bound('a'));
  EXPECT_EQ(*(multiset_int_1.upper_bound(-100)), -5);
  EXPECT_EQ(*(multiset_int_2.upper_bound(-100)), -5);
  EXPECT_EQ(*(--multiset_int_1.upper_bound(-100)), -100);
  EXPECT_EQ(*(--multiset_int_2.upper_bound(-100)), -100);
  EXPECT_EQ(*(multiset_double_1.upper_bound(-55.55)), -33.3);
  EXPECT_EQ(*(multiset_double_2.upper_bound(-55.55)), -33.3);
  EXPECT_EQ(*(--multiset_double_1.upper_bound(-55.55)), -55.55);
  EXPECT_EQ(*(--multiset_double_2.upper_bound(-55.55)), -55.55);
  EXPECT_EQ(*(multiset_str_1.upper_bound("Rock")), "Wow");
  EXPECT_EQ(*(multiset_str_2.upper_bound("Rock")), "Wow");
  EXPECT_EQ(*(--multiset_str_1.upper_bound("Rock")), "Rock");
  EXPECT_EQ(*(--multiset_str_2.upper_bound("Rock")), "Rock");
  EXPECT_EQ(*(multiset_char_1.upper_bound('a')), 'b');
  EXPECT_EQ(*(multiset_char_2.upper_bound('a')), 'b');
  EXPECT_EQ(*(++multiset_char_1.upper_bound('a')), 'c');
  EXPECT_EQ(*(++multiset_char_2.upper_bound('a')), 'c');
  EXPECT_EQ(*(--multiset_char_1.upper_bound('a')), 'a');
  EXPECT_EQ(*(--multiset_char_2.upper_bound('a')), 'a');
  EXPECT_EQ(*(multiset_char_1.upper_bound('b')), 'c');
  EXPECT_EQ(*(multiset_char_2.upper_bound('b')), 'c');
  EXPECT_EQ(*(--multiset_char_2.upper_bound('b')), 'b');
  EXPECT_EQ(*(--multiset_char_1.upper_bound('b')), 'b');
}
TEST(MultisetTest, EqualRange) {
  my_containers::multiset<int> multiset_int_1;
  std::multiset<int> multiset_int_2;
  my_containers::multiset<double> multiset_double_1;
  std::multiset<double> multiset_double_2;
  my_containers::multiset<std::string> multiset_str_1;
  std::multiset<std::string> multiset_str_2;
  my_containers::multiset<char> multiset_char_1;
  std::multiset<char> multiset_char_2;
  multisetIntConstructor(multiset_int_1);
  multisetIntConstructorSTD(multiset_int_2);
  multisetDoubleConstructor(multiset_double_1);
  multisetDoubleConstructorSTD(multiset_double_2);
  multisetStringConstructor(multiset_str_1);
  multisetStringConstructorSTD(multiset_str_2);
  multisetCharConstructor(multiset_char_1);
  multisetCharConstructorSTD(multiset_char_2);

  EXPECT_EQ(*(multiset_int_1.equal_range(-100).second),
            *multiset_int_2.upper_bound(-100));
  EXPECT_EQ(*(multiset_double_1.equal_range(-55.55).second),
            *multiset_double_2.upper_bound(-55.55));
  EXPECT_EQ(*(multiset_str_1.equal_range("Rock").second),
            *multiset_str_2.upper_bound("Rock"));
  EXPECT_EQ(*(multiset_char_1.equal_range('a').second),
            *multiset_char_2.upper_bound('a'));
  EXPECT_EQ(*(++multiset_int_1.equal_range(-100).second),
            *(++multiset_int_2.upper_bound(-100)));
  EXPECT_EQ(*(++multiset_double_1.equal_range(-55.55).second),
            *(++multiset_double_2.upper_bound(-55.55)));
  EXPECT_EQ(*(++multiset_str_1.equal_range("Rock").second),
            *(++multiset_str_2.upper_bound("Rock")));
  EXPECT_EQ(*(++multiset_char_1.equal_range('a').second),
            *(++multiset_char_2.upper_bound('a')));
  EXPECT_EQ(*(--multiset_int_1.equal_range(-100).second),
            *(--multiset_int_2.upper_bound(-100)));
  EXPECT_EQ(*(--multiset_double_1.equal_range(-55.55).second),
            *(--multiset_double_2.upper_bound(-55.55)));
  EXPECT_EQ(*(--multiset_str_1.equal_range("Rock").second),
            *(--multiset_str_2.upper_bound("Rock")));
  EXPECT_EQ(*(--multiset_char_1.equal_range('a').second),
            *(--multiset_char_2.upper_bound('a')));

  EXPECT_EQ(*(multiset_int_1.equal_range(-100).second),
            *multiset_int_2.equal_range(-100).second);
  EXPECT_EQ(*(multiset_double_1.equal_range(-55.55).second),
            *multiset_double_2.equal_range(-55.55).second);
  EXPECT_EQ(*(multiset_str_1.equal_range("Rock").second),
            *multiset_str_2.equal_range("Rock").second);
  EXPECT_EQ(*(multiset_char_1.equal_range('a').second),
            *multiset_char_2.equal_range('a').second);
  EXPECT_EQ(*(++multiset_int_1.equal_range(-100).second),
            *(++multiset_int_2.equal_range(-100).second));
  EXPECT_EQ(*(++multiset_double_1.equal_range(-55.55).second),
            *(++multiset_double_2.equal_range(-55.55).second));
  EXPECT_EQ(*(++multiset_str_1.equal_range("Rock").second),
            *(++multiset_str_2.equal_range("Rock").second));
  EXPECT_EQ(*(++multiset_char_1.equal_range('a').second),
            *(++multiset_char_2.equal_range('a').second));
  EXPECT_EQ(*(--multiset_int_1.equal_range(-100).second),
            *(--multiset_int_2.equal_range(-100).second));
  EXPECT_EQ(*(--multiset_double_1.equal_range(-55.55).second),
            *(--multiset_double_2.equal_range(-55.55).second));
  EXPECT_EQ(*(--multiset_str_1.equal_range("Rock").second),
            *(--multiset_str_2.equal_range("Rock").second));
  EXPECT_EQ(*(--multiset_char_1.equal_range('a').second),
            *(--multiset_char_2.equal_range('a').second));

  EXPECT_EQ(*(multiset_int_1.equal_range(-100).first),
            *multiset_int_2.lower_bound(-100));
  EXPECT_EQ(*(multiset_double_1.equal_range(-55.55).first),
            *multiset_double_2.lower_bound(-55.55));
  EXPECT_EQ(*(multiset_str_1.equal_range("Rock").first),
            *multiset_str_2.lower_bound("Rock"));
  EXPECT_EQ(*(multiset_char_1.equal_range('a').first),
            *multiset_char_2.lower_bound('a'));
  EXPECT_EQ(*(++multiset_int_1.equal_range(-100).first),
            *(++multiset_int_2.lower_bound(-100)));
  EXPECT_EQ(*(++multiset_double_1.equal_range(-55.55).first),
            *(++multiset_double_2.lower_bound(-55.55)));
  EXPECT_EQ(*(++multiset_str_1.equal_range("Rock").first),
            *(++multiset_str_2.lower_bound("Rock")));
  EXPECT_EQ(*(++multiset_char_1.equal_range('a').first),
            *(++multiset_char_2.lower_bound('a')));
  EXPECT_EQ(*(--multiset_double_1.equal_range(-55.55).first),
            *(--multiset_double_2.lower_bound(-55.55)));
  EXPECT_EQ(*(--multiset_str_1.equal_range("Rock").first),
            *(--multiset_str_2.lower_bound("Rock")));
  EXPECT_EQ(*(--multiset_char_1.equal_range('a').first),
            *(--multiset_char_2.lower_bound('a')));

  EXPECT_EQ(*(multiset_int_1.equal_range(-100).first),
            *multiset_int_2.equal_range(-100).first);
  EXPECT_EQ(*(multiset_double_1.equal_range(-55.55).first),
            *multiset_double_2.equal_range(-55.55).first);
  EXPECT_EQ(*(multiset_str_1.equal_range("Rock").first),
            *multiset_str_2.equal_range("Rock").first);
  EXPECT_EQ(*(multiset_char_1.equal_range('a').first),
            *multiset_char_2.equal_range('a').first);
  EXPECT_EQ(*(++multiset_int_1.equal_range(-100).first),
            *(++multiset_int_2.equal_range(-100).first));
  EXPECT_EQ(*(++multiset_double_1.equal_range(-55.55).first),
            *(++multiset_double_2.equal_range(-55.55).first));
  EXPECT_EQ(*(++multiset_str_1.equal_range("Rock").first),
            *(++multiset_str_2.equal_range("Rock").first));
  EXPECT_EQ(*(++multiset_char_1.equal_range('a').first),
            *(++multiset_char_2.equal_range('a').first));
  EXPECT_EQ(*(--multiset_double_1.equal_range(-55.55).first),
            *(--multiset_double_2.equal_range(-55.55).first));
  EXPECT_EQ(*(--multiset_str_1.equal_range("Rock").first),
            *(--multiset_str_2.equal_range("Rock").first));
  EXPECT_EQ(*(--multiset_char_1.equal_range('a').first),
            *(--multiset_char_2.equal_range('a').first));
}
TEST(MultisetTest, Count) {
  my_containers::multiset<int> multiset_int_1;
  std::multiset<int> multiset_int_2;
  my_containers::multiset<double> multiset_double_1;
  std::multiset<double> multiset_double_2;
  multisetIntConstructor(multiset_int_1);
  multisetIntConstructorSTD(multiset_int_2);
  multisetDoubleConstructor(multiset_double_1);
  multisetDoubleConstructorSTD(multiset_double_2);

  EXPECT_EQ(multiset_int_1.count(-100), multiset_int_2.count(-100));
  EXPECT_EQ(multiset_int_1.count(0), multiset_int_2.count(0));
  EXPECT_EQ(multiset_int_1.count(100), multiset_int_2.count(100));
  EXPECT_EQ(multiset_int_1.count(-500000), multiset_int_2.count(-50000));
  EXPECT_EQ(multiset_double_1.count(0), multiset_double_2.count(0));
  EXPECT_EQ(multiset_double_1.count(1), multiset_double_2.count(1));
  EXPECT_EQ(multiset_double_1.count(100), multiset_double_2.count(100));
  EXPECT_EQ(multiset_double_1.count(-55.55), multiset_double_2.count(-55.55));
  EXPECT_EQ(multiset_double_1.count(1000), multiset_double_2.count(1000));
}

TEST(MultisetTest, Sum) {
  my_containers::multiset<int> multiset;
  multiset.insert(10);
  multiset.insert(10);
  multiset.insert(10);
  multiset.insert(10);
  multiset.insert(10);
  multiset.insert(10);
  multiset.insert(10);
  multiset.insert(10);
  multiset.insert(10);
  multiset.insert(10);
  EXPECT_EQ(multiset.size(), 10U);
  auto it = multiset.begin();
  multiset.erase(it);
  EXPECT_EQ(multiset.size(), 9U);
  it = multiset.begin();
  EXPECT_EQ(*it, 10);
  multiset.erase(it);
  EXPECT_EQ(multiset.size(), 8U);
}
