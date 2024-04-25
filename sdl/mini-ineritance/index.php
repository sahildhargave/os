<!DOCTYPE html>
<html lang="en">

<head>
	<meta charset="UTF-8">
	<meta http-equiv="X-UA-Compatible" content="IE=edge">
	<meta name="viewport" content="width=device-width, initial-scale=1.0">
	<title>LMS - User Roles</title>
</head>

<body>
	<h1>Learning Management System - User Roles</h1>

	<?php
    // Include the necessary class files
    require_once 'student.php';
    require_once 'instructor.php';

    // Create a Student instance
    $student = new Student('johndoe', 'johndoe@email.com', 'S12345');
    echo "<h2>Student Details</h2>";
    echo "Username: " . $student->getUsername() . "<br>";
    echo "Email: " . $student->getEmail() . "<br>";
    echo "Student ID: " . $student->getStudentId() . "<br><br>";

    // Create an Instructor instance
    $instructor = new Instructor('janedoe', 'janedoe@email.com', 'I98765');
    echo "<h2>Instructor Details</h2>";
    echo "Username: " . $instructor->getUsername() . "<br>";
    echo "Email: " . $instructor->getEmail() . "<br>";
    echo "Instructor ID: " . $instructor->getEmployeeId() . "<br>";
    ?>

</body>

</html>