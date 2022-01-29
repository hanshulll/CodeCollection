import 'dart:io';

void main() {
  var number = 100;

  for (var i = 0; i < number; i++){

    if ( i % 3 == 0 && i % 5 == 0){
      print('fizz buzz');
    }
    else if (i % 3 == 0){
      print('fizz');
    }
    else if (i % 5 == 0 ){
      print('buzz');
    }
    else{
      print(i);
    }
  }

} 