
let w = 'abx';
let S = 'abxaba';

let holdWords = S.split("");

console.log(holdWords)

console.log(holdWords.slice(1,2))

console.log(holdWords.slice(0,w.length))
for(let i = 0; i < holdWords.length; i++) {
    let currWord = holdWords.slice(i,i + w.length).join("");

    if(currWord.split("").sort().join("") == w.split("").sort().join("")) {
        console.log("Current Word Is Anagram")
        console.log(currWord);
        console.log(i)
    }
} 