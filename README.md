# Debate Tab Maker

This repository contains the source code of the local teb-maker, which is planned to be used during the workshops of the SPbPU debate club.

The teb-maker is able to assign players and referees to rooms randomly and also randomly form teams.

For the program to work, you must have at least 4 players.  
If there are more players, rooms will be formed with the following priority:  
* British format (4 teams, 2 VS 2 VS 2 VS 2)
* British ironman format (4 teams, 2 VS 2 VS 2 VS 1)
* School format (2 teams, 3 VS 3)
* American format (2 teams, 2 VS 2)
* Mixed format (2 teams, 3 VS 2)

In case of forming british room with ironman, ironman will play on Closing Proposition.  
In case of forming mixed format room, a team of three will play on Proposition.  

The initial data must come in the form of a file with the XLSX extension, in which the first worksheet contains a table of the form:

| Time mark | Who are you? | Do you have teammate? | Referee name | Name of first player | Name of second player | Name of player |
|-----------|--------------|-----------------------|--------------|----------------------|-----------------------|----------------|
| Some mark | Судья        |                       | Best referee |                      |                       |                |
| Some mark | Игрок        | Да                    |              | Sweet lover one      | Sweet lover two       |                |
| Some mark | Игрок        | Нет                   |              |                      |                       | Forever alone  |

Cells with Russian letter must be same as in example, otherwise, there is no difference.  
It is also important to mention that this table must start in cell A1.

As can be understood from the required type of initial data, the program is able to take into account the wishes of two players so that they are necessarily assigned to one team.  
Moreover, if there is a pair of players who want to play in the same team, then they can only be in a team that consists of two people. They will not be included in a three-man team with some kind of extra player.  
By the number of double teams, we mean the number of teams consisting of two people, which is in total in the rooms obtained after the optimal distribution. (See above)  
**If the number of double teams formed according to the wishes of the players is greater than the number of double teams in the optimal distribution, then the distribution will fail!**

The path to the source file is passed to the program as the first argument on the command line.   
As further arguments, you can pass an unlimited number of classroom numbers in which the games will be played.  
Also, classrooms can be omitted, in which case they will be marked as indefinite.  
**However, if the audiences are passed and there are fewer than the number of rooms after the optimal distribution, then the distribution will fail!**

As part of the current functionality, the program outputs information about the generated rooms to the output.xlsx file. For each room, a cell will be generated, shown below. They will be presented two in a row.

| Аудитория   | Classroom number |             | 
|-------------|------------------|-------------|
| Судья       | Referee name     |             |   
| <br/>       |                  |             |      
| 1ПР         |                  | 1ОП         |     
| First name  |                  | First name  |     
| Second name |                  | Second Name |
| <br/>       |                  |             |
| 2ПР         |                  | 2ОП         |
| First name  |                  | First name  |
| Second name |                  | Second name |

Obviously, for rooms from two teams, one proposition team and one opposition team will be printed.

**This project uses the OpenXLSX library, for a successful build you need to include it in your project!**