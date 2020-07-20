// This file is auto-generated, don't edit it. Thanks.
/**
 * tea assert module
 */
package client

import (
	"encoding/json"
	"errors"
	"fmt"
	"path/filepath"
	"reflect"
	"runtime"
	"strings"

	"github.com/alibabacloud-go/tea/tea"
)

/**
 * Judge the expect result is equal to the actual result
 * @param expect the expect result
 * @param actual the actual result
 * @param message the message which the assertion error is thrown with
 * @return void
 */
func Equal(expect interface{}, actual interface{}, message *string) error {
	equal := reflect.DeepEqual(expect, actual)
	pc, file, line, _ := runtime.Caller(1)
	entity := runtime.FuncForPC(pc)
	file = filepath.Base(file)
	if !equal {
		str := fmt.Sprintf("Error Trace:  %s:%d\nTest:         %s\nmessage:      %s\n", file, line, entity.Name(), *message)
		return errors.New(str)
	}
	return nil
}

/**
 * Judge the expect map is equal to the actual map in deep and strict way
 * @param expect the expect map
 * @param actual the actual map
 * @param message the message which the assertion error is thrown with
 * @return void
 */
func MapEql(expect map[string]interface{}, actual map[string]interface{}, message *string) error {
	var exp interface{}
	var act interface{}
	pc, file, line, _ := runtime.Caller(1)
	entity := runtime.FuncForPC(pc)
	file = filepath.Base(file)
	buf, err := json.Marshal(expect)
	if err != nil {
		str := fmt.Sprintf("Error Trace:  %s:%d\nTest:         %s\nmessage:      %s\n", file, line, entity.Name(), err.Error())
		return errors.New(str)
	}
	json.Unmarshal(buf, &exp)
	buf, err = json.Marshal(actual)
	if err != nil {
		str := fmt.Sprintf("Error Trace:  %s:%d\nTest:         %s\nmessage:      %s\n", file, line, entity.Name(), err.Error())
		return errors.New(str)
	}
	json.Unmarshal(buf, &act)
	equal := reflect.DeepEqual(exp, act)
	if !equal {
		str := fmt.Sprintf("Error Trace:  %s:%d\nTest:         %s\nmessage:      %s\n", file, line, entity.Name(), *message)
		return errors.New(str)
	}
	return nil
}

/**
 * Judge the expect array is equal to the actual array in deep and strict way
 * @param expect the expect array
 * @param actual the actual array
 * @param message the message which the assertion error is thrown with
 * @return void
 */
func ArrayEql(expect []interface{}, actual []interface{}, message *string) error {
	var exp interface{}
	var act interface{}
	pc, file, line, _ := runtime.Caller(1)
	entity := runtime.FuncForPC(pc)
	file = filepath.Base(file)
	buf, err := json.Marshal(expect)
	if err != nil {
		str := fmt.Sprintf("Error Trace:  %s:%d\nTest:         %s\nmessage:      %s\n", file, line, entity.Name(), err.Error())
		return errors.New(str)
	}
	json.Unmarshal(buf, &exp)
	buf, err = json.Marshal(actual)
	if err != nil {
		str := fmt.Sprintf("Error Trace:  %s:%d\nTest:         %s\nmessage:      %s\n", file, line, entity.Name(), err.Error())
		return errors.New(str)
	}
	json.Unmarshal(buf, &act)
	equal := reflect.DeepEqual(exp, act)
	if !equal {
		str := fmt.Sprintf("Error Trace:  %s:%d\nTest:         %s\nmessage:      %s\n", file, line, entity.Name(), *message)
		return errors.New(str)
	}
	return nil
}

/**
 * throw assertion error with the message
 * @param message message the message which the assertion error is thrown with
 * @return void
 */
func Fail(message *string) error {
	pc, file, line, _ := runtime.Caller(1)
	entity := runtime.FuncForPC(pc)
	file = filepath.Base(file)
	str := fmt.Sprintf("Error Trace:  %s:%d\nTest:         %s\nmessage:      %s\n", file, line, entity.Name(), *message)
	return errors.New(str)
}

/**
 * Judge the actual contains the subStr
 * @param actual the actual string
 * @param subStr the substring
 * @param message the message which the assertion error is thrown with
 * @return void
 */
func Contains(contains *string, subStr *string, message *string) error {
	pc, file, line, _ := runtime.Caller(1)
	entity := runtime.FuncForPC(pc)
	file = filepath.Base(file)
	if ok := strings.Contains(tea.StringValue(contains), tea.StringValue(subStr)); !ok {
		str := fmt.Sprintf("Error Trace:  %s:%d\nTest:         %s\nmessage:      %s\n", file, line, entity.Name(), *message)
		return errors.New(str)
	}
	return nil
}
