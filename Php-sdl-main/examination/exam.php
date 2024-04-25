<?php
session_start();
$conn = new mysqli("localhost", "root","","examination");

$id = (int)$_SESSION['id'];//typecasting
$subject = $_POST['subject'];
$mark = (int)$_POST['mark'];
$prn = $_POST['prn'];

$sql = "INSERT INTO exam VALUES ($id, '$subject', $mark, '$prn')";
if($conn->query($sql)===TRUE){
    header('location:index.php');
}
else{
    echo  "Error".$sql.'<br>'.$conn->error;
}
$conn->close();
?>