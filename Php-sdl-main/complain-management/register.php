<?php
include 'db.php';

$username = $_POST['username'];
$password = password_hash($_POST['password'], PASSWORD_DEFAULT);
$email = $_POST['email'];

$sql = "INSERT INTO users (username, password, email) VALUES ('$username', '$password', '$email')";

if ($conn->query($sql) === TRUE) {
    header("Location: complain.html");
} else {
    echo "Error: " . $sql . "<br>" . $conn->error;
}

$conn->close();
?>
