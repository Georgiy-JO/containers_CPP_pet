

#include <stack>

#include "global_tests.h"
// #include "../containers/stack/stack.hpp"

TEST(StackTest, Constructor_Exclusions) {
  my_containers::Stack<int> stack_int;
  my_containers::Stack<double> stack_double;
  my_containers::Stack<std::string> stack_string;
  my_containers::Stack<char> stach_char;

  EXPECT_EQ(stack_int.size(), 0);
  EXPECT_EQ(stack_double.size(), 0);
  EXPECT_EQ(stack_string.size(), 0);
  EXPECT_EQ(stach_char.size(), 0);

  EXPECT_EQ(stack_int.empty(), true);
  EXPECT_EQ(stack_double.empty(), true);
  EXPECT_EQ(stack_string.empty(), true);
  EXPECT_EQ(stach_char.empty(), true);

  EXPECT_THROW(stack_int.top(), std::out_of_range);
  EXPECT_THROW(stack_double.top(), std::out_of_range);
  EXPECT_THROW(stack_string.top(), std::out_of_range);
  EXPECT_THROW(stach_char.top(), std::out_of_range);

  EXPECT_THROW(stack_int.pop(), std::out_of_range);
  EXPECT_THROW(stack_double.pop(), std::out_of_range);
  EXPECT_THROW(stack_string.pop(), std::out_of_range);
  EXPECT_THROW(stach_char.pop(), std::out_of_range);
}

TEST(StackTest, ArrayConstructor) {
  my_containers::Stack<int> stack_int{4, 5, 6, 7, 2, -55};
  my_containers::Stack<double> stack_double{3.3, 5.5, 5.555, -110.5, 23.44, 0};
  my_containers::Stack<std::string> stack_string{"Hell", "to", "you", "!"};
  my_containers::Stack<char> stach_char{'f', '0', '\0', 'd', '1', 'k'};

  EXPECT_EQ(stack_int.size(), 6);
  EXPECT_EQ(stack_double.size(), 6);
  EXPECT_EQ(stack_string.size(), 4);
  EXPECT_EQ(stach_char.size(), 6);

  EXPECT_EQ(stack_int.empty(), false);
  EXPECT_EQ(stack_double.empty(), false);
  EXPECT_EQ(stack_string.empty(), false);
  EXPECT_EQ(stach_char.empty(), false);

  EXPECT_EQ(stack_int.top(), -55);
  EXPECT_EQ(stack_double.top(), 0);
  EXPECT_EQ(stack_string.top(), "!");
  EXPECT_EQ(stach_char.top(), 'k');

  stack_int.pop();
  stack_double.pop();
  stack_string.pop();
  stach_char.pop();

  EXPECT_EQ(stack_int.top(), 2);
  EXPECT_EQ(stack_double.top(), 23.44);
  EXPECT_EQ(stack_string.top(), "you");
  EXPECT_EQ(stach_char.top(), '1');

  stack_int.push(5.5);
  stack_double.push(5.555);
  stack_string.push("Avdol");
  stach_char.push(' ');

  EXPECT_EQ(stack_int.top(), 5);
  EXPECT_EQ(stack_double.top(), 5.555);
  EXPECT_EQ(stack_string.top(), "Avdol");
  EXPECT_EQ(stach_char.top(), ' ');
}

