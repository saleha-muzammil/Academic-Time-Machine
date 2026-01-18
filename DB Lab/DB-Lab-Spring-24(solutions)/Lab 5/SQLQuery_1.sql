-- -- Create database twitter
-- use twitter

-- create table Users
-- (
-- User_ID int,
-- UserName varchar(20) primary key,
-- Age int,
-- Country varchar(20),
-- privacy int
-- )

-- go

-- INSERT [dbo].[users] (User_ID,[UserName], [Age], [Country],privacy) VALUES (1,N'Ali123', 18, N'Pakistan',1)
-- INSERT [dbo].[users] (User_ID,[UserName], [Age], [Country],privacy) VALUES (2,N'Aliza', 40, N'USA',1)
-- INSERT [dbo].[users] (User_ID,[UserName], [Age], [Country],privacy) VALUES (3,N'Aysha', 19, N'Iran',0)
-- INSERT [dbo].[users] (User_ID,[UserName], [Age], [Country],privacy) VALUES (4,N'DonaldTrump', 60, N'USA',0)
-- INSERT [dbo].[users] (User_ID,[UserName], [Age], [Country],privacy) VALUES (5,N'ImranKhan', 55, N'Pakistan',0)
-- INSERT [dbo].[users] (User_ID,[UserName], [Age], [Country],privacy) VALUES (6,N'Natasha', 28, N'USA',0)
-- INSERT [dbo].[users] (User_ID,[UserName], [Age], [Country],privacy) VALUES (7,N'Samuel', 37, N'Australia',0)
-- INSERT [dbo].[users] (User_ID,[UserName], [Age], [Country],privacy) VALUES (8,N'Sara', 30, N'Iran',1)



-- go

-- create table Following
-- (
-- FollowerUserName varchar(20) Foreign key References Users(UserName) ,
-- FollowedUserName varchar(20) Foreign key References Users(UserName),
-- primary key (FollowerUserName, FollowedUserName)
-- )

-- go

-- INSERT [dbo].[Following] ([FollowerUserName], [FollowedUserName]) VALUES (N'Ali123', N'DonaldTrump')
-- INSERT [dbo].[Following] ([FollowerUserName], [FollowedUserName]) VALUES (N'Aliza', N'Ali123')
-- INSERT [dbo].[Following] ([FollowerUserName], [FollowedUserName]) VALUES (N'Aliza', N'DonaldTrump')
-- INSERT [dbo].[Following] ([FollowerUserName], [FollowedUserName]) VALUES (N'Aliza', N'ImranKhan')
-- INSERT [dbo].[Following] ([FollowerUserName], [FollowedUserName]) VALUES (N'Aysha', N'ImranKhan')
-- INSERT [dbo].[Following] ([FollowerUserName], [FollowedUserName]) VALUES (N'DonaldTrump', N'ImranKhan')
-- INSERT [dbo].[Following] ([FollowerUserName], [FollowedUserName]) VALUES (N'ImranKhan', N'DonaldTrump')
-- INSERT [dbo].[Following] ([FollowerUserName], [FollowedUserName]) VALUES (N'Natasha', N'ImranKhan')
-- INSERT [dbo].[Following] ([FollowerUserName], [FollowedUserName]) VALUES (N'Samuel', N'DonaldTrump')
-- INSERT [dbo].[Following] ([FollowerUserName], [FollowedUserName]) VALUES (N'Samuel', N'ImranKhan')
-- INSERT [dbo].[Following] ([FollowerUserName], [FollowedUserName]) VALUES (N'Sara', N'DonaldTrump')

-- go

-- Create table Tweets
-- (
-- TweetID int primary key,
-- UserName varchar(20) Foreign key References Users(UserName),
-- [Text] varchar(140)
-- )

-- go

