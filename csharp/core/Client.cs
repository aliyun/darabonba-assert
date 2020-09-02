/**
 * tea assert module
 */
// This file is auto-generated, don't edit it. Thanks.

using System;
using System.Collections;
using System.Collections.Generic;

using AlibabaCloud.TeaAssert.Exceptions;

using Xunit;

namespace AlibabaCloud.TeaAssert
{
    public class Client
    {

        /**
         * Judge the expect result is equal to the actual result
         * @param expect the expect result
         * @param actual the actual result
         * @param message the message which the assertion error is thrown with
         * @return void
         */
        public static void Equal(object expect, object actual, string message)
        {
            try
            {
                Assert.StrictEqual(expect, actual);
            }
            catch (Exception e)
            {
                throw new TeaAssertException(message, e);
            }
        }

        /**
         * Judge the expect map is equal to the actual map in deep and strict way
         * @param expect the expect map
         * @param actual the actual map
         * @param message the message which the assertion error is thrown with
         * @return void
         */
        public static void MapEql(IDictionary expect, IDictionary actual, string message)
        {
            try
            {
                Assert.Equal(expect, actual);
            }
            catch (Exception e)
            {
                throw new TeaAssertException(message, e);
            }
        }

        /**
         * Judge the expect array is equal to the actual array in deep and strict way
         * @param expect the expect array
         * @param actual the actual array
         * @param message the message which the assertion error is thrown with
         * @return void
         */
        public static void ArrayEql(IList expect, IList actual, string message)
        {
            try
            {
                Assert.Equal(expect, actual);
            }
            catch (Exception e)
            {
                throw new TeaAssertException(message, e);
            }
        }

        /**
         * throw assertion error with the message
         * @param message message the message which the assertion error is thrown with
         * @return void
         */
        public static void Fail(string message)
        {
            throw new TeaAssertException(message);
        }

        /**
        * Judge the actual contains the subStr
        * @param actual the actual string
        * @param subStr the substring
        * @param message the message which the assertion error is thrown with
        * @return void
        */
        public static void Contains(string actual, string subStr, string message)
        {
            try
            {
                Assert.Contains(subStr, actual);
            }
            catch (Exception e)
            {
                throw new TeaAssertException(message, e);
            }
        }

    }
}
