// This file is auto-generated, don't edit it. Thanks.

#ifndef DARABONBA_ASSERT_H_
#define DARABONBA_ASSERT_H_

#include <boost/algorithm/cxx11/any_of.hpp>
#include <boost/any.hpp>
#include <iostream>
#include <map>
#include <vector>

#include <memory>
#include <type_traits>

template <class T> struct is_shared_ptr : std::false_type {};

template <class T> struct is_shared_ptr<std::shared_ptr<T>> : std::true_type {};

using namespace std;

namespace Darabonba_Assert {
class Client {
public:
  template <class T1, class T2>
  static void equal(shared_ptr<T1> expect, shared_ptr<T2> actual,
                    shared_ptr<string> message) {
    string msg =
        !message ? "Assertion Error equal: expect == actual" : *message;
    if (typeid(T1) != typeid(T2)) {
      boost::throw_exception(runtime_error(msg));
    }
    boost::any a = boost::any(expect);
    boost::any b = boost::any(actual);

    shared_ptr<T1> source = boost::any_cast<shared_ptr<T1>>(a);
    shared_ptr<T1> target = boost::any_cast<shared_ptr<T1>>(b);
    if (*source != *target) {
      boost::throw_exception(runtime_error(msg));
    }
  };

  static void mapEql(shared_ptr<map<string, boost::any>> expect,
                     shared_ptr<map<string, boost::any>> actual,
                     shared_ptr<string> message);

  static void arrayEql(shared_ptr<vector<boost::any>> expect,
                       shared_ptr<vector<boost::any>> actual,
                       shared_ptr<string> message);

  static void fail(shared_ptr<string> message);

  static void contains(shared_ptr<string> actual, shared_ptr<string> subStr,
                       shared_ptr<string> message);

  Client(){};
};
} // namespace Darabonba_Assert

#endif
