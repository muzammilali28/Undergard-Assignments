
drop database bankschema;
create database bankschema;
use bankschema;


DROP TABLE IF EXISTS bank;

CREATE TABLE bank (
  bank_id int(11) NOT NULL,
  bank_name varchar(30) DEFAULT NULL,
  HeadOfficeAddress varchar(100) DEFAULT NULL,
  startDate date DEFAULT NULL,
  PRIMARY KEY (bank_id)
);




INSERT INTO bank VALUES (1,'Muslim Commercial Bank Limited','MCB House, 15 - Main Gulberg, Jail Road, Lahore','1947-07-09'),(2,'Allied Bank Limited','Plot No. 74, Sheet GK-7, M.W. Tower, M.A. Jinnah Road, Karachi','1942-12-03'),(3,'United Bank Limited','UBL Warehouse Building,Mai Kolachi Road, Karachi.','1959-11-07');


DROP TABLE IF EXISTS branch;

CREATE TABLE branch (
  branch_id varchar(15) NOT NULL,
  bank_id int(11) DEFAULT NULL,
  branch_address varchar(60) DEFAULT NULL,
  PRIMARY KEY (branch_id),
  KEY bank_id (bank_id),
  CONSTRAINT branch_ibfk_1 FOREIGN KEY (bank_id) REFERENCES bank (bank_id)
);


INSERT INTO branch VALUES ('ABL001',2,'Iqbal Town branch Lahore'),('ABL002',2,'Johar Town branch Lahore'),('ABL003',2,'Barkat Market branch Lahore'),('MCB001',1,'Moon Market branch Lahore'),('MCB002',1,'15, Jail road branch Lahore'),('UBL001',3,'Baghban pura branch Lahore'),('UBL002',3,'Thokar niaz baig branch Lahore');


DROP TABLE IF EXISTS customer;

CREATE TABLE customer (
  customer_id varchar(15) NOT NULL,
  name varchar(20) DEFAULT NULL,
  Address varchar(100) DEFAULT NULL,
  phoneNum varchar(15) DEFAULT NULL,
  PRIMARY KEY (customer_id)
);



INSERT INTO customer VALUES ('332021832675','Imran Khan','16-A Johar Town Lahore','92313212321'),('332021832676','M. Kareem','78 Korangi Town, Karachi','92323212322'),('332021832677','Ali Ahmad','90 Kemari Town, Karachi','92323212324'),('332021832678','Waqar Azeem','23-C Qasimabad, Haiderabad','92353212329'),('352017898532','Ahsan ALi','19-J Johar Town Lahore','923126455982'),('352021832671','Anwar Majeed','58-B Wapda Town,Multan','92343212311'),('352021832672','Zubair ALi','16-A Johar Town Lahore','92343212312'),('352021832673','Ahtasham Khan','33-Y Nazamabad, Karachi','92343212322'),('352021832674','M. ALi','76-C Faisal Town Lahore','92343212321'),('362021832675','Imtiaz Khan','21-D Johar Town Lahore','92323212323'),('362021832676','Shafqat Ali','32-H Liari, Karachi','92323212326');



DROP TABLE IF EXISTS loanaccounts;

CREATE TABLE loanaccounts (
  Account_number varchar(20) NOT NULL,
  branch_id varchar(15) DEFAULT NULL,
  max_credit int(11) DEFAULT NULL,
  customer_id varchar(15) DEFAULT NULL,
  current_credit int(11) DEFAULT NULL,
  PRIMARY KEY (Account_number),
  KEY customer_id (customer_id),
  KEY branch_id (branch_id),
  CONSTRAINT loanaccounts_ibfk_1 FOREIGN KEY (customer_id) REFERENCES customer (customer_id),
  CONSTRAINT loanaccounts_ibfk_2 FOREIGN KEY (branch_id) REFERENCES branch (branch_id)
);

INSERT INTO loanaccounts VALUES ('lbABL501','ABL002',30000,'352021832671',12000),('lbABL502','ABL003',100000,'352021832672',70000),('lbABL601','ABL002',200000,'352021832673',38000),('lbMCB701','MCB002',26000,'332021832677',5400),('lbUBL201','UBL002',95000,'332021832676',60000),('lbUBL301','UBL001',75000,'332021832675',30000),('lbUBL401','UBL002',40000,'352021832674',15000);



DROP TABLE IF EXISTS savingaccounts;

CREATE TABLE savingaccounts (
  Account_number varchar(20) NOT NULL,
  branch_id varchar(15) DEFAULT NULL,
  customer_id varchar(15) DEFAULT NULL,
  current_balance int(11) DEFAULT NULL,
  PRIMARY KEY (Account_number),
  KEY customer_id (customer_id),
  KEY branch_id (branch_id),
  CONSTRAINT savingaccounts_ibfk_1 FOREIGN KEY (customer_id) REFERENCES customer (customer_id),
  CONSTRAINT savingaccounts_ibfk_2 FOREIGN KEY (branch_id) REFERENCES branch (branch_id)
);


