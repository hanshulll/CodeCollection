calculatorDisplay=document.querySelector('h1');
inputButtons=document.querySelectorAll('button');
clear=document.getElementById('clear');


let firstValue=0;
let operatorValue='';
let existsSecondValue=false;


const calculation={
    '/' : (firstNum , secondNum)=> firstNum / secondNum,
    '*' : (firstNum , secondNum)=> firstNum * secondNum,
    '+' : (firstNum , secondNum)=> firstNum + secondNum,
    '-' : (firstNum , secondNum)=> firstNum - secondNum,
    //If equal is pressed then just display the second number
    '=' : (firstNum , secondNum)=> secondNum,
    '%' : (firstNum , secondNum)=> firstNum / secondNum,
    '$' : (firstNum , secondNum)=> -secondNum,
};



function sendNumberVal(number){
    //if there exists a second number then display it make the boolean to false
    if(existsSecondValue){
        calculatorDisplay.textContent=number;
        existsSecondValue=false;
    }
    else{
    // console.log(number);
    // initially display is 0 then that has to be replaced else the number should be concatenated with the existing value
    const displayValue=calculatorDisplay.textContent;
    calculatorDisplay.textContent = displayValue === '0' ? number : displayValue + number; 
    }
}
function sendOperator(operator){
    const currentValue = Number(calculatorDisplay.textContent);
    //prevent multiple operations to be taken
    if(existsSecondValue && operatorValue){
        operatorValue=operator;
     return;
    }
    //if there exits no first number, make it one!
    if( !firstValue){
        firstValue = currentValue;
    }
    else{
        console.log('firstValue','operatorValue','currentValue',firstValue,operatorValue,currentValue);
         //Passing the values to the calculation const
        const calculatedResult= calculation[operatorValue](firstValue,currentValue);
        // console.log('result',calculatedResult);
        calculatorDisplay.textContent=calculatedResult;
        firstValue=calculatedResult;
    }
    //to take in second value only after the first value is taken and the operator is inputed
    existsSecondValue=true;
    operatorValue = operator;
}
function addDecimal(){
    //If a operator is pressed,it should'nt take a decimal after that ex. 25 +. (the display shows 25.)
    if(existsSecondValue)
    return;
    //restrict only one decimal in the input
    if( !calculatorDisplay.textContent.includes('.')){
        calculatorDisplay.textContent=`${calculatorDisplay.textContent}.`;
    }
}
//Mentioned ones should be resetted to that we can take in the next user input
function clearAll(){
    calculatorDisplay.textContent='0';
    firstValue=0;
    operatorValue='';
    secondValue=false;
}


//Event Listeners
//For each of the button,according to its class list execute the functions
inputButtons.forEach((inputButton) => {
    if(inputButton.classList.length === 0)
    inputButton.addEventListener('click',() => sendNumberVal(inputButton.value));
    if(inputButton.classList.contains('operator'))
    inputButton.addEventListener('click',() => sendOperator(inputButton.value));
    if(inputButton.classList.contains('decimal'))
    inputButton.addEventListener('click',() => addDecimal());
})

clear.addEventListener('click',clearAll);
