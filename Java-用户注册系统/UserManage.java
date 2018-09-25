package com.liushuai;
/*
用户管理界面
*/

import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class UserManage extends AbstractFrame implements ActionListener {
    private JFrame frame = new JFrame();
    private String welcomMsg = "选择如下操作:";
    private JLabel lblWelcome = new JLabel(welcomMsg);
    private JButton btQuery = new JButton("显示详细信息");
    private JButton btModify = new JButton("修改个人资料");
    private JButton btExit = new JButton("退出");

    private Frame modify;

    public UserManage() {

        frame.setTitle("当前登录: " + User.username);
        frame.setLayout(new GridLayout(4, 1));
        frame.add(lblWelcome);
        frame.add(btQuery);
        frame.add(btModify);
        frame.add(btExit);
        frame.setSize(400, 300);
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setResizable(false);
        frame.setVisible(true);

        btQuery.addActionListener(this);
        btModify.addActionListener(this);
        btExit.addActionListener(this);
    }


    @Override
    public void actionPerformed(ActionEvent e) {
        //显示用户信息
        if (e.getSource() == btQuery) {
            String message = "您的详细资料为:\n";
            message += "账号:" + User.username + "\n";
            message += "密码:" + User.password + "\n";
            message += "编号:" + User.id + "\n";
            JOptionPane.showMessageDialog(frame, message);
        } else if (e.getSource() == btModify) {
            modify= Factory.getFrame("修改界面").getFrame();
            //new Modify();
        } else {
            frame.dispose();
        }
    }

    @Override
    public JFrame getFrame() {
        return frame;
    }
}


