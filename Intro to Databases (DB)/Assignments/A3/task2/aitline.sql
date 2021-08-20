create database airplane;

use airplane;

CREATE TABLE AIRPORT( 
Airport_code CHAR(3) NOT NULL,
Airport_name VARCHAR(50) NOT NULL,
City VARCHAR(20) NOT NULL,
State VARCHAR(10),

PRIMARY KEY (Airport_code)
);
describe AIRPORT;
insert INTO AIRPORT VALUES
('SKT','Sialkot International Airport','Sialkot','Pakistan'),
('MUX','Multan International Airport','Multan','Pakistan'),
('LHE','Allama Iqbal International Airport','Lahore','Pakistan'),
('ISB','Islamabad International Airport','Islamabad','Pakistan'),
('KHI','Jinnah International Airport','Karachi','Pakistan'),
('LYP','Faisalabad International Airport','Faisalabad','Pakistan'),
('PEW','Bacha Khan International Airport','Peshawar','Pakistan'),
('UET','Quetta International Airport','Quetta','Pakistan'),
('GWD','Gwadar International Airport','Gwadar','Pakistan'),
('SKZ','Sukkur International Airport','Sukkur','Pakistan');
select * from AIRPORT;

CREATE TABLE FLIGHT( 
Flight_number CHAR(5) NOT NULL,
Airline VARCHAR(40) NOT NULL,
Weekdays INTEGER NOT NULL,

PRIMARY KEY (Flight_number) 
);
describe FLIGHT;
insert INTO FLIGHT VALUES 
('PK303','Pakistan International Airline',4),
('PK322','Pakistan International Airline',1),
('PA974','Airblue Airlines',2),
('PA205','Airblue Airlines',3),
('PK561','Pakistan International Airline',5),
('PK302','Pakistan International Airline',3),
('ER505','Serene Airlines',1),
('PA410','Airblue Airlines',4),
('PK351','Pakistan International Airline',7),
('PK341','Pakistan International Airline',3);
select * from FLIGHT;

CREATE TABLE FLIGHT_LEG( 
Flight_number CHAR(5) NOT NULL,
Leg_number INTEGER NOT NULL,
Departure_airport_code CHAR(3) NOT NULL,
Scheduled_departure_time CHAR(8),
Arrival_airport_code CHAR(3) NOT NULL,
Scheduled_arrival_time CHAR(8),

PRIMARY KEY (Flight_number, Leg_number)
);
describe FLIGHT_LEG;
insert INTO FLIGHT_LEG VALUES
('PK303',1,'LHE','01:20:00','KHI','03:10:00'),
('PK322',2,'LHE','03:30:00','UET','11:50:00'),
('PA974',3,'LHE','12:00:00','SKT','02:30:00'),
('PA205',4,'ISB','01:50:00','KHI','03:20:00'),
('PK561',5,'LHE','05:10:00','ISB','06:30:00'),
('PK302',6,'KHI','06:30:00','LHE','07:10:00'),
('ER505',7,'KHI','07:20:00','ISB','10:50:00'),
('PA410',8,'SKT','02:40:00','GWD','04:40:00'),
('PK351',9,'PEW','09:20:00','KHI','11:30:00'),
('PK341',10,'LYP','7:10:00','LHE','12:20:00');
select * from FLIGHT_LEG;

