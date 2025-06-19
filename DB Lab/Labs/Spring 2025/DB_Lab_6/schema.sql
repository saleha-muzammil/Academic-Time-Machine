-- Use master and drop database if it already exists
USE master;
GO
IF EXISTS (SELECT name FROM sys.databases WHERE name = 'Mystical_Adventures')
    DROP DATABASE Mystical_Adventures;
GO

-- Create Database
CREATE DATABASE Mystical_Adventures;
GO
USE Mystical_Adventures;
GO

-- Table: Organizations (General) - Tracks different factions (Created first for dependencies)
CREATE TABLE Organizations (
    OrganizationID INT IDENTITY(1,1) PRIMARY KEY,
    Name NVARCHAR(100) NOT NULL,
    Leader NVARCHAR(100) NOT NULL,
    InfluenceLevel INT NOT NULL CHECK (InfluenceLevel BETWEEN 1 AND 100)
);
GO

-- Table: Missions (General) - Tracks various missions assigned to agents, hunters, and artifacts
CREATE TABLE Missions (
    MissionID INT IDENTITY(1,1) PRIMARY KEY,
    Title NVARCHAR(200) NOT NULL,
    Type NVARCHAR(50) CHECK (Type IN ('Investigation', 'Dungeon Raid', 'Artifact Retrieval', 'Espionage')) NOT NULL,
    DifficultyLevel NVARCHAR(50) CHECK (DifficultyLevel IN ('Low', 'Medium', 'High', 'Extreme')),
    Status NVARCHAR(50) DEFAULT 'Pending' CHECK (Status IN ('Pending', 'Ongoing', 'Completed', 'Failed'))
);
GO

-- Table: Hunters (Solo Leveling) - Linked to Organizations
CREATE TABLE Hunters (
    HunterID INT IDENTITY(1,1) PRIMARY KEY,
    Name NVARCHAR(100) NOT NULL,
    Rank CHAR(1) CHECK (Rank IN ('E', 'D', 'C', 'B', 'A', 'S')) NOT NULL,
    Guild NVARCHAR(100),
    PowerLevel INT NOT NULL,
    OrganizationID INT,
    CONSTRAINT FK_Hunter_Org FOREIGN KEY (OrganizationID) REFERENCES Organizations(OrganizationID) ON DELETE SET NULL
);
GO

-- Table: Agents (General) - Links individuals to Organizations
CREATE TABLE Agents (
    AgentID INT IDENTITY(1,1) PRIMARY KEY,
    Name NVARCHAR(100) NOT NULL,
    Role NVARCHAR(100),
    OrganizationID INT,
    FOREIGN KEY (OrganizationID) REFERENCES Organizations(OrganizationID) ON DELETE SET NULL
);
GO

-- Table: Dungeons (Solo Leveling)
CREATE TABLE Dungeons (
    DungeonID INT IDENTITY(1,1) PRIMARY KEY,
    Name NVARCHAR(100) NOT NULL,
    Difficulty NVARCHAR(3) CHECK (Difficulty IN ('E', 'D', 'C', 'B', 'A', 'S', 'SS', 'SSS')) NOT NULL,
    Boss NVARCHAR(100),
    Status NVARCHAR(10) DEFAULT 'Open' CHECK (Status IN ('Open', 'Cleared'))
);
GO

-- Table: Hunter_Missions (Solo Leveling) - Linking Hunters and Dungeons
CREATE TABLE Hunter_Missions (
    MissionID INT IDENTITY(1,1) PRIMARY KEY,
    HunterID INT,
    DungeonID INT,
    MissionStatus NVARCHAR(10) DEFAULT 'Assigned' CHECK (MissionStatus IN ('Assigned', 'Completed', 'Failed')),
    CONSTRAINT FK_Hunter FOREIGN KEY (HunterID) REFERENCES Hunters(HunterID) ON DELETE CASCADE,
    CONSTRAINT FK_Dungeon FOREIGN KEY (DungeonID) REFERENCES Dungeons(DungeonID) ON DELETE CASCADE
);
GO

