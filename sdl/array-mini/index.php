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

    // Array to store student data
    $students = array();
    $students[] = new Student('johndoe', 'johndoe@email.com', 'S12345');

    // Array to store instructor data
    $instructors = array();
    $instructors[] = new Instructor('janedoe', 'janedoe@email.com', 'I98765');

    // Display student details
    echo "<h2>Student Details</h2>";
    foreach ($students as $student) {
        echo "Username: " . $student->getUsername() . "<br>";
        echo "Email: " . $student->getEmail() . "<br>";
        echo "Student ID: " . $student->getStudentId() . "<br>";
        echo "<hr>";
    }

    // Display instructor details
    echo "<h2>Instructor Details</h2>";
    foreach ($instructors as $instructor) {
        echo "Username: " . $instructor->getUsername() . "<br>";
        echo "Email: " . $instructor->getEmail() . "<br>";
        echo "Instructor ID: " . $instructor->getEmployeeId() . "<br>";
        echo "<hr>";
    }
    ?>

</body>

</html>