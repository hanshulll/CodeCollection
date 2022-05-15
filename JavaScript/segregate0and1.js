function segregate0and1(arr, n) {

    //code here
    let arry = []
    let index = []
    for (let i = 0; i < arr.length; i++) {
        if (arr[i] == 1) {
            index.push(i)
        } else {
            arry.push(arr[i])
        }
    }
    index.forEach((element) => {
        arry.push(arr[element])
    })
    return arry
}