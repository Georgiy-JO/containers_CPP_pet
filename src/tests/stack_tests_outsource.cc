

#include <stack>

#include "global_tests.h"
// #include "../containers/stack/stack.hpp"

// OutSource Tests

TEST(stack, case1) {
  my_containers::Stack<int> my_stack_int;
  my_containers::Stack<double> my_stack_double;
  my_containers::Stack<std::string> my_stack_string;

  EXPECT_EQ(my_stack_int.size(), 0U);
  EXPECT_THROW(my_stack_int.top(), std::out_of_range);
  EXPECT_THROW(my_stack_int.pop(), std::out_of_range);

  EXPECT_EQ(my_stack_double.size(), 0U);
  EXPECT_THROW(my_stack_double.top(), std::out_of_range);
  EXPECT_THROW(my_stack_double.pop(), std::out_of_range);

  EXPECT_EQ(my_stack_string.size(), 0U);
  EXPECT_THROW(my_stack_string.top(), std::out_of_range);
  EXPECT_THROW(my_stack_string.pop(), std::out_of_range);
}

TEST(stack, case2) {
  my_containers::Stack<int> my_stack_int{1, 4, 8, 9, 1};
  my_containers::Stack<double> my_stack_double{1.4, 4.8, 8.9, 9.1, 1.1};
  my_containers::Stack<std::string> my_stack_string{"Hello", ",", "world", "!", "!!"};

  EXPECT_EQ(my_stack_int.size(), 5U);
  EXPECT_EQ(my_stack_int.top(), 1);

  EXPECT_EQ(my_stack_double.size(), 5U);
  EXPECT_EQ(my_stack_double.top(), 1.1);

  EXPECT_EQ(my_stack_string.size(), 5U);
  EXPECT_EQ(my_stack_string.top(), "!!");
}

TEST(stack, case3) {
  my_containers::Stack<int> my_stack_ref_int{1, 4, 8, 9, 1};
  my_containers::Stack<int> my_stack_res_int(my_stack_ref_int);

  my_containers::Stack<double> my_stack_ref_double{1.4, 4.8, 8.9, 9.1, 1.1};
  my_containers::Stack<double> my_stack_res_double(my_stack_ref_double);

  my_containers::Stack<std::string> my_stack_ref_string{"Hello", ",", "world", "!",
                                               "!!"};
  my_containers::Stack<std::string> my_stack_res_string(my_stack_ref_string);

  EXPECT_EQ(my_stack_res_int.size(), 5U);
  EXPECT_EQ(my_stack_res_int.top(), 1);
  EXPECT_EQ(my_stack_ref_int.size(), 5U);
  EXPECT_EQ(my_stack_ref_int.top(), 1);

  EXPECT_EQ(my_stack_res_double.size(), 5U);
  EXPECT_EQ(my_stack_res_double.top(), 1.1);

  EXPECT_EQ(my_stack_res_string.size(), 5U);
  EXPECT_EQ(my_stack_res_string.top(), "!!");
}

TEST(stack, case4) {
  my_containers::Stack<int> my_stack_ref_int{1, 4, 8, 9, 1};
  my_containers::Stack<int> my_stack_res_int = my_stack_ref_int;

  my_containers::Stack<double> my_stack_ref_double{1.4, 4.8, 8.9, 9.1, 1.1};
  my_containers::Stack<double> my_stack_res_double = my_stack_ref_double;

  my_containers::Stack<std::string> my_stack_ref_string{"Hello", ",", "world", "!",
                                               "!!"};
  my_containers::Stack<std::string> my_stack_res_string = my_stack_ref_string;

  EXPECT_EQ(my_stack_res_int.size(), 5U);
  EXPECT_EQ(my_stack_res_int.top(), 1);

  EXPECT_EQ(my_stack_res_double.size(), 5U);
  EXPECT_EQ(my_stack_res_double.top(), 1.1);

  EXPECT_EQ(my_stack_res_string.size(), 5U);
  EXPECT_EQ(my_stack_res_string.top(), "!!");
}

TEST(stack, case5) {
  my_containers::Stack<int> my_stack_ref_int{1, 4, 8, 9, 1};
  my_containers::Stack<int> my_stack_res_int = std::move(my_stack_ref_int);

  my_containers::Stack<double> my_stack_ref_double{1.4, 4.8, 8.9, 9.1, 1.1};
  my_containers::Stack<double> my_stack_res_double = std::move(my_stack_ref_double);

  my_containers::Stack<std::string> my_stack_ref_string{"Hello", ",", "world", "!",
                                               "!!"};
  my_containers::Stack<std::string> my_stack_res_string =
      std::move(my_stack_ref_string);

  EXPECT_EQ(my_stack_ref_int.size(), 0U);
  EXPECT_EQ(my_stack_res_int.size(), 5U);
  EXPECT_EQ(my_stack_res_int.top(), 1);

  EXPECT_EQ(my_stack_ref_double.size(), 0U);
  EXPECT_EQ(my_stack_res_double.size(), 5U);
  EXPECT_EQ(my_stack_res_double.top(), 1.1);

  EXPECT_EQ(my_stack_ref_string.size(), 0U);
  EXPECT_EQ(my_stack_res_string.size(), 5U);
  EXPECT_EQ(my_stack_res_string.top(), "!!");
}

