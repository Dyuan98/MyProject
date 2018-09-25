
import com.stu.model.Student;
import com.stu.util.DaoFactory;
import java.util.List;


public class Main {

    public static void main(String[] args) {
// 显示结果
        displayStudents("原始");
        Student stu = new Student("9512104", "张三", "男", 20, "计算机系");
// 插入数据之前需要先判断学号是否重复
        if (DaoFactory.getStudentDao().findStudent(stu.getSno())) {
            System.out.println("系统信息：学号为 " + stu.getSno() + " 的学生信息已经存在！");
            return;
        }
// 插入学生数据
        if (DaoFactory.getStudentDao().insertStudent(stu)) {
            System.out.println("系统信息：数据插入成功！");
        }
// 显示结果
        displayStudents("插入");
// 修改学生数据
        stu.setSage(18);
        if (DaoFactory.getStudentDao().updateStudent(stu)) {
            System.out.println("系统信息：数据修改成功！");
        }
// 显示结果
        displayStudents("修改");
// 删除学生数据
        if (DaoFactory.getStudentDao().deleteStudent("9512104")) {
            System.out.println("系统信息：数据删除成功！");
        }
// 显示结果
        displayStudents("删除");
    }

    private static void displayStudents(String state) {
        List<Student> students = DaoFactory.getStudentDao().getAllStudent();
        System.out.println("**************************************");
        System.out.println(state + "学生记录后结果为：");
        for (Student s : students) {
            System.out.print("学号：" + s.getSno());
            System.out.print(" 姓名:" + s.getSname());
            System.out.print(" 性别： " + s.getSsex());
            System.out.print(" 年龄：" + s.getSage());
            System.out.println(" 系部：" + s.getSdept());
        }
    }
}
