-- reset database
IF EXISTS (SELECT name FROM sys.databases WHERE name = 'CursedTitansDB')
BEGIN
	use master;
	drop database CursedTitansDB;
    CREATE DATABASE CursedTitansDB;
END
GO

-- Use the database
USE CursedTitansDB;
GO

-- Drop existing tables if they exist (for rerun safety)
DROP TABLE IF EXISTS Battle_Participants, Character_Techniques, Battle_Techniques, Mission_Assignments, Character_Artifacts;
DROP TABLE IF EXISTS Characters, Battles, Locations, Techniques, Artifacts, Missions, Prophecies;

-- Table for Characters (Titan-shifters, Jujutsu sorcerers, or both)
CREATE TABLE Characters (
    character_id INT IDENTITY(1,1) PRIMARY KEY,
    name NVARCHAR(100) NOT NULL,
    faction NVARCHAR(50) CHECK (faction IN ('Titan-shifter', 'Jujutsu Sorcerer', 'Hybrid')),
    titan_form NVARCHAR(100) NULL, -- Null if not a Titan-shifter
    cursed_technique NVARCHAR(100) NULL, -- Null if not a Sorcerer
    rank NVARCHAR(50), -- e.g., "Elite", "Captain"
    backstory TEXT,
    created_at DATETIME DEFAULT GETDATE()
);

-- Table for Locations (Walls, cursed shrines, battlefields)
CREATE TABLE Locations (
    location_id INT IDENTITY(1,1) PRIMARY KEY,
    name NVARCHAR(100) NOT NULL UNIQUE,
    type NVARCHAR(50) CHECK (type IN ('Wall', 'Cursed Shrine', 'Battlefield')),
    cursed_contamination_level INT CHECK (cursed_contamination_level BETWEEN 0 AND 100),
    historical_significance TEXT,
    created_at DATETIME DEFAULT GETDATE()
);

-- Table for Battles (events where characters fought)
CREATE TABLE Battles (
    battle_id INT IDENTITY(1,1) PRIMARY KEY,
    location_id INT NOT NULL,
    battle_date DATETIME NOT NULL,
    outcome NVARCHAR(100), -- e.g., "Victory", "Defeat", "Stalemate"
    summary TEXT,
    FOREIGN KEY (location_id) REFERENCES Locations(location_id) ON DELETE CASCADE
);

-- Many-to-Many: Characters participating in Battles
CREATE TABLE Battle_Participants (
    battle_id INT,
    character_id INT,
    PRIMARY KEY (battle_id, character_id),
    FOREIGN KEY (battle_id) REFERENCES Battles(battle_id) ON DELETE CASCADE,
    FOREIGN KEY (character_id) REFERENCES Characters(character_id) ON DELETE CASCADE
);

-- Table for Techniques (Titan abilities & Jujutsu techniques)
CREATE TABLE Techniques (
    technique_id INT IDENTITY(1,1) PRIMARY KEY,
    name NVARCHAR(100) NOT NULL UNIQUE,
    type NVARCHAR(50) CHECK (type IN ('Titan Ability', 'Jujutsu Technique')),
    power_level INT CHECK (power_level BETWEEN 1 AND 100),
    description TEXT,
    created_at DATETIME DEFAULT GETDATE()
);

-- Many-to-Many: Characters mastering Techniques
CREATE TABLE Character_Techniques (
    character_id INT,
    technique_id INT,
    mastery_level INT CHECK (mastery_level BETWEEN 1 AND 100),
    last_updated DATETIME DEFAULT GETDATE(),
    PRIMARY KEY (character_id, technique_id),
    FOREIGN KEY (character_id) REFERENCES Characters(character_id) ON DELETE CASCADE,
    FOREIGN KEY (technique_id) REFERENCES Techniques(technique_id) ON DELETE CASCADE
);

-- Many-to-Many: Techniques used in Battles
CREATE TABLE Battle_Techniques (
    battle_id INT,
    technique_id INT,
    PRIMARY KEY (battle_id, technique_id),
    FOREIGN KEY (battle_id) REFERENCES Battles(battle_id) ON DELETE CASCADE,
    FOREIGN KEY (technique_id) REFERENCES Techniques(technique_id) ON DELETE CASCADE
);

