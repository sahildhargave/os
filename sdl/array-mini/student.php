<?php 
class Student{
	private $username;
	private $email;
	private $studentId;
	public function __construct($username,$email,$studentId){
		$this->username=$username;
		$this->email=$email;
		$this->studentId= $studentId;
	}

	public function getUsername(){
		return $this->username;
	}

	public function getEmail(){
		return $this->email;
	}

	public function getStudentId(){
		return $this->studentId;
	}

}
?>