function plusOne(digits: number[]): number[] {
    for(let i = digits.length - 1; i>=0; i--){
        if(digits[i] < 9){
            digits[i] += 1;
            return digits;
        }
        
        digits[i] = 0;
    }
    let arr: number[] = [];
    arr[0] = 1;
    for(let i = 0; i<digits.length; i++){
        arr[i+1] = digits[i];
    }
    return arr;
};