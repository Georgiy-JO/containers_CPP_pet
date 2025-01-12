
#include "global_tests.h"
// #include "../containers/queue/queue.h"
#include <queue>
#include <vector>

TEST(Queue_Constructor, Default) {
  my_containers::queue<int> int_q;
  my_containers::queue<double> double_q;

  EXPECT_EQ(int_q.empty(), 1);
  EXPECT_EQ(double_q.empty(), 1);
}

TEST(Queue_Constructor, Initializer_List) {
  my_containers::queue<int> int_q = {1, 2, 3};

  EXPECT_EQ(int_q.empty(), 0);
}

TEST(Queue_Constructor, Copy) {
  my_containers::queue<int> int_q1 = {1, 2, 3};
  my_containers::queue<int> int_q2(int_q1);

  EXPECT_EQ(int_q2.empty(), 0);
}

TEST(Queue_Constructor, Move) {
  my_containers::queue<int> int_q1 = {1, 2, 3};
  my_containers::queue<int> int_q2(std::move(int_q1));

  EXPECT_EQ(int_q2.empty(), 0);
  EXPECT_EQ(int_q1.empty(), 1);
}

TEST(Queue_Constructor, Operator_eq) {
  my_containers::queue<int> int_q1 = {1, 2, 3};
  my_containers::queue<int> int_q2;
  int_q2 = std::move(int_q1);

  EXPECT_EQ(int_q2.empty(), 0);
}

// element access

TEST(Queue_Element_Access, Front) {
  my_containers::queue<int> int_q = {1, 2, 3};

  EXPECT_EQ(int_q.front(), 1);
}

TEST(Queue_Element_Access, Front_Empty) {
  my_containers::queue<int> int_q;

  EXPECT_THROW(int_q.front(), std::out_of_range);
}

TEST(Queue_Element_Access, Back) {
  my_containers::queue<int> int_q = {1, 2, 3};

  EXPECT_EQ(int_q.back(), 3);
}

TEST(Queue_Element_Access, Back_Empty) {
  my_containers::queue<int> int_q;

  EXPECT_THROW(int_q.back(), std::out_of_range);
}

// capacity

TEST(Queue_Capacity, Empty) {
  my_containers::queue<int> int_q1 = {1, 2, 3};
  my_containers::queue<int> int_q2;

  EXPECT_EQ(int_q1.empty(), 0);
  EXPECT_EQ(int_q2.empty(), 1);
}

TEST(Queue_Capacity, Size) {
  my_containers::queue<int> int_q1 = {1, 2, 3};
  my_containers::queue<int> int_q2;

  EXPECT_EQ(int_q1.size(), 3);
  EXPECT_EQ(int_q2.size(), 0);
}

// modifiers

TEST(Queue_Modifiers, Push) {
  my_containers::queue<int> int_q = {1, 2, 3};
  int_q.push(7);

  EXPECT_EQ(int_q.size(), 4);
  EXPECT_EQ(int_q.back(), 7);
}

TEST(Queue_Modifiers, Push_Empty) {
  my_containers::queue<int> int_q;
  int_q.push(7);

  EXPECT_EQ(int_q.empty(), 0);
  EXPECT_EQ(int_q.size(), 1);
}

TEST(Queue_Modifiers, Pop) {
  my_containers::queue<int> int_q = {1, 2, 3};
  int_q.pop();

  EXPECT_EQ(int_q.front(), 2);
}

TEST(Queue_Modifiers, Pop_Empty) {
  my_containers::queue<int> int_q;

  EXPECT_THROW(int_q.pop(), std::out_of_range);
}

TEST(Queue_Modifiers, Swap) {
  my_containers::queue<int> int_q1 = {1, 2, 3};
  my_containers::queue<int> int_q2;

  EXPECT_EQ(int_q1.empty(), 0);
  EXPECT_EQ(int_q2.empty(), 1);

  int_q1.swap(int_q2);

  EXPECT_EQ(int_q1.empty(), 1);
  EXPECT_EQ(int_q2.empty(), 0);
}

TEST(Queue_Insert_Many, Insert_Many_Back) {
  my_containers::queue<int> int_q = {1, 2, 3};
  int_q.insert_many_back(4, 5, 6);

  EXPECT_EQ(int_q.size(), 6);
  EXPECT_EQ(int_q.back(), 6);
}