-- Table for Ancient Artifacts
CREATE TABLE Artifacts (
    artifact_id INT IDENTITY(1,1) PRIMARY KEY,
    name NVARCHAR(100) NOT NULL UNIQUE,
    effect TEXT,
    rarity NVARCHAR(50) CHECK (rarity IN ('Common', 'Rare', 'Legendary')),
    discovered_at DATETIME DEFAULT GETDATE()
);

-- Many-to-Many: Characters possessing Artifacts
CREATE TABLE Character_Artifacts (
    character_id INT,
    artifact_id INT,
    PRIMARY KEY (character_id, artifact_id),
    FOREIGN KEY (character_id) REFERENCES Characters(character_id) ON DELETE CASCADE,
    FOREIGN KEY (artifact_id) REFERENCES Artifacts(artifact_id) ON DELETE CASCADE
);

-- Table for Prophecies (foreshadowing events)
CREATE TABLE Prophecies (
    prophecy_id INT IDENTITY(1,1) PRIMARY KEY,
    title NVARCHAR(200) NOT NULL,
    content TEXT,
    predicted_outcome TEXT,
    created_at DATETIME DEFAULT GETDATE()
);

-- Table for Missions (team-based operations)
CREATE TABLE Missions (
    mission_id INT IDENTITY(1,1) PRIMARY KEY,
    objective TEXT NOT NULL,
    status NVARCHAR(50) CHECK (status IN ('Pending', 'Ongoing', 'Completed', 'Failed')),
    success_criteria TEXT,
    discovered_clues TEXT,
    mission_date DATETIME NOT NULL,
    created_at DATETIME DEFAULT GETDATE()
);

-- Many-to-Many: Characters assigned to Missions
CREATE TABLE Mission_Assignments (
    mission_id INT,
    character_id INT,
    PRIMARY KEY (mission_id, character_id),
    FOREIGN KEY (mission_id) REFERENCES Missions(mission_id) ON DELETE CASCADE,
    FOREIGN KEY (character_id) REFERENCES Characters(character_id) ON DELETE CASCADE
);

-- Use the database
USE CursedTitansDB;
GO

-- Insert data into Characters
INSERT INTO Characters (name, faction, titan_form, cursed_technique, rank, backstory)
VALUES 
('Eren Yeager', 'Hybrid', 'Attack Titan', 'Binding Vows', 'Elite', 'Once a soldier, now a revolutionary.'),
('Gojo Satoru', 'Jujutsu Sorcerer', NULL, 'Limitless', 'Captain', 'Strongest sorcerer of his time.'),
('Levi Ackerman', 'Titan-shifter', 'Beast Titan', NULL, 'Elite', 'Legendary fighter with lightning-fast strikes.'),
('Yuji Itadori', 'Hybrid', 'War Hammer Titan', 'Divergent Fist', 'Elite', 'A host of Sukuna with Titan abilities.'),
('Mikasa Ackerman', 'Jujutsu Sorcerer', NULL, 'Heavenly Restriction', 'Elite', 'A warrior with immense physical prowess.');

-- Insert data into Locations
INSERT INTO Locations (name, type, cursed_contamination_level, historical_significance)
VALUES 
('Wall Maria', 'Wall', 30, 'The first major Titan breach occurred here.'),
('Cursed Shrine of Ryomen Sukuna', 'Cursed Shrine', 95, 'The resting place of the King of Curses.'),
('Shiganshina District', 'Battlefield', 60, 'Site of multiple Titan invasions.'),
('Hidden Village of Sorcery', 'Cursed Shrine', 80, 'A lost stronghold of ancient jujutsu masters.'),
('Titan Forest', 'Battlefield', 50, 'A dense area where Titan battles frequently take place.');

-- Insert data into Battles
INSERT INTO Battles (location_id, battle_date, outcome, summary)
VALUES 
(1, '2025-02-14', 'Victory', 'The Survey Corps managed to push back the Titans.'),
(2, '2025-03-01', 'Defeat', 'Sukuna�s cursed energy overwhelmed the forces.'),
(3, '2025-03-10', 'Stalemate', 'Both sides suffered heavy losses.'),
(4, '2025-04-05', 'Victory', 'A secret jujutsu technique banished multiple Titans.'),
(5, '2025-04-20', 'Defeat', 'A new unknown curse emerged, forcing retreat.');

