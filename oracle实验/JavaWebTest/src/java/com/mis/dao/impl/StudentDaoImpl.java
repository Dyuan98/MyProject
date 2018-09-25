package com.mis.dao.impl;

import com.mis.dao.IStudentDao;
import com.mis.model.Student;
import com.mis.util.DatabaseBean;
import java.sql.Connection;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.util.ArrayList;
import java.util.List;

public class StudentDaoImpl implements IStudentDao {

    @Override
    public List<Student> getAllStudent() {
        List<Student> students = new ArrayList<Student>();
        Connection conn = null;
        PreparedStatement psmt = null;
        ResultSet rs = null;
        try {
            conn = DatabaseBean.getConnection();
            String sql = "select * from student";
            psmt = conn.prepareStatement(sql);
            rs = psmt.executeQuery();
            while (rs.next()) {
                Student stu = new Student();
                stu.setSno(rs.getString("sno"));
                stu.setSname(rs.getString("sname"));
                stu.setSsex(rs.getString("ssex"));
                stu.setSage(rs.getInt("sage"));
                stu.setSdept(rs.getString("sdept"));
                students.add(stu);
            }
            return students;
        } catch (SQLException e) {
            e.printStackTrace();
        } finally {
            DatabaseBean.close(rs, psmt, conn);
        }
        return null;
    }

    @Override
    public Student getStudent(String sno) {
        Student stu = null;
        Connection conn = null;
        PreparedStatement psmt = null;
        ResultSet rs = null;
        try {
            conn = DatabaseBean.getConnection();
            String sql = "select * from student where sno=?";
            psmt = conn.prepareStatement(sql);
            psmt.setString(1, sno);
            rs = psmt.executeQuery();
            if (rs.next()) {
                stu = new Student();
                stu.setSno(rs.getString("sno"));
                stu.setSname(rs.getString("sname"));
                stu.setSsex(rs.getString("ssex"));
                stu.setSage(rs.getInt("sage"));
                stu.setSdept(rs.getString("sdept"));
            }
            return stu;
        } catch (SQLException e) {
            e.printStackTrace();
        } finally {
            DatabaseBean.close(rs, psmt, conn);
        }
        return null;
    }

    @Override
    public boolean findStudent(String sno) {
        Connection conn = null;
        PreparedStatement psmt = null;
        ResultSet rs = null;
        try {
            conn = DatabaseBean.getConnection();
            String sql = "select * from student where sno=?";
            psmt = conn.prepareStatement(sql);
            psmt.setString(1, sno);
            rs = psmt.executeQuery();
            while (rs.next()) {
                return true;
            }
        } catch (SQLException ex) {
            ex.printStackTrace();
        } finally {
            DatabaseBean.close(rs, psmt, conn);
        }
        return false;
    }

    @Override
    public boolean insertStudent(Student stu) {
        Connection conn = null;
        PreparedStatement psmt = null;

        try {
            conn = DatabaseBean.getConnection();
            String sql = "insert into student(sno,sname,ssex,sage,sdept) values(?,?,?,?,?)";
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
            DatabaseBean.close(null, psmt, conn);
        }
        return false;
    }

    @Override
    public boolean updateStudent(Student stu) {
        Connection conn = null;
        PreparedStatement psmt = null;

        try {
            conn = DatabaseBean.getConnection();
            String sql = "update student set sname=?,ssex=?,sage=?,sdept=? where sno=?";
            psmt = conn.prepareStatement(sql);
            psmt.setString(1, stu.getSname());
            psmt.setString(2, stu.getSsex());
            psmt.setInt(3, stu.getSage());
            psmt.setString(4, stu.getSdept());
            psmt.setString(5, stu.getSno());
            psmt.executeUpdate();
            return true;
        } catch (SQLException ex) {
            ex.printStackTrace();
        } finally {
            DatabaseBean.close(null, psmt, conn);
        }
        return false;
    }

    @Override
    public boolean deleteStudent(String sno) {
        Connection conn = null;
        PreparedStatement psmt = null;
        ResultSet rs = null;
        try {
            conn = DatabaseBean.getConnection();
            String sql = "delete from student where sno=?";
            psmt = conn.prepareStatement(sql);
            psmt.setString(1, sno);
            psmt.executeUpdate();
            return true;
        } catch (SQLException e) {
            e.printStackTrace();
        } finally {
            DatabaseBean.close(rs, psmt, conn);
        }
        return false;
    }
}
