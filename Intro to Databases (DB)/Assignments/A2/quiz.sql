create database quiz;
use quiz;
-- DROP DATABASE QUIZ;
CREATE TABLE CUSTOMER(
CustId INT(4) NOT NULL,
Cname VARCHAR(25),
City VARCHAR(20),
PRIMARY KEY(CustId));

CREATE TABLE ORDER_(
OrderId INT(8) NOT NULL,
Odate VARCHAR(20),
CustId INT(4),
PRIMARY KEY(OrderId,CustId,Odate),
FOREIGN KEY(CustId) REFERENCES CUSTOMER(CustId)
);

CREATE TABLE ORDER_ITEM(
OrderId INT(8) NOT NULL,
ItemId VARCHAR(8),
Qty INT(4),
PRIMARY KEY(OrderId,ItemId,Qty),
FOREIGN KEY(OrderId) REFERENCES ORDER_(OrderId)
);

CREATE TABLE ITEM(
ItemId VARCHAR(8) NOT NULL,
IName VARCHAR(30),
Unit_price DECIMAL(10,1),
PRIMARY KEY(ItemId)
);

INSERT INTO CUSTOMER VALUES
(1234,'Carine','Lahore'),
(0011,'Jean','Lahore'),
(7891,'Brydey','Karachi'),
(4527,'Thompson','Lahore'),
(2378,'Mike','Karachi');

INSERT INTO ORDER_ VALUES
(10100,'18 November 2020',1234),
(10101,'1 June 2020',2378),
(10105,'3 Feburary 2020',1234),
(10103,'17 Octobor 2020',4527),
(10102,'2 Octobor 2020',1234),
(10101,'7 September 2020',7891),
(10103,'31 November 2020',2378),
(10104,'15 November 2020',1234),
(10106,'11 January 2020',7891),
(10101,'14 August 2020',4527),
(10106,'2 November 2020',2378),
(10103,'5 July 2020',4527),
(10105,'23 November 2020',7891);

INSERT INTO ORDER_ITEM VALUES
(10100,'ABC0041',30),
(10101,'LM2371',70),
(10102,'XY00213',2),
(10103,'HM4569',1),
(10104,'HQ4569',12),
(10105,'QWC0081',21);

INSERT INTO ITEM VALUES
('ABC0041','Lux Beauty Soap 20g',150),
('HQ4569','Lipton Yellow Label 450gm',450),
('QWC0081','Lipton Yellow Label 150gm',150),
('HM4569','Nescafe Coffee',450),
('XY00213','Colgate',250),
('LM2371','Dettol Soap',120);

ALTER TABLE ORDER_ITEM ADD CONSTRAINT FOREIGN KEY(ItemId) REFERENCES ITEM(ItemId)
ON DELETE CASCADE
ON UPDATE CASCADE;

-- Let's see which orders where placed in octobor and in what quantity
SELECT I.ItemId, I.IName, I.Unit_price,O.Odate,Qty FROM ITEM I
JOIN ORDER_ITEM OI ON I.ItemId = OI.ItemId 
JOIN ORDER_ O ON OI.OrderId=O.OrderId
WHERE O.Odate LIKE '% Octobor 2020';

-- find details of maximum ordered item  during octobor 2020
SELECT I.ItemId, I.IName, I.Unit_price, MAX(Qty) FROM ITEM I
JOIN ORDER_ITEM OI ON I.ItemId = OI.ItemId 
JOIN ORDER_ O ON OI.OrderId=O.OrderId
WHERE O.Odate LIKE '% Octobor 2020';

-- Find names of items along with  purchased date which were ordered by customers living in Lahore
SELECT I.IName, O.Odate,C.City FROM ITEM I
JOIN ORDER_ITEM  OI ON I.ItemId=OI.ItemId
JOIN ORDER_ O ON OI.OrderId = O.OrderId
JOIN CUSTOMER C ON O.CustId =C.CustId
WHERE C.City='Lahore';

-- Let's see the customers who lives in Karachi 
SELECT * FROM CUSTOMER WHERE City ='Karachi';
-- Those who have placed an order in November 2020
SELECT * FROM CUSTOMER JOIN ORDER_
ON CUSTOMER.CustId = ORDER_.CustId 
WHERE Odate LIKE '%November 2020';

-- Find total number of orders placed by cutomers living in karachi, in November 2020
SELECT COUNT(CustId) FROM ORDER_ 
WHERE CustId IN(SELECT CustId FROM CUSTOMER
WHERE City='Karachi' ) AND Odate Like '%November 2020'
GROUP BY CustId;

-- OR

SELECT *,COUNT(ORDER_.CustID) AS CountOfOrders FROM CUSTOMER JOIN ORDER_
ON CUSTOMER.CustId = ORDER_.CustId 
WHERE Odate LIKE '%November 2020' 
AND City='Karachi'
GROUP BY(ORDER_.CustId);

-- Name of Customers who have ordered LIPTOPN YELLOW LABEL
SELECT Cname FROM CUSTOMER WHERE CustId IN(
SELECT CustId FROM ORDER_ WHERE OrderId IN(
SELECT OrderId FROM ORDER_ITEM WHERE ItemId IN(
SELECT ItemId FROM ITEM WHERE IName LIKE 'Lipton Yellow Label%')));

-- Details of Customers + count of total orders placed by each cutomer
SELECT C.CustId,C.City,C.Cname,COUNT(ORDER_.CustId) AS CountOfOrders
FROM CUSTOMER C LEFT JOIN ORDER_ ON C.CustId = ORDER_.CustId
GROUP BY ORDER_.CustId;

-- OR 
SELECT  *,(SELECT COUNT(CustId) FROM ORDER_ WHERE CUSTOMER.CustId=ORDER_.CustId) AS Count_Of_Orders
FROM CUSTOMER;
