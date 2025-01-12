#include <map>

#include "global_tests.h"

TEST(MapTest, defaultConstructor) {
  my_containers::map<const int, int> m;
  std::map<const int, int> std_m;

  EXPECT_EQ(m.size(), 0);
  EXPECT_EQ(m.empty(), true);
  EXPECT_EQ(std_m.size(), 0);
  EXPECT_EQ(std_m.empty(), true);
}
TEST(MapTest, SimpleTests) {
  my_containers::map<double, int> map_db_it_1{
      {555.55, 5}, {423.2, 2},   {1000, 0},     {-55.55, 6000},
      {-33.3, -5}, {-1000, 100}, {100100, 100}, {-5.5, 15}};
  std::map<double, int> map_db_it_2{{555.55, 5},    {423.2, 2},  {1000, 0},
                                    {-55.55, 6000}, {-33.3, -5}, {-1000, 100},
                                    {100100, 100},  {-5.5, 15}};
  my_containers::map<char, std::string> map_ch_st_1{
      std::pair<char, std::string>{'4', "Jazz"},
      {'\n', "I"},
      {'y', "played"},
      {'(', "with"},
      {'`', "Blues"},
      {'-', "brothers"},
      {'=', "like"},
      {'b', "Yoda"},
      {'d', "Wow"},
      {'c', "!"}};
  std::map<char, std::string> map_ch_st_2{
      std::pair<char, std::string>{'4', "Jazz"},
      {'\n', "I"},
      {'y', "played"},
      {'(', "with"},
      {'`', "Blues"},
      {'-', "brothers"},
      {'=', "like"},
      {'b', "Yoda"},
      {'d', "Wow"},
      {'c', "!"}};

  EXPECT_EQ(map_db_it_1.size(), 8);
  EXPECT_EQ(map_db_it_2.size(), 8);
  EXPECT_EQ(map_ch_st_1.size(), 10);
  EXPECT_EQ(map_ch_st_2.size(), 10);
  EXPECT_EQ(map_db_it_1.empty(), false);
  EXPECT_EQ(map_db_it_2.empty(), false);
  EXPECT_EQ(map_ch_st_1.empty(), false);
  EXPECT_EQ(map_ch_st_2.empty(), false);
  EXPECT_EQ(map_db_it_1.contains(-1000), true);
  EXPECT_EQ(*(map_db_it_1.begin()), 100);
  EXPECT_EQ(*(map_db_it_1.end()), 100);

  my_containers::map<double, int> map_db_it_3(std::move(map_db_it_1));
  std::map<double, int> map_db_it_4(std::move(map_db_it_2));
  my_containers::map<char, std::string> map_ch_st_3(std::move(map_ch_st_1));
  std::map<char, std::string> map_ch_st_4(std::move(map_ch_st_2));
  EXPECT_EQ(map_db_it_3.size(), 8);
  EXPECT_EQ(map_db_it_4.size(), 8);
  EXPECT_EQ(map_ch_st_3.size(), 10);
  EXPECT_EQ(map_ch_st_4.size(), 10);
  EXPECT_EQ(map_db_it_3.empty(), false);
  EXPECT_EQ(map_db_it_4.empty(), false);
  EXPECT_EQ(map_ch_st_3.empty(), false);
  EXPECT_EQ(map_ch_st_4.empty(), false);
  EXPECT_EQ(map_db_it_1.size(), 0);
  EXPECT_EQ(map_db_it_2.size(), 0);
  EXPECT_EQ(map_ch_st_1.size(), 0);
  EXPECT_EQ(map_ch_st_2.size(), 0);
  EXPECT_EQ(map_db_it_1.empty(), true);
  EXPECT_EQ(map_db_it_2.empty(), true);
  EXPECT_EQ(map_ch_st_1.empty(), true);
  EXPECT_EQ(map_ch_st_2.empty(), true);

  my_containers::map<double, int> map_db_it_5(map_db_it_3);
  std::map<double, int> map_db_it_6(map_db_it_4);
  my_containers::map<char, std::string> map_ch_st_5(map_ch_st_3);
  std::map<char, std::string> map_ch_st_6(map_ch_st_4);
  EXPECT_EQ(map_db_it_3.size(), 8);
  EXPECT_EQ(map_db_it_4.size(), 8);
  EXPECT_EQ(map_ch_st_3.size(), 10);
  EXPECT_EQ(map_ch_st_4.size(), 10);
  EXPECT_EQ(map_db_it_3.empty(), false);
  EXPECT_EQ(map_db_it_4.empty(), false);
  EXPECT_EQ(map_ch_st_3.empty(), false);
  EXPECT_EQ(map_ch_st_4.empty(), false);
  EXPECT_EQ(map_db_it_5.size(), 8);
  EXPECT_EQ(map_db_it_6.size(), 8);
  EXPECT_EQ(map_ch_st_5.size(), 10);
  EXPECT_EQ(map_ch_st_6.size(), 10);
  EXPECT_EQ(map_db_it_5.empty(), false);
  EXPECT_EQ(map_db_it_6.empty(), false);
  EXPECT_EQ(map_ch_st_5.empty(), false);
  EXPECT_EQ(map_ch_st_6.empty(), false);

  my_containers::map<double, int> map_db_it_7;
  std::map<double, int> map_db_it_8;
  my_containers::map<char, std::string> map_ch_st_7;
  std::map<char, std::string> map_ch_st_8;

  map_db_it_7 = std::move(map_db_it_1);
  map_db_it_8 = std::move(map_db_it_2);
  map_ch_st_7 = std::move(map_ch_st_1);
  map_ch_st_8 = std::move(map_ch_st_2);
  EXPECT_EQ(map_db_it_7.size(), 0);
  EXPECT_EQ(map_db_it_8.size(), 0);
  EXPECT_EQ(map_ch_st_7.size(), 0);
  EXPECT_EQ(map_ch_st_8.size(), 0);
  EXPECT_EQ(map_db_it_7.empty(), true);
  EXPECT_EQ(map_db_it_8.empty(), true);
  EXPECT_EQ(map_ch_st_7.empty(), true);
  EXPECT_EQ(map_ch_st_8.empty(), true);
  EXPECT_EQ(map_db_it_1.size(), 0);
  EXPECT_EQ(map_db_it_2.size(), 0);
  EXPECT_EQ(map_ch_st_1.size(), 0);
  EXPECT_EQ(map_ch_st_2.size(), 0);
  EXPECT_EQ(map_db_it_1.empty(), true);
  EXPECT_EQ(map_db_it_2.empty(), true);
  EXPECT_EQ(map_ch_st_1.empty(), true);
  EXPECT_EQ(map_ch_st_2.empty(), true);
  map_db_it_7 = map_db_it_1;
  map_db_it_8 = map_db_it_2;
  map_ch_st_7 = map_ch_st_1;
  map_ch_st_8 = map_ch_st_2;
  EXPECT_EQ(map_db_it_7.size(), 0);
  EXPECT_EQ(map_db_it_8.size(), 0);
  EXPECT_EQ(map_ch_st_7.size(), 0);
  EXPECT_EQ(map_ch_st_8.size(), 0);
  EXPECT_EQ(map_db_it_7.empty(), true);
  EXPECT_EQ(map_db_it_8.empty(), true);
  EXPECT_EQ(map_ch_st_7.empty(), true);
  EXPECT_EQ(map_ch_st_8.empty(), true);
  EXPECT_EQ(map_db_it_1.size(), 0);
  EXPECT_EQ(map_db_it_2.size(), 0);
  EXPECT_EQ(map_ch_st_1.size(), 0);
  EXPECT_EQ(map_ch_st_2.size(), 0);
  EXPECT_EQ(map_db_it_1.empty(), true);
  EXPECT_EQ(map_db_it_2.empty(), true);
  EXPECT_EQ(map_ch_st_1.empty(), true);
  EXPECT_EQ(map_ch_st_2.empty(), true);

  map_db_it_5 = map_db_it_7;
  map_db_it_6 = map_db_it_8;
  map_ch_st_5 = map_ch_st_7;
  map_ch_st_6 = map_ch_st_8;
  EXPECT_EQ(map_db_it_5.size(), 0);
  EXPECT_EQ(map_db_it_6.size(), 0);
  EXPECT_EQ(map_ch_st_5.size(), 0);
  EXPECT_EQ(map_ch_st_6.size(), 0);
  EXPECT_EQ(map_db_it_5.empty(), true);
  EXPECT_EQ(map_db_it_6.empty(), true);
  EXPECT_EQ(map_ch_st_5.empty(), true);
  EXPECT_EQ(map_ch_st_6.empty(), true);

  map_db_it_5 = std::move(map_db_it_3);
  map_db_it_6 = std::move(map_db_it_4);
  map_ch_st_5 = std::move(map_ch_st_3);
  map_ch_st_6 = std::move(map_ch_st_4);
  EXPECT_EQ(map_db_it_5.size(), 8);
  EXPECT_EQ(map_db_it_6.size(), 8);
  EXPECT_EQ(map_ch_st_5.size(), 10);
  EXPECT_EQ(map_ch_st_6.size(), 10);
  EXPECT_EQ(map_db_it_3.size(), 0);
  EXPECT_EQ(map_db_it_4.size(), 0);
  EXPECT_EQ(map_ch_st_3.size(), 0);
  EXPECT_EQ(map_ch_st_4.size(), 0);
  map_db_it_7 = map_db_it_5;
  map_db_it_8 = map_db_it_6;
  map_ch_st_7 = map_ch_st_5;
  map_ch_st_8 = map_ch_st_6;
  EXPECT_EQ(map_db_it_7.size(), 8);
  EXPECT_EQ(map_db_it_8.size(), 8);
  EXPECT_EQ(map_ch_st_7.size(), 10);
  EXPECT_EQ(map_ch_st_8.size(), 10);
  EXPECT_EQ(map_db_it_5.size(), 8);
  EXPECT_EQ(map_db_it_6.size(), 8);
  EXPECT_EQ(map_ch_st_5.size(), 10);
  EXPECT_EQ(map_ch_st_6.size(), 10);

  map_db_it_5.clear();
  map_db_it_6.clear();
  map_ch_st_5.clear();
  map_ch_st_6.clear();
  EXPECT_EQ(map_db_it_5.size(), 0);
  EXPECT_EQ(map_db_it_6.size(), 0);
  EXPECT_EQ(map_ch_st_5.size(), 0);
  EXPECT_EQ(map_ch_st_6.size(), 0);
  EXPECT_EQ(map_db_it_5.empty(), true);
  EXPECT_EQ(map_db_it_6.empty(), true);
  EXPECT_EQ(map_ch_st_5.empty(), true);
  EXPECT_EQ(map_ch_st_6.empty(), true);

  EXPECT_EQ(map_db_it_3.size(), 0);
  EXPECT_EQ(map_db_it_4.size(), 0);
  EXPECT_EQ(map_ch_st_3.size(), 0);
  EXPECT_EQ(map_ch_st_4.size(), 0);
  map_db_it_3.swap(map_db_it_7);
  map_db_it_4.swap(map_db_it_8);
  map_ch_st_3.swap(map_ch_st_7);
  map_ch_st_4.swap(map_ch_st_8);
  EXPECT_EQ(map_db_it_3.size(), 8);
  EXPECT_EQ(map_db_it_4.size(), 8);
  EXPECT_EQ(map_ch_st_3.size(), 10);
  EXPECT_EQ(map_ch_st_4.size(), 10);
  EXPECT_EQ(map_db_it_7.size(), 0);
  EXPECT_EQ(map_db_it_8.size(), 0);
  EXPECT_EQ(map_ch_st_7.size(), 0);
  EXPECT_EQ(map_ch_st_8.size(), 0);

  EXPECT_EQ(map_db_it_7.insert(std::pair<double, int>(55.55, 5)).second, true);
  EXPECT_EQ(map_db_it_7.insert(std::pair<double, int>(55.55, 5)).second, false);
  EXPECT_EQ(map_db_it_8.insert(std::pair<double, int>(55.55, 5)).second, true);
  EXPECT_EQ(map_db_it_8.insert(std::pair<double, int>(55.55, 5)).second, false);
  EXPECT_EQ(map_db_it_7.contains(55.55), true);
  EXPECT_EQ(map_db_it_7.contains(55.555), false);
  EXPECT_EQ(map_ch_st_7.insert('5', "Rock").second, true);
  EXPECT_EQ(map_ch_st_7.insert('5', "Rock").second, false);
  EXPECT_EQ(
      map_ch_st_8.insert(std::pair<char, std::string>('5', "Rock")).second,
      true);
  EXPECT_EQ(
      map_ch_st_8.insert(std::pair<char, std::string>('5', "Rock")).second,
      false);

  map_db_it_3.swap(map_db_it_7);
  map_db_it_4.swap(map_db_it_8);
  map_ch_st_3.swap(map_ch_st_7);
  map_ch_st_4.swap(map_ch_st_8);
  EXPECT_EQ(map_db_it_3.size(), 1);
  EXPECT_EQ(map_db_it_4.size(), 1);
  EXPECT_EQ(map_ch_st_3.size(), 1);
  EXPECT_EQ(map_ch_st_4.size(), 1);
  EXPECT_EQ(map_db_it_7.size(), 8);
  EXPECT_EQ(map_db_it_8.size(), 8);
  EXPECT_EQ(map_ch_st_7.size(), 10);
  EXPECT_EQ(map_ch_st_8.size(), 10);

  EXPECT_EQ(map_db_it_7.insert(std::pair<double, int>(55.55, 5)).second, true);
  EXPECT_EQ(map_db_it_8.insert(std::pair<double, int>(55.55, 5)).second, true);
  EXPECT_EQ(map_ch_st_7.insert('5', "Rock").second, true);
  EXPECT_EQ(
      map_ch_st_8.insert(std::pair<char, std::string>('5', "Rock")).second,
      true);

  map_db_it_3.merge(map_db_it_7);
  map_db_it_4.merge(map_db_it_8);
  map_ch_st_3.merge(map_ch_st_7);
  map_ch_st_4.merge(map_ch_st_8);
  EXPECT_EQ(map_db_it_3.size(), 9);
  EXPECT_EQ(map_db_it_4.size(), 9);
  EXPECT_EQ(map_ch_st_3.size(), 11);
  EXPECT_EQ(map_ch_st_4.size(), 11);
  EXPECT_EQ(map_db_it_7.size(), 1);
  EXPECT_EQ(map_db_it_8.size(), 1);
  EXPECT_EQ(map_ch_st_7.size(), 1);
  EXPECT_EQ(map_ch_st_8.size(), 1);

  my_containers::map<double, int>::iterator it_1 =
      map_db_it_7.insert_or_assign(55.55, 1000).first;
  std::map<double, int>::iterator it_2 =
      map_db_it_8.insert_or_assign(55.55, 1000).first;

  EXPECT_EQ(map_db_it_7.insert_or_assign(55.55, 1000).second, false);
  EXPECT_EQ(map_db_it_8.insert_or_assign(55.55, 1000).second, false);
  EXPECT_EQ(*it_1, 1000);
  map_db_it_7.erase(it_1);
  map_db_it_8.erase(it_2);
  EXPECT_EQ(map_db_it_7.size(), 0);
  EXPECT_EQ(map_db_it_8.size(), 0);

  EXPECT_EQ(map_ch_st_3['='], "like");
  EXPECT_EQ(map_db_it_3[555.555], 0);
}

