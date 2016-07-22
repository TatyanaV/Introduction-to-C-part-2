/**************************************************************
Tatyana Vlaskin
Assignment #1
name: 1.cpp
Description:
Game of life problem. Description was provided in the undestanding
section of the report. Brief rules are summorized in the program
**************************************************************/
#include<iostream>
#include<string>
using std::string;
using std::cout;
using std::cin;
using std::endl;
int const COLUMNS = 80 +2;
int const ROWS = 22 + 2;

/************************************************
** Function: Introduction()
** Description: Function describes the game.
*************************************************/
void Introduction();

/************************************************
** Function: GameOfLife::MakeYourSelection()
** Description: Asks the user to choose how
they want to make their initial configuration
of the world. The user has an option
to choose alive cells or they can let the
computer randomly position 200 alive cells
*************************************************/
void MakeYourSelection();

/************************************************
** Function: initializeToMinusSign
** Description: Initializes elements in the array world to '-'.
Basically makes all worlds dead.
*************************************************/
void initializeToMinusSign(char array[][COLUMNS]);

/************************************************
** Function:void continueManual(int row, int column)
** Description: Lets the user choose which cells they want to make
alive
*************************************************/
void continueManual(int row, int column);

/************************************************
** Function: void continueAutomate(char generation[][COLUMNS]
** Description:  Allows computer to randomly position 200
alive cells on in the "world"
*************************************************/
void continueAutomate(char generation[][COLUMNS]);

/************************************************
** Function:void Display(const char generation[][COLUMNUMNS],int generationNum))
** Description: Displays world on the screen
*************************************************/
void Display(const char generation[][COLUMNS],int generationCount);

/************************************************
** Function:void countueToNextGeneration(int generation, bool cont)
** Description: Asks the user if they want to move on to the next generation
Please enter Y, y, n and N
*************************************************/
void countueToNextGeneration(int generation);

/************************************************
** Function:void NextGeneration(char generation[][COLUMNUMNS])
** Description: Determins which cells will stay alive and which
cells will be born in the next generation. This function calls
2 other functions: CountNeighbors and SurvivorsAndNewborns
and loops through each element in the array.
Rows 0 and 23 as well as columns 1 and 81 are skipted, thus
they will be always dead as assigned at the beginninig of the program.
Results are stored in temporatry array to avoid changes in the original array before all counting is complete
Once we are done looping through the array, old generation array is replaced with the new generation array by
calling function:  ReplaceOldGenerationWithNew(nextGeneration,generation); Temp array is out new world array
*************************************************/
void NextGeneration(char generation[][COLUMNS]);

/************************************************
** Function:void ReplaceOldGenerationerationWithNew(char newGenerationeration[][COLUMNUMNS],char oldGenerationeration[][COLUMNUMNS])
** Description: replaces previous generationeration with the new generation
*************************************************/
void ReplaceOldGenerationWithNew(char newGeneration[][COLUMNS],char oldGeneration[][COLUMNS]);

/************************************************
** Function:CountNeighbors(char generation[][COLUMNUMNS],int index_X,int index_Y)
** Description: Count Neighbors around each world. Rows go from 0 to 23.
Columns go from 0-81. We do check row 0 and 23, and columnumn 0 and 81.
Howerver, cells in those 2 rows and 2 columns will be dead all the time
as defined at the begining of the game
//used information from: http://ptgmedia.pearsoncmg.com/images/0672320665/downloads/The%20Game%20of%20Life.html
*************************************************/

int CountNeighbors(char generation[][COLUMNS],int index_X,int intdex_Y);

/************************************************
** Function:voidSurvivorsAndNewborns(char generation[][COLUMNUMNS], char nextGenerationeration[][COLUMNUMNS],int neighbors,int index_X,int index_Y)
** Description: Undates the worlds for the next generationeration using the following rules:
    1. A living cell dies of overcrowding if it has >3 of living neighbors.
    2. A living cell dies of loneliness if it has <2 of living neighbors."
    3. An empty cell becomes alive if it has exactly 3 living neighbors."
    4. All other cell remain unchanged.
// used information from: http://arstechnica.com/civis/viewtopic.php?f=20&t=541788
*************************************************/
void SurvivorsAndNewborns(char generation[][COLUMNS],char nextGeneration[][COLUMNS],int neighbors,int index_X,int index_Y);
/************************************************
** Function: void goToMenuFunction()
** Description:Ask if the user wants to go to the main menu
*************************************************/
void goToMenuFunction();
/************************************************
** Function: int integerCheck (string INPUT
** Description:Function checks that valid integer was
entered
*************************************************/
int integerCheck (string INPUT);
char world[ROWS][COLUMNS];
/************************************************
** Function: void newLine()
** Description:Function taken from the book. Reads
all charactes untill it see new life
*************************************************/
void newLine();

