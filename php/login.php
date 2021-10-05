<?php
include "db_connect.php";
if($conn)
{
	$username=$_POST['username'];
	$password=$_POST['password'];
	if($username=='' || $password=='')
	{
		#<input type='hidden' value="Invalid Credentials,Please Retry."/>
		echo "Invalid Credentials,Please Retry.";
		header("Location:mini_project.php");
		exit;
	}
	else
	{	
		$query="SELECT * FROM user WHERE username='$username' AND password='".md5($password)."'";
		$exec_query=mysqli_query($conn,$query);
		$s=mysqli_num_rows($exec_query);
		if($s>=1)
		{
			session_start();
			$_SESSION['username']=$username;
			header("Location:homepage.php");
		}
		else
		{   
			#echo "<html><body><script>alert("Invalid Username or password")</script></body></html>";
			header("Location:mini_project.php");
		}
	}
}
else
{
	header("Location:mini_project.php");
	#echo "Database connection issue!!!";
}
?>
