<%@page contentType="text/html" pageEncoding="UTF-8"%>
<%@taglib prefix="c" uri="http://java.sun.com/jsp/jstl/core" %>
<!DOCTYPE html>
<html>
    <head>
        <meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
        <title>显示学生信息内容</title>
        <script type="text/javascript">
            function del() {
                var msg = "确定要删除这条记录吗？";
                if (confirm(msg) === true) {
                    return true;
                } else {
                    return false;
                }
            }
        </script>
    </head>
    <body>
        <h1 align="center">显示所有学生信息内容</h1>
        <table align="center" width="70%" border="1">
            <thead>
                <tr>
                    <td>学生学号</td>
                    <td>学生姓名</td>
                    <td>学生性别</td>
                    <td>学生年龄</td>
                    <td>学生系部</td>
                    <td>功能操作</td>
                </tr>
            </thead>
            <tbody>
                <c:forEach items="${students}" var="stu">
                    <tr>
                        <td>${stu.sno}</td>
                        <td>${stu.sname}</td>
                        <td>${stu.ssex}</td>
                        <td>${stu.sage}</td>
                        <td>${stu.sdept}</td>
                        <td>
                            <a href="<%=request.getContextPath()%>/DeleteServlet?sno=${stu.sno}" onclick="javascript:return del();">删除</a> | 
                            <a href="<%=request.getContextPath()%>/UpdateServlet?sno=${stu.sno}">修改</a>
                        </td>
                    </tr>
                </c:forEach>
            </tbody>
        </table>
    <center><a href="insert.jsp">插入学生记录</a></center>
</body>
</html>