-- Table: Beyonders (Lord of the Mysteries) - Linked to Organizations
CREATE TABLE Beyonders (
    BeyonderID INT IDENTITY(1,1) PRIMARY KEY,
    Name NVARCHAR(100) NOT NULL,
    Path NVARCHAR(100) NOT NULL,
    PotionConsumption INT NOT NULL,
    Status NVARCHAR(20) DEFAULT 'Stable' CHECK (Status IN ('Stable', 'At Risk', 'Lost Control')),
    OrganizationID INT,
    CONSTRAINT FK_Beyonder_Org FOREIGN KEY (OrganizationID) REFERENCES Organizations(OrganizationID) ON DELETE SET NULL
);
GO

-- Table: Artifacts (Lord of the Mysteries) - Linking Beyonders and Missions
CREATE TABLE Artifacts (
    ArtifactID INT IDENTITY(1,1) PRIMARY KEY,
    Name NVARCHAR(100) NOT NULL,
    RiskLevel NVARCHAR(10) CHECK (RiskLevel IN ('Low', 'Medium', 'High', 'Extreme')) NOT NULL,
    SealedStatus NVARCHAR(15) DEFAULT 'Sealed' CHECK (SealedStatus IN ('Sealed', 'Compromised', 'Lost')),
    GuardianID INT,
    MissionID INT,
    CONSTRAINT FK_Guardian FOREIGN KEY (GuardianID) REFERENCES Beyonders(BeyonderID) ON DELETE SET NULL,
    CONSTRAINT FK_Artifact_Mission FOREIGN KEY (MissionID) REFERENCES Missions(MissionID) ON DELETE SET NULL
);
GO

-- Table: Mission_Assignments (General) - Links Agents, Hunters, and Missions
CREATE TABLE Mission_Assignments (
    AssignmentID INT IDENTITY(1,1) PRIMARY KEY,
    MissionID INT,
    AgentID INT NULL,
    HunterID INT NULL,
    Role NVARCHAR(100) NOT NULL,
    FOREIGN KEY (MissionID) REFERENCES Missions(MissionID) ON DELETE CASCADE,
    FOREIGN KEY (AgentID) REFERENCES Agents(AgentID) ON DELETE SET NULL,
    FOREIGN KEY (HunterID) REFERENCES Hunters(HunterID) ON DELETE SET NULL
);
GO

-- Table: Intelligence_Reports (General) - Tracks reports related to missions
CREATE TABLE Intelligence_Reports (
    ReportID INT IDENTITY(1,1) PRIMARY KEY,
    MissionID INT,
    SubmittedBy NVARCHAR(100) NOT NULL,
    ReportContent NVARCHAR(MAX) NOT NULL,
    DateSubmitted DATETIME DEFAULT GETDATE(),
    FOREIGN KEY (MissionID) REFERENCES Missions(MissionID) ON DELETE CASCADE
);
GO


-- Insert Data into Organizations
INSERT INTO Organizations (Name, Leader, InfluenceLevel) VALUES
('Hunters Association', 'Go Gunhee', 95),
('Bureau of Investigation', 'Sherlock Holmes', 90),
('Church of Evernight', 'Cardinal Snake', 85),
('Secret Order', 'Adam', 80),
('Mystic Guardians', 'Elias', 75),
('Nighthawks', 'Dunn Smith', 70),
('Psykers Union', 'Xio Derecha', 65),
('Royal Observers', 'King George', 60),
('Shadow Society', 'Amon', 55),
('Celestial Hunters', 'Jin-Woo', 99);
GO

