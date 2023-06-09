USE [CompanyElmasri]
GO
/****** Object:  Table [dbo].[Employee]    Script Date: 01/07/2011 15:24:17 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
SET ANSI_PADDING ON
GO
CREATE TABLE [dbo].[Employee](
	[Fname] [varchar](50) NULL,
	[Minit] [varchar](50) NULL,
	[Lname] [nchar](10) NULL,
	[Ssn] [int] NOT NULL,
	[Bdate] [datetime] NULL,
	[Address] [varchar](50) NULL,
	[Sex] [varchar](50) NULL,
	[Salary] [int] NULL,
	[Super_ssn] [int] NULL,
	[Dno] [int] NULL,
 CONSTRAINT [PK_Employee] PRIMARY KEY CLUSTERED 
(
	[Ssn] ASC
)WITH (PAD_INDEX  = OFF, STATISTICS_NORECOMPUTE  = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS  = ON, ALLOW_PAGE_LOCKS  = ON) ON [PRIMARY]
) ON [PRIMARY]
GO
SET ANSI_PADDING OFF
GO
INSERT [dbo].[Employee] ([Fname], [Minit], [Lname], [Ssn], [Bdate], [Address], [Sex], [Salary], [Super_ssn], [Dno]) VALUES (N'John', N'B', N'Smith     ', 123456789, CAST(0x00005CC500000000 AS DateTime), N'731 Fondren, Housten, Tx', N'M', 30000, 333445555, 5)
INSERT [dbo].[Employee] ([Fname], [Minit], [Lname], [Ssn], [Bdate], [Address], [Sex], [Salary], [Super_ssn], [Dno]) VALUES (N'Franklin', N'T', N'Wong      ', 333445555, CAST(0x00004FCD00000000 AS DateTime), N'639 Voss, Houston, TX', N'M', 40000, 888665555, 5)
INSERT [dbo].[Employee] ([Fname], [Minit], [Lname], [Ssn], [Bdate], [Address], [Sex], [Salary], [Super_ssn], [Dno]) VALUES (N'Joyce', N'A', N'English   ', 453453453, CAST(0x0000678D00000000 AS DateTime), N'5631 Rice, Houston, TX', N'F', 25000, 333445555, 5)
INSERT [dbo].[Employee] ([Fname], [Minit], [Lname], [Ssn], [Bdate], [Address], [Sex], [Salary], [Super_ssn], [Dno]) VALUES (N'Ramesh', N'K', N'Narayan   ', 666884444, CAST(0x0000597600000000 AS DateTime), N'975 Fire Oak, Humble, TX', N'M', 38000, 333445555, 5)
INSERT [dbo].[Employee] ([Fname], [Minit], [Lname], [Ssn], [Bdate], [Address], [Sex], [Salary], [Super_ssn], [Dno]) VALUES (N'James', N'E', N'Borg      ', 888665555, CAST(0x0000360300000000 AS DateTime), N'450 Stone, Houston, TX', N'M', 55000, NULL, 1)
INSERT [dbo].[Employee] ([Fname], [Minit], [Lname], [Ssn], [Bdate], [Address], [Sex], [Salary], [Super_ssn], [Dno]) VALUES (N'Jennifer', N'S', N'Wallace   ', 987654321, CAST(0x00003B2900000000 AS DateTime), N'291 Berry, Bellaire, TX', N'F', 43000, 888665555, 4)
INSERT [dbo].[Employee] ([Fname], [Minit], [Lname], [Ssn], [Bdate], [Address], [Sex], [Salary], [Super_ssn], [Dno]) VALUES (N'Ahmad', N'V', N'Jabbar    ', 987987987, CAST(0x000062C900000000 AS DateTime), N'980 Dallas, Houston, TX', N'M', 25000, 987654321, 4)
INSERT [dbo].[Employee] ([Fname], [Minit], [Lname], [Ssn], [Bdate], [Address], [Sex], [Salary], [Super_ssn], [Dno]) VALUES (N'Alicia', N'J', N'Zelaya    ', 999887777, CAST(0x0000611600000000 AS DateTime), N'3321 Castel,Spring, TX', N'F', 25000, 987654321, 4)
/****** Object:  Table [dbo].[Dependent]    Script Date: 01/07/2011 15:24:17 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
SET ANSI_PADDING ON
GO
CREATE TABLE [dbo].[Dependent](
	[Essn] [int] NOT NULL,
	[Dependent_name] [varchar](50) NOT NULL,
	[Sex] [varchar](50) NULL,
	[Bdate] [datetime] NULL,
	[Relationship] [nchar](10) NULL,
 CONSTRAINT [PK_Dependent] PRIMARY KEY CLUSTERED 
(
	[Essn] ASC,
	[Dependent_name] ASC
)WITH (PAD_INDEX  = OFF, STATISTICS_NORECOMPUTE  = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS  = ON, ALLOW_PAGE_LOCKS  = ON) ON [PRIMARY]
) ON [PRIMARY]
GO
SET ANSI_PADDING OFF
GO
INSERT [dbo].[Dependent] ([Essn], [Dependent_name], [Sex], [Bdate], [Relationship]) VALUES (123456789, N'Aice', N'F', CAST(0x00007EF900000000 AS DateTime), N'Daughter  ')
INSERT [dbo].[Dependent] ([Essn], [Dependent_name], [Sex], [Bdate], [Relationship]) VALUES (123456789, N'Elizabeth', N'F', CAST(0x0000601300000000 AS DateTime), N'Spouse    ')
INSERT [dbo].[Dependent] ([Essn], [Dependent_name], [Sex], [Bdate], [Relationship]) VALUES (123456789, N'Michael', N'M', CAST(0x00007D9000000000 AS DateTime), N'Son       ')
INSERT [dbo].[Dependent] ([Essn], [Dependent_name], [Sex], [Bdate], [Relationship]) VALUES (333445555, N'Alice', N'F', CAST(0x00007B1100000000 AS DateTime), N'Daughter  ')
INSERT [dbo].[Dependent] ([Essn], [Dependent_name], [Sex], [Bdate], [Relationship]) VALUES (333445555, N'Joy', N'F', CAST(0x0000533A00000000 AS DateTime), N'Spouse    ')
INSERT [dbo].[Dependent] ([Essn], [Dependent_name], [Sex], [Bdate], [Relationship]) VALUES (333445555, N'Theodore', N'M', CAST(0x0000779400000000 AS DateTime), N'Son       ')
INSERT [dbo].[Dependent] ([Essn], [Dependent_name], [Sex], [Bdate], [Relationship]) VALUES (987654321, N'Abner', N'M', CAST(0x00003C2600000000 AS DateTime), N'Spouse    ')
/****** Object:  Table [dbo].[Department]    Script Date: 01/07/2011 15:24:17 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
SET ANSI_PADDING ON
GO
CREATE TABLE [dbo].[Department](
	[Dname] [varchar](50) NULL,
	[Dnumber] [int] NOT NULL,
	[Mgr_ssn] [int] NULL,
	[Mgr_start_date] [datetime] NULL,
 CONSTRAINT [PK_Department] PRIMARY KEY CLUSTERED 
(
	[Dnumber] ASC
)WITH (PAD_INDEX  = OFF, STATISTICS_NORECOMPUTE  = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS  = ON, ALLOW_PAGE_LOCKS  = ON) ON [PRIMARY]
) ON [PRIMARY]
GO
SET ANSI_PADDING OFF
GO
INSERT [dbo].[Department] ([Dname], [Dnumber], [Mgr_ssn], [Mgr_start_date]) VALUES (N'Headquarters', 1, 888665555, CAST(0x0000743A00000000 AS DateTime))
INSERT [dbo].[Department] ([Dname], [Dnumber], [Mgr_ssn], [Mgr_start_date]) VALUES (N'Administration', 4, 987654321, CAST(0x0000878A00000000 AS DateTime))
INSERT [dbo].[Department] ([Dname], [Dnumber], [Mgr_ssn], [Mgr_start_date]) VALUES (N'Research', 5, 333445555, CAST(0x00007E1B00000000 AS DateTime))
/****** Object:  Table [dbo].[Dept_Locations]    Script Date: 01/07/2011 15:24:17 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
SET ANSI_PADDING ON
GO
CREATE TABLE [dbo].[Dept_Locations](
	[Dnumber] [int] NOT NULL,
	[Dlocation] [varchar](50) NOT NULL,
 CONSTRAINT [PK_Dept_Locations] PRIMARY KEY CLUSTERED 
(
	[Dnumber] ASC,
	[Dlocation] ASC
)WITH (PAD_INDEX  = OFF, STATISTICS_NORECOMPUTE  = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS  = ON, ALLOW_PAGE_LOCKS  = ON) ON [PRIMARY]
) ON [PRIMARY]
GO
SET ANSI_PADDING OFF
GO
INSERT [dbo].[Dept_Locations] ([Dnumber], [Dlocation]) VALUES (1, N'Houston')
INSERT [dbo].[Dept_Locations] ([Dnumber], [Dlocation]) VALUES (4, N'Stafford')
INSERT [dbo].[Dept_Locations] ([Dnumber], [Dlocation]) VALUES (5, N'Bellaire')
INSERT [dbo].[Dept_Locations] ([Dnumber], [Dlocation]) VALUES (5, N'Houston')
INSERT [dbo].[Dept_Locations] ([Dnumber], [Dlocation]) VALUES (5, N'Sugarland')
/****** Object:  Table [dbo].[Project]    Script Date: 01/07/2011 15:24:17 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
SET ANSI_PADDING ON
GO
CREATE TABLE [dbo].[Project](
	[Pname] [varchar](50) NULL,
	[Pnumber] [int] NOT NULL,
	[Plocation] [varchar](50) NULL,
	[Dnum] [int] NULL,
 CONSTRAINT [PK_Project] PRIMARY KEY CLUSTERED 
(
	[Pnumber] ASC
)WITH (PAD_INDEX  = OFF, STATISTICS_NORECOMPUTE  = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS  = ON, ALLOW_PAGE_LOCKS  = ON) ON [PRIMARY]
) ON [PRIMARY]
GO
SET ANSI_PADDING OFF
GO
INSERT [dbo].[Project] ([Pname], [Pnumber], [Plocation], [Dnum]) VALUES (N'ProductX', 1, N'Bellaire', 5)
INSERT [dbo].[Project] ([Pname], [Pnumber], [Plocation], [Dnum]) VALUES (N'ProductY', 2, N'Sugarland', 5)
INSERT [dbo].[Project] ([Pname], [Pnumber], [Plocation], [Dnum]) VALUES (N'ProductZ', 3, N'Houston', 5)
INSERT [dbo].[Project] ([Pname], [Pnumber], [Plocation], [Dnum]) VALUES (N'Computerization', 10, N'Stafford', 4)
INSERT [dbo].[Project] ([Pname], [Pnumber], [Plocation], [Dnum]) VALUES (N'Reorganization', 20, N'Houston', 1)
INSERT [dbo].[Project] ([Pname], [Pnumber], [Plocation], [Dnum]) VALUES (N'Newbenefits', 30, N'Stafford', 4)
/****** Object:  Table [dbo].[Works_On]    Script Date: 01/07/2011 15:24:17 ******/
SET ANSI_NULLS ON
GO
SET QUOTED_IDENTIFIER ON
GO
CREATE TABLE [dbo].[Works_On](
	[Essn] [int] NOT NULL,
	[Pno] [int] NOT NULL,
	[Hours] [float] NULL,
 CONSTRAINT [PK_Works_On] PRIMARY KEY CLUSTERED 
(
	[Essn] ASC,
	[Pno] ASC
)WITH (PAD_INDEX  = OFF, STATISTICS_NORECOMPUTE  = OFF, IGNORE_DUP_KEY = OFF, ALLOW_ROW_LOCKS  = ON, ALLOW_PAGE_LOCKS  = ON) ON [PRIMARY]
) ON [PRIMARY]
GO
INSERT [dbo].[Works_On] ([Essn], [Pno], [Hours]) VALUES (123456789, 1, 32.5)
INSERT [dbo].[Works_On] ([Essn], [Pno], [Hours]) VALUES (123456789, 2, 7.5)
INSERT [dbo].[Works_On] ([Essn], [Pno], [Hours]) VALUES (333445555, 2, 10)
INSERT [dbo].[Works_On] ([Essn], [Pno], [Hours]) VALUES (333445555, 3, 10)
INSERT [dbo].[Works_On] ([Essn], [Pno], [Hours]) VALUES (333445555, 10, 10)
INSERT [dbo].[Works_On] ([Essn], [Pno], [Hours]) VALUES (333445555, 20, 10)
INSERT [dbo].[Works_On] ([Essn], [Pno], [Hours]) VALUES (453453453, 1, 20)
INSERT [dbo].[Works_On] ([Essn], [Pno], [Hours]) VALUES (453453453, 2, 20)
INSERT [dbo].[Works_On] ([Essn], [Pno], [Hours]) VALUES (666884444, 3, 40)
INSERT [dbo].[Works_On] ([Essn], [Pno], [Hours]) VALUES (888665555, 20, NULL)
INSERT [dbo].[Works_On] ([Essn], [Pno], [Hours]) VALUES (987654321, 20, 15)
INSERT [dbo].[Works_On] ([Essn], [Pno], [Hours]) VALUES (987654321, 30, 20)
INSERT [dbo].[Works_On] ([Essn], [Pno], [Hours]) VALUES (987987987, 10, 35)
INSERT [dbo].[Works_On] ([Essn], [Pno], [Hours]) VALUES (987987987, 30, 5)
INSERT [dbo].[Works_On] ([Essn], [Pno], [Hours]) VALUES (999887777, 10, 10)
INSERT [dbo].[Works_On] ([Essn], [Pno], [Hours]) VALUES (999887777, 30, 30)
/****** Object:  ForeignKey [FK_Department_Employee]    Script Date: 01/07/2011 15:24:17 ******/
ALTER TABLE [dbo].[Department]  WITH CHECK ADD  CONSTRAINT [FK_Department_Employee] FOREIGN KEY([Mgr_ssn])
REFERENCES [dbo].[Employee] ([Ssn])
GO
ALTER TABLE [dbo].[Department] CHECK CONSTRAINT [FK_Department_Employee]
GO
/****** Object:  ForeignKey [FK_Dependent_Employee]    Script Date: 01/07/2011 15:24:17 ******/
ALTER TABLE [dbo].[Dependent]  WITH CHECK ADD  CONSTRAINT [FK_Dependent_Employee] FOREIGN KEY([Essn])
REFERENCES [dbo].[Employee] ([Ssn])
GO
ALTER TABLE [dbo].[Dependent] CHECK CONSTRAINT [FK_Dependent_Employee]
GO
/****** Object:  ForeignKey [FK_Dept_Locations_Department]    Script Date: 01/07/2011 15:24:17 ******/
ALTER TABLE [dbo].[Dept_Locations]  WITH CHECK ADD  CONSTRAINT [FK_Dept_Locations_Department] FOREIGN KEY([Dnumber])
REFERENCES [dbo].[Department] ([Dnumber])
GO
ALTER TABLE [dbo].[Dept_Locations] CHECK CONSTRAINT [FK_Dept_Locations_Department]
GO
/****** Object:  ForeignKey [FK_Project_Department]    Script Date: 01/07/2011 15:24:17 ******/
ALTER TABLE [dbo].[Project]  WITH CHECK ADD  CONSTRAINT [FK_Project_Department] FOREIGN KEY([Dnum])
REFERENCES [dbo].[Department] ([Dnumber])
GO
ALTER TABLE [dbo].[Project] CHECK CONSTRAINT [FK_Project_Department]
GO
/****** Object:  ForeignKey [FK_Works_On_Employee]    Script Date: 01/07/2011 15:24:17 ******/
ALTER TABLE [dbo].[Works_On]  WITH CHECK ADD  CONSTRAINT [FK_Works_On_Employee] FOREIGN KEY([Essn])
REFERENCES [dbo].[Employee] ([Ssn])
GO
ALTER TABLE [dbo].[Works_On] CHECK CONSTRAINT [FK_Works_On_Employee]
GO
/****** Object:  ForeignKey [FK_Works_On_Project]    Script Date: 01/07/2011 15:24:17 ******/
ALTER TABLE [dbo].[Works_On]  WITH CHECK ADD  CONSTRAINT [FK_Works_On_Project] FOREIGN KEY([Pno])
REFERENCES [dbo].[Project] ([Pnumber])
GO
ALTER TABLE [dbo].[Works_On] CHECK CONSTRAINT [FK_Works_On_Project]
GO
