package com.liushuai;

/*
注册界面
*/

import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class Register  extends AbstractFrame implements ActionListener {
    private JFrame frame=new JFrame();
    private JPanel jp1 = new JPanel();
    private JLabel jlusername1 = new JLabel("用户名:");
    private JLabel jlpassword1 = new JLabel("密 码:");
    private JLabel jlpassword2 = new JLabel("确认密码：");
    private JTextField jtxtName1 = new JTextField();
    private JPasswordField jtxtPassword1 = new JPasswordField();
    private JPasswordField jtxtPassword2 = new JPasswordField();
    private JLabel jid = new JLabel("编号：");
    private JTextField jtxtid = new JTextField();
    private JButton jb1 = new JButton("确认");
    private JButton jb2 = new JButton("取消");

    public Register() {
        jp1.setLayout(null);
        jlusername1.setBounds(80, 50, 100, 30);
        jlpassword1.setBounds(80, 100, 100, 30);
        jlpassword2.setBounds(80, 150, 100, 30);
        jid.setBounds(80, 200, 100, 30);
        jtxtName1.setBounds(140, 50, 180, 30);
        jtxtPassword1.setBounds(140, 100, 180, 30);
        jtxtPassword2.setBounds(140, 150, 180, 30);
        jtxtid.setBounds(140, 200, 180, 30);
        jb1.setBounds(100, 290, 80, 30);
        jb2.setBounds(220, 290, 80, 30);

        jp1.add(jlusername1);
        jp1.add(jlpassword1);
        jp1.add(jlpassword2);
        jp1.add(jid);
        jp1.add(jtxtName1);
        jp1.add(jtxtPassword1);
        jp1.add(jtxtPassword2);
        jp1.add(jtxtid);
        jp1.add(jb1);
        jp1.add(jb2);
        jtxtPassword1.setEchoChar('*');
        jtxtPassword2.setEchoChar('*');

        jlusername1.setFont(new Font("微软雅黑", Font.PLAIN, 15));
        jlpassword1.setFont(new Font("微软雅黑", Font.PLAIN, 15));
        jlpassword2.setFont(new Font("微软雅黑", Font.PLAIN, 15));
        jid.setFont(new Font("微软雅黑", Font.PLAIN, 15));
        jtxtName1.setFont(new Font("微软雅黑", Font.BOLD, 15));
        jtxtPassword1.setFont(new Font("微软雅黑", Font.BOLD, 15));
        jtxtPassword2.setFont(new Font("微软雅黑", Font.BOLD, 15));
        jtxtid.setFont(new Font("微软雅黑", Font.BOLD, 15));
        jb1.setFont(new Font("微软雅黑", Font.BOLD, 15));
        jb2.setFont(new Font("微软雅黑", Font.BOLD, 15));

        frame.add(jp1);
        frame.setTitle("注册界面");
        frame.setResizable(false);
        frame.setBounds(100, 100, 400, 400);//窗口大小
        frame.setVisible(true);
        //点击取消，退出当前窗口
        jb2.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent exit) {
                frame.dispose();
            }
        });

        jb1.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                if (e.getSource() == jb1) {
                    String password1 = new String(jtxtPassword1.getPassword());
                    String password2 = new String(jtxtPassword2.getPassword());
                    if (!password1.equals(password2)) {
                        JOptionPane.showMessageDialog(null, "两次密码不一致");
                        return;
                    }
                    String username = jtxtName1.getText();
                    File.getInfoByUsername(username);
                    if (User.username != null) {//单例模式
                        Singleton s1 = Singleton.GetInstance();
                        Singleton s2 = Singleton.GetInstance();
                    }
                    else {
                        String id = jtxtid.getText();
                        File.updata(username, password1, id);
                        JOptionPane.showMessageDialog(null, "注册成功");
                        frame.dispose();
                    }
                }
            }
        });
    }

    @Override
    public void actionPerformed(ActionEvent actionEvent) {
    }
    public JFrame getFrame() {
        return frame;
    }
}

