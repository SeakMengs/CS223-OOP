package com.oopclass.oopexamplejava.controllers;

import com.oopclass.oopexamplejava.models.Student;
import com.oopclass.oopexamplejava.repositories.StudentRepository;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Controller;
import org.springframework.ui.Model;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.PostMapping;
import org.springframework.web.bind.annotation.RequestParam;

@Controller
public class StudentController {

    @Autowired
    private StudentRepository studentRepository;

    @GetMapping("/students")
    public String getAllStudents(Model model){
        Iterable<Student> students = studentRepository.findAll();
        model.addAttribute("students", students);
        return "students";
    }
    @PostMapping("/student/add")
    public String addNewStudent(@RequestParam String name,
                                @RequestParam String department,
                                @RequestParam String gender,
                                Model model){
        Student student = new Student(name, department, gender);
        studentRepository.save(student);
        return "redirect:/students";
    }


    @GetMapping("/studentadd")
    public String addStudent(Model model){
        return "studentadd";
    }

}
