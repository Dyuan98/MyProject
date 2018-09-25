package com.mis.dao;

import com.mis.model.Student;
import java.util.List;

/**
 *
 * @author xin
 */
public interface IStudentDao {
    public List<Student> getAllStudent();
    public Student getStudent(String sno);
    public boolean findStudent(String sno);
    public boolean insertStudent(Student stu);
    public boolean updateStudent(Student stu);
    public boolean deleteStudent(String sno);    
}
