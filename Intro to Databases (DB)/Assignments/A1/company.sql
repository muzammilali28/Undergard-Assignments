create database company;
use company;

CREATE TABLE EMPLOYEE( 
Fname VARCHAR(15) NOT NULL,
Minit CHAR(1),
Lname VARCHAR(15) NOT NULL,
Ssn CHAR(9) NOT NULL,
Bdate DATE, 
Address VARCHAR(30), 
Sex CHAR, 
Salary DECIMAL(10,2), 
Super_ssn CHAR(9), 
Dno INT NOT NULL, 

PRIMARY KEY (Ssn)
);

insert into EMPLOYEE values
('John','B','Smith','123456789','1965-01-09','731 Fondren, Houston, TX','M',30000,'333445555',5),
('Franklin','T','Wong','333445555','1955-12-08','638 Voss, Houston, TX','M',40000,'888665555',5),
('Alicia','J','Zelaya','999887777','1968-01-19','3321 Castle, Spring, TX','F',25000,'987654321',4),
('Jennifer','S','Wallace','987654321','1941-06-20','291 Berry, Bellaire, TX','F',43000,'888665555',4),
('Ramesh','K','Narayan','666884444','1962-09-15','975 Fire Oak, Humble, TX','M',38000,'333445555',5),
('Joyce','A','English','453453453','1972-07-31','5631 Rice, Houston, TX','F',25000,'333445555',5),
('Ahmad','V','Jabbar','987987987','1969-03-29','980 Dallas, Houston, TX','M',25000,'987654321',4),
('James','E','Borg','888665555','1937-11-10','450 Stone, Houston, TX','M',55000,NULL,1);

select * from EMPLOYEE;
describe EMPLOYEE;

CREATE TABLE DEPARTMENT(
Dname VARCHAR(15) NOT NULL, 
Dnumber INT NOT NULL, 
Mgr_ssn CHAR(9) NOT NULL, 
Mgr_start_date DATE, 

PRIMARY KEY (Dnumber), 
UNIQUE (Dname)
);

insert into DEPARTMENT values
('Research',5,'333445555','1988-05-22'),
('Administration',4,'987654321','1995-01-01'),
('Headquaters',1,'888665555','1981-06-19');

select * from DEPARTMENT;
describe DEPARTMENT;

CREATE TABLE DEPT_LOCATIONS(
Dnumber INT NOT NULL, 
Dlocation VARCHAR(15) NOT NULL, 

PRIMARY KEY (Dnumber, Dlocation)
);

insert into DEPT_LOCATIONS values
(1,'Houston'),
(4,'Stafford'),
(5,'Bellaire'),
(5,'Sugarland'),
(5,'Houston');

select * from DEPT_LOCATIONS;
describe DEPT_LOCATIONS;

CREATE TABLE PROJECT(
Pname VARCHAR(15) NOT NULL,
Pnumber INT NOT NULL,
Plocation VARCHAR(15),
Dnum INT NOT NULL,

PRIMARY KEY (Pnumber),
UNIQUE (Pname)
);

insert into PROJECT values
('ProductX',1,'Bellaire',5),
('ProductY',2,'Sugarland',5),
('ProductZ',3,'Houston',5),
('Computerization',10,'Stafford',4),
('Reorganization',20,'Houston',1),
('Newbenefits',30,'Stafford',4);

select * from PROJECT;
describe PROJECT;

CREATE TABLE WORKS_ON(
Essn CHAR(9) NOT NULL, 
Pno INT NOT NULL, 
Hours DECIMAL(3,1), 

PRIMARY KEY (Essn, Pno)
);
alter table WORKS_ON Modify Hours DECIMAL(3,1) NULL;
insert into WORKS_ON values
('123456789',1,32.5),
('123456789',2,7.5),
('666884444',3,40.0),
('453453453',1,20.0),
('453453453',2,20.0),
('333445555',2,10.0),
('333445555',3,10.0),
('333445555',10,10.0),
('333445555',20,10.0),
('999887777',30,30.0),
('999887777',10,10.0),
('987987987',10,35.0),
('987987987',30,5.0),
('987654321',30,20.0),
('987654321',20,15.0),
('888665555',20,NULL);

