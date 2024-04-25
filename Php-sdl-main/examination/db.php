<?php
$conn = new mysqli("localhost", "root","","examination");

if($conn->connect_error){
    die("Connection Error: ".$conn->connect_error);
}
?>