TEST(Map, test_create_int) {
  my_containers::map<int, int> my_map1;

  my_map1.insert(5, 22);
  my_map1.insert(9, 33);
  my_map1.insert(12, 44);
  my_map1.insert(456, 555);

  EXPECT_EQ(my_map1[5], 22);
  EXPECT_EQ(my_map1[9], 33);
  EXPECT_EQ(my_map1[12], 44);
  EXPECT_EQ(my_map1[456], 555);
}
TEST(Map, test_insert1) {
  my_containers::map<int, int> my_map1;

  std::pair<int, int> w1 = {5, 22};
  std::pair<int, int> w2 = {9, 33};
  std::pair<int, int> w3 = {12, 44};
  std::pair<int, int> w4 = {456, 555};

  my_map1.insert(w1);
  my_map1.insert(w2);
  my_map1.insert(w3);
  my_map1.insert(w4);

  EXPECT_EQ(my_map1[5], 22);
  EXPECT_EQ(my_map1[9], 33);
  EXPECT_EQ(my_map1[12], 44);
  EXPECT_EQ(my_map1[456], 555);
}

TEST(Map, test_insert_or_assign) {
  my_containers::map<int, int> my_map1{{1, 11}, {2, 22}, {3, 33}};

  my_map1.insert_or_assign(1, 66);
  my_map1.insert_or_assign(4, 44);

  EXPECT_EQ(my_map1[1], 66);
  EXPECT_EQ(my_map1[2], 22);
  EXPECT_EQ(my_map1[3], 33);
  EXPECT_EQ(my_map1[4], 44);
}

