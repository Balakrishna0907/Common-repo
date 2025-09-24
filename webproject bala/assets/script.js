//login part
let loginform = document.getElementById("loginform");
if (loginform) {
    let loginmsg = document.getElementById("loginmsg");

loginform.addEventListener("submit",function(event) {
    event.preventDefault();
    alert("Form is submitted");

    let email = document.getElementById("email").value;
    let password = document.getElementById("password").value;

    if (email==="" || password==="")
    {
        loginmsg.textContent = "Please fill in all login fields!";
        return;
    }

    loginmsg.style.color = "green";
    loginmsg.textContent = "Log In Succeessful!";
})
}

//signup part
//login part
let signupform = document.getElementById("signupform");
if (signupform) {
    let signupmsg = document.getElementById("signupmsg");

    signupform.addEventListener("submit", function(event) {
        event.preventDefault();
        alert("Form is submitted");
    let email = document.getElementById("signupemail").value;
    let password = document.getElementById("signuppassword").value;
    let confirm = document.getElementById("signupconfirm").value;

    if (email === "" || password === "" || confirm === "") {
      signupmsg.textContent = "Please fill in all signup fields!";
      return;
    }

    if (password !== confirm) {
      signupmsg.textContent = "Passwords do not match!";
      alert("Password do not match the confirm password")
      return;
    }

    signupmsg.style.color = "green";
    signupmsg.textContent = "Signup successful!";
  });
}
