// This file is auto-generated, don't edit it. Thanks.

#ifndef DARABONBA_ASSERT_H_
#define DARABONBA_ASSERT_H_

#include <boost/any.hpp>
#include <iostream>
#include <map>
#include <vector>


using namespace std;

namespace Darabonba_Assert {
class Client {
public:
  template<class T>
  static void equal(T expect, T actual,
                shared_ptr<string> message)
  {
    string msg;
    if (!message) {
      msg = "Assertion Error equal: expect == actual";
    } else {
      msg = *message;
    }

    if (expect != actual) {
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
