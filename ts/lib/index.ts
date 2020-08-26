/**
 * tea assert module
 */
import * as $tea from '@alicloud/tea-typescript';
import assert from 'assert';

export default class Assert {

  /**
   * Judge the expect result is equal to the actual result
   * @param expect the expect result
   * @param actual the actual result
   * @param message the message which the assertion error is thrown with
   * @return void
   */
  static equal(expect: any, actual: any, message: string): void {
    assert.strictEqual(expect, actual, message);
  }

  /**
   * Judge the expect map is equal to the actual map in deep and strict way
   * @param expect the expect map
   * @param actual the actual map
   * @param message the message which the assertion error is thrown with
   * @return void
   */
  static mapEql(expect: { [key: string]: any }, actual: { [key: string]: any }, message: string): void {
    assert.deepStrictEqual(actual, expect, message);
  }

  /**
   * Judge the expect array is equal to the actual array in deep and strict way
   * @param expect the expect array
   * @param actual the actual array
   * @param message the message which the assertion error is thrown with
   * @return void
   */
  static arrayEql(expect: any[], actual: any[], message: string): void {
    assert.deepStrictEqual(actual, expect, message);
  }

  /**
   * throw assertion error with the message
   * @param message message the message which the assertion error is thrown with
   * @return void
   */
  static fail(message: string): void {
    assert.fail(message);
  }

  /**
   * Judge the actual contains the subStr
   * @param actual the actual string
   * @param subStr the substring
   * @param message the message which the assertion error is thrown with
   * @return void
   */
  static contains(actual: string, subStr: string, message: string): void {
    if (!actual.includes(subStr)) {
      throw new Error(message);
    };
  }

}
