DROP TABLE student;

CREATE TABLE student(    
  sno VARCHAR2(7) PRIMARY  KEY,
  sname VARCHAR2(18),
  ssex VARCHAR2(3),
  sage SMALLINT,
  sdept VARCHAR2(50)
);


insert into student(sno,sname,ssex,sage,sdept) values('9512101','����','��',19,'�����ϵ');
insert into student(sno,sname,ssex,sage,sdept) values('9512102','����','��',20,'�����ϵ');
insert into student(sno,sname,ssex,sage,sdept) values('9512103','����','Ů',20,'�����ϵ');
insert into student(sno,sname,ssex,sage,sdept) values('9521101','����','��',22,'��Ϣϵ');
insert into student(sno,sname,ssex,sage,sdept) values('9521102','���','Ů',21,'��Ϣϵ');
insert into student(sno,sname,ssex,sage,sdept) values('9521103','�ź�','��',20,'��Ϣϵ');
insert into student(sno,sname,ssex,sage,sdept) values('9531101','ǮСƽ','Ů',18,'��ѧϵ');
insert into student(sno,sname,ssex,sage,sdept) values('9531102','������','��',19,'��ѧϵ');
insert into student(sno,sname,ssex,sage,sdept) values('9512104','�Ž�','��',19,'�����ϵ');


COMMIT;

