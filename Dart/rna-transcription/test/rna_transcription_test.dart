import 'package:rna_transcription/rna_transcription.dart';
import 'package:test/test.dart';

final rnaTranscription = RnaTranscription();

void main() {
  group('RnaTranscription', () {
    test('Empty RNA sequence', () {
      final String result = rnaTranscription.toRna('');
      expect(result, equals(''));
    }, skip: false);

    test('RNA complement of cytosine is guanine', () {
      final String result = rnaTranscription.toRna('C');
      expect(result, equals('G'));
    }, skip: true);

    test('RNA complement of guanine is cytosine', () {
      final String result = rnaTranscription.toRna('G');
      expect(result, equals('C'));
    }, skip: true);

    test('RNA complement of thymine is adenine', () {
      final String result = rnaTranscription.toRna('T');
      expect(result, equals('A'));
    }, skip: true);

    test('RNA complement of adenine is uracil', () {
      final String result = rnaTranscription.toRna('A');
      expect(result, equals('U'));
    }, skip: true);

    test('RNA complement', () {
      final String result = rnaTranscription.toRna('ACGTGGTCTTAA');
      expect(result, equals('UGCACCAGAAUU'));
    }, skip: true);
  });
}