TEST(Map, test_create_double) {
  my_containers::map<double, double> my_map1;

  my_map1.insert(5.5, 2e12);
  my_map1.insert(9.7, 3e-4);
  my_map1.insert(12.1, 44);
  my_map1.insert(456.55, 555);

  EXPECT_EQ(my_map1[5.5], 2e12);
  EXPECT_EQ(my_map1[9.7], 3e-4);
  EXPECT_EQ(my_map1[12.1], 44);
  EXPECT_EQ(my_map1[456.55], 555);
}

TEST(Map, test_create_char) {
  my_containers::map<int, char> my_map1;

  my_map1.insert(5, '2');
  my_map1.insert(9, '\0');
  my_map1.insert(12, 'e');
  my_map1.insert(456, ' ');

  EXPECT_EQ(my_map1[5], '2');
  EXPECT_EQ(my_map1[9], '\0');
  EXPECT_EQ(my_map1[12], 'e');
  EXPECT_EQ(my_map1[456], ' ');
}

TEST(Map, test_empty) {
  my_containers::map<int, int> my_map1;
  std::map<int, int> std_map1;

  EXPECT_EQ(my_map1.empty(), std_map1.empty());
}

TEST(Map, test_copy_constructor) {
  my_containers::map<int, int> my_map1;

  my_map1.insert(5, 50);
  my_map1.insert(9, 12);
  my_map1.insert(12, 44);

  my_containers::map<int, int> my_map2(my_map1);

  EXPECT_EQ(my_map1[5], my_map2[5]);
  EXPECT_EQ(my_map1[9], my_map2[9]);
  EXPECT_EQ(my_map1[12], my_map2[12]);
}

