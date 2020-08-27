# -*- coding: utf-8 -*-
# This file is auto-generated, don't edit it. Thanks.


class Client(object):
    """
    tea assert module
    """
    @staticmethod
    def equal(expect, actual, message):
        """
        Judge the expect result is equal to the actual result

        @param expect: the expect result

        @param actual: the actual result

        @type message: str
        @param message: the message which the assertion error is thrown with

        @return: void
        """
        assert expect == actual, message

    @staticmethod
    def map_eql(expect, actual, message):
        """
        Judge the expect map is equal to the actual map in deep and strict way

        @type expect: dict
        @param expect: the expect map

        @type actual: dict
        @param actual: the actual map

        @type message: str
        @param message: the message which the assertion error is thrown with

        @return: void
        """
        assert expect == actual, message

    @staticmethod
    def array_eql(expect, actual, message):
        """
        Judge the expect array is equal to the actual array in deep and strict way

        @type expect: list
        @param expect: the expect array

        @type actual: list
        @param actual: the actual array

        @type message: str
        @param message: the message which the assertion error is thrown with

        @return: void
        """
        assert expect == actual, message

    @staticmethod
    def fail(message):
        """
        throw assertion error with the message

        @type message: str
        @param message: message the message which the assertion error is thrown with

        @return: void
        """
        assert False, message

    @staticmethod
    def contains(actual, sub_str, message):
        """
        Judge the actual contains the subStr

        @type actual: str
        @param actual: the actual string

        @type sub_str: str
        @param sub_str: the substring

        @type message: str
        @param message: the message which the assertion error is thrown with

        @return: void
        """
        assert sub_str in actual, message
