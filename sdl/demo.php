<?php
$firstName = $_POST('firstName');
$lastName = $_POST('lastName');
$gender = $_POST('gender');
$email = $_POST('email');
$password = $_POST('password');
$number = $_POST('number');

$conn = new mysqli("localhost","root","","test");
if($conn->connect_error){
	echo "$conn->connect_error";
	die("Connection failed:".$conn->connect_error);
	
}

else{
	$stmt=$conn->prepare("insert into registration(firstName,lastName,gender,email,password,number) values(?,?,?,?,?,?)");
	$stmt->bind_param("sssssi",$firstName,$lastName,$gender,$email,$password,$number);
	$execval->$stmt->execute();
	echo $execval;
	echo "registration Successfully";
	$stmt->close();
	$conn->close();
}
?>