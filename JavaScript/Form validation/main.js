console.log("to check")
const name = document.getElementById('name');
const email = document.getElementById('email');
const phone = document.getElementById('phone');
let validEmail = false
let validPhone = false
let validUser = false
$('#failure').hide();
$('#success').hide();
//blur meaning is select krke vapas bhr click krna kaahi 

name.addEventListener('blur', () => {
    console.log("name is blurred");
    // Validate name here
    let regex = /^[a-zA-Z]([0-9a-zA-Z]){2,10}$ /;
    let str = name.value;
    
    console.log(regex, str);
    if (regex.test(str)) {
        console.log('Your name is valid');
        name.classList.remove('is-invalid');
            validUser = true;
    }
    else {
        console.log('Your name is not valid');
        name.classList.add('is-invalid');
            validUser = false;

    }
})


email.addEventListener('blur', () => {
    console.log("blurred");
    //validdate email here
    let regex = /^([_\-\.0-9a-zA-Z]+)@([_\-\.0-9a-zA-Z]+)\.([a-zA-z]{2,7})$/;
    let str = email.value;
    console.log(regex, str);
    if (regex.test(str)) {
        console.log('Your email is valid');
        email.classList.remove('is-invalid');
            validEmail = true;
    }
    else {
        console.log('Your email is not valid');
        email.classList.add('is-invalid');
            validEmail = false;

    }
})

phone.addEventListener('blur', () => {
    console.log("blurred");
    //validdate phone here
    let regex = /^([0-9]){10}$/;
    let str = phone.value;
    console.log(regex, str);
    if (regex.test(str)) {
        console.log('Your phone is valid');
        phone.classList.remove('is-invalid');
            validPhone= true;
    }
    else {
        console.log('Your phone is not valid');
        phone.classList.add('is-invalid');
            validPhone = false;

    }
})

let submit = document.getElementById('submit');
submit.addEventListener('click', (e) => {
    e.preventDefault();
    console.log('working button')
    //submit your form here

    if (validEmail && validUser && validPhone){
        console.log('Phone, user and email are valid. Submitting the form..');
        let failure = document.getElementById('failure')
      let success = document.getElementById('success')
        success.classList.add('show');
        // failure.classList.remove('show');
        // failure.alert('close')
        $('#failure').hide();
        $('#success').show();

    }
    else{
        console.log('One of Phone, user and email are not  valid.Hence not submitting the form..Please correct the errors and try again');
        
        let failure = document.getElementById('failure')
        failure.classList.add('show')
        // success.classList.remove('show')
        // success.alert('close')
        $('#success').hide();
        $('#failure').show();
    }

})