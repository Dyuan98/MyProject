/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package com.stu.dao;

import com.stu.model.Student;
import java.util.List;

/**
 *
 * 数据访问接口，用于封装相关的数据库操作方法。
 * @author Administrator
 */
public interface IStudentDao {

    public List<Student> getAllStudent();

    public Student getStudent(String sno);

    public boolean findStudent(String sno);

    public boolean insertStudent(Student stu);

    public boolean updateStudent(Student stu);

    public boolean deleteStudent(String sno);
}
