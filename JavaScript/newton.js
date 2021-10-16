// Newton Method for finding the square-root of a number
// 
// 1. Guess a square root
// 2. Operate with the formula until the previous value is the same as the current
// 3. Then that value is the square root

const newton = (num) => {
    let x = num * 0.75;

    while(true) {
        let y = 0.5 * ( x + (num/x));
        if (x === y) break
        x = y;
    }
    
    return x
}