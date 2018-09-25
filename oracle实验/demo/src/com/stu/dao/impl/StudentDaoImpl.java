/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package com.stu.dao.impl;

import com.stu.dao.IStudentDao;
import com.stu.model.Student;
import com.stu.util.DatabaseBean;
import java.sql.Connection;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.sql.Statement;
import java.util.ArrayList;
import java.util.List;

/**
 *
 * 用于对IstudentDao 接口中相关数据库操作方法的具体实现。
 * @author Administrator
 */
public class StudentDaoImpl implements IStudentDao {

    Connection conn = null;//定义连接类对象
    Statement stmt = null;//为SQL语句的使用定义对象
    PreparedStatement psmt = null;//
    ResultSet rs = null;//定义搜索结果集对象

    @Override
    public List<Student> getAllStudent() {
        List<Student> students = new ArrayList<Student>();
        try {
            conn = DatabaseBean.getConnection();
            stmt = conn.createStatement();
            rs = stmt.executeQuery("select sno,sname,ssex,sage,sdept from student");
            while (rs.next()) {
                Student stu = new Student();
                stu.setSno(rs.getString("sno"));
                stu.setSname(rs.getString("sname"));
                stu.setSsex(rs.getString("ssex"));
                stu.setSage(rs.getInt("sage"));
                stu.setSdept(rs.getString("sdept"));
                students.add(stu);
            }
        } catch (SQLException ex) {
            ex.printStackTrace();
        } finally {
            DatabaseBean.close(rs, stmt, conn);
        }
        return students;
    }

    @Override
    public Student getStudent(String sno) {
        Student stu = new Student();
        try {
            conn = DatabaseBean.getConnection();
            psmt = conn.prepareStatement("select sno,sname,ssex,sage,sdept from student where sno=?");
            psmt.setString(1, sno);
            rs = psmt.executeQuery();
            while (rs.next()) {
                stu.setSno(rs.getString("sno"));
                stu.setSname(rs.getString("sname"));
                stu.setSsex(rs.getString("ssex"));
                stu.setSage(rs.getInt("sage"));
                stu.setSdept(rs.getString("sdept"));
            }
        } catch (SQLException ex) {
            ex.printStackTrace();
        } finally {
            DatabaseBean.close(rs, psmt, conn);
        }
        return stu;
    }

    @Override
    public boolean findStudent(String sno) {
        try {
            String sql = "select sno from student";
            conn = DatabaseBean.getConnection();
            psmt = conn.prepareStatement(sql);
            rs = psmt.executeQuery(sql);
            while (rs.next()) {
               if(sno.equals(rs.getString("sno"))){
                   return true;
               }
            }
        } catch (SQLException ex) {
            ex.printStackTrace();
        } finally {
            DatabaseBean.close(rs, stmt, conn);
        }
        return false;
    }

    @Override
    public boolean insertStudent(Student stu) {
        try {
            String sql = "insert into student(sno,sname,ssex,sage,sdept) values(?,?,?,?,?)";
            conn = DatabaseBean.getConnection();
            psmt = conn.prepareStatement(sql);
            psmt.setString(1, stu.getSno());
            psmt.setString(2, stu.getSname());
            psmt.setString(3, stu.getSsex());
            psmt.setInt(4, stu.getSage());
            psmt.setString(5, stu.getSdept());
            psmt.executeUpdate();
            return true;
        } catch (SQLException ex) {
            ex.printStackTrace();
        } finally {
            DatabaseBean.close(rs, stmt, conn);
        }
        return false;
    }

    @Override
    public boolean updateStudent(Student stu) {
        try {
            String sql = "update student set sname=?,ssex=?,sage=?,sdept=? where sno=?";
            conn = DatabaseBean.getConnection();
            psmt = conn.prepareStatement(sql);
            psmt.setString(1, stu.getSname());
            psmt.setString(2,stu.getSsex());
            psmt.setInt(3,stu.getSage());
            psmt.setString(4,stu.getSdept());
            psmt.setString(5,stu.getSno());
            psmt.executeUpdate();
            return true;
        } catch (SQLException ex) {
            ex.printStackTrace();
        } finally {
            DatabaseBean.close(rs, stmt, conn);
        }
        return false;
    }

    @Override
    public boolean deleteStudent(String sno) {
        try {
            String sql = "delete from student where sno=?";
            conn = DatabaseBean.getConnection();
            psmt = conn.prepareStatement(sql);
            psmt.setString(1,sno);
            psmt.executeUpdate();
            return true;
        } catch (SQLException ex) {
            ex.printStackTrace();
        } finally {
            DatabaseBean.close(rs, stmt, conn);
        }
        return false;
    }
}
