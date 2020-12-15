#include "gtest/gtest.h"
#include <boost/exception/current_exception_cast.hpp>
#include <darabonba/assert.hpp>

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}

TEST(tests_Client, test_equal) {
  Darabonba_Assert::Client::equal(
      make_shared<string>("s"),
      make_shared<string>("s"),
      make_shared<string>("msg")
  );
  Darabonba_Assert::Client::equal(
      make_shared<int>(1),
      make_shared<int>(1),
      make_shared<string>("test 1 failed")
  );
  try {
    Darabonba_Assert::Client::equal(make_shared<string>("s1"),
                                    make_shared<string>("s2"),
                                    make_shared<string>("string not equal"));
    assert(false);
  } catch (boost::exception &e) {
    string msg = boost::current_exception_cast<std::runtime_error>()->what();
    ASSERT_EQ("string not equal", msg);
  }

  try {
    Darabonba_Assert::Client::equal(
        make_shared<int>(1),
        make_shared<string>("1"),
        make_shared<string>("test 1 failed")
    );
    assert(false);
  } catch (boost::exception &e) {
    string msg = boost::current_exception_cast<std::runtime_error>()->what();
    ASSERT_EQ("test 1 failed", msg);
  }
}

TEST(tests_Client, test_mapEql) {
  shared_ptr<map<string, boost::any>> m1 = make_shared<map<string, boost::any>>(map<string, boost::any>({
                                                                                                            {"k1", 1},
                                                                                                            {"k2",
                                                                                                             string("v1")},
                                                                                                            {"k3", 0.1}
                                                                                                        }));
  shared_ptr<map<string, boost::any>> m2 = make_shared<map<string, boost::any>>(map<string, boost::any>({
                                                                                                            {"k1", 1},
                                                                                                            {"k2",
                                                                                                             string("v1")},
                                                                                                            {"k3", 0.1}
                                                                                                        }));

  Darabonba_Assert::Client::mapEql(m1, m2, make_shared<string>("msg"));

  shared_ptr<map<string, boost::any>> m3 = make_shared<map<string, boost::any>>(map<string, boost::any>({
                                                                                                            {"k1", 1},
                                                                                                            {"k2",
                                                                                                             string("v3")},
                                                                                                            {"k3", 0.1}
                                                                                                        }));
  shared_ptr<map<string, boost::any>> m4 = make_shared<map<string, boost::any>>(map<string, boost::any>({
                                                                                                            {"k1", 1},
                                                                                                            {"k2",
                                                                                                             string("v4")},
                                                                                                            {"k3", 0.1}
                                                                                                        }));
  try {
    Darabonba_Assert::Client::mapEql(m3, m4, make_shared<string>("msg"));
    assert(false);
  } catch (boost::exception &e) {
    string msg = boost::current_exception_cast<std::runtime_error>()->what();
    ASSERT_EQ("msg", msg);
  }

  shared_ptr<map<string, boost::any>> m5 = make_shared<map<string, boost::any>>(map<string, boost::any>({
                                                                                                            {"k1", 1},
                                                                                                            {"k2",
                                                                                                             string("v1")},
                                                                                                            {"k3", 0.1},
                                                                                                            {"k4", m3}
                                                                                                        }));
  shared_ptr<map<string, boost::any>> m6 = make_shared<map<string, boost::any>>(map<string, boost::any>({
                                                                                                            {"k1", 1},
                                                                                                            {"k2",
                                                                                                             string("v1")},
                                                                                                            {"k3", 0.1},
                                                                                                            {"k4", m4}
                                                                                                        }));
  try {
    Darabonba_Assert::Client::mapEql(m5, m6, make_shared<string>("msg"));
    assert(false);
  } catch (boost::exception &e) {
    string msg = boost::current_exception_cast<std::runtime_error>()->what();
    ASSERT_EQ("msg", msg);
  }
}

TEST(tests_Client, test_arrayEql) {
  shared_ptr<vector<boost::any>> v1 = make_shared<vector<boost::any>>(vector<boost::any>(
      {1, 0.1, string("v")}
  ));
  shared_ptr<vector<boost::any>> v2 = make_shared<vector<boost::any>>(vector<boost::any>(
      {1, 0.1, string("v")}
  ));
  Darabonba_Assert::Client::arrayEql(v1, v2, make_shared<string>("msg"));

  shared_ptr<vector<boost::any>> v3 = make_shared<vector<boost::any>>(vector<boost::any>(
      {1, 0.2, string("v")}
  ));
  shared_ptr<vector<boost::any>> v4 = make_shared<vector<boost::any>>(vector<boost::any>(
      {1, 0.1, string("v")}
  ));
  try {
    Darabonba_Assert::Client::arrayEql(v3, v4, make_shared<string>("msg"));
    assert(false);
  } catch (boost::exception &e) {
    string msg = boost::current_exception_cast<std::runtime_error>()->what();
    ASSERT_EQ("msg", msg);
  }

  shared_ptr<vector<boost::any>> v5 = make_shared<vector<boost::any>>(vector<boost::any>(
      {1, 0.1, string("v"), v3}
  ));
  shared_ptr<vector<boost::any>> v6 = make_shared<vector<boost::any>>(vector<boost::any>(
      {1, 0.1, string("v"), v4}
  ));
  try {
    Darabonba_Assert::Client::arrayEql(v5, v6, make_shared<string>("msg"));
    assert(false);
  } catch (boost::exception &e) {
    string msg = boost::current_exception_cast<std::runtime_error>()->what();
    ASSERT_EQ("msg", msg);
  }
}

TEST(tests_Client, test_fail) {
  try {
    Darabonba_Assert::Client::fail(make_shared<string>("msg"));
    assert(false);
  } catch (boost::exception &e) {
    string msg = boost::current_exception_cast<std::runtime_error>()->what();
    ASSERT_EQ("msg", msg);
  }
}

TEST(tests_Client, test_contains) {
  Darabonba_Assert::Client::contains(
      make_shared<string>("hello world"),
      make_shared<string>("hello"),
      make_shared<string>("msg")
  );

  try {
    Darabonba_Assert::Client::contains(
        make_shared<string>("world"),
        make_shared<string>("hello"),
        make_shared<string>("msg")
    );
    assert(false);
  } catch (boost::exception &e) {
    string msg = boost::current_exception_cast<std::runtime_error>()->what();
    ASSERT_EQ("msg", msg);
  }
}
