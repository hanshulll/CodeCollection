// * Solutions By SushanShakya

class WordCount {
  Map<String, int> countWords(String s) {
    RegExp re = RegExp(r"\w+('(t|ve|d))?");

    return re
        .allMatches(s)
        .map((e) => e.group(0).toLowerCase())
        .fold(<String, int>{}, (acc, v) {
      if (acc[v] == null) acc[v] = 0;
      acc[v]++;
      return acc;
    });
  }
}
