use Graded_Lab_1;

--TASK 1
create table Person(
PersonID INT (1) NOT NULL,
FName VARCHAR (15) NOT NULL,
Gender CHAR(1),
Age INT (3),
Email VARCHAR (20)
);
describe Person;
INSERT INTO Person VALUES
(1,'Sarah','F',10,'sarah@ucp.edu.pk'),
(2,'Nagesh','M',28,'nagesh@gmail.com'),
(3,'Arifa','F',92,'arifa@gmail.com'),
(4,'Rehan','M',74,'rehan@nust.edu.pk'),
(5,'Makhdoom','M',159,'makhdoom@ucp.edu.pk');
SELECT * FROM Person;

--TASK 2
alter table Person drop Gender;
alter table Person add City VARCHAR (10) NULL after FName;
update Person set City = 'Swat' where FName = 'Sarah';
update Person set City = 'Murree' where FName = 'Nagesh';
update Person set City = 'Karachi' where FName = 'Arifa';
update Person set City = 'Islamabad' where FName = 'Rehan';
update Person set City = 'Lahore' where FName = 'Makhdoom';

--TASK 3
alter table Person add PRIMARY KEY(PersonID);
create table Contacts(
PhoneID INT(1) NOT NULL,
PersonID INT(1) NOT NULL,
Phone CHAR(16) NOT NULL
);
insert into Contacts values
(1,1,'+92-0333-1111111'),
(2,4,'+92-0321-1234567'),
(3,2,'+92-0321-7894561'),
(4,5,'+92-0345-3453453'),
(5,3,'+92-0313-1313131');
alter table Contacts add CONSTRAINT FOREIGN KEY(PersonID) REFERENCES Person(PersonID) ON DELETE CASCADE ON UPDATE CASCADE;

--TASK 4
delete from Person where FName = 'Nagesh';

--TASK 5
create table Officer(
OfficerID INT(1) NOT NULL,
Name VARCHAR(20) NOT NULL,
Age INT(2),
Gender CHAR(1)
);
insert into Officer values
(1,'Affer Raza',35,'M'),
(2,'Sami Saqib',26,'F'),
(3,'Rehan Khan',22,'M'),
(4,'Zikriya',24,'M'),
(5,'Mahwand Sultan',29,'M');
select * from Officer;

--TASK 6
create table Preferences(
PreferenceID INT(1) NOT NULL,
Preferrence VARCHAR(10)
);
select * from Preferences;

--TASK 7
alter table Preferences add OfficerID INT(1) after PreferenceID;
insert into Preferences values
(1,1,'Manager'),
(2,2,'Supervisor'),
(3,1,'Senior');

--TASK 8
alter table Officer add PRIMARY KEY(OfficerID);
alter table Preferences add CONSTRAINT FOREIGN KEY (OfficerID) REFERENCES Officer(OfficerID);
describe Preferences;