TEST(stack, case6) {
  my_containers::Stack<int> my_stack_ref_int{1, 4, 8, 9, 1};
  my_containers::Stack<int> my_stack_res_int;
  my_stack_res_int = std::move(my_stack_ref_int);

  my_containers::Stack<double> my_stack_ref_double{1.4, 4.8, 8.9, 9.1, 1.1};
  my_containers::Stack<double> my_stack_res_double;
  my_stack_res_double = std::move(my_stack_ref_double);

  my_containers::Stack<std::string> my_stack_ref_string{"Hello", ",", "world", "!",
                                               "!!"};
  my_containers::Stack<std::string> my_stack_res_string;
  my_stack_res_string = std::move(my_stack_ref_string);

  EXPECT_EQ(my_stack_ref_int.size(), 0U);
  EXPECT_EQ(my_stack_res_int.size(), 5U);
  EXPECT_EQ(my_stack_res_int.top(), 1);

  EXPECT_EQ(my_stack_ref_double.size(), 0U);
  EXPECT_EQ(my_stack_res_double.size(), 5U);
  EXPECT_EQ(my_stack_res_double.top(), 1.1);

  EXPECT_EQ(my_stack_ref_string.size(), 0U);
  EXPECT_EQ(my_stack_res_string.size(), 5U);
  EXPECT_EQ(my_stack_res_string.top(), "!!");
}

TEST(stack, case7) {
  int n = 1e4;
  my_containers::Stack<int> st = {};
  std::stack<int> orig_st = {};
  for (int i = 0; i < n; i++) {
    st.push(i);
    orig_st.push(i);
  }
  EXPECT_EQ(st.size(), orig_st.size());
  st.pop();
  st.pop();
  orig_st.pop();
  orig_st.pop();
  EXPECT_EQ(st.size(), orig_st.size());
  int top = st.top();
  int orig_top = orig_st.top();
  EXPECT_EQ(top, orig_top);
}

TEST(STACK_EMPTY, case1) {
  my_containers::Stack<int> my_stack_int{1, 4, 8, 9, 1};
  my_containers::Stack<double> my_stack_double{1.4, 4.8, 8.9, 9.1, 1.1};
  my_containers::Stack<std::string> my_stack_string{"Hello", ",", "world", "!", "!!"};

  EXPECT_EQ(my_stack_int.empty(), 0);
  EXPECT_EQ(my_stack_double.empty(), 0);
  EXPECT_EQ(my_stack_string.empty(), 0);
}

TEST(STACK_EMPTY, case2) {
  my_containers::Stack<int> my_stack_int;
  my_containers::Stack<double> my_stack_double;
  my_containers::Stack<std::string> my_stack_string;

  EXPECT_EQ(my_stack_int.empty(), 1);
  EXPECT_EQ(my_stack_double.empty(), 1);
  EXPECT_EQ(my_stack_string.empty(), 1);
}

TEST(STACK_SIZE, case1) {
  my_containers::Stack<int> my_stack_int{1, 4, 8, 9, 1};
  my_containers::Stack<double> my_stack_double{1.4, 4.8, 8.9, 9.1, 1.1};
  my_containers::Stack<std::string> my_stack_string{"Hello", ",", "world", "!", "!!"};

  EXPECT_EQ(my_stack_int.size(), 5U);
  EXPECT_EQ(my_stack_double.size(), 5U);
  EXPECT_EQ(my_stack_string.size(), 5U);
}

TEST(STACK_SIZE, case2) {
  my_containers::Stack<int> my_stack_int;
  my_containers::Stack<double> my_stack_double;
  my_containers::Stack<std::string> my_stack_string;

  EXPECT_EQ(my_stack_int.size(), 0U);
  EXPECT_EQ(my_stack_double.size(), 0U);
  EXPECT_EQ(my_stack_string.size(), 0U);
}

TEST(STACK_TOP, case1) {
  my_containers::Stack<int> my_stack_int{1, 4, 8, 9, 1};
  my_containers::Stack<double> my_stack_double{1.4, 4.8, 8.9, 9.1, 1.1};
  my_containers::Stack<std::string> my_stack_string{"Hello", ",", "world", "!", "!!"};

  EXPECT_EQ(my_stack_int.top(), 1);
  EXPECT_EQ(my_stack_double.top(), 1.1);
  EXPECT_EQ(my_stack_string.top(), "!!");
}

TEST(STACK_TOP, case2) {
  my_containers::Stack<int> my_stack_int;
  my_containers::Stack<double> my_stack_double;
  my_containers::Stack<std::string> my_stack_string;

  EXPECT_THROW(my_stack_int.top(), std::out_of_range);
  EXPECT_THROW(my_stack_double.top(), std::out_of_range);
  EXPECT_THROW(my_stack_string.top(), std::out_of_range);
}