int main(){
    bool cont=true;
    Introduction();
    MakeYourSelection();
    return 0;
}

/************************************************
** Function: Introduction()
** Description: Function describes the game.
*************************************************/
void Introduction(){
    cout<<"*******************************************************************************\n"<<endl;
    cout <<"Welcome to the GAME OF LIFE!" << endl;
    cout <<"You have an option to chose an initial configuration of the world."<<endl;
    cout<< "Or you can let the computer to generation randome configuration of 200 alive cells."<<endl;
    cout<< "Worlds change for each generation using the following rules:" <<endl;
    cout<< "1. A living cell dies of overcrowding if it has >3 of living neighbors."<<endl;
    cout<< "2. A living cell dies of loneliness if it has <2 of living neighbors."<<endl;
    cout<< "3. An empty cell becomes alive if it has exactly 3 living neighbors." <<endl;
    cout<< "4. All other cells remain unchanged." <<endl;
    cout<< "5. The new generationeration becomes the current generationeration and the world is displayed." <<endl;

}

/************************************************
** Function: GameOfLife::MakeYourSelection()
** Description: Asks the user to choose how
they want to make their initial configuration
of the world. The user has an option
to choose alive cells or they can let the
computer randomly position 200 alive cells
*************************************************/
void MakeYourSelection(){
    string entered;
    int input;
    int row, column;
    cout<< endl<< "Chose how you want to generate the world. Choose 1, 2 or 3." <<endl<<endl;
    cout << "1. Choose which cells you want to make alive. \n" << endl;
    cout << "2. Let the computer randomly choose where to place live cells.\n" << endl;
    cout << "3. Exit the game. \n" << endl;
    cout << "Make your selection: ";
    getline(cin,entered);
    input = integerCheck(entered);
    int generation =0;
    switch(input)
    {
    case 1:
        initializeToMinusSign(world);
        continueManual(row, column);
        Display(world,generation);
        countueToNextGeneration(generation);
        goToMenuFunction();
        break;
    case 2:
        initializeToMinusSign(world);
        continueAutomate(world);
        Display(world,generation);
        countueToNextGeneration(generation);
        goToMenuFunction();
        break;
    case 3:
        cout << "Have a nice day.\n";
        break;
    default:
        cout << "Error, please pick 1, 2, or 3." << endl;
        MakeYourSelection();
        break;
        }
}

/************************************************
** Function: initializeToMinusSign
** Description: Initializes elements in the array world to '-'.
Basically makes all worlds dead.
*************************************************/
void initializeToMinusSign(char array[][COLUMNS]){
    for(int i=0;i<ROWS;i++){
        for(int j=0;j<COLUMNS;j++){
            array[i][j]='-';
        }
    }
}

/************************************************
** Function:void continueManual(int row, int column)
** Description: Lets the user choose which cells they want to make
alive
*************************************************/
void continueManual(int row, int column){
    char nextMove;
    bool cont=true;
    string entered;
    cout << "Which cells do you want to male alive?" << endl;
    while(cont==true){
        do{
            cout<<"ROW index of an alive world(1-22): ";
            getline(cin,entered);
            row = integerCheck(entered);
        }while(row<1||row>22);

        do{
            cout<<"COLUMN index of an alive world(1-80): ";
            getline(cin,entered);
            column = integerCheck(entered);
        }while(column<1||column>80);

        world[row][column]=2;
        cout<<"["<<row<<"]["<<column<<"] was born.\n";
        cout<<"\nDo you want to indicate another alive cell?(y/n): ";
        do{
            cin>>nextMove;
        }while(nextMove!='y'&&nextMove!='Y'&&nextMove!='n'&&nextMove!='N');
        if(nextMove=='n'||nextMove=='N')
            cont=false;
    }

}

