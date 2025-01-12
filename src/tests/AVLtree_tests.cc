#include "global_tests.h"
#include <set>
#include "../src/AVLtree/avl_tree.hpp"
#include "../src/stack/stack.hpp"
#include <iostream>

TEST(TreeTest, DefaultConstructor) {
    s21::Tree<int> tree_int;
    s21::Tree<double> tree_double;
    s21::Tree<std::string> tree_str;
    s21::Tree<char> tree_char;
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
    // std::cout<<tree_int.find(-55)->data_<<std::endl;
    tree_int.showTreeVertical();
    EXPECT_EQ(tree_int.size(), 13);
    EXPECT_EQ(tree_int.empty(),false);
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
    // tree_double.showTreeVertical();
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
    // tree_str.showTreeVertical();
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
    // tree_char.showTreeVertical();
    EXPECT_EQ(tree_char.size(), 7);
    EXPECT_EQ(tree_char.empty(), false);

    tree_int.clear();
    EXPECT_EQ(tree_int.size(), 0);
    EXPECT_EQ(tree_int.empty(),true);

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
TEST(TreeTest, RootConstructor) {
    s21::Tree<int> tree_int{10};
    s21::Tree<double> tree_double{555.55};
    s21::Tree<std::string> tree_str{"Jazz"};
    s21::Tree<char> tree_char{'5'};
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
    EXPECT_EQ(tree_int.empty(),false);
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
    EXPECT_EQ(tree_int.empty(),true);
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
TEST(TreeTest, ArrayConstructor) {
    s21::Tree<int> tree_int{10,2,3,44,5,66,-5,-100,0,0,0,5,33,23,64,55,0,1,1000};
    s21::Tree<double> tree_double{555.55, 423.2,2,1000,-55.55,-33.3,-1000,100,1000,100,-5.5};
    s21::Tree<std::string> tree_str{"Jazz", "I", "played", "with", "Blues", "brothers", "like", "Yoda", "Wow", "!"};
    s21::Tree<char> tree_char{'a', 'b', 'c', 'd','5','1','a','-','=','+','q','\n','\t','y',']','[','(','`'};
    tree_int.insert(5);
    tree_int.insert(2);
    tree_int.insert(8);
    tree_int.insert(4);
    tree_int.insert(4.55);
    EXPECT_EQ(tree_int.size(), 17);
    EXPECT_EQ(tree_int.empty(),false);
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
TEST(TreeTest, CopyTree) {
    s21::Tree<int> tree_int{10,2,3,44,5,66,-5,-100,0,0,0,5,33,23,64,55,0,1,1000};
    s21::Tree<double> tree_double{555.55, 423.2,2,1000,-55.55,-33.3,-1000,100,1000,100,-5.5};
    s21::Tree<std::string> tree_str{"Jazz", "I", "played", "with", "Blues", "brothers", "like", "Yoda", "Wow", "!"};
    s21::Tree<char> tree_char{'a', 'b', 'c', 'd','5','1','a','-','=','+','q','\n','\t','y',']','[','(','`'};
    EXPECT_EQ(tree_int.size(), 15);
    EXPECT_EQ(tree_double.size(), 9);
    EXPECT_EQ(tree_str.size(), 10);
    EXPECT_EQ(tree_char.size(), 17);

    s21::Tree<int> tree_int_2; 
    tree_int.copyTree(tree_int_2);
    s21::Tree<double> tree_double_2;
    tree_double.copyTree(tree_double_2);
    s21::Tree<std::string> tree_str_2;
    tree_str.copyTree(tree_str_2);
    s21::Tree<char> tree_char_2;
    tree_char.copyTree(tree_char_2);

    EXPECT_EQ(tree_int_2.size(), 15);
    EXPECT_NE(&tree_int_2,&tree_int);
    EXPECT_EQ(tree_double_2.size(), 9);
    EXPECT_NE(&tree_double_2,&tree_double);
    EXPECT_EQ(tree_str_2.size(), 10);
    EXPECT_NE(&tree_str_2,&tree_str);
    EXPECT_EQ(tree_char_2.size(), 17);
    EXPECT_NE(&tree_char_2,&tree_char);

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

    s21::Tree<int> tree_int_3;
    s21::Tree<int> tree_int_4;
    tree_int_3.copyTree(tree_int_4);
    EXPECT_EQ(tree_int_3.empty(), true);
    EXPECT_EQ(tree_int_4.empty(), true);
}
TEST(TreeTest, GetTree) {
    s21::Tree<int> tree_int{10,2,3,44,5,66,-5,-100,0,0,0,5,33,23,64,55,0,1,1000};
    s21::Tree<double> tree_double{555.55, 423.2,2,1000,-55.55,-33.3,-1000,100,1000,100,-5.5};
    s21::Tree<std::string> tree_str{"Jazz", "I", "played", "with", "Blues", "brothers", "like", "Yoda", "Wow", "!"};
    s21::Tree<char> tree_char{'a', 'b', 'c', 'd','5','1','a','-','=','+','q','\n','\t','y',']','[','(','`'};
    EXPECT_EQ(tree_int.size(), 15);
    EXPECT_EQ(tree_double.size(), 9);
    EXPECT_EQ(tree_str.size(), 10);
    EXPECT_EQ(tree_char.size(), 17);

    s21::Stack<int> stack_int;
    s21::Stack<double> stack_double;
    s21::Stack<std::string> stack_str;
    s21::Stack<char> stack_char;

    tree_int.getTree(stack_int);
    tree_double.getTree(stack_double);
    tree_str.getTree(stack_str);
    tree_char.getTree(stack_char);
    EXPECT_EQ(stack_int.size(), 15);
    EXPECT_EQ(stack_double.size(), 9);
    EXPECT_EQ(stack_str.size(), 10);
    EXPECT_EQ(stack_char.size(), 17);

    s21::Stack<int> stack_int_2;
    s21::Stack<double> stack_double_2;
    s21::Stack<std::string> stack_str_2;
    s21::Stack<char> stack_char_2;
    stack_int_2=tree_int.getTree(stack_int_2);
    stack_double_2=tree_double.getTree(stack_double_2);
    stack_str_2=tree_str.getTree(stack_str_2);
    stack_char_2=tree_char.getTree(stack_char_2);
    EXPECT_EQ(stack_int_2.size(), 15);
    EXPECT_EQ(stack_double_2.size(), 9);
    EXPECT_EQ(stack_str_2.size(), 10);
    EXPECT_EQ(stack_char_2.size(), 17);

    s21::Stack<int> stack_int_3;
    s21::Stack<double> stack_double_3;
    s21::Stack<std::string> stack_str_3;
    s21::Stack<char> stack_char_3;
    s21::Stack<int> stack_int_4;
    s21::Stack<double> stack_double_4;
    s21::Stack<std::string> stack_str_4;
    s21::Stack<char> stack_char_4;

    stack_int_3=tree_int.getTree(stack_int_4);
    stack_double_3=tree_double.getTree(stack_double_4);
    stack_str_3=tree_str.getTree(stack_str_4);
    stack_char_3=tree_char.getTree(stack_char_4);
    EXPECT_EQ(stack_int_3.size(), 15);
    EXPECT_EQ(stack_double_3.size(), 9);
    EXPECT_EQ(stack_str_3.size(), 10);
    EXPECT_EQ(stack_char_3.size(), 17);
    EXPECT_EQ(stack_int_4.size(), 15);
    EXPECT_EQ(stack_double_4.size(), 9);
    EXPECT_EQ(stack_str_4.size(), 10);
    EXPECT_EQ(stack_char_4.size(), 17);
}
TEST(TreeTest, MoveAssignment) {
    s21::Tree<int> tree_int{10,2,3,44,5,66,-5,-100,0,0,0,5,33,23,64,55,0,1,1000};
    s21::Tree<double> tree_double{555.55, 423.2,2,1000,-55.55,-33.3,-1000,100,1000,100,-5.5};
    s21::Tree<std::string> tree_str{"Jazz", "I", "played", "with", "Blues", "brothers", "like", "Yoda", "Wow", "!"};
    s21::Tree<char> tree_char{'a', 'b', 'c', 'd','5','1','a','-','=','+','q','\n','\t','y',']','[','(','`'};
    EXPECT_EQ(tree_int.size(), 15);
    EXPECT_EQ(tree_double.size(), 9);
    EXPECT_EQ(tree_str.size(), 10);
    EXPECT_EQ(tree_char.size(), 17);

    s21::Tree<int> tree_int_2=std::move(tree_int);
    s21::Tree<double> tree_double_2=std::move(tree_double);
    s21::Tree<std::string> tree_str_2=std::move(tree_str);
    s21::Tree<char> tree_char_2=std::move(tree_char);
    EXPECT_EQ(tree_int_2.size(), 15);
    EXPECT_EQ(tree_double_2.size(), 9);
    EXPECT_EQ(tree_str_2.size(), 10);
    EXPECT_EQ(tree_char_2.size(), 17);
    EXPECT_EQ(tree_int.size(), 0);
    EXPECT_EQ(tree_double.size(), 0);
    EXPECT_EQ(tree_str.size(), 0);
    EXPECT_EQ(tree_char.size(), 0);

     s21::Tree<int> tree_int_3;
     s21::Tree<double> tree_double_3;
     s21::Tree<std::string> tree_str_3;
     s21::Tree<char> tree_char_3;
     s21::Tree<int> tree_int_4=std::move(tree_int_3);
     s21::Tree<double> tree_double_4=std::move(tree_double_3);
     s21::Tree<std::string> tree_str_4=std::move(tree_str_3);
     s21::Tree<char> tree_char_4=std::move(tree_char_3);
     EXPECT_EQ(tree_int_4.empty(), true);
     EXPECT_EQ(tree_double_4.empty(), true);
     EXPECT_EQ(tree_str_4.empty(), true);
     EXPECT_EQ(tree_char_4.empty(), true);
     EXPECT_EQ(tree_int_3.empty(), true);
     EXPECT_EQ(tree_double_3.empty(), true);
     EXPECT_EQ(tree_str_3.empty(), true);
     EXPECT_EQ(tree_char_3.empty(), true);
}
TEST(TreeTest, Contains) {
    s21::Tree<int> tree_int{10,2,3,44,5,66,-5,-100,0,0,0,5,33,23,64,55,0,1,1000};
    s21::Tree<double> tree_double{555.55, 423.2,2,1000,-55.55,-33.3,-1000,100,1000,100,-5.5};
    s21::Tree<std::string> tree_str{"Jazz", "I", "played", "with", "Blues", "brothers", "like", "Yoda", "Wow", "!"};
    s21::Tree<char> tree_char{'a', 'b', 'c', 'd','5','1','a','-','=','+','q','\n','\t','y',']','[','(','`'};
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
TEST(TreeTest, Swap) {
    s21::Tree<int> tree_int{10,2,3,44,5,66,-5,-100,0,0,0,5,33,23,64,55,0,1,1000};
    s21::Tree<double> tree_double{555.55, 423.2,2,1000,-55.55,-33.3,-1000,100,1000,100,-5.5};
    s21::Tree<std::string> tree_str{"Jazz", "I", "played", "with", "Blues", "brothers", "like", "Yoda", "Wow", "!"};
    s21::Tree<char> tree_char{'a', 'b', 'c', 'd','5','1','a','-','=','+','q','\n','\t','y',']','[','(','`'};
    EXPECT_EQ(tree_int.size(), 15);
    EXPECT_EQ(tree_double.size(), 9);
    EXPECT_EQ(tree_str.size(), 10);
    EXPECT_EQ(tree_char.size(), 17);

    s21::Tree<int> tree_int_2{10,2,3,44,5,66,-5};
    s21::Tree<double> tree_double_2{555.55, 42,100,1000,100,-5.5};
    s21::Tree<std::string> tree_str_2{"Jazz", "I", "played", "with", "Yoda"};
    s21::Tree<char> tree_char_2{'a', 'b',']','[','(','`'};
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
TEST(TreeTest, CopyAssignment) {
    s21::Tree<int> tree_int{10,2,3,44,5,66,-5,-100,0,0,0,5,33,23,64,55,0,1,1000};
    s21::Tree<double> tree_double{555.55, 423.2,2,1000,-55.55,-33.3,-1000,100,1000,100,-5.5};
    s21::Tree<std::string> tree_str{"Jazz", "I", "played", "with", "Blues", "brothers", "like", "Yoda", "Wow", "!"};
    s21::Tree<char> tree_char{'a', 'b', 'c', 'd','5','1','a','-','=','+','q','\n','\t','y',']','[','(','`'};
    EXPECT_EQ(tree_int.size(), 15);
    EXPECT_EQ(tree_double.size(), 9);
    EXPECT_EQ(tree_str.size(), 10);
    EXPECT_EQ(tree_char.size(), 17);

    s21::Tree<int> tree_int_2=tree_int;
    s21::Tree<double> tree_double_2=tree_double;
    s21::Tree<std::string> tree_str_2=tree_str;
    s21::Tree<char> tree_char_2=tree_char;
    EXPECT_EQ(tree_int.size(), 15);
    EXPECT_EQ(tree_double.size(), 9);
    EXPECT_EQ(tree_str.size(), 10);
    EXPECT_EQ(tree_char.size(), 17);
    EXPECT_EQ(tree_int_2.size(), 15);
    EXPECT_EQ(tree_double_2.size(), 9);
    EXPECT_EQ(tree_str_2.size(), 10);
    EXPECT_EQ(tree_char_2.size(), 17);

     s21::Tree<int> tree_int_3;
     s21::Tree<double> tree_double_3;
     s21::Tree<std::string> tree_str_3;
     s21::Tree<char> tree_char_3;
     s21::Tree<int> tree_int_4=tree_int_3;
     s21::Tree<double> tree_double_4=tree_double_3;
     s21::Tree<std::string> tree_str_4=tree_str_3;
     s21::Tree<char> tree_char_4=tree_char_3;
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

    tree_int_4=tree_int_2;
    tree_double_4=tree_double_2;
    tree_str_4=tree_str_2;
    tree_char_4=tree_char_2;
    tree_int=tree_int_3;
    tree_double=tree_double_3;
    tree_str=tree_str_3;
    tree_char=tree_char_3;
    EXPECT_EQ(tree_int_4.size(), 15);
    EXPECT_EQ(tree_double_4.size(), 9);
    EXPECT_EQ(tree_str_4.size(), 10);
    EXPECT_EQ(tree_char_4.size(), 17);
     EXPECT_EQ(tree_int.empty(), true);
     EXPECT_EQ(tree_double.empty(), true);
     EXPECT_EQ(tree_str.empty(), true);
     EXPECT_EQ(tree_char.empty(), true);


}
TEST(TreeTest, MoveConstructor) {
    s21::Tree<int> tree_int{10,2,3,44,5,66,-5,-100,0,0,0,5,33,23,64,55,0,1,1000};
    s21::Tree<double> tree_double{555.55, 423.2,2,1000,-55.55,-33.3,-1000,100,1000,100,-5.5};
    s21::Tree<std::string> tree_str{"Jazz", "I", "played", "with", "Blues", "brothers", "like", "Yoda", "Wow", "!"};
    s21::Tree<char> tree_char{'a', 'b', 'c', 'd','5','1','a','-','=','+','q','\n','\t','y',']','[','(','`'};
    EXPECT_EQ(tree_int.size(), 15);
    EXPECT_EQ(tree_double.size(), 9);
    EXPECT_EQ(tree_str.size(), 10);
    EXPECT_EQ(tree_char.size(), 17);

    s21::Tree<int> tree_int_2(std::move(tree_int));
    s21::Tree<double> tree_double_2(std::move(tree_double));
    s21::Tree<std::string> tree_str_2(std::move(tree_str));
    s21::Tree<char> tree_char_2(std::move(tree_char));
    EXPECT_EQ(tree_int_2.size(), 15);
    EXPECT_EQ(tree_double_2.size(), 9);
    EXPECT_EQ(tree_str_2.size(), 10);
    EXPECT_EQ(tree_char_2.size(), 17);
    EXPECT_EQ(tree_int.size(), 0);
    EXPECT_EQ(tree_double.size(), 0);
    EXPECT_EQ(tree_str.size(), 0);
    EXPECT_EQ(tree_char.size(), 0);
}
TEST(TreeTest, CopyConstructor) {
    s21::Tree<int> tree_int{10,2,3,44,5,66,-5,-100,0,0,0,5,33,23,64,55,0,1,1000};
    s21::Tree<double> tree_double{555.55, 423.2,2,1000,-55.55,-33.3,-1000,100,1000,100,-5.5};
    s21::Tree<std::string> tree_str{"Jazz", "I", "played", "with", "Blues", "brothers", "like", "Yoda", "Wow", "!"};
    s21::Tree<char> tree_char{'a', 'b', 'c', 'd','5','1','a','-','=','+','q','\n','\t','y',']','[','(','`'};
    EXPECT_EQ(tree_int.size(), 15);
    EXPECT_EQ(tree_double.size(), 9);
    EXPECT_EQ(tree_str.size(), 10);
    EXPECT_EQ(tree_char.size(), 17);

    s21::Tree<int> tree_int_2(tree_int);
    s21::Tree<double> tree_double_2(tree_double);
    s21::Tree<std::string> tree_str_2(tree_str);
    s21::Tree<char> tree_char_2(tree_char);
    EXPECT_EQ(tree_int_2.size(), 15);
    EXPECT_EQ(tree_double_2.size(), 9);
    EXPECT_EQ(tree_str_2.size(), 10);
    EXPECT_EQ(tree_char_2.size(), 17);
    EXPECT_EQ(tree_int.size(), 15);
    EXPECT_EQ(tree_double.size(), 9);
    EXPECT_EQ(tree_str.size(), 10);
    EXPECT_EQ(tree_char.size(), 17);
}
// This thest is systrm dependent -- may cause errors 
TEST(TreeTest, Max_size) {
    s21::Tree<int> tree_int{10,2,3,44,5,66,-5,-100,0,0,0,5,33,23,64,55,0,1,1000};
    s21::Tree<double> tree_double{555.55, 423.2,2,1000,-55.55,-33.3,-1000,100,1000,100,-5.5};
    s21::Tree<std::string> tree_str{"Jazz", "I", "played", "with", "Blues", "brothers", "like", "Yoda", "Wow", "!"};
    s21::Tree<char> tree_char{'a', 'b', 'c', 'd','5','1','a','-','=','+','q','\n','\t','y',']','[','(','`'};
    s21::Tree<int> tree_int_2;
    s21::Tree<double> tree_double_2;
    s21::Tree<std::string> tree_str_2;
    s21::Tree<char> tree_char_2;
    EXPECT_EQ(tree_int.max_size(),576460752303423487);
    EXPECT_EQ(tree_double.max_size(),576460752303423487);
    EXPECT_EQ(tree_str.max_size(),329406144173384850);
    EXPECT_EQ(tree_char.max_size(),576460752303423487);
    EXPECT_EQ(tree_int_2.max_size(),576460752303423487);
    EXPECT_EQ(tree_double_2.max_size(),576460752303423487);
    EXPECT_EQ(tree_str_2.max_size(),329406144173384850);
    EXPECT_EQ(tree_char_2.max_size(),576460752303423487);
}
TEST(TreeTest, Remove_int) {
    s21::Tree<int> tree_int{15,4,26,5,20,0,34,10,16,22,3,32,-5,50,8,18,12,21,1,28,33,-2,43,-10,100};
    EXPECT_EQ(tree_int.size(), 25);
    // tree_int.showTreeVertical();
    EXPECT_EQ(tree_int.contains(-10),true);
    tree_int.remove(-10);
    EXPECT_EQ(tree_int.size(), 24);
    EXPECT_EQ(tree_int.contains(-10),false);
    // tree_int.showTreeVertical();
    EXPECT_EQ(tree_int.contains(16),true);
    tree_int.remove(16);
    EXPECT_EQ(tree_int.size(), 23);
    EXPECT_EQ(tree_int.contains(16),false);
    EXPECT_EQ(tree_int.contains(22),true);
    tree_int.remove(22);
    EXPECT_EQ(tree_int.size(), 22);
    EXPECT_EQ(tree_int.contains(22),false);
    EXPECT_EQ(tree_int.contains(50),true);
    tree_int.remove(50);
    EXPECT_EQ(tree_int.size(), 21);
    EXPECT_EQ(tree_int.contains(50),false);
    EXPECT_EQ(tree_int.contains(26),true);
    tree_int.remove(26);
    EXPECT_EQ(tree_int.size(), 20);
    EXPECT_EQ(tree_int.contains(26),false);
    EXPECT_EQ(tree_int.contains(28),true);
    tree_int.remove(28);
    EXPECT_EQ(tree_int.size(), 19);
    EXPECT_EQ(tree_int.contains(28),false);
    EXPECT_EQ(tree_int.contains(4),true);
    tree_int.remove(4);
    EXPECT_EQ(tree_int.size(), 18);
    EXPECT_EQ(tree_int.contains(4),false);
    EXPECT_EQ(tree_int.contains(400),false);
    tree_int.remove(400);
    EXPECT_EQ(tree_int.size(), 18);
    EXPECT_EQ(tree_int.contains(400),false);
    EXPECT_EQ(tree_int.contains(15),true);
    tree_int.remove(15);
    EXPECT_EQ(tree_int.size(), 17);
    EXPECT_EQ(tree_int.contains(15),false);
    tree_int.remove(10);
    tree_int.remove(8);
    tree_int.remove(12);
    tree_int.remove(3);
    tree_int.remove(1);
    EXPECT_EQ(tree_int.size(), 12);
    EXPECT_EQ(tree_int.contains(10),false);
    EXPECT_EQ(tree_int.contains(8),false);
    EXPECT_EQ(tree_int.contains(12),false);
    EXPECT_EQ(tree_int.contains(3),false);
    EXPECT_EQ(tree_int.contains(1),false);
    tree_int.remove(-2);
    tree_int.remove(-5);
    tree_int.remove(0);
    EXPECT_EQ(tree_int.size(), 9);
    EXPECT_EQ(tree_int.contains(-2),false);
    EXPECT_EQ(tree_int.contains(-5),false);
    EXPECT_EQ(tree_int.contains(0),false);
    // tree_int.showTreeVertical();
}
TEST(TreeTest, Remove_double) {
    s21::Tree<double> tree{15.15,4.4,26.26,5.5,20.20,0,34.34,10.1,16.16,22.22,3.3,32.32,-5.5,50.50,8.8,18.18,12.12,21.21,1.1,28.28,33.33,-2.2,43.43,-10.1,100.1};
    EXPECT_EQ(tree.size(), 25);
    // tree.showTreeVertical();
    EXPECT_EQ(tree.contains(-10.1),true);
    tree.remove(-10.1);
    EXPECT_EQ(tree.size(), 24);
    EXPECT_EQ(tree.contains(-10.1),false);
    // tree.showTreeVertical();
    EXPECT_EQ(tree.contains(16.16),true);
    tree.remove(16.16);
    EXPECT_EQ(tree.size(), 23);
    EXPECT_EQ(tree.contains(16.16),false);
    EXPECT_EQ(tree.contains(22.22),true);
    tree.remove(22.22);
    EXPECT_EQ(tree.size(), 22);
    EXPECT_EQ(tree.contains(22.22),false);
    EXPECT_EQ(tree.contains(50.5),true);
    tree.remove(50.5);
    EXPECT_EQ(tree.size(), 21);
    EXPECT_EQ(tree.contains(50.5),false);
    tree.remove(10.1);
    tree.remove(8.8);
    tree.remove(12.12);
    tree.remove(3.3);
    tree.remove(1.1);
    EXPECT_EQ(tree.size(), 16);
    EXPECT_EQ(tree.contains(10.1),false);
    EXPECT_EQ(tree.contains(8.8),false);
    EXPECT_EQ(tree.contains(12.12),false);
    EXPECT_EQ(tree.contains(3.3),false);
    EXPECT_EQ(tree.contains(1.1),false);
    tree.remove(-2.2);
    tree.remove(-5.5);
    tree.remove(0);
    tree.remove(0);
    tree.remove(0);
    tree.remove(0);
    tree.remove(15.15);
    EXPECT_EQ(tree.size(), 12);
    EXPECT_EQ(tree.contains(-2.2),false);
    EXPECT_EQ(tree.contains(-5.5),false);
    EXPECT_EQ(tree.contains(0),false);
    EXPECT_EQ(tree.contains(15),false);
    // tree.showTreeVertical();
}
TEST(TreeTest, Remove_string) {
    s21::Tree<std::string> tree{"What's", "up", "Vsauce", "Michael", "Here", "!"};
    EXPECT_EQ(tree.size(), 6);
    // tree.showTreeVertical();
    EXPECT_EQ(tree.contains("up"),true);
    tree.remove("up");
    EXPECT_EQ(tree.size(), 5);
    EXPECT_EQ(tree.contains("up"),false);
    // tree.showTreeVertical();
    EXPECT_EQ(tree.contains("Vsauce"),true);
    tree.remove("Vsauce");
    EXPECT_EQ(tree.size(), 4);
    EXPECT_EQ(tree.contains("Vsauce"),false);
    EXPECT_EQ(tree.contains("Here"),true);
    tree.remove("Here");
    EXPECT_EQ(tree.size(), 3);
    EXPECT_EQ(tree.contains("Here"),false);
    EXPECT_EQ(tree.contains("!"),true);
    tree.remove("!");
    EXPECT_EQ(tree.size(), 2);
    EXPECT_EQ(tree.contains("!"),false);
    tree.insert("?");
    EXPECT_EQ(tree.size(), 3);
    // tree.showTreeVertical();

}
TEST(TreeTest, Remove_char) {
    s21::Tree<char> tree{'g','\0','4','a','\t','0','f','v','b','n','j','h','t','e'};
    EXPECT_EQ(tree.size(), 14);
    // tree.showTreeVertical();
    EXPECT_EQ(tree.contains('4'),true);
    tree.remove('4');
    EXPECT_EQ(tree.size(), 13);
    EXPECT_EQ(tree.contains('4'),false);
    // tree.showTreeVertical();
    EXPECT_EQ(tree.contains('1'),false);
    tree.remove('1');
    EXPECT_EQ(tree.size(), 13);
    EXPECT_EQ(tree.contains('1'),false);
    EXPECT_EQ(tree.contains('\0'),true);
    tree.remove('\0');
    tree.remove('\t');
    EXPECT_EQ(tree.size(), 11);
    EXPECT_EQ(tree.contains('\0'),false);
    EXPECT_EQ(tree.contains('f'),true);
    tree.remove('f');
    tree.remove('v');
    tree.remove('b');
    tree.remove('n');
    EXPECT_EQ(tree.size(), 7);
    EXPECT_EQ(tree.contains('f'),false);
    EXPECT_EQ(tree.contains('v'),false);
    EXPECT_EQ(tree.contains('b'),false);
    EXPECT_EQ(tree.contains('n'),false);
    
    // tree.showTreeVertical();
}
TEST(TreeTest, Parent) {
s21::Tree<int> tree_int{15,4,26,5,20,0,34,10,16,22,3,32,-5,50,8,18,12,21,1,28,33,-2,43,-10,100};
    EXPECT_EQ(tree_int.size(), 25);
    EXPECT_THROW(tree_int.getParentData(15),std::out_of_range);
    EXPECT_EQ(tree_int.getParentData(26),15);
    EXPECT_EQ(tree_int.getParentData(4),15);
    EXPECT_EQ(tree_int.getParentData(5),8);
    EXPECT_EQ(tree_int.getParentData(20),26);
    EXPECT_EQ(tree_int.getParentData(0),4);
    EXPECT_EQ(tree_int.getParentData(100),50);
    EXPECT_EQ(tree_int.getParentData(33),32);
    EXPECT_EQ(tree_int.getParentData(28),32);
    EXPECT_EQ(tree_int.getParentData(10),8);
    EXPECT_EQ(tree_int.getParentData(-2),-5);
    // tree_int.crazyPrinter();
    EXPECT_EQ(tree_int.getParentData(21),22);
    EXPECT_EQ(tree_int.contains(32),true);
    tree_int.remove(32);
    EXPECT_EQ(tree_int.contains(32),false);
    EXPECT_EQ(tree_int.getParentData(28),33);
    EXPECT_EQ(tree_int.contains(26),true);
    tree_int.remove(26);
    EXPECT_EQ(tree_int.contains(26),false);
    EXPECT_EQ(tree_int.getParentData(20),28);
    tree_int.remove(10);
    tree_int.remove(8);
    tree_int.remove(12);
    tree_int.remove(3);
    tree_int.remove(34);
    tree_int.remove(20);
    tree_int.remove(2);
    tree_int.remove(-10);
    // tree_int.crazyPrinter();
    EXPECT_EQ(tree_int.getParentData(28),15);
    EXPECT_EQ(tree_int.getParentData(22),21);
    EXPECT_EQ(tree_int.getParentData(16),21);
    EXPECT_EQ(tree_int.getParentData(1),4);
    EXPECT_THROW(tree_int.getParentData(-1000),std::out_of_range);
    EXPECT_EQ(tree_int.getParentData(-2),-5);
    EXPECT_EQ(tree_int.getParentData(22),21);
    EXPECT_EQ(tree_int.getParentData(50),43);
}
TEST(TreeTest, begin_end) {
    s21::Tree<int> tree_int{15,4,26,5,20,0,34,10,16,22,3,32,-5,50,8,18,12,21,1,28,33,-2,43,-10,100};
    EXPECT_EQ(tree_int.size(), 25);
    s21::Tree<double> tree_double{15.15,4.4,26.26,5.5,20.20,0,34.34,10.1,16.16,22.22,3.3,32.32,-5.5,50.50,8.8,18.18,12.12,21.21,1.1,28.28,33.33,-2.2,43.43,-10.1,100.1};
    EXPECT_EQ(tree_double.size(), 25);
    s21::Tree<std::string> tree_string{"What's", "up", "Vsauce", "Michael", "here", "!"};
    EXPECT_EQ(tree_string.size(), 6);
     s21::Tree<char> tree_char{'g','\0','4','a','\t','0','f','v','b','n','j','h','t','e'};
    EXPECT_EQ(tree_char.size(), 14);

    EXPECT_EQ(*(tree_int.begin()),-10);
    EXPECT_EQ(*(tree_int.end()),100);
    EXPECT_EQ(*(tree_double.begin()),-10.1);
    EXPECT_EQ(*(tree_double.end()),100.1);
    EXPECT_EQ(*(tree_string.begin()),"!");
    EXPECT_EQ(*(tree_string.end()),"up" );
    EXPECT_EQ(*(tree_char.begin()),'\0');
    EXPECT_EQ(*(tree_char.end()),'v');


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

    EXPECT_EQ(*(tree_int.begin()),1);
    EXPECT_EQ(*(tree_int.end()),21);
    EXPECT_EQ(*(tree_double.begin()),-5.5);
    EXPECT_EQ(*(tree_double.end()),50.5);
    EXPECT_EQ(*(tree_string.begin()),"Vsauce");
    EXPECT_EQ(*(tree_string.end()),"Vsauce" );
    EXPECT_EQ(*(tree_char.begin()),'\t');
    EXPECT_EQ(*(tree_char.end()),'g');


    tree_string.remove("Vsauce");
   EXPECT_THROW(*(tree_string.begin()),std::out_of_range);
}
TEST(TreeTest, iterator) {
    s21::Tree<int> tree_int{15,4,26,5,20,0,34,10,16,22,3,32,-5,50,8,18,12,21,1,28,33,-2,43,-10,100};
    EXPECT_EQ(tree_int.size(), 25);
    s21::Tree<double> tree_double{15.15,4.4,26.26,5.5,20.20,0,34.34,10.1,16.16,22.22,3.3,32.32,-5.5,50.50,8.8,18.18,12.12,21.21,1.1,28.28,33.33,-2.2,43.43,-10.1,100.1};
    EXPECT_EQ(tree_double.size(), 25);
    s21::Tree<std::string> tree_string{"What's", "up", "Vsauce", "Michael", "here", "!"};
    EXPECT_EQ(tree_string.size(), 6);
     s21::Tree<char> tree_char{'g','\0','4','a','\t','0','f','v','b','n','j','h','t','e'};
    EXPECT_EQ(tree_char.size(), 14);

    s21::Tree<int>::iterator it_int=tree_int.begin();
    s21::Tree<int>::constIterator cit_int(tree_int.end());
    EXPECT_EQ(*(it_int),-10);
    EXPECT_EQ(*cit_int,100);

    s21::Tree<double>::iterator it_double =tree_double.begin();
    s21::Tree<double>::iterator it_double_2 =it_double;
    s21::Tree<double>::iterator it_double_3(it_double);
    s21::Tree<double>::iterator it_double_4(tree_double.end());
    s21::Tree<double>::constIterator cit_double(it_double);
    s21::Tree<double>::constIterator cit_double_2(cit_double);
    s21::Tree<double>::constIterator cit_double_3(it_double_4);

    EXPECT_EQ(*(it_double),-10.1);
    EXPECT_EQ(*(it_double_2),-10.1);
    EXPECT_EQ(*(it_double_3),-10.1);
    EXPECT_EQ(*(cit_double),-10.1);
    EXPECT_EQ(*(cit_double_2),-10.1);

    it_int++;
    EXPECT_EQ(*(it_int),-5);
    it_int++;
    EXPECT_EQ(*(it_int),-2);
    it_int+=5;
    EXPECT_EQ(*(it_int),5);
    it_int-=2;
    EXPECT_EQ(*(it_int),3);
    it_int-=5;
    EXPECT_EQ(*(it_int),-10);
    it_int-=100;
    EXPECT_EQ(*(it_int),-10);
    it_int+=1000;
    EXPECT_EQ(*(it_int),100);

    s21::Tree<std::string>::iterator it_string;
    it_string=tree_string;
    EXPECT_EQ(*(it_string),"What's");
    EXPECT_EQ(it_double==it_double_2, true);
    EXPECT_EQ(it_double==it_double_3, true);
    EXPECT_EQ(it_double!=it_double_3, false);
    EXPECT_EQ(it_double!=it_double_4,true);
    EXPECT_EQ(it_double==it_double_4,false);
    EXPECT_EQ(cit_double==cit_double_2,true);
    EXPECT_EQ(cit_double==cit_double_3,false);

    s21::Tree<int>::iterator it_int_2;
    it_int_2=--it_int;
    EXPECT_EQ(*(it_int_2),50);
    EXPECT_EQ(*(it_int),50);
    EXPECT_EQ(it_int_2==it_int, true);
     it_int_2=it_int--;
     EXPECT_EQ(*(it_int_2),50);
     EXPECT_EQ(*(it_int),43);
     EXPECT_EQ(it_int_2==it_int, false);
}