-- Insert Data into Missions
INSERT INTO Missions (Title, Type, DifficultyLevel, Status) VALUES
('Investigate the Shadow Cult', 'Investigation', 'High', 'Ongoing'),
('Retrieve the Sealed Artifact', 'Artifact Retrieval', 'Extreme', 'Pending'),
('Hunt the Demon King', 'Dungeon Raid', 'Extreme', 'Pending'),
('Espionage in the Royal Palace', 'Espionage', 'High', 'Completed'),
('Stop the Abyssal Ritual', 'Investigation', 'High', 'Failed'),
('Secure the Golden Scarab', 'Artifact Retrieval', 'Medium', 'Pending'),
('Eliminate the Rogue Hunter', 'Investigation', 'High', 'Ongoing'),
('Explore the Forgotten Dungeon', 'Dungeon Raid', 'Medium', 'Ongoing'),
('Break the Curse of Nightfall', 'Investigation', 'Extreme', 'Pending'),
('Intercept the Forbidden Tome', 'Espionage', 'Medium', 'Completed');
GO

-- Insert Data into Hunters
INSERT INTO Hunters (Name, Rank, Guild, PowerLevel, OrganizationID) VALUES
('Sung Jin-Woo', 'S', 'Solo Player', 9999, 10),
('Thomas Andre', 'S', 'Scavenger Guild', 9500, 1),
('Lennart Niermann', 'S', 'Germany Guild', 8700, 1),
('Christopher Reed', 'S', 'USA Guild', 8900, 1),
('Goto Ryuji', 'S', 'Japan Guild', 8600, 1),
('Sidis Neumann', 'A', 'Free Agent', 7200, 1),
('Jin Ah', 'B', 'Korea Guild', 5400, 10),
('Baek Yoonho', 'A', 'White Tiger Guild', 7500, 1),
('Cha Hae-In', 'S', 'Hunters Guild', 9200, 1),
('Woo Jinchul', 'A', 'Korea Guild', 7300, 10);
GO

-- Insert Data into Agents
INSERT INTO Agents (Name, Role, OrganizationID) VALUES
('Arthas Moonshadow', 'Field Investigator', 2),
('Elena Storm', 'Spy', 4),
('Lucius Cain', 'Artifact Researcher', 3),
('Valeria Nightshade', 'Infiltrator', 6),
('Draven Thorn', 'Espionage Specialist', 7),
('Cassius Vale', 'Tactician', 5),
('Seraphina Evermore', 'Diplomatic Agent', 8),
('Dorian Blackwood', 'Battle Mage', 9),
('Morgan Frost', 'Strategist', 1),
('Orion Graves', 'Enforcer', 10);
GO

-- Insert Data into Dungeons
INSERT INTO Dungeons (Name, Difficulty, Boss, Status) VALUES
('Red Gate of Doom', 'SS', 'Demon Monarch', 'Open'),
('Everlasting Abyss', 'S', 'Void Warden', 'Open'),
('Frozen Tundra Lair', 'A', 'Frost Titan', 'Cleared'),
('Shadow Realm Gate', 'SSS', 'King of Shadows', 'Open'),
('Necropolis of Despair', 'B', 'Undead General', 'Cleared'),
('Caverns of Nightmares', 'C', 'Nightmare Bringer', 'Open'),
('Crimson Eclipse Rift', 'S', 'Blood Sorcerer', 'Open'),
('Abyssal Labyrinth', 'A', 'Dark Minotaur', 'Cleared'),
('Sunken Catacombs', 'D', 'Ghost King', 'Cleared'),
('Sky Fortress Ruins', 'B', 'Storm Colossus', 'Open');
GO

-- Insert Data into Hunter_Missions
INSERT INTO Hunter_Missions (HunterID, DungeonID, MissionStatus) VALUES
(1, 1, 'Assigned'),
(2, 2, 'Completed'),
(3, 3, 'Failed'),
(4, 4, 'Assigned'),
(5, 5, 'Completed'),
(6, 6, 'Assigned'),
(7, 7, 'Failed'),
(8, 8, 'Completed'),
(9, 9, 'Assigned'),
(10, 10, 'Completed');
GO

