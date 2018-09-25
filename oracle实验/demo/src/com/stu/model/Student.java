/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */


/*
model放置学生表的模型，实体类。
*/
package com.stu.model;

/**
 *
 * @author Administrator
 */


public class Student {

    private String sno;
    private String sname;
    private String ssex;
    private int sage;
    private String sdept;

    public Student() {
    }

    public Student(String sno, String sname, String ssex, int sage, String sdept) {
        this.sno = sno;
        this.sname = sname;
        this.ssex = ssex;
        this.sage = sage;
        this.sdept = sdept;
    }

    public String getSno() {
        return sno;
    }

    public void setSno(String sno) {
        this.sno = sno;
    }

    public String getSname() {
        return sname;
    }

    public void setSname(String sname) {
        this.sname = sname;
    }

    public String getSsex() {
        return ssex;
    }

    public void setSsex(String ssex) {
        this.ssex = ssex;
    }

    public int getSage() {
        return sage;
    }

    public void setSage(int sage) {
        this.sage = sage;
    }

    public String getSdept() {
        return sdept;
    }

    public void setSdept(String sdept) {
        this.sdept = sdept;
    }

}
