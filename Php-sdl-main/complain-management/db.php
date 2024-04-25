<?php

$servername = "localhost";
$username = "root"; // Your MySQL username
$password = ""; // Your MySQL password
$dbname = "complaint_management";

$conn = new mysqli($servername, $username, $password, $dbname);

if ($conn->connect_error) {
    die("Connection failed: " . $conn->connect_error);
}
echo "hello"
?>
