// Function to clear all form error messages
function clearErrors() {
    let errors = document.getElementsByClassName('formerror');
    for (let item of errors) {
        item.innerHTML = "";
    }
}

// Function to set error message for a specific form field
function seterror(id, error) {
    let element = document.getElementById(id);
    let errorElement = element.querySelector('.formerror');
    errorElement.innerHTML = error;
}

// Function to validate the registration form
function validateForm() {
    // Clear any existing error messages
    clearErrors();

    // Flag to track form validation status
    let isValid = true;

    // Retrieve form input values
    let firstName = document.forms['myForm']['fname'].value;
    let lastName = document.forms['myForm']['lname'].value;
    let email = document.forms['myForm']['femail'].value;
    let password = document.forms['myForm']['password'].value;
    let confirmPassword = document.forms['myForm']['cpass'].value;
    let mobile = document.forms['myForm']['mobile'].value;
    let gender = document.querySelector('input[name="myGender"]:checked');

    // Validate First Name and Last Name
    if (firstName.trim() === "" || lastName.trim() === "") {
        seterror("name", "*Please enter your full name");
        isValid = false;
    }

    // Validate Email
    if (email.trim() === "") {
        seterror("email", "*Please enter your email");
        isValid = false;
    }

    // Validate Password
    if (password.length < 6) {
        seterror("password", "*Password should be at least 6 characters long");
        isValid = false;
    }

    // Validate Confirm Password
    if (confirmPassword !== password) {
        seterror("cpassword", "*Passwords do not match");
        isValid = false;
    }

    // Validate Mobile Number
    if (mobile.trim() === "" || isNaN(mobile) || mobile.length !== 10) {
        seterror("phone", "*Please enter a valid 10-digit mobile number");
        isValid = false;
    }

    // Validate Gender
    if (!gender) {
        seterror("gender", "*Please select your gender");
        isValid = false;
    }

    // Return validation status
    return isValid;
}

document.addEventListener("click", () => {
    Notification.requestPermission().then(perm =>{
        if(perm === "granted"){
            new Notification("Fill out this form to register! -Yash here!");
        }
    })
}, {once: true});