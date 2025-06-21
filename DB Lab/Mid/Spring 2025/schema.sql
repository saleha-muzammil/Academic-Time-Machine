use master
GO
IF EXISTS (SELECT name FROM sys.databases WHERE name = 'PWL2')
BEGIN
    DROP DATABASE PWL2;
END
GO
create database PWL2;
GO
use PWL2;
GO

-- Trainers Table
CREATE TABLE Trainers (
    TrainerID INT PRIMARY KEY IDENTITY(1,1),
    Name VARCHAR(100) NOT NULL,
    Region VARCHAR(50),
    JoinDate DATE DEFAULT GETDATE()
);
GO
-- Pokémon Table
CREATE TABLE Pokemon (
    PokemonID INT PRIMARY KEY IDENTITY(1,1),
    Name VARCHAR(50) NOT NULL,
    Type1 VARCHAR(20) NOT NULL,
    Type2 VARCHAR(20) NULL
);
GO
-- Trainer_Pokemon (4NF: Resolving Multi-Valued Dependency)
CREATE TABLE Trainer_Pokemon (
    TrainerID INT FOREIGN KEY REFERENCES Trainers(TrainerID) ON DELETE CASCADE,
    PokemonID INT FOREIGN KEY REFERENCES Pokemon(PokemonID) ON DELETE CASCADE,
    Nickname VARCHAR(50) NULL,
    PRIMARY KEY (TrainerID, PokemonID)
);
GO
-- Gym Badges Table
CREATE TABLE GymBadges (
    BadgeID INT PRIMARY KEY IDENTITY(1,1),
    BadgeName VARCHAR(50) NOT NULL,
    Region VARCHAR(50) NOT NULL
);
GO
-- Trainer_Badges (4NF: Each Trainer Can Have Multiple Badges)
CREATE TABLE Trainer_Badges (
    TrainerID INT FOREIGN KEY REFERENCES Trainers(TrainerID) ON DELETE CASCADE,
    BadgeID INT FOREIGN KEY REFERENCES GymBadges(BadgeID) ON DELETE CASCADE,
    EarnedDate DATE NOT NULL,
    PRIMARY KEY (TrainerID, BadgeID)
);
GO
-- Battles Table
CREATE TABLE Battles (
    BattleID INT PRIMARY KEY IDENTITY(1,1),
    BattleDate DATETIME DEFAULT GETDATE(),
    WinnerID INT FOREIGN KEY REFERENCES Trainers(TrainerID) ON DELETE NO ACTION,
    LoserID INT FOREIGN KEY REFERENCES Trainers(TrainerID) ON DELETE NO ACTION,
);
GO
-- Tournaments Table
CREATE TABLE Tournaments (
    TournamentID INT PRIMARY KEY IDENTITY(1,1),
    TournamentName VARCHAR(100) NOT NULL,
    StartDate DATE NOT NULL,
    EndDate DATE NOT NULL,
    PrizeMoney DECIMAL(10,2) NOT NULL
);
GO
-- Tournament Participants Table
CREATE TABLE Tournament_Participants (
    TournamentID INT FOREIGN KEY REFERENCES Tournaments(TournamentID) ON DELETE CASCADE,
    TrainerID INT FOREIGN KEY REFERENCES Trainers(TrainerID) ON DELETE CASCADE,
    Placement INT NOT NULL,
    PrizeWon DECIMAL(10,2) DEFAULT 0,
    PRIMARY KEY (TournamentID, TrainerID)
);
GO
INSERT INTO Trainers (Name, Region, JoinDate) VALUES
('Ash Ketchum', 'Kanto', '2000-01-01'),
('Brock', 'Pewter', '1998-06-15'),
('Misty', 'Cerulean', '1999-03-10'),
('Gary Oak', 'Pallet Town', '2001-09-25'),
('Cynthia', 'Sinnoh', '2003-07-12'),
('Steven Stone', 'Hoenn', '2002-05-21'),
('Lance', 'Johto', '2001-12-05'),
('Dawn', 'Sinnoh', '2004-08-08'),
('Iris', 'Unova', '2005-10-30'),
('Leon', 'Galar', '2006-11-11'),
('MK', 'Asia', '2007-11-11')
GO
INSERT INTO Pokemon (Name, Type1, Type2) VALUES
('Pikachu', 'Electric', NULL),
('Charizard', 'Fire', 'Flying'),
('Bulbasaur', 'Grass', 'Poison'),
('Squirtle', 'Water', NULL),
('Gengar', 'Ghost', 'Poison'),
('Dragonite', 'Dragon', 'Flying'),
('Lucario', 'Fighting', 'Steel'),
('Tyranitar', 'Rock', 'Dark'),
('Garchomp', 'Dragon', 'Ground'),
('Snorlax', 'Normal', NULL);
GO
INSERT INTO Trainer_Pokemon (TrainerID, PokemonID, Nickname) VALUES
(1, 1, 'Sparky'),      -- Ash's Pikachu
(1, 2, 'Blaze'),       -- Ash's Charizard
(2, 4, 'Shellshock'),  -- Brock's Squirtle
(3, 3, 'Bulby'),       -- Misty's Bulbasaur
(4, 5, 'Shadow'),      -- Gary's Gengar
(5, 6, 'Drago'),       -- Cynthia's Dragonite
(6, 7, 'Aura'),        -- Steven's Lucario
(7, 8, 'Tyrant'),      -- Lance's Tyranitar
(8, 9, 'Chomper'),     -- Dawn's Garchomp
(9, 10, 'Snorelord');  -- Iris's Snorlax
GO
INSERT INTO GymBadges (BadgeName, Region) VALUES
('Boulder Badge', 'Kanto'),
('Cascade Badge', 'Kanto'),
('Thunder Badge', 'Kanto'),
('Rainbow Badge', 'Kanto'),
('Marsh Badge', 'Kanto'),
('Volcano Badge', 'Kanto'),
('Earth Badge', 'Kanto'),
('Zephyr Badge', 'Johto'),
('Hive Badge', 'Johto'),
('Storm Badge', 'Johto');
GO
INSERT INTO Trainer_Badges (TrainerID, BadgeID, EarnedDate) VALUES
(1, 1, '2000-02-10'),
(1, 2, '2000-03-15'),
(1, 3, '2000-04-20'),
(2, 4, '1998-07-01'),
(3, 5, '1999-04-12'),
(4, 6, '2001-10-10'),
(5, 7, '2003-08-20'),
(6, 8, '2002-06-15'),
(7, 9, '2001-12-25'),
(8, 10, '2004-09-01');
GO
INSERT INTO Battles (BattleDate, WinnerID, LoserID) VALUES
('2024-01-10', 1, 2),
('2024-01-12', 3, 4),
('2024-01-15', 5, 6),
('2024-01-18', 7, 8),
('2024-01-20', 9, 10),
('2024-02-01', 2, 3),
('2024-02-05', 4, 5),
('2024-02-10', 6, 7),
('2024-02-15', 8, 9),
('2024-02-20', 10, 1);
GO
INSERT INTO Battles (BattleDate, WinnerID, LoserID) VALUES
('2025-01-10', 1, 10),
('2025-01-12', 1, 4),
('2025-01-15', 1, 6),
('2025-01-18', 1, 8),
('2025-01-20', 1, 10)
GO
INSERT INTO Battles (BattleDate, WinnerID, LoserID) VALUES
('2024-01-10', 1, 10),
('2024-01-12', 1, 4),
('2024-01-15', 1, 6),
('2024-01-18', 1, 8),
('2024-01-20', 1, 10)
GO
INSERT INTO Tournaments (TournamentName, StartDate, EndDate, PrizeMoney) VALUES
('Kanto League', '2023-10-01', '2023-10-10', 5000),
('Johto League', '2023-11-01', '2023-11-10', 6000),
('Hoenn League', '2023-12-01', '2023-12-10', 7000),
('Sinnoh League', '2024-01-01', '2024-01-10', 8000),
('Unova League', '2024-02-01', '2024-02-10', 9000),
('Kalos League', '2024-03-01', '2024-03-10', 10000),
('Alola League', '2024-04-01', '2024-04-10', 11000),
('Galar League', '2024-05-01', '2024-05-10', 12000),
('World Championship', '2024-06-01', '2024-06-10', 15000),
('Elite Four Tournament', '2024-07-01', '2024-07-10', 20000);
GO
INSERT INTO Tournament_Participants (TournamentID, TrainerID, Placement, PrizeWon) VALUES
(1, 1, 1, 5000),
(1, 2, 2, 3000),
(2, 3, 1, 6000),
(2, 4, 3, 2000),
(3, 5, 1, 7000),
(3, 6, 2, 4000),
(4, 7, 1, 8000),
(4, 8, 4, 1000),
(5, 9, 2, 5000),
(5, 10, 1, 9000);
GO