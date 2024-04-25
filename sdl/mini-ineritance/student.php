<?php
require_once 'user.php';

class Student extends User {
    private $studentId;

    public function __construct($username, $email, $studentId) {
        parent::__construct($username, $email);
        $this->studentId = $studentId;
    }

    public function getStudentId() {
        return $this->studentId;
    }
}
?>