TEST(StackTest, Swap) {
  my_containers::Stack<int> stack_int{4, 5, 6, 7, 2, -55};
  my_containers::Stack<double> stack_double{3.3, 5.5, 5.555, -110.5, 23.44, 0};
  my_containers::Stack<std::string> stack_string{"Hell", "to", "you", "!"};
  my_containers::Stack<char> stach_char{'f', '0', '\0', 'd', '1', 'k'};

  my_containers::Stack<int> stack_int2{1, 2, 3};
  my_containers::Stack<double> stack_double2{4.5, 7, 6, 10};
  my_containers::Stack<std::string> stack_string2{"Hello", ",", "World"};
  my_containers::Stack<char> stach_char2{'f', '0', '0', 'l'};

  EXPECT_EQ(stack_int.size(), 6);
  EXPECT_EQ(stack_double.size(), 6);
  EXPECT_EQ(stack_string.size(), 4);
  EXPECT_EQ(stach_char.size(), 6);

  EXPECT_EQ(stack_int.empty(), false);
  EXPECT_EQ(stack_double.empty(), false);
  EXPECT_EQ(stack_string.empty(), false);
  EXPECT_EQ(stach_char.empty(), false);

  EXPECT_EQ(stack_int.top(), -55);
  EXPECT_EQ(stack_double.top(), 0);
  EXPECT_EQ(stack_string.top(), "!");
  EXPECT_EQ(stach_char.top(), 'k');

  EXPECT_EQ(stack_int2.size(), 3);
  EXPECT_EQ(stack_double2.size(), 4);
  EXPECT_EQ(stack_string2.size(), 3);
  EXPECT_EQ(stach_char2.size(), 4);

  EXPECT_EQ(stack_int2.empty(), false);
  EXPECT_EQ(stack_double2.empty(), false);
  EXPECT_EQ(stack_string2.empty(), false);
  EXPECT_EQ(stach_char2.empty(), false);

  EXPECT_EQ(stack_int2.top(), 3);
  EXPECT_EQ(stack_double2.top(), 10);
  EXPECT_EQ(stack_string2.top(), "World");
  EXPECT_EQ(stach_char2.top(), 'l');

  stack_int.swap(stack_int2);
  stack_double.swap(stack_double2);
  stack_string.swap(stack_string2);
  stach_char.swap(stach_char2);

  EXPECT_EQ(stack_int.size(), 3);
  EXPECT_EQ(stack_double.size(), 4);
  EXPECT_EQ(stack_string.size(), 3);
  EXPECT_EQ(stach_char.size(), 4);

  EXPECT_EQ(stack_int.empty(), false);
  EXPECT_EQ(stack_double.empty(), false);
  EXPECT_EQ(stack_string.empty(), false);
  EXPECT_EQ(stach_char.empty(), false);

  EXPECT_EQ(stack_int.top(), 3);
  EXPECT_EQ(stack_double.top(), 10);
  EXPECT_EQ(stack_string.top(), "World");
  EXPECT_EQ(stach_char.top(), 'l');

  EXPECT_EQ(stack_int2.size(), 6);
  EXPECT_EQ(stack_double2.size(), 6);
  EXPECT_EQ(stack_string2.size(), 4);
  EXPECT_EQ(stach_char2.size(), 6);

  EXPECT_EQ(stack_int2.empty(), false);
  EXPECT_EQ(stack_double2.empty(), false);
  EXPECT_EQ(stack_string2.empty(), false);
  EXPECT_EQ(stach_char2.empty(), false);

  EXPECT_EQ(stack_int2.top(), -55);
  EXPECT_EQ(stack_double2.top(), 0);
  EXPECT_EQ(stack_string2.top(), "!");
  EXPECT_EQ(stach_char2.top(), 'k');
}

