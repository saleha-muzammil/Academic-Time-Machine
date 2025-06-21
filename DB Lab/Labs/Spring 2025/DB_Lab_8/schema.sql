-- Create the PakLegionWebToonDB database
CREATE DATABASE PakLegionWebToonDB;
GO

-- Switch to the newly created database
USE PakLegionWebToonDB;
GO

-- Create the Regions table
CREATE TABLE Regions (
    RegionID INT PRIMARY KEY IDENTITY(1,1),
    RegionName NVARCHAR(100) NOT NULL,
    CulturalSignificance NVARCHAR(MAX)
);
GO

-- Create the Characters table
CREATE TABLE Characters (
    CharacterID INT PRIMARY KEY IDENTITY(1,1),
    CharacterName NVARCHAR(100) NOT NULL,
    Alias NVARCHAR(100),
    Age INT,
    BackgroundStory NVARCHAR(MAX),
    RegionID INT,
    CONSTRAINT FK_Characters_Regions FOREIGN KEY (RegionID) REFERENCES Regions(RegionID)
);
GO

-- Create the Superpowers table
CREATE TABLE Superpowers (
    PowerID INT PRIMARY KEY IDENTITY(1,1),
    PowerName NVARCHAR(100) NOT NULL,
    Description NVARCHAR(MAX)
);
GO

-- Create the CharacterSuperpowers junction table
CREATE TABLE CharacterSuperpowers (
    CharacterID INT,
    PowerID INT,
    ProficiencyLevel NVARCHAR(50),
    PRIMARY KEY (CharacterID, PowerID),
    CONSTRAINT FK_CharacterSuperpowers_Characters FOREIGN KEY (CharacterID) REFERENCES Characters(CharacterID),
    CONSTRAINT FK_CharacterSuperpowers_Superpowers FOREIGN KEY (PowerID) REFERENCES Superpowers(PowerID)
);
GO

-- Create the Teams table
CREATE TABLE Teams (
    TeamID INT PRIMARY KEY IDENTITY(1,1),
    TeamName NVARCHAR(100) NOT NULL,
    MissionStatement NVARCHAR(MAX)
);
GO

-- Create the CharacterTeams junction table
CREATE TABLE CharacterTeams (
    CharacterID INT,
    TeamID INT,
    JoinDate DATE,
    RoleInTeam NVARCHAR(100),
    PRIMARY KEY (CharacterID, TeamID),
    CONSTRAINT FK_CharacterTeams_Characters FOREIGN KEY (CharacterID) REFERENCES Characters(CharacterID),
    CONSTRAINT FK_CharacterTeams_Teams FOREIGN KEY (TeamID) REFERENCES Teams(TeamID)
);
GO

-- Create the Artifacts table
CREATE TABLE Artifacts (
    ArtifactID INT PRIMARY KEY IDENTITY(1,1),
    ArtifactName NVARCHAR(100) NOT NULL,
    Origin NVARCHAR(100),
    PowersGranted NVARCHAR(MAX),
    CurrentHolderID INT,
    CONSTRAINT FK_Artifacts_Characters FOREIGN KEY (CurrentHolderID) REFERENCES Characters(CharacterID)
);
GO

-- Create the CharacterAlliances table
CREATE TABLE CharacterAlliances (
    CharacterID1 INT,
    CharacterID2 INT,
    AllianceType NVARCHAR(50),
    PRIMARY KEY (CharacterID1, CharacterID2),
    CONSTRAINT FK_CharacterAlliances_Character1 FOREIGN KEY (CharacterID1) REFERENCES Characters(CharacterID),
    CONSTRAINT FK_CharacterAlliances_Character2 FOREIGN KEY (CharacterID2) REFERENCES Characters(CharacterID)
);
GO

-- Sample Data

-- Insert Regions
INSERT INTO Regions (RegionName, CulturalSignificance) VALUES
('Punjab', 'Heartland of ancient warrior traditions'),
('Sindh', 'Land of mystic river civilizations'),
('Khyber', 'Gateway of legendary strategists');
GO

-- Insert Characters
INSERT INTO Characters (CharacterName, Alias, Age, BackgroundStory, RegionID) VALUES
('Zoravar Singh', 'Iron Lion', 28, 'Disgraced prince seeking redemption', 1),
('Sana Jilani', 'Desert Fox', 24, 'Nomadic hacker with ancient codes', 2),
('Khalid Durrani', 'Mountain Ghost', 35, 'Ex-military tracker gone rogue', 3),
('Layla Qureshi', 'Veiled Vengeance', 22, 'Heiress to mystic artifacts', 1);
GO

-- Insert Superpowers
INSERT INTO Superpowers (PowerName, Description) VALUES
('Telekinesis', 'Control objects with mind'),
('Pyrokinesis', 'Generate and control fire'),
('Sand Manipulation', 'Control desert environments'),
('Enhanced Reflexes', 'Superhuman reaction time');
GO

-- Link Characters to Superpowers
INSERT INTO CharacterSuperpowers (CharacterID, PowerID, ProficiencyLevel) VALUES
(1, 1, 'Master'),
(1, 4, 'Master'),
(2, 3, 'Expert'),
(3, 1, 'Adept'),
(4, 2, 'Novice');
GO

-- Create Teams
INSERT INTO Teams (TeamName, MissionStatement) VALUES
('Guardians of Lahore', 'Protect Punjab''s ancient secrets'),
('Sindh Shadows', 'Preserve river valley mysteries'),
('Khyber Sentinels', 'Guard the mountain passages');
GO

-- Assign Characters to Teams
INSERT INTO CharacterTeams (CharacterID, TeamID, JoinDate, RoleInTeam) VALUES
(2, 1, '2024-02-22', 'Double Agent'),
(1, 1, '2023-01-15', 'Field Leader'),
(2, 2, '2023-02-20', 'Tech Specialist'),
(3, 3, '2023-03-10', 'Recon Expert'),
(4, 1, '2023-04-05', 'Artifact Handler');
GO

-- Add Artifacts
INSERT INTO Artifacts (ArtifactName, Origin, PowersGranted, CurrentHolderID) VALUES
('Golden Pistol', 'Sindh', 'Mobile Snatching', 1),
('Ruby of Multan', 'Ancient Punjab', 'Fire resistance', 1),
('Mohenjo-Daro Seal', 'Indus Valley', 'Water control', 2),
('Khyber Dagger', 'Mountain Forges', 'Enhanced stealth', 3);
GO

-- Create Alliances
INSERT INTO CharacterAlliances (CharacterID1, CharacterID2, AllianceType) VALUES
(1, 2, 'Temporary Truce'),
(3, 4, 'Reluctant Partnership'),
(2, 4, 'Secret Alliance');
GO
