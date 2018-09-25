/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package com.stu.model;

import com.stu.util.DaoFactory;
import java.util.ArrayList;
import java.util.List;
import javax.swing.table.AbstractTableModel;

/**
 *
 * @author Administrator
 */
public class StudentTableModel extends AbstractTableModel {
//表格中第一行所要显示的内容存放在字符串数组columnNames 中

    final String[] columnNames = {"学号", "姓名", "性别", "年龄", "系部"};
//表格中各行的内容保存在集合列表中
    List<Student> rowsData;
// 表格模型默认构造方法

    public StudentTableModel() {
        rowsData = DaoFactory.getStudentDao().getAllStudent();
    }
// 表格模型带参数构造方法

    public StudentTableModel(String sno) {
        rowsData = new ArrayList<Student>();
        rowsData.add(DaoFactory.getStudentDao().getStudent(sno));
    }
// 获得行的数目

    @Override
    public int getRowCount() {
        return rowsData.size();
    }
// 获得列的数目

    @Override
    public int getColumnCount() {
        return columnNames.length;
    }
//获得某行某列的数据，而数据保存在集合列表rowsData 中

    @Override
    public Object getValueAt(int rowIndex, int columnIndex) {
        switch (columnIndex) {
            case 0:
                return rowsData.get(rowIndex).getSno();
            case 1:
                return rowsData.get(rowIndex).getSname();
            case 2:
                return rowsData.get(rowIndex).getSsex();
            case 3:
                return rowsData.get(rowIndex).getSage();
            case 4:
                return rowsData.get(rowIndex).getSdept();
//            case 5:
//                return rowsData.get(rowIndex).getSavgGrade();
            default:
                return null;
        }
    }
//获得某列的名字，而目前各列的名字保存在字符串数组columnNames 中

    @Override
    public String getColumnName(int column) {
        return columnNames[column];
    }
}