TEST(StackTest, MoveAssignment) {
  using std::move;
  my_containers::Stack<int> stack_int{4, 5, 6, 7, 2, -55};
  my_containers::Stack<double> stack_double{3.3, 5.5, 5.555, -110.5, 23.44, 0};
  my_containers::Stack<std::string> stack_string{"Hell", "to", "you", "!"};
  my_containers::Stack<char> stach_char{'f', '0', '\0', 'd', '1', 'k'};

  my_containers::Stack<int> stack_int2;
  my_containers::Stack<double> stack_double2;
  my_containers::Stack<std::string> stack_string2;
  my_containers::Stack<char> stach_char2;

  EXPECT_EQ(stack_int.size(), 6);
  EXPECT_EQ(stack_double.size(), 6);
  EXPECT_EQ(stack_string.size(), 4);
  EXPECT_EQ(stach_char.size(), 6);

  EXPECT_EQ(stack_int.empty(), false);
  EXPECT_EQ(stack_double.empty(), false);
  EXPECT_EQ(stack_string.empty(), false);
  EXPECT_EQ(stach_char.empty(), false);

  EXPECT_EQ(stack_int.top(), -55);
  EXPECT_EQ(stack_double.top(), 0);
  EXPECT_EQ(stack_string.top(), "!");
  EXPECT_EQ(stach_char.top(), 'k');

  EXPECT_EQ(stack_int2.size(), 0);
  EXPECT_EQ(stack_double2.size(), 0);
  EXPECT_EQ(stack_string2.size(), 0);
  EXPECT_EQ(stach_char2.size(), 0);

  EXPECT_EQ(stack_int2.empty(), true);
  EXPECT_EQ(stack_double2.empty(), true);
  EXPECT_EQ(stack_string2.empty(), true);
  EXPECT_EQ(stach_char2.empty(), true);

  EXPECT_THROW(stack_int2.top(), std::out_of_range);
  EXPECT_THROW(stack_double2.top(), std::out_of_range);
  EXPECT_THROW(stack_string2.top(), std::out_of_range);
  EXPECT_THROW(stach_char2.top(), std::out_of_range);

  stack_int2 = move(stack_int);
  stack_double2 = move(stack_double);
  stack_string2 = move(stack_string);
  stach_char2 = move(stach_char);

  EXPECT_EQ(stack_int2.size(), 6);
  EXPECT_EQ(stack_double2.size(), 6);
  EXPECT_EQ(stack_string2.size(), 4);
  EXPECT_EQ(stach_char2.size(), 6);

  EXPECT_EQ(stack_int2.empty(), false);
  EXPECT_EQ(stack_double2.empty(), false);
  EXPECT_EQ(stack_string2.empty(), false);
  EXPECT_EQ(stach_char2.empty(), false);

  EXPECT_EQ(stack_int2.top(), -55);
  EXPECT_EQ(stack_double2.top(), 0);
  EXPECT_EQ(stack_string2.top(), "!");
  EXPECT_EQ(stach_char2.top(), 'k');

  EXPECT_EQ(stack_int.size(), 0);
  EXPECT_EQ(stack_double.size(), 0);
  EXPECT_EQ(stack_string.size(), 0);
  EXPECT_EQ(stach_char.size(), 0);

  EXPECT_EQ(stack_int.empty(), true);
  EXPECT_EQ(stack_double.empty(), true);
  EXPECT_EQ(stack_string.empty(), true);
  EXPECT_EQ(stach_char.empty(), true);

  EXPECT_THROW(stack_int.top(), std::out_of_range);
  EXPECT_THROW(stack_double.top(), std::out_of_range);
  EXPECT_THROW(stack_string.top(), std::out_of_range);
  EXPECT_THROW(stach_char.top(), std::out_of_range);
}

TEST(StackTest, MoveConstructor) {
  using std::move;
  my_containers::Stack<int> stack_int{4, 5, 6, 7, 2, -55};
  my_containers::Stack<double> stack_double{3.3, 5.5, 5.555, -110.5, 23.44, 0};
  my_containers::Stack<std::string> stack_string{"Hell", "to", "you", "!"};
  my_containers::Stack<char> stach_char{'f', '0', '\0', 'd', '1', 'k'};

  EXPECT_EQ(stack_int.size(), 6);
  EXPECT_EQ(stack_double.size(), 6);
  EXPECT_EQ(stack_string.size(), 4);
  EXPECT_EQ(stach_char.size(), 6);

  EXPECT_EQ(stack_int.empty(), false);
  EXPECT_EQ(stack_double.empty(), false);
  EXPECT_EQ(stack_string.empty(), false);
  EXPECT_EQ(stach_char.empty(), false);

  EXPECT_EQ(stack_int.top(), -55);
  EXPECT_EQ(stack_double.top(), 0);
  EXPECT_EQ(stack_string.top(), "!");
  EXPECT_EQ(stach_char.top(), 'k');

  my_containers::Stack<int> stack_int2(move(stack_int));
  my_containers::Stack<double> stack_double2(move(stack_double));
  my_containers::Stack<std::string> stack_string2(move(stack_string));
  my_containers::Stack<char> stach_char2(move(stach_char));

  EXPECT_EQ(stack_int2.size(), 6);
  EXPECT_EQ(stack_double2.size(), 6);
  EXPECT_EQ(stack_string2.size(), 4);
  EXPECT_EQ(stach_char2.size(), 6);

  EXPECT_EQ(stack_int2.empty(), false);
  EXPECT_EQ(stack_double2.empty(), false);
  EXPECT_EQ(stack_string2.empty(), false);
  EXPECT_EQ(stach_char2.empty(), false);

  EXPECT_EQ(stack_int2.top(), -55);
  EXPECT_EQ(stack_double2.top(), 0);
  EXPECT_EQ(stack_string2.top(), "!");
  EXPECT_EQ(stach_char2.top(), 'k');

  EXPECT_EQ(stack_int.size(), 0);
  EXPECT_EQ(stack_double.size(), 0);
  EXPECT_EQ(stack_string.size(), 0);
  EXPECT_EQ(stach_char.size(), 0);

  EXPECT_EQ(stack_int.empty(), true);
  EXPECT_EQ(stack_double.empty(), true);
  EXPECT_EQ(stack_string.empty(), true);
  EXPECT_EQ(stach_char.empty(), true);

  EXPECT_THROW(stack_int.top(), std::out_of_range);
  EXPECT_THROW(stack_double.top(), std::out_of_range);
  EXPECT_THROW(stack_string.top(), std::out_of_range);
  EXPECT_THROW(stach_char.top(), std::out_of_range);
}