INSERT INTO savingaccounts VALUES ('sbABL107','ABL002','332021832677',32800),('sbABL109','ABL001','352017898532',59000),('sbABL303','ABL001','352021832674',36000),('sbMCB100','MCB002','362021832676',32800),('sbMCB101','MCB002','362021832675',32800),('sbUBL103','UBL002','332021832676',32800),('sbUBL105','UBL002','332021832678',32800),('sbUBL204','UBL001','332021832675',930000);


DROP TABLE IF EXISTS transaction;

CREATE TABLE transaction (
  transaction_id varchar(10) NOT NULL,
  transaction_amount int(11) DEFAULT NULL,
  transaction_date date DEFAULT NULL,
  loanAccount_number varchar(20) DEFAULT NULL,
  savingAccount_number varchar(20) DEFAULT NULL,
  transactionDetails varchar(50) DEFAULT NULL,
  eid varchar(10) DEFAULT NULL,
  PRIMARY KEY (transaction_id),
  KEY loanAccount_number (loanAccount_number),
  KEY savingAccount_number (savingAccount_number),
 
  CONSTRAINT transaction_ibfk_2 FOREIGN KEY (loanAccount_number) REFERENCES loanaccounts (Account_number),
  CONSTRAINT transaction_ibfk_3 FOREIGN KEY (savingAccount_number) REFERENCES savingaccounts (Account_number)
);


INSERT INTO transaction VALUES ('tr101',-30000,'2016-01-08',NULL,'sbABL303','debited amount for personal use','ABLB101'),('tr1010',-26000,'2017-05-07',NULL,'sbUBL105','For home renovation','UBLB202'),('tr1011',27000,'2017-06-06',NULL,'sbMCB101','For Employees salries','MCB202'),('tr1012',-23000,'2018-01-05',NULL,'sbMCB101','For purchasing LED','MCB203'),('tr1013',-32000,'2018-02-04',NULL,'sbMCB100','debited amount for personal use','MCB203'),('tr1014',30000,'2017-03-03',NULL,'sbMCB100','For purchasing LED','MCB202'),('tr102',800000,'2017-02-07',NULL,'sbABL303','credited amount of sold car','ABLB102'),('tr103',30000,'2016-03-06',NULL,'sbUBL204','For Office use','UBLB101'),('tr104',28000,'2017-04-05',NULL,'sbUBL204','For utility bills','UBLB103'),('tr105',-25000,'2016-05-04',NULL,'sbUBL103','For Employees salaries','UBLB201'),('tr106',20000,'2018-01-03',NULL,'sbUBL103','salary credited','UBLB202'),('tr107',-15500,'2016-02-02',NULL,'sbABL107','debited amount for personal use','ABLB203'),('tr108',12000,'2016-03-01',NULL,'sbABL107','For Office use','ABLB203'),('tr109',14000,'2017-04-08',NULL,'sbUBL105','For utility bills','UBLB201'),('tr201',900000,'2017-04-09','lbABL501',NULL,'For purchasing AC','ABLB202'),('tr2010',60000,'2017-05-02','lbUBL301',NULL,'For purchasing Mobile Phone','UBLB103'),('tr2011',90000,'2017-07-03','lbUBL201',NULL,'For purchasing AC','UBLB201'),('tr2012',95000,'2017-08-04','lbUBL201',NULL,'For purchasing Laptop','UBLB202'),('tr2013',20000,'2017-09-05','lbMCB701',NULL,'For purchasing AC','MCB202'),('tr2014',15000,'2017-10-08','lbMCB701',NULL,'For purchasing Washing Machine','MCB203'),('tr202',85000,'2017-04-10','lbABL501',NULL,'For purchasing LED','ABLB203'),('tr203',95000,'2017-05-09','lbABL502',NULL,'For purchasing Fridge','ABLB301'),('tr204',100000,'2017-04-11','lbABL502',NULL,'For purchasing Furniture for office','ABLB303'),('tr205',175000,'2017-03-11','lbABL601',NULL,'For purchasing Home Furniture','ABLB203'),('tr206',150000,'2017-04-05','lbABL601',NULL,'For purchasing LED','ABLB202'),('tr207',40000,'2017-01-09','lbUBL401',NULL,'For purchasing UPS','UBLB201'),('tr208',30000,'2017-02-09','lbUBL401',NULL,'For purchasing LED','UBLB201'),('tr209',70000,'2017-03-09','lbUBL301',NULL,'For purchasing Car tyres','UBLB101');

