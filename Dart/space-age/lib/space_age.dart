// * Solutions By SushanShakya

class SpaceAge {
  static const Map<String, double> dayCount = {
    'Mercury': 0.2408467,
    'Venus': 0.61519726,
    'Earth': 1.0,
    'Mars': 1.8808158,
    'Jupiter': 11.862615,
    'Saturn': 29.447498,
    'Uranus': 84.016846,
    'Neptune': 164.79132,
  };

  double age({String planet, int seconds}) {
    return double.parse(
        (dayCount[planet] * _ageInEarth(seconds)).toStringAsFixed(2));
  }

  double _ageInEarth(int seconds) {
    return seconds / 31557600;
  }
}
