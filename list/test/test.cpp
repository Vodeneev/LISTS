#include "gtest.h"
#include "List.h"
#include "Iterator.h"

TEST(List, can_create_list)
{
	ASSERT_NO_THROW(List s());
}

TEST(List, can_get_size)
{
	List st(3);
	EXPECT_EQ(st.Size(), 3);
}

TEST(List, can_insert)
{
	List st(3);
	for (Iterator it = st.begin(); it != st.end(); ++it) {
		*it = 1;
	}
	st.insert(2, st.Head());
	Iterator itres(st.Head());
	EXPECT_EQ(*(++itres), 2);
}

TEST(List, can_delete1)
{
	int i = 0;
	List st(3);
	for (Iterator it = st.begin(); it != st.end(); ++it) {
		*it = i;
		i++;
	}
	st.Delete(st.Head());
	Iterator itres(st.Head());
	EXPECT_EQ((*itres), 1);
}

TEST(List, can_delete2)
{
	List st(3);
	st.Delete(st.Head());
	EXPECT_EQ(st.Size(), 2);
}

TEST(List, search)
{
	int i = 0;
	List st(3);
	for (Iterator it = st.begin(); it != st.end(); ++it) {
		*it = i;
		i++;
	}
	EXPECT_EQ(st.search(1), 2);
}
TEST(List, medium)
{
	int i = 0;
	List st(3);
	for (Iterator it = st.begin(); it != st.end(); ++it) {
		*it = i;
		i++;
	}
	EXPECT_EQ(st.medium(), 1);
}

// òåñòû íà èòåðàòîð

TEST(Iterator, plus_plus_left)
{
	List st(3);
	int i = 0;
	for (Iterator it = st.begin(); it != st.end(); ++it) {
		*it = i;
		i++;
	}
	Iterator resit(st.Head());
	++resit;
	EXPECT_EQ(*resit, 1);
}

TEST(Iterator, plus_plus_right)
{
	int i = 0;
	List st(3);
	for (Iterator it = st.begin(); it != st.end(); ++it) {
		*it = i;
		i++;
	}
	Iterator resit1(st.Head());
	Iterator resit2(st.Head());
	resit2 = resit1++;
	EXPECT_EQ(*resit2, 0);
}

TEST(Iterator, ravno) {
	Iterator i1 = NULL;
	Iterator i2 = NULL;
	EXPECT_TRUE(i1 == i2);
}

TEST(Iterator, neravno) {
	Iterator i1 = NULL;
	Iterator i2 = NULL;
	EXPECT_TRUE(!(i1 != i2));
}

TEST(List, can_copy)
{
  List st(3);
  for (Iterator it = st.begin(); it != st.end(); ++it) {
    *it = 1;
  }
  List st2(st);
  EXPECT_EQ(st.Head()->data, st2.Head()->data);
}