-- Insert data into Battle_Participants
INSERT INTO Battle_Participants (battle_id, character_id)
VALUES 
(1, 1), (1, 3), (2, 2), (2, 4), (3, 5),
(3, 1), (4, 2), (4, 3), (5, 4), (5, 5);

-- Insert data into Techniques
INSERT INTO Techniques (name, type, power_level, description)
VALUES 
('Hardening', 'Titan Ability', 85, 'Allows a Titan to reinforce its body with hardened skin.'),
('Infinite Void', 'Jujutsu Technique', 95, 'Traps enemies in an infinite state of perception.'),
('War Hammer Strike', 'Titan Ability', 90, 'Forms weapons from Titan flesh.'),
('Black Flash', 'Jujutsu Technique', 88, 'Enhances physical attacks with cursed energy.'),
('Beast Roar', 'Titan Ability', 80, 'A devastating roar that paralyzes enemies.'),
('weakness', 'Jujutsu Technique', 1, 'afsos hua sun ke');

-- Insert data into Character_Techniques
INSERT INTO Character_Techniques (character_id, technique_id, mastery_level)
VALUES 
(1, 1, 90), (2, 2, 100), (3, 5, 85), (4, 3, 92), (5, 4, 88);

-- Insert data into Battle_Techniques
INSERT INTO Battle_Techniques (battle_id, technique_id)
VALUES 
(1, 1), (2, 2), (3, 3), (4, 4), (5, 5);

-- Insert data into Artifacts
INSERT INTO Artifacts (name, effect, rarity, discovered_at)
VALUES 
('Cursed Dagger', 'Can pierce through Titan flesh with ease.', 'Rare', '2025-01-10'),
('War Hammer Core', 'Boosts War Hammer Titan abilities.', 'Legendary', '2025-02-22'),
('Seal of Binding', 'Restricts a Titan�s transformation.', 'Legendary', '2025-03-05'),
('Infinity Orb', 'Enhances jujutsu techniques.', 'Rare', '2025-03-15'),
('Beast Pendant', 'Strengthens Beast Titan�s control.', 'Common', '2025-04-01');

-- Insert data into Character_Artifacts
INSERT INTO Character_Artifacts (character_id, artifact_id)
VALUES 
(1, 1), (2, 4), (3, 5), (4, 2), (5, 3);

-- Insert data into Prophecies
INSERT INTO Prophecies (title, content, predicted_outcome)
VALUES 
('The Fall of the Walls', 'A great Titan infused with cursed energy will bring destruction.', 'A cataclysmic war.'),
('The Sorcerer�s Sacrifice', 'A powerful sorcerer must be sacrificed to break the curse.', 'A new era of balance.'),
('The Forbidden Transformation', 'A Titan-shifter who masters jujutsu will become unstoppable.', 'A godlike warrior.'),
('The Lost Ritual', 'A secret technique exists to permanently sever the Titan curse.', 'The end of the Titan age.'),
('The Eternal War', 'As long as hatred exists, the Titans and curses will never vanish.', 'A never-ending cycle.');

-- Insert data into Missions
INSERT INTO Missions (objective, status, success_criteria, discovered_clues, mission_date)
VALUES 
('Recover the War Hammer Core.', 'Completed', 'Retrieve the artifact.', 'It was hidden in a cursed shrine.', '2025-02-22'),
('Investigate the Titan-Curse Fusion.', 'Ongoing', 'Determine the origin of the hybrid forms.', 'A sorcerer-Titan connection found.', '2025-03-10'),
('Defend Wall Maria from invasion.', 'Completed', 'Prevent breach.', 'Titans with cursed energy are stronger.', '2025-02-14'),
('Find the Lost Ritual.', 'Pending', 'Locate ancient texts.', 'The ritual might be hidden in a sorcerer�s vault.', '2025-04-01'),
('Assassinate a rogue Titan-shifter.', 'Ongoing', 'Eliminate the target.', 'He has mastered both Titan and jujutsu abilities.', '2025-03-20');

-- Insert data into Mission_Assignments
INSERT INTO Mission_Assignments (mission_id, character_id)
VALUES 
(1, 4), (1, 5), (2, 2), (2, 1), (3, 3),
(3, 1), (4, 5), (4, 2), (5, 3), (5, 4);

