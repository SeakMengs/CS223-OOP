package com.oopclass.oopexamplejava.repositories;

import com.oopclass.oopexamplejava.models.Student;
import org.springframework.data.repository.CrudRepository;

public interface StudentRepository extends CrudRepository<Student, Long> {
}
