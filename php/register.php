<?php 
$server='localhost';
$username='root';
$password='';
$database='jobs';

$conn= mysqli_connect($server,$username,$password,$database);

if($conn->connect_error){
	die("Connection failed:".$conn->connect_error);

}
echo"";

if(isset($_POST['submit'])){
    $name=$_POST['name'];
    $email=$_POST['email'];
    $number=$_POST['phone_no'];
    $password=$_POST['password'];

    $sql = "INSERT INTO `users`(`Name`, `email`, `password`,`phone_no`) VALUES ('$name','$email','$password','$number')";
    if(mysqli_query($conn, $sql)){
        echo "Records inserted successfully.";
    } else{
        echo "ERROR: Could not able to execute $sql. " . mysqli_error($conn);
    }
}
?>
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <link href="https://cdn.jsdelivr.net/npm/bootstrap@5.1.1/dist/css/bootstrap.min.css" rel="stylesheet" integrity="sha384-F3w7mX95PdgyTmZZMECAngseQB83DfGTowi0iMjiWaeVhAn4FJkqJByhZMI3AhiU" crossorigin="anonymous">
   <style>
     body{
     background-image:url('background.jpg');
     background-size :cover;
     }
    form{
      background-color:#fff;
      margin-top:6cm ;
      margin-left:30em;
      margin-right:10em;
      padding: 30px;
      box-shadow:10px 10px 8px 10px #888888;
    }
   </style>
    <title>Register</title>
  </head>
  <body>
    
  <div class="container">
  <form method="POST">  
      <div class="mb-3">
            <label for="exampleInputName" class="form label"></label>Full Name </label>
             
            <input type="text" class="form-control" id="exampleInputName" aria-describedby="emailHelp" name="name" >
           </div>

        <div class="mb-3">    
        <label for="exampleInputEmail" class="form label"></label>Email Address </label>
            <input type="text" class="form-control" id="exampleInputEmail" aria-describedby="emailHelp" name="email">
            <div id="emailHelp" class="form-text ">We will never share the email with anyone else</div>
        </div>
        <div class="mb-3">
            <label for="exampleInputPassword1" class="form label">Password</label>
            <input type="password" class="form-control" id="exampleInputPassword" aria-describedby="emailHelp" name="password">
        </div>
        <div class="mb-3">
            <Confirm for="exampleInputPassword2" class="form label">Confirm Password</label>
            <input type="password" class="form-control" id="exampleInputPassword2" aria-describedby="emailHelp">
        </div>
        <label for="exampleInputEmail" class="form label"></label>Phone Number</label>
            <input type="number" class="form-control" id="exampleInputEmail" aria-describedby="emailHelp" name="phone_no">
         
        <div class="mb-3 form-check">
            <input type ="checkbox" class="form-check-input" id="exampleCheck1">
            <label class="form-check-label" for="exampleCheck1">Check me out</label>
        </div>
        <input type="submit" value="Submit" name="submit"> </input>
        <br>
       <b>Already Registered?</b>  <a href="Login.php">Login</a>
        </form>
  </div>
</body>
</html>