TEST(StackTest, CopyAssignment) {
  my_containers::Stack<int> stack_int{4, 5, 6, 7, 2, -55};
  my_containers::Stack<double> stack_double{3.3, 5.5, 5.555, -110.5, 23.44, 0};
  my_containers::Stack<std::string> stack_string{"Hell", "to", "you", "!"};
  my_containers::Stack<char> stach_char{'f', '0', '\0', 'd', '1', 'k'};

  my_containers::Stack<int> stack_int2;
  my_containers::Stack<double> stack_double2;
  my_containers::Stack<std::string> stack_string2;
  my_containers::Stack<char> stach_char2;

  EXPECT_EQ(stack_int.size(), 6);
  EXPECT_EQ(stack_double.size(), 6);
  EXPECT_EQ(stack_string.size(), 4);
  EXPECT_EQ(stach_char.size(), 6);

  EXPECT_EQ(stack_int.empty(), false);
  EXPECT_EQ(stack_double.empty(), false);
  EXPECT_EQ(stack_string.empty(), false);
  EXPECT_EQ(stach_char.empty(), false);

  EXPECT_EQ(stack_int.top(), -55);
  EXPECT_EQ(stack_double.top(), 0);
  EXPECT_EQ(stack_string.top(), "!");
  EXPECT_EQ(stach_char.top(), 'k');

  EXPECT_EQ(stack_int2.size(), 0);
  EXPECT_EQ(stack_double2.size(), 0);
  EXPECT_EQ(stack_string2.size(), 0);
  EXPECT_EQ(stach_char2.size(), 0);

  EXPECT_EQ(stack_int2.empty(), true);
  EXPECT_EQ(stack_double2.empty(), true);
  EXPECT_EQ(stack_string2.empty(), true);
  EXPECT_EQ(stach_char2.empty(), true);

  EXPECT_THROW(stack_int2.top(), std::out_of_range);
  EXPECT_THROW(stack_double2.top(), std::out_of_range);
  EXPECT_THROW(stack_string2.top(), std::out_of_range);
  EXPECT_THROW(stach_char2.top(), std::out_of_range);

  stack_int2 = stack_int;
  stack_double2 = stack_double;
  stack_string2 = stack_string;
  stach_char2 = stach_char;

  EXPECT_EQ(stack_int2.size(), 6);
  EXPECT_EQ(stack_double2.size(), 6);
  EXPECT_EQ(stack_string2.size(), 4);
  EXPECT_EQ(stach_char2.size(), 6);

  EXPECT_EQ(stack_int2.empty(), false);
  EXPECT_EQ(stack_double2.empty(), false);
  EXPECT_EQ(stack_string2.empty(), false);
  EXPECT_EQ(stach_char2.empty(), false);

  EXPECT_EQ(stack_int2.top(), -55);
  EXPECT_EQ(stack_double2.top(), 0);
  EXPECT_EQ(stack_string2.top(), "!");
  EXPECT_EQ(stach_char2.top(), 'k');

  EXPECT_EQ(stack_int.size(), 6);
  EXPECT_EQ(stack_double.size(), 6);
  EXPECT_EQ(stack_string.size(), 4);
  EXPECT_EQ(stach_char.size(), 6);

  EXPECT_EQ(stack_int.empty(), false);
  EXPECT_EQ(stack_double.empty(), false);
  EXPECT_EQ(stack_string.empty(), false);
  EXPECT_EQ(stach_char.empty(), false);

  EXPECT_EQ(stack_int.top(), -55);
  EXPECT_EQ(stack_double.top(), 0);
  EXPECT_EQ(stack_string.top(), "!");
  EXPECT_EQ(stach_char.top(), 'k');

  stack_int2.~Stack();
  stack_double2.~Stack();
  stack_string2.~Stack();
  stach_char2.~Stack();

  EXPECT_EQ(stack_int.size(), 6);
  EXPECT_EQ(stack_double.size(), 6);
  EXPECT_EQ(stack_string.size(), 4);
  EXPECT_EQ(stach_char.size(), 6);

  EXPECT_EQ(stack_int.empty(), false);
  EXPECT_EQ(stack_double.empty(), false);
  EXPECT_EQ(stack_string.empty(), false);
  EXPECT_EQ(stach_char.empty(), false);

  EXPECT_EQ(stack_int.top(), -55);
  EXPECT_EQ(stack_double.top(), 0);
  EXPECT_EQ(stack_string.top(), "!");
  EXPECT_EQ(stach_char.top(), 'k');

  EXPECT_EQ(stack_int2.size(), 0);
  EXPECT_EQ(stack_double2.size(), 0);
  EXPECT_EQ(stack_string2.size(), 0);
  EXPECT_EQ(stach_char2.size(), 0);

  EXPECT_EQ(stack_int2.empty(), true);
  EXPECT_EQ(stack_double2.empty(), true);
  EXPECT_EQ(stack_string2.empty(), true);
  EXPECT_EQ(stach_char2.empty(), true);

  EXPECT_THROW(stack_int2.top(), std::out_of_range);
  EXPECT_THROW(stack_double2.top(), std::out_of_range);
  EXPECT_THROW(stack_string2.top(), std::out_of_range);
  EXPECT_THROW(stach_char2.top(), std::out_of_range);
}

