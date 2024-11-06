// SPDX-License-Identifier: MIT
pragma solidity ^0.8.0;

contract Student3 {
    
    struct Student {
        uint rollNo;
        string name;
    }

    Student[] public students;
    mapping(uint => Student) studentMapping;

    function addStudent(uint rollNo, string memory name) public {
        // Add student to array
        students.push(Student(rollNo, name));    
        // Add student to mapping
        studentMapping[rollNo] = Student(rollNo, name);
    }

    function getStudent(uint _rollNo) public view returns (uint rollNo, string memory name) {
        Student memory student = studentMapping[_rollNo];
        return (student.rollNo, student.name);
    }

    function getStudent2(uint _rollNo) public view returns (uint rollNo, string memory name) {
        // Iterate over the array to find the student
        for (uint i = 0; i < students.length; i++) {
            if (students[i].rollNo == _rollNo) {
                return (students[i].rollNo, students[i].name);
            }
        }
        revert("Student not found");
    }
}