select * from WORKS_ON;
describe WORKS_ON;

CREATE TABLE DEPENDENT(
Essn CHAR(9) NOT NULL,
Dependent_name VARCHAR(15) NOT NULL,
Sex CHAR(1),
Bdate DATE,
Relationship VARCHAR(8),

PRIMARY KEY (Essn, Dependent_name)
);

insert into DEPENDENT values
('333445555','Alice','F','1986-04-05','Daughter'),
('333445555','Theodore','M','1983-10-25','Son'),
('333445555','Joy','F','1958-05-03','Spouse'),
('987654321','Abner','M','1942-02-28','Spouse'),
('123456789','Michael','M','1988-01-04','Son'),
('123456789','Alice','F','1988-12-30','Daughter'),
('123456789','Elizabeth','F','1967-05-05','Spouse');

select * from DEPENDENT;
describe DEPENDENT;

alter table EMPLOYEE add CONSTRAINT FOREIGN KEY (Super_ssn) REFERENCES EMPLOYEE(Ssn) ON DELETE CASCADE ON UPDATE CASCADE;
alter table EMPLOYEE add CONSTRAINT FOREIGN KEY (Dno) REFERENCES DEPARTMENT(Dnumber) ON DELETE CASCADE ON UPDATE CASCADE;

alter table DEPARTMENT add CONSTRAINT FOREIGN KEY (Mgr_ssn) REFERENCES EMPLOYEE(Ssn) ON DELETE CASCADE ON UPDATE CASCADE;

alter table DEPT_LOCATIONS add CONSTRAINT FOREIGN KEY (Dnumber) REFERENCES DEPARTMENT(Dnumber) ON DELETE CASCADE ON UPDATE CASCADE;

alter table PROJECT add CONSTRAINT FOREIGN KEY (Dnum) REFERENCES DEPARTMENT(Dnumber) ON DELETE CASCADE ON UPDATE CASCADE;

alter table WORKS_ON add CONSTRAINT FOREIGN KEY (Essn) REFERENCES EMPLOYEE(Ssn) ON DELETE CASCADE ON UPDATE CASCADE;
alter table WORKS_ON add CONSTRAINT FOREIGN KEY (Pno) REFERENCES PROJECT(pnumber) ON DELETE CASCADE ON UPDATE CASCADE;

alter table DEPENDENT add CONSTRAINT FOREIGN KEY (Essn) REFERENCES EMPLOYEE(Ssn) ON DELETE CASCADE ON UPDATE CASCADE;




use company;

/*(a) Find the details of the Employees working for department # 4*/
select * from employee where Dno=4;

/*(b) Find the details of the Employees who earn more than 30K.*/
select * from employee where salary > 30000;

/*(c) Find the details of the Employees who either work for department # 4 and earn
more than 25K or work for department # 5 and earn more than 30K.*/
select * from employee where dno=4 and salary>25000 union select * from employee where dno=5 and salary>30000;

/*(d) Find the first name, last name and salaries of all the employees.*/
select fname as First_Name,lname as Last_Name,Salary from Employee;

/*(e) Find the combinations of sex and salary in the Employees table.*/
select Sex,Salary from Employee;

/*(f) Find the names and salaries of the employees working for department # 5.*/
select fname as First_Name,lname as Last_Name,Salary from Employee where Dno=5;

/*(g) Find the SSN of the employees who either work for department # 5 or supervise
someone who works for department # 5.*/
select SSN from employee where dno=5 UNION select SSN from employee where super_ssn IN(select ssn from employee where dno=5);

/*(h) Find the SSN of the employees who work for department # 5 and also supervise
someone who works for department # 5.*/
select SSN from employee where dno=5 INTERSECT select SSN from employee where super_ssn IN(select ssn from employee where dno=5);

