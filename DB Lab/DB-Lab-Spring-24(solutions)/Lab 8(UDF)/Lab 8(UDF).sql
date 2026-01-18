use master
go
drop  database ATM
go 
Create database ATM
go 
use ATM
go

create table [User](
[userId] int primary key,
[name] varchar(20) not null,
[phoneNum] varchar(15) not null,
[city] varchar(20) not null
)
go

create table CardType(
[cardTypeID] int primary key,
[name] varchar(15),
[description] varchar(40) null
)
go
create Table [Card](
cardNum Varchar(20) primary key,
cardTypeID int foreign key references  CardType([cardTypeID]),
PIN varchar(4) not null,
[expireDate] date not null,
balance float not null
)
go


Create table UserCard(
userID int foreign key references [User]([userId]),
cardNum varchar(20) foreign key references [Card](cardNum),
primary key(cardNum)
)
go
create table [Transaction](
transId int primary key,
transDate date not null,
cardNum varchar(20) foreign key references [Card](cardNum),
amount int not null
)


INSERT [dbo].[User] ([userId], [name], [phoneNum], [city]) VALUES (1, N'Ali', N'03036067000', N'Narowal')
GO
INSERT [dbo].[User] ([userId], [name], [phoneNum], [city]) VALUES (2, N'Ahmed', N'03036047000', N'Lahore')
GO
INSERT [dbo].[User] ([userId], [name], [phoneNum], [city]) VALUES (3, N'Aqeel', N'03036063000', N'Karachi')
GO
INSERT [dbo].[User] ([userId], [name], [phoneNum], [city]) VALUES (4, N'Usman', N'03036062000', N'Sialkot')
GO
INSERT [dbo].[User] ([userId], [name], [phoneNum], [city]) VALUES (5, N'Hafeez', N'03036061000', N'Lahore')
GO


INSERT [dbo].[CardType] ([cardTypeID], [name], [description]) VALUES (1, N'Debit', N'Spend Now, Pay Now')
GO
INSERT [dbo].[CardType] ([cardTypeID], [name], [description]) VALUES (2, N'Credit', N'Spend Now, Pay later')
GO

INSERT [dbo].[Card] ([cardNum], [cardTypeID], [PIN], [expireDate], [balance]) VALUES (N'1234', 1, N'1770', CAST(N'2022-07-01' AS Date), 43025.31)
GO
INSERT [dbo].[Card] ([cardNum], [cardTypeID], [PIN], [expireDate], [balance]) VALUES (N'1235', 1, N'9234', CAST(N'2020-03-02' AS Date), 14425.62)
GO
INSERT [dbo].[Card] ([cardNum], [cardTypeID], [PIN], [expireDate], [balance]) VALUES (N'1236', 1, N'1234', CAST(N'2019-02-06' AS Date), 34325.52)
GO
INSERT [dbo].[Card] ([cardNum], [cardTypeID], [PIN], [expireDate], [balance]) VALUES (N'1237', 2, N'1200', CAST(N'2021-02-05' AS Date), 24325.3)
GO
INSERT [dbo].[Card] ([cardNum], [cardTypeID], [PIN], [expireDate], [balance]) VALUES (N'1238', 2, N'9004', CAST(N'2020-09-02' AS Date), 34025.12)
GO

INSERT [dbo].[UserCard] ([userID], [cardNum]) VALUES (1, N'1234')
GO
INSERT [dbo].[UserCard] ([userID], [cardNum]) VALUES (1, N'1235')
GO
INSERT [dbo].[UserCard] ([userID], [cardNum]) VALUES (2, N'1236')
GO
INSERT [dbo].[UserCard] ([userID], [cardNum]) VALUES (3, N'1238')
GO
Insert  [dbo].[UserCard] ([userID], [cardNum]) VALUES (4, N'1237')

INSERT [dbo].[Transaction] ([transId], [transDate], [cardNum], [amount]) VALUES (1, CAST(N'2017-02-02' AS Date), N'1234', 500)
GO
INSERT [dbo].[Transaction] ([transId], [transDate], [cardNum], [amount]) VALUES (2, CAST(N'2018-02-03' AS Date), N'1235', 3000)
GO
INSERT [dbo].[Transaction] ([transId], [transDate], [cardNum], [amount]) VALUES (3, CAST(N'2020-01-06' AS Date), N'1236', 2500)
GO
INSERT [dbo].[Transaction] ([transId], [transDate], [cardNum], [amount]) VALUES (4, CAST(N'2016-09-09' AS Date), N'1238', 2000)
GO
INSERT [dbo].[Transaction] ([transId], [transDate], [cardNum], [amount]) VALUES (5, CAST(N'2020-02-10' AS Date), N'1234', 6000)
GO


Select * from [User]
Select * from UserCard
Select * from [Card]
Select * from CardType
Select * from [Transaction]



