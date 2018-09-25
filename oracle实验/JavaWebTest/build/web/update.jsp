<%@page contentType="text/html" pageEncoding="UTF-8"%>
<%@taglib prefix="c" uri="http://java.sun.com/jsp/jstl/core" %>
<!DOCTYPE html>
<html>
    <head>
        <meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
        <title>修改学生记录</title>
    </head>
    <body>
    <center>
        <h1>修改学生记录!</h1>
        <p style="color:red;">${updateErr}</p>
        <form id="updateForm" name="updateForm" action="<%=request.getContextPath()%>/UpdateServletDo" method="get">
            <p>学生学号：<input id="sno" name="sno" type="text" value="${stu.sno}" readonly /></p>
            <p>学生姓名：<input id="sname" name="sname" type="text" value="${stu.sname}" /></p>
            <p>学生性别：
                <c:if test="${stu.ssex == '男'}">
                    <input id="ssex" name="ssex" type="radio" checked="checked" value="男" />男&nbsp;&nbsp;
                    <input id="ssex" name="ssex" type="radio" value="女" />女
                </c:if>
                <c:if test="${stu.ssex == '女'}">
                    <input id="ssex" name="ssex" type="radio" value="男" />男&nbsp;&nbsp;
                    <input id="ssex" name="ssex" type="radio" checked="checked" value="女" />女
                </c:if>
            </p>
            <p>学生年龄：<input id="sage" name="sage" type="text" value="${stu.sage}"  /></p>
            <p>学生系部：<input id="sdept" name="sdept" type="text" value="${stu.sdept}" /></p>
            <p><input type="submit" value="提交" /></p>
        </form>
    </center>
    </body>
</html>
