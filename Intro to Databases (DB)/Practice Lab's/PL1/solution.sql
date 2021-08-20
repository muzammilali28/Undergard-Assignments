-- phpMyAdmin SQL Dump
-- version 5.0.3
-- https://www.phpmyadmin.net/
--
-- Host: localhost
-- Generation Time: Nov 23, 2020 at 07:49 AM
-- Server version: 10.4.14-MariaDB
-- PHP Version: 7.4.11

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
START TRANSACTION;
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;

--
-- Database: `bonus_db`
--
CREATE DATABASE IF NOT EXISTS `bonus_db` DEFAULT CHARACTER SET latin1 COLLATE latin1_swedish_ci;
USE `bonus_db`;

-- --------------------------------------------------------

--
-- Table structure for table `fillings`
--

DROP TABLE IF EXISTS `fillings`;
CREATE TABLE IF NOT EXISTS `fillings` (
  `vid` int(11) DEFAULT NULL,
  `sid` int(11) DEFAULT NULL,
  `amount` int(11) DEFAULT NULL,
  KEY `sid` (`sid`),
  KEY `vid` (`vid`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Truncate table before insert `fillings`
--

TRUNCATE TABLE `fillings`;
--
-- Dumping data for table `fillings`
--

INSERT INTO `fillings` (`vid`, `sid`, `amount`) VALUES
(1, 2, 230),
(1, 1, 1110),
(2, 3, 1070),
(2, 5, 1030),
(1, 3, 1170),
(1, 4, 550),
(1, 5, 1010),
(1, 6, 440),
(1, 7, 680),
(2, 6, 1030),
(2, 4, 1030),
(2, 2, 1170),
(2, 1, 1030),
(2, 7, 1000),
(2, 8, 1500),
(4, 1, 770),
(3, 1, 130),
(5, 2, 220),
(3, 2, 1010),
(3, 3, 1010),
(5, 1, 1010),
(5, 4, 1010),
(5, 5, 1010),
(6, 1, 1010),
(6, 2, 1010),
(6, 3, 1010),
(6, 4, 1010),
(6, 5, 1010),
(7, 1, 550),
(7, 2, 550),
(7, 3, 550),
(7, 4, 550),
(7, 5, 550),
(7, 7, 550),
(8, 1, 1200),
(8, 7, 800),
(8, 3, 1200),
(8, 8, 2000),
(8, 5, 1800),
(8, 4, 950);

-- --------------------------------------------------------

--
-- Table structure for table `person`
--

DROP TABLE IF EXISTS `person`;
CREATE TABLE IF NOT EXISTS `person` (
  `pid` int(11) NOT NULL,
  `pname` varchar(20) NOT NULL,
  `paddress` varchar(50) NOT NULL,
  PRIMARY KEY (`pid`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Truncate table before insert `person`
--

TRUNCATE TABLE `person`;
--
-- Dumping data for table `person`
--

INSERT INTO `person` (`pid`, `pname`, `paddress`) VALUES
(1, 'Omer Saleem', 'House #123 Block B Johar Town Lahore '),
(2, 'Saleem Ahmed', 'House #456 Block C Model Town Lahore '),
(3, 'Kaleem Ali', 'Flat #32C New Gulshan Heights, Lahore'),
(4, 'Ahsan Hayat', 'House #32C Block D PCSIR Phase 1, Lahore'),
(5, 'Nabeel Mirza', 'House #86 Block D Garhi Shahu, Lahore'),
(6, 'Kashif Khan', '1 Khayaban-e-Jinnah, Johar Town, Lahore'),
(7, 'Asad Kabeer', 'Shop # 23 Old Anar Kali, Lahore'),
(8, 'Muhammad Mohsin', 'Flat # 3d, Liberty Market, Lahore'),
(9, 'Fareed Khan', 'House #53, Saleem Block, Garden Town, Lahore');

-- --------------------------------------------------------

--
-- Table structure for table `station`
--

DROP TABLE IF EXISTS `station`;
CREATE TABLE IF NOT EXISTS `station` (
  `sid` int(11) NOT NULL,
  `sname` varchar(20) DEFAULT NULL,
  PRIMARY KEY (`sid`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Truncate table before insert `station`
--

TRUNCATE TABLE `station`;
--
-- Dumping data for table `station`
--

INSERT INTO `station` (`sid`, `sname`) VALUES
(1, 'Xoom Gulberg'),
(2, 'Shell Liberty'),
(3, 'Shell Canal'),
(4, 'GO Johr Town'),
(5, 'Go Firdous Market'),
(6, 'Xoom Saddar'),
(7, 'PSO Airport'),
(8, 'Shell Saddar');

-- --------------------------------------------------------

--
-- Table structure for table `vehicle`
--

DROP TABLE IF EXISTS `vehicle`;
CREATE TABLE IF NOT EXISTS `vehicle` (
  `vid` int(11) NOT NULL,
  `vmake` varchar(15) DEFAULT NULL,
  `vmodel` varchar(15) DEFAULT NULL,
  `vyear` char(4) DEFAULT NULL,
  `oid` int(11) DEFAULT NULL,
  PRIMARY KEY (`vid`),
  KEY `oid_fkey` (`oid`)
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Truncate table before insert `vehicle`
--

TRUNCATE TABLE `vehicle`;
--
-- Dumping data for table `vehicle`
--

INSERT INTO `vehicle` (`vid`, `vmake`, `vmodel`, `vyear`, `oid`) VALUES
(1, 'Toyota', 'Corolla XLI', '2011', 1),
(2, 'Toyota', 'Corolla GLI', '2013', 2),
(3, 'Toyota', 'Corolla XLI', '2011', 3),
(4, 'Honda', 'City', '2015', 4),
(5, 'Honda', 'Civic', '2011', 5),
(6, 'Suzuki', 'WagonR', '2016', 6),
(7, 'Suzuki', 'Cultus', '2015', 7),
(8, 'Suzuki', 'Mehran', '2003', 8);

--
-- Constraints for dumped tables
--

--
-- Constraints for table `fillings`
--
ALTER TABLE `fillings`
  ADD CONSTRAINT `fillings_ibfk_1` FOREIGN KEY (`sid`) REFERENCES `station` (`sid`),
  ADD CONSTRAINT `fillings_ibfk_2` FOREIGN KEY (`vid`) REFERENCES `vehicle` (`vid`);

--
-- Constraints for table `vehicle`
--
ALTER TABLE `vehicle`
  ADD CONSTRAINT `oid_fkey` FOREIGN KEY (`oid`) REFERENCES `person` (`pid`);
COMMIT;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;

use bonus_db;

/*Find the Owner Names and Details of the Vehicles who spent at least 1000 rupees on every petrol pump where Omer Saleem spent 1000 rupees on any of his vehicles.*/
select S.sid from Station S where S.sid IN(select F.sid from fillings F where amount>=1000 and F.vid IN(select V.vid from vehicle V where V.oid IN(select P.pid from Person P where P.pname="Omer Saleem"))); /*Station ID where Omer spent >=1000*/

select Per.pname,Veh.* from Person Per join vehicle Veh on Per.pid=Veh.oid where Veh.vid IN
(select Fil.vid from fillings Fil where amount>=1000 and Fil.sid IN
(select S.sid from Station S where S.sid IN
(select F.sid from fillings F where amount>=1000 and F.vid IN
(select V.vid from vehicle V where V.oid IN
(select P.pid from Person P where P.pname="Omer Saleem")))) group by Fil.vid);
