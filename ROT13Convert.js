function rot13(str) {
  let codeArr= []

  for(let i=0; i<str.length; i++){
    let charCode = str.charCodeAt(i);     //translating alphabetical characters ASCII code to alphabetical characters

     if(charCode < 65 || charCode > 90){  //inserting special characters ASCII code(special characters are not shifted)
      codeArr.push(charCode);
    }
    else if(charCode-13<65){              //if shifting is lower that 'A'
      codeArr.push(charCode-13+91-65)
    }

    else if(charCode-13 <= 90){           //if shifting is in range 'A'-'Z'
      codeArr.push(charCode-13)
    }
  }
    let newCode ="";

    for(let i=0; i<codeArr.length; i++){    
      newCode += String.fromCharCode(codeArr[i]); //translating ASCII code to alphabetical characters
      }

  return newCode;
  }

rot13(<ENTER_ROT13_CODE_HERE>);
