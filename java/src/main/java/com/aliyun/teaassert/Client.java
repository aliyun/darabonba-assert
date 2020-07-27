// This file is auto-generated, don't edit it. Thanks.
package com.aliyun.teaassert;

public class Client {

    /**
     * Judge the expect result is equal to the actual result
     *
     * @param expect  the expect result
     * @param actual  the actual result
     * @param message the message which the assertion error is thrown with
     * @return void
     */
    public static void equal(Object expect, Object actual, String message) throws Exception {
        assert expect == actual : message;
    }

    /**
     * Judge the expect map is equal to the actual map in deep and strict way
     *
     * @param expect  the expect map
     * @param actual  the actual map
     * @param message the message which the assertion error is thrown with
     * @return void
     */
    public static void mapEql(java.util.Map<String, ?> expect, java.util.Map<String, ?> actual,
                              String message) throws Exception {
        assert expect.equals(actual) : message;
    }

    /**
     * Judge the expect array is equal to the actual array in deep and strict way
     *
     * @param expect  the expect array
     * @param actual  the actual array
     * @param message the message which the assertion error is thrown with
     * @return void
     */
    public static void arrayEql(java.util.List<?> expect, java.util.List<?> actual, String message)
            throws Exception {
        assert expect.equals(actual) : message;
    }

    /**
     * throw assertion error with the message
     *
     * @param message message the message which the assertion error is thrown with
     * @return void
     */
    public static void fail(String message) throws Exception {
        assert false : message;
    }

    /**
     * Judge the actual contains the subStr
     *
     * @param actual  the actual string
     * @param subStr  the substring
     * @param message the message which the assertion error is thrown with
     * @return void
     */
    public static void contains(String actual, String subStr, String message) throws Exception {
        assert actual.contains(subStr) : message;
    }

}