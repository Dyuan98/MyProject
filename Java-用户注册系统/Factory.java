package com.liushuai;

public class Factory {
    public static AbstractFrame getFrame(String tag) {
        if (tag.equals("登录")) {
           return new Login();
        } else if (tag.equals("注册")) {
            return new Register();
        }
        else if (tag.equals("用户管理界面")) {
            return new UserManage();
        }
        else if (tag.equals("修改界面")) {
            return new Modify();
        }
        else if (tag.equals("主界面")) {
            return new MainFrame();
        }
        else
            return null;
    }
}