TEST(Map, test_move_constructor) {
  my_containers::map<int, int> my_map1;

  my_map1.insert(5, 50);
  my_map1.insert(9, 12);
  my_map1.insert(12, 44);

  my_containers::map<int, int> my_map2(std::move(my_map1));

  EXPECT_EQ(50, my_map2[5]);
  EXPECT_EQ(12, my_map2[9]);
  EXPECT_EQ(44, my_map2[12]);
  EXPECT_EQ(1, my_map1.empty());
}

TEST(Map, test_init_list_constructor) {
  my_containers::map<int, int> my_map1{
      {-4, 222}, {6, 333}, {1, 5676554}, {2, 4}};
  std::map<int, int> std_map1{{-4, 222}, {6, 333}, {1, 5676554}, {2, 4}};

  EXPECT_EQ(my_map1[-4], std_map1[-4]);
  EXPECT_EQ(my_map1[6], std_map1[6]);
  EXPECT_EQ(my_map1[1], std_map1[1]);
  EXPECT_EQ(my_map1[2], std_map1[2]);
}

TEST(Map, test_copy_assign) {
  my_containers::map<int, int> my_map1;
  my_containers::map<int, int> my_map2;

  my_map1.insert(5, 50);
  my_map1.insert(9, 12);
  my_map1.insert(12, 44);

  my_map2 = my_map1;

  EXPECT_EQ(my_map1[5], my_map2[5]);
  EXPECT_EQ(my_map1[9], my_map2[9]);
  EXPECT_EQ(my_map1[12], my_map2[12]);
}

