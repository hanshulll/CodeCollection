function convertToRoman(num) {
  const ROMAN = {'M':1000 , 'CM':900 , 'D':500 , 'CD':400 , 'C':100 , 'XC':90 , 'L':50 , 'XL':40 , 'X':10 , 'IX':9 , 'V':5 , 'IV':4 , 'I':1}
  let romanStr= ""

    for(let n in ROMAN){
      while(num >= ROMAN[n]){
        romanStr += n;
        num -= ROMAN[n];
      }
      }

 return romanStr;
}

convertToRoman(<ENTER_A_NUMBER_TO_CONVERT>);