/************************************************
** Function: void continueAutomate(char generation[][COLUMNS]
** Description:  Allows computer to randomly position 200
alive cells on in the "world"
*************************************************/
void continueAutomate(char generation[][COLUMNS]){
    int coutAlive;
     srand(time(0));
    for (int countAlive =0; countAlive < 200; countAlive++){
                    generation[rand()%22+1][rand()%80+1] = 2;
    }
}

/************************************************
** Function:void Display(const char generation[][COLUMNS],int generationNum))
** Description: Displays world on the screen
*************************************************/
void Display(const char generation[][COLUMNS],int generationCount){
    cout<<"\n\n\n Generationeration "<<generationCount<<":\n\n";
    for(int i=1;i<ROWS-1;i++){
        for(int j=1;j<COLUMNS-1;j++){
        cout<<generation[i][j];
        }
    }
}

/************************************************
** Function:void countueToNextGeneration(int generation, bool cont)
** Description: Asks the user if they want to move on to the next generation
Please enter Y, y, n and N
*************************************************/

void countueToNextGeneration(int generation){
    char answer;
    bool cont = true;
    while(cont==true){
        cout<<"\n\nDo you want to go to the next generationeration?(y/n): ";
        do{
               cin>>answer;
        }while(answer!='y'&&answer!='Y'&&answer!='n'&&answer!='N');
        if(answer=='n'||answer=='N')
        {
            cont=false;
            break;
        }
        NextGeneration(world);
        generation++;
        Display(world,generation);
    }
}

/************************************************
** Function:void NextGeneration(char generation[][COLUMNUMNS])
** Description: Determins which cells will stay alive and which
cells will be born in the next generation. This function calls
2 other functions: CountNeighbors and SurvivorsAndNewborns
and loops through each element in the array.
Rows 0 and 23 as well as columns 1 and 81 are skipted, thus
they will be always dead as assigned at the beginninig of the program.
Results are stored in temporatry array to avoid changes in the original array before all counting is complete
Once we are done looping through the array, old generation array is replaced with the new generation array by
calling function:  ReplaceOldGenerationWithNew(nextGeneration,generation); Temp array is out new world array
*************************************************/
void NextGeneration(char generation[][COLUMNS]){
    int neighbors=0;
    int i,j;
    char nextGeneration[ROWS][COLUMNS];
    for(i=1;i<ROWS-1;i++){//WE WILL IGNORE ROW 0 AND 23 AS WELL AS COLUMNUMN 0 AND 81
        for(j=1;j<COLUMNS-1;j++){
            neighbors=CountNeighbors(generation,i,j);
            SurvivorsAndNewborns(generation,nextGeneration,neighbors,i,j);
        }
    }
    ReplaceOldGenerationWithNew(nextGeneration,generation);
}
/************************************************
** Function:void ReplaceOldGenerationWithNew(char newGeneration[][COLUMNS],char oldGeneration[][COLUMNS])
** Description: replaces previous generationeration with the new generation
*************************************************/
void ReplaceOldGenerationWithNew(char newGeneration[][COLUMNS],char oldGeneration[][COLUMNS]){
    for(int i=0;i<ROWS;i++){
        for(int j=0;j<COLUMNS;j++){
            oldGeneration[i][j]=newGeneration[i][j];
        }
    }
}
/************************************************
** Function:CountNeighbors(char generation[][COLUMNS],int index_X,int index_Y)
** Description: Count Neighbors around each world. Rows go from 0 to 23.
Columns go from 0-81. We do check row 0 and 23, and columnumn 0 and 81.
Howerver, cells in those 2 rows and 2 columns will be dead all the time
as defined at the begining of the game
//used information from: http://ptgmedia.pearsoncmg.com/images/0672320665/downloads/The%20Game%20of%20Life.html
*************************************************/
int CountNeighbors(char generation[][COLUMNS],int index_X,int index_Y){
    int neighbors=0;
    //checking above row
    if(((index_X-1)>=0)&&((index_Y-1)>=0)&&(generation[index_X-1][index_Y-1]==2)){ neighbors++;}
    if(((index_X-1)>=0)&&(generation[index_X-1][index_Y]==2)){neighbors++;}
    if(((index_X-1)>=0)&&((index_Y+1)<COLUMNS)&&(generation[index_X-1][index_Y+1]==2)){neighbors++;}
    //checking same row
    if(((index_Y-1)>=0)&&(generation[index_X][index_Y-1]==2)){neighbors++;}
    if(((index_Y+1)<COLUMNS)&&(generation[index_X][index_Y+1]==2)){neighbors++;}
    //checking below row
    if(((index_X+1)<COLUMNS)&&((index_Y-1)>=0)&&(generation[index_X+1][index_Y-1]==2)){neighbors++;}
    if(((index_X+1)<COLUMNS)&&(generation[index_X+1][index_Y]==2)){neighbors++;}
    if(((index_X+1)<COLUMNS)&&((index_Y+1)<COLUMNS)&&(generation[index_X+1][index_Y+1]==2)){neighbors++;}
    return neighbors;
}

