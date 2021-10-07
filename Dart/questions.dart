import 'dart:io';

class MathQuestion {
  MathQuestion(String Tquestion, double Tanswer) {
    this.question = Tquestion;
    this.answer = Tanswer;
  }

  String question = "";
  double answer = 0;
}

double promptQuestion(String questionText) {
  print("Your Question is: $questionText");
  String ans = stdin.readLineSync()!;
  double val = double.parse(ans);
  return val;
}

void main() {
  List<MathQuestion> questions = [
    MathQuestion("2+2", 4.0),
    MathQuestion("32*2", 64.0),
    MathQuestion("70-1", 69.0)
  ];
  int score = 0;
  for (int i = 0; i < questions.length; i++) {
    double ans = promptQuestion(questions[i].question);
    if (ans == questions[i].answer) {
      score++;
    }
  }

  print("Your Score is:  ${score}");
}