TEST(Map, test_move_assign) {
  my_containers::map<int, int> my_map1;
  my_containers::map<int, int> my_map2;

  my_map1.insert(5, 50);
  my_map1.insert(9, 12);
  my_map1.insert(12, 44);

  my_map2 = std::move(my_map1);

  EXPECT_EQ(50, my_map2[5]);
  EXPECT_EQ(12, my_map2[9]);
  EXPECT_EQ(44, my_map2[12]);
  EXPECT_EQ(1, my_map1.empty());
}

TEST(Map, test_swap) {
  my_containers::map<int, int> my_map1{{1, 11}, {2, 22}, {3, 33}};
  my_containers::map<int, int> my_map2{{-1, -11}, {-2, -22}, {-3, -33}};

  my_map1.swap(my_map2);

  EXPECT_EQ(my_map1[-1], -11);
  EXPECT_EQ(my_map1[-2], -22);
  EXPECT_EQ(my_map1[-3], -33);
  EXPECT_EQ(my_map2[1], 11);
  EXPECT_EQ(my_map2[2], 22);
  EXPECT_EQ(my_map2[3], 33);
}

TEST(Map, iterator_operator) {
  my_containers::map<int, int> my_map1{{1, 1}, {2, 2}, {3, 3}};

  my_containers::map<int, int>::iterator my_iter;
  my_containers::map<int, int>::const_iterator my_c_iter = my_map1.cend();
  int i = 1;
  my_c_iter = my_map1.cbegin();

  for (my_iter = my_map1.begin(); my_iter != my_map1.end(); ++my_iter, ++i) {
    EXPECT_EQ(*my_iter, i);
  }
  my_iter = my_map1.begin();
  my_containers::map<int, int>::iterator my_iter2 = my_map1.begin();

  EXPECT_EQ(my_iter == my_iter2, 1);
  EXPECT_EQ(my_iter != my_iter2, 0);
}

