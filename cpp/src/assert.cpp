// This file is auto-generated, don't edit it. Thanks.

#include <boost/any.hpp>
#include <boost/throw_exception.hpp>
#include <darabonba/assert.hpp>
#include <map>
#include <vector>

using namespace std;

using namespace Darabonba_Assert;

template <typename T> shared_ptr<T> cast_any(boost::any value) {
  if (typeid(shared_ptr<T>) == value.type()) {
    return boost::any_cast<shared_ptr<T>>(value);
  } else if (typeid(T) == value.type()) {
    return make_shared<T>(boost::any_cast<T>(value));
  }
}

template <typename T> bool isinstance(boost::any value) {
  if (typeid(shared_ptr<T>) == value.type()) {
    return true;
  } else if (typeid(T) == value.type()) {
    return true;
  }
  return false;
}

void Assert(boost::any val1, boost::any val2) {
  if (val1.empty() || val2.empty()) {
    throw exception();
  }
  shared_ptr<string> msg;
  if (isinstance<map<string, boost::any>>(val1) &&
      isinstance<map<string, boost::any>>(val2)) {
    map<string, boost::any> m1 = *cast_any<map<string, boost::any>>(val1);
    map<string, boost::any> m2 = *cast_any<map<string, boost::any>>(val2);
    for (const auto &it : m1) {
      Assert(it.second, m2[it.first]);
    }
  } else if (isinstance<vector<boost::any>>(val1) &&
             isinstance<vector<boost::any>>(val2)) {
    vector<boost::any> v1 = *cast_any<vector<boost::any>>(val1);
    vector<boost::any> v2 = *cast_any<vector<boost::any>>(val2);
    for (int i = 0; i < v1.size(); i++) {
      Assert(v1[i], v2[i]);
    }
  } else if (isinstance<string>(val1) && isinstance<string>(val2)) {
    Darabonba_Assert::Client::equal(cast_any<string>(val1),
                                    cast_any<string>(val2), msg);
  } else if (isinstance<int>(val1) && isinstance<int>(val2)) {
    Darabonba_Assert::Client::equal(cast_any<int>(val1), cast_any<int>(val2),
                                    msg);
  } else if (isinstance<long>(val1) && isinstance<long>(val2)) {
    Darabonba_Assert::Client::equal(cast_any<long>(val1), cast_any<long>(val2),
                                    msg);
  } else if (isinstance<float>(val1) && isinstance<float>(val2)) {
    Darabonba_Assert::Client::equal(cast_any<float>(val1),
                                    cast_any<float>(val2), msg);
  } else if (isinstance<double>(val1) && isinstance<double>(val2)) {
    Darabonba_Assert::Client::equal(cast_any<double>(val1),
                                    cast_any<double>(val2), msg);
  } else if (isinstance<bool>(val1) && isinstance<bool>(val2)) {
    Darabonba_Assert::Client::equal(cast_any<bool>(val1), cast_any<bool>(val2),
                                    msg);
  } else if (isinstance<bool>(val1) && isinstance<bool>(val2)) {
    Darabonba_Assert::Client::equal(cast_any<bool>(val1), cast_any<bool>(val2),
                                    msg);
  } else if (isinstance<const char *>(val1) && isinstance<const char *>(val2)) {
    Darabonba_Assert::Client::equal(cast_any<const char *>(val1),
                                    cast_any<const char *>(val2), msg);
  } else {
    throw exception();
  }
}

void Darabonba_Assert::Client::mapEql(
    shared_ptr<map<string, boost::any>> expect,
    shared_ptr<map<string, boost::any>> actual, shared_ptr<string> message) {
  string msg;
  if (!message) {
    msg = "Assertion Error mapEql: expect == actual";
  } else {
    msg = *message;
  }

  if (expect && actual) {
    try {
      for (const auto &it : *expect) {
        Assert(it.second, (*actual)[it.first]);
      }
      for (const auto &it : *actual) {
        Assert(it.second, (*expect)[it.first]);
      }
    } catch (std::exception &) {
      boost::throw_exception(runtime_error(msg));
    }
  }
}

void Darabonba_Assert::Client::arrayEql(shared_ptr<vector<boost::any>> expect,
                                        shared_ptr<vector<boost::any>> actual,
                                        shared_ptr<string> message) {
  string msg;
  if (!message) {
    msg = "Assertion Error arrayEql: expect == actual";
  } else {
    msg = *message;
  }

  if (expect && actual) {
    bool exp_loop = true;
    if (actual->size() > expect->size()) {
      exp_loop = false;
    }

    try {
      if (exp_loop) {
        for (int i = 0; i < expect->size(); i++) {
          Assert((*actual)[i], (*expect)[i]);
        }
      } else {
        for (int i = 0; i < actual->size(); i++) {
          Assert((*actual)[i], (*expect)[i]);
        }
      }
    } catch (std::exception &) {
      boost::throw_exception(runtime_error(msg));
    }
  }
}

void Darabonba_Assert::Client::fail(shared_ptr<string> message) {
  string msg;
  if (!message) {
    msg = "Assertion Error fail.";
  } else {
    msg = *message;
  }
  boost::throw_exception(runtime_error(msg));
}

void Darabonba_Assert::Client::contains(shared_ptr<string> actual,
                                        shared_ptr<string> subStr,
                                        shared_ptr<string> message) {
  string msg;
  if (!message) {
    msg = "Assertion Error contains.";
  } else {
    msg = *message;
  }

  if (actual && subStr) {
    if (actual->find(*subStr) == std::string::npos) {
      boost::throw_exception(runtime_error(msg));
    }
  }
}
