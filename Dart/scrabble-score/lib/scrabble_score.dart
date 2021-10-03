// * Solutions By SushanShakya

Map<List<String>, int> scores = {
  ['z', 'q']: 10,
  ['j', 'x']: 8,
  ['k']: 5,
  ['f', 'h', 'v', 'w', 'y']: 4,
  ['b', 'c', 'm', 'p']: 3,
  ['d', 'g']: 2,
  ['a', 'e', 'i', 'o', 'u', 'l', 'n', 'r', 's', 't']: 1
};
int getScore(String s) {
  int sc = scores[scores.keys.firstWhere((e) => e.contains(s))];
  return sc ?? 1;
}

int score(String s) {
  int total = 0;
  for (var i in s.split('')) {
    total += getScore(i.toLowerCase());
  }
  return total;
}