/*(i) Find the SSN of the employees who do not work for department # 5 but supervise
someone who works for department # 5.*/
select SSN from employee where dno!=5 INTERSECT select SSN from employee where super_ssn IN(select ssn from employee where dno=5);

/*(j) Find the names of the female employees along with the names of their dependents.*/
select E.fname,E.lname,D.dependent_name from employee E join Dependent D on E.ssn=D.essn where E.sex='F';
select Fname,Lname,(select dependent_name from dependent D where E.ssn=D.essn)
from Employee E where E.sex='F';

/*(k) Find out the names of the department managers.*/
select fname,lname from employee where ssn IN(select mgr_ssn from department);

/*(l) List the names of the projects along with the names of the departments under
which they are run.*/
select dept.Dname,pro.Pname from Department dept join project pro on dept.Dnumber=pro.Dnum;

/*(m) List the name of the employees who are working on any project not being run by
their department. (Nested Query)*/
select fname,lname from Employee where SSN IN(select essn from Works_on where Pno IN(select Pnumber from Project where Dnum NOT IN(select Dnumber from Department)));

/*(n) List the names, gender and salaries of the employees who are supervised by
Jennifer Wallace (Nested Query)*/
select fname,lname,sex,salary from employee where super_ssn IN(select ssn from employee where fname='Jennifer' and lname='Wallace');

/*(o) List the name of the employees who manage a department which has an office in
Houston. (Nested Query)*/
select fname,lname from employee where ssn IN(select mgr_ssn from department where Dnumber IN(select Dnumber from dept_locations where Dlocation='Houston'));

/*(p) Find the name and salaries of the employees who have a female dependent.
(Nested Query)*/
select fname,lname,salary from employee where SSN IN(select essn from dependent where sex='F');

/*(q) Find the names of salaries of the employees who have a dependent of the same
gender as the employee. (Co-Related Query)*/
select fname,lname,salary from employee e where exists (select essn from dependent d where d.sex=e.sex and e.ssn=d.essn); /* querry 1 */
select fname,lname,salary from employee e where e.SSN IN(select d.essn from dependent d where e.sex=d.sex); 			  /* querry 2 */ /* both querry 1 and querry 2 are Co-related and works the same*/

/*(r) List the average salary of the female employees.*/
 select avg(salary) from employee where sex='F';
 
 /*(s) List the names sex, and salary of the employees who earn more than the average
salary of the female employees.*/
select fname,lname,sex,salary from employee having salary > (select avg(salary) from employee where sex='F');

/*(t) For each department list the department name and the average salary of the
employees working in that department.*/
select Dname,avg(salary) from department join employee on Dnumber=Dno group by Dno;

/*(u) List the names of the employees who do not have any dependent.*/
select fname,lname from employee where ssn NOT IN(select essn from dependent);

/*(v) List the names and salaries of the employees along with the total number of hours
they have spent on all project.*/
select fname,lname,salary,sum(hours) from Employee join Works_on on ssn=essn where Pno IN(select Pnumber from project) group by essn;

/*(w) List the names and salaries of the employees along with the total number of hours
spent on projects if they have spent less than 20 hours total.*/
select fname,lname,salary,sum(hours) from Employee join Works_on on ssn=essn join project on Pno=Pnumber group by essn having sum(hours)<20;

/*(x) List the names and salaries of all the employees who have at least 2 dependents.*/
select fname,lname,salary from Employee where (select count(essn) from Dependent where ssn=essn group by essn) >=2;

/*(y) List the name of managers who have at least 1 dependent. */
select fname,lname from Employee where ssn IN(select mgr_ssn from department where mgr_ssn IN(select essn from dependent));
select fname,lname from Employee where ssn IN(select mgr_ssn from department where (select count(essn) from dependent where mgr_ssn=essn group by essn)>=1);

/*(z) List the name and salaries of all the employees along with the total number of
their dependents. (You must show data for all the employees even if they do not
have any dependent)*/
select fname,lname,salary,(select count(essn) from dependent D where E.ssn=D.essn) as count
from employee E group by Fname;
