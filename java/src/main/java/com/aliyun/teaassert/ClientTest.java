package com.aliyun.teaassert;

import org.junit.jupiter.api.Test;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

import org.junit.jupiter.api.Assertions;

public class ClientTest {

    @Test
    public static void testEqual() {
        String origin = null;
        String test = null;
        try {
            Client.equal(1, '1', "test 1 failed");
        } catch (Exception e) {
            origin = e.getMessage();
        }
        try {
            Assertions.assertEquals(1, '1', "test 1 failed");
        } catch (Exception e) {
            test = e.getMessage();
        }
        Assertions.assertEquals(origin, test);
    }

    @Test
    public static void testMapEql() {
        Map<String, Integer> a = new HashMap<String, Integer>();
        a.put("A", 1);
        Map<String, Integer> b = new HashMap<String, Integer>();
        b.put("A", 1);
        String origin = null;
        String test = null;
        try {
            Client.mapEql(a, b, "test mapEql failed");
        } catch (Exception e) {
            origin = e.getMessage();
        }
        try {
            Assertions.assertSame(a, b, "test mapEql failed");
        } catch (Exception e) {
            test = e.getMessage();
        }
        Assertions.assertEquals(origin, test);
    }

    @Test
    public static void testArrayEql() {
        List<String> a = new ArrayList<>();
        a.add("A");
        List<String> b = new ArrayList<>();
        b.add("B");
        String origin = null;
        String test = null;
        try {
            Client.arrayEql(a, b, "test arrayEql failed");
        } catch (Exception e) {
            origin = e.getMessage();
        }
        try {
            Assertions.assertSame(a, b, "test arrayEql failed");
        } catch (Exception e) {
            test = e.getMessage();
        }
        Assertions.assertEquals(origin, test);
    }

    @Test
    public static void testFail() {
        String origin = null;
        String test = null;
        try {
            Client.fail("false");
        } catch (Exception e) {
            origin = e.getMessage();
        }
        try {
            Assertions.fail("false");
        } catch (Exception e) {
            test = e.getMessage();
        }
        Assertions.assertEquals(origin, test);
    }
}