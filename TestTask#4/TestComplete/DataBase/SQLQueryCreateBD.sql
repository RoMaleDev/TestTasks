USE master;
GO
CREATE DATABASE MSdBase
ON 
( NAME = MSdBase_dat,
    FILENAME = 'C:\DataBase\MSdBase.mdf',
    SIZE = 8,
    MAXSIZE = 50,
    FILEGROWTH = 5 )
LOG ON
( NAME = MSdBase_log,
    FILENAME = 'C:\DataBase\MSdBase.ldf',
    SIZE = 5MB,
    MAXSIZE = 25MB,
    FILEGROWTH = 5MB ) ;
GO

USE MSdBase;
GO

CREATE TABLE Brokers
(
    ID INTEGER NOT NULL PRIMARY KEY IDENTITY,
    Name NVARCHAR(24) NOT NULL,
    DestinationFolderName NVARCHAR(256)
);

GO

CREATE TABLE SourceFolders
(
    ID INTEGER NOT NULL PRIMARY KEY IDENTITY,
    Name NVARCHAR(256) NOT NULL,     
    BrokersCode INTEGER CONSTRAINT FKBrokersID REFERENCES Brokers,
);

GO
