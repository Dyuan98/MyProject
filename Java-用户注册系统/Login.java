package com.liushuai;

/*
登录界面
*/

import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class Login extends AbstractFrame implements ActionListener {
    private JFrame frame=new JFrame();
    private JPanel jp = new JPanel();
    private JLabel jlusername = new JLabel("用户名:");
    private JLabel jlpassword = new JLabel("密 码:");
    private JButton jlogin = new JButton("登录");
    private JButton jexit = new JButton("取消");
    private JTextField jtxtName = new JTextField();
    private JPasswordField jtxtPassword = new JPasswordField();


    private Frame manage;


    public Login() {
        jp.setLayout(null);
        jlusername.setBounds(80, 60, 100, 30);//用户名
        jlpassword.setBounds(80, 170, 100, 30);//密码
        jlogin.setBounds(80, 260, 80, 30);//登录
        jexit.setBounds(200, 260, 80, 30);//退出
        jp.add(jlusername);
        jp.add(jlpassword);
        jp.add(jlogin);
        jp.add(jexit);

        jtxtName.setBounds(140, 60, 180, 30);//用户名对应的文本框
        jp.add(jtxtName);
        jtxtPassword.setBounds(140, 170, 180, 30);//密码对应的文本框
        jp.add(jtxtPassword);
        jtxtPassword.setEchoChar('*');

        //添加事件监听器
        jlogin.addActionListener(this);
        jexit.addActionListener(this);

        //设置字体
        jlusername.setFont(new Font("微软雅黑", Font.PLAIN, 15));
        jlpassword.setFont(new Font("微软雅黑", Font.PLAIN, 15));
        jtxtName.setFont(new Font("微软雅黑", Font.BOLD, 15));
        jtxtPassword.setFont(new Font("微软雅黑", Font.BOLD, 15));
        jlogin.setFont(new Font("微软雅黑", Font.BOLD, 15));
        jexit.setFont(new Font("微软雅黑", Font.BOLD, 15));


        frame.add(jp);
        frame.setTitle("登录界面");
        frame.setResizable(false);
        frame.setBounds(100, 100, 400, 400);//窗口大小
        frame.setVisible(true);
    }


    @Override
    public void actionPerformed(ActionEvent e) {
        //登录按钮
        if (e.getSource() == jlogin) {
            String username = jtxtName.getText();
            String password = new String(jtxtPassword.getPassword());
            File.getInfoByUsername(username);
            if (User.username == null) {
                JOptionPane.showMessageDialog(frame, "用户名不存在");
                return;
            } else if (!User.password.equals(password)) {
                JOptionPane.showMessageDialog(frame, "密码错误");
                return;
            }
            JOptionPane.showMessageDialog(frame, "登录成功");
            frame.dispose();
            manage = Factory.getFrame("用户管理界面").getFrame();
            //new UserManage();
        } else {
            frame.dispose();
        }
    }

    @Override
    public JFrame getFrame() {
        return frame;
    }
}


