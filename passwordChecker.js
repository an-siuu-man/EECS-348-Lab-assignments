function validate() {
    var pass1 = document.getElementById("password1").value;
    var pass2 = document.getElementById("password2").value;


    if (pass1.length < 8) {
        alert("First password is less than 8 characters!")
    } else if (pass2.length < 8) {
        alert("Second password is less than 8 characters!")
    } else if (pass1 != pass2) {
        alert("Passwords don't match!")
    } else {
        alert("Your passwords match! I hope they are...... safe...")
    }
}