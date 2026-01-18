--QUESTION 1

-- select cardTypeID, count(cardTypeID) as numberOfUsers 
-- from [user]
-- inner join UserCard on [user].userid=UserCard.userID
-- inner join Card on UserCard.cardNum=Card.cardNum
-- group by Card.cardTypeID

--QUESTION 2

-- select [user].name, Card.cardNum
-- from [user]
-- inner join UserCard on [user].userid=UserCard.userID
-- inner join Card on UserCard.cardNum=Card.cardNum
-- where (balance>=20000 AND balance<=40000)

--QUESTION 3
--a)
-- user - usercard will gice users with no cards

-- select userid, [name]
-- from [user]
-- where userid=(
-- (select userid from [User])
-- EXCEPT
-- (SELECT userID from UserCard)
-- )

--b)

-- select [user].userid, [name]
-- FROM [User]
-- LEFT JOIN UserCard
-- on [user].userid=[UserCard].userID
-- where cardNum is NULL

--QUESTION 4

--a)

-- SELECT user.userid, user.name 
-- from [User]
-- where
-- (
--     select cardNum from UserCard
--     where 
--     UserID=(
--     (Select userid from [User])
--     INTERSECT  
--     (Select userid from [UserCard]))
-- )


--b)
-- select DISTINCT ([Card].cardNum) As CardNumber, [user].name, [CardType].name as CardType, transDate
-- from [User]
-- join [UserCard] on [user].userId=UserCard.userID
-- join [Card] on [userCard].cardNum=Card.cardNum
-- join [CardType] on [Card].cardTypeID=CardType.cardTypeID
-- join [Transaction] on [Card].cardNum=[Transaction].cardNum
-- where (year(GETDATE())-Year(transDate))>=1

--QUESTION 5

-- select * from [Transaction]

-- select cardType.name as CardType, count(amount) as countTrans, sum(amount) as sumAmount
-- from [Transaction]
-- join Card on card.cardNum=[transaction].cardNum
-- join cardType on card.cardTypeID=CardType.cardTypeID
-- where (year(transDate)=2015 OR year(transDate)=2016 OR year(transDate)=2017 )
-- group by [CardType].name
-- having sum(amount)>=6000

--Note that the sum() and date condition means that very few rows are selected from the table

--QUESTION 6

-- select [user].userId, [user].name, phoneNum, city, card.cardNum, cardType.name, card.expireDate
-- from [User]
-- INNER JOIN UserCard on [user].userId=UserCard.userID
-- INNER JOIN Card on [UserCard].cardNum=Card.cardNum
-- INNER JOIN CardType on [card].cardTypeID=CardType.cardTypeID
-- where ((YEAR(GETDATE())=YEAR(Card.expireDate)) AND abs((MONTH(GETDATE())-MONTH(card.expireDate))) <= 3)

--QUESTION 7

-- select [user].userId, [user].name, sum(card.balance) as SumOfBalance
-- from [User]
-- join UserCard on [user].userId=UserCard.userID
-- join card on [UserCard].cardNum=card.cardNum
-- group by [user].userID, [user].name

--Note that we are grouping by both name and id as we want to display the names(i.e. can be used with select clause)


--QUESTION 8

-- select cardRel1.CardNum as Card_1, cardRel1.expireDate as Expiry_1, cardRel2.CardNum as Card_2, cardRel2.expireDate as Expiry_2
-- FROM Card as cardRel1
-- join Card as cardRel2
-- on cardRel1.expireDate!=cardRel2.expireDate
-- where ((year(cardRel1.expireDate) - year(cardRel2.expireDate)) = 0) --i.e the same year

--QUESTION 9

-- select user_1.name as Name_1, user_2.name as Name_2
-- from [user] as user_1
-- join [user] as user_2 
-- on user_1.name!=user_2.name
-- where (user_1.name LIKE 'A%' AND user_2.name LIKE 'A%')

--QUESTION 10

-- (
--     select [user].userid, [User].name, CardType.name as CardName
--     from [User]
--     join UserCard on [user].userID=UserCard.userID
--     join Card on UserCard.cardNum=card.cardNum
--     join CardType on card.cardTypeID=cardType.cardTypeID
--     where cardType.name='Debit'
-- )
-- INTERSECT
-- (
--     select [user].userid, [User].name, CardType.name as CardName
--     from [User]
--     join UserCard on [user].userID=UserCard.userID
--     join Card on UserCard.cardNum=card.cardNum
--     join CardType on card.cardTypeID=cardType.cardTypeID
--     where cardType.name='Credit' 
-- )

--QUESTION 11

-- select city as cityName, count(city)
-- from [user] 
-- group by city
