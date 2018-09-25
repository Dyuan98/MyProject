/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package com.stu.util;

import com.stu.dao.IStudentDao;
import com.stu.dao.impl.StudentDaoImpl;

/**
 *用于生成数据操作访问对象。
 * @author Administrator
 */
public class DaoFactory {

    public static IStudentDao getStudentDao() {
        return new StudentDaoImpl();
    }
}
