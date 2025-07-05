-- Create database and use it
CREATE DATABASE lab5E;
USE lab5E;

-- Create table named hotel
CREATE TABLE hotel(
    hotelno VARCHAR(10) PRIMARY KEY,
    hotelname VARCHAR(20),
    city VARCHAR(20)
);

-- Insert values into hotel table
INSERT INTO hotel VALUES('fb01', 'Grosvenor', 'London');
INSERT INTO hotel VALUES('fb02', 'Watergate', 'Paris');
INSERT INTO hotel VALUES('ch01', 'Omni Shoreham', 'London');
INSERT INTO hotel VALUES('ch02', 'Phoenix Park', 'London');
INSERT INTO hotel VALUES('dc01', 'Latham', 'Berlin');
INSERT INTO hotel VALUES('dc02', 'PC', 'PAKISTAN');

-- Create table named room
CREATE TABLE room(
    roomno NUMERIC(5),
    hotelno VARCHAR(10),
    type VARCHAR(10),
    price DECIMAL(5,2),
    PRIMARY KEY (roomno, hotelno),
    FOREIGN KEY (hotelno) REFERENCES hotel(hotelno)
);

-- Insert values into room table
INSERT INTO room VALUES(501, 'fb01', 'single', 19);
INSERT INTO room VALUES(601, 'fb01', 'double', 29);
INSERT INTO room VALUES(701, 'fb01', 'family', 39);
INSERT INTO room VALUES(1001, 'fb02', 'single', 58);
INSERT INTO room VALUES(1101, 'fb02', 'double', 86);
INSERT INTO room VALUES(1001, 'ch01', 'single', 29.99);
INSERT INTO room VALUES(1101, 'ch01', 'family', 59.99);
INSERT INTO room VALUES(701, 'ch02', 'single', 10);
INSERT INTO room VALUES(801, 'ch02', 'double', 15);
INSERT INTO room VALUES(901, 'dc01', 'single', 18);
INSERT INTO room VALUES(1001, 'dc01', 'double', 30);
INSERT INTO room VALUES(1101, 'dc01', 'family', 35);

-- Create table named guest
CREATE TABLE guest(
    guestno NUMERIC(5),
    guestname VARCHAR(20),
    guestaddress VARCHAR(50),
    PRIMARY KEY (guestno)
);

-- Insert values into guest table
INSERT INTO guest VALUES(10001, 'John Kay', '56 High St, London');
INSERT INTO guest VALUES(10002, 'Mike Ritchie', '18 Tain St, London');
INSERT INTO guest VALUES(10003, 'Mary Tregear', '5 Tarbot Rd, Aberdeen');
INSERT INTO guest VALUES(10004, 'Joe Keogh', '2 Fergus Dr, Aberdeen');
INSERT INTO guest VALUES(10005, 'Carol Farrel', '6 Achray St, Glasgow');
INSERT INTO guest VALUES(10006, 'Tina Murphy', '63 Well St, Glasgow');
INSERT INTO guest VALUES(10007, 'Tony Shaw', '12 Park Pl, Glasgow');
INSERT INTO guest VALUES(10008, 'WAHAJ', 'PAKISTAN');

-- Create table named booking
CREATE TABLE booking(
    hotelno VARCHAR(10),
    guestno NUMERIC(5),
    datefrom DATETIME,
    dateto DATETIME,
    roomno NUMERIC(5),
    PRIMARY KEY (hotelno, guestno, datefrom),
    FOREIGN KEY (roomno, hotelno) REFERENCES room(roomno, hotelno),
    FOREIGN KEY (guestno) REFERENCES guest(guestno)
);

-- Insert values into booking table
INSERT INTO booking VALUES('fb01', 10001, '2004-04-01', '2004-04-08', 501);
INSERT INTO booking VALUES('fb01', 10004, '2004-04-15', '2004-05-15', 601);
INSERT INTO booking VALUES('fb01', 10005, '2004-05-02', '2004-05-07', 501);
INSERT INTO booking VALUES('fb01', 10001, '2004-05-01', NULL, 701);
INSERT INTO booking VALUES('fb02', 10003, '2004-04-05', '2010-04-04', 1001);
INSERT INTO booking VALUES('ch01', 10006, '2004-04-21', NULL, 1101);
INSERT INTO booking VALUES('ch02', 10002, '2004-04-25', '2004-05-06', 801);
INSERT INTO booking VALUES('dc01', 10007, '2004-05-13', '2004-05-15', 1001);
INSERT INTO booking VALUES('dc01', 10003, '2004-05-20', NULL, 1001);

-- Select data from tables
SELECT * FROM booking;
SELECT * FROM guest;
SELECT * FROM hotel;
SELECT * FROM room;