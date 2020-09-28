package client

import (
	"testing"

	"github.com/alibabacloud-go/tea/tea"
	"github.com/alibabacloud-go/tea/utils"
)

func TestEqual(t *testing.T) {
	err := Equal(tea.String("a"), tea.String("a"), tea.String("hasdfs"))
	utils.AssertNil(t, err)

	err = Equal(tea.String("a"), tea.String("b"), tea.String("hasdfs"))
	utils.AssertEqual(t, err.Error(), "Error Trace:  client_test.go:14\nTest:         github.com/alibabacloud-go/darabonba-assert/client.TestEqual\nmessage:      hasdfs\n")
}

func TestContains(t *testing.T) {
	err := Contains(tea.String("Test error"), tea.String("Test"), tea.String("hasdfs"))
	utils.AssertNil(t, err)

	err = Contains(tea.String("Test error"), tea.String("test"), tea.String("hasdfs"))
	utils.AssertEqual(t, err.Error(), "Error Trace:  client_test.go:22\nTest:         github.com/alibabacloud-go/darabonba-assert/client.TestContains\nmessage:      hasdfs\n")
}

func TestMapEql(t *testing.T) {
	err := MapEql(map[string]interface{}{"a": "1", "b": 2}, map[string]interface{}{"a": "1", "b": 2}, tea.String(""))
	utils.AssertNil(t, err)
}

func TestArrayEql(t *testing.T) {
	err := ArrayEql([]interface{}{"1", 2}, []interface{}{"1", 2}, tea.String(""))
	utils.AssertNil(t, err)
}

func TestFail(t *testing.T) {
	err := Fail(tea.String("is error"))
	utils.AssertEqual(t, err.Error(), "Error Trace:  client_test.go:37\nTest:         github.com/alibabacloud-go/darabonba-assert/client.TestFail\nmessage:      is error\n")
}
