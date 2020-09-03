/**
 * tea assert module
 */
// This file is auto-generated, don't edit it. Thanks.

using System.Collections;
using System.Collections.Generic;

using AlibabaCloud.TeaAssert.Comparers;
using AlibabaCloud.TeaAssert.Exceptions;

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
            var comparer = EqualityComparer<object>.Default;

            if (!comparer.Equals(expect, actual))
                throw new TeaAssertException(message);
        }

        /**
         * Judge the expect map is equal to the actual map in deep and strict way
         * @param expect the expect map
         * @param actual the actual map
         * @param message the message which the assertion error is thrown with
         * @return void
         */
        public static void MapEql<T>(T expect, T actual, string message) where T : IDictionary
        {
            var comparer = new AssertEqualityComparer<T>();

            Equal(expect, actual, comparer, message);
        }

        /**
         * Judge the expect array is equal to the actual array in deep and strict way
         * @param expect the expect array
         * @param actual the actual array
         * @param message the message which the assertion error is thrown with
         * @return void
         */
        public static void ArrayEql<T>(T expect, T actual, string message) where T : IList
        {
            var comparer = new AssertEqualityComparer<T>();

            Equal(expect, actual, comparer, message);
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
            if (actual == null || actual.IndexOf(subStr) < 0)
            {
                throw new TeaAssertException(message);
            }
        }

        internal static void Equal<T>(T expected, T actual, IEqualityComparer<T> comparer, string message)
        {

            var expectedAsIEnum = expected as IEnumerable;
            var actualAsIEnum = actual as IEnumerable;

            // If both are IEnumerable (or null), see if we got an AssertEqualityComparer<T>, so that
            // we can invoke it to get the mismatched index.
            if ((expectedAsIEnum != null && (actual == null || actualAsIEnum != null)) ||
                (actualAsIEnum != null && expected == null))
            {
                var aec = comparer as AssertEqualityComparer<T>;
                int? mismatchedIndex;

                if (aec != null && !aec.Equals(expected, actual, out mismatchedIndex))
                {
                    if (mismatchedIndex.HasValue)
                        throw new TeaAssertException(message);
                    else
                        throw new TeaAssertException(message);
                }
            }

            if (!comparer.Equals(expected, actual))
                throw new TeaAssertException(message);
        }

    }
}
