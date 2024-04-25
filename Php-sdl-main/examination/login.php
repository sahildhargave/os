<?php
session_start();
$conn = new mysqli('localhost','root','','examination');

$name = $_POST['username'];
$pass = $_POST['userpass'];

$sql = "SELECT * FROM register WHERE username='$name'";
// $res = mysqli_query($conn,$sql);
$result = $conn->query($sql);

if($result->num_rows == 1){
    $row = $result->fetch_assoc();
    if($pass == $row['userpass']){
        $_SESSION['id']=$row['id'];
        header('location:index.php');
    }
}

$conn->close();
?>