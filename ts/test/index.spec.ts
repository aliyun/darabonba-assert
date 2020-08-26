'use strict';
import expect from 'expect.js';
import Assert from '../lib/index';
import 'mocha';

describe('Tea assert typescript check', function () {
  it('equal should be okay', function () {
    expect(() => {
      let map1 = { a: 1, b: "2" };
      let map2 = { a: 1, b: "2" };
      Assert.equal(map1, map2, 'tea assert equal fail')
    }).to.throwException(function (e) { // get the exception object
      expect(e.message).to.be(`tea assert equal fail`);
    });

    expect(() => {
      let string1 = '1';
      let number1 = 1;
      Assert.equal(string1, number1, 'tea assert equal fail')
    }).to.throwException(function (e) { // get the exception object
      expect(e.message).to.be(`tea assert equal fail`);
    });

    expect(() => {
      let map1 = { a: 1, b: "2" };
      let map2 = map1;
      Assert.equal(map1, map2, 'tea assert equal fail');
      let number1 = 1;
      let number2 = 1;
      Assert.equal(number1, number2, 'tea assert equal fail');
      let string1 = '1';
      let string2 = '1';
      Assert.equal(string1, string2, 'tea assert equal fail');
      let bool1 = true;
      let bool2 = true;
      Assert.equal(bool1, bool2, 'tea assert equal fail');
    }).to.not.throwException();
  });

  it('mapEqual should ok', function () {
    expect(() => {
      let map1 = { a: 1, b: "2" };
      let map2 = { a: 1, b: 2 };
      Assert.mapEql(map1, map2, 'tea assert equal fail')
    }).to.throwException(function (e) { // get the exception object
      expect(e.message).to.be(`tea assert equal fail`);
    });

    expect(() => {
      let map1 = { a: 1, b: "2" };
      let map2 = { a: 1, b: "2" };
      Assert.mapEql(map1, map2, 'tea assert equal fail')
    }).to.not.throwException();
  });

  it('arrayEqual should ok', function () {
    expect(() => {
      let array1 = [1, "2"];
      let array2 = [1, 2];
      Assert.arrayEql(array1, array2, 'tea assert equal fail')
    }).to.throwException(function (e) { // get the exception object
      expect(e.message).to.be(`tea assert equal fail`);
    });

    expect(() => {
      let array1 = [1, 2];
      let array2 = [1, 2];
      Assert.arrayEql(array1, array2, 'tea assert equal fail')
    }).to.not.throwException();
  });

  it('contains should ok', function () {
    expect(() => {
      Assert.contains('origin message', 'originMessage', 'new message')
    }).to.throwException(function (e) {
      expect(e.message).to.be('new message');
    });

    expect(() => {
      Assert.contains('originMessage', 'originMessage', 'new message')
    }).to.not.throwException();
  });

});
