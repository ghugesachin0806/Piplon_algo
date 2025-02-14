#include "libraries.h"
using namespace std;

// golbal variables
int batsmen;
int bowlers;
int overs;
int overs_per_batsman;
int overs_per_bowler;
int fielders_from_batting_side;
int fielders_from_bowlers_side;
int battingside_rotation_per_overs;
int bowlingside_rotation_per_overs;

// functions

void Test()
{
    cout << "batsmen: " << batsmen << endl;
    cout << "bowlers: " << bowlers << endl;
    cout << "overs: " << overs << endl;
    cout << "overs_per_batsman: " << overs_per_batsman << endl;
    cout << "overs_per_bowler: " << overs_per_bowler << endl;
    cout << "fielders_from_batting_side: " << fielders_from_batting_side << endl;
    cout << "fielders_from_bowlers_side: " << fielders_from_bowlers_side << endl;
    cout << "battingside_rotation_per_overs: " << battingside_rotation_per_overs << endl;
    cout << "bowlingside_rotation_per_overs: " << bowlingside_rotation_per_overs << endl;
}
void init()
{
    batsmen = 0;
    bowlers = 0;
    overs = 0;
    overs_per_batsman = 0;
    overs_per_bowler = 0;
    fielders_from_batting_side = 0;
    fielders_from_bowlers_side = 0;
    battingside_rotation_per_overs = 0;
    bowlingside_rotation_per_overs = 0;
}

int selectBatsmen()
{
    cout << "select batsmen : ";
    cin >> batsmen;

    if (batsmen < MIN_BATSMEN || batsmen > MAX_BATSMEN)
        return 1;
    else
        return 0;
}

int selectBowlers()
{
    vector<int> bowlersVect;

    cout << "No. of bowlers choices available: ";
    for (int i = 1; i <= MAX_BOWLERS; i++)
    {
        if (lcm(i, batsmen) <= MAX_OVERS_ALLOWED)
        {
            bowlersVect.push_back(i);
            cout << i << " ";
        }
    }
    cout << endl;

    cout << "Select the no. of bowlers from above available choices :";
    cin >> bowlers;

    for (int i = 0; i < bowlersVect.size(); i++)
    {
        if (bowlersVect[i] == bowlers)
            return 0;
    }

    return 1;
}

int oversSelect()
{
    vector<int> possible_overs;
    cout << "Over choices Available : ";

    int temp = lcm(batsmen, bowlers);

    int i = 1;

    int tempCnt = temp;
    while (tempCnt <= MAX_OVERS_ALLOWED)
    {
        i++;
        cout << tempCnt << " ";
        possible_overs.push_back(tempCnt);
        tempCnt = temp * i;
    }
    cout << endl;

    cout << "Enter total overs you want from above choice : ";
    cin >> overs;

    for (int i = 0; i < possible_overs.size(); i++)
    {
        if (overs == possible_overs[i])
        {
            overs_per_batsman = overs / batsmen;
            overs_per_bowler = overs / bowlers;
            cout << "Overs selected: " << overs << endl;
            cout << "overs per batsman: " << overs / batsmen << endl;
            cout << "Overs per bowler: " << overs / bowlers << endl;
            return 0;
        }
    }

    return 1;
}

int selectCombinationFielders()
{
    cout << "select batsmen for fielding from range : " << 0 << " - " << batsmen - 1 << " : ";
    cin >> fielders_from_batting_side;
    cout << "select bowlers for fielding from tange : " << 0 << " - " << bowlers - 1 << " : ";
    cin >> fielders_from_bowlers_side;

    if ((fielders_from_batting_side < 0 || fielders_from_batting_side >= batsmen) || (fielders_from_bowlers_side < 0 || fielders_from_bowlers_side >= bowlers))
        return 1;

    return 0;
}

int selectRotation()
{
    cout << "Batsmen Rotation available : " << overs_per_batsman << endl;
    battingside_rotation_per_overs = overs_per_batsman;

    cout << "Bowling side rotation available choices : ";

    vector<int> bowlingRotationVect;

    for (int i = 1; i <= overs_per_bowler; i++)
    {
        if (overs_per_bowler % i == 0)
        {
            bowlingRotationVect.push_back(i);
            cout << i << " ";
        }
    }
    cout << endl;

    cout << "Select bowlerside rotation choice from above: ";
    cin >> bowlingside_rotation_per_overs;

    for (int i = 0; i < bowlingRotationVect.size(); i++)
    {
        if (bowlingside_rotation_per_overs == bowlingRotationVect[i])
            return 0;
    }
    return 1;
}

