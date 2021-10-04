<?php
session_start();
if(isset($_SESSION['username']))
{
?>
<html>
	<head>
		<title>Homepage</title>
	</head>
	<body>
		<center>
		Welcome to Homepage
		<form action='logout.php' method='post'>
			<input type='submit' value='Logout'>
		</form>
		</center>
	</body>
</html>

<?php
}
else
{
	header("Location:mini_project.php");
}
?>
