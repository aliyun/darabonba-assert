using System;
using System.Collections.Generic;

using AlibabaCloud.TeaAssert;
using AlibabaCloud.TeaAssert.Exceptions;

using Xunit;

namespace tests
{
    public class ClientTest
    {
        [Fact]
        public void Test_Equl()
        {
            Dictionary<string, object> map1 = new Dictionary<string, object>
            { { "a", 1 },
                { "b", "2" }
            };
            Dictionary<string, object> map2 = new Dictionary<string, object>
            { { "a", 1 },
                { "b", "2" }
            };
            Assert.Equal("tea assert equal fail", Assert.Throws<TeaAssertException>(() =>
            {
                Client.Equal(map1, map2, "tea assert equal fail");
            }).Message);

            Assert.Equal("tea assert equal fail", Assert.Throws<TeaAssertException>(() =>
            {
                Client.Equal("1", 1, "tea assert equal fail");
            }).Message);

            Dictionary<string, object> map3 = map1;
            Client.Equal(map1, map3, "tea assert equal fail");

            int number1 = 1;
            int number2 = 1;
            Client.Equal(number1, number2, "tea assert equal fail");

            bool bool1 = true;
            bool bool2 = true;
            Client.Equal(bool1, bool2, "tea assert equal fail");
        }

        [Fact]
        public void Test_Fail()
        {
            bool ok = true;
            try
            {
                Client.Fail("should failed");
            }
            catch (Exception ex)
            {
                ok = false;
            }

            Client.Equal(false, ok, "shold failed");
        }

        [Fact]
        public void Test_MapEql()
        {
            Dictionary<string, object> map1 = new Dictionary<string, object>
            { { "a", 1 },
                { "b", "2" }
            };
            Dictionary<string, object> map2 = new Dictionary<string, object>
            { { "a", 1 },
                { "b", 2 }
            };
            Assert.Equal("tea assert equal fail", Assert.Throws<TeaAssertException>(() =>
            {
                Client.MapEql(map1, map2, "tea assert equal fail");
            }).Message);

            Dictionary<string, object> map3 = new Dictionary<string, object>
            { { "a", 1 },
                { "b", "2" }
            };
            Client.MapEql(map1, map3, "tea assert equal fail");
        }

        [Fact]
        public void Test_ArrayEql()
        {
            List<object> array1 = new List<object> { 1, "2" };
            List<object> array2 = new List<object> { 1, 2 };
            Assert.Equal("tea assert equal fail", Assert.Throws<TeaAssertException>(() =>
            {
                Client.ArrayEql(array1, array2, "tea assert equal fail");
            }).Message);

            List<object> array3 = new List<object> { 1, 2 };

            Client.ArrayEql(array2, array3, "tea assert equal fail");
        }

        [Fact]
        public void Test_Contains()
        {
            string a = "hello world";
            string b = "world";

            Client.Contains(a, b, "test string contains failed");

            Assert.Equal("test string contains failed", Assert.Throws<TeaAssertException>(() =>
            {
                Client.Contains(a, "wr", "test string contains failed");
            }).Message);
        }

    }
}