-- INSERT [dbo].[Tweets] ([TweetID], [UserName], [Text]) VALUES (1, N'Ali123', N'Pakistan’s largest-ever population #Census  starts today in 63 districts after 19 years. ')
-- INSERT [dbo].[Tweets] ([TweetID], [UserName], [Text]) VALUES (2, N'ImranKhan', N'Pakistan’s largest-ever population #Census  starts today in 63 districts after 19 years. ')
-- INSERT [dbo].[Tweets] ([TweetID], [UserName], [Text]) VALUES (3, N'Sara', N'Take the soldier who come to our door for #Census as A ThankYou from Pakistan Army for our devotion. #CensusWithSupportOfArmy')
-- INSERT [dbo].[Tweets] ([TweetID], [UserName], [Text]) VALUES (4, N'ImranKhan', N'Pakistan is going to experience 6th #Census 2017.')
-- INSERT [dbo].[Tweets] ([TweetID], [UserName], [Text]) VALUES (5, N'Sara', N'Only #census can reveal where this aunty lives ')
-- INSERT [dbo].[Tweets] ([TweetID], [UserName], [Text]) VALUES (6, N'ImranKhan', N'Quand tu te lèves 3h en avance (littéralement) pour la #massecritique ')
-- INSERT [dbo].[Tweets] ([TweetID], [UserName], [Text]) VALUES (7, N'Sara', N'Over 1 million decrypted Gmail and Yahoo accounts allegedly up for sale on the Dark Web https://geekz0ne.fr/shaarli/?wQRSoQ  #piratage')
-- INSERT [dbo].[Tweets] ([TweetID], [UserName], [Text]) VALUES (8, N'Sara', N'Harry pot-head and the Sorcerer''s stoned')
-- INSERT [dbo].[Tweets] ([TweetID], [UserName], [Text]) VALUES (9, N'DonaldTrump', N'LSDespicable Me  #DrugMovies')
-- INSERT [dbo].[Tweets] ([TweetID], [UserName], [Text]) VALUES (10, N'ImranKhan', N'Forrest Bump #DrugMovies @midnight')
-- INSERT [dbo].[Tweets] ([TweetID], [UserName], [Text]) VALUES (12, N'DonaldTrump', N'Quand tu te lèves 3h en avance (littéralement) pour la #massecritique ')
-- INSERT [dbo].[Tweets] ([TweetID], [UserName], [Text]) VALUES (13, N'Sara', N'#DrugMovies')
-- INSERT [dbo].[Tweets] ([TweetID], [UserName], [Text]) VALUES (14, N'DonaldTrump', N'Quand tu te lèves 3h en avance (littéralement) pour la #massecritique ')
-- INSERT [dbo].[Tweets] ([TweetID], [UserName], [Text]) VALUES (15, N'Aliza', N'Quand tu te lèves 3h en avance (littéralement) pour la #massecritique ')

-- go

-- Create table Likes
-- (
-- TweetID int Foreign key References Tweets(TweetID),
-- LikeByUserName varchar(20) Foreign key References Users(UserName),
-- LikeOnDate date
-- primary key (TweetID ,LikeByUserName)
-- )

-- GO
-- INSERT [dbo].[Likes] ([TweetID], [LikeByUserName], [LikeOnDate]) VALUES (1, N'Aliza', CAST(0x693C0B00 AS Date))
-- INSERT [dbo].[Likes] ([TweetID], [LikeByUserName], [LikeOnDate]) VALUES (2, N'Aliza', CAST(0x693C0B00 AS Date))
-- go

-- Create table Interests
-- (
-- InterestID int primary key,
-- [Description] varchar(30)
-- )

-- GO
-- INSERT [dbo].[Interests] ([InterestID], [Description]) VALUES (10, N'Politics')
-- INSERT [dbo].[Interests] ([InterestID], [Description]) VALUES (11, N'Sports')
-- INSERT [dbo].[Interests] ([InterestID], [Description]) VALUES (12, N'Movies')
-- INSERT [dbo].[Interests] ([InterestID], [Description]) VALUES (13, N'Education')
-- INSERT [dbo].[Interests] ([InterestID], [Description]) VALUES (14, N'Video Games')

-- go

-- create table UserInterests
-- (UserName varchar(20)  Foreign key References Users(UserName),
-- InterestID int Foreign key References Interests(InterestID)
-- primary key (UserName, InterestID)
--  )
 
--  GO
-- INSERT [dbo].[UserInterests] ([UserName], [InterestID]) VALUES (N'Ali123', 10)
-- INSERT [dbo].[UserInterests] ([UserName], [InterestID]) VALUES (N'Ali123', 11)
-- INSERT [dbo].[UserInterests] ([UserName], [InterestID]) VALUES (N'Ali123', 13)
-- INSERT [dbo].[UserInterests] ([UserName], [InterestID]) VALUES (N'Ali123', 14)
-- INSERT [dbo].[UserInterests] ([UserName], [InterestID]) VALUES (N'Aliza', 10)
-- INSERT [dbo].[UserInterests] ([UserName], [InterestID]) VALUES (N'Aliza', 11)
-- INSERT [dbo].[UserInterests] ([UserName], [InterestID]) VALUES (N'Aliza', 13)
-- INSERT [dbo].[UserInterests] ([UserName], [InterestID]) VALUES (N'Aliza', 14)
-- INSERT [dbo].[UserInterests] ([UserName], [InterestID]) VALUES (N'ImranKhan', 10)
 
--  go

--  Create table Hashtags
--  (HashtagID int primary key,
--  Hashtag varchar(30))
 