-- Insert Data into Beyonders
INSERT INTO Beyonders (Name, Path, PotionConsumption, Status, OrganizationID) VALUES
('Klein Moretti', 'Seer', 3, 'Stable', 3),
('Dwayne Dant�s', 'Spectator', 2, 'Stable', 3),
('Roselle Gustav', 'Emperor', 5, 'Lost Control', 5),
('Amon', 'Parasitic Thief', 4, 'At Risk', 9),
('Adam', 'Manipulator', 6, 'Stable', 4),
('Zaratul', 'Mystic Traveler', 7, 'Lost Control', 6),
('Medici', 'Demon King', 8, 'At Risk', 7),
('Herabergan', 'Eternal Blazing Sun', 3, 'Stable', 8),
('Antigonus', 'Evernight Priest', 9, 'Lost Control', 2),
('Mystra', 'Arcane Sorcerer', 4, 'At Risk', 10);
GO

-- Insert Data into Artifacts
INSERT INTO Artifacts (Name, RiskLevel, SealedStatus, GuardianID, MissionID) VALUES
('Eye of the Abyss', 'High', 'Sealed', 1, 2),
('Crown of Forgotten Kings', 'Medium', 'Compromised', 2, 5),
('Shadow Orb', 'High', 'Lost', 3, 7),
('Tome of the Ancients', 'Extreme', 'Sealed', 4, 10),
('Phantom Dagger', 'Medium', 'Sealed', 5, 1),
('Scepter of Eternal Night', 'High', 'Compromised', 6, 3),
('Cursed Mirror', 'Extreme', 'Lost', 7, 8),
('Frostheart Amulet', 'Low', 'Sealed', 8, 4),
('Necronomicon', 'Extreme', 'Compromised', 9, 6),
('Ring of Shadows', 'Medium', 'Sealed', 10, 9);
GO

-- Insert Data into Mission_Assignments
INSERT INTO Mission_Assignments (MissionID, AgentID, HunterID, Role) VALUES
(1, 1, NULL, 'Lead Investigator'),
(2, 2, 1, 'Artifact Recovery Specialist'),
(3, NULL, 2, 'Dungeon Explorer'),
(4, 3, NULL, 'Espionage Handler'),
(5, NULL, 3, 'Cult Hunter'),
(6, 4, NULL, 'Information Analyst'),
(7, NULL, 4, 'Battle Commander'),
(8, 5, 5, 'Strategist'),
(9, NULL, 6, 'Dark Arts Researcher'),
(10, 6, 7, 'Infiltrator');
GO

-- Insert Data into Intelligence Reports
INSERT INTO Intelligence_Reports (MissionID, SubmittedBy, ReportContent, DateSubmitted) VALUES
(1, 'Arthas Moonshadow', 'Shadow Cult activity detected in the southern ruins.', GETDATE()),
(2, 'Lucius Cain', 'Sealed artifact retrieved successfully.', GETDATE()),
(3, 'Elena Storm', 'The Demon King is amassing an army.', GETDATE()),
(4, 'Draven Thorn', 'Espionage successful; no traces left behind.', GETDATE()),
(5, 'Cassius Vale', 'Abyssal Ritual failed due to unexpected intervention.', GETDATE()),
(6, 'Seraphina Evermore', 'Golden Scarab found but heavily guarded.', GETDATE()),
(7, 'Morgan Frost', 'Rogue Hunter eliminated in stealth operation.', GETDATE()),
(8, 'Orion Graves', 'Forgotten Dungeon mapped; artifacts recovered.', GETDATE()),
(9, 'Dorian Blackwood', 'Curse of Nightfall broken using holy incantations.', GETDATE()),
(10, 'Ezekiel Voss', 'Forbidden Tome intercepted from smugglers.', GETDATE());
GO