CREATE TABLE LEG_INSTANCE( 
Flight_number CHAR(5) NOT NULL,
Leg_number INTEGER NOT NULL,
Leg_date DATE NOT NULL,
No_of_available_seats INTEGER,
Airplane_id INTEGER,
Departure_airport_code CHAR(3),
Departure_time CHAR(8),
Arrival_airport_code CHAR(3),
Arrival_time CHAR(8),

PRIMARY KEY (Flight_number, Leg_number, Leg_date)
);
describe LEG_INSTANCE;
insert INTO LEG_INSTANCE VALUES
('PK303',1,'2020-11-10',60,1,'LHE','01:10:00','KHI','10:10:00'),
('PK322',2,'2020-11-11',61,2,'LHE','12:20:00','UET','01:20:00'),
('PA974',3,'2020-11-12',62,3,'LHE','03:10:00','SKT','03:40:00'),
('PA205',4,'2020-11-13',63,4,'ISB','04:40:00','KHI','05:10:00'),
('PK561',5,'2020-11-14',64,5,'LHE','04:50:00','ISB','06:40:00'),
('PK302',6,'2020-11-15',65,6,'KHI','04:30:00','LHE','06:10:00'),
('ER505',7,'2020-11-16',66,7,'KHI','07:20:00','ISB','11:40:00'),
('PA410',8,'2020-11-17',67,8,'SKT','11:30:00','GWD','13:40:00'),
('PK351',9,'2020-11-18',68,9,'PEW','08:40:00','KHI','17:30:00'),
('PK341',10,'2020-11-19',69,10,'LYP','09:50:00','LHE','12:20:00');
select * from LEG_INSTANCE;

CREATE TABLE FARES(
Flight_number CHAR(5) NOT NULL,
Fare_code INTEGER NOT NULL,
Amount INTEGER NOT NULL,
Rrestrictions VARCHAR(3),

PRIMARY KEY (Flight_number, Fare_code)
);
describe FARES;
insert INTO FARES VALUES
('PK303',1,80000,'NO'),
('PK322',2,55000,'YES'),
('PA974',3,30000,NULL),
('PA205',4,95000,'NO'),
('PK561',5,80000,'NO'),
('PK302',6,75000,'NO'),
('ER505',7,80000,NULL),
('PA410',8,95000,'YES'),
('PK351',9,70000,'NO'),
('PK341',10,65000,NULL);
select * from FARES;

CREATE TABLE AIRPLANE_TYPE(
Type_name CHAR(4) NOT NULL,
Max_seats INTEGER NOT NULL,
Company VARCHAR(10) NOT NULL,

PRIMARY KEY (Type_name)
);
describe AIRPLANE_TYPE;
insert INTO AIRPLANE_TYPE VALUES 
('A220',350,'Airbus'),
('A380',290,'Airbus'),
('A318',281,'Airbus'),
('A310',379,'Airbus'),
('A300',262,'Airbus'),
('B787',355,'Boeing'),
('B767',545,'Boeing'),
('B777',330,'Boeing'),
('B747',225,'Boeing'),
('B737',310,'Boeing');
select * from AIRPLANE_TYPE;

CREATE TABLE CAN_LAND(
Airplane_type_name CHAR(4) NOT NULL,
Airport_code CHAR(3) NOT NULL,

PRIMARY KEY (Airplane_type_name, Airport_code)
);
describe CAN_LAND;
insert INTO CAN_LAND VALUES 
('A220','SKT'),
('A300','LHE'),
('A310','ISB'),
('A318','KHI'),
('A380','GWD'),
('B737','LYP'),
('B747','PEW'),
('B767','UET'),
('B777','ISB'),
('B787','KHI');
select * from CAN_LAND;

CREATE TABLE AIRPLANE(
Airplane_id INTEGER NOT NULL,
Total_number_of_seats INTEGER NOT NULL,
Airplane_type CHAR(4) NOT NULL,

PRIMARY KEY (Airplane_id)
);
describe AIRPLANE;
insert INTO AIRPLANE VALUES 
(1,290,'A220'),
(2,380,'A300'),
(3,171,'A310'),
(4,269,'A318'),
(5,352,'A380'),
(6,145,'B737'),
(7,245,'B747'),
(8,330,'B767'),
(9,225,'B777'),
(10,210,'B787');
select * from AIRPLANE;