// Batsmen matrix
// matrix[batsmen][TotalOvers]
// @ -> batting
// & -> Rest
// {Natural Number} -> Fielding position
void batsmenMatrixFun()
{
    char **matrix = (char **)malloc(batsmen * sizeof(char *));

    for (int i = 0; i < batsmen; i++)
    {
        matrix[i] = (char *)malloc(overs * sizeof(char));
    }

    // for single player from batting side
    int totalOversForFielding = fielders_from_batting_side * battingside_rotation_per_overs;
    int totaloversForFieldingInst = totalOversForFielding / battingside_rotation_per_overs;
    int restOversForBatsman = overs - (fielders_from_batting_side * battingside_rotation_per_overs + overs_per_batsman);

    // Total rest instances
    int restInst = restOversForBatsman / battingside_rotation_per_overs;

    // After Batting rest instance
    int nextInst = restInst / 2;

    // After Bowling rest instance
    int prevInst = restInst - restInst / 2;

    // first row formation
    int cnt = 0;

    // -> batting
    for (int i = 0; i < battingside_rotation_per_overs; i++)
    {
        matrix[0][cnt] = '@';
        cnt++;
    }

    // -> rest after batting
    for (int i = 0; i < nextInst; i++)
    {
        for (int j = 0; j < battingside_rotation_per_overs; j++)
        {
            matrix[0][cnt] = '&';
            cnt++;
        }
    }

    // -> fielding
    for (int i = fielders_from_batting_side; i > 0; --i)
    {
        for (int j = 0; j < battingside_rotation_per_overs; j++)
        {
            matrix[0][cnt] = '0' + i;
            cnt++;
        }
    }

    // -> rest before batting
    for (int i = 0; i < prevInst; i++)
    {
        for (int j = 0; j < battingside_rotation_per_overs; j++)
        {
            matrix[0][cnt] = '&';
            cnt++;
        }
    }

    // Other rows
    for (int i = 1; i < batsmen; i++)
    {
        for (int j = 0; j < overs; j++)
        {
            matrix[i][j] = matrix[i - 1][(j + (overs - battingside_rotation_per_overs) % overs) % overs];
        }
    }

    // printing of Matrix
    for (int i = 0; i < batsmen; i++)
    {
        for (int j = 0; j < overs; j++)
            cout << matrix[i][j] << " ";
        cout << endl;
    }
}

// Bowler matrix
// matrix[bowlers][TotalOvers]
// @ -> bowling
// & -> Rest
// {Natural Number} -> Fielding position
void bowlersMatrixFun()
{
    char **matrix = (char **)malloc(bowlers * sizeof(char *));

    for (int i = 0; i < bowlers; i++)
    {
        matrix[i] = (char *)malloc(overs * sizeof(char));
    }

    for (int i = 0; i < bowlers; i++)
    {
        for (int j = 0; j < overs; j++)
            matrix[i][j] = '&';
    }

    // first row
    int currPosition = 0;
    int nextPosition = overs/(overs_per_bowler/bowlingside_rotation_per_overs);

    for(int i=0;i<overs_per_bowler/bowlingside_rotation_per_overs;i++)
    {
        int cnt= currPosition;

        // -> bowling during first rotation
        for(int j=0;j<bowlingside_rotation_per_overs;j++)
        {
            matrix[0][cnt] = '@';
            cnt++;
        }

        // -> fielding during first rotation
        for(int i = fielders_from_bowlers_side;i>0;--i)
        {
            for(int j=0;j<bowlingside_rotation_per_overs;j++)
            {
                matrix[0][cnt] = '0' + i;
                cnt++;
            }
        }
        // increment slot
        currPosition +=nextPosition;
    }

    // Other rows
    for(int i=1;i<bowlers;i++)
    {
        for(int j=0;j<overs;j++)
        {
            matrix[i][j] = matrix[i-1][(j+(overs-bowlingside_rotation_per_overs)%overs)%overs];
        }
    }

    cout<<"-------------"<<endl;
    // printing of Matrix
    for (int i = 0; i < bowlers; i++)
    {
        for (int j = 0; j < overs; j++)
            cout << matrix[i][j] << " ";
        cout << endl;
    }
    //  bowlers;
    //  overs;
    //  overs_per_bowler;
    //  fielders_from_bowlers_side;
    //  bowlingside_rotation_per_overs;
}

int main()
{
    init();

    // select batsmen
    if (selectBatsmen())
    {
        cout << "Invalid Input tt" << endl;
        return 1;
    }

    // select bowlers
    if (selectBowlers())
    {
        cout << "Invalid Input" << endl;
        return 1;
    }

    // select total overs
    if (oversSelect())
    {
        cout << "Invalid Input" << endl;
        return 1;
    }

    // select combination of fielders
    if (selectCombinationFielders())
    {
        cout << "Invalid Input" << endl;
        return 1;
    }

    // Rotation choices allowed for batsmen and bowlers
    if (selectRotation())
    {
        cout << "Invalid Input" << endl;
        return 1;
    }

    Test();

    batsmenMatrixFun();
    bowlersMatrixFun();
}