package com.mis.util;

import com.mis.dao.IStudentDao;
import com.mis.dao.impl.StudentDaoImpl;

public class DaoFactory {
	public static IStudentDao getStudentDao(){
		return new StudentDaoImpl();
	}
}
