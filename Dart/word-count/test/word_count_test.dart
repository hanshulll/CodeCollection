import 'package:test/test.dart';
import 'package:word_count/word_count.dart';

final wordCount = WordCount();

void main() {
  group("WordCount: Simple Tests - ", simpleTests);
  group("WordCount: Ignore special characters - ", ignoreSpecialCharacters);
  group("WordCount: Works with numbers too - ", notJustWords);
  group("WordCount: Edge case - ", edgeCases);
}

void simpleTests() {
  test('count one word', () {
    final Map<String, int> result = wordCount.countWords('word');
    expect(result, equals(<String, int>{'word': 1}));
  }, skip: false);

  test('count one of each word', () {
    final Map<String, int> result = wordCount.countWords('one of each');
    expect(result, equals(<String, int>{'one': 1, 'of': 1, 'each': 1}));
  }, skip: true);

  test('multiple occurrences of a word', () {
    final Map<String, int> result = wordCount.countWords('one fish two fish red fish blue fish');
    expect(result, equals(<String, int>{'one': 1, 'fish': 4, 'two': 1, 'red': 1, 'blue': 1}));
  }, skip: true);
}

void ignoreSpecialCharacters() {
  test('handles cramped lists', () {
    final Map<String, int> result = wordCount.countWords('one,two,three');
    expect(result, equals(<String, int>{'one': 1, 'two': 1, 'three': 1}));
  }, skip: true);

  test('handles expanded lists', () {
    final Map<String, int> result = wordCount.countWords('one,\ntwo,\nthree');
    expect(result, equals(<String, int>{'one': 1, 'two': 1, 'three': 1}));
  }, skip: true);

  test('ignore punctuation', () {
    final Map<String, int> result = wordCount.countWords('car: carpet as java: javascript!!&@\$%^&');
    expect(result, equals(<String, int>{'car': 1, 'carpet': 1, 'as': 1, 'java': 1, 'javascript': 1}));
  }, skip: true);

  test('with quotations', () {
    final Map<String, int> result = wordCount.countWords('Joe can\'t tell between \'large\' and large.');
    expect(result, equals(<String, int>{'joe': 1, 'can\'t': 1, 'tell': 1, 'between': 1, 'large': 2, 'and': 1}));
  }, skip: true);
}

void notJustWords() {
  test('include numbers', () {
    final Map<String, int> result = wordCount.countWords('testing, 1, 2 testing');
    expect(result, equals(<String, int>{'testing': 2, '1': 1, '2': 1}));
  }, skip: true);
}

void edgeCases() {
  test('normalize case', () {
    final Map<String, int> result = wordCount.countWords('go Go GO Stop stop');
    expect(result, equals(<String, int>{'go': 3, 'stop': 2}));
  }, skip: true);

  test('with apostrophes', () {
    final Map<String, int> result = wordCount.countWords('First: don\'t laugh. Then: don\'t cry.');
    expect(result, equals(<String, int>{'first': 1, 'don\'t': 2, 'laugh': 1, 'then': 1, 'cry': 1}));
  }, skip: true);

  test('substrings from the beginning', () {
    final Map<String, int> result = wordCount.countWords('Joe can\'t tell between app, apple and a.');
    expect(result,
        equals(<String, int>{'joe': 1, 'can\'t': 1, 'tell': 1, 'between': 1, 'app': 1, 'apple': 1, 'and': 1, 'a': 1}));
  }, skip: true);

  test('multiple spaces not detected as a word', () {
    final Map<String, int> result = wordCount.countWords(' multiple   whitespaces');
    expect(result, equals(<String, int>{'multiple': 1, 'whitespaces': 1}));
  }, skip: true);

  test('alternating word separators not detected as a word', () {
    final Map<String, int> result = wordCount.countWords(',\n,one,\n ,two \n \'three\'');
    expect(result, equals(<String, int>{'one': 1, 'two': 1, 'three': 1}));
  }, skip: true);
}
