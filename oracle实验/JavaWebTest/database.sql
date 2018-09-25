DROP TABLE student;

CREATE TABLE student(    
  sno VARCHAR2(7) PRIMARY  KEY,
  sname VARCHAR2(18),
  ssex VARCHAR2(3),
  sage SMALLINT,
  sdept VARCHAR2(50)
);


insert into student(sno,sname,ssex,sage,sdept) values('9512101','李勇','男',19,'计算机系');
insert into student(sno,sname,ssex,sage,sdept) values('9512102','刘晨','男',20,'计算机系');
insert into student(sno,sname,ssex,sage,sdept) values('9512103','王敏','女',20,'计算机系');
insert into student(sno,sname,ssex,sage,sdept) values('9521101','张立','男',22,'信息系');
insert into student(sno,sname,ssex,sage,sdept) values('9521102','吴宾','女',21,'信息系');
insert into student(sno,sname,ssex,sage,sdept) values('9521103','张海','男',20,'信息系');
insert into student(sno,sname,ssex,sage,sdept) values('9531101','钱小平','女',18,'数学系');
insert into student(sno,sname,ssex,sage,sdept) values('9531102','王大力','男',19,'数学系');
insert into student(sno,sname,ssex,sage,sdept) values('9512104','张健','男',19,'计算机系');


COMMIT;