TEST(Map, test_size) {
  my_containers::map<int, int> my_map1;

  my_map1.insert(5, 44);
  my_map1.insert(9, 55);
  my_map1.insert(12, 66);
  my_map1.insert(456, 77);

  EXPECT_EQ(my_map1.size(), 4);
}
/*
PC related value
TEST(Map, test_max_size) {
  my_containers::map<int, int> my_map1;
  std::map<int, int> std_map1;

  EXPECT_EQ(my_map1.max_size(), std_map1.max_size());
}
*/
TEST(Map, test_clear) {
  my_containers::map<int, int> my_map1;

  my_map1.insert(5, 44);
  my_map1.insert(9, 55);
  my_map1.insert(12, 66);
  my_map1.insert(456, 77);

  my_map1.clear();

  EXPECT_EQ(my_map1.empty(), 1);
}

TEST(Map, test_erase1) {
  my_containers::map<int, int> my_map1;
  my_map1.insert(5, 44);

  my_containers::map<int, int>::iterator my_iter = my_map1.begin();
  my_map1.erase(my_iter);

  EXPECT_EQ(my_map1.empty(), 1);

  my_map1.insert(5, 44);
  my_map1.insert(9, 55);
  my_map1.insert(12, 66);
  my_map1.insert(456, 77);

  my_iter = my_map1.begin();
  my_map1.erase(my_iter);
  my_iter = my_map1.begin();
  EXPECT_EQ(*my_iter, 55);
}

TEST(Map, test_erase2) {
  my_containers::map<int, int> my_map1;
  my_map1.insert(5, 5);
  my_map1.insert(-4, -4);

  my_containers::map<int, int>::iterator my_iter;

  my_iter = my_map1.begin();
  ++my_iter;
  my_map1.erase(my_iter);

  EXPECT_EQ(my_map1.size(), 1);
}

TEST(Map, test_merge) {
  my_containers::map<int, int> my_map1{{1, 11}, {2, 22}, {3, 33}};
  my_containers::map<int, int> my_map2{{-1, -11}, {-2, -22}, {-3, -33}};

  my_map1.merge(my_map2);

  EXPECT_EQ(my_map1.contains(-1), 1);
  EXPECT_EQ(my_map1.contains(-2), 1);
  EXPECT_EQ(my_map1.contains(-3), 1);
}

TEST(Map, test_contains) {
  my_containers::map<int, int> my_map1{{1, 11}, {2, 22}, {3, 33}};

  EXPECT_EQ(my_map1.contains(1), 1);
  EXPECT_EQ(my_map1.contains(44), 0);
}

TEST(Map, test_bracket) {
  my_containers::map<int, int> my_map1{{1, 11}, {2, 22}, {3, 33}};

  EXPECT_EQ(my_map1[1], 11);
  EXPECT_EQ(my_map1[0], 0);
}

TEST(Map, test_at) {
  my_containers::map<int, int> my_map1{{1, 11}, {2, 22}, {3, 33}};

  EXPECT_EQ(my_map1.at(1), 11);
  EXPECT_ANY_THROW(my_map1.at(55));
}

TEST(Map, test_insert_many) {
  my_containers::map<int, int> ms{{1, 11}, {2, 22}, {3, 33}};

  my_containers::map<int, int>::iterator iter;

  std::pair<int, int> p1 = {4, 44};
  std::pair<int, int> p2 = {5, 55};
  std::pair<int, int> p3 = {6, 66};
  std::pair<int, int> p4 = {7, 77};

  ms.insert_many(p1, p2, p3, p4);
  iter = ms.end();

  EXPECT_EQ(*iter, 77);
  EXPECT_EQ(ms.size(), 7);
}