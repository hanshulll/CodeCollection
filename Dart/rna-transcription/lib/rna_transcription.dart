// * Solutions By SushanShakya

class RnaTranscription {
  static const conversion = {
    'G': 'C',
    'C': 'G',
    'T': 'A',
    'A': 'U',
  };

  String toRna(String data) {
    return data.split('').map((e) => conversion[e]).join();
  }
}