TEST(STACK_PUSH, case1) {
  my_containers::Stack<int> my_stack_int{1, 4, 8, 9, 1};
  my_containers::Stack<double> my_stack_double{1.4, 4.8, 8.9, 9.1, 1.1};
  my_containers::Stack<std::string> my_stack_string{"Hello", ",", "world", "!", "!!"};

  my_stack_int.push(255);
  my_stack_double.push(255.0);
  my_stack_string.push("255");

  EXPECT_EQ(my_stack_int.top(), 255);
  EXPECT_EQ(my_stack_double.top(), 255.0);
  EXPECT_EQ(my_stack_string.top(), "255");
}

TEST(STACK_PUSH, case2) {
  my_containers::Stack<int> my_stack_int;
  my_containers::Stack<double> my_stack_double;
  my_containers::Stack<std::string> my_stack_string;

  my_stack_int.push(255);
  my_stack_double.push(255.0);
  my_stack_string.push("255");

  EXPECT_EQ(my_stack_int.top(), 255);
  EXPECT_EQ(my_stack_double.top(), 255.0);
  EXPECT_EQ(my_stack_string.top(), "255");
}

TEST(STACK_POP, case1) {
  my_containers::Stack<int> my_stack_int{1, 4, 8, 9, 1};
  my_containers::Stack<double> my_stack_double{1.4, 4.8, 8.9, 9.1, 1.1};
  my_containers::Stack<std::string> my_stack_string{"Hello", ",", "world", "!", "!!"};

  my_stack_int.pop();
  my_stack_double.pop();
  my_stack_string.pop();

  EXPECT_EQ(my_stack_int.top(), 9);
  EXPECT_EQ(my_stack_double.top(), 9.1);
  EXPECT_EQ(my_stack_string.top(), "!");
}

TEST(STACK_POP, case2) {
  my_containers::Stack<int> my_stack_int;
  my_containers::Stack<double> my_stack_double;
  my_containers::Stack<std::string> my_stack_string;

  EXPECT_THROW(my_stack_int.pop(), std::out_of_range);
  EXPECT_THROW(my_stack_double.pop(), std::out_of_range);
  EXPECT_THROW(my_stack_string.pop(), std::out_of_range);
}

TEST(STACK_SWAP, case1) {
  my_containers::Stack<int> my_stack_ref_int{1, 4, 8, 9, 1};
  my_containers::Stack<int> my_stack_res_int;

  my_containers::Stack<double> my_stack_ref_double{1.4, 4.8, 8.9, 9.1, 1.1};
  my_containers::Stack<double> my_stack_res_double;

  my_containers::Stack<std::string> my_stack_ref_string{"Hello", ",", "world", "!",
                                               "!!"};
  my_containers::Stack<std::string> my_stack_res_string;

  my_stack_ref_int.swap(my_stack_res_int);
  my_stack_ref_double.swap(my_stack_res_double);
  my_stack_ref_string.swap(my_stack_res_string);

  EXPECT_EQ(my_stack_ref_int.size(), 0U);
  EXPECT_EQ(my_stack_res_int.size(), 5U);
  EXPECT_EQ(my_stack_res_int.top(), 1);

  EXPECT_EQ(my_stack_ref_double.size(), 0U);
  EXPECT_EQ(my_stack_res_double.size(), 5U);
  EXPECT_EQ(my_stack_res_double.top(), 1.1);

  EXPECT_EQ(my_stack_ref_string.size(), 0U);
  EXPECT_EQ(my_stack_res_string.size(), 5U);
  EXPECT_EQ(my_stack_res_string.top(), "!!");
}

TEST(STACK_SWAP, case2) {
  my_containers::Stack<int> my_stack_ref_int{1, 4, 8, 9, 1};
  my_containers::Stack<int> my_stack_res_int{12, 13, 14};

  my_containers::Stack<double> my_stack_ref_double{1.4, 4.8, 8.9, 9.1, 1.1};
  my_containers::Stack<double> my_stack_res_double{13.0};

  my_containers::Stack<std::string> my_stack_ref_string{"Hello", ",", "world", "!",
                                               "!!"};
  my_containers::Stack<std::string> my_stack_res_string{"14", "15"};

  my_stack_ref_int.swap(my_stack_res_int);
  my_stack_ref_double.swap(my_stack_res_double);
  my_stack_ref_string.swap(my_stack_res_string);

  EXPECT_EQ(my_stack_ref_int.size(), 3U);
  EXPECT_EQ(my_stack_ref_int.top(), 14);
  EXPECT_EQ(my_stack_res_int.size(), 5U);
  EXPECT_EQ(my_stack_res_int.top(), 1);

  EXPECT_EQ(my_stack_ref_double.size(), 1U);
  EXPECT_EQ(my_stack_ref_double.top(), 13.0);
  EXPECT_EQ(my_stack_res_double.size(), 5U);
  EXPECT_EQ(my_stack_res_double.top(), 1.1);

  EXPECT_EQ(my_stack_ref_string.size(), 2U);
  EXPECT_EQ(my_stack_ref_string.top(), "15");
  EXPECT_EQ(my_stack_res_string.size(), 5U);
  EXPECT_EQ(my_stack_res_string.top(), "!!");
}