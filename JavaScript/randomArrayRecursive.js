const randomArray = (array,index = 0) => {
    console.log(array.length,index);
    const randomIndex = Math.floor(Math.random() * array.length);
    const selectedItem = array[index];
    array[index] = array[randomIndex];
    array[randomIndex] = selectedItem;
    if(array.length - 1 == index) {
        return array;

    } else {
        return randomArray(array,index + 1);
    }
}

const result = randomArray(['keqing','raiden','ganyu']);
console.log(result);