--  GO
-- INSERT [dbo].[Hashtags] ([HashtagID], [Hashtag]) VALUES (1, N'#Census')
-- INSERT [dbo].[Hashtags] ([HashtagID], [Hashtag]) VALUES (2, N'#ClassiqueMatin')
-- INSERT [dbo].[Hashtags] ([HashtagID], [Hashtag]) VALUES (3, N'#MasseCritique')
-- INSERT [dbo].[Hashtags] ([HashtagID], [Hashtag]) VALUES (4, N'#piratage')
-- INSERT [dbo].[Hashtags] ([HashtagID], [Hashtag]) VALUES (5, N'#DrugMovies')

-- GO

-- Select * from Following
-- Select * from Hashtags
-- Select * from Interests
-- Select * from Tweets
-- Select * from UserInterests
-- Select * from Users


--Q1
SELECT MAX(age) as [Max Age], MIN(Age) AS [Min Age], ROUND(STDEV(age), 3) AS [Standard Deviation]
FROM Users

--Q2
SELECT followedusername, COUNT(*) AS [Number of Followers]
FROM [following]
GROUP BY followedusername
HAVING (COUNT(*)=(Select top 1 COUNT(*) from [following] GROUP BY followedusername ORDER BY 1 desc))
ORDER BY 2 DESC

--Q3
SELECT followedusername as [User], COUNT(*) AS [Number of Followers]
FROM [following]
GROUP BY followedusername
HAVING (COUNT(*)=(
    (SELECT top 1 intermediateTable.countVal
    FROM (Select DISTINCT top 2 COUNT(*) AS countVal from [following] GROUP BY followedusername ORDER BY 1 DESC) AS intermediateTable
    ORDER BY countVal ASC
    )
    )
)

--Q4
SELECT DISTINCT users.username
FROM Users
LEFT JOIN Tweets
ON users.Username=tweets.username
WHERE tweetid is NULL

--Q5
SELECT hashtag, username, COUNT(*) AS [Number Of Times]
FROM Hashtags
INNER JOIN tweets
ON (CHARINDEX(hashtag, text)>0)    --i.e the hashtag was found within the text
GROUP BY hashtag, username

--Q6
(
SELECT DISTINCT UserName
FROM(
SELECT hashtag, username, COUNT(*) AS [Number Of Times]
FROM Hashtags
INNER JOIN tweets
ON (CHARINDEX(hashtag, text)>0)
GROUP BY hashtag, username
) as midTable2
)
EXCEPT
(
SELECT DISTINCT username as userName
FROM(
SELECT *
FROM(
SELECT hashtag, username, COUNT(*) AS [Number Of Times]
FROM Hashtags
INNER JOIN tweets
ON (CHARINDEX(hashtag, text)>0)
GROUP BY hashtag, username
) as midTable
WHERE hashtag = '#Census'
) as midTable1
)

--Q7
-- (SELECT Username FROM [users])
-- EXCEPT
-- (SELECT DISTINCT followedusername from [following])

--Q8
SELECT username
FROM users as u1
WHERE NOT EXISTS(SELECT followedusername from [following] WHERE u1.username=followedusername)

--used a correlated query as exist would only return true or false if we use a consition

--Q9
-- most common interest
SELECT interests.interestID,description, COUNT(*) as [interestCount]
from interests
INNER JOIN userinterests
ON interests.interestid=userinterests.interestid
GROUP BY interests.interestid, DESCRIPTION
HAVING (count(*)=(SELECT TOP 1 count(*) FROM userinterests GROUP BY interestID order BY 1 desc))
ORDER BY 3 DESC

--least common interest
SELECT interests.interestID,description, COUNT(*) as [interestCount]
from interests
INNER JOIN userinterests
ON interests.interestid=userinterests.interestid
GROUP BY interests.interestid, DESCRIPTION
HAVING (count(*)=(SELECT TOP 1 count(*) FROM userinterests GROUP BY interestID order BY 1 asc))
ORDER BY 3 ASC

--Q10
SELECT country, count(*) as [Number of Tweets]
FROM users
INNER JOIN tweets
ON users.username=tweets.username
GROUP BY country

--Q11
SELECT username, count(*) as [Number of Tweets]
FROM Tweets
GROUP BY username
HAVING (COUNT(*) > (SELECT AVG(midTable.numTweets)
FROM (SELECT count(*) as numTweets FROM tweets GROUP BY username) AS midTable))

--scalar inner query only provides a single value that can be used within having clause for comparison

--Q12
SELECT followedusername as [User Name], COUNT(*) AS [NumFollowersFromPakistan]
FROM users
INNER JOIN [following] 
ON users.username=following.followerusername
WHERE (country='Pakistan')
GROUP BY followedusername

--Q13
SELECT interests.interestID,description, COUNT(*) as [interestCount]
from interests
INNER JOIN userinterests
ON interests.interestid=userinterests.interestid
GROUP BY interests.interestid, DESCRIPTION
HAVING (count(*)=(SELECT TOP 1 count(*) FROM userinterests GROUP BY interestID order BY 1 desc))