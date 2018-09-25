/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package com.stu.util;

/**
 *
 封装相关的数据库连接和关闭操作
 * @author Administrator
 */
import java.sql.*;
import oracle.jdbc.pool.OracleDataSource;

public class DatabaseBean {

    public static Connection getConnection() throws SQLException {
        String jdbcUrl = "jdbc:oracle:thin:@localhost:1521/xe";
        String userid = "hr";
        String password = "oracle";
// Oracle 数据库厂商提供了专门的数据库驱动包ojdbc6.jar
// 这里使用ORACLE 的数据源OracleDataSource 来创建数据库连接
// 在使用时需要引入相应的包
        OracleDataSource ds = new OracleDataSource();
        ds.setURL(jdbcUrl);
        return ds.getConnection(userid, password);
    }

    public static void close(ResultSet rs, Statement st, Connection conn) {
        try {
            if (rs != null) {
                rs.close();
            }
            if (st != null) {
                st.close();
            }
            if (conn != null) {
                conn.close();
            }
        } catch (SQLException ex) {
            ex.printStackTrace();
        }
    }
}
