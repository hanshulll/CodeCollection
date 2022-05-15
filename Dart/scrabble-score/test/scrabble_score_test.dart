import 'package:scrabble_score/scrabble_score.dart';
import 'package:test/test.dart';

void main() {
  group('ScrabbleScore', () {
    test('lowercase letter', () {
      final int result = score('a');
      expect(result, equals(1));
    }, skip: false);

    test('uppercase letter', () {
      final int result = score('A');
      expect(result, equals(1));
    }, skip: true);

    test('valuable letter', () {
      final int result = score('f');
      expect(result, equals(4));
    }, skip: true);

    test('short word', () {
      final int result = score('at');
      expect(result, equals(2));
    }, skip: true);

    test('short, valuable word', () {
      final int result = score('zoo');
      expect(result, equals(12));
    }, skip: true);

    test('medium word', () {
      final int result = score('street');
      expect(result, equals(6));
    }, skip: true);

    test('medium, valuable word', () {
      final int result = score('quirky');
      expect(result, equals(22));
    }, skip: true);

    test('long, mixed-case word', () {
      final int result = score('OxyphenButazone');
      expect(result, equals(41));
    }, skip: true);

    test('english-like word', () {
      final int result = score('pinata');
      expect(result, equals(8));
    }, skip: true);

    test('empty input', () {
      final int result = score('');
      expect(result, equals(0));
    }, skip: true);

    test('entire alphabet available', () {
      final int result = score('abcdefghijklmnopqrstuvwxyz');
      expect(result, equals(87));
    }, skip: true);
  });
}
