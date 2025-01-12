#include "global_tests.h"
// #include "../containers/AVLtree/avl_tree.hpp"
// #include "../containers/stack/stack.hpp"
// #include "../containers/vector/vector.h"

TEST(TreeTest, DefaultConstructor_SS) {
  my_containers::Tree<int, int> tree_int;
  my_containers::Tree<double, double> tree_double;
  my_containers::Tree<std::string, std::string> tree_str;
  my_containers::Tree<char, char> tree_char;
  tree_int.insert(5);
  tree_int.insert(2);
  tree_int.insert(8);
  tree_int.insert(4);
  tree_int.insert(15);
  tree_int.insert(7);
  tree_int.insert(44);
  tree_int.insert(0);
  tree_int.insert(-5);
  tree_int.insert(-1);
  tree_int.insert(-15);
  tree_int.insert(-22);
  tree_int.insert(-22);
  tree_int.insert(-55);
  EXPECT_EQ(tree_int.size(), 13);
  EXPECT_EQ(tree_int.empty(), false);
  tree_double.insert(3.55);
  tree_double.insert(2.22);
  tree_double.insert(8.88);
  tree_double.insert(4.44);
  tree_double.insert(15.15);
  tree_double.insert(7.77);
  tree_double.insert(44.44);
  tree_double.insert(0.00);
  tree_double.insert(-5.55);
  tree_double.insert(-1.11);
  tree_double.insert(-15.15);
  tree_double.insert(-22.22);
  tree_double.insert(-22.22);
  tree_double.insert(-55.55);
  EXPECT_EQ(tree_double.size(), 13);
  EXPECT_EQ(tree_double.empty(), false);
  tree_str.insert("hello");
  tree_str.insert("world");
  tree_str.insert("s21");
  tree_str.insert("tree");
  tree_str.insert("test");
  tree_str.insert("tree");
  tree_str.insert("tree");
  tree_str.insert("tree");
  tree_str.insert("Rock");
  tree_str.insert("Roll");
  EXPECT_EQ(tree_str.size(), 7);
  EXPECT_EQ(tree_str.empty(), false);
  tree_char.insert('a');
  tree_char.insert('b');
  tree_char.insert('c');
  tree_char.insert('h');
  tree_char.insert('e');
  tree_char.insert('l');
  tree_char.insert('l');
  tree_char.insert('o');
  EXPECT_EQ(tree_char.size(), 7);
  EXPECT_EQ(tree_char.empty(), false);

  tree_int.clear();
  EXPECT_EQ(tree_int.size(), 0);
  EXPECT_EQ(tree_int.empty(), true);

  tree_double.clear();
  EXPECT_EQ(tree_double.size(), 0);
  EXPECT_EQ(tree_double.empty(), true);

  tree_str.clear();
  EXPECT_EQ(tree_str.size(), 0);
  EXPECT_EQ(tree_str.empty(), true);

  tree_char.clear();
  EXPECT_EQ(tree_char.size(), 0);
  EXPECT_EQ(tree_char.empty(), true);
}
TEST(TreeTest, DefaultConstructor_MS) {
  my_containers::Tree<int, double> tree_double;
  my_containers::Tree<char, std::string> tree_str;
  tree_double.insert(5, 5.55);
  tree_double.insert(2, 3453.43);
  tree_double.insert(8, 333.4);
  tree_double.insert(4, -66.6);
  tree_double.insert(15, -1000);
  tree_double.insert(7, -457);
  tree_double.insert(44, 0);
  tree_double.insert(0, 0);
  tree_double.insert(-5, 0.553535);
  tree_double.insert(-1, 0.353453);
  tree_double.insert(-15, 1234567890.4);
  tree_double.insert(-22, 9876543.33333);
  tree_double.insert(-22, 23232.2323232);
  tree_double.insert(-55, -3333.3);
  tree_double.showTreeVertical();
  tree_double.showTreeVerticalVal();
  tree_double.crazyPrinter();
  EXPECT_EQ(tree_double.size(), 13);
  EXPECT_EQ(tree_double.empty(), false);
  tree_str.insert('\t', "hello");
  tree_str.insert('\0', "world");
  tree_str.insert('4', "s21");
  tree_str.insert('\0', "tree");
  tree_str.insert('5', "test");
  tree_str.insert('f', "tree");
  tree_str.insert('i', "tree");
  tree_str.insert('-', "tree");
  tree_str.insert('.', "Rock");
  tree_str.insert('/', "Roll");
  EXPECT_EQ(tree_str.size(), 9);
  EXPECT_EQ(tree_str.empty(), false);

  tree_double.clear();
  EXPECT_EQ(tree_double.size(), 0);
  EXPECT_EQ(tree_double.empty(), true);

  tree_str.clear();
  EXPECT_EQ(tree_str.size(), 0);
  EXPECT_EQ(tree_str.empty(), true);

  my_containers::Tree<int, int> tree_int;
  tree_int.clear();
  EXPECT_EQ(tree_int.size(), 0);
  EXPECT_EQ(tree_int.empty(), true);
}
TEST(TreeTest, RootConstructor_SS) {
  my_containers::Tree<int, int> tree_int{10};
  my_containers::Tree<double, double> tree_double{555.55};
  my_containers::Tree<std::string, std::string> tree_str{"Jazz"};
  my_containers::Tree<char, char> tree_char{'5'};
  tree_int.insert(5);
  tree_int.insert(2);
  tree_int.insert(8);
  tree_int.insert(4);
  tree_int.insert(15);
  tree_int.insert(7);
  tree_int.insert(44);
  tree_int.insert(0);
  tree_int.insert(-5);
  tree_int.insert(-1);
  tree_int.insert(-15);
  tree_int.insert(-22);
  tree_int.insert(-22);
  tree_int.insert(-55);
  EXPECT_EQ(tree_int.size(), 14);
  EXPECT_EQ(tree_int.empty(), false);
  tree_double.insert(3.55);
  tree_double.insert(2.22);
  tree_double.insert(8.88);
  tree_double.insert(4.44);
  tree_double.insert(15.15);
  tree_double.insert(7.77);
  tree_double.insert(44.44);
  tree_double.insert(0.00);
  tree_double.insert(-5.55);
  tree_double.insert(-1.11);
  tree_double.insert(-15.15);
  tree_double.insert(-22.22);
  tree_double.insert(-22.22);
  tree_double.insert(-55.55);
  EXPECT_EQ(tree_double.size(), 14);
  EXPECT_EQ(tree_double.empty(), false);
  tree_str.insert("hello");
  tree_str.insert("world");
  tree_str.insert("s21");
  tree_str.insert("tree");
  tree_str.insert("test");
  tree_str.insert("tree");
  tree_str.insert("tree");
  tree_str.insert("tree");
  tree_str.insert("Rock");
  tree_str.insert("Roll");
  EXPECT_EQ(tree_str.size(), 8);
  EXPECT_EQ(tree_str.empty(), false);
  tree_char.insert('a');
  tree_char.insert('b');
  tree_char.insert('c');
  tree_char.insert('h');
  tree_char.insert('e');
  tree_char.insert('l');
  tree_char.insert('l');
  tree_char.insert('o');
  EXPECT_EQ(tree_char.size(), 8);
  EXPECT_EQ(tree_char.empty(), false);

  tree_int.clear();
  EXPECT_EQ(tree_int.size(), 0);
  EXPECT_EQ(tree_int.empty(), true);
  tree_double.clear();
  EXPECT_EQ(tree_double.size(), 0);
  EXPECT_EQ(tree_double.empty(), true);
  tree_str.clear();
  EXPECT_EQ(tree_str.size(), 0);
  EXPECT_EQ(tree_str.empty(), true);
  tree_char.clear();
  EXPECT_EQ(tree_char.size(), 0);
  EXPECT_EQ(tree_char.empty(), true);
}
TEST(TreeTest, RootConstructor_MS) {
  my_containers::Tree<int, double> tree_double(144, 6.6);
  std::string tmp = "Hello world!";
  my_containers::Tree<char, std::string> tree_str('Z', tmp);
  tree_double.insert(5, 5.55);
  tree_double.insert(2, 3453.43);
  tree_double.insert(8, 333.4);
  tree_double.insert(4, -66.6);
  tree_double.insert(15, -1000);
  tree_double.insert(7, -457);
  tree_double.insert(44, 0);
  tree_double.insert(0, 0);
  tree_double.insert(-5, 0.553535);
  tree_double.insert(-1, 0.353453);
  tree_double.insert(-15, 1234567890.4);
  tree_double.insert(-22, 9876543.33333);
  tree_double.insert(-22, 23232.2323232);
  tree_double.insert(-55, -3333.3);
  EXPECT_EQ(tree_double.size(), 14);
  EXPECT_EQ(tree_double.empty(), false);
  tree_str.insert('\t', "hello");
  tree_str.insert('\0', "world");
  tree_str.insert('4', "s21");
  tree_str.insert('\0', "tree");
  tree_str.insert('5', "test");
  tree_str.insert('f', "tree");
  tree_str.insert('i', "tree");
  tree_str.insert('-', "tree");
  tree_str.insert('.', "Rock");
  tree_str.insert('/', "Roll");
  EXPECT_EQ(tree_str.size(), 10);
  EXPECT_EQ(tree_str.empty(), false);

  tree_double.clear();
  EXPECT_EQ(tree_double.size(), 0);
  EXPECT_EQ(tree_double.empty(), true);

  tree_str.clear();
  EXPECT_EQ(tree_str.size(), 0);
  EXPECT_EQ(tree_str.empty(), true);

  my_containers::Tree<int, int> tree_int;
  tree_int.clear();
  EXPECT_EQ(tree_int.size(), 0);
  EXPECT_EQ(tree_int.empty(), true);
}
TEST(TreeTest, ArrayConstructor_SS) {
  my_containers::Tree<int, int> tree_int{
      10, 2, 3, 44, 5, 66, -5, -100, 0, 0, 0, 5, 33, 23, 64, 55, 0, 1, 1000};
  my_containers::Tree<double, double> tree_double{
      555.55, 423.2, 2, 1000, -55.55, -33.3, -1000, 100, 1000, 100, -5.5};
  my_containers::Tree<std::string, std::string> tree_str{
      "Jazz",     "I",    "played", "with", "Blues",
      "brothers", "like", "Yoda",   "Wow",  "!"};
  my_containers::Tree<char, char> tree_char{'a',  'b', 'c', 'd', '5', '1',
                                            'a',  '-', '=', '+', 'q', '\n',
                                            '\t', 'y', ']', '[', '(', '`'};
  tree_int.insert(5);
  tree_int.insert(2);
  tree_int.insert(8);
  tree_int.insert(4);
  tree_int.insert(4.55);
  EXPECT_EQ(tree_int.size(), 17);
  EXPECT_EQ(tree_int.empty(), false);
  tree_double.insert(3.55);
  tree_double.insert(2.22);
  tree_double.insert(8.88);
  tree_double.insert(4.44);
  tree_double.insert(15.15);
  EXPECT_EQ(tree_double.size(), 14);
  EXPECT_EQ(tree_double.empty(), false);
  EXPECT_EQ(tree_str.size(), 10);
  EXPECT_EQ(tree_str.empty(), false);
  tree_char.insert('a');
  tree_char.insert('l');
  tree_char.insert('l');
  tree_char.insert('o');
  EXPECT_EQ(tree_char.size(), 19);
  EXPECT_EQ(tree_char.empty(), false);
}
TEST(TreeTest, ArrayConstructor_MS) {
  my_containers::Tree<int, double> tree_double{
      {10, 555.55}, {-600, 423.2}, {10000, 2},  {1, 1000},
      {11, -55.55}, {-55, -33.3},  {0, -1000},  {6, 100},
      {6, 1000},    {1234, 100},   {-4211, 5.5}};
  my_containers::Tree<std::string, char> tree_str{
      std::pair<std::string, char>{"Jazz", '5'},
      {"I", '5'},
      {"played", '5'},
      {"with", '5'},
      {"Blues", '5'},
      {"brothers", '5'},
      {"like", '5'},
      {"Yoda", '5'},
      {"Wow", '5'},
      {"!", '5'}};

  EXPECT_EQ(tree_double.size(), 10);
  EXPECT_EQ(tree_double.empty(), false);
  tree_double.insert(5, 5.55);
  tree_double.insert(2, 3453.43);
  tree_double.insert(8, 333.4);
  tree_double.insert(4, -66.6);
  tree_double.insert(15, -1000);
  tree_double.insert(7, -457);
  tree_double.insert(44, 0);
  tree_double.insert(0, 0);
  tree_double.insert(-5, 0.553535);
  tree_double.insert(-1, 0.353453);
  tree_double.insert(-15, 1234567890.4);
  tree_double.insert(-22, 9876543.33333);
  tree_double.insert(-22, 23232.2323232);
  tree_double.insert(-55, -3333.3);
  EXPECT_EQ(tree_double.size(), 21);

  EXPECT_EQ(tree_str.empty(), false);
  EXPECT_EQ(tree_str.size(), 10);
  tree_str.insert("hello", '\t');
  tree_str.insert("world", '\0');
  tree_str.insert("s21", '4');
  tree_str.insert("tree", '\0');
  tree_str.insert("test", '5');
  tree_str.insert("tree", 'f');
  tree_str.insert("tree", 'i');
  tree_str.insert("tree", '-');
  tree_str.insert("Rock", '.');
  tree_str.insert("Roll", '/');
  tree_str.insert("!", ',');
  EXPECT_EQ(tree_str.size(), 17);

  tree_double.clear();
  EXPECT_EQ(tree_double.size(), 0);
  EXPECT_EQ(tree_double.empty(), true);
}
TEST(TreeTest, CopyTree_SS) {
  my_containers::Tree<int, int> tree_int{
      10, 2, 3, 44, 5, 66, -5, -100, 0, 0, 0, 5, 33, 23, 64, 55, 0, 1, 1000};
  my_containers::Tree<double, double> tree_double{
      555.55, 423.2, 2, 1000, -55.55, -33.3, -1000, 100, 1000, 100, -5.5};
  my_containers::Tree<std::string, std::string> tree_str{
      "Jazz",     "I",    "played", "with", "Blues",
      "brothers", "like", "Yoda",   "Wow",  "!"};
  my_containers::Tree<char, char> tree_char{'a',  'b', 'c', 'd', '5', '1',
                                            'a',  '-', '=', '+', 'q', '\n',
                                            '\t', 'y', ']', '[', '(', '`'};
  EXPECT_EQ(tree_int.size(), 15);
  EXPECT_EQ(tree_double.size(), 9);
  EXPECT_EQ(tree_str.size(), 10);
  EXPECT_EQ(tree_char.size(), 17);

  my_containers::Tree<int, int> tree_int_2;
  tree_int.copyTree(tree_int_2);
  my_containers::Tree<double, double> tree_double_2;
  tree_double.copyTree(tree_double_2);
  my_containers::Tree<std::string, std::string> tree_str_2;
  tree_str.copyTree(tree_str_2);
  my_containers::Tree<char, char> tree_char_2;
  tree_char.copyTree(tree_char_2);

  EXPECT_EQ(tree_int_2.size(), 15);
  EXPECT_NE(&tree_int_2, &tree_int);
  EXPECT_EQ(tree_double_2.size(), 9);
  EXPECT_NE(&tree_double_2, &tree_double);
  EXPECT_EQ(tree_str_2.size(), 10);
  EXPECT_NE(&tree_str_2, &tree_str);
  EXPECT_EQ(tree_char_2.size(), 17);
  EXPECT_NE(&tree_char_2, &tree_char);

  tree_int.insert(5000);
  tree_double.insert(5000.5);
  tree_str.insert("5000");
  tree_char.insert('0');
  EXPECT_EQ(tree_int.size(), 16);
  EXPECT_EQ(tree_int_2.size(), 15);
  EXPECT_EQ(tree_double.size(), 10);
  EXPECT_EQ(tree_double_2.size(), 9);
  EXPECT_EQ(tree_str.size(), 11);
  EXPECT_EQ(tree_str_2.size(), 10);
  EXPECT_EQ(tree_char.size(), 18);
  EXPECT_EQ(tree_char_2.size(), 17);

  my_containers::Tree<int, int> tree_int_3;
  my_containers::Tree<int, int> tree_int_4;
  tree_int_3.copyTree(tree_int_4);
  EXPECT_EQ(tree_int_3.empty(), true);
  EXPECT_EQ(tree_int_4.empty(), true);

  EXPECT_EQ(tree_int_2.contains(-100), true);
  EXPECT_EQ(tree_int_2.containsVal(-100), true);
}
TEST(TreeTest, CopyTree_MS) {
  my_containers::Tree<double, int> tree_db_it{
      {555.55, 5}, {423.2, 2},   {1000, 0},     {-55.55, 6000},
      {-33.3, -5}, {-1000, 100}, {100100, 100}, {-5.5, 15}};
  my_containers::Tree<char, std::string> tree_ch_st{
      std::pair<char, std::string>{'5', "Jazz"},
      {'\n', "I"},
      {'y', "played"},
      {'(', "with"},
      {'`', "Blues"},
      {'-', "brothers"},
      {'=', "like"},
      {'b', "Yoda"},
      {'d', "Wow"},
      {'c', "!"}};
  EXPECT_EQ(tree_db_it.size(), 8);
  EXPECT_EQ(tree_ch_st.size(), 10);

  my_containers::Tree<double, int> tree_db_it_2;
  tree_db_it.copyTree(tree_db_it_2);

  my_containers::Tree<char, std::string> tree_ch_st_2;
  tree_ch_st.copyTree(tree_ch_st_2);

  EXPECT_EQ(tree_db_it_2.size(), 8);
  EXPECT_NE(&tree_db_it_2, &tree_db_it);
  EXPECT_EQ(tree_ch_st_2.size(), 10);
  EXPECT_NE(&tree_ch_st_2, &tree_ch_st);

  tree_db_it.insert(5000, 5);
  tree_ch_st.insert('0', "5000");
  EXPECT_EQ(tree_db_it.size(), 9);
  EXPECT_EQ(tree_db_it_2.size(), 8);
  EXPECT_EQ(tree_ch_st.size(), 11);
  EXPECT_EQ(tree_ch_st_2.size(), 10);

  my_containers::Tree<double, int> tree__3;
  my_containers::Tree<double, int> tree__4;
  tree__3.copyTree(tree__4);
  EXPECT_EQ(tree__3.empty(), true);
  EXPECT_EQ(tree__4.empty(), true);

  EXPECT_EQ(tree_db_it.contains(1000), true);
  EXPECT_EQ(tree_db_it.contains(55.555), false);
  EXPECT_EQ(tree_db_it.containsVal(15), true);
  EXPECT_EQ(tree_db_it.containsVal(-22222), false);
}
TEST(TreeTest, GetTree_SS) {
  my_containers::Tree<int, int> tree_int{
      10, 2, 3, 44, 5, 66, -5, -100, 0, 0, 0, 5, 33, 23, 64, 55, 0, 1, 1000};
  my_containers::Tree<double, double> tree_double{
      555.55, 423.2, 2, 1000, -55.55, -33.3, -1000, 100, 1000, 100, -5.5};
  my_containers::Tree<std::string, std::string> tree_str{
      "Jazz",     "I",    "played", "with", "Blues",
      "brothers", "like", "Yoda",   "Wow",  "!"};
  my_containers::Tree<char, char> tree_char{'a',  'b', 'c', 'd', '5', '1',
                                            'a',  '-', '=', '+', 'q', '\n',
                                            '\t', 'y', ']', '[', '(', '`'};
  EXPECT_EQ(tree_int.size(), 15);
  EXPECT_EQ(tree_double.size(), 9);
  EXPECT_EQ(tree_str.size(), 10);
  EXPECT_EQ(tree_char.size(), 17);

  my_containers::Stack<int> stack_int;
  my_containers::Stack<double> stack_double;
  my_containers::Stack<std::string> stack_str;
  my_containers::Stack<char> stack_char;

  tree_int.getTree(stack_int);
  tree_double.getTree(stack_double);
  tree_str.getTree(stack_str);
  tree_char.getTree(stack_char);
  EXPECT_EQ(stack_int.size(), 15);
  EXPECT_EQ(stack_double.size(), 9);
  EXPECT_EQ(stack_str.size(), 10);
  EXPECT_EQ(stack_char.size(), 17);

  my_containers::Stack<int> stack_int_2;
  my_containers::Stack<double> stack_double_2;
  my_containers::Stack<std::string> stack_str_2;
  my_containers::Stack<char> stack_char_2;
  stack_int_2 = tree_int.getTree(stack_int_2);
  stack_double_2 = tree_double.getTree(stack_double_2);
  stack_str_2 = tree_str.getTree(stack_str_2);
  stack_char_2 = tree_char.getTree(stack_char_2);
  EXPECT_EQ(stack_int_2.size(), 15);
  EXPECT_EQ(stack_double_2.size(), 9);
  EXPECT_EQ(stack_str_2.size(), 10);
  EXPECT_EQ(stack_char_2.size(), 17);

  my_containers::Stack<int> stack_int_3;
  my_containers::Stack<double> stack_double_3;
  my_containers::Stack<std::string> stack_str_3;
  my_containers::Stack<char> stack_char_3;
  my_containers::Stack<int> stack_int_4;
  my_containers::Stack<double> stack_double_4;
  my_containers::Stack<std::string> stack_str_4;
  my_containers::Stack<char> stack_char_4;

  stack_int_3 = tree_int.getTree(stack_int_4);
  stack_double_3 = tree_double.getTree(stack_double_4);
  stack_str_3 = tree_str.getTree(stack_str_4);
  stack_char_3 = tree_char.getTree(stack_char_4);
  EXPECT_EQ(stack_int_3.size(), 15);
  EXPECT_EQ(stack_double_3.size(), 9);
  EXPECT_EQ(stack_str_3.size(), 10);
  EXPECT_EQ(stack_char_3.size(), 17);
  EXPECT_EQ(stack_int_4.size(), 15);
  EXPECT_EQ(stack_double_4.size(), 9);
  EXPECT_EQ(stack_str_4.size(), 10);
  EXPECT_EQ(stack_char_4.size(), 17);
}
TEST(TreeTest, GetTree_MS) {
  my_containers::Tree<double, int> tree_db_it{
      {555.55, 5}, {423.2, 2},   {1000, 0},     {-55.55, 6000},
      {-33.3, -5}, {-1000, 100}, {100100, 100}, {-5.5, 15}};
  my_containers::Tree<char, std::string> tree_ch_st{
      std::pair<char, std::string>{'5', "Jazz"},
      {'\n', "I"},
      {'y', "played"},
      {'(', "with"},
      {'`', "Blues"},
      {'-', "brothers"},
      {'=', "like"},
      {'b', "Yoda"},
      {'d', "Wow"},
      {'c', "!"}};
  EXPECT_EQ(tree_db_it.size(), 8);
  EXPECT_EQ(tree_ch_st.size(), 10);
  std::pair<my_containers::Stack<double>, my_containers::Stack<int>>
      stack_db_it;
  std::pair<my_containers::Stack<char>, my_containers::Stack<std::string>>
      stack_ch_st;

  tree_db_it.getTree(stack_db_it);
  tree_ch_st.getTree(stack_ch_st);
  EXPECT_EQ(stack_db_it.first.size(), 8);
  EXPECT_EQ(stack_db_it.second.size(), 8);
  EXPECT_EQ(stack_ch_st.first.size(), 10);
  EXPECT_EQ(stack_ch_st.second.size(), 10);

  std::pair<my_containers::Stack<double>, my_containers::Stack<int>>
      stack_db_it_2;
  std::pair<my_containers::Stack<char>, my_containers::Stack<std::string>>
      stack_ch_st_2;

  stack_db_it_2 = tree_db_it.getTree(stack_db_it_2);
  stack_ch_st_2 = tree_ch_st.getTree(stack_ch_st_2);
  EXPECT_EQ(stack_db_it_2.first.size(), 8);
  EXPECT_EQ(stack_db_it_2.second.size(), 8);
  EXPECT_EQ(stack_ch_st_2.first.size(), 10);
  EXPECT_EQ(stack_ch_st_2.second.size(), 10);

  std::pair<my_containers::Stack<double>, my_containers::Stack<int>>
      stack_db_it_3;
  std::pair<my_containers::Stack<char>, my_containers::Stack<std::string>>
      stack_ch_st_3;
  std::pair<my_containers::Stack<double>, my_containers::Stack<int>>
      stack_db_it_4;
  std::pair<my_containers::Stack<char>, my_containers::Stack<std::string>>
      stack_ch_st_4;

  stack_db_it_3 = tree_db_it.getTree(stack_db_it_4);
  stack_ch_st_3 = tree_ch_st.getTree(stack_ch_st_4);
  EXPECT_EQ(stack_db_it_3.first.size(), 8);
  EXPECT_EQ(stack_db_it_3.second.size(), 8);
  EXPECT_EQ(stack_ch_st_3.first.size(), 10);
  EXPECT_EQ(stack_ch_st_3.second.size(), 10);
  EXPECT_EQ(stack_db_it_4.first.size(), 8);
  EXPECT_EQ(stack_db_it_4.second.size(), 8);
  EXPECT_EQ(stack_ch_st_4.first.size(), 10);
  EXPECT_EQ(stack_ch_st_4.second.size(), 10);
}
TEST(TreeTest, MoveAssignment_SS) {
  my_containers::Tree<int, int> tree_int{
      10, 2, 3, 44, 5, 66, -5, -100, 0, 0, 0, 5, 33, 23, 64, 55, 0, 1, 1000};
  my_containers::Tree<double, double> tree_double{
      555.55, 423.2, 2, 1000, -55.55, -33.3, -1000, 100, 1000, 100, -5.5};
  my_containers::Tree<std::string, std::string> tree_str{
      "Jazz",     "I",    "played", "with", "Blues",
      "brothers", "like", "Yoda",   "Wow",  "!"};
  my_containers::Tree<char, char> tree_char{'a',  'b', 'c', 'd', '5', '1',
                                            'a',  '-', '=', '+', 'q', '\n',
                                            '\t', 'y', ']', '[', '(', '`'};
  EXPECT_EQ(tree_int.size(), 15);
  EXPECT_EQ(tree_double.size(), 9);
  EXPECT_EQ(tree_str.size(), 10);
  EXPECT_EQ(tree_char.size(), 17);

  my_containers::Tree<int, int> tree_int_2 = std::move(tree_int);
  my_containers::Tree<double, double> tree_double_2 = std::move(tree_double);
  my_containers::Tree<std::string, std::string> tree_str_2 =
      std::move(tree_str);
  my_containers::Tree<char, char> tree_char_2 = std::move(tree_char);
  EXPECT_EQ(tree_int_2.size(), 15);
  EXPECT_EQ(tree_double_2.size(), 9);
  EXPECT_EQ(tree_str_2.size(), 10);
  EXPECT_EQ(tree_char_2.size(), 17);
  EXPECT_EQ(tree_int.size(), 0);
  EXPECT_EQ(tree_double.size(), 0);
  EXPECT_EQ(tree_str.size(), 0);
  EXPECT_EQ(tree_char.size(), 0);

  my_containers::Tree<int, int> tree_int_3;
  my_containers::Tree<double, double> tree_double_3;
  my_containers::Tree<std::string, std::string> tree_str_3;
  my_containers::Tree<char, char> tree_char_3;
  my_containers::Tree<int, int> tree_int_4 = std::move(tree_int_3);
  my_containers::Tree<double, double> tree_double_4 = std::move(tree_double_3);
  my_containers::Tree<std::string, std::string> tree_str_4 =
      std::move(tree_str_3);
  my_containers::Tree<char, char> tree_char_4 = std::move(tree_char_3);
  EXPECT_EQ(tree_int_4.empty(), true);
  EXPECT_EQ(tree_double_4.empty(), true);
  EXPECT_EQ(tree_str_4.empty(), true);
  EXPECT_EQ(tree_char_4.empty(), true);
  EXPECT_EQ(tree_int_3.empty(), true);
  EXPECT_EQ(tree_double_3.empty(), true);
  EXPECT_EQ(tree_str_3.empty(), true);
  EXPECT_EQ(tree_char_3.empty(), true);
}
TEST(TreeTest, MoveAssignment_MS) {
  my_containers::Tree<double, int> tree_db_it{
      {555.55, 5}, {423.2, 2},   {1000, 0},     {-55.55, 6000},
      {-33.3, -5}, {-1000, 100}, {100100, 100}, {-5.5, 15}};
  my_containers::Tree<char, std::string> tree_ch_st{
      std::pair<char, std::string>{'5', "Jazz"},
      {'\n', "I"},
      {'y', "played"},
      {'(', "with"},
      {'`', "Blues"},
      {'-', "brothers"},
      {'=', "like"},
      {'b', "Yoda"},
      {'d', "Wow"},
      {'c', "!"}};
  EXPECT_EQ(tree_db_it.size(), 8);
  EXPECT_EQ(tree_ch_st.size(), 10);

  my_containers::Tree<double, int> tree_db_it_2 = std::move(tree_db_it);
  my_containers::Tree<char, std::string> tree_ch_st_2 = std::move(tree_ch_st);
  EXPECT_EQ(tree_db_it_2.size(), 8);
  EXPECT_EQ(tree_ch_st_2.size(), 10);
  EXPECT_EQ(tree_db_it.size(), 0);
  EXPECT_EQ(tree_ch_st.size(), 0);

  my_containers::Tree<double, int> tree_db_it_3;
  my_containers::Tree<char, std::string> tree_ch_st_3;
  my_containers::Tree<double, int> tree_db_it_4 = std::move(tree_db_it_3);
  my_containers::Tree<char, std::string> tree_ch_st_4 = std::move(tree_ch_st_3);
  EXPECT_EQ(tree_db_it_3.empty(), true);
  EXPECT_EQ(tree_ch_st_3.empty(), true);
  EXPECT_EQ(tree_db_it_4.empty(), true);
  EXPECT_EQ(tree_ch_st_4.empty(), true);
}
TEST(TreeTest, Contains_SS) {
  my_containers::Tree<int, int> tree_int{
      10, 2, 3, 44, 5, 66, -5, -100, 0, 0, 0, 5, 33, 23, 64, 55, 0, 1, 1000};
  my_containers::Tree<double, double> tree_double{
      555.55, 423.2, 2, 1000, -55.55, -33.3, -1000, 100, 1000, 100, -5.5};
  my_containers::Tree<std::string, std::string> tree_str{
      "Jazz",     "I",    "played", "with", "Blues",
      "brothers", "like", "Yoda",   "Wow",  "!"};
  my_containers::Tree<char, char> tree_char{'a',  'b', 'c', 'd', '5', '1',
                                            'a',  '-', '=', '+', 'q', '\n',
                                            '\t', 'y', ']', '[', '(', '`'};
  EXPECT_EQ(tree_int.size(), 15);
  EXPECT_EQ(tree_double.size(), 9);
  EXPECT_EQ(tree_str.size(), 10);
  EXPECT_EQ(tree_char.size(), 17);

  EXPECT_EQ(tree_int.contains(-100), true);
  EXPECT_EQ(tree_int.contains(1000), true);
  EXPECT_EQ(tree_int.contains(0), true);
  EXPECT_EQ(tree_int.contains(-555), false);
  EXPECT_EQ(tree_double.contains(1000), true);
  EXPECT_EQ(tree_double.contains(-1000), true);
  EXPECT_EQ(tree_double.contains(-5000.5), false);
  EXPECT_EQ(tree_str.contains("Wow"), true);
  EXPECT_EQ(tree_str.contains("Blues"), true);
  EXPECT_EQ(tree_str.contains("wow"), false);
  EXPECT_EQ(tree_char.contains('a'), true);
  EXPECT_EQ(tree_char.contains('5'), true);
  EXPECT_EQ(tree_char.contains('z'), false);
}
TEST(TreeTest, Contains_MS) {
  my_containers::Tree<double, int> tree_db_it{
      {555.55, 5}, {423.2, 2},   {1000, 0},     {-55.55, 6000},
      {-33.3, -5}, {-1000, 100}, {100100, 100}, {-5.5, 15}};
  my_containers::Tree<char, std::string> tree_ch_st{
      std::pair<char, std::string>{'5', "Jazz"},
      {'\n', "I"},
      {'y', "played"},
      {'(', "with"},
      {'`', "Blues"},
      {'-', "brothers"},
      {'=', "like"},
      {'b', "Yoda"},
      {'d', "Wow"},
      {'c', "!"}};
  EXPECT_EQ(tree_db_it.size(), 8);
  EXPECT_EQ(tree_ch_st.size(), 10);

  EXPECT_EQ(tree_db_it.containsVal(-5), true);
  EXPECT_EQ(tree_db_it.containsVal(100), true);
  EXPECT_EQ(tree_db_it.containsVal(0), true);
  EXPECT_EQ(tree_db_it.containsVal(-555), false);
  EXPECT_EQ(tree_db_it.containsVal(6000), true);
  EXPECT_EQ(tree_db_it.containsVal(5), true);
  EXPECT_EQ(tree_db_it.containsVal(-5000.5), false);
  EXPECT_EQ(tree_ch_st.containsVal("Wow"), true);
  EXPECT_EQ(tree_ch_st.containsVal("Blues"), true);
  EXPECT_EQ(tree_ch_st.containsVal("wow"), false);
}
TEST(TreeTest, Swap_SS) {
  my_containers::Tree<int, int> tree_int{
      10, 2, 3, 44, 5, 66, -5, -100, 0, 0, 0, 5, 33, 23, 64, 55, 0, 1, 1000};
  my_containers::Tree<double, double> tree_double{
      555.55, 423.2, 2, 1000, -55.55, -33.3, -1000, 100, 1000, 100, -5.5};
  my_containers::Tree<std::string, std::string> tree_str{
      "Jazz",     "I",    "played", "with", "Blues",
      "brothers", "like", "Yoda",   "Wow",  "!"};
  my_containers::Tree<char, char> tree_char{'a',  'b', 'c', 'd', '5', '1',
                                            'a',  '-', '=', '+', 'q', '\n',
                                            '\t', 'y', ']', '[', '(', '`'};
  EXPECT_EQ(tree_int.size(), 15);
  EXPECT_EQ(tree_double.size(), 9);
  EXPECT_EQ(tree_str.size(), 10);
  EXPECT_EQ(tree_char.size(), 17);

  my_containers::Tree<int, int> tree_int_2{10, 2, 3, 44, 5, 66, -5};
  my_containers::Tree<double, double> tree_double_2{555.55, 42,  100,
                                                    1000,   100, -5.5};
  my_containers::Tree<std::string, std::string> tree_str_2{
      "Jazz", "I", "played", "with", "Yoda"};
  my_containers::Tree<char, char> tree_char_2{'a', 'b', ']', '[', '(', '`'};
  EXPECT_EQ(tree_int_2.size(), 7);
  EXPECT_EQ(tree_double_2.size(), 5);
  EXPECT_EQ(tree_str_2.size(), 5);
  EXPECT_EQ(tree_char_2.size(), 6);

  tree_int.swap(tree_int_2);
  tree_double.swap(tree_double_2);
  tree_str.swap(tree_str_2);
  tree_char.swap(tree_char_2);

  EXPECT_EQ(tree_int.size(), 7);
  EXPECT_EQ(tree_double.size(), 5);
  EXPECT_EQ(tree_str.size(), 5);
  EXPECT_EQ(tree_char.size(), 6);
  EXPECT_EQ(tree_int_2.size(), 15);
  EXPECT_EQ(tree_double_2.size(), 9);
  EXPECT_EQ(tree_str_2.size(), 10);
  EXPECT_EQ(tree_char_2.size(), 17);
}
TEST(TreeTest, Swap_MS) {
  my_containers::Tree<double, int> tree_db_it{
      {555.55, 5}, {423.2, 2},   {1000, 0},     {-55.55, 6000},
      {-33.3, -5}, {-1000, 100}, {100100, 100}, {-5.5, 15}};
  my_containers::Tree<char, std::string> tree_ch_st{
      std::pair<char, std::string>{'5', "Jazz"},
      {'\n', "I"},
      {'y', "played"},
      {'(', "with"},
      {'`', "Blues"},
      {'-', "brothers"},
      {'=', "like"},
      {'b', "Yoda"},
      {'d', "Wow"},
      {'c', "!"}};
  EXPECT_EQ(tree_db_it.size(), 8);
  EXPECT_EQ(tree_ch_st.size(), 10);

  my_containers::Tree<double, int> tree_db_it_2{
      {555.55, 10}, {42, 3}, {100, 44}, {1000, 5}, {100, 66}, {-5.5, -5}};
  my_containers::Tree<char, std::string> tree_ch_st_2{
      {'a', "Jazz"}, {']', "I"}, {'(', "played"}, {'[', "with"}, {'b', "Yoda"}};
  EXPECT_EQ(tree_db_it_2.size(), 5);
  EXPECT_EQ(tree_ch_st_2.size(), 5);

  tree_db_it.swap(tree_db_it_2);
  tree_ch_st.swap(tree_ch_st_2);

  EXPECT_EQ(tree_db_it_2.size(), 8);
  EXPECT_EQ(tree_ch_st_2.size(), 10);
  EXPECT_EQ(tree_db_it.size(), 5);
  EXPECT_EQ(tree_ch_st.size(), 5);
}
TEST(TreeTest, CopyAssignment_SS) {
  my_containers::Tree<int, int> tree_int{
      10, 2, 3, 44, 5, 66, -5, -100, 0, 0, 0, 5, 33, 23, 64, 55, 0, 1, 1000};
  my_containers::Tree<double, double> tree_double{
      555.55, 423.2, 2, 1000, -55.55, -33.3, -1000, 100, 1000, 100, -5.5};
  my_containers::Tree<std::string, std::string> tree_str{
      "Jazz",     "I",    "played", "with", "Blues",
      "brothers", "like", "Yoda",   "Wow",  "!"};
  my_containers::Tree<char, char> tree_char{'a',  'b', 'c', 'd', '5', '1',
                                            'a',  '-', '=', '+', 'q', '\n',
                                            '\t', 'y', ']', '[', '(', '`'};
  EXPECT_EQ(tree_int.size(), 15);
  EXPECT_EQ(tree_double.size(), 9);
  EXPECT_EQ(tree_str.size(), 10);
  EXPECT_EQ(tree_char.size(), 17);

  my_containers::Tree<int, int> tree_int_2 = tree_int;
  my_containers::Tree<double, double> tree_double_2 = tree_double;
  my_containers::Tree<std::string, std::string> tree_str_2 = tree_str;
  my_containers::Tree<char, char> tree_char_2 = tree_char;
  EXPECT_EQ(tree_int.size(), 15);
  EXPECT_EQ(tree_double.size(), 9);
  EXPECT_EQ(tree_str.size(), 10);
  EXPECT_EQ(tree_char.size(), 17);
  EXPECT_EQ(tree_int_2.size(), 15);
  EXPECT_EQ(tree_double_2.size(), 9);
  EXPECT_EQ(tree_str_2.size(), 10);
  EXPECT_EQ(tree_char_2.size(), 17);

  my_containers::Tree<int, int> tree_int_3;
  my_containers::Tree<double, double> tree_double_3;
  my_containers::Tree<std::string, std::string> tree_str_3;
  my_containers::Tree<char, char> tree_char_3;
  my_containers::Tree<int, int> tree_int_4 = tree_int_3;
  my_containers::Tree<double, double> tree_double_4 = tree_double_3;
  my_containers::Tree<std::string, std::string> tree_str_4 = tree_str_3;
  my_containers::Tree<char, char> tree_char_4 = tree_char_3;
  EXPECT_EQ(tree_int_4.empty(), true);
  EXPECT_EQ(tree_double_4.empty(), true);
  EXPECT_EQ(tree_str_4.empty(), true);
  EXPECT_EQ(tree_char_4.empty(), true);
  EXPECT_EQ(tree_int_3.empty(), true);
  EXPECT_EQ(tree_double_3.empty(), true);
  EXPECT_EQ(tree_str_3.empty(), true);
  EXPECT_EQ(tree_char_3.empty(), true);

  tree_int.insert(123456789);
  tree_double.insert(123456789.123456789);
  tree_str.insert("Anything");
  tree_char.insert('z');
  EXPECT_EQ(tree_int.size(), 16);
  EXPECT_EQ(tree_double.size(), 10);
  EXPECT_EQ(tree_str.size(), 11);
  EXPECT_EQ(tree_char.size(), 18);
  EXPECT_EQ(tree_int_2.size(), 15);
  EXPECT_EQ(tree_double_2.size(), 9);
  EXPECT_EQ(tree_str_2.size(), 10);
  EXPECT_EQ(tree_char_2.size(), 17);

  tree_int_4 = tree_int_2;
  tree_double_4 = tree_double_2;
  tree_str_4 = tree_str_2;
  tree_char_4 = tree_char_2;
  tree_int = tree_int_3;
  tree_double = tree_double_3;
  tree_str = tree_str_3;
  tree_char = tree_char_3;
  EXPECT_EQ(tree_int_4.size(), 15);
  EXPECT_EQ(tree_double_4.size(), 9);
  EXPECT_EQ(tree_str_4.size(), 10);
  EXPECT_EQ(tree_char_4.size(), 17);
  EXPECT_EQ(tree_int.empty(), true);
  EXPECT_EQ(tree_double.empty(), true);
  EXPECT_EQ(tree_str.empty(), true);
  EXPECT_EQ(tree_char.empty(), true);
}
TEST(TreeTest, CopyAssignment_MS) {
  my_containers::Tree<double, int> tree_db_it{
      {555.55, 5}, {423.2, 2},   {1000, 0},     {-55.55, 6000},
      {-33.3, -5}, {-1000, 100}, {100100, 100}, {-5.5, 15}};
  my_containers::Tree<char, std::string> tree_ch_st{
      std::pair<char, std::string>{'5', "Jazz"},
      {'\n', "I"},
      {'y', "played"},
      {'(', "with"},
      {'`', "Blues"},
      {'-', "brothers"},
      {'=', "like"},
      {'b', "Yoda"},
      {'d', "Wow"},
      {'c', "!"}};
  EXPECT_EQ(tree_db_it.size(), 8);
  EXPECT_EQ(tree_ch_st.size(), 10);

  my_containers::Tree<double, int> tree_db_it_2 = tree_db_it;
  my_containers::Tree<char, std::string> tree_ch_st_2 = tree_ch_st;
  EXPECT_EQ(tree_db_it.size(), 8);
  EXPECT_EQ(tree_ch_st.size(), 10);
  EXPECT_EQ(tree_db_it_2.size(), 8);
  EXPECT_EQ(tree_ch_st_2.size(), 10);
}
TEST(TreeTest, MoveConstructor_SS) {
  my_containers::Tree<int, int> tree_int{
      10, 2, 3, 44, 5, 66, -5, -100, 0, 0, 0, 5, 33, 23, 64, 55, 0, 1, 1000};
  my_containers::Tree<double, double> tree_double{
      555.55, 423.2, 2, 1000, -55.55, -33.3, -1000, 100, 1000, 100, -5.5};
  my_containers::Tree<std::string, std::string> tree_str{
      "Jazz",     "I",    "played", "with", "Blues",
      "brothers", "like", "Yoda",   "Wow",  "!"};
  my_containers::Tree<char, char> tree_char{'a',  'b', 'c', 'd', '5', '1',
                                            'a',  '-', '=', '+', 'q', '\n',
                                            '\t', 'y', ']', '[', '(', '`'};
  EXPECT_EQ(tree_int.size(), 15);
  EXPECT_EQ(tree_double.size(), 9);
  EXPECT_EQ(tree_str.size(), 10);
  EXPECT_EQ(tree_char.size(), 17);

  my_containers::Tree<int, int> tree_int_2(std::move(tree_int));
  my_containers::Tree<double, double> tree_double_2(std::move(tree_double));
  my_containers::Tree<std::string, std::string> tree_str_2(std::move(tree_str));
  my_containers::Tree<char, char> tree_char_2(std::move(tree_char));
  EXPECT_EQ(tree_int_2.size(), 15);
  EXPECT_EQ(tree_double_2.size(), 9);
  EXPECT_EQ(tree_str_2.size(), 10);
  EXPECT_EQ(tree_char_2.size(), 17);
  EXPECT_EQ(tree_int.size(), 0);
  EXPECT_EQ(tree_double.size(), 0);
  EXPECT_EQ(tree_str.size(), 0);
  EXPECT_EQ(tree_char.size(), 0);
}
TEST(TreeTest, MoveConstructor_MS) {
  my_containers::Tree<double, int> tree_db_it{
      {555.55, 5}, {423.2, 2},   {1000, 0},     {-55.55, 6000},
      {-33.3, -5}, {-1000, 100}, {100100, 100}, {-5.5, 15}};
  my_containers::Tree<char, std::string> tree_ch_st{
      std::pair<char, std::string>{'5', "Jazz"},
      {'\n', "I"},
      {'y', "played"},
      {'(', "with"},
      {'`', "Blues"},
      {'-', "brothers"},
      {'=', "like"},
      {'b', "Yoda"},
      {'d', "Wow"},
      {'c', "!"}};
  EXPECT_EQ(tree_db_it.size(), 8);
  EXPECT_EQ(tree_ch_st.size(), 10);

  my_containers::Tree<double, int> tree_db_it_2(std::move(tree_db_it));
  my_containers::Tree<char, std::string> tree_ch_st_2(std::move(tree_ch_st));
  EXPECT_EQ(tree_db_it_2.size(), 8);
  EXPECT_EQ(tree_ch_st_2.size(), 10);
  EXPECT_EQ(tree_db_it.size(), 0);
  EXPECT_EQ(tree_ch_st.size(), 0);
}
TEST(TreeTest, CopyConstructor_SS) {
  my_containers::Tree<int, int> tree_int{
      10, 2, 3, 44, 5, 66, -5, -100, 0, 0, 0, 5, 33, 23, 64, 55, 0, 1, 1000};
  my_containers::Tree<double, double> tree_double{
      555.55, 423.2, 2, 1000, -55.55, -33.3, -1000, 100, 1000, 100, -5.5};
  my_containers::Tree<std::string, std::string> tree_str{
      "Jazz",     "I",    "played", "with", "Blues",
      "brothers", "like", "Yoda",   "Wow",  "!"};
  my_containers::Tree<char, char> tree_char{'a',  'b', 'c', 'd', '5', '1',
                                            'a',  '-', '=', '+', 'q', '\n',
                                            '\t', 'y', ']', '[', '(', '`'};
  EXPECT_EQ(tree_int.size(), 15);
  EXPECT_EQ(tree_double.size(), 9);
  EXPECT_EQ(tree_str.size(), 10);
  EXPECT_EQ(tree_char.size(), 17);

  my_containers::Tree<int, int> tree_int_2(tree_int);
  my_containers::Tree<double, double> tree_double_2(tree_double);
  my_containers::Tree<std::string, std::string> tree_str_2(tree_str);
  my_containers::Tree<char, char> tree_char_2(tree_char);
  EXPECT_EQ(tree_int_2.size(), 15);
  EXPECT_EQ(tree_double_2.size(), 9);
  EXPECT_EQ(tree_str_2.size(), 10);
  EXPECT_EQ(tree_char_2.size(), 17);
  EXPECT_EQ(tree_int.size(), 15);
  EXPECT_EQ(tree_double.size(), 9);
  EXPECT_EQ(tree_str.size(), 10);
  EXPECT_EQ(tree_char.size(), 17);
}
TEST(TreeTest, CopyConstructor_MS) {
  my_containers::Tree<double, int> tree_db_it{
      {555.55, 5}, {423.2, 2},   {1000, 0},     {-55.55, 6000},
      {-33.3, -5}, {-1000, 100}, {100100, 100}, {-5.5, 15}};
  my_containers::Tree<char, std::string> tree_ch_st{
      std::pair<char, std::string>{'5', "Jazz"},
      {'\n', "I"},
      {'y', "played"},
      {'(', "with"},
      {'`', "Blues"},
      {'-', "brothers"},
      {'=', "like"},
      {'b', "Yoda"},
      {'d', "Wow"},
      {'c', "!"}};
  EXPECT_EQ(tree_db_it.size(), 8);
  EXPECT_EQ(tree_ch_st.size(), 10);

  my_containers::Tree<double, int> tree_db_it_2(tree_db_it);
  my_containers::Tree<char, std::string> tree_ch_st_2(tree_ch_st);
  EXPECT_EQ(tree_db_it_2.size(), 8);
  EXPECT_EQ(tree_ch_st_2.size(), 10);
  EXPECT_EQ(tree_db_it.size(), 8);
  EXPECT_EQ(tree_ch_st.size(), 10);
}
/*
// This thest is systrm dependent -- may cause errors
TEST(TreeTest, Max_size_SS_MS) {
    my_containers::Tree<int,int>
tree_int{10,2,3,44,5,66,-5,-100,0,0,0,5,33,23,64,55,0,1,1000};
    my_containers::Tree<double,double> tree_double{555.55,
423.2,2,1000,-55.55,-33.3,-1000,100,1000,100,-5.5};
    my_containers::Tree<std::string,std::string> tree_str{"Jazz", "I", "played",
"with", "Blues", "brothers", "like", "Yoda", "Wow", "!"};
my_containers::Tree<char,char> tree_char{'a', 'b', 'c',
'd','5','1','a','-','=','+','q','\n','\t','y',']','[','(','`'};
    my_containers::Tree<double,int> tree_db_it {{555.55,5},
{423.2,2},{1000,0},{-55.55,6000},{-33.3,-5},{-1000,100},{100100,100},{-5.5,15}};
    my_containers::Tree<char,std::string>
tree_ch_st{std::pair<char,std::string>{ '5',"Jazz"}, {'\n',"I"}, {'y',"played"},
{'(',"with"}, {'`',"Blues"},
{'-',"brothers"}, {'=',"like"}, {'b',"Yoda"}, {'d',"Wow"}, {'c',"!"}};

    my_containers::Tree<int,int> tree_int_2;
    my_containers::Tree<double,double> tree_double_2;
    my_containers::Tree<std::string,std::string> tree_str_2;
    my_containers::Tree<char,char> tree_char_2;
    my_containers::Tree<double,int> tree_db_it_2;
    my_containers::Tree<char,std::string> tree_ch_st_2;

    EXPECT_EQ(tree_int.max_size(),576460752303423487);
    EXPECT_EQ(tree_double.max_size(),461168601842738790);
    EXPECT_EQ(tree_str.max_size(),209622091746699450);
    EXPECT_EQ(tree_char.max_size(),576460752303423487);
    EXPECT_EQ(tree_int_2.max_size(),576460752303423487);
    EXPECT_EQ(tree_double_2.max_size(),461168601842738790);
    EXPECT_EQ(tree_str_2.max_size(),209622091746699450);
    EXPECT_EQ(tree_char_2.max_size(),576460752303423487);
    EXPECT_EQ(tree_db_it.max_size(),461168601842738790);
    EXPECT_EQ(tree_db_it_2.max_size(),461168601842738790);
    EXPECT_EQ(tree_ch_st.max_size(),288230376151711743);
    EXPECT_EQ(tree_ch_st_2.max_size(),288230376151711743);
}
*/
TEST(TreeTest, Remove_int_SS) {
  my_containers::Tree<int, int> tree_int{15, 4,  26, 5,  20, 0,   34, 10, 16,
                                         22, 3,  32, -5, 50, 8,   18, 12, 21,
                                         1,  28, 33, -2, 43, -10, 100};
  EXPECT_EQ(tree_int.size(), 25);
  // tree_int.showTreeVertical();
  EXPECT_EQ(tree_int.contains(-10), true);
  tree_int.remove(-10);
  EXPECT_EQ(tree_int.size(), 24);
  EXPECT_EQ(tree_int.contains(-10), false);
  // tree_int.showTreeVertical();
  EXPECT_EQ(tree_int.contains(16), true);
  tree_int.remove(16);
  EXPECT_EQ(tree_int.size(), 23);
  EXPECT_EQ(tree_int.contains(16), false);
  EXPECT_EQ(tree_int.contains(22), true);
  tree_int.remove(22);
  EXPECT_EQ(tree_int.size(), 22);
  EXPECT_EQ(tree_int.contains(22), false);
  EXPECT_EQ(tree_int.contains(50), true);
  tree_int.remove(50);
  EXPECT_EQ(tree_int.size(), 21);
  EXPECT_EQ(tree_int.contains(50), false);
  EXPECT_EQ(tree_int.contains(26), true);
  tree_int.remove(26);
  EXPECT_EQ(tree_int.size(), 20);
  EXPECT_EQ(tree_int.contains(26), false);
  EXPECT_EQ(tree_int.contains(28), true);
  tree_int.remove(28);
  EXPECT_EQ(tree_int.size(), 19);
  EXPECT_EQ(tree_int.contains(28), false);
  EXPECT_EQ(tree_int.contains(4), true);
  tree_int.remove(4);
  EXPECT_EQ(tree_int.size(), 18);
  EXPECT_EQ(tree_int.contains(4), false);
  EXPECT_EQ(tree_int.contains(400), false);
  tree_int.remove(400);
  EXPECT_EQ(tree_int.size(), 18);
  EXPECT_EQ(tree_int.contains(400), false);
  EXPECT_EQ(tree_int.contains(15), true);
  tree_int.remove(15);
  EXPECT_EQ(tree_int.size(), 17);
  EXPECT_EQ(tree_int.contains(15), false);
  tree_int.remove(10);
  tree_int.remove(8);
  tree_int.remove(12);
  tree_int.remove(3);
  tree_int.remove(1);
  EXPECT_EQ(tree_int.size(), 12);
  EXPECT_EQ(tree_int.contains(10), false);
  EXPECT_EQ(tree_int.contains(8), false);
  EXPECT_EQ(tree_int.contains(12), false);
  EXPECT_EQ(tree_int.contains(3), false);
  EXPECT_EQ(tree_int.contains(1), false);
  tree_int.remove(-2);
  tree_int.remove(-5);
  tree_int.remove(0);
  EXPECT_EQ(tree_int.size(), 9);
  EXPECT_EQ(tree_int.contains(-2), false);
  EXPECT_EQ(tree_int.contains(-5), false);
  EXPECT_EQ(tree_int.contains(0), false);
  // tree_int.showTreeVertical();
}
TEST(TreeTest, Remove_double_int_MS) {
  my_containers::Tree<double, int> tree_db_it{
      {555.55, 5}, {423.2, 2},   {1000, 0},     {-55.55, 6000},
      {-33.3, -5}, {-1000, 100}, {100100, 100}, {-5.5, 15}};
  EXPECT_EQ(tree_db_it.size(), 8);
  EXPECT_EQ(tree_db_it.contains(423.2), true);
  tree_db_it.remove(423.2);
  EXPECT_EQ(tree_db_it.size(), 7);
  EXPECT_EQ(tree_db_it.contains(423.2), false);
  EXPECT_EQ(tree_db_it.contains(1000), true);
  tree_db_it.remove(1000);
  EXPECT_EQ(tree_db_it.size(), 6);
  EXPECT_EQ(tree_db_it.contains(1000), false);
  EXPECT_EQ(tree_db_it.contains(-1000), true);
  tree_db_it.remove(-1000);
  EXPECT_EQ(tree_db_it.size(), 5);
  EXPECT_EQ(tree_db_it.contains(-1000), false);
  tree_db_it.remove(555.55);
  tree_db_it.remove(100100);
  tree_db_it.remove(-5.5);
  tree_db_it.remove(-33.3);
  EXPECT_EQ(tree_db_it.size(), 1);
  EXPECT_EQ(tree_db_it.contains(555.55), false);
  EXPECT_EQ(tree_db_it.contains(100100), false);
  EXPECT_EQ(tree_db_it.contains(-5.5), false);
  EXPECT_EQ(tree_db_it.contains(-33.3), false);
  EXPECT_EQ(tree_db_it.contains(-55.55), true);
  tree_db_it.remove(-55.55);
  EXPECT_EQ(tree_db_it.size(), 0);
  EXPECT_EQ(tree_db_it.empty(), true);
  tree_db_it.remove(0);
  EXPECT_EQ(tree_db_it.size(), 0);
  EXPECT_EQ(tree_db_it.empty(), true);
  // tree_db_it.showTreeVertical();
}
TEST(TreeTest, Remove_double_SS) {
  my_containers::Tree<double, double> tree{
      15.15, 4.4,   26.26, 5.5,  20.20, 0,     34.34, 10.1,  16.16,
      22.22, 3.3,   32.32, -5.5, 50.50, 8.8,   18.18, 12.12, 21.21,
      1.1,   28.28, 33.33, -2.2, 43.43, -10.1, 100.1};
  EXPECT_EQ(tree.size(), 25);
  // tree.showTreeVertical();
  EXPECT_EQ(tree.contains(-10.1), true);
  tree.remove(-10.1);
  EXPECT_EQ(tree.size(), 24);
  EXPECT_EQ(tree.contains(-10.1), false);
  // tree.showTreeVertical();
  EXPECT_EQ(tree.contains(16.16), true);
  tree.remove(16.16);
  EXPECT_EQ(tree.size(), 23);
  EXPECT_EQ(tree.contains(16.16), false);
  EXPECT_EQ(tree.contains(22.22), true);
  tree.remove(22.22);
  EXPECT_EQ(tree.size(), 22);
  EXPECT_EQ(tree.contains(22.22), false);
  EXPECT_EQ(tree.contains(50.5), true);
  tree.remove(50.5);
  EXPECT_EQ(tree.size(), 21);
  EXPECT_EQ(tree.contains(50.5), false);
  tree.remove(10.1);
  tree.remove(8.8);
  tree.remove(12.12);
  tree.remove(3.3);
  tree.remove(1.1);
  EXPECT_EQ(tree.size(), 16);
  EXPECT_EQ(tree.contains(10.1), false);
  EXPECT_EQ(tree.contains(8.8), false);
  EXPECT_EQ(tree.contains(12.12), false);
  EXPECT_EQ(tree.contains(3.3), false);
  EXPECT_EQ(tree.contains(1.1), false);
  tree.remove(-2.2);
  tree.remove(-5.5);
  tree.remove(0);
  tree.remove(0);
  tree.remove(0);
  tree.remove(0);
  tree.remove(15.15);
  EXPECT_EQ(tree.size(), 12);
  EXPECT_EQ(tree.contains(-2.2), false);
  EXPECT_EQ(tree.contains(-5.5), false);
  EXPECT_EQ(tree.contains(0), false);
  EXPECT_EQ(tree.contains(15), false);
  // tree.showTreeVertical();
}
TEST(TreeTest, Remove_string) {
  my_containers::Tree<std::string, std::string> tree{
      "What's", "up", "Vsauce", "Michael", "Here", "!"};
  EXPECT_EQ(tree.size(), 6);
  EXPECT_EQ(tree.contains("up"), true);
  tree.remove("up");
  EXPECT_EQ(tree.size(), 5);
  EXPECT_EQ(tree.contains("up"), false);
  EXPECT_EQ(tree.contains("Vsauce"), true);
  tree.remove("Vsauce");
  EXPECT_EQ(tree.size(), 4);
  EXPECT_EQ(tree.contains("Vsauce"), false);
  EXPECT_EQ(tree.contains("Here"), true);
  tree.remove("Here");
  EXPECT_EQ(tree.size(), 3);
  EXPECT_EQ(tree.contains("Here"), false);
  EXPECT_EQ(tree.contains("!"), true);
  tree.remove("!");
  EXPECT_EQ(tree.size(), 2);
  EXPECT_EQ(tree.contains("!"), false);
  tree.insert("?");
  EXPECT_EQ(tree.size(), 3);
}
TEST(TreeTest, Remove_char_SS) {
  my_containers::Tree<char, char> tree{'g', '\0', '4', 'a', '\t', '0', 'f',
                                       'v', 'b',  'n', 'j', 'h',  't', 'e'};
  EXPECT_EQ(tree.size(), 14);
  EXPECT_EQ(tree.contains('4'), true);
  tree.remove('4');
  EXPECT_EQ(tree.size(), 13);
  EXPECT_EQ(tree.contains('4'), false);
  EXPECT_EQ(tree.contains('1'), false);
  tree.remove('1');
  EXPECT_EQ(tree.size(), 13);
  EXPECT_EQ(tree.contains('1'), false);
  EXPECT_EQ(tree.contains('\0'), true);
  tree.remove('\0');
  tree.remove('\t');
  EXPECT_EQ(tree.size(), 11);
  EXPECT_EQ(tree.contains('\0'), false);
  EXPECT_EQ(tree.contains('f'), true);
  tree.remove('f');
  tree.remove('v');
  tree.remove('b');
  tree.remove('n');
  EXPECT_EQ(tree.size(), 7);
  EXPECT_EQ(tree.contains('f'), false);
  EXPECT_EQ(tree.contains('v'), false);
  EXPECT_EQ(tree.contains('b'), false);
  EXPECT_EQ(tree.contains('n'), false);
}
TEST(TreeTest, Remove_string_char_MS) {
  my_containers::Tree<std::string, char> tree{
      std::pair<std::string, char>{"Jazz", '5'},
      {"I", '\n'},
      {"played", 'y'},
      {"with", '('},
      {"brothers", '-'}};
  EXPECT_EQ(tree.size(), 5);
  std::string str = "up";
  EXPECT_EQ(tree.contains(str), false);
  tree.remove(str);
  EXPECT_EQ(tree.size(), 5);
  str = "Jazz";
  EXPECT_EQ(tree.contains(str), true);
  tree.remove(str);
  EXPECT_EQ(tree.size(), 4);
  EXPECT_EQ(tree.contains(str), false);
  EXPECT_EQ(tree.contains("played"), true);
  tree.remove("played");
  EXPECT_EQ(tree.size(), 3);
  EXPECT_EQ(tree.contains("played"), false);
  EXPECT_EQ(tree.contains("I"), true);
  tree.remove("I");
  EXPECT_EQ(tree.size(), 2);
  EXPECT_EQ(tree.contains("I"), false);
  EXPECT_EQ(tree.contains("with"), true);
  tree.remove("with");
  tree.remove("with");
  EXPECT_EQ(tree.size(), 1);
  EXPECT_EQ(tree.contains("with"), false);
  EXPECT_EQ(tree.contains("brothers"), true);
  tree.remove("brothers");
  EXPECT_EQ(tree.size(), 0);
  EXPECT_EQ(tree.empty(), true);
  EXPECT_EQ(tree.contains("brothers"), false);
}
TEST(TreeTest, Parent_SS) {
  my_containers::Tree<int, int> tree_int{15, 4,  26, 5,  20, 0,   34, 10, 16,
                                         22, 3,  32, -5, 50, 8,   18, 12, 21,
                                         1,  28, 33, -2, 43, -10, 100};
  EXPECT_EQ(tree_int.size(), 25);
  EXPECT_THROW(tree_int.getParentData(15), std::out_of_range);
  EXPECT_EQ(tree_int.getParentData(26), 15);
  EXPECT_EQ(tree_int.getParentData(4), 15);
  EXPECT_EQ(tree_int.getParentData(5), 8);
  EXPECT_EQ(tree_int.getParentData(20), 26);
  EXPECT_EQ(tree_int.getParentData(0), 4);
  EXPECT_EQ(tree_int.getParentData(100), 50);
  EXPECT_EQ(tree_int.getParentData(33), 32);
  EXPECT_EQ(tree_int.getParentData(28), 32);
  EXPECT_EQ(tree_int.getParentData(10), 8);
  EXPECT_EQ(tree_int.getParentData(-2), -5);
  // tree_int.crazyPrinter();
  EXPECT_EQ(tree_int.getParentData(21), 22);
  EXPECT_EQ(tree_int.contains(32), true);
  tree_int.remove(32);
  EXPECT_EQ(tree_int.contains(32), false);
  EXPECT_EQ(tree_int.getParentData(28), 33);
  EXPECT_EQ(tree_int.contains(26), true);
  tree_int.remove(26);
  EXPECT_EQ(tree_int.contains(26), false);
  EXPECT_EQ(tree_int.getParentData(20), 28);
  tree_int.remove(10);
  tree_int.remove(8);
  tree_int.remove(12);
  tree_int.remove(3);
  tree_int.remove(34);
  tree_int.remove(20);
  tree_int.remove(2);
  tree_int.remove(-10);
  // tree_int.crazyPrinter();
  EXPECT_EQ(tree_int.getParentData(28), 15);
  EXPECT_EQ(tree_int.getParentData(22), 21);
  EXPECT_EQ(tree_int.getParentData(16), 21);
  EXPECT_EQ(tree_int.getParentData(1), 4);
  EXPECT_THROW(tree_int.getParentData(-1000), std::out_of_range);
  EXPECT_EQ(tree_int.getParentData(-2), -5);
  EXPECT_EQ(tree_int.getParentData(22), 21);
  EXPECT_EQ(tree_int.getParentData(50), 43);
}
TEST(TreeTest, Parent_MS) {
  my_containers::Tree<char, std::string> tree_ch_st{
      std::pair<char, std::string>{'5', "Jazz"},
      {'\n', "I"},
      {'y', "played"},
      {'(', "with"},
      {'`', "Blues"},
      {'-', "brothers"},
      {'=', "like"},
      {'b', "Yoda"},
      {'d', "Wow"},
      {'c', "!"}};
  EXPECT_EQ(tree_ch_st.size(), 10);
  EXPECT_THROW(tree_ch_st.getParentData('5'), std::out_of_range);
  EXPECT_EQ(tree_ch_st.getParentData('y'), 'd');
  EXPECT_EQ(tree_ch_st.getParentData('`'), 'b');
  EXPECT_EQ(tree_ch_st.getParentData('\n'), '(');
  // tree_ch_st.crazyPrinter();
}
TEST(TreeTest, Begin_End_SS) {
  my_containers::Tree<int, int> tree_int{15, 4,  26, 5,  20, 0,   34, 10, 16,
                                         22, 3,  32, -5, 50, 8,   18, 12, 21,
                                         1,  28, 33, -2, 43, -10, 100};
  EXPECT_EQ(tree_int.size(), 25);
  my_containers::Tree<double, double> tree_double{
      15.15, 4.4,   26.26, 5.5,  20.20, 0,     34.34, 10.1,  16.16,
      22.22, 3.3,   32.32, -5.5, 50.50, 8.8,   18.18, 12.12, 21.21,
      1.1,   28.28, 33.33, -2.2, 43.43, -10.1, 100.1};
  EXPECT_EQ(tree_double.size(), 25);
  my_containers::Tree<std::string, std::string> tree_string{
      "What's", "up", "Vsauce", "Michael", "here", "!"};
  EXPECT_EQ(tree_string.size(), 6);
  my_containers::Tree<char, char> tree_char{
      'g', '\0', '4', 'a', '\t', '0', 'f', 'v', 'b', 'n', 'j', 'h', 't', 'e'};
  EXPECT_EQ(tree_char.size(), 14);

  EXPECT_EQ(*(tree_int.begin()), -10);
  EXPECT_EQ(*(tree_int.end()), 100);
  EXPECT_EQ(*(tree_double.begin()), -10.1);
  EXPECT_EQ(*(tree_double.end()), 100.1);
  EXPECT_EQ(*(tree_string.begin()), "!");
  EXPECT_EQ(*(tree_string.end()), "up");
  EXPECT_EQ(*(tree_char.begin()), '\0');
  EXPECT_EQ(*(tree_char.end()), 'v');

  tree_int.remove(-10);
  tree_int.remove(-5);
  tree_int.remove(-2);
  tree_int.remove(0);
  tree_int.remove(3);
  tree_int.remove(5);
  tree_int.remove(8);
  tree_int.remove(50);
  tree_int.remove(43);
  tree_int.remove(33);
  tree_int.remove(34);
  tree_int.remove(32);
  tree_int.remove(28);
  tree_int.remove(22);
  tree_int.remove(26);
  tree_int.remove(100);
  tree_double.remove(-10.1);
  tree_double.remove(100.1);
  tree_string.remove("!");
  tree_string.remove("up");
  tree_string.remove("here");
  tree_string.remove("Michael");
  tree_string.remove("What's");
  tree_char.remove('\0');
  tree_char.remove('v');
  tree_char.remove('n');
  tree_char.remove('j');
  tree_char.remove('h');
  tree_char.remove('t');

  EXPECT_EQ(*(tree_int.begin()), 1);
  EXPECT_EQ(*(tree_int.end()), 21);
  EXPECT_EQ(*(tree_double.begin()), -5.5);
  EXPECT_EQ(*(tree_double.end()), 50.5);
  EXPECT_EQ(*(tree_string.begin()), "Vsauce");
  EXPECT_EQ(*(tree_string.end()), "Vsauce");
  EXPECT_EQ(*(tree_char.begin()), '\t');
  EXPECT_EQ(*(tree_char.end()), 'g');

  tree_string.remove("Vsauce");
  EXPECT_THROW(*(tree_string.begin()), std::out_of_range);
}
TEST(TreeTest, Begin_End_MS) {
  my_containers::Tree<double, int> tree_db_it{
      {555.55, 5}, {423.2, 2},   {1000, 0},     {-55.55, 6000},
      {-33.3, -5}, {-1000, 100}, {100100, 100}, {-5.5, 15}};
  my_containers::Tree<char, std::string> tree_ch_st{
      std::pair<char, std::string>{'5', "Jazz"},
      {'\n', "I"},
      {'y', "played"},
      {'(', "with"},
      {'`', "Blues"},
      {'-', "brothers"},
      {'=', "like"},
      {'b', "Yoda"},
      {'d', "Wow"},
      {'c', "!"}};
  EXPECT_EQ(tree_db_it.size(), 8);
  EXPECT_EQ(tree_ch_st.size(), 10);
  EXPECT_EQ(*(tree_db_it.begin()), 100);
  EXPECT_EQ(*(tree_db_it.end()), 100);
  EXPECT_EQ(*(tree_ch_st.begin()), "I");
  EXPECT_EQ(*(tree_ch_st.end()), "played");
}
TEST(TreeTest, Iterator) {
  my_containers::Tree<int, int> tree_int{15, 4,  26, 5,  20, 0,   34, 10, 16,
                                         22, 3,  32, -5, 50, 8,   18, 12, 21,
                                         1,  28, 33, -2, 43, -10, 100};
  EXPECT_EQ(tree_int.size(), 25);
  my_containers::Tree<double, double> tree_double{
      15.15, 4.4,   26.26, 5.5,  20.20, 0,     34.34, 10.1,  16.16,
      22.22, 3.3,   32.32, -5.5, 50.50, 8.8,   18.18, 12.12, 21.21,
      1.1,   28.28, 33.33, -2.2, 43.43, -10.1, 100.1};
  EXPECT_EQ(tree_double.size(), 25);
  my_containers::Tree<std::string, std::string> tree_string{
      "What's", "up", "Vsauce", "Michael", "here", "!"};
  EXPECT_EQ(tree_string.size(), 6);
  my_containers::Tree<char, char> tree_char{
      'g', '\0', '4', 'a', '\t', '0', 'f', 'v', 'b', 'n', 'j', 'h', 't', 'e'};
  EXPECT_EQ(tree_char.size(), 14);

  my_containers::Tree<int, int>::iterator it_int = tree_int.begin();
  my_containers::Tree<int, int>::constIterator cit_int(tree_int.end());
  EXPECT_EQ(*(it_int), -10);
  EXPECT_EQ(*cit_int, 100);

  my_containers::Tree<double, double>::iterator it_double = tree_double.begin();
  my_containers::Tree<double, double>::iterator it_double_2 = it_double;
  my_containers::Tree<double, double>::iterator it_double_3(it_double);
  my_containers::Tree<double, double>::iterator it_double_4(tree_double.end());
  my_containers::Tree<double, double>::constIterator cit_double(it_double);
  my_containers::Tree<double, double>::constIterator cit_double_2(cit_double);
  my_containers::Tree<double, double>::constIterator cit_double_3(it_double_4);

  EXPECT_EQ(*(it_double), -10.1);
  EXPECT_EQ(*(it_double_2), -10.1);
  EXPECT_EQ(*(it_double_3), -10.1);
  EXPECT_EQ(*(cit_double), -10.1);
  EXPECT_EQ(*(cit_double_2), -10.1);

  it_int++;
  EXPECT_EQ(*(it_int), -5);
  it_int++;
  EXPECT_EQ(*(it_int), -2);
  it_int += 5;
  EXPECT_EQ(*(it_int), 5);
  it_int -= 2;
  EXPECT_EQ(*(it_int), 3);
  it_int -= 5;
  EXPECT_EQ(*(it_int), -10);
  // it_int-=100;
  // EXPECT_EQ(*(it_int),-10);
  // it_int+=1000;
  // EXPECT_EQ(*(it_int),100);
  it_int = tree_int.end();

  my_containers::Tree<std::string, std::string>::iterator it_string;
  it_string = tree_string;
  EXPECT_EQ(*(it_string), "What's");
  EXPECT_EQ(it_double == it_double_2, true);
  EXPECT_EQ(it_double == it_double_3, true);
  EXPECT_EQ(it_double != it_double_3, false);
  EXPECT_EQ(it_double != it_double_4, true);
  EXPECT_EQ(it_double == it_double_4, false);
  EXPECT_EQ(cit_double == cit_double_2, true);
  EXPECT_EQ(cit_double == cit_double_3, false);

  my_containers::Tree<int, int>::iterator it_int_2;
  it_int_2 = --it_int;
  EXPECT_EQ(*(it_int_2), 50);
  EXPECT_EQ(*(it_int), 50);
  EXPECT_EQ(it_int_2 == it_int, true);
  it_int_2 = it_int--;
  EXPECT_EQ(*(it_int_2), 50);
  EXPECT_EQ(*(it_int), 43);
  EXPECT_EQ(it_int_2 == it_int, false);
}
TEST(TreeTest, Mixed_SS_MS) {
  my_containers::Tree<int, int> tree_int{
      10, 2, 3, 44, 5, 66, -5, -100, 0, 0, 0, 5, 33, 23, 64, 55, 0, 1, 1000};
  my_containers::Tree<double, double> tree_double{
      555.55, 423.2, 2, 1000, -55.55, -33.3, -1000, 100, 1000, 100, -5.5};
  my_containers::Tree<std::string, std::string> tree_str{
      "Jazz",     "I",    "played", "with", "Blues",
      "brothers", "like", "Yoda",   "Wow",  "!"};
  my_containers::Tree<char, char> tree_char{'a',  'b', 'c', 'd', '5', '1',
                                            'a',  '-', '=', '+', 'q', '\n',
                                            '\t', 'y', ']', '[', '(', '`'};
  EXPECT_EQ(tree_int.size(), 15);
  EXPECT_EQ(tree_double.size(), 9);
  EXPECT_EQ(tree_str.size(), 10);
  EXPECT_EQ(tree_char.size(), 17);
  my_containers::Tree<double, int> tree_db_it{
      {555.55, 5}, {423.2, 2},   {1000, 0},     {-55.55, 6000},
      {-33.3, -5}, {-1000, 100}, {100100, 100}, {-5.5, 15}};
  my_containers::Tree<char, std::string> tree_ch_st{
      std::pair<char, std::string>{'5', "Jazz"},
      {'\n', "I"},
      {'y', "played"},
      {'(', "with"},
      {'`', "Blues"},
      {'-', "brothers"},
      {'=', "like"},
      {'b', "Yoda"},
      {'d', "Wow"},
      {'c', "!"}};
  EXPECT_EQ(tree_db_it.size(), 8);
  EXPECT_EQ(tree_ch_st.size(), 10);

  my_containers::Tree<double, int>::iterator it_tree_db_it = tree_db_it.begin();
  EXPECT_EQ(it_tree_db_it.getValue(), 100);
  EXPECT_EQ(it_tree_db_it.getKey(), -1000);
  EXPECT_EQ(it_tree_db_it.getPair().first, -1000);
  EXPECT_EQ(it_tree_db_it.getPair().second, 100);

  my_containers::Tree<double, int>::iterator it;
  EXPECT_THROW(*it, std::out_of_range);

  it = tree_db_it.find(-55.55);
  EXPECT_EQ(*it, 6000);
  EXPECT_EQ(it.assigned(), true);
  std::pair<my_containers::Tree<std::string, std::string>::iterator_, bool>
      output;
  output = tree_str.insert("Han");
  EXPECT_EQ(output.second, true);
  EXPECT_EQ(*output.first, "Han");
  EXPECT_EQ(tree_str.contains("Han"), true);
  output = tree_str.insert("Han");
  EXPECT_EQ(output.second, false);
  EXPECT_THROW(*output.first, std::out_of_range);
  EXPECT_EQ(output.first.assigned(), false);
  EXPECT_EQ(tree_str.contains("Han"), true);

  std::pair<my_containers::Tree<char, std::string>::iterator_, bool> output_2;
  output_2 = tree_ch_st.insert('5', "Jazz");
  EXPECT_EQ(output_2.second, false);
  EXPECT_EQ(tree_ch_st.contains('5'), true);
  output_2 = tree_ch_st.insert('+', "Rock");
  EXPECT_EQ(output_2.second, true);
  EXPECT_EQ(tree_ch_st.contains('+'), true);
  EXPECT_EQ(*output_2.first, "Rock");
  EXPECT_EQ(output_2.first.getKey(), '+');

  tree_ch_st.erase(output_2.first);
  EXPECT_EQ(tree_ch_st.contains('+'), false);
  tree_db_it.erase(it);
  EXPECT_EQ(tree_db_it.size(), 7);
  EXPECT_EQ(tree_db_it.contains(-55.55), false);
}
TEST(TreeTest, Merge_SS_MS) {
  my_containers::Tree<int, int> tree_int{
      10, 2, 3, 44, 5, 66, -5, -100, 0, 0, 0, 5, 33, 23, 64, 55, 0, 1, 1000};
  my_containers::Tree<int, int> tree_int_2{11, 12, 13, 14, 15, 16, 17, 18,
                                           19, 20, 23, 33, 64, 55, 0,  -1000};
  my_containers::Tree<double, double> tree_double{
      555.55, 423.2, 2, 1000, -55.55, -33.3, -1000, 100, 1000, 100, -5.5};
  my_containers::Tree<double, double> tree_double_2{1000, 1000, 12345.12334,
                                                    234.345, 678.678};
  my_containers::Tree<std::string, std::string> tree_str{
      "Jazz",     "Me",   "played", "with", "Blues",
      "brothers", "like", "Yoda",   "Wow",  "!"};
  my_containers::Tree<std::string, std::string> tree_str_2{"I", "Love",
                                                           "Trains", "!"};
  my_containers::Tree<char, char> tree_char{'a',  'b', 'c', 'd', '5', '1',
                                            'a',  '-', '=', '+', 'q', '\n',
                                            '\t', 'y', ']', '[', '(', '`'};
  my_containers::Tree<char, char> tree_char_2{'a',  'b', 'c', 'd', '5', '1',
                                              'a',  '-', '=', '+', 'q', '\n',
                                              '\t', 'y', ']', '[', '(', '`'};
  EXPECT_EQ(tree_int.size(), 15);
  EXPECT_EQ(tree_int_2.size(), 16);
  EXPECT_EQ(tree_double.size(), 9);
  EXPECT_EQ(tree_double_2.size(), 4);
  EXPECT_EQ(tree_str.size(), 10);
  EXPECT_EQ(tree_str_2.size(), 4);
  EXPECT_EQ(tree_char.size(), 17);
  EXPECT_EQ(tree_char_2.size(), 17);
  my_containers::Tree<double, int> tree_db_it{
      {555.55, 5}, {423.2, 2},   {1000, 0},     {-55.55, 6000},
      {-33.3, -5}, {-1000, 100}, {100100, 100}, {-5.5, 15}};
  my_containers::Tree<double, int> tree_db_it_2{
      {1000.1, 1000}, {4.2, 2},     {10, 0},    {-55.5, 6000},
      {-33.3, -5},    {-1000, 100}, {100, 100}, {-5, 15}};
  my_containers::Tree<char, std::string> tree_ch_st{
      std::pair<char, std::string>{'5', "Jazz"},
      {'\n', "I"},
      {'y', "played"},
      {'(', "with"},
      {'`', "Blues"},
      {'-', "brothers"},
      {'=', "like"},
      {'b', "Yoda"},
      {'d', "Wow"},
      {'c', "!"}};
  my_containers::Tree<std::string, char> tree_ch_st_2{
      std::pair<std::string, char>{"Jazz", '5'},
      {"I", '\n'},
      {"played", 'y'},
      {"with", '('},
      {"brothers", '-'}};
  EXPECT_EQ(tree_db_it.size(), 8);
  EXPECT_EQ(tree_db_it_2.size(), 8);
  EXPECT_EQ(tree_ch_st.size(), 10);
  EXPECT_EQ(tree_ch_st_2.size(), 5);
  my_containers::Tree<int, int> tree_int_3;
  my_containers::Tree<int, int> tree_int_4;

  tree_int.merge(tree_int_2);
  EXPECT_EQ(tree_int.size(), 26);
  EXPECT_EQ(tree_int_2.size(), 5);
  EXPECT_EQ(tree_int.contains(10), true);
  EXPECT_EQ(tree_int.contains(11), true);
  EXPECT_EQ(tree_int.contains(12), true);
  EXPECT_EQ(tree_int_2.contains(13), false);
  EXPECT_EQ(tree_int_2.contains(14), false);
  EXPECT_EQ(tree_int_2.contains(55), true);
  EXPECT_EQ(tree_int.contains(55), true);

  tree_int.merge(tree_int_3);
  EXPECT_EQ(tree_int.size(), 26);
  EXPECT_EQ(tree_int_3.size(), 0);

  tree_int_4.merge(tree_int);
  EXPECT_EQ(tree_int.size(), 0);
  EXPECT_EQ(tree_int_4.size(), 26);
  EXPECT_EQ(tree_int_4.contains(10), true);
  EXPECT_EQ(tree_int_4.contains(11), true);
  EXPECT_EQ(tree_int_4.contains(12), true);

  tree_double.merge(tree_double_2);
  EXPECT_EQ(tree_double.size(), 12);
  EXPECT_EQ(tree_double_2.size(), 1);
  EXPECT_EQ(tree_double.contains(12345.12334), true);

  tree_str.merge(tree_str_2);
  EXPECT_EQ(tree_str.size(), 13);
  EXPECT_EQ(tree_str_2.size(), 1);
  EXPECT_EQ(tree_str.contains("Trains"), true);

  tree_char.merge(tree_char_2);
  EXPECT_EQ(tree_char.size(), 17);
  EXPECT_EQ(tree_char_2.size(), 17);

  tree_db_it.merge(tree_db_it_2);
  EXPECT_EQ(tree_db_it.size(), 14);
  EXPECT_EQ(tree_db_it_2.size(), 2);
}
TEST(TreeTest, Bonus_SS) {
  my_containers::Tree<int, int> tree_int(-5000);
  my_containers::Tree<double, double> tree_double(-5000.5005);
  my_containers::Tree<std::string, std::string> tree_str("John Sheridan");
  my_containers::Tree<char, char> tree_char('t');
  my_containers::Tree<int, int> tree_int_2;
  my_containers::Tree<double, double> tree_double_2;
  my_containers::Tree<std::string, std::string> tree_str_2;
  my_containers::Tree<char, char> tree_char_2;

  tree_int.insert_many(10, 2, 3, 44, 5, 66, -5, -100, 0, 0, 0, 5, 33, 23, 64,
                       55, 0, 1, 1000);
  tree_double.insert_many(555.55, 423.2, 2, 1000, -55.55, -33.3, -1000, 100,
                          1000, 100, -5.5);
  tree_str.insert_many("Jazz", "Me", "played", "with", "Blues", "brothers",
                       "like", "Yoda", "Wow", "!");
  tree_char.insert_many('a', 'b', 'c', 'd', '5', '1', 'a', '-', '=', '+', 'q',
                        '\n', '\t', 'y', ']', '[', '(', '`');
  EXPECT_EQ(tree_int.size(), 16);
  EXPECT_EQ(tree_double.size(), 10);
  EXPECT_EQ(tree_str.size(), 11);
  EXPECT_EQ(tree_char.size(), 18);
  EXPECT_EQ(tree_int.contains(10), true);
  EXPECT_EQ(tree_int.contains(44), true);
  EXPECT_EQ(tree_int.contains(-5000), true);
  EXPECT_EQ(tree_double.contains(1000), true);
  EXPECT_EQ(tree_str.contains("Blues"), true);
  EXPECT_EQ(tree_str.contains("Wow"), true);
  EXPECT_EQ(tree_char.contains('a'), true);
  EXPECT_EQ(tree_char.contains('b'), true);
  EXPECT_EQ(tree_char.contains('c'), true);

  tree_int_2.insert_many(11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 23, 33, 64, 55,
                         0, -1000);
  tree_double_2.insert_many(1000, 1000, 12345.12334, 234.345, 678.678);
  tree_str_2.insert_many("I", "Love", "Trains", "!");
  tree_char_2.insert_many('a', 'b', 'c', 'd', '5', '1', 'a', '-', '=', '+', 'q',
                          '\n', '\t', 'y', ']', '[', '(', '`');
  EXPECT_EQ(tree_int_2.size(), 16);
  EXPECT_EQ(tree_double_2.size(), 4);
  EXPECT_EQ(tree_str_2.size(), 4);
  EXPECT_EQ(tree_char_2.size(), 17);
  EXPECT_EQ(tree_int_2.contains(11), true);
  EXPECT_EQ(tree_int_2.contains(14), true);
  EXPECT_EQ(tree_int_2.contains(23), true);
  EXPECT_EQ(tree_double_2.contains(1000), true);
  EXPECT_EQ(tree_str_2.contains("I"), true);
  EXPECT_EQ(tree_str_2.contains("Love"), true);
  EXPECT_EQ(tree_char_2.contains('a'), true);
  EXPECT_EQ(tree_char_2.contains('b'), true);
  EXPECT_EQ(tree_char_2.contains('c'), true);

  tree_int_2.insert_many();
  tree_double_2.insert_many();
  tree_str_2.insert_many();
  tree_char_2.insert_many();
  EXPECT_EQ(tree_int_2.size(), 16);
  EXPECT_EQ(tree_double_2.size(), 4);
  EXPECT_EQ(tree_str_2.size(), 4);
  EXPECT_EQ(tree_char_2.size(), 17);

  my_containers::vector<
      std::pair<my_containers::Tree<int, int>::iterator, bool>>
      vec;
  vec = tree_int_2.insert_many(12, 44, 14, 55, 0, 77, 88, 99, 100, -5, -100, 55,
                               55.5, 77.77777);
  EXPECT_EQ(tree_int_2.size(), 23);
  EXPECT_EQ(vec.size(), 14);
  for (size_t i = 0; i < vec.size(); i++) {
    if (i == 0 || i == 2 || i == 3 || i == 4 || i == 11 || i == 12 || i == 13)
      EXPECT_EQ(vec[i].second, false);
    else {
      EXPECT_EQ(vec[i].second, true);
      EXPECT_EQ(tree_int_2.contains(*vec[i].first), true);
    }
  }
}
TEST(TreeTest, Multiset_functions) {
  my_containers::Tree<int, int> tree_int{
      10, 2, 3, 44, 5, 66, -5, -100, 0, 0, 0, 5, 33, 23, 64, 55, 0, 1, 1000};
  my_containers::Tree<double, double> tree_double{
      555.55, 423.2, 2, 1000, -55.55, -33.3, -1000, 100, 1000, 100, -5.5};
  my_containers::Tree<std::string, std::string> tree_str{
      "Jazz",     "Me",   "played", "with", "Blues",
      "brothers", "like", "Yoda",   "Wow",  "!"};
  my_containers::Tree<char, char> tree_char{'a',  'b', 'c', 'd', '5', '1',
                                            'a',  '-', '=', '+', 'q', '\n',
                                            '\t', 'y', ']', '[', '(', '`'};
  EXPECT_EQ(tree_int.size(), 15);
  EXPECT_EQ(tree_double.size(), 9);
  EXPECT_EQ(tree_str.size(), 10);
  EXPECT_EQ(tree_char.size(), 17);

  tree_int.insertMult(55);
  tree_int.insertMult(55);
  tree_int.insertMult(55);
  tree_int.insertMult(55);
  tree_int.insertMult(55);
  tree_int.insertMult(55);
  tree_int.insertMult(55);
  tree_int.insertMult(55);
  tree_int.insertMult(55);
  tree_int.insertMult(55);
  tree_int.insertMult(55);
  tree_int.insertMult(55);
  tree_int.insertMult(55);
  tree_int.insertMult(54);
  tree_int.insertMult(56);
  // tree_int.showTreeVertical();
  EXPECT_EQ(tree_int.size(), 30);
  // tree_int.crazyPrinter();
  EXPECT_NE(tree_double.insertMult(-1000), tree_double.insertMult(-1000));
  EXPECT_EQ(*tree_double.insertMult(-1000), *tree_double.insertMult(-1000));
}