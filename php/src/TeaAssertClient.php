<?php

// This file is auto-generated, don't edit it. Thanks.

namespace Alibabacloud\TeaAssert;

use PHPUnit\Framework\Assert;

/**
 * tea assert module.
 */
class TeaAssertClient
{
    /**
     * Judge the expect result is equal to the actual result.
     *
     * @param mixed  $expect  the expect result
     * @param mixed  $actual  the actual result
     * @param string $message the message which the assertion error is thrown with
     */
    public static function equal($expect, $actual, $message)
    {
        Assert::assertTrue($expect === $actual, $message);
    }

    /**
     * Judge the expect map is equal to the actual map in deep and strict way.
     *
     * @param array  $expect  the expect map
     * @param array  $actual  the actual map
     * @param string $message the message which the assertion error is thrown with
     */
    public static function mapEql($expect, $actual, $message)
    {
        Assert::assertTrue(\is_array($expect) && \is_array($actual), $message);
        $expect = new Dot($expect);
        $actual = new Dot($actual);
        $equal  = array_diff_assoc(
            $expect->flatten(),
            $actual->flatten()
        ) == array_diff_assoc(
                    $actual->flatten(),
                    $expect->flatten()
                );
        Assert::assertTrue($equal, $message);
    }

    /**
     * Judge the expect array is equal to the actual array in deep and strict way.
     *
     * @param array  $expect  the expect array
     * @param array  $actual  the actual array
     * @param string $message the message which the assertion error is thrown with
     */
    public static function arrayEql($expect, $actual, $message)
    {
        $equal = array_diff($expect, $actual) == array_diff($actual, $expect);
        Assert::assertTrue($equal, $message);
    }

    /**
     * throw assertion error with the message.
     *
     * @param string $message message the message which the assertion error is thrown with
     */
    public static function fail($message)
    {
        Assert::assertTrue(false, $message);
    }

    /**
     * Judge the actual contains the subStr.
     *
     * @param string $actual  the actual string
     * @param string $subStr  the substring
     * @param string $message the message which the assertion error is thrown with
     */
    public static function contains($actual, $subStr, $message)
    {
        Assert::assertTrue(false !== strpos($actual, $subStr));
    }
}