TEST(StackTest, CopyConstructor) {
  my_containers::Stack<int> stack_int{4, 5, 6, 7, 2, -55};
  my_containers::Stack<double> stack_double{3.3, 5.5, 5.555, -110.5, 23.44, 0};
  my_containers::Stack<std::string> stack_string{"Hell", "to", "you", "!"};
  my_containers::Stack<char> stach_char{'f', '0', '\0', 'd', '1', 'k'};

  EXPECT_EQ(stack_int.size(), 6);
  EXPECT_EQ(stack_double.size(), 6);
  EXPECT_EQ(stack_string.size(), 4);
  EXPECT_EQ(stach_char.size(), 6);

  EXPECT_EQ(stack_int.empty(), false);
  EXPECT_EQ(stack_double.empty(), false);
  EXPECT_EQ(stack_string.empty(), false);
  EXPECT_EQ(stach_char.empty(), false);

  EXPECT_EQ(stack_int.top(), -55);
  EXPECT_EQ(stack_double.top(), 0);
  EXPECT_EQ(stack_string.top(), "!");
  EXPECT_EQ(stach_char.top(), 'k');

  my_containers::Stack<int> stack_int2 = stack_int;
  my_containers::Stack<double> stack_double2 = stack_double;
  my_containers::Stack<std::string> stack_string2 = stack_string;
  my_containers::Stack<char> stach_char2 = stach_char;

  EXPECT_EQ(stack_int2.size(), 6);
  EXPECT_EQ(stack_double2.size(), 6);
  EXPECT_EQ(stack_string2.size(), 4);
  EXPECT_EQ(stach_char2.size(), 6);

  EXPECT_EQ(stack_int2.empty(), false);
  EXPECT_EQ(stack_double2.empty(), false);
  EXPECT_EQ(stack_string2.empty(), false);
  EXPECT_EQ(stach_char2.empty(), false);

  EXPECT_EQ(stack_int2.top(), -55);
  EXPECT_EQ(stack_double2.top(), 0);
  EXPECT_EQ(stack_string2.top(), "!");
  EXPECT_EQ(stach_char2.top(), 'k');

  EXPECT_EQ(stack_int.size(), 6);
  EXPECT_EQ(stack_double.size(), 6);
  EXPECT_EQ(stack_string.size(), 4);
  EXPECT_EQ(stach_char.size(), 6);

  EXPECT_EQ(stack_int.empty(), false);
  EXPECT_EQ(stack_double.empty(), false);
  EXPECT_EQ(stack_string.empty(), false);
  EXPECT_EQ(stach_char.empty(), false);

  EXPECT_EQ(stack_int.top(), -55);
  EXPECT_EQ(stack_double.top(), 0);
  EXPECT_EQ(stack_string.top(), "!");
  EXPECT_EQ(stach_char.top(), 'k');

  stack_int2.~Stack();
  stack_double2.~Stack();
  stack_string2.~Stack();
  stach_char2.~Stack();

  EXPECT_EQ(stack_int.size(), 6);
  EXPECT_EQ(stack_double.size(), 6);
  EXPECT_EQ(stack_string.size(), 4);
  EXPECT_EQ(stach_char.size(), 6);

  EXPECT_EQ(stack_int.empty(), false);
  EXPECT_EQ(stack_double.empty(), false);
  EXPECT_EQ(stack_string.empty(), false);
  EXPECT_EQ(stach_char.empty(), false);

  EXPECT_EQ(stack_int.top(), -55);
  EXPECT_EQ(stack_double.top(), 0);
  EXPECT_EQ(stack_string.top(), "!");
  EXPECT_EQ(stach_char.top(), 'k');

  EXPECT_EQ(stack_int2.size(), 0);
  EXPECT_EQ(stack_double2.size(), 0);
  EXPECT_EQ(stack_string2.size(), 0);
  EXPECT_EQ(stach_char2.size(), 0);

  EXPECT_EQ(stack_int2.empty(), true);
  EXPECT_EQ(stack_double2.empty(), true);
  EXPECT_EQ(stack_string2.empty(), true);
  EXPECT_EQ(stach_char2.empty(), true);

  EXPECT_THROW(stack_int2.top(), std::out_of_range);
  EXPECT_THROW(stack_double2.top(), std::out_of_range);
  EXPECT_THROW(stack_string2.top(), std::out_of_range);
  EXPECT_THROW(stach_char2.top(), std::out_of_range);
}
TEST(StackTest, BonusFunctions) {
  my_containers::Stack<int> stack_int{4, 5, 6, 7, 2, -55};
  my_containers::Stack<double> stack_double{3.3, 5.5, 5.555, -110.5, 23.44, 0};
  my_containers::Stack<std::string> stack_string{"Hell", "to", "you", "!"};
  my_containers::Stack<char> stach_char{'f', '0', '\0', 'd', '1', 'k'};

  stack_int.insert_many_back(44, 32, 434, 322, 44, 55, 66, 77, 22, 34, 5435,
                             5345, 545, 345, 435, 35, 35, -55);
  EXPECT_EQ(stack_int.top(), -55);
  EXPECT_EQ(stack_int.size(), 24);
  EXPECT_EQ(stack_int.empty(), false);
  stack_double.insert_many_back(132.13, 31231.312313, 1.1, 2.2, 3.3, 4.4, 5.5,
                                6.6);
  EXPECT_EQ(stack_double.top(), 6.6);
  EXPECT_EQ(stack_double.size(), 14);
  EXPECT_EQ(stack_double.empty(), false);
  stack_string.insert_many_back("Hello", "World", "!");
  EXPECT_EQ(stack_string.top(), "!");
  EXPECT_EQ(stack_string.size(), 7);
  EXPECT_EQ(stack_string.empty(), false);
  stach_char.insert_many_back('1', '2', '3', '4', '5', '6', '\t');
  EXPECT_EQ(stach_char.top(), '\t');
  EXPECT_EQ(stach_char.size(), 13);
  EXPECT_EQ(stach_char.empty(), false);

  stack_int.insert_many_back(5);
  EXPECT_EQ(stack_int.top(), 5);
  EXPECT_EQ(stack_int.size(), 25);
  stack_double.insert_many_back(5);
  EXPECT_EQ(stack_double.top(), 5);
  EXPECT_EQ(stack_double.size(), 15);
  stack_string.insert_many_back("5");
  EXPECT_EQ(stack_string.top(), "5");
  EXPECT_EQ(stack_string.size(), 8);
  stach_char.insert_many_back('5');
  EXPECT_EQ(stach_char.top(), '5');
  EXPECT_EQ(stach_char.size(), 14);

  stack_int.insert_many_back();
  EXPECT_EQ(stack_int.top(), 5);
  EXPECT_EQ(stack_int.size(), 25);
  stack_double.insert_many_back();
  EXPECT_EQ(stack_double.top(), 5);
  EXPECT_EQ(stack_double.size(), 15);
  stack_string.insert_many_back();
  EXPECT_EQ(stack_string.top(), "5");
  EXPECT_EQ(stack_string.size(), 8);
  stach_char.insert_many_back();
  EXPECT_EQ(stach_char.top(), '5');
  EXPECT_EQ(stach_char.size(), 14);

  my_containers::Stack<int> stack_int_2;
  my_containers::Stack<double> stack_double_2;
  my_containers::Stack<std::string> stack_string_2;
  my_containers::Stack<char> stach_char_2;
  EXPECT_EQ(stack_int_2.empty(), true);
  EXPECT_EQ(stack_double_2.empty(), true);
  EXPECT_EQ(stack_string_2.empty(), true);
  EXPECT_EQ(stach_char_2.empty(), true);
  EXPECT_EQ(stack_int_2.size(), 0);
  EXPECT_EQ(stack_double_2.size(), 0);
  EXPECT_EQ(stack_string_2.size(), 0);
  EXPECT_EQ(stach_char_2.size(), 0);

  stack_int_2.insert_many_back();
  stack_double_2.insert_many_back();
  stack_string_2.insert_many_back();
  stach_char_2.insert_many_back();
  EXPECT_EQ(stack_int_2.empty(), true);
  EXPECT_EQ(stack_double_2.empty(), true);
  EXPECT_EQ(stack_string_2.empty(), true);
  EXPECT_EQ(stach_char_2.empty(), true);
  EXPECT_EQ(stack_int_2.size(), 0);
  EXPECT_EQ(stack_double_2.size(), 0);
  EXPECT_EQ(stack_string_2.size(), 0);
  EXPECT_EQ(stach_char_2.size(), 0);

  stack_int_2.insert_many_back(1, 2, 3, 4, 5);
  stack_double_2.insert_many_back(1.1, 2.2, 3.3, 4.4, 5.5);
  stack_string_2.insert_many_back("1", "2", "3", "4", "5");
  stach_char_2.insert_many_back('1', '2', '3', '4', '5');
  EXPECT_EQ(stack_int_2.empty(), false);
  EXPECT_EQ(stack_double_2.empty(), false);
  EXPECT_EQ(stack_string_2.empty(), false);
  EXPECT_EQ(stach_char_2.empty(), false);
  EXPECT_EQ(stack_int_2.size(), 5);
  EXPECT_EQ(stack_double_2.size(), 5);
  EXPECT_EQ(stack_string_2.size(), 5);
  EXPECT_EQ(stach_char_2.size(), 5);
  EXPECT_EQ(stack_int_2.top(), 5);
  EXPECT_EQ(stack_double_2.top(), 5.5);
  EXPECT_EQ(stack_string_2.top(), "5");
  EXPECT_EQ(stach_char_2.top(), '5');

  stack_int_2.insert_many_back(9.9);
  EXPECT_EQ(stack_int_2.top(), 9);
  stack_int_2.insert_many_back('9');
  EXPECT_EQ(stack_int_2.top(), 9 + '0');
}
