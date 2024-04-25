<?php
$conn = new mysqli("localhost", "root","","examination");
    
$name = $_POST['username'];
$email = $_POST['useremail'];
$password = $_POST['userpass'];

$sql = "INSERT INTO register VALUES (4,'$name','$email','$password')";
if($conn->query($sql)===TRUE){
    header('location:login.html');
}
else{
    echo  "Error".$sql.'<br>'.$conn->error;
}
?>