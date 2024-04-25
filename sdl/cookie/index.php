<?php
if($_SERVER['REQUEST_METHOD'] == "POST"){
	$username = $_POST["username"];

	setcookie("user", $username, time()+(86400* 30),"/" );
	header("Location: index.html");
	exit();
}
?>