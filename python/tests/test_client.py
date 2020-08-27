import unittest

from alibabacloud_tea_assert.client import Client


class TestClient(unittest.TestCase):
    def test_equal(self):
        Client.equal('A', 'A', '')
        try:
            Client.equal(1, '1', 'test 1 failed')
        except AssertionError as e:
            self.assertEqual('test 1 failed', str(e))

    def test_fail(self):
        try:
            Client.fail('should failed')
        except AssertionError as e:
            self.assertEqual('should failed', str(e))

    def test_map_eql(self):
        a = {'A': 1}
        b = {'A': 1}
        Client.map_eql(a, b, '')

        b = {'A': '1'}
        try:
            Client.map_eql(a, b, 'test map failed')
        except AssertionError as e:
            self.assertEqual('test map failed', str(e))

    def test_array_eql(self):
        a = ['A']
        b = ['A']
        Client.array_eql(a, b, '')

        b = [['A']]
        try:
            Client.array_eql(a, b, 'test array failed')
        except AssertionError as e:
            self.assertEqual('test array failed', str(e))

    def test_contains(self):
        a = 'hello world'
        b = 'hello'
        Client.contains(a, b, '')

        a = 'world'
        try:
            Client.contains(a, b, 'test string contains failed')
        except AssertionError as e:
            self.assertEqual('test string contains failed', str(e))
