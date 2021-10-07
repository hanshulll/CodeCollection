// sliding window algorithm to find max sum of particular sequence
// this algorithm is more optimized in case of large array

function getMax(arr, seq) {
    if (arr.length < seq) {
        return arr
    }
    let firstSum = 0;
    let maxSum = 0;
    for (let i = 0; i <= seq - 1; i++) {
        firstSum += arr[i];
    }
    maxSum = firstSum;
    let windowValue = firstSum;
    for (let i = seq; i < arr.length; i++) {
        windowValue = windowValue - (arr[i-seq]) + arr[i];
        if (windowValue > maxSum) {
            maxSum = windowValue;
        }
    }
    return maxSum;
}

console.log(getMax([2, 1, 6, 2, 8, 9, 3], 2))