CREATE TABLE SEAT_RESERVATION( 
Flight_number CHAR(5) NOT NULL,
Leg_number INTEGER NOT NULL,
Leg_date DATE NOT NULL,
Seat_number INTEGER NOT NULL,
Customer_name VARCHAR(30) NOT NULL,
Customer_phone CHAR(11) NOT NULL,

PRIMARY KEY (Flight_number, Leg_number, Leg_Date, Seat_number)
);
describe SEAT_RESERVATION;
insert INTO SEAT_RESERVATION VALUES 
('PK303',1,'2020-11-10',1,'Shahroz','27384967591'),
('PK322',2,'2020-11-11',2,'Hassan','82736456789'),
('PA974',3,'2020-11-12',3,'Sarim','65473829123'),
('PA205',4,'2020-11-13',4,'Hadi','43526178564'),
('PK561',5,'2020-11-14',5,'Kalsoom','26574829453'),
('PK302',6,'2020-11-15',6,'Fatima','01927564352'),
('ER505',7,'2020-11-16',7,'Anser','12938465534'),
('PA410',8,'2020-11-17',8,'Mohid','98765432456'),
('PK351',9,'2020-11-18',9,'Mohsin','98765342511'),
('PK341',10,'2020-11-19',10,'Qasim','82675432191');
select * from SEAT_RESERVATION;

alter table FLIGHT_LEG add CONSTRAINT FOREIGN KEY (Flight_number) REFERENCES FLIGHT (Flight_number) ON DELETE CASCADE ON UPDATE CASCADE;
alter table FLIGHT_LEG add CONSTRAINT FOREIGN KEY (Departure_airport_code) REFERENCES AIRPORT (Airport_code) ON DELETE CASCADE ON UPDATE CASCADE;
alter table FLIGHT_LEG add CONSTRAINT FOREIGN KEY (Arrival_airport_code) REFERENCES AIRPORT (Airport_code) ON DELETE CASCADE ON UPDATE CASCADE;

alter table LEG_INSTANCE add CONSTRAINT FOREIGN KEY (Flight_number) REFERENCES FLIGHT_LEG (Flight_number) ON DELETE CASCADE ON UPDATE CASCADE;
/*alter table LEG_INSTANCE add CONSTRAINT FOREIGN KEY (Leg_number) REFERENCES FLIGHT_LEG (Leg_number) ON DELETE CASCADE ON UPDATE CASCADE;*/
alter table LEG_INSTANCE add CONSTRAINT FOREIGN KEY (Airplane_id) REFERENCES AIRPLANE (Airplane_id) ON DELETE CASCADE ON UPDATE CASCADE;
alter table LEG_INSTANCE add CONSTRAINT FOREIGN KEY (Departure_airport_code) REFERENCES AIRPORT (Airport_code) ON DELETE CASCADE ON UPDATE CASCADE;
alter table LEG_INSTANCE add CONSTRAINT FOREIGN KEY (Arrival_airport_code) REFERENCES AIRPORT (Airport_code) ON DELETE CASCADE ON UPDATE CASCADE;

alter table FARES add CONSTRAINT FOREIGN KEY (Flight_number) REFERENCES FLIGHT (Flight_number) ON DELETE CASCADE ON UPDATE CASCADE;

alter table CAN_LAND add CONSTRAINT FOREIGN KEY (Airplane_type_name) REFERENCES AIRPLANE_TYPE (Type_name) ON DELETE CASCADE ON UPDATE CASCADE;
alter table CAN_LAND add CONSTRAINT FOREIGN KEY (Airport_code) REFERENCES AIRPORT (Airport_code) ON DELETE CASCADE ON UPDATE CASCADE;

alter table AIRPLANE add CONSTRAINT FOREIGN KEY (Airplane_type) REFERENCES AIRPLANE_TYPE (Type_name) ON DELETE CASCADE ON UPDATE CASCADE;

alter table SEAT_RESERVATION add CONSTRAINT FOREIGN KEY (Flight_number, Leg_number, Leg_date) REFERENCES LEG_INSTANCE (Flight_number, Leg_number, Leg_date) ON DELETE CASCADE ON UPDATE CASCADE;