/************************************************
** Function:voidSurvivorsAndNewborns(char generation[][COLUMNUMNS], char nextGeneration[][COLUMNS],int neighbors,int index_X,int index_Y)
** Description: Undates the worlds for the next generation using the following rules:
    1. A living cell dies of overcrowding if it has >3 of living neighbors.
    2. A living cell dies of loneliness if it has <2 of living neighbors."
    3. An empty cell becomes alive if it has exactly 3 living neighbors."
    4. All other cell remain unchanged.
// used information from: http://arstechnica.com/civis/viewtopic.php?f=20&t=541788
*************************************************/
void SurvivorsAndNewborns(char generation[][COLUMNS], char nextGeneration[][COLUMNS],int neighbors,int index_X,int index_Y){
    if(neighbors>3 && generation[index_X][index_Y]==2){//overcrowding death
        nextGeneration[index_X][index_Y]='-';
    }
    else if(neighbors<=1 &&generation[index_X][index_Y]==2){//dies from lonliness
        nextGeneration[index_X][index_Y]='-';
      }
    else if(neighbors==3 &&generation[index_X][index_Y]=='-'){//birth if 3 neighbors
        nextGeneration[index_X][index_Y]=2;
    }
    else
        nextGeneration[index_X][index_Y]=generation[index_X][index_Y];//other worlds remain unchanged.
}


/************************************************
** Function: void goToMenuFunction()
** Description:Ask if the user wants to go to the main menu
*************************************************/
void goToMenuFunction(){
    char goToMenu;
    cout << endl << "Would you like to go back to the MENU? (y/n): ";
    cin >> goToMenu;
    switch(goToMenu)
    {
        case 'y':
        case 'Y':
            newLine();
            MakeYourSelection();
            break;
        case 'n':
        case 'N':
            cout <<"\nThank you for using our program.\n";
            cout << "Have a nice day.\n";
            break;
        default:
            cout << "Error, please type Y for yes and N for no" << endl;
            cout << endl << "Would you like to go back to the MENU? (y/n): ";
            cin >> goToMenu;
            break;
        }
}

/************************************************
** Function: int integerCheck (string INPUT
** Description:Function checks that valid integer was
entered
*************************************************/
// I GOT THIS FUNCTION FROM Terry Lauer last quarter IN CS161
//MY ERROR CHECK FUNCTION HAD ONE PROBELM
//WHEN I TRIED TO ENTER 1 ;jkkhjggf (number, splace and some randome characters)
//IT WAS ACCEPTING IT AS A VALID ENTRY
int integerCheck (string INPUT){
	int isanint = 'n'; // is it an integer loop condition
	int x; // used in the loop
	int isok ; // used to test for integer
	int NUM; // the integer to be returned
// test to yes if it is an int
				isanint = 'n';
				while (isanint == 'n')
					{
						isok = 1;
						for (x=0; x < INPUT.length(); x=x+1)
							{
// check for digits
								if (((INPUT.at(x) >= '0' && INPUT.at(x) <= '9')))
									{
										isok = 1;
									}
								else
								 	{
// flag as bad and set exit
								 		isok = 0;
								 		x = INPUT.length();
								 	}
							}

/// if it did not pass the test for integer
				if ( isok == 0)
					{	cout << endl<<"That was NOT an integer or integer was <1." << endl;
						cout << "Please enter an integer " ;
						getline(cin,INPUT);
						cout << endl;
					}
				else
					{
						NUM = atoi(INPUT.c_str());
						isanint = 'y';
						isok = 1;
					}
			}
 	return NUM;
}
/************************************************
** Function: void newLine()
** Description:Function taken from the book. Reads
all charactes untill it see new life
*************************************************/
void newLine()
{
   char symbol;
   do
   {
      cin.get(symbol);
   } while (symbol != '\n');
}