--Question 1
CREATE FUNCTION [retBalance](@cardNumber varchar(20))
RETURNS FLOAT
AS
BEGIN
	DECLARE @bal FLOAT
	SELECT @bal=[Card].balance FROM Card WHERE cardNum=@cardNumber
	RETURN @bal
END

DECLARE @bal FLOAT='1235'
SELECT dbo.retBalance(@bal) AS Balance


--Question 2
CREATE FUNCTION [retUserDetails](@uID INT)
RETURNS TABLE
AS
	RETURN SELECT*
	FROM [User] WHERE [User].userId=@uID

SELECT * FROM [retUserDetails](2)


--Question 3
CREATE PROCEDURE [retUserDetailsFromName]
@name VARCHAR(20)
AS
BEGIN
	SELECT * FROM [User] WHERE [User].name=@name
END

DECLARE @uName VARCHAR(20)='Aqeel'
EXECUTE [retUserDetailsFromName]
@name=@uName


--Question 4
CREATE PROCEDURE [displayOwnerDetails]
@uID INT
AS
BEGIN
	SELECT  cardNum, dbo.retBalance(UserCard.cardNum) AS Balance from UserCard where userID=@uID
END

DECLARE @ID INT=2
EXECUTE [displayOwnerDetails]
@uID=@ID


--QUESTION 5
CREATE FUNCTION [showCardDetails](@uID INT)
RETURNS TABLE
AS
	RETURN SELECT cardNum, dbo.retBalance(cardNum) AS BALANCE
	FROM [UserCard] WHERE userId=@uID

SELECT * FROM [showCardDetails](1)


--QUESTION 6
CREATE PROCEDURE [getNumCards]
@uID INT,
@numOfCards INT OUTPUT
AS
BEGIN
	SELECT @numOfCards=COUNT(*) FROM [UserCard] GROUP BY userID HAVING userID=@uID
END

DECLARE @ID INT=2, @nCards INT=0
EXECUTE [getNumCards]
@uID=@ID,
@numOfCards=@nCards OUTPUT
SELECT @ID as [User ID], @nCards as [Number Of Cards]


--QUESTION 7
CREATE PROCEDURE [LoginCard2]
@cNum VARCHAR(20),
@pinCode VARCHAR(4),
@status INT OUTPUT
AS
BEGIN
	IF EXISTS(Select * FROM [Card] WHERE (cardNum=@cNum AND PIN=@pinCode))
		BEGIN
			SET @status=1
		END
	ELSE
		BEGIN
			SET @status=0
		END
END

DECLARE @cn VARCHAR(20)='1234', @p VARCHAR(4)='1777',@out INT
EXECUTE [LoginCard2]
@cNum=@cn,
@pinCode=@p,
@status=@out OUTPUT
SELECT @out AS Valid

--we can write a function that will return the status as the return value



--QUESTION 8
CREATE PROCEDURE [updatePIN1]
@cNum VARCHAR(20),
@oldPIN VARCHAR(4),
@newPIN VARCHAR(4)
AS
BEGIN
	IF (EXISTS(Select * FROM [Card] WHERE (cardNum=@cNum AND PIN=@oldPIN)) AND LEN(@newPIN)=4)
		BEGIN
			UPDATE [Card] SET PIN=@newPIN Where (cardNum=@cNum)
			print('PIN is updated')
		END
	ELSE
		BEGIN
			print('Error')
		END
END

DECLARE @cn VARCHAR(20)='1234', @oldp VARCHAR(4)='1888',@newp VARCHAR(4)='1999'
EXECUTE [updatePIN1]
@cNum=@cn,
@oldPIN=@oldp,
@newPIN=@newp

select * from [Card]


--QUESTION 9
CREATE PROCEDURE [withDraw1]
@cN VARCHAR(20),
@cPin VARCHAR(4),
@transAmount int
AS
BEGIN
	DECLARE @out INT
	EXECUTE dbo.[LoginCard2]
	@cNum=@cN,
	@pinCode=@cPin,
	@status=@out OUTPUT
	if (@out=1)
		BEGIN
			if (@transAmount<=(select balance from [Card] where cardNum=@cN))
				BEGIN
					--retrieve the max value from the table
					DECLARE @maxTransID INT
					select top 1 @maxTransID=transId from [Transaction] order by transID DESC
					--insert into the transaction table
					insert into [Transaction]
					values
					(@maxTransID+1, GETDATE(), @cN, @transAmount)
					--update the balance in the card table
					Update [Card]
					set balance=balance-@transAmount
					where cardNum=@cN
					print('Transaction succesful')
				END
			ELSE
				BEGIN
					print('Insufficient balance')
				END
		END
	ELSE
		BEGIN
			print('Incorrect card details entered')
		END
END


Declare @cNum varchar(20)='1234', @pin varchar(4)='1999', @amount int='20000' 
EXECUTE [withDraw1]
@cN=@cNum,
@cPin=@pin,
@transAmount=@amount

