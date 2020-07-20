package client

import (
	"testing"

	"github.com/alibabacloud-go/tea/tea"
	"github.com/stretchr/testify/assert"
)

func TestEqual(t *testing.T) {
	err := Equal(tea.String("a"), tea.String("a"), tea.String("hasdfs"))
	assert.Nil(t, err)

	err = Equal(tea.String("a"), tea.String("b"), tea.String("hasdfs"))
	assert.Equal(t, err.Error(), "Error Trace:  client_test.go:14\nTest:         github.com/alibabacloud-go/tea-assert/client.TestEqual\nmessage:      hasdfs\n")
}

func TestContains(t *testing.T) {
	err := Contains(tea.String("Test error"), tea.String("Test"), tea.String("hasdfs"))
	assert.Nil(t, err)

	err = Contains(tea.String("Test error"), tea.String("test"), tea.String("hasdfs"))
	assert.Equal(t, err.Error(), "Error Trace:  client_test.go:22\nTest:         github.com/alibabacloud-go/tea-assert/client.TestContains\nmessage:      hasdfs\n")
}

func TestMapEql(t *testing.T) {
	err := MapEql(map[string]interface{}{"a": "1", "b": 2}, map[string]interface{}{"a": "1", "b": 2}, tea.String(""))
	assert.Nil(t, err)
}

func TestArrayEql(t *testing.T) {
	err := ArrayEql([]interface{}{"1", 2}, []interface{}{"1", 2}, tea.String(""))
	assert.Nil(t, err)
}

func TestFail(t *testing.T) {
	err := Fail(tea.String("is error"))
	assert.EqualError(t, err, "Error Trace:  client_test.go:37\nTest:         github.com/alibabacloud-go/tea-assert/client.TestFail\nmessage:      is error\n")
}
