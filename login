<!DOCTYPE html>
<html>
<head>
<meta name="viewport" content="width=device-width, initial-scale=1">
<style>
body {font-family: Arial, Helvetica, sans-serif;}
form {border: 3px solid #f1f1f1;}

h2{
    text-align: center;
}

label{
  margin: 4px;
}

input[type=text], input[type=password] {
  border-radius: 10px;
  width: 40%;
  padding: 12px 20px;
  margin: 8px 0;
  border: 1px solid #ccc;
  box-sizing: border-box;
  margin: auto;
}

button {
  background-color: #04AA6D;
  color: white;
  padding: 14px 20px;
  margin: 5px auto;
  border: none;
  cursor: pointer;
  width: 20%;
  border: 2px solid black;
  border-radius: 20px;
}

button:hover {
  opacity: 0.8;
}

.cancelbtn {
  width: 20%;
  padding: 10px 18px;
  background-color: #f44336;
}

.imgcontainer {
  text-align: center;
  margin: 24px 0 12px 0;
}

img.avatar {
  width: 40%;
  border-radius: 50%;
}

span.psw {
  float: right;
  padding-top: 16px;
}

.login-container{
  border: 1px solid black;
  width: 50%;
  display: flex;
    flex-direction: column;
    text-align: center;
    margin: auto;
    height: auto;
}

.container{
    display: flex;
    flex-direction: column;
    text-align: center;
    padding: 16px;
}

/* Change styles for span and cancel button on extra small screens */
@media screen and (max-width: 300px) {
  span.psw {
     display: block;
     float: none;
  }
  .cancelbtn {
     width: 40%;
  }
}
</style>
</head>
<body>

<h2>Login Form</h2>

<form action="/action_page.php" method="post">
  <div class="imgcontainer">
    <img src="img_avatar2.png" alt="Avatar" class="avatar">
  </div>

  <div class="login-container">
    <div class="container">
    <label for="uname"><b>Username</b></label>
    <input style="margin-bottom: 10px;" type="text" placeholder="Enter Username" name="uname" required>

    <label for="psw"><b>Password</b></label>
    <input type="password" placeholder="Enter Password" name="psw" required>
        
    <button type="submit">Login</button>
    <label>
      <input type="checkbox" checked="checked" name="remember"> Remember me
    </label>
  </div>
  </div>
  <br>

  <div class="container" style="background-color:#f1f1f1">
    <button type="button" class="cancelbtn">Cancel</button>
    <span class="psw">Forgot <a href="#">password?</a></span>
  </div>
</form>

</body